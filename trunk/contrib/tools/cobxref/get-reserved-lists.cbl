       >>source free
 Identification division.
*>**********************
      program-id.       get-reserved-lists.
*>**
*>    author.           Vincent Bryan Coen, Applewood Computers,
*>                      Applewood, Epping Road, Roydon, Essex, UK.
*>**
*>    date-written.     26 September 2010.
*>**
*>    Security.         Copyright (C) 2010- forever, Vincent Bryan Coen.
*>                      Distributed under the GNU General Public License
*>                      v2.0. Only. See the file COPYING for details but
*>                      for use within Open Cobol ONLY.
*>**
*>    Usage.            Get the reserved word lists from Open Cobol's
*>                      cobc, from v1.1 for Intrinsic and reserved words.
*>                      Note that Mnemonics - devices, features and switch names
*>                      are NOT obtained so that they can appear in xref listings.
*>**
*>    Called by.
*>                      cobxref
*>**
*>    Calls.
*>                      cobc
*>                      CBL_DELETE_FILE
*>                      SYSTEM
*>
*>    Changes.          See Changelog & Prog-Name.
*>
*>*************************************************************************
*>
*> Copyright Notice.
*>*****************
*>
*> This file/program is part of Cobxref AND Open Cobol and is copyright
*> (c) Vincent B Coen 2010 - forever.
*>
*> This program is free software; you can redistribute it and/or modify it
*> under the terms of the GNU General Public License as published by the
*> Free Software Foundation; version 2 ONLY within Open Cobol, providing
*> the package continues to be issued or marketed as 'Open Cobol' and
*> is available FREE OF CHARGE AND WITH FULL SOURCE CODE.
*>
*> It cannot be included or used with any other Compiler without the
*> written Authority by the copyright holder, Vincent B Coen.
*>
*> Cobxref is distributed in the hope that it will be useful, but WITHOUT
*> ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
*> FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
*> for more details. If it breaks, you own both pieces but I will endevor
*> to fix it, providing you tell me about the problem.
*>
*> You should have received a copy of the GNU General Public License along
*> with Cobxref; see the file COPYING.  If not, write to the Free Software
*> Foundation, 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
*>*************************************************************************
*>
 environment division.
 configuration section.
 source-computer.      linux.
 object-computer.      linux.
 input-Output section.
 file-control.
*>
     select   Reserve-Stream   assign "res.tmp"
              organization     line sequential
              status           fs-reply.
*>
     select   Intrinsic-Stream assign "int.tmp"
              organization     line sequential
              status           fs-reply.
*>
 data division.
 file section.
*>***********
*>
*> CAUTION: Both of these files can and probably do contain Tab chars
*>
 fd  Reserve-Stream.
 01  Res-Record            pic x(128).
*>
 fd  Intrinsic-Stream.
 01  Int-Record            pic x(128).
*>
 working-storage section.
*>**********************
 77  Prog-Name             pic x(27) value "get-reserved-lists v1.00.01".
 77  S-Ptr                 Binary-long  value zero.
 77  Res-Start             Binary-char  value zero.
 77  ws-Function-Table-Size pic s9(5)  comp value zero.
 77  ws-Resvd-Table-Size   pic s9(5)   comp value zero.
 77  fs-reply              pic 99.
*>
 01  Placement-Res         pic x(30).
 01  Placement-Res-State   pic x.

 Linkage section.
*>**************
 01  ws-Return-Code        binary-char.
*>
*> Here for cb_intrinsic_table in OC see cobc/reserved.c in the open-cobol source directory but
*>    Totally ingoring the system_table as not needed/used by xref
*>
*> Also note that the number 0 or 1 indicates if the function/reserved word is implemented in Open Cobol
*>   but xref treats all, as being reserved as they are so (reserved that is)
*>
 01  Function-Table-R.
     03  All-Functions                 occurs 256 ascending key P-Function indexed by All-Fun-Idx.
         05  P-oc-implemented  pic x.
         05  P-Function        pic x(30).
 01  Function-Table-Size       pic s9(5)  comp.
*>
*> Note that system names are omitted so that they turn up in the cross refs
*>
*> Here for all reserved words in OC see :
*>           struct reserved reserved_words in cobc/reserved.c in the open-cobol source directory
*>
 01  Additional-Reserved-Words-R.
     03  Reserved-Names                occurs 1024 ascending key Resvd-Word indexed by Resvd-Idx.
         05  Resvd-Implemented pic x.
         05  Resvd-Word        pic x(30).
 01  Resvd-Table-Size          pic s9(5)   comp.
*>
 procedure division using ws-Return-Code
                          Function-Table-R
                          Function-Table-Size
                          Additional-Reserved-Words-R
                          Resvd-Table-Size.
*>===================================================
 aa000-startup section.
 aa010-Init.

     call     "SYSTEM" using "cobc --list-intrinsics > int.tmp".
     call     "SYSTEM" using "cobc --list-reserved > res.tmp".
     move     zero to ws-return-code.
     perform  ba000-Get-Intrinsics-Words.
     if       ws-return-code not zero
              exit program.
     perform  ca000-Get-Reserved-Words.
     call     "CBL_DELETE_FILE" using "res.tmp". *> delete temp files
     call     "CBL_DELETE_FILE" using "int.tmp".
     exit     program.
      stop run.
*>
 ba000-Get-Intrinsics-Words section.
 ba010-init.
     open     input Intrinsic-Stream.
     if       fs-reply = 35
              display "Cannot run 'cobc  --list-intrinsics', cobc not in path?".
     if       fs-reply not = zero
              move fs-reply to ws-return-code
              exit section.
*>
     move     Function-Table-Size to ws-Function-Table-Size.  *> keep old
     move     high-values to Function-Table-R.                *> there is a data stream so we can clear the table
     move     zero to Function-Table-Size.
*>
 ba020-get-thru-base-data.
     move     high-values to Int-Record.
     read     Intrinsic-Stream at end
              move zero to ws-return-code
              close Intrinsic-Stream
              if Function-Table-Size > ws-Function-Table-Size
                 display "Intrinsic word table was successfully updated"
              end-if
              exit section.
*>
     if       Int-Record (1:3) = spaces                       *> blank line
       or     Int-Record (1:18) = "Intrinsic Function"        *> header
              go to ba020-get-thru-base-data.
*>
*>  This point we now have data
*>
     move     1 to S-Ptr.
     move     spaces to Placement-Res Placement-Res-State.
     unstring Int-Record delimited by all x"09" or all spaces into Placement-Res pointer S-Ptr.
     unstring Int-Record delimited by all x"09" or all spaces into Placement-Res-State pointer S-Ptr.
     add      1 to Function-Table-Size.
     move     Placement-Res to P-Function (Function-Table-Size).
     If       Placement-Res-State = "Y"
              move "1" to P-oc-implemented (Function-Table-Size)
     else
              move "0" to P-oc-implemented (Function-Table-Size).
*>
     go to ba020-get-thru-base-data.
*>
 ca000-Get-Reserved-Words section.
*>*******************************
 ca010-init.
     open     input Reserve-Stream.
     if       fs-reply = 35
              display "Cannot run 'cobc  --list-reserved', cobc not in path?".
     if       fs-reply not = zero
              move fs-reply to ws-return-code
              exit section.
*>
     move     Resvd-Table-Size to ws-Resvd-Table-Size.
     move     high-values to Additional-Reserved-Words-R.  *> there is a data stream so we can clear the table
     move     zero to Resvd-Table-Size.
     move     zero to Res-Start.
*>
 ca020-get-thru-base-data.
     move     high-values to Res-Record.
     read     Reserve-Stream at end
              go to ca030-Clean-Up.
*>
     if       Res-Record (1:3) = spaces                       *> blank line
       or     Res-Record (1:14) = "Reserved Words"            *> header
              go to ca020-get-thru-base-data
     end-if
     if       Res-Record (1:16) = "Extra (obsolete)"
              perform until exit
                 read Reserve-Stream at end
                      go to ca030-Clean-Up
                 end-read
                 if Res-Record (1:14) = "Extra internal"
                    move 1 to Res-Start                       *> Now we don't have res-State set to 1 so help to make it so
                    go to ca020-get-thru-base-data
                 end-if
              end-perform
     end-if
*>
*>  This point we now have data
*>
     move     1 to S-Ptr.
     move     spaces to Placement-Res Placement-Res-State.
     unstring Res-Record delimited by all x"09" or all spaces into Placement-Res pointer S-Ptr.
     unstring Res-Record delimited by all x"09" or all spaces into Placement-Res-State pointer S-Ptr.
     add      1 to Resvd-Table-Size.
     move     Placement-Res to Resvd-Word (Resvd-Table-Size).
     If       Placement-Res-State = "Y"
              move "1" to Resvd-Implemented (Resvd-Table-Size)
     else
      if      Placement-Res-State = "N"
              move "0" to Resvd-Implemented (Resvd-Table-Size)
      else
       If     Res-Start = 1                                        *> have a Extra internal with no implemented flag
              move "1" to Resvd-Implemented (Resvd-Table-Size)
       else
              move "0" to Resvd-Implemented (Resvd-Table-Size)
       end-if
      end-if
     end-if
*>
     go to ca020-get-thru-base-data.
*>
 ca030-Clean-Up.
     move     zero to ws-return-code.
     close    Reserve-Stream.
     if       Resvd-Table-Size > ws-Resvd-Table-Size
                 display "Reserve word table was successfully updated"
     end-if
     exit     section.
*>
