       >>source free
 identification division.
 program-id.    printcbl.
*> Author.      Vincent B Coen New verson v2.01.10+) 01/5/13 See Changelog file
*>                                                  for all changes.
*> Tesing Level 1/2
*>*****************
*>
*> 17/05/12 vbc - Copy                working
*> 18/05/12 vbc - 'Suppress'          working
*> 18/05/12 vbc - 'Suppress printing' working
*> 01/06/12 vbc - 'REPLACING'         working
*> 01/06/12 vbc - 'NOPRINT'           working
*> 01/06/12 vbc - 'LIST|NOLIST'       working
*> 02/06/12 vbc - 'EJECT' | '/'       working
*>           add differing case for the above
*>
*>  Please read all of the notes before use!!!
*>   Notes transferred to a manual in LibreOffice & PDF formats.
*>     Need more clean up as a bit of a mess!
*>
*>  Latest version at http://applewoodbbs/mine.nu/files/Cobol-Dev/prtcbl-latest.zip
*>   or via (anonymous) ftp  applewoodbbs.mine.nu/pub/Cobol-Dev/printtcbl-latest.zip
*>   also added to trunk/contrib/tools on GNU Cobol/Open Cobol at sourceforge.
*>
*> Suggestions for updates to vbcoen at gmail.com
*> Message subject should be 'printcbl requests' or 'printcbl bugs'
*>   subject to the issue or problem.
*>
*> If you wish to be on a update & bug report email list for:
*> Printcbl, Cobxref, Profiler (Cobol), dectrans and anything else
*> related to Cobol development, Send your details to above
*> adddress with subject: 'Update lists' and you will
*> be added to my address list for such purposes.
*>
*>NOLIST
*>*************************************************************
*> Purpose:
*>         Produces a print (or an updated source file) of a
*>      Cobol source program with all of it's copy books included.
*>      =========================================================
*>
*>  See manual for more information
*>
*>***************************************************************
*>
 environment division.
 input-output section.
 file-control.
           select Print-File     assign to WS-Print-File-Name
                                 organization line sequential.
*>
 data division.
 file section.
*>
 fd  Print-File.
 01  Formatted-Line          pic x(160).
 01  Print-Line.
     03  PL-Line-Number      pic z(5).
     03  PL-Filler-1.
         05  PL-Star         pic x.
         05  PL-Level        pic z.
         05  filler          pic x.
     03  PL-Text             pic x(152).
*>
 working-storage section.
*>======================
*>
 01  WS-Name-Program        pic x(15) value "Prtcbl v2.01.12".  *> ver.rel.build
*>
*>   **************************************
*>   *     User changeable values here:   ****************************************************
*>   **************************************
*>
*> Temporary for testing program args etc, (We-Are-Testing) will display prog arguments at start.
*>  Useful to have anyway!
*>
 77  Testing                pic 9 value 1.
     88 We-Are-Testing            value 1
                               False is 1.
 77  Testing2               pic 9 value 0.
     88 We-Are-Testing2           value 1
                               False is 0.
 77  Testing3               pic 9 value 0.
     88 We-Are-Testing3           value 1
                               False is 0.
 77  Testing4               pic 9 value 0.
     88 We-Are-Testing4           value 1
                               False is 0.
 77  Print-It-Out           pic 9 value zero.    *>  Set this to 1 if you want reports printed unless
*>                                                   changed by NOPRINT in line 1 of any source file.
*>                                                   See manual for information. Set to 0 for testing
*>   +-----------------------+
*>   | Portrait lpr Settings |
*>   +-----------------------+
*>
 01  Print-Report.
     03  filler             pic x(119)     value
    "lpr " &
*>    "-r " &                                 *> Uncomment if you want to delete file after printing
    "-o 'orientation-requested=3 page-left=24 page-top=24 " &     *> 24 = 1/4 inch (6mm) edges
    "page-right=24 sides=two-sided-long-edge " &                  *>  and increase page-left to 48
                                                                  *>    for hole punching, etc.
    "cpi=16.6 " &                                                 *> Change if font size wrong
    "lpi=9' -P ".                                                 *> change if lines per inch wrong
     03  PSN                pic x(48)      value "HPLJ4TCP ".     *> Change to your Print Spool Name
*>
*>>>>>>        Change To Your Spool Name for printer
*> This is the Cups print spool, change it for yours,
*>  if your printer can not handle Duplex printing remove string
*>       ' sides=two-sided-long-edge'
*>  if you do not want to delete file after spooling leave the commented out "-r " &
*>>>>>>
*>
     03  PR-Name            pic x(32)     value spaces.     *> O/P filename goes here
*>
 01  WS-Page-Lines          pic 999       value 99.         *> Change if you do not fill a page or go over to
*>                                                              a new one without a heading line (see Docs)
*>
 01  WS-Local-Time-Zone     pic 9         value 3.          *> Defaults to International, See comments below !
*>
*> Set WS-Local-Time-Zone ^^ to one of these 88 value's according to your local requirements
*>
     88  LTZ-Unix                         value 3. *> ccyy/mm/dd  Also implies A4 Paper for prints
     88  LTZ-USA                          value 2. *> mm/dd/ccyy  Also implies US Letter Paper for prints
     88  LTZ-UK                           value 1. *> dd/mm/ccyy  Also implies A4 Paper for prints
*>
*>   **************************************
*>   *    End of User Changeable Values   ****************************************************
*>   **************************************
*>
 01  WS-Print-File-Name     pic x(64)      value spaces.
 01  WS-Input-File-Name     pic x(64)      value spaces.
 01  WS-Status              PIC 99         value zero.
 01  WS-Copy-File-Name      pic x(768)     value spaces.
 01  WS-Hold-Copy-File-Name pic x(768)     value spaces.
 01  WS-Line-Number         pic 9(5)  comp value zero.
 01  WS-Page-Line-Counter   pic 999   comp value 999.
 01  WS-Page-Number         pic 999   comp value zero.
 01  WS-Error-Count         pic 999   comp value zero.
 01  WS-Caution-Count       pic 999   comp value zero.
 01  WS-Current-Date        pic x(21)      value spaces.  *> cc17-21 = +/-, hhmm UTC diff not used.
 01  WS-PPage               PIC ZZ9.
 01  WS-Switch-Print        pic 9          value 1.
     88  Print-On                          value 1      False is 0.
 01  WS-Print-Open-Flag     pic 9          value zero.
     88 WS-Print-Open                      value 1      False is 0.
*>
 01  Found-Quote-in-Copy    pic 9          value zero.
*>
 01  No-Print               pic 9          value zero.  *> Set if "*>NOPRINT" or "**NOPRINT"
     88  No-Printing                       value 1  False is 0.    *>   found in 1st rec
 01  Found-In               pic 9          value zero.  *> Not used yet
 01  Found-WD               pic 9          value zero.
     88  Found-Word                        value 1      False is 0.
 01  Found-No               pic 9          value zero.
     88  Found-Number                      value 1      False is 0.
 01  In-Dir                 pic x(500)     value space. *> Not used yet
 01  Hold-Word1             pic x(32)      value space.
 01  Hold-Word2             pic x(32)      value space.
 01  WS-Free                pic 9          value zero.  *> Source code format
     88  WS-Fixed-Set                      value zero.
     88  WS-Free-Set                       value 1.
 01  WS-Search              pic 9          value zero.  *> Search in copy libs
     88  No-Search                         value 1.     *> Don't, as we are using source file
     88  Yes-Search                        value zero.  *> Do so, as we are using Copy files
 01  WS-Number-Test.
     03  WS-Number          pic 9.
*>
*>   Used in Copy Table
*>
 01  WS-T1                  pic x.
 01  WS-T1x redefines WS-T1 binary-char.
 01  Word-Delimit           pic x          value space.
 01  Word-Delimit2          pic xx         value spaces.  *> Of copyfilename, space or ". "
 01  WS-P1                  pic s9(7) comp value zero.    *> Used for small buffers
 01  WS-P2                  pic s9(7) comp value zero.    *>    ---- ditto ----
 01  WS-P3                  pic s9(7) comp value zero.
 01  WS-P4                  pic s9(7) comp value zero.
 01  WS-P5                  pic s9(7) comp value zero.
 01  WS-P6                  pic s9(7) comp value zero.
 01  WS-P7                  pic s9(7) comp value zero.
 01  WS-P8                  pic s9(7) comp value zero.
 01  WS-P9                  pic s9(7) comp value zero.
 01  WS-P10                 pic s9(7) comp value zero.
 01  WS-P11                 pic s9(7) comp value zero.
 01  WS-P12                 pic s9(7) comp value zero.
 01  WS-P13                 pic s9(7) comp value zero.
 01  WS-End                 pic s9(7) comp value zero.    *> Normal end of record, eg, 256 or 72
 01  WS-Disp                pic z9.
 01  WS-Disp2               pic zz9.
 01  WS-Disp3               pic ----9.
 01  WS-Disp4               pic z(6)9.
 01  a                      pic s9(5) comp value zero.
 01  e                      pic s9(5) comp value zero.
 01  f                      pic s9(5) comp value zero.
 01  g                      pic s9(7) comp value zero.
*>
 01  fn                     pic 999  comp  value zero.
 01  t                      pic 999  comp  value zero.
 01  u                      pic 999  comp  value zero.
 01  x                      pic 9(4) comp  value zero.
 01  y                      pic 99   comp  value zero.
 01  z                      pic 99   comp  value zero.
*>
*>   ******************************************************************
*>   *  Contents of COBC Env vars if set but usually only one of both *
*>   *  if both exist AND the same only use one - COBCPY              *
*>   ******************************************************************
*>
 01  Uns-Delimiter          pic x          value space.
 01  Cobcpy                 pic x(500)     value spaces.
 01  Cob_Copy_Dir           pic x(500)     value spaces.
 01  Copy-Dirs-Block.                                          *> Could be larger but if you need it, you have
*>                                                                some serious project control issues !!
     03  No-Of-Copy-Dirs    pic s99  comp  value zero.
     03  Copy-Lib           pic x(500)                 occurs 10.
*>
*>   *****************************************************
*>   *  Holds program parameter values from command line *
*>   *****************************************************
*>
 01  Arg-Number             pic 9          value zero.
 01  Arg-Vals                              value spaces.
     03  Arg-Value          pic x(515)                 occurs 5.
 01  Arg-Test               pic x(515)     value spaces.
*>
*>   *******************************************
*>   *  Variables/Tables for Copy input files  *
*>   *******************************************
*>
*>   +==========================================================+
*>   | NOTE that some data and code taken from Profiler (v0.01) |
*>   |     and Cobxref (both under Alpha test)                  |
*>   | SO copy any bugs fixes here to them !!                   |
*>   +==========================================================+
*>
*>   Starting with Error Messages
*>
 01  Error-messages.
     03  Msg1               pic x(34)     value "Error: Too many levels (9) of COPY".
     03  Msg2               pic x(27)     value "Error: Copy File Not Found ".
     03  Msg3               pic x(22)     value "Error: File Not Found ".
     03  Msg4               pic x(24)     value "(P): File Not Closed? = ".
     03  Msg5               pic x(25)     value "(P): On Read. Ret.code = ".
     03  Msg6               pic x(35)     value "Error: When opening I/P file got = ".
     03  Msg7               pic x(52)     value "Error: Cannot Find File, & tried six different .Exts".
     03  Msg8               pic x(28)     value "Error: Abnormal end of input".
     03  Msg9               pic x(48)     value "Caution: One or more replacing sources not found".
     03  Msg10              pic x(33)     value "Error: Invalid Format, try again!".
*>
*>   ***************************************
*>   | List of possible source file .exts, |
*>   |  First one is ALWAYS space.         |
*>   ***************************************
*>LIST
 01  Extention-Table        pic x(28)     value "    .cpy.CPY.cbl.CBL.cob.COB".
 01  filler redefines Extention-Table.
     03  File-Ext           pic x(4)  occurs 7.
 01  Ext-Table-Size         pic 9         value 7.
*>
*>   **********************************************************    NOTE: that OC only goes 2-5
*>   *  Now follows the tables needed for the 9 depth levels  *          ?????????????
*>   *  that support the copy verb  within a copy verb.       *
*>   *  First is ALWAYS the source file.                      *
*>   **********************************************************
*>
 01  Copy-Record.
     05  CR-Buffer          pic x(256).            *> Both; max size for free format + 1
 01  CR-Buffer-Data-Size    pic 999     comp       value zero.
*>
 01  Input-Record.
     05  IR-Buffer          pic x(256).
 01  IR-Buffer-Data-Size    pic 999     comp       value zero.
 01  Temp-Input-Record.
     03  TIR                pic x(256).
*>
*>   WARNING: Do NOT alter these Structures or Formats!
*>
 01  Copy-Depth             pic 99                 value zero.
 01  Max-Copy-Depth         pic 99                 value zero.
*>
 01  Copy-Max-Length        pic 9(6)    comp       value 65536.      *> Is this too high? NOT USED
*>
 01  File-Handle-Tables.                                             *>  1st occurrence is for orig source file.
     03  FHT                            occurs 1 to 10 depending on Fht-Table-Size.
         05  Fht-Byte-Count        pic x(4)    comp-x  value 1048576.
         05  Fht-Var-Block.
             07  Fht-File-Handle   pic x(4).
             07  Fht-File-OffSet   pic x(8)    comp-x  value zero.
             07  Fht-File-Size     pic x(8)    comp-x  value zero.
             07  Fht-Block-OffSet  pic x(8)    comp-x  value zero.
             07  Fht-Pointer       pic s9(7)   comp    value zero.
             07  Fht-P1            pic s9(7)   comp    value zero.   *> WS-P1 Storage Not yet used
             07  Fht-P2            pic s9(7)   comp    value zero.   *> WS-P2 Storage Not yet used
             07  Fht-Copy-Line-End pic s9(5)   comp    value zero.   *>  All new not programmed
             07  Fht-Copy-Words    pic s9(5)   comp    value zero.   *>  All new not programmed
             07  Fht-SW-Eof        pic 9               value zero.
                 88  Fht-Eof                           value 1     False is 0.
             07  Fht-Copy-Found    pic 9               value zero.   *>  All new not programmed
             07  Fht-Replace-Found pic 9               value zero.   *>      ----- ' --------
             07  Fht-Literal-Found pic 9               value zero.   *>      ----- ' --------
             07  Fht-Continue      pic 9               value zero.   *>      ----- ' --------
             07  Fht-Quote-Found   pic 9               value zero.   *>      ----- ' --------
             07  Fht-Quote-Type    pic x               value space.  *>      ----- ' --------
             07  Fht-Source-Format pic 9               value zero.
                 88  Fht-Fixed                         value 0.
                 88  Fht-Free                          value 1.
             07  Fht-Block-Status  pic 9               value zero.
                 88  Fht-Block-Eof                     value 1.
         05  Fht-Current-Rec       pic x(256)          value spaces. *> Max size of free recs + 1
         05  Fht-File-Name         pic x(768)          value spaces.
         05  Fht-Buffer.
             07  filler            pic x(1024)  occurs 1024.         *> same as Fht-Buffer-Size
             07  filler            pic x.                            *> Fht-Buffer-Size + 1
         05  filler                pic x               value x"FF".  *> Trap for buffer overflow Hopefully!
*>
 01  Fht-Buffer-Size               pic s9(7)   comp    value 1048576.
 01  Fht-Table-Size                pic s999    comp    value zero.
 01  Fht-Max-Table-Size            pic 999     comp    value 10.     *> same as occurs in (above) FHT.
 01  CRT-Replace-Arguments-Size    pic 999     comp    value 50.     *> Same as occurs in WS- | CRT-Replace-Arguments
 01  CRT-Table-Size                pic 999     comp    value zero.
 01  Copy-Replacing-Table.                                           *>  occurs per copy file
     03  CRT-Instance        occurs 1 to 10 depending on CRT-Table-Size. *> well nine is correct figure ..
         05  CRT-Active-Flag       pic 9               value zero.
             88  CRT-Active                            value 1     False is 0.
         05  CRT-Copy-Found-Flag   pic 9               value zero.
             88  CRT-Copy-Found                        value 1     False is 0.
         05  CRT-Copy-Library-Flag pic 9               value zero.
             88  CRT-COPY-Lib-Found                    value 1     False is 0.
         05  CRT-Copy-Fname-Ext-Flag pic 9             value zero.
             88  CRT-Copy-Fname-Ext                    value 1     False is 0.
         05  CRT-Replace-Found-Flag   pic 9            value zero.
             88  CRT-Replace-Found                     value 1     False is 0.
         05  CRT-Quote-Found-Flag     pic 9            value zero.
             88  CRT-Quote-Found                       value 1     False is 0.
         05  CRT-Quote-Type        pic x               value space.
         05  CRT-Literal-Found-Flag   pic 9            value zero.   *>  All new not programmed
             88  CRT-Literal-Found                     value 1     False is 0. *> not programmed
         05  CRT-Continue-Flag     pic 9               value zero.   *>  All new not programmed
             88  CRT-Continue                          value 1     False is 0. *> not programmed
         05  CRT-Within-Comment    pic 9               value zero.   *>  All new not programmed
         05  CRT-Within-Bracket    pic 9               value zero.   *>  All new not programmed
         05  CRT-Need-Quotation-Flag  pic 9            value zero.   *>  All new not programmed
         05  CRT-Need-Continuation pic 9               value zero.   *>  All new not programmed
         05  CRT-Replace-Space     pic 9               value zero.   *>  All new not programmed
         05  CRT-Suppress-Flag     pic 9               value zero.
             88  CRT-Suppress                          value 1     False is 0.
         05  CRT-Consecutive-Quotation pic 9           value zero.   *>  All new not programmed
         05  CRT-Newline-Count     pic 999     comp    value zero.   *>  All new not programmed
         05  CRT-Replacing-Count   pic 999     comp    value zero.
         05  CRT-Copy-Length       pic 9(7)    comp    value zero.   *>  All new not programmed [ used in testing 4 prints]
         05  CRT-Copy-Statement                        value spaces. *> The entire copy statement but not really needed
             07  filler            pic x(1024)  occurs 1024.         *> 1 MB                      except during testing
         05  CRT-Copy-FileName     pic x(256)          value spaces.
         05  CRT-Copy-Library      pic x(512)          value spaces.
         05  CRT-Replace-Arguments      occurs  50.                  *>  Fixed size, Usage is CRT-Replacing-Count.
             07  CRT-Leading-Flag  pic 9               value zero.
                 88  Crt-Leading                       value 1     False is 0.
             07  CRT-Trailing-Flag pic 9               value zero.
                 88  Crt-Trailing                      value 1     False is 0.
             07  CRT-Replace-Type  pic 9               value zero.
                 88  CRT-RT-Lit                        value 1.
                 88  CRT-RT-Pseudo                     value 2.
                 88  CRT-RT-Else                       value 3.
                 88  CRT-RT-Oops                       value 0.
             07  CRT-Found-Src     pic 99              value zero.    *> non zero if a replacing target is found
             07  CRT-Source-Size   pic 9(4)            value zero.    *> these sizes relate to the relacing-source and target
             07  CRT-Target-Size   pic 9(4)            value zero.    *>   - - - -  ditto - - - -
*>
*>  On paper these can be as large as 65,535 BUT coding can only cope if literal or word is on same source line
*>     So not relevant at this time (30 April 2012) v02.01.*
*>
             07  CRT-Replacing-Source  pic x(2048)     value spaces.  *> Make larger if required (coding changes also needed)
             07  CRT-Replacing-Target  pic x(2048)     value spaces.  *> ditto
*>
 01  Cbl-File-Fields.
     03  Cbl-File-name      pic x(768).
     03  Cbl-Access-Mode    pic x          comp-x  value 1.
     03  Cbl-Deny-Mode      pic x          comp-x  value 3.
     03  Cbl-Device         pic x          comp-x  value zero.
     03  Cbl-Flags          pic x          comp-x  value zero.       *> normal 0 or 128 returns filesize in file offset
     03  Cbl-File-Handle    pic x(4)               value zero.
     03  Cbl-File-OffSet    pic x(8)       comp-x  value zero.
*>
 01  Cbl-File-Details.
     03  Cbl-File-Size      pic x(8)       comp-x  value zero.
     03  Cbl-File-Date.
         05  Cbl-File-Day   pic x          comp-x  value zero.
         05  Cbl-File-Mth   pic x          comp-x  value zero.
         05  Cbl-File-Year  pic xx         comp-x  value zero.
     03  Cbl-File-time.
         05  Cbl-File-Hour  pic x          comp-x  value zero.
         05  Cbl-File-Min   pic x          comp-x  value zero.
         05  Cbl-File-Sec   pic x          comp-x  value zero.
         05  Cbl-File-Hund  pic x          comp-x  value zero.
*>
*>  Extra Buffers needed for replacing  For Active Copy
*>
 01  IB-Size                pic 9(7)               value zero.
 01  Input-Buffer.
     03  In-Buffer          pic x(1024)    occurs 1024.  *> 1 MB buffers
 01  CInput-Buffer.                                      *> Converted to uppercase for test
     03  CIn-Buffer         pic x(1024)    occurs 1024.  *> 1 MB buffers
 01  OB-Size                pic 9(7)               value zero.
 01  Temp-Replacing-Source  pic x(2048).                 *> same as size of CRT-Replacing-Source
 01  Temp-Replacing-Target  pic x(2048).                 *>  - - Ditto for Target
 01  Temp-Record            pic x(256).
*>
*> Copy of current Copy table block to save accessing a table when processing COPY
*>
 01  WS-CRT-Active-Copy-Table     pic s999    comp    value zero.    *> taken from CRT-Table-Size BUT NOT YET UTILISED
 01  WS-CRT-Instance.
     03  WS-CRT-Active-Flag       pic 9               value zero.
         88  WS-CRT-Active                            value 1     False is 0.
     03  WS-CRT-Copy-Found-Flag   pic 9               value zero.
         88  WS-CRT-Copy-Found                        value 1     False is 0.
     03  WS-CRT-Copy-Library-Flag pic 9               value zero.
         88  WS-CRT-COPY-Lib-Found                    value 1     False is 0.
     03  WS-CRT-Copy-Fname-Ext-Flag   pic 9           value zero.
         88  WS-CRT-Copy-Fname-Ext                    value 1     False is 0.
     03  WS-CRT-Replace-Found-Flag    pic 9           value zero.
         88  WS-CRT-Replace-Found                     value 1     False is 0.
     03  WS-CRT-Quote-Found-Flag  pic 9               value zero.
         88  WS-CRT-Quote-Found                       value 1     False is 0.
     03  WS-CRT-Quote-Type        pic x               value space.
     03  WS-CRT-Literal-Found-Flag    pic 9           value zero.    *>  All new not programmed
         88  WS-CRT-Literal-Found                     value 1     False is 0. *> not programmed
     03  WS-CRT-Continue-Flag     pic 9               value zero.    *>  All new not programmed
         88  WS-CRT-Continue                          value 1     False is 0. *> not programmed
     03  WS-CRT-Within-Comment    pic 9               value zero.    *>  All new not programmed
     03  WS-CRT-Within-Bracket    pic 9               value zero.    *>  All new not programmed
     03  WS-CRT-Need-Quotation-Flag   pic 9           value zero.    *>  All new not programmed
     03  WS-CRT-Need-Continuation pic 9               value zero.    *>  All new not programmed
     03  WS-CRT-Replace-Space     pic 9               value zero.    *>  All new not programmed
     03  WS-CRT-Suppress-Flag     pic 9               value zero.
         88  WS-CRT-Suppress                          value 1     False is 0.
     03  WS-CRT-Consecutive-Quotation pic 9           value zero.    *>  All new not programmed
     03  WS-CRT-Newline-Count     pic 999     comp    value zero.    *>  All new not programmed
     03  WS-CRT-Replacing-Count   pic 999     comp    value zero.
     03  WS-CRT-Copy-Length       pic 9(7)    comp    value zero.
     03  WS-CRT-Copy-Statement                        value spaces.
         05  filler               pic x(1024)  occurs 1024.          *> 1 MB
     03  WS-CRT-Copy-FileName     pic x(256)          value spaces.
     03  WS-CRT-Copy-Library      pic x(512)          value spaces.
     03  WS-CRT-Replace-Arguments      occurs  50.                   *>  Usage WS-CRT-Replacing-Count
         05  WS-CRT-Leading-Flag  pic 9               value zero.
             88  WS-CRT-Leading                       value 1     False is 0.
         05  WS-CRT-Trailing-Flag pic 9               value zero.
             88  WS-CRT-Trailing                      value 1     False is 0.
         05  WS-CRT-Replace-Type  pic 9               value zero.
             88  WS-CRT-RT-Lit                        value 1.
             88  WS-CRT-RT-Pseudo                     value 2.
             88  WS-CRT-RT-Else                       value 3.
             88  WS-CRT-RT-Oops                       value 0.
         05  WS-CRT-Found-Src     pic 99              value zero.    *> non zero if a replacing target is found
         05  WS-CRT-Source-Size   pic 9(4)            value zero.    *> these sizes relate to the replacing-source and target
         05  WS-CRT-Target-Size   pic 9(4)            value zero.    *>   - - - -  ditto - - - -
         05  WS-CRT-Replacing-Source  pic x(2048)     value spaces.  *> Make larger if required
         05  WS-CRT-Replacing-Target  pic x(2048)     value spaces.  *> ditto
*>
*>NOLIST
*> linkage section.
 Procedure Division.
 AA-Main Section.
*>**************
*>
     perform  aa000-Initialization.
     perform  ba000-Process.
     perform  ca000-End-of-Job.
     goback.                               *> It might be called
*>
 aa000-Initialization section.
*>***************************
*>
     perform  zz020-Get-Program-Args.
*>
*> if args > 3 we have in, out filenames & source format, so just need to open and test etc
*>
     if       Arg-Number > 3                             *> CHANGE to > 2 if Cups spool name always constant
              go to aa030-Bypass-Accepts.                *>               and setup in PSN
*>
 aa010-Get-Input-File.
     display  "1) Enter Input-File Name - "             at 1201 with erase eos.
     accept   WS-Input-File-Name at 1228 with update.
*>
     display  "2) Enter Print-File (Work File) Name - " at 1401 with erase eol.
     accept   WS-Print-File-Name at 1440 with update.
*>
 aa020-Get-Source-Format.
     display  "3) Program format fixed or free - "      at 1601 with erase eos.
     move     "fixed" to Hold-Word1.
     if       ws-Free-Set
              move "free" to Hold-Word1
     end-if
     if       ws-Fixed-Set
              move "fixed" to Hold-Word1
     end-if
     accept   Hold-Word1 at 1635 with update.
     move     function upper-case (Hold-Word1) to Hold-Word1.
     if       Hold-Word1 = "FIXED" or "-FIXED"
              set ws-Fixed-Set to true
     else
      if      Hold-Word1 = "FREE" or "-FREE"
              set ws-Free-Set to true
      else
              display Msg10                         at 1801 with foreground-color 3
              go to aa020-Get-Source-Format
      end-if
     end-if.
*>
     display  "4) Enter Print Spool Name - "        at 1801  with erase eos.
     Accept   PSN at 1829 with update.
     move     WS-Print-File-Name to PR-Name.
     display  "Warning: Only using Env. vars. for searches"  at 2001 with background-color 3.
*>
 aa030-Bypass-Accepts.
*>
*>  Changing this to use block reads via copy table as entry 1
*>
     set      No-Search to true.
     move     WS-Input-File-Name to WS-Copy-File-Name.
     if       not WS-Print-Open
              open output Print-File
              set WS-Print-Open to true
     end-if.
*>LIST
 aa040-Open-Main.
     perform  zz300-Open-File thru zz300-Exit.
     if       Return-Code  = 26
              display Msg3 at 1301 with foreground-color 3
              go to aa010-Get-Input-File.
*>
*> Next, this should not occur !!
*>
     if       Return-Code not = zero
              display Msg6           at 1301 with foreground-color 3 highlight
              display Return-Code    at 1336 with foreground-color 3 highlight
              go to aa010-Get-Input-File.
*>
     set      Yes-Search to true.          *>  ?????   <<<< IS IT?
     move     WS-Free to Fht-Source-Format (Fht-Table-Size).   *> copy format to current table record
*>
 aa000-Exit.
     Exit     Section.
*>
 ba000-Process Section.
*>********************
*>
*>   This loop for main source file and copy files as well
*>
     if       Fht-Table-Size = zero
              if    not No-Printing
                    perform  bd000-Test-For-Messages
              end-if
              go to ba999-exit                              *> EOJ
     end-if
     perform  zz600-Read-File thru zz600-Exit.
     if       Fht-Eof (Fht-Table-Size)
*>        and   Fht-Block-Eof (Fht-Table-Size)
        and   Fht-Table-Size < 2                            *> closing source file
              perform zz500-Close-File thru zz500-Exit
              if    not No-Printing
                    perform  bd000-Test-For-Messages
              end-if
              go to ba999-exit                              *> EOJ
     end-if
*>
     if       Fht-Eof (Fht-Table-Size)                      *> EOF on current copy file
         or   Return-Code = -1
              perform zz500-Close-File thru zz500-Exit
              perform bc000-Test-For-Missing-Replace
              go to ba000-Process.
*>
     move     Fht-Current-Rec (Fht-Table-Size) to Input-Record.
*>
*>  Lets see if current source line has a >>SOURCE declaration if so change fixed/free attribute.
*>
     perform  da000-Check-For-Source.
     if       Fht-Free (Fht-Table-Size)
              set WS-Free-Set to true
              move 256 to WS-End
     else
              set WS-Fixed-Set to true
              move 72  to WS-End
     end-if
*>
*> Find size of source record (max = 255 as per specs) & start of source
*>
     perform  varying IR-Buffer-Data-Size from WS-End by -1 until IR-Buffer (IR-Buffer-Data-Size:1) not = " "
                                                               or IR-Buffer-Data-Size < 2
     end-perform
     if       IR-Buffer (IR-Buffer-Data-Size:1) = x"0D" or x"00"
              subtract 1 from IR-Buffer-Data-Size
     end-if
     if       WS-Free-Set  and IR-Buffer-Data-Size < 2              *> Blank line
        or    WS-Fixed-Set and IR-Buffer-Data-Size < 9
              add      1 to WS-Line-Number
              move     ws-line-number to PL-line-number
              move     spaces to PL-Filler-1
              if       Fht-Table-Size > 1
                       move Fht-Table-Size to PL-Level
              end-if
              move     Input-Record To PL-Text
              perform  zz010-Write-Print-Line2
              perform  zz100-Headings
              go to ba000-Process.
*>
     move     zero to WS-P2.
     move     1    to WS-P1                                         *> Force Free format in case!!
                      WS-P5.
     if       WS-Fixed-Set                                          *> Free set above
              move  7 to WS-P1 WS-P5.
*>
*>  Support for source update only (no report) but can only happen on the first line of the source code
*>   and any Compiler directives MUST be from line 2. This is to make SURE no print lines are produced.
*>
     if       WS-Line-Number = zero
      and     ((ws-fixed-set and function upper-case (IR-Buffer (7:9)) = "**NOPRINT")
        or     (ws-free-set  and function upper-case (IR-Buffer (1:9)) = "*>NOPRINT"))
              set No-Printing to true
              move 1 to WS-Line-Number
              go to ba000-Process
     end-if
*>
     add      1 to WS-Line-Number.
     perform  zz100-Headings.
     move     ws-line-number to PL-line-number.
     move     spaces to PL-Filler-1.
     if       Fht-Table-Size > 1
              move Fht-Table-Size to PL-Level
     end-if
     perform  zz900-Process-Replace.
     move     Input-Record To PL-Text.
*>
     if       (ws-fixed-set and function upper-case (IR-Buffer (7:6)) = "**LIST")
       or     (ws-Free-set  and function upper-case (IR-Buffer (1:6)) = "*>LIST")
              set Print-On to True
     end-if
     if       Print-On
              if    ws-Fixed-Set
               and  (IR-Buffer (7:1) = "/"
                or  function upper-case (IR-Buffer (7:7)) = "**EJECT")  *> force page break NEXT line
                    move 250 to WS-Page-Line-Counter
              end-if
              if    (ws-Free-Set
               and  function upper-case (IR-Buffer (1:7)) = "*>EJECT")
                    move 250 to WS-Page-Line-Counter
              end-if
              perform zz010-Write-Print-Line1
     end-if
     if       (ws-fixed-set and function upper-case (IR-Buffer (7:8)) = "**NOLIST")
        or    (ws-free-set  and function upper-case (IR-Buffer (1:8)) = "*>NOLIST")
              set Print-On to false
     end-if
*>
*> If comments, we are done with line having tested for list. nolist, eject etc
*>
     if       (ws-Fixed-Set and IR-Buffer (7:1) = "*")
         or   (ws-Fixed-Set and IR-Buffer (7:1) = "$")  *> ex MF source/lists
         or   (ws-Fixed-Set and IR-Buffer (7:1) = "#")  *> can we get them here cc7 ?
         or   (ws-Free-Set and IR-Buffer (1:2) = "*>")
         or   (ws-Free-Set and IR-Buffer (1:1) = "$")
         or   (ws-Free-Set and IR-Buffer (1:1) = "#")
              go to ba000-Process
     end-if
*>
*>  As we have now output record we can clean it up, hopefully won't upset any searches
*>         looks like it might do so rem' this lot out
*>     inspect  Input-Record replacing all x"09" by space   *> TAB
*>                                         X"0D" by space   *> CR
*>                                         x"00" by space   *> null
*>                                         " ; " by "   "
*>                                         " , " by "   "
*>                                         ": "  by "  "
*>                                         ", "  by "  ".
*>
     set      Found-Word   to false.
     set      Found-Number to false.
*>
 ba010-Compare-Loop.
     if       IR-Buffer (WS-P1:2) = "*>"                  *> Floating '*>', applies to both Free & Fixed
              go to ba000-Process.
*>
*>   Make sure we dont use COPY word in a 'display' but accept one after a possible level number
*>
     if       NOT Found-Number and Found-Word
        and   (function upper-case (IR-Buffer (WS-P1:6)) = " COPY "
         or   WS-P1 = 1 and function upper-case (IR-Buffer (1:5)) = "COPY ")
              add      1 to WS-P1
              if       WS-P1 < IR-Buffer-Data-Size - 6
                       go to ba010-Compare-Loop
              else
                       go to ba000-Process
              end-if
     end-if
     if       IR-Buffer (WS-P1:1) = quote or "'"
              add 1 to WS-P1
              perform varying WS-P1 from WS-P1 by 1 until IR-Buffer (WS-P1:1) = quote
                                                       or "'"
                                                       or WS-P1 > IR-Buffer-Data-Size - 7
              end-perform                                           *> lose the literal or line
              if   WS-P1 > IR-Buffer-Data-Size - 7
                   go to ba000-Process
              end-if
     end-if

     if       function upper-case (IR-Buffer (WS-P1:6)) = " COPY "
       or     (WS-P1 = 1 and function upper-case (IR-Buffer (1:5)) = "COPY ")
              move zero to Found-Quote-in-Copy
              go to ba020-Copy.
*>
     move     IR-Buffer (WS-P1:1) to WS-Number-Test.
     if       WS-Number numeric
              set Found-Number to true.
     if       WS-Number-Test is Alphabetic
        and   WS-Number-Test not = space
              set Found-Word   to true.
*>
     add      1 to WS-P1.
     if       WS-P1 < IR-Buffer-Data-Size - 6
              go to ba010-Compare-Loop.

     go       to ba000-Process.
*>
 ba020-Copy.
     subtract 1 from WS-Line-Number.
     move     spaces to WS-Copy-File-Name
                        Input-Buffer.
     move     zero to IB-Size.
     move     Fht-Table-Size to CRT-Table-Size.
     initialize CRT-Instance (CRT-Table-Size).                 *> occurs matches in fht
*>
     initialize WS-CRT-Instance.
     move     CRT-Table-Size to WS-CRT-Active-Copy-Table.
*>
*> Preprocess copy statement
*>
     perform  bb000-Copy-Setup.                                *> copy is now in table so move to ws active copy
*>
     move     spaces to Hold-Word1 Hold-Word2.
*>
 ba030-Move-Loop.
     if       WS-CRT-Copy-Lib-Found
              unstring WS-CRT-Copy-Library delimited by space into Hold-Word1
              end-unstring
     end-if
     move     zero to e.
     inspect  WS-CRT-Copy-Filename tallying e for all ".".
     if       e > zero                                        *> its a .ext
              set WS-CRT-Copy-Fname-Ext to true
*>            go to ba040-Open-CopyFile                       *> IS THIS RIGHT? Need to add in copy-lib if present ???
     else
              set WS-CRT-Copy-Fname-Ext to false
     end-if                                                   *> Got space, now get 'IN' or 'OF'
*>
*> Could be "literal" so skip " or ' & copy rest to copy-file
*>
     if       WS-CRT-Quote-Found
              move 2 to WS-P1                                 *> quote bypass
              unstring WS-CRT-Copy-FileName  delimited by WS-CRT-Quote-Type
                                              into WS-Copy-File-Name
                                              pointer WS-P1
              end-unstring
              move  1 to Found-Quote-in-Copy
     else
              move     WS-CRT-Copy-FileName to WS-Copy-File-Name
     end-if
     Move     WS-Copy-File-Name To WS-Hold-Copy-File-Name.
*>
*> Check for 'in "../../foo". clause (quotes have been removed) and think about replacing clause
*>
     if       WS-CRT-Copy-Lib-Found
              move spaces to Arg-Test
              move WS-Copy-File-Name to Hold-Word2
              string  Hold-Word1        delimited by space
                      "/"               delimited by size
                      Hold-Word2        delimited by space into Arg-Test
              end-string
              move Arg-Test to WS-Copy-File-Name
     end-if.                *> At this point we should have content of Lib and filename
*>
 ba040-Open-CopyFile.
*>
*> Look for name, if not found add .ext's but if it was in ' or "
*>       going to get some silly .exts eg, foo.ext.cpy             >>>  NEED to look at this and STOP it.
*>
     perform  zz300-Open-file thru zz300-Exit.
     if       Return-Code = 24
              move spaces to Formatted-Line
              add  1      to WS-Error-Count
              if   No-Printing
                   string "*> "
                          Msg1 into PL-Text
                   end-string
              else
                   move Msg1   to PL-Text
              end-if
              perform zz010-Write-Print-Line2
              go     to ba000-process
     end-if
     if       Return-Code = 23
              move spaces to Formatted-Line
              add 1 to WS-Error-Count
              if   No-Printing
                   string "*> "
                          "Error: Recursive Copy File Name = " delimited by size
                         WS-Copy-File-Name                     delimited by space
                        " - Above is IGNORED"                  delimited by size   into PL-Text
                   end-string
              else
                   string "Error: Recursive Copy File Name = " delimited by size
                          WS-Copy-File-Name                    delimited by space
                          " - Above is IGNORED"                delimited by size   into PL-Text
                   end-string
              end-if
              perform zz010-Write-Print-Line2
              go     to ba000-Process
     end-if
     if       Return-Code not = zero   *> not found
      and     Found-Quote-in-Copy = 1
              go to ba050-Try-CopyPaths
     end-if
     if       return-code = zero
              if we-are-testing2
                  move spaces to formatted-line
                  string "We now are processing "
                         Fht-File-Name (Fht-Table-Size) into formatted-line
                  end-string
                  perform zz010-Write-Print-Line2
              end-if
              go to ba070-Print-Loop.
*>
*> Here for RT not zero
*>
 ba050-Try-CopyPaths.
     perform  varying x from 1 by 1 until x > No-Of-Copy-Dirs
              string Copy-Lib (x)           delimited by space
                              "/"           delimited by size
                     WS-Hold-Copy-File-Name delimited by space into WS-Copy-File-Name
              end-string
              if we-are-testing2
                  move spaces to formatted-line
                  string "We are looking for "
                         WS-Copy-File-Name (1:120) into formatted-line
                  end-string
                  perform zz010-Write-Print-Line2
              end-if
              perform  zz300-Open-file thru zz300-Exit
              if     Return-Code = zero
                     if we-are-testing2
                         move spaces to formatted-line
                         string "We have found "
                                Fht-File-Name (Fht-Table-Size) (1:117) into formatted-line
                         end-string
                         perform zz010-Write-Print-Line2
                     end-if
                     exit perform
              end-if
     end-perform.
*>
 ba060-CopyPaths-End.
     if       Return-Code = 26        *> foo.ext
              add  1 to WS-Error-Count
              move spaces to formatted-line
              if   No-Printing
                   string "*> "
                          Msg2 into PL-Text
                   end-string
              else
                   move   Msg2   to PL-Text
              end-if
     end-if
     if       Return-Code = 25        *> foo
              add  1 to WS-Error-Count
              move spaces to formatted-line
              if   No-Printing
                   string "*> "
                          Msg7 into PL-Text
                   end-string
              else
                   move   Msg7   to PL-Text
              end-if
     end-if
     if       Return-Code not = zero
              perform zz010-Write-Print-Line2
              go     to ba000-process
     end-if.
*>
 ba070-Print-Loop.                                             *> process COPY lib source
*>
     move     WS-Free to Fht-Source-Format (Fht-Table-Size).   *> copy format to current table record
     go       to ba000-process.
*>
 ba999-Exit.
     exit     section.
*>
 bb000-Copy-Setup Section.
*>***********************
*>
*>   **********************************************************************
*>   * Here a ' copy ' word has now been found, we build Input-buffer     *
*>   *  containing the entire copy statement instead of reading over      *
*>   *  multiple source records.                                          *
*>   * While doing so we can set the found-Replacing flag.                *
*>   *    and other related fields so we can process the full copy        *
*>   *        statement in one hit.  Well that's the theory !!            *
*>   *                                                                    *
*>   *  Then return to main process loop to act on it having set index    *
*>   *  to point at next word after 'COPY '                               *
*>   *                       NOT SURE OF THIS BIT AT ALL!!                *
*>   *====================================================================*
*>   * As the standard is that ALL COPY statements end in a period, the   *
*>   * search will terminate on finding one at the end of a input record. *
*>   *                                                                    *
*>   **********************************************************************
*>
 bb000-Start.
*>
*>  Get rid of noise chars, eg tab, ; and , then pack it, replacing all continuous multi-spaces to only one
*>
     inspect  Input-Record replacing all x"09" by space   *> TAB
                                         X"0D" by space   *> CR
                                         x"00" by space   *> null
                                         " ; " by "   "
                                         " , " by "   "
                                         ": "  by "  "
                                         ", "  by "  ".
     move     zero to WS-P3 WS-P4.
     move     spaces to Temp-Input-Record.
     if       WS-Fixed-Set
              move 8 to WS-P5
     else
              move 1 to WS-P5
     end-if
*>
*>   WE ARE NOT (YET) SUPPORTING CONTINUE LINES WITH '&' or '-' in cc7 etc in copy statement or source ??
*>   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*>
     perform  varying WS-P3 from WS-P5 by 1 until WS-P3 > IR-Buffer-Data-Size
              if     IR-Buffer (WS-P3:1) = quote or "'"
                     add 1 to WS-P4
                     move IR-Buffer (WS-P3:1) to TIR (WS-P4:1)
                     perform forever
                            add   1 to WS-P3
                            add   1 to WS-P4
                            move  IR-Buffer (WS-P3:1) to TIR (WS-P4:1)
                            if    IR-Buffer (WS-P3:1) = quote or "'"
                                  add 1 to WS-P3
                                  exit perform
                            end-if
                     end-perform
              end-if                                          *> Done quoted literals
              if     IR-Buffer (WS-P3:2) = "*>"
                     exit perform
              end-if
              if     WS-P3 > IR-Buffer-Data-Size              *> just in case
                     exit perform
              end-if
              if     IR-Buffer (WS-P3:1) not = space and WS-P3 not > IR-Buffer-Data-Size
                     add    1 to WS-P4
                     move   IR-Buffer (WS-P3:1) to TIR (WS-P4:1)
              end-if
              if    IR-Buffer (WS-P3:1) = space and WS-P3 not > IR-Buffer-Data-Size
                    add 1 to WS-P4
                    add 1 to WS-P3
                    perform until IR-Buffer (WS-P3:1) not = space
                               or WS-P3 > IR-Buffer-Data-Size
                                  add 1 to WS-P3
                    end-perform
                    subtract 1 from WS-P3
              end-if
     end-perform
*>
*>  Now we have no excessive spaces
*>
     move     Temp-Input-Record to Input-Record.
     move     WS-P4 to IR-Buffer-Data-Size.
*>
 bb010-Start-Complete.
*>
     move     zero to IB-Size.
     perform  varying WS-P3 from 1 by 1 until WS-P3 > IR-Buffer-Data-Size
              if     function upper-case (IR-Buffer (WS-P3:5)) = "COPY "
                     set CRT-Copy-Found (CRT-Table-Size) to true
                     set CRT-Active (CRT-Table-Size)    to true
                     compute WS-P4 = IR-Buffer-Data-Size - (WS-P3 - 1)
                     add 1 to IB-Size
                     move IR-Buffer (WS-P3:WS-P4) to Input-Buffer (IB-Size:WS-P4)
                     add WS-P4  to IB-Size
                     subtract 1 from IB-Size
                     if  IR-Buffer (IR-Buffer-Data-Size:2) = ". "    *> End of Copy statement
                      or IR-Buffer (IR-Buffer-Data-Size - 1:2) = ". "
                      or Input-Buffer (IB-Size:1) = "."
                         go to bb030-Got-Full-Copy-Statement
                     end-if
                     exit perform
              end-if
     end-perform
     if       Fht-Eof (Fht-Table-Size)
              go to bb030-Got-Full-Copy-Statement.
*>
 bb020-Get-More-Copy.
*>
*> Now get rest of copy line 2 onwards
*>
     perform  zz600-Read-File thru zz600-Exit.
     if       Fht-Eof (Fht-Table-Size)                               *> Should not happen if copy end with '.'
              perform zz500-Close-File thru zz500-Exit
              if  Fht-Table-Size > zero
                  move CRT-Instance (CRT-Table-Size) to WS-CRT-Instance  *> restore active table
                  move CRT-Table-Size to WS-CRT-Active-Copy-Table
              else
                  initialize WS-CRT-Instance           *> THIS Should never happen as it means no more data
                  display Msg8                         *> for source file unless the user/programmer cocked up (no '.')!!
                  move spaces to formatted-line
                  if   No-Printing
                       if   WS-Free-Set
                            string "*>> "
                                   Msg8 into PL-Text
                            end-string
                       else
                            string "      ** "
                                   Msg8 into PL-Text
                            end-string
                       end-if
                  else
                       move Msg8  to PL-Text
                  end-if
                  perform zz010-Write-Print-Line2
                  go to ba999-Exit
              end-if
              if  WS-Fixed-Set                         *> Now to cover butt & make sure a '.' is in record
                  move "." to Input-Buffer (72:1)
              else
                  move "." to Input-Buffer (255:1)
              end-if
              go to bb030-Got-Full-Copy-Statement
     end-if
*>
     move     Fht-Current-Rec (Fht-Table-Size) to Input-Record.
     perform  da000-Check-For-Source.                  *> JIC >>source inside copy
     if       Fht-Free (Fht-Table-Size)
              set WS-Free-Set to true
     else
              set WS-Fixed-Set to true
     end-if
*>
*> Find size of source record (max = 255 as per specs) & start of source
*>
     perform  varying IR-Buffer-Data-Size from WS-End by -1 until  IR-Buffer (IR-Buffer-Data-Size:1) not = " "
                                                                or IR-Buffer-Data-Size < 2
     end-perform
     if       IR-Buffer (IR-Buffer-Data-Size:1) = x"0D" or x"00"
              subtract 1 from IR-Buffer-Data-Size
     end-if
*>
     perform  zz100-Headings.
     move     zeros to PL-line-number.
     Move     space To PL-Filler-1.
     if       Fht-Table-Size > 1
              move Fht-Table-Size to PL-Level
     end-if
     Move     Input-Record To PL-Text.
     if       Print-On
              perform zz010-Write-Print-Line3
     end-if
*>
     perform  bb000-Start.                                         *>  WE NEED TO CONSIDER CODE FOR Lit continuation (-) etc
     perform  varying WS-P3 from 1 by 1 until WS-P3 > IR-Buffer-Data-Size or IR-Buffer (WS-P3:2) = ". "
              if     function upper-case (IR-Buffer (WS-P3:3)) = "IN " or = "OF "
               or    function upper-case (IR-Buffer (WS-P3:9)) = "SUPPRESS "
               or    function upper-case (IR-Buffer (WS-P3:10)) = "REPLACING "
                     compute WS-P4 = IR-Buffer-Data-Size - (WS-P3 - 1)
                     add 2 to IB-Size                              *> leave a space before next chars
                     move IR-Buffer (WS-P3:WS-P4) to Input-Buffer (IB-Size:WS-P4)
                     add WS-P4 to IB-Size
                     if  IR-Buffer (IR-Buffer-Data-Size:2) = ". "  *> End of copy
                         go to bb030-Got-Full-Copy-Statement
                     end-if
                     exit perform
              end-if
              if     IR-Buffer (WS-P3:1) not = space
                     compute WS-P4 = IR-Buffer-Data-Size - (WS-P3 - 1)
                     add 2 to IB-Size
                     move IR-Buffer (WS-P3:WS-P4) to Input-Buffer (IB-Size:WS-P4)
                     add WS-P4 to IB-Size
                     if  IR-Buffer (IR-Buffer-Data-Size:2) = ". "   *> End of copy
                         go to bb030-Got-Full-Copy-Statement
                     end-if
                     exit perform
              end-if
     end-perform
     if       Fht-Eof (Fht-Table-Size)
              go to bb030-Got-Full-Copy-Statement.
     go       to bb020-Get-More-Copy.
*>
 bb030-Got-Full-Copy-Statement.
*>
*> Now process Copy buffer and store elements of it into CRT table for later processing
*>
     move     Input-Buffer to CRT-Copy-Statement (CRT-Table-Size).  *> NEEDED - not yet??
     move     IB-Size      to CRT-Copy-Length (CRT-Table-Size).
*>
     move     function upper-case (Input-Buffer) to CInput-Buffer.
     move     CRT-Instance (CRT-Table-Size) to WS-CRT-Instance.     *> copied to current copy area 4 easier working
*>
     perform  varying WS-P3 from 1 by 1 until WS-P3 > IB-Size
                                           or CInput-Buffer (WS-P3:2) = ". "
              if      CInput-Buffer (WS-P3:5)  = "COPY "
                      add 5 to WS-P3  *> now process copyfilename
                      unstring Input-Buffer delimited by ". " or space   *> Will be getting word or literal
                               into WS-CRT-Copy-FileName
                                   delimiter Word-Delimit2
                                   pointer   WS-P3
                      end-unstring
                      if       WS-CRT-Copy-FileName (1:1) = quote or "'"
                               set WS-CRT-Quote-Found to true
                               if WS-CRT-Copy-FileName (1:1) = quote
                                  move quote to WS-CRT-Quote-Type
                               else
                                  move "'" to WS-CRT-Quote-Type
                               end-if
                      end-if
                      if       Word-Delimit2 = ". "                     *> End of Copy
                               exit perform
                      end-if
              end-if
              if      CInput-Buffer (WS-P3:3) = "IN " or "OF "
                      add 3 to WS-P3
                      set WS-CRT-COPY-Lib-Found to true
                      if   CInput-Buffer (WS-P3:1) = "'" or quote
                           add 1 to WS-P3
                      end-if
                      unstring Input-Buffer delimited by space or "'" or quote      *> Use original
                          into WS-CRT-Copy-Library
                                   pointer WS-P3
                      end-unstring
                      add 1 to WS-P3
              end-if
              if      CInput-Buffer (WS-P3:18) = " SUPPRESS PRINTING" *> so same as no print OF COPYLIB
                      set WS-CRT-Suppress to true                     *> NOT copy statement
                      add 18 to WS-P3
              end-if
              if      CInput-Buffer (WS-P3:17) = "SUPPRESS PRINTING"  *> so same as no print OF COPYLIB
                      set WS-CRT-Suppress to true        *> NOT copy statement
                      add 17 to WS-P3
              end-if
              if      CInput-Buffer (WS-P3:9) = " SUPPRESS"           *> so same as no print OF COPYLIB
                      set WS-CRT-Suppress to true
                      add 9 to WS-P3
              end-if
              if      CInput-Buffer (WS-P3:8) = "SUPPRESS"            *> so same as no print OF COPYLIB
                      set WS-CRT-Suppress to true
                      add 8 to WS-P3
              end-if
              if      CInput-Buffer (WS-P3:10) = "REPLACING "
                      add   10 to WS-P3
                      add   1 to WS-CRT-Replacing-Count
                      set   WS-CRT-Replace-Found to true
                      if    CInput-Buffer (WS-P3:8) = "LEADING "
                            add 8 to WS-P3
                            set WS-CRT-Leading (WS-CRT-Replacing-Count) to true
                      end-if
                      if    CInput-Buffer (WS-P3:9) = "TRAILING "
                            add 9 to WS-P3
                            set WS-CRT-Trailing (WS-CRT-Replacing-Count) to true
                      end-if
                      if    Input-Buffer (WS-P3:1) = "="
                            set WS-CRT-RT-Pseudo (WS-CRT-Replacing-Count) to true
                      else
                       if   Input-Buffer (WS-P3:1) = quote or "'"
                            set WS-CRT-RT-Lit (WS-CRT-Replacing-Count) to true
                       else                                          *> covers programmer variable
                            set WS-CRT-RT-Else (WS-CRT-Replacing-Count) to true
                       end-if
                      end-if
                      move     WS-P3 to WS-P4                        *> start CC of field
                      unstring Input-Buffer delimited by space       *> Use original
                          into WS-CRT-Replacing-Source (WS-CRT-Replacing-Count)
                                   pointer WS-P3
                      end-unstring
                      subtract WS-P4 1 from WS-P3 giving WS-P4       *> End CC + 1 of field
                      move     WS-P4 to WS-CRT-Source-Size (WS-CRT-Replacing-Count)
                      add      3  to  WS-P3                          *> bypass 'BY '
                      move     WS-P3 to WS-P4                        *> start CC of field
                      unstring Input-Buffer delimited by space or ". "
                          into WS-CRT-Replacing-Target (WS-CRT-Replacing-Count)
                                 delimiter Word-Delimit2 pointer WS-P3
                      end-unstring
                      subtract WS-P4 1 from WS-P3 giving WS-P4       *> End CC + 1 of field
                      if       Word-Delimit2 = ". "
                               subtract 1 from WS-P4
                      end-if
                      move     WS-P4 to WS-CRT-Target-Size (WS-CRT-Replacing-Count)
              end-if
              if      CInput-Buffer (WS-P3:1) not = space
                      add   1 to WS-CRT-Replacing-Count
                      if    CInput-Buffer (WS-P3:8) = "LEADING "
                            add 8 to WS-P3
                            set WS-CRT-Leading (WS-CRT-Replacing-Count) to true
                      end-if
                      if    CInput-Buffer (WS-P3:9) = "TRAILING "
                            add 9 to WS-P3
                            set WS-CRT-Trailing (WS-CRT-Replacing-Count) to true
                      end-if
                      if    Input-Buffer (WS-P3:1) = "="
                            set WS-CRT-RT-Pseudo (WS-CRT-Replacing-Count) to true
                      else
                       if   Input-Buffer (WS-P3:1) = quote or "'"
                            set WS-CRT-RT-Lit (WS-CRT-Replacing-Count) to true
                       else                                          *> covers programmer variable
                            set WS-CRT-RT-Else (WS-CRT-Replacing-Count) to true
                       end-if
                      end-if
                      move     WS-P3 to WS-P4                        *> start CC of field
                      unstring Input-Buffer delimited by space       *> Use original
                          into WS-CRT-Replacing-Source (WS-CRT-Replacing-Count)
                                   pointer WS-P3
                      end-unstring
                      subtract WS-P4 1 from WS-P3 giving WS-P4       *> End CC + 1 of field
                      move     WS-P4 to WS-CRT-Source-Size (WS-CRT-Replacing-Count)
                      add      3  to  WS-P3                             *> bypass 'BY '
                      move     WS-P3 to WS-P4                        *> start CC of field
                      unstring Input-Buffer delimited by space or ". "
                          into WS-CRT-Replacing-Target (WS-CRT-Replacing-Count)
                                  delimiter Word-Delimit2 pointer WS-P3
                      end-unstring
                      subtract WS-P4 1 from WS-P3 giving WS-P4       *> End CC + 1 of field
                      if       Word-Delimit2 = ". "
                               subtract 1 from WS-P4
                      end-if
                      move     WS-P4 to WS-CRT-Target-Size (WS-CRT-Replacing-Count)
              end-if
     end-perform.
*>
 bb040-Clean-Up.
     move     WS-CRT-Instance to CRT-Instance (CRT-Table-Size).     *> copied to current copy area
*>
     if       We-Are-Testing3    *> Print the COPY statement from copy buffer in FULL
       and    WS-CRT-Active
              perform varying WS-P4 from 1 by 160 until WS-P4 > WS-CRT-Copy-Length
                       move  WS-CRT-Copy-Statement (ws-P4:160) to Formatted-Line
                       perform zz010-Write-Print-Line2
                       perform zz100-Headings
              end-perform
              move    spaces to Formatted-Line
              move  WS-CRT-Copy-FileName  to Formatted-Line
              perform zz010-Write-Print-Line2
              perform zz100-Headings
              move    spaces to Formatted-Line
              move    "CP Fnd = "  to Formatted-Line (1:9)
              move    WS-CRT-Copy-Found-Flag to Formatted-Line (10:1)
              move    " Rep Fnd = " to Formatted-Line (11:11)
              move    WS-CRT-Replace-Found-Flag to Formatted-Line (22:1)
              move    " QoT Fnd = " to Formatted-Line (23:11)
              move    WS-CRT-Quote-Found-Flag to Formatted-Line (34:1)
              move    " QoT Typ = " to Formatted-Line (35:11)
              move    WS-CRT-Quote-Type to Formatted-Line (46:1)
              move    " Lit Fnd = " to Formatted-Line (47:11)
              move    WS-CRT-Literal-Found-Flag to Formatted-Line (58:1)
              move    " Cont Fnd = " to Formatted-Line (59:12)
              move    WS-CRT-Continue-Flag to Formatted-Line (71:1)
              move    " Sup Flag = " to Formatted-Line (72:12)
              move    WS-CRT-Suppress-Flag to  Formatted-Line (84:1)
              move    " Repl Cnt = " to Formatted-Line (85:12)
              move    WS-CRT-Replacing-Count to Formatted-Line (97:3)
              perform zz010-Write-Print-Line2
              perform zz100-Headings
              move    spaces to Formatted-Line
              if      WS-CRT-Copy-Lib-Found
                      move    "IN/OF = "    to Formatted-Line (1:8)
                      move    WS-CRT-Copy-Library to Formatted-Line (9:152)  *> 1st 152 chars
                      perform zz010-Write-Print-Line2
                      perform zz100-Headings
              end-if
              move    spaces to Formatted-Line
              perform varying WS-P4 from 1 by 1 until WS-P4 > WS-CRT-Replacing-Count
                      move "Rep "   to Formatted-Line (1:4)
                      move  WS-P4   to WS-Disp
                      move  WS-Disp to Formatted-Line (5:3)
                      move  " Lead Fnd = " to Formatted-Line (8:12)
                      move  WS-CRT-Leading-Flag (WS-P4) to Formatted-Line (20:1)
                      move  " Tral Fnd = " to Formatted-Line (21:12)
                      move  WS-CRT-Trailing-Flag (WS-P4) to Formatted-Line (33:1)
                      move  " Rep Type = " to Formatted-Line (34:12)
                      if  WS-CRT-RT-Lit (WS-P4)   move "Lit" to Formatted-Line (46:3)
                      else
                       if WS-CRT-RT-Pseudo (WS-P4) move "Pse" to Formatted-Line (46:3)
                       else
                        if WS-CRT-RT-Else (WS-P4) move "Els" to Formatted-Line (46:3)
                        else
                                           move "Ops" to Formatted-Line (46:3)
                        end-if
                       end-if
                      end-if
                      move  " Src size = " to Formatted-Line (49:12)
                      move  WS-CRT-Source-Size (WS-P4) to WS-Disp2
                      move  WS-Disp2  to Formatted-Line (61:3)
                      move  " Tgt size = " to Formatted-Line (64:12)
                      move  WS-CRT-Target-Size (WS-P4) to WS-Disp2
                      move  WS-Disp2  to Formatted-Line (76:3)
                      perform zz010-Write-Print-Line2
                      perform zz100-Headings
                      move    spaces to Formatted-Line
                      move  WS-CRT-Replacing-Source  (WS-P4) (1:160) to Formatted-Line
                      perform zz010-Write-Print-Line2
                      perform zz100-Headings
                      move  WS-CRT-Replacing-Target  (WS-P4) (1:160) to Formatted-Line
                      perform zz010-Write-Print-Line2
                      perform zz100-Headings
              end-perform
     end-if
*>
*> Now we have dumped out the copy statement from source, concatinated source and as broken down in table.
*>
     go to bb000-Exit.
*>
 bb000-Exit.
     exit     section.
*>
 bc000-Test-For-Missing-Replace Section.
*>*************************************
*>
*>  We have CLOSED the file and table-size is now 1 less, so ...
*>
     move CRT-Instance (Fht-Table-Size + 1) to WS-CRT-Instance.      *> copy file closed so sames as fht ???
     if       WS-CRT-Replacing-Count = zero
              go to bc999-Exit.
     perform  varying WS-P11 from 1 by 1 until WS-P11 > WS-CRT-Replacing-Count
                                            or WS-CRT-Replacing-Count > CRT-Replace-Arguments-Size
*>              if       WS-CRT-Leading (WS-P11)
*>                or     WS-CRT-Trailing (WS-P11)
*>                       exit perform cycle
*>              end-if
              if       WS-CRT-Found-Src (WS-P11) = zero
                       move spaces to formatted-line
                       if   No-Printing
                            string "*> "
                                   Msg9 into PL-Text
                            end-string
                       else
                            move   Msg9   to PL-Text
                       end-if
                       perform zz010-Write-Print-Line2
                       add 1 to WS-Caution-Count
                       exit perform
              end-if
     end-perform.
*>
 bc999-Exit.
     exit     section.
*>
 bd000-Test-For-Messages Section.
*>******************************
*>
     move spaces to Print-Line.
     perform  zz010-Write-Print-Line2.
     move  1 to a.
     string   " Info: Total Copy Depth Used = " delimited by size
              Max-Copy-Depth                    delimited by size
                      into Print-Line pointer a.
     if       WS-Error-Count > zero
              move WS-Error-Count  to WS-Disp2
              string  ";  Files not Found = "   delimited by size
                      WS-Disp2                  delimited by size
                           into Print-Line pointer a
              end-string
     end-if
     if       WS-Caution-Count > zero
              move    WS-Caution-Count to WS-Disp2
              string  ";  Caution messages issued = " delimited by size
                      WS-Disp2                  delimited by size
                           into Print-Line pointer a
              end-string
     end-if
     perform  zz010-Write-Print-Line2.
*>
 bd999-Exit.
     Exit     Section.
*>
 ca000-End-of-Job Section.
*>***********************
*>
     close    print-file.
*>
     if       Print-It-Out = 1
              call "SYSTEM" using Print-Report.
*>
     exit     section.
*>
 da000-Check-For-Source section.
*>*****************************
*>
*> Check for existance of >>SOURCE in line at cc8 and if found looks
*> for FREE or FIXED, then changes free/fixed mode for the current file
*>      in Input-Record
*>
     move     zero to WS-P7
                      WS-P8.
     move     function upper-case (Input-Record) to Temp-Input-Record.
     if       Temp-Input-Record (8:8) not = ">>SOURCE"
              go to da000-Exit.
     inspect  Temp-Input-Record tallying WS-P7 for leading "FREE".
     inspect  Temp-Input-Record tallying WS-P8 for leading "FIXED".
     if       WS-P8 > zero
              set Fht-Fixed (Fht-Table-Size) to true
              move 72   to WS-End
     end-if
     if       WS-P7 > zero
              set  Fht-Free (Fht-Table-Size) to true
              move 256  to WS-End
     end-if
     move     zero to WS-P7 WS-P8.
*>
 da000-Exit.
     exit     section.
*>
 zz010-Write-Print-Line1 Section.
*>******************************
*>
     if       No-Printing
*> try this!!
              perform  zz030-Test-For-Copy
              if  WS-P6 not = zero
                  if  WS-Fixed-Set
                      move PL-Text to Formatted-Line         *> Hopefully will work
                      move "*" to Formatted-Line (7:1)
                  else
                      string "*>"     delimited by size
                              PL-Text delimited by size into Formatted-Line
                      end-string
                  end-if
              else
                  move PL-Text to Formatted-Line
              end-if
*>              move zero to u
*>              perform varying t from 9 by 1 until t > 160
*>                    add 1 to u
*>                    move Formatted-Line (t:1) to Formatted-Line (u:1)
*>              end-perform
              move spaces to Formatted-Line (153:8)
              write Formatted-Line
     else
              if    not WS-CRT-Suppress
                    write Print-Line after 1
                    add 1 to WS-Page-Line-Counter
              end-if
     end-if
     move     zero to WS-P6.
*>
*> More variations for above ???
*>
 zz010-Write-Print-Line2 Section.
*>******************************
*>
     if       No-Printing
              move PL-Text to Formatted-Line         *> Works with OC
              move spaces to Formatted-Line (153:8)
              write Formatted-Line
     else
              write Print-Line after 1
              add 1 to WS-Page-Line-Counter
     end-if.
*>
 zz010-Write-Print-Line3 Section.
*>******************************
*>
*> Only called when processing a COPY statements sub-clauses
*>
     if       No-Printing
              if  WS-Fixed-Set
                  move PL-Text to Formatted-Line
                  move "*" to Formatted-Line (7:1)
              else
                  string "*>"     delimited by size
                          PL-Text delimited by size into Formatted-Line
                  end-string
              end-if
              move spaces to Formatted-Line (153:8)
              write Formatted-Line
     else
              write Print-Line after 1
              add 1 to WS-Page-Line-Counter
     end-if.
*>
 zz020-Get-Program-Args     section.
*>*********************************
*>
 zz020a-start.
*>
*> Get Env. Variables
*>
     accept   Cobcpy        from Environment "COBCPY".
     accept   Cob_Copy_Dir  from Environment "COB_COPY_DIR".
*>
*>    if both the same only use COBCPY
*>
     if       Cobcpy = Cob_Copy_Dir
              move spaces to Cob_Copy_Dir
     end-if
*>
*> See if we have all Mandatory params otherwise we will request
*>   them manually having given details of required params
*>
     accept   Arg-Number from argument-number.
     if       Arg-Number < 4 or > 5
              display " " at 0101 with erase eos
              display WS-Name-Program " Usage:"
              display " "
              display " Prtcbl P1 P2 P3 P4 P5"
              display "  P1: Input Filename"
              display "  P2: Output-Filename"
              display "  P3: Source format [-fixed or -free, fixed or free]"
              display "  P4: PSN (Print Spool Name)"
              display "  P5: 'Temp-CopyLib-Path'"
              display " "
              display " P1 thru P4 are Mandatory"
              display " "
              display " Prtcbl also looks for Open Cobol Env. variables"
              display "  COBCPY and COB_COPY_DIR for copy library search paths"
              display " "
              display " Hit return to accept parameters manually"
              accept  Hold-Word1 (1:1)
              move    space to Hold-Word1 (1:1)
              go      to zz020-exit
     end-if .
*>
 zz020b-get-args.
     move     zero to z.
     perform  Arg-Number times
              add     1 to z
              move spaces to Arg-Test
              accept  Arg-Value (z) from Argument-Value
              if     z = 3
                     move function upper-case (Arg-Value (z)) to Arg-Test
              else
                     move Arg-Value (z) to Arg-Test
              end-if
              if      z = 1
                      move Arg-Test to WS-Input-File-Name
              end-if
              if      z = 2
                      move Arg-Test to WS-Print-File-Name
              end-if
              if      z = 3 and (Arg-Test (1:6) = "-FIXED" or "FIXED ")
                      set ws-fixed-set to true
              end-if
              if      z = 3 and (Arg-Test (1:5) = "-FREE" or "FREE ")
                      set ws-free-set to true
              end-if
              if      z = 4
                      move Arg-Test  to PSN
              end-if
              if      z = 5
                      exit perform
              end-if
     end-perform.
     perform zz020d-Process-CopyLibs thru zz020f-Get-CobCopyDir.
     move     zero to x z.
*>
*>  \******************************/
*>   \  We now have (if present): /
*>    \**************************/
*>
*>  From P! = Input File Name   thats in current directory
*>  From P2 = Output/Print file going in current directory
*>  From P3 = -Fixed | Fixed or -Free | Free for type of source code
*>  From P4 = PSN (Print Spool Name)
*>  From P5 = The Path of one or more Copy Libraries But not more than 9 eg, foo:bar:nuts
*>     which should be more than enough for anyone !!
*>      where No-Of-Copy-Dirs = number of ALL copylib paths
*>        stored in Copy-Lib (n) where n = 0(none), 1 - 10
*>                    Happy days!!
 zz020c-Disp-Data.
     if       not We-Are-Testing
              move   zero to x y z
              go     to zz020-exit.
     display " Program Args found:".
     display "Input  = " WS-Input-File-Name.
     display "Output = " WS-Print-File-Name.
     display "Format = " no advancing.
     if      ws-Fixed-Set
             display "Fixed"
     else
      if     ws-free-set
             display "Free"
      end-if
     end-if.
     display "PSN    = " PSN.
     display "Copy Libraries to search:".
     move    No-Of-Copy-Dirs to y.
     perform varying z from 1 by 1 until z > No-Of-Copy-Dirs
             move Copy-Lib (z) to Arg-Test
             display z "/" y " " Arg-Test (1:72)   *> restrict total display line to 79 (stops wrapping)
     end-perform.
     display " ".
     move     zero to x y z.
     go       to zz020-exit.
*>
 zz020d-Process-CopyLibs.
*>
*> If arg 5 exists, it will supersede values from COBCPY / COB_COPY_DIR
*>  as 1ist path
*>
     initialize Copy-Dirs-Block.
     move     zero to No-Of-Copy-Dirs.
     move     "Z" to Uns-Delimiter.
     if       z not = 5
              go to zz020e-get-cobcpy  *> skip P4 procesing
     end-if
*>
     move 1 to x.
     perform forever
           if   Uns-Delimiter = " "
            or  x > 498
            or  No-Of-Copy-Dirs > 9
                exit perform
           end-if
           add  1 to No-Of-Copy-Dirs
           unstring Arg-Test delimited by ":" or " " into Copy-Lib (No-Of-Copy-Dirs)
                           delimiter Uns-Delimiter    pointer x
           end-unstring
     end-perform
     move     "Z" to Uns-Delimiter.
*>
 zz020e-Get-CobCpy.
*>
*> Done P5, now do Env Vars
*>
     if       Cobcpy (1:1) not = " "
              move 1 to x
              perform forever
                    if   Uns-Delimiter = " "
                     or  x > 498
                     or  No-Of-Copy-Dirs > 9
                         exit perform
                    end-if
                    add  1 to No-Of-Copy-Dirs
                    unstring Cobcpy   delimited by ":" or " "  into Copy-Lib (No-Of-Copy-Dirs)
                                 delimiter Uns-Delimiter    pointer x
                    end-unstring
              end-perform
     end-if
     move     "Z" to Uns-Delimiter.
*>
 zz020f-Get-CobCopyDir.
     if       cob_copy_dir (1:1) not = " "
              move 1 to x
              perform forever
                    if   Uns-Delimiter = " "
                     or  x > 498
                     or  No-Of-Copy-Dirs > 9
                         exit perform
                    end-if
                    add  1 to No-Of-Copy-Dirs
                    unstring Cob_Copy_Dir delimited by ":" or " " into Copy-Lib (No-Of-Copy-Dirs)
                                 delimiter in Uns-Delimiter   pointer x
                    end-unstring
              end-perform
     end-if.
*>
 zz020-Exit.
     exit     section.
*>
 zz030-Test-For-Copy section.
     move     zero to WS-P6.                         *> non zero indicates copy statement present
     if       not No-Printing
              go to zz030-Exit.
     if       (WS-Fixed-Set and IR-Buffer (7:1) = "*")
         or   (WS-Fixed-Set and IR-Buffer (7:1) = "-")                  *> Literal
         or   (WS-Fixed-Set and (IR-Buffer (7:1) = "D" or = "d"))       *> Debug with COPY  ????
         or   (WS-Free-Set and IR-Buffer (1:2) = "*>")
         or   (WS-Free-Set and IR-Buffer (1:1) = "$")
         or   (WS-Free-Set and IR-Buffer (1:1) = "#")
              go to zz030-Exit
     end-if
     inspect  function upper-case (IR-Buffer) tallying WS-P6 for all "COPY ".
     if       WS-P6 = zero
              go to zz030-Exit.
*>
*> We have a COPY
*>
     set      Found-Word   to false.
     set      Found-Number to false.
*>
     perform  varying WS-P6 from 1 by 1 until WS-P6 > IR-Buffer-Data-Size - 7
                                           or IR-Buffer (WS-P6:2) = ". " or "*>"
              if       NOT Found-Number and Found-Word
                and    (function upper-case (IR-Buffer (WS-P6:6)) = " COPY "
                or     (WS-P1 = 1
                   and function upper-case (IR-Buffer (1:5)) = "COPY "))
                       move zero to WS-P6
                       exit perform
              end-if
              if       IR-Buffer (WS-P6:1) = quote or "'"
                       add 1 to WS-P6
                       perform varying WS-P6 from WS-P6 by 1 until IR-Buffer (WS-P6:1) = quote
                                                                or "'"
                                                                or WS-P6 > IR-Buffer-Data-Size - 7
                       end-perform                     *> lose the literal or line
                       if   WS-P6 > IR-Buffer-Data-Size - 7
                            move zero to WS-P6
                            exit perform
                       end-if
              end-if
              if       function upper-case (IR-Buffer (WS-P6:6)) = " COPY "
                       exit perform
              end-if
              if       WS-P1 = 1 and function upper-case (IR-Buffer (1:5)) = "COPY "
                       exit perform
              end-if
              move     IR-Buffer (WS-P6:1) to WS-Number-Test
              if       WS-Number numeric
                       set Found-Number to true
              end-if
              if       WS-Number-Test is Alphabetic
                 and   WS-Number-Test not = space
                       set Found-Word   to true
              end-if
     end-perform.
*>
 zz030-Exit.
     exit section.
*>
*>eject
*>  Multi-depth copy level support. Init code.
*>
 zz100-Headings      Section.
     if       No-Printing
              go to  zz100-Exit.
     if       WS-Page-Line-Counter not > WS-Page-Lines
              go to  zz100-Exit.
     move     spaces                to Print-Line.
     add      1                     to WS-Page-Number.
     if       WS-Page-Number not = 1
              write Print-Line after 1.
     move     function Current-Date to Ws-Current-Date.
     move     WS-Input-File-Name    to Print-Line.
     move     "Cobol Source Print"  to Print-Line (25:18).
     move     "("                   to Print-Line (44:1).
     move     WS-Name-Program       to Print-Line (45:15).
     move     ")"                   to Print-Line (60:1).
*>
*>    Now dates in three flavours
*>    ===========================
*> UK - dd/mm/ccyy
*>
     if       LTZ-UK
              string
                     WS-Current-Date (7:2) delimited by size  *> DD
                     "/"                   delimited by size
                     WS-Current-Date (5:2) delimited by size  *> MM
                     "/"                   delimited by size
                     WS-Current-Date (1:4) delimited by size  *> YY
                                               into print-line (69:10)
              end-string
     end-if
*>
*> USA - mm/dd/ccyy
*>
     if       LTZ-USA
              string
                     WS-Current-Date (5:2) delimited by size  *> MM
                     "/"                   delimited by size
                     WS-Current-Date (7:2) delimited by size  *> DD
                     "/"                   delimited by size
                     WS-Current-Date (1:4) delimited by size  *> YY
                                               into print-line (69:10)
              end-string
     end-if
*>
*> Intl/*Unix eg, ccyy/mm/dd
*>
     if       LTZ-Unix
              string WS-Current-Date (1:4) delimited by size  *> YY
                     "/"                   delimited by size
                     WS-Current-Date (5:2) delimited by size  *> MM
                     "/"                   delimited by size
                     WS-Current-Date (7:2) delimited by size  *> DD
                                               into print-line (69:10)
              end-string
     end-if
*>
*>  and now comes the time as hh:mm:ss.ms & Page no.
*>
     move     WS-Page-Number to WS-PPage.
     string   WS-Current-Date (9:2)
              ":"
              WS-Current-Date (11:2)
              ":"
              WS-Current-Date (13:2)
              "."
              WS-Current-Date (15:2)
              "  Page "
              WS-PPage                         into Print-Line (80:21)
     end-string
     move     zero to y.                        *> temp line cnt for printing run time params
     if       WS-Page-Number not = 1
              write Print-Line after page
     else
              write  Print-Line before 1
              move   spaces to print-line
              if     ws-Fixed-Set
                     move "Fixed" to Hold-Word1
              else
                     move "Free"  to Hold-Word1
              end-if
              string "Running with "     delimited by size
                     WS-Input-File-Name  delimited by space
                     ", "                delimited by size
                     WS-Print-File-Name  delimited by space
                     ", "                delimited by size
                     Hold-Word1          delimited by space
                     ", "                delimited by size
                     PSN                 delimited by space
                     " And "             delimited by size   into print-line
              end-string
              write  print-line before 1
              move   2 to y
              perform varying z from 1 by 1 until z > No-Of-Copy-Dirs
                     move "Copy Path 01 = " to print-line
                     move z            to print-line (11:2)
                     move Copy-Lib (z) to print-line (16:85)
                     write print-line before 1
                     add 1 to y
              end-perform
     end-if
     move     spaces to print-line.
     write    print-line after 1.
     add      3 to y giving WS-Page-Line-Counter.
     move     zero to y.
*>
 zz100-Exit.
     exit     Section.
*>
 zz300-Copy-Control Section.
*>*************************
*>=======================================================================
*>
*> zz300, zz400, zz500 & zz600 all relate to copy files/libraries via the COPY verb
*>
*>  this code allows for 9 levels of COPY, plus source file
*>
 zz300-Open-File.
*>**************
*> Open a Copy file using CBL-OPEN-File
*>  filename is using Cbl-File-name
*>
     move     zero to Return-Code.
     if       Fht-Table-Size > Fht-Max-Table-Size                *> 10
              move 24 to Return-Code                             *> RT 24 file table limit exceeded
              display Msg1
              go to zz300-Exit
     end-if
*>
*>   First test that we do NOT have duplicate copy's (within copy's)
*>
     if       Fht-Table-Size not = zero
              perform  varying fn from 1 by 1 until fn > Fht-Table-Size
                       if    Fht-File-Name (fn) = WS-Copy-File-Name
                             move 23 to Return-Code              *> RT 23 recursive copy filenames
                             go to zz300-Exit                    *> Prevents dead lock in prtcbl
                       end-if
              end-perform
     end-if
*>
*> set up New entry in File Table
*>
     add      1 to Fht-Table-Size.
     move     Fht-Table-Size to e.
     initialize Fht-Var-Block (e).
     move     Fht-Buffer-Size  to   Fht-Byte-Count (e).
     move     spaces to Fht-Current-Rec (e)
                        Fht-Buffer (e).
     move     1      to Fht-pointer (e).
*>
     perform  zz400-Check-File-Exists thru zz400-Exit.
     if       Return-Code not = zero             *> Could have 26, 25, 35 = no file found
                                                 *> 24 = table exceeded or another?
              subtract 1 from Fht-Table-Size
              go to zz300-Exit.
*>
     move     Fht-Table-Size to e.               *> just in case its been altered or used etc
     move     Cbl-File-Size to Fht-File-Size (e).
     move     Cbl-File-Name to Fht-File-Name (e).
     move     1    to Cbl-Access-Mode
                      Cbl-Deny-Mode.             *> deny write
     move     zero to Cbl-Device
                      Cbl-File-Handle.
     move     zero to Return-Code.
     call     "CBL_OPEN_FILE" using
              Cbl-File-name
              Cbl-Access-Mode
              Cbl-Deny-Mode
              Cbl-Device
              Cbl-File-Handle
     end-call
     if       Return-Code not = zero
              display Msg3 cbl-File-name (1:59)
              display "zz300 - This should not happen here"
              subtract 1 from Fht-Table-Size
              go to zz300-exit
     end-if
*>
     move     Cbl-File-Handle to Fht-File-Handle (e).
     add      1 to Copy-Depth.
     if       Copy-Depth > Max-Copy-Depth           *> Keep track of how deep we went!
              move Copy-Depth to Max-Copy-Depth.
 zz300-Exit.
     exit.
*>
 zz400-Check-File-Exists.
*>
*> Check for correct filename and extention, taken from COPY verb
*>
*>  Input : WS-Copy-File-Name     ( A copy lib path could precede FN )
*> Output : Return-Code = 0  :    Cbl-File-Details & Cbl-File-name
*>          Return-Code = 25/26 : Failed fn in WS-Copy-File-Name
*>
     move     zero to f.
     inspect  WS-Copy-File-Name tallying f for all ".".
     if       f not = zero                           *> We have 'copy foo.ext' or 'copy path/foo.ext'
        or    No-Search
              go to zz400-Try1
     end-if
     perform  varying a from 1 by 1  until Return-Code = zero or a > Ext-Table-Size
              move   spaces to Cbl-File-name
              string WS-Copy-File-Name delimited by space
                     File-Ext (a)      delimited by size into Cbl-File-name
              end-string
              move   zero to Return-Code
              if we-are-testing2
                  move spaces to formatted-line
                  string "Checking for "
                         Cbl-File-Name into formatted-line
                  end-string
                  perform zz010-Write-Print-Line2
              end-if
              call   "CBL_CHECK_FILE_EXIST" using
                                            Cbl-File-name
                                            Cbl-File-Details
              end-call
              if   Return-Code not = zero
               and a = Ext-Table-Size                           *> error 35 (well it should be)
                     exit perform                               *> and we tried all combinations
              end-if
     end-perform
     if       Return-Code not = zero    *> On, 'copy foo', NO .ext can be found on this copy lib path
              move 25 to Return-Code                            *> RT 25 - file not found
              if we-are-testing2
                  move spaces to formatted-line
                  string "Not found "
                         Cbl-File-Name into formatted-line
                  end-string
                  perform zz010-Write-Print-Line2
              end-if
              go to zz400-Exit
     end-if
*>                                                                 OK, file now found
     go       to zz400-Exit.
*>
 zz400-Try1.
*>
*> We have 'copy foo.ext' or 'copy path/foo.ext' OR it could be the main source file
*>
     move     WS-Copy-File-Name to Cbl-File-Name.
     move     zero to Return-Code.
     call     "CBL_CHECK_FILE_EXIST" using
              Cbl-File-name
              Cbl-File-Details
     end-call
     if       Return-Code not = zero
              move 26 to Return-Code             *> foo.ext not found (error 26)!
              if we-are-testing2
                  move spaces to formatted-line
                  string "We cant find "
                         Cbl-File-Name into formatted-line
                  end-string
                  perform zz010-Write-Print-Line2
              end-if
              go to zz400-Exit.
*>
*> OK, file now found
*>
        if we-are-testing2
            move spaces to formatted-line
            string "We have found "
                   Cbl-File-Name into formatted-line
            end-string
            perform zz010-Write-Print-Line2
        end-if.
 zz400-Exit.
     exit.
*>
 zz500-Close-File.
     call     "CBL_CLOSE_FILE" using Fht-File-Handle (Fht-Table-Size).
     if       Return-Code not = zero
              move return-code to WS-Disp3
              display Msg4 WS-Disp3
              display " on " Fht-File-Name (Fht-Table-Size)
     end-if
     subtract 1 from Fht-Table-Size.
*>
     subtract 1 from Copy-Depth.
     move     zero to Return-Code.
     go       to zz500-Exit.
*>
 zz500-Exit.
     exit.
*>
 zz600-Read-File.
*>**************
*> Called using file-handle returning  Fht-Current-Rec (Fht-Table-Size)
*>
*> If buffer enpty read a block and regardless,
*>     move record terminated by x"0a" to Fht-Current-Rec (Fht-Table-Size)
*>
     if       Fht-Eof (Fht-Table-Size) and Fht-Block-Eof (Fht-Table-Size)
*>              perform zz500-Close-File thru zz500-Exit
              go to zz600-Exit.
*>
     if       Fht-File-OffSet (Fht-Table-Size) = zero
         and  Fht-Block-OffSet (Fht-Table-Size) = zero
              perform zz600-Read-A-Block thru zz600-Read-A-Block-Exit
              if      Return-Code = -1 or = 10
                      set Fht-Block-Eof (Fht-Table-Size) to true
                      go to zz600-Exit
              end-if
              go to zz600-Get-A-Record.
*>
 zz600-Get-A-Record.
*>*****************
*> Now to extract a record from buffer and if needed read a block
*>         then extract
*>
     if       Fht-Eof (Fht-Table-Size)
         and  Fht-Block-Eof (Fht-Table-Size)
              go to zz600-Exit.
*>
     move     spaces to Fht-Current-Rec (Fht-Table-Size).
     add      1 to Fht-Block-OffSet (Fht-Table-Size) giving g.
*>
*> note size is buffer size + 1
*>
     unstring Fht-Buffer (Fht-Table-Size) (1:Fht-Buffer-Size + 1)    *>  1048577)  *> (1:4097)
                delimited by x"0A" or x"FF"
                into         Fht-Current-Rec (Fht-Table-Size)
                delimiter    Word-Delimit
                pointer      g.
*>
*> Get next Block of data ?
*>
     if       Word-Delimit = x"FF"
          and g not <  Fht-Buffer-Size + 1 *>  1048577     *> 4097
              add Fht-Block-OffSet (Fht-Table-Size) to Fht-File-OffSet (Fht-Table-Size)
              perform zz600-Read-A-Block thru zz600-Read-A-Block-Exit
              if      Return-Code = -1 or Fht-Block-Eof (Fht-Table-Size)
                      set Fht-Eof (Fht-Table-Size) to true
                      if we-are-testing2
                         move spaces to formatted-line
                         string "Blk/Rec EOF on "
                                Fht-File-Name (Fht-Table-Size) into formatted-line
                         end-string
                         perform zz010-Write-Print-Line2
                      end-if
                      go to zz600-Exit
              end-if
              go to zz600-Get-A-Record.
*> EOF?
     move     1 to Fht-Pointer (Fht-Table-Size).
     if       Word-Delimit = x"FF"
              set Fht-Eof (Fht-Table-Size) to true
              go to zz600-Exit.
*> So. now tidy up
     subtract 1 from g giving Fht-Block-OffSet (Fht-Table-Size).
     go       to zz600-exit.
*>
 zz600-Read-A-Block.
*>*****************
     if       Fht-Block-Eof (Fht-Table-Size)
*>              set Fht-Eof (Fht-Table-Size) to true
              go to zz600-Read-A-Block-Exit
     move     all x"FF" to Fht-Buffer (Fht-Table-Size).  *> next 2 put back
     if       Fht-File-Size (Fht-Table-Size) < Fht-Byte-Count (Fht-Table-Size) and not = zero   *> 4096
              move Fht-File-Size (Fht-Table-Size) to Fht-Byte-Count (Fht-Table-Size).
*>
     call     "CBL_READ_FILE" using
              Fht-File-Handle (Fht-Table-Size)
              Fht-File-OffSet (Fht-Table-Size)
              Fht-Byte-Count (Fht-Table-Size)
              Cbl-Flags
              Fht-Buffer (Fht-Table-Size)
     end-call
     if       Return-Code = -1 or = 10
              set Fht-Block-Eof (Fht-Table-Size) to true
              if we-are-testing2
                  move spaces to formatted-line
                  string "Blk EOF on "
                         Fht-File-Name (Fht-Table-Size) into formatted-line
                  end-string
                  perform zz010-Write-Print-Line2
              end-if
              go to zz600-Read-A-Block-Exit
     end-if
     if       Return-Code not = zero              *> Could be indicating EOF (-1 ? )
              set Fht-Block-Eof (Fht-Table-Size) to true
              move Return-Code to WS-Disp3
              move spaces to formatted-line
              if   No-Printing
                   string "*> "
                          Msg5
                          WS-Disp3 into PL-Text
                   end-string
              else
                   string Msg5
                          WS-Disp3 into PL-Text
                   end-string
              end-if
              perform zz010-Write-Print-Line2
              go to zz600-Read-A-Block-Exit
     end-if
*> just in case all ff does not work
     move     x"FF" to Fht-Buffer (Fht-Table-Size) (Fht-Buffer-Size + 1:1)     *>  1048577:1)          *> (4097:1).
     move     zero to Fht-Block-OffSet (Fht-Table-Size).
     subtract Fht-Byte-Count (Fht-Table-Size) from Fht-File-Size (Fht-Table-Size).
*>
 zz600-Read-A-Block-Exit.
     exit.
*>
 zz600-Exit.
     exit.
*>
 zz900-Process-Replace  Section.
*>*****************************
*>
*> Now we have read a RECORD first check if table < 2 (not a copylib)
*>  and check if active copy (active-table) has replacing active!
*>
     if       CRT-Table-Size < 1
              go to zz900-Exit.
     if       Fht-Table-Size > 1
              move CRT-Instance (Fht-Table-Size - 1) to WS-CRT-Instance
     else
              go to zz900-Exit
     end-if
     if       not WS-CRT-Replace-Found
              go to zz900-Exit.
*>
*> Process one at a time, Cannot see how to do it in one sweep !!
*>
     perform  varying WS-P11 from 1 by 1 until WS-P11 > WS-CRT-Replacing-Count
                                            or WS-CRT-Replacing-Count > CRT-Replace-Arguments-Size
*>              if       WS-CRT-Leading (WS-P11)
*>                or     WS-CRT-Trailing (WS-P11)
*>                       exit perform cycle
*>              end-if
              move  WS-CRT-Replacing-Source (WS-P11) to Temp-Replacing-Source
              move  WS-CRT-Replacing-Target (WS-P11) to Temp-Replacing-Target
              if    WS-CRT-RT-Lit (WS-P11)
                    subtract 2 from WS-CRT-Source-Size (WS-P11) giving WS-P12    *> skip quotes
                    subtract 2 from WS-CRT-Target-Size (WS-P11) giving WS-P13
                    inspect  Input-Record tallying WS-CRT-Found-Src (WS-P11) for all Temp-Replacing-Source (2:WS-P12)
                    move     function substitute (Input-Record                   *> Copy Record
                             Temp-Replacing-Source (2:WS-P12)
                             Temp-Replacing-Target (2:WS-P13)) to Temp-Record
                    move     Temp-Record to Input-Record
              end-if
              if    WS-CRT-RT-Pseudo (WS-P11)
                    subtract 4 from WS-CRT-Source-Size (WS-P11) giving WS-P12    *> skip the '==' & case no care
                    subtract 4 from WS-CRT-Target-Size (WS-P11) giving WS-P13
                    inspect  Input-Record tallying WS-CRT-Found-Src (WS-P11) for all Temp-Replacing-Source (3:WS-P12)
                    move     function substitute-case (Input-Record
                             Temp-Replacing-Source (3:WS-P12)
                             Temp-Replacing-Target (3:WS-P13)) to Temp-Record
                    move     Temp-Record to Input-Record
              end-if
              if    WS-CRT-RT-Else (WS-P11)
                    move     WS-CRT-Source-Size (WS-P11) to WS-P12               *> No skips as its a field name & case no care
                    move     WS-CRT-Target-Size (WS-P11) to WS-P13
                    inspect  Input-Record tallying WS-CRT-Found-Src (WS-P11) for all Temp-Replacing-Source (1:WS-P12)
                    move     function substitute-case (Input-Record
                             Temp-Replacing-Source (1:WS-P12)
                             Temp-Replacing-Target (1:WS-P13)) to Temp-Record
                    move     Temp-Record to Input-Record
              end-if
              move  WS-CRT-Found-Src (WS-P11) to CRT-Found-Src (Fht-Table-Size - 1, WS-P11)
     end-perform.
*>
 zz900-Exit.  Exit section.
*>*********   ************
*>
