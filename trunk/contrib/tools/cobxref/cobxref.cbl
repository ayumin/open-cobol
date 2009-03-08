       >>source free
 Identification division.
 program-id.            cobxref.
*>author.               Vincent Bryan Coen, Applewood Computers,
*>                      Applewood, Epping Road, Roydon, Essex, UK.
*>date-written.         28 July 1983 with code going back to 1967.
*>date-rewriten.        10 March 2007 with code going back to 1983.
*>date-compiled.        Today & Don't forget to update prog-name for builds
*>Security.             Copyright (C) 1967-2009, Vincent Bryan Coen.
*>                      Distributed under the GNU General Public License
*>                      v2.0. Only. See the file COPYING for details but
*>                      for use within Open Cobol ONLY.
*>
*> Usage.               Cobol Cross Referencer for Open Cobol from v1.0.
*>
*> Changes.             See Changelog & Prog-Name.
*>
*>*************************************************************************
*>
*> Copyright Notice.
*>*****************
*>
*> This file/program is part of Cobxref AND Open Cobol and is copyright
*> (c) Vincent B Coen 1967-2009. This version bears no resemblance to the
*> original versions running on ICL 1501/1901 and IBM 1401 & 360/30 in the
*> 1960's and 70's.

*> This program is free software; you can redistribute it and/or modify it
*> under the terms of the GNU General Public License as published by the
*> Free Software Foundation; version 2 ONLY within Open Cobol providing
*> the package continues to be issued or marketed as 'Open Cobol'.
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
 special-names.
     switch-1 is sn-Test-1 on snt1-on off snt1-off
     currency sign is "£".
 input-Output section.
 file-control.
*>
     select   Supplemental-Part2-In assign Supp-File-2
              organization line sequential.
*>
     select   Supplemental-Part1-Out assign Supp-File-1
              organization line sequential.
*>
     select   Source-Listing assign Print-FileName
              organization line sequential.
*>
     select   SourceInput assign SourceFileName
              organization line sequential
              file status fs-reply.
*>
     select   SortFile assign Sort1tmp.
*>
 i-o-control.
*>
     same record area for Supplemental-Part1-Out
                          Supplemental-Part2-In.
*>
 data division.
 file section.
 fd  Source-Listing.
 01  Source-List.
     03  sl-Gen-RefNo1     pic z(5)9bb.
     03  SourceOutput      pic x(1024).
*>
 01  PrintLine.
     02  XrDataName        pic x(32).
     02  XrDefn            pic 9(6).
     02  XrType            pic x.
     02  XrCond            pic x.
     02  filler            pic x.
     02  filler     occurs 8.
       03  XrReference     pic 9(6).
       03  filler          pic x.
     02  filler            pic x(62).
*>
 01  filler.
     03  filler            pic x(42).
     03  PL-Prog-Name      pic x(32).
*>
 01  PrintLine2.
     03  P-Conditions      pic x(32).
     03  P-Variables       pic x(32).
*>
 fd  SourceInput.
 01  SourceRecIn           pic x(1024).
*>
 fd  Supplemental-Part1-Out.
 01  SortRecord.
     03  SkaDataName       pic x(32).
     03  SkaWSorPD         pic 9.
     03  SkaWSorPD2        pic 9.
     03  SkaRefNo          pic 9(6).
*>
 fd  Supplemental-Part2-In.
 01  filler                pic x(40).
*>
 sd  SortFile.
 01  filler.
     03  SdSortKey         pic x(40).
*>
 working-storage section.
 77  Prog-Name             pic x(13) value "Xref v1.01.06".
 77  String-Pointer        Binary-long  value 1.
 77  String-Pointer2       Binary-long  value 1.
 77  S-Pointer             Binary-long  value zero.
 77  S-Pointer2            Binary-long  value zero.
 77  Line-Count            Binary-char  value 70.
 77  Word-Length           Binary-long  value zero.
 77  Line-End              Binary-long  value zero.
 77  Source-Line-End       Binary-long  value zero.
 77  Source-Words          Binary-long  value zero.
 77  F-Pointer             Binary-long  value zero.
 77  HoldFoundWord2-Size   binary-long  value zero.
 77  HoldFoundWord2-Type   binary-long  value zero.
 77  a                     Binary-Long  value zero.
 77  a1                    Binary-Long  value zero.
 77  b                     Binary-Long  value zero.
 77  c                     Binary-Long  value zero.
 77  d                     Binary-Long  value zero.
 77  e                     Binary-Long  value zero.
 77  s                     Binary-Long  value zero.
 77  s2                    Binary-Long  value zero.
 77  t                     Binary-Long  value zero.
 77  y                     Binary-Long  value zero.
 77  z                     Binary-Long  value zero.
 77  z2                    Binary-Long  value zero.
 77  z3                    Binary-Long  value zero.
 77  q                     Binary-Long  value zero.
 77  q2                    Binary-Long  value zero.
*>
*> System parameters control how xref works or reports
*>  May be add extra func for default.conf ?
*>
 77  sw-1                  pic x           value "N".
*>  command line input -G
  88 All-Reports                           value "A".
 77  sw-2                  pic x           value "N".
  88 List-Source                           value "Y".
 77  sw-4                  pic 9           value zero.
  88  Dump-Reserved-Words                  value 1.
 77  sw-5                  pic x           value "N".
  88 We-Are-Testing                        value "Y".
 77  sw-6                  pic 9           value zero.
  88  Reports-In-Lower                     value 1.
*>
*> Switches used during processing
*>
*> And these two are the size of any Cobol word currently set
*> to value specified in PL22.4 20xx
*>
 78  Cobol-Word-Size                       value 31.
 78  CWS                                   value 31.
*>
 77  sw-Source-Eof         pic 9           value 0.
  88 Source-Eof                            value 1.
*> got end of program
 77  sw-End-Prog           pic 9           value zero.
  88 End-Prog                              value 1.
*> Had end of program (nested) - Confused yet? you will be!
 77  sw-Had-End-Prog       pic 9           value zero.
  88 Had-End-Prog                          value 1.
*> We have found a Global verb
 77  sw-Git                pic 9           value zero.
  88 Global-Active                         value 1.
*>  Multi modules in one source file flag
 77  sw-Nested             pic 9           value zero.
  88 Have-Nested                           value 1.
*>
 77  Arg-Number            pic 99          value zero.
 77  Gen-RefNo1            pic 9(6)        value zero.
 77  Build-Number          pic 99          value zero.
 77  GotEndProgram         pic 9           value zero.
 77  GotPicture            pic 9           value zero.
 77  WasPicture            pic 9           value zero.
 77  Currency-Sign         pic X           value "£".
 77  HoldWSorPD            pic 9           value 0.
 77  HoldWSorPD2           pic 9           value 0.
 77  Word-Delimit          pic x           value space.
 77  Word-Delimit2         pic x           value space.
 77  OS-Delimiter          pic x           value space.
 77  GotASection           pic x           value space.
 *> section name + 8 chars
 77  HoldFoundWord         pic x(40)       value spaces.
 77  HoldFoundWord2        pic x(40)       value spaces.
 77  saveSkaDataName       pic x(32)       value spaces.
 77  Saved-Variable        pic x(32)       value spaces.
 77  saveSkaWSorPD         pic 9           value zero.
 77  saveSkaWSorPD2        pic 9           value zero.
 77  WS-Anal1              pic 9           value zero.
 77  fs-reply              pic 99          value zeros.
 77  SourceFileName        pic x(1024)     value spaces.
 77  Print-FileName        pic x(1024)     value spaces.
 77  Prog-BaseName         pic x(1024)     value spaces.
*>
*> in theory Linux can go to 4096 and Windoz 32,767
*>
 77  Temp-Pathname         pic x(1024)     value spaces.
 77  Supp-File-1           pic x(1036)     value spaces.
 77  Supp-File-2           pic x(1036)     value spaces.
 77  Sort1tmp              pic x(1036)     value spaces.
 77  Global-Current-Word   pic x(32)       value spaces.
 77  Global-Current-Refno  pic 9(6)        value zero.
 77  Global-Current-Level  pic 99          value zero.
*>
 01  HoldID                pic x(32)       value spaces.
 01  HoldID-Module         pic x(32)       value spaces.
*>
 01  SourceInWS.
     03  sv1what           pic x(16).
     03  filler            pic x(1008).
*>
 01  wsFoundWord.
     03  wsf1-3.
      04  wsf1-2.
       05  wsf1-1          pic x.
       05  filler          pic x.
      04  filler           pic x.
     03  filler            pic x(1021).
*>
 01  wsFoundWord2 redefines wsFoundWord.
     03  wsf3-1            pic 9.    *> only used for Build-Number
         88 wsf3-1-numeric           values 0 thru 9.
     03  wsf3-2            pic 9.    *>   processing
     03  filler            pic x(1022).
*>
 01  wsFoundNewWord        pic x(32).
 01  wsFoundNewWord2       pic x(32).
 01  wsFoundNewWord3       pic x(1024).  *> max size quot lit 1 lin
 01  wsFoundNewWord4       pic x(32).
 01  wsFoundNewWord5       pic x(1024). *> space removal source i/p
*>
 01  HDR1.
     03  filler            pic X(10) value "ACS Cobol ".
     03  H1Prog-Name       pic x(14) value spaces.
     03  filler            pic x     value "(".
     03  H1-dd             pic 99.
     03  filler            pic x     value "/".
     03  H1-MM             pic 99.
     03  filler            pic x     value "/".
     03  H1-YY             pic 9(4).
     03  filler            pic x     value "@".
     03  H1-HH             pic 99.
     03  filler            pic x     value ":".
     03  H1-Min            pic 99.
     03  filler            pic xx    value ") ".
     03  filler            pic x(20) value "Dictionary File for ".
     03  h1programid       pic x(60) value spaces.
*>
 01  HDR2.
     03  filler            pic X(33) value "All Data/Proc Names".
     03  filler            pic X(19) value "Defn     Reference".
*>
 01  hdr3.
     03  filler            pic x(32) value all "-".
     03  filler            pic x     value "+".
     03  filler            pic x(63) value all "-".
*>
 01  hdr5-symbols.
     03  filler            pic x(19) value "Symbols of Module: ".
     03  hdr5-Prog-Name    pic x(67) value spaces.
*>
 01  hdr6-symbols.
     03  filler            pic x(19) value all "-".
*>
*> below is replaced with hyphens to size of Prog-Name
*>
     03  hdr6-hyphens      pic x(67) value spaces.
*>
 01  hdr7-ws.
     03  filler            pic x(14) value "Data Section (".
     03  hdr7-variable     pic x(19) value spaces.
     03  filler            pic x(8)  value "Defn".
     03  filler            pic x(9)  value "Locations".
*>
 01  hdr8-ws.
     03  hdr8-hd           pic x(9)  value "Procedure".
     03  filler            pic x(24) value spaces.
     03  filler            pic x(8)  value "Defn".
     03  filler            pic x(9)  value "Locations".
*>
 01  hdr9.
     03  filler            pic x(36) value "Unreferenced Working Storage Symbols".
*>
 01  hdr9B.
     03  filler            pic x(38) value "Unreferenced Globals throughout Source".
*>
 01  hdr10.
     03  filler            pic x(23) value "Unreferenced Procedures".
*>
 01  hdr11.
     03  filler            pic x(16) value "Variable Tested".
     03  hdr11a-sorted     pic xxx   value spaces.
     03  filler            pic x(12) value spaces.
     03  filler            pic x(8)  value "Symbol (".
     03  filler            pic x(15) value "88-Conditions)".
     03  hdr11b-sorted     pic xxx   value spaces.
     03  filler            pic x(5)  value spaces.
*>
 01  hdr12-hyphens.
     03  filler            pic x(62) value all "-".
*>
 01  hdtime                          value spaces.
     03  hd-hh             pic xx.
     03  hd-mm             pic xx.
     03  hd-ss             pic xx.
     03  hd-uu             pic xx.
 01  hddate                          value spaces.
     03  hd-y              pic xx.
     03  hd-m              pic xx.
     03  hd-d              pic xx.
*>
 01  hd-date-time.
     03  hd2-d             pic xx.
     03  filler            pic x     value "/".
     03  hd2-m             pic xx.
     03  filler            pic x     value "/".
     03  hd2-y             pic xx.
     03  filler            pic xx    value spaces.
     03  hd2-hh            pic xx.
     03  filler            pic x     value ":".
     03  hd2-mm            pic xx.
     03  filler            pic x     value ":".
     03  hd2-ss            pic xx.
     03  filler            pic x     value ":".
     03  hd2-uu            pic xx.
*>
 01  WS-When-Compiled.
     03  WS-WC-YY          pic 9(4).
     03  WS-WC-MM          pic 99.
     03  WS-WC-DD          pic 99.
     03  WS-WC-HH          pic 99.
     03  WS-WC-Min         pic 99.
     03  filler            pic x(9).
*>
 01  Error-messages.                      *> Sorry, English msgs Only
     03 Msg1      pic x(28) value "Aborting: No input stream".
     03 Msg2      pic x(29) value "Aborting: Early eof on source".
     03 Msg4      pic x(42) value "Logic Error:Lost1 wsFoundWord2 numeric? = ".
     03 Msg5      pic x(32) value "Logic Error:Lost2 wsFoundWord2 =".
     03 Msg6      pic x(34) value "Error: Con table size needs > 5000".
     03 Msg7      pic x(24) value "bb050 Error: Logic error".
     03 Msg8      pic x(26) value "Error: Eof on source again".
     03 Msg9      pic x(34) value "Error: File not present Try Again!".
     03 Msg10     pic x(36) value "Error: Git Table size exceeds 10,000".
     03 Msg16     pic x(66) value "Error: " &
     "Eof on source possible logic error at aa047 ASSUMING again".
*>
 01  SectTable.
     03  filler            pic x(9) value "FWLKCRSPI".
 01  filler  redefines SectTable.
     03  LSect             pic x  occurs 9.
*> Keep track of sections used in analysed module
 01  Section-Used-Table  value zeros.
     03  USect             pic 9  occurs 9.
*> holds program parameter values from command line
 01  Arg-Vals                       value spaces.
     03  Arg-Value         pic x(128)  occurs 6.
*>
 01  Section-Names-Table.
     03  filler pic x(24) value "FILE SECTION.           ".
     03  filler pic x(24) value "WORKING-STORAGE SECTION.".
     03  filler pic x(24) value "LOCAL-STORAGE SECTION.  ".
     03  filler pic x(24) value "LINKAGE SECTION.        ".
     03  filler pic x(24) value "COMMUNICATION SECTION.  ".
     03  filler pic x(24) value "REPORT SECTION.         ".
     03  filler pic x(24) value "SCREEN SECTION.         ".
     03  filler pic x(24) value "PROCEDURE DIVISION.     ".
 01  filler   redefines Section-Names-Table.
     03  Full-Section-Name          occurs 8.
*>                  ascending key Section-Name indexed by Full-Section-Name-Idx.
         05  Section-Name  pic x(16).
         05  filler        pic x(08).
*>
 01  Section-Short-Names-Table.
     03  filler pic x(16) value "FILE            ".
     03  filler pic x(16) value "WORKING-STORAGE ".
     03  filler pic x(16) value "LOCAL-STORAGE   ".
     03  filler pic x(16) value "LINKAGE         ".
     03  filler pic x(16) value "COMMUNICATION   ".
     03  filler pic x(16) value "REPORT          ".
     03  filler pic x(16) value "SCREEN          ".
     03  filler pic x(16) value "PROCEDURE       ".
 01  filler   redefines Section-Short-Names-Table.
     03  Short-Section-Name          occurs 8.
         05  Sht-Section-Name  pic x(16).
*>
*> Here for cb_intrinsic_table in OC see :
*>   cobc/reserved.c in the open-cobol source directory but
*>    Totally ingoring the system_table as not needed/used by xref
*>
*> Also note that the number 0 or 1 indicates if the
*>  function/reserved word is implemented in Open Cobol
*>   but xref treats all as being reserved as they are so
*>
 01  Function-Table.
     03  filler pic x(28) value "1ABS                        ".
     03  filler pic X(28) value "1ACOS                       ".
     03  filler pic X(28) value "1ANNUITY                    ".
     03  filler pic X(28) value "1ASIN                       ".
     03  filler pic X(28) value "1ATAN                       ".
     03  filler pic X(28) value "0BOOLEAN-OF-INTEGER         ".
     03  filler pic X(28) value "1BYTE-LENGTH                ".
     03  filler pic X(28) value "1CHAR                       ".
     03  filler pic X(28) value "0CHAR-NATIONAL              ".
     03  filler pic X(28) value "1COMBINED-DATETIME          ".
     03  filler pic X(28) value "1CONCATENATE                ".
     03  filler pic X(28) value "1COS                        ".
     03  filler pic X(28) value "1CURRENT-DATE               ".
     03  filler pic X(28) value "1DATE-OF-INTEGER            ".
     03  filler pic X(28) value "1DATE-TO-YYYYMMDD           ".
     03  filler pic X(28) value "1DAY-OF-INTEGER             ".
     03  filler pic X(28) value "1DAY-TO-YYYYDDD             ".
     03  filler pic X(28) value "0DISPLAY-OF                 ".
*>
*> ignore this one, gets confused with username and this
*>     03  filler pic X(28) value "0E                          ".
*>
*> so does OC
*>
     03  filler pic X(28) value "1EXCEPTION-FILE             ".
     03  filler pic X(28) value "0EXCEPTION-FILE-N           ".
     03  filler pic X(28) value "1EXCEPTION-LOCATION         ".
     03  filler pic X(28) value "0EXCEPTION-LOCATION-N       ".
     03  filler pic X(28) value "1EXCEPTION-STATEMENT        ".
     03  filler pic X(28) value "1EXCEPTION-STATUS           ".
     03  filler pic X(28) value "1EXP                        ".
     03  filler pic X(28) value "1EXP10                      ".
     03  filler pic X(28) value "1FACTORIAL                  ".
     03  filler pic X(28) value "1FRACTION-PART              ".
     03  filler pic X(28) value "0HIGHEST-ALGEBRAIC          ".
     03  filler pic X(28) value "1INTEGER                    ".
     03  filler pic X(28) value "0INTEGER-OF-BOOLEAN         ".
     03  filler pic X(28) value "1INTEGER-OF-DATE            ".
     03  filler pic X(28) value "1INTEGER-OF-DAY             ".
     03  filler pic X(28) value "1INTEGER-PART               ".
     03  filler pic X(28) value "1LENGTH                     ".
     03  filler pic X(28) value "0LOCALE-COMPARE             ".
     03  filler pic X(28) value "1LOCALE-DATE                ".
     03  filler pic X(28) value "1LOCALE-TIME                ".
     03  filler pic X(28) value "1LOCALE-TIME-FROM-SECONDS   ".
     03  filler pic X(28) value "1LOG                        ".
     03  filler pic X(28) value "1LOG10                      ".
     03  filler pic X(28) value "1LOWER-CASE                 ".
     03  filler pic X(28) value "0LOWEST-ALGEBRAIC           ".
     03  filler pic X(28) value "1MAX                        ".
     03  filler pic X(28) value "1MEAN                       ".
     03  filler pic X(28) value "1MEDIAN                     ".
     03  filler pic X(28) value "1MIDRANGE                   ".
     03  filler pic X(28) value "1MIN                        ".
     03  filler pic X(28) value "1MOD                        ".
     03  filler pic X(28) value "0NATIONAL-OF                ".
     03  filler pic X(28) value "1NUMVAL                     ".
     03  filler pic X(28) value "1NUMVAL-C                   ".
     03  filler pic X(28) value "0NUMVAL-F                   ".
     03  filler pic X(28) value "1ORD                        ".
     03  filler pic X(28) value "1ORD-MAX                    ".
     03  filler pic X(28) value "1ORD-MIN                    ".
     03  filler pic X(28) value "0PI                         ".
     03  filler pic X(28) value "1PRESENT-VALUE              ".
     03  filler pic X(28) value "1RANDOM                     ".
     03  filler pic X(28) value "1RANGE                      ".
     03  filler pic X(28) value "1REM                        ".
     03  filler pic X(28) value "1REVERSE                    ".
     03  filler pic X(28) value "1SECONDS-FROM-FORMATTED-TIME".
     03  filler pic X(28) value "1SECONDS-PAST-MIDNIGHT      ".
     03  filler pic X(28) value "1SIGN                       ".
     03  filler pic X(28) value "1SIN                        ".
     03  filler pic X(28) value "1SQRT                       ".
     03  filler pic X(28) value "0STANDARD-COMPARE           ".
     03  filler pic X(28) value "1STANDARD-DEVIATION         ".
     03  filler pic X(28) value "1STORED-CHAR-LENGTH         ".
     03  filler pic X(28) value "1SUBSTITUTE                 ".
     03  filler pic X(28) value "1SUBSTITUTE-CASE            ".
     03  filler pic X(28) value "1SUM                        ".
     03  filler pic X(28) value "1TAN                        ".
     03  filler pic X(28) value "1TEST-DATE-YYYYMMDD         ".
     03  filler pic X(28) value "1TEST-DAY-YYYYDDD           ".
     03  filler pic X(28) value "0TEST-NUMVAL                ".
     03  filler pic X(28) value "0TEST-NUMVAL-C              ".
     03  filler pic X(28) value "0TEST-NUMVAL-F              ".
     03  filler pic X(28) value "1TRIM                       ".
     03  filler pic X(28) value "1UPPER-CASE                 ".
     03  filler pic X(28) value "1VARIANCE                   ".
     03  filler pic X(28) value "1WHEN-COMPILED              ".
     03  filler pic X(28) value "1YEAR-TO-YYYY               ".
*>
 01  filler redefines Function-Table.
     03  All-Functions                 occurs 84
               ascending key P-Function indexed by All-Fun-Idx.
         05  P-oc-implemented pic x.
         05  P-Function       pic x(27).
 01  Function-Table-Size   pic s9(5)  comp  value 84.
*>
*> Note that system names are omitted so thatr they turn up
*>  in the cross refs
*>
*> Here for all reserved words in OC see :
*>           struct reserved reserved_words in
*>   cobc/reserved.c in the open-cobol source directory
*>
 01  Additional-Reserved-Words.
     03  filler pic x(26) value "1ACCEPT             ".
     03  filler pic x(26) value "1ACCESS             ".
     03  filler pic x(26) value "0ACTIVE-CLASS       ".
     03  filler pic x(26) value "1ADD                ".
     03  filler pic x(26) value "1ADDRESS            ".
     03  filler pic x(26) value "1ADVANCING          ".
     03  filler pic x(26) value "1AFTER              ".
     03  filler pic x(26) value "0ALIGNED            ".
     03  filler pic x(26) value "1ALL                ".
     03  filler pic x(26) value "1ALLOCATE           ".
     03  filler pic x(26) value "1ALPHABET           ".
     03  filler pic x(26) value "1ALPHABETIC         ".
     03  filler pic x(26) value "1ALPHABETIC-LOWER   ".
     03  filler pic x(26) value "1ALPHABETIC-UPPER   ".
     03  filler pic x(26) value "1ALPHANUMERIC       ".
     03  filler pic x(26) value "1ALPHANUMERIC-EDITED".
     03  filler pic x(26) value "1ALSO".
     03  filler pic x(26) value "1ALTER".
     03  filler pic x(26) value "1ALTERNATE".
     03  filler pic x(26) value "1AND".
     03  filler pic x(26) value "1ANY".
     03  filler pic x(26) value "0ANYCASE".
     03  filler pic x(26) value "1ARE".
     03  filler pic x(26) value "1AREA".
     03  filler pic x(26) value "1AREAS".
     03  filler pic x(26) value "1ARGUMENT-NUMBER".
     03  filler pic x(26) value "1ARGUMENT-VALUE".
     03  filler pic x(26) value "0ARITHMETIC".
     03  filler pic x(26) value "1AS".
     03  filler pic x(26) value "1ASCENDING".
     03  filler pic x(26) value "1ASSIGN".
     03  filler pic x(26) value "1AT".
     03  filler pic x(26) value "0ATTRIBUTE".
     03  filler pic x(26) value "1AUTO".
     03  filler pic x(26) value "1AUTO-SKIP".
     03  filler pic x(26) value "1AUTOMATIC".
     03  filler pic x(26) value "1AUTOTERMINATE".
     03  filler pic x(26) value "0B-AND".
     03  filler pic x(26) value "0B-NOT".
     03  filler pic x(26) value "0B-OR".
     03  filler pic x(26) value "0B-XOR".
     03  filler pic x(26) value "1BACKGROUND-COLOR".
     03  filler pic x(26) value "1BASED".
     03  filler pic x(26) value "1BELL".
     03  filler pic x(26) value "1BEFORE".
     03  filler pic x(26) value "1BELL".
     03  filler pic x(26) value "1BINARY".
     03  filler pic x(26) value "1BINARY-CHAR".
     03  filler pic x(26) value "1BINARY-DOUBLE".
     03  filler pic x(26) value "1BINARY-LONG".
     03  filler pic x(26) value "1BINARY-SHORT".
     03  filler pic x(26) value "0BIT".
     03  filler pic x(26) value "1BLANK".
     03  filler pic x(26) value "1BLINK".
     03  filler pic x(26) value "1BLOCK".
     03  filler pic x(26) value "0BOOLEAN".
     03  filler pic x(26) value "1BOTTOM".
     03  filler pic x(26) value "1BY".
     03  filler pic x(26) value "0BYTE-LENGTH".
     03  filler pic x(26) value "1CALL".
     03  filler pic x(26) value "1CANCEL".
     03  filler pic x(26) value "0CD".
     03  filler pic x(26) value "0CENTER".
     03  filler pic x(26) value "0CF".
     03  filler pic x(26) value "0CH".
     03  filler pic x(26) value "0CHAIN".
     03  filler pic x(26) value "1CHAINING".
     03  filler pic x(26) value "1CHARACTER".
     03  filler pic x(26) value "1CHARACTERS".
     03  filler pic x(26) value "1CLASS".
     03  filler pic x(26) value "0CLASS-ID".
     03  filler pic x(26) value "0CLASSIFICATION".
     03  filler pic x(26) value "1CLOSE".
     03  filler pic x(26) value "0CODE".
     03  filler pic x(26) value "1CODE-SET".
     03  filler pic x(26) value "1COL".
     03  filler pic x(26) value "1COLLATING".
     03  filler pic x(26) value "1COLS".
     03  filler pic x(26) value "1COLUMN".
     03  filler pic x(26) value "1COLUMNS".
     03  filler pic x(26) value "1COMMA".
     03  filler pic x(26) value "1COMMAND-LINE".
     03  filler pic x(26) value "1COMMIT".
     03  filler pic x(26) value "1COMMON".
     03  filler pic x(26) value "0COMMUNICATION".
     03  filler pic x(26) value "1COMP".
     03  filler pic x(26) value "1COMP-1".
     03  filler pic x(26) value "1COMP-2".
     03  filler pic x(26) value "1COMP-3".
     03  filler pic x(26) value "1COMP-4".
     03  filler pic x(26) value "1COMP-5".
     03  filler pic x(26) value "1COMP-X".
     03  filler pic x(26) value "1COMPUTATIONAL".
     03  filler pic x(26) value "1COMPUTATIONAL-1".
     03  filler pic x(26) value "1COMPUTATIONAL-2".
     03  filler pic x(26) value "1COMPUTATIONAL-3".
     03  filler pic x(26) value "1COMPUTATIONAL-4".
     03  filler pic x(26) value "1COMPUTATIONAL-5".
     03  filler pic x(26) value "1COMPUTATIONAL-X".
     03  filler pic x(26) value "1COMPUTE".
     03  filler pic x(26) value "0CONDITION".
     03  filler pic x(26) value "1CONFIGURATION".
     03  filler pic x(26) value "1CONSTANT".
     03  filler pic x(26) value "1CONTAINS".
     03  filler pic x(26) value "1CONTENT".
     03  filler pic x(26) value "1CONTINUE".
     03  filler pic x(26) value "0CONTROL".
     03  filler pic x(26) value "0CONTROLS".
     03  filler pic x(26) value "1CONVERTING".
     03  filler pic x(26) value "1COPY".
     03  filler pic x(26) value "1CORR".
     03  filler pic x(26) value "1CORRESPONDING".
     03  filler pic x(26) value "1COUNT".
     03  filler pic x(26) value "1CRT".
     03  filler pic x(26) value "1CURRENCY".
     03  filler pic x(26) value "1CURSOR".
     03  filler pic x(26) value "1CYCLE".
     03  filler pic x(26) value "1DATA".
     03  filler pic x(26) value "0DATA-POINTER".
     03  filler pic x(26) value "1DATE".
     03  filler pic x(26) value "1DAY".
     03  filler pic x(26) value "1DAY-OF-WEEK".
     03  filler pic x(26) value "0DE".
     03  filler pic x(26) value "1DEBUGGING".
     03  filler pic x(26) value "1DECIMAL-POINT".
     03  filler pic x(26) value "1DECLARATIVES".
     03  filler pic x(26) value "1DEFAULT".
     03  filler pic x(26) value "1DELETE".
     03  filler pic x(26) value "1DELIMITED".
     03  filler pic x(26) value "1DELIMITER".
     03  filler pic x(26) value "1DEPENDING".
     03  filler pic x(26) value "1DESCENDING".
     03  filler pic x(26) value "0DESTINATION".
     03  filler pic x(26) value "0DETAIL".
     03  filler pic x(26) value "0DISABLE".
     03  filler pic x(26) value "1DISK".
     03  filler pic x(26) value "1DISPLAY".
     03  filler pic x(26) value "1DIVIDE".
     03  filler pic x(26) value "1DIVISION".
     03  filler pic x(26) value "1DOWN".
     03  filler pic x(26) value "1DUPLICATES".
     03  filler pic x(26) value "1DYNAMIC".
     03  filler pic x(26) value "1EBCDIC".
     03  filler pic x(26) value "0EC".
     03  filler pic x(26) value "0EGI".
     03  filler pic x(26) value "1ELSE".
     03  filler pic x(26) value "0EMI".
     03  filler pic x(26) value "0ENABLE".
     03  filler pic x(26) value "1END".
     03  filler pic x(26) value "1END-ACCEPT".
     03  filler pic x(26) value "1END-ADD".
     03  filler pic x(26) value "1END-CALL".
     03  filler pic x(26) value "1END-COMPUTE".
     03  filler pic x(26) value "1END-DELETE".
     03  filler pic x(26) value "1END-DISPLAY".
     03  filler pic x(26) value "1END-DIVIDE".
     03  filler pic x(26) value "1END-EVALUATE".
     03  filler pic x(26) value "1END-IF".
     03  filler pic x(26) value "1END-MULTIPLY".
     03  filler pic x(26) value "1END-OF-PAGE".
     03  filler pic x(26) value "1END-PERFORM".
     03  filler pic x(26) value "1END-READ".
     03  filler pic x(26) value "0END-RECEIVE".
     03  filler pic x(26) value "1END-RETURN".
     03  filler pic x(26) value "1END-REWRITE".
     03  filler pic x(26) value "1END-SEARCH".
     03  filler pic x(26) value "1END-START".
     03  filler pic x(26) value "1END-STRING".
     03  filler pic x(26) value "1END-SUBTRACT".
     03  filler pic x(26) value "1END-UNSTRING".
     03  filler pic x(26) value "1END-WRITE".
     03  filler pic x(26) value "1ENTRY".
     03  filler pic x(26) value "0ENTRY-CONVENTION".
     03  filler pic x(26) value "1ENVIRONMENT".
     03  filler pic x(26) value "1ENVIRONMENT-NAME".
     03  filler pic x(26) value "1ENVIRONMENT-VALUE".
     03  filler pic x(26) value "0EO".
     03  filler pic x(26) value "1EOL".
     03  filler pic x(26) value "1EOP".
     03  filler pic x(26) value "1EOS".
     03  filler pic x(26) value "1EQUAL".
     03  filler pic x(26) value "1EQUALS".
     03  filler pic x(26) value "1ERASE".
     03  filler pic x(26) value "1ERROR".
     03  filler pic x(26) value "1ESCAPE".
     03  filler pic x(26) value "0ESI".
     03  filler pic x(26) value "1EVALUATE".
     03  filler pic x(26) value "1EXCEPTION".
     03  filler pic x(26) value "0EXCEPTION-OBJECT".
     03  filler pic x(26) value "1EXCLUSIVE".
     03  filler pic x(26) value "1EXIT".
     03  filler pic x(26) value "0EXPANDS".
     03  filler pic x(26) value "1EXTEND".
     03  filler pic x(26) value "1EXTERNAL".
     03  filler pic x(26) value "0FACTORY".
     03  filler pic x(26) value "1FALSE".
     03  filler pic x(26) value "1FD".
     03  filler pic x(26) value "1FILE".
     03  filler pic x(26) value "1FILE-CONTROL".
     03  filler pic x(26) value "1FILE-ID".
     03  filler pic x(26) value "1FILLER".
     03  filler pic x(26) value "0FINAL".
     03  filler pic x(26) value "1FIRST".
     03  filler pic x(26) value "0FLOAT-BINARY-16".
     03  filler pic x(26) value "0FLOAT-BINARY-34".
     03  filler pic x(26) value "0FLOAT-BINARY-7".
     03  filler pic x(26) value "0FLOAT-DECIMAL-16".
     03  filler pic x(26) value "0FLOAT-DECIMAL-34".
     03  filler pic x(26) value "0FLOAT-EXTENDED".
     03  filler pic x(26) value "1FLOAT-LONG".
     03  filler pic x(26) value "1FLOAT-SHORT".
     03  filler pic x(26) value "1FOOTING".
     03  filler pic x(26) value "1FOR".
     03  filler pic x(26) value "1FOREGROUND-COLOR".
     03  filler pic x(26) value "1FOREVER".
     03  filler pic x(26) value "0FORMAT".
     03  filler pic x(26) value "1FREE".
     03  filler pic x(26) value "1FROM".
     03  filler pic x(26) value "1FULL".
     03  filler pic x(26) value "1FUNCTION".
     03  filler pic x(26) value "0FUNCTION-ID".
     03  filler pic x(26) value "0FUNCTION-POINTER".
     03  filler pic x(26) value "0GENERATE".
     03  filler pic x(26) value "0GET".
     03  filler pic x(26) value "1GIVING".
     03  filler pic x(26) value "1GLOBAL".
     03  filler pic x(26) value "1GO".
     03  filler pic x(26) value "1GOBACK".
     03  filler pic x(26) value "1GREATER".
     03  filler pic x(26) value "0GROUP".
     03  filler pic x(26) value "0GROUP-USAGE".
     03  filler pic x(26) value "0HEADING".
     03  filler pic x(26) value "1HIGH-VALUE".
     03  filler pic x(26) value "1HIGH-VALUES".
     03  filler pic x(26) value "1HIGHLIGHT".
     03  filler pic x(26) value "1I-O".
     03  filler pic x(26) value "1I-O-CONTROL".
     03  filler pic x(26) value "1ID".
     03  filler pic x(26) value "1IDENTIFICATION".
     03  filler pic x(26) value "1IF".
     03  filler pic x(26) value "1IGNORE".
     03  filler pic x(26) value "1IGNORING".
     03  filler pic x(26) value "0IMPLEMENTS".
     03  filler pic x(26) value "1IN".
     03  filler pic x(26) value "1INDEX".
     03  filler pic x(26) value "1INDEXED".
     03  filler pic x(26) value "0INDICATE".
     03  filler pic x(26) value "0INFINITY".
     03  filler pic x(26) value "0INHERITS".
     03  filler pic x(26) value "1INITIAL".
     03  filler pic x(26) value "1INITIALIZE".
     03  filler pic x(26) value "1INITIALIZED".
     03  filler pic x(26) value "0INITIATE".
     03  filler pic x(26) value "1INPUT".
     03  filler pic x(26) value "1INPUT-OUTPUT".
     03  filler pic x(26) value "1INSPECT".
     03  filler pic x(26) value "0INTERFACE".
     03  filler pic x(26) value "0INTERFACE-ID".
     03  filler pic x(26) value "1INTO".
     03  filler pic x(26) value "0INTRINSIC".
     03  filler pic x(26) value "1INVALID".
     03  filler pic x(26) value "0INVOKE".
     03  filler pic x(26) value "1IS".
     03  filler pic x(26) value "1JUST".
     03  filler pic x(26) value "1JUSTIFIED".
     03  filler pic x(26) value "1KEY".
     03  filler pic x(26) value "1LABEL".
     03  filler pic x(26) value "0LAST".
     03  filler pic x(26) value "0LC_ALL".
     03  filler pic x(26) value "0LC_COLLATE".
     03  filler pic x(26) value "0LC_CTYPE".
     03  filler pic x(26) value "0LC_MESSAGES".
     03  filler pic x(26) value "0LC_MONETARY".
     03  filler pic x(26) value "0LC_NUMERIC".
     03  filler pic x(26) value "0LC_TIME".
     03  filler pic x(26) value "1LEADING".
     03  filler pic x(26) value "1LEFT".
     03  filler pic x(26) value "1LENGTH".
     03  filler pic x(26) value "1LESS".
     03  filler pic x(26) value "0LIMIT".
     03  filler pic x(26) value "0LIMITS".
     03  filler pic x(26) value "1LINAGE".
     03  filler pic x(26) value "1LINAGE-COUNTER".
     03  filler pic x(26) value "1LINE".
     03  filler pic x(26) value "0LINE-COUNTER".
     03  filler pic x(26) value "1LINES".
     03  filler pic x(26) value "1LINKAGE".
     03  filler pic x(26) value "1LOCAL-STORAGE".
     03  filler pic x(26) value "1LOCALE".
     03  filler pic x(26) value "1LOCK".
     03  filler pic x(26) value "1LOW-VALUE".
     03  filler pic x(26) value "1LOW-VALUES".
     03  filler pic x(26) value "1LOWLIGHT".
     03  filler pic x(26) value "1MANUAL".
     03  filler pic x(26) value "1MEMORY".
     03  filler pic x(26) value "1MERGE".
     03  filler pic x(26) value "0MESSAGE".
     03  filler pic x(26) value "0METHOD".
     03  filler pic x(26) value "0METHOD-ID".
     03  filler pic x(26) value "1MINUS".
     03  filler pic x(26) value "1MODE".
     03  filler pic x(26) value "1MOVE".
     03  filler pic x(26) value "1MULTIPLE".
     03  filler pic x(26) value "1MULTIPLY".
     03  filler pic x(26) value "1NATIONAL".
     03  filler pic x(26) value "1NATIONAL-EDITED".
     03  filler pic x(26) value "1NATIVE".
     03  filler pic x(26) value "1NEGATIVE".
     03  filler pic x(26) value "0NESTED".
     03  filler pic x(26) value "1NEXT".
     03  filler pic x(26) value "1NO".
     03  filler pic x(26) value "0NONE".
     03  filler pic x(26) value "0NORMAL".
     03  filler pic x(26) value "1NOT".
     03  filler pic x(26) value "1NULL".
     03  filler pic x(26) value "1NULLS".
     03  filler pic x(26) value "1NUMBER".
     03  filler pic x(26) value "1NUMBER-OF-CALL-PARAMETERS".
     03  filler pic x(26) value "1NUMBERS".
     03  filler pic x(26) value "1NUMERIC".
     03  filler pic x(26) value "1NUMERIC-EDITED".
     03  filler pic x(26) value "0OBJECT".
     03  filler pic x(26) value "1OBJECT-COMPUTER".
     03  filler pic x(26) value "0OBJECT-REFERENCE".
     03  filler pic x(26) value "1OCCURS".
     03  filler pic x(26) value "1OF".
     03  filler pic x(26) value "1OFF".
     03  filler pic x(26) value "1OMITTED".
     03  filler pic x(26) value "1ON".
     03  filler pic x(26) value "1ONLY".
     03  filler pic x(26) value "1OPEN".
     03  filler pic x(26) value "1OPTIONAL".
     03  filler pic x(26) value "0OPTIONS".
     03  filler pic x(26) value "1OR".
     03  filler pic x(26) value "1ORDER".
     03  filler pic x(26) value "1ORGANIZATION".
     03  filler pic x(26) value "1OTHER".
     03  filler pic x(26) value "1OUTPUT".
     03  filler pic x(26) value "1OVERFLOW".
     03  filler pic x(26) value "1OVERLINE".
     03  filler pic x(26) value "0OVERRIDE".
     03  filler pic x(26) value "1PACKED-DECIMAL".
     03  filler pic x(26) value "1PADDING".
     03  filler pic x(26) value "1PAGE".
     03  filler pic x(26) value "0PAGE-COUNTER".
     03  filler pic x(26) value "1PARAGRAPH".
     03  filler pic x(26) value "1PERFORM".
     03  filler pic x(26) value "0PF".
     03  filler pic x(26) value "0PH".
     03  filler pic x(26) value "1PIC".
     03  filler pic x(26) value "1PICTURE".
     03  filler pic x(26) value "1PLUS".
     03  filler pic x(26) value "1POINTER".
     03  filler pic x(26) value "1POSITION".
     03  filler pic x(26) value "1POSITIVE".
     03  filler pic x(26) value "0PRESENT".
     03  filler pic x(26) value "1PREVIOUS".
     03  filler pic x(26) value "1PRINTER".
     03  filler pic x(26) value "0PRINTING".
     03  filler pic x(26) value "1PROCEDURE".
     03  filler pic x(26) value "1PROCEDURE-POINTER".
     03  filler pic x(26) value "1PROCEDURES".
     03  filler pic x(26) value "1PROCEED".
     03  filler pic x(26) value "1PROGRAM".
     03  filler pic x(26) value "1PROGRAM-ID".
     03  filler pic x(26) value "1PROGRAM-POINTER".
     03  filler pic x(26) value "1PROMPT".
     03  filler pic x(26) value "0PROPERTY".
     03  filler pic x(26) value "0PROTOTYPE".
     03  filler pic x(26) value "0PURGE".
     03  filler pic x(26) value "0QUEUE".
     03  filler pic x(26) value "1QUOTE".
     03  filler pic x(26) value "1QUOTES".
     03  filler pic x(26) value "0RAISE".
     03  filler pic x(26) value "0RAISING".
     03  filler pic x(26) value "1RANDOM".
     03  filler pic x(26) value "0RD".
     03  filler pic x(26) value "1READ".
     03  filler pic x(26) value "0RECEIVE".
     03  filler pic x(26) value "1RECORD".
     03  filler pic x(26) value "1RECORDING".
     03  filler pic x(26) value "1RECORDS".
     03  filler pic x(26) value "1RECURSIVE".
     03  filler pic x(26) value "1REDEFINES".
     03  filler pic x(26) value "1REEL".
     03  filler pic x(26) value "1REFERENCE".
     03  filler pic x(26) value "0RELATION".
     03  filler pic x(26) value "1RELATIVE".
     03  filler pic x(26) value "1RELEASE".
     03  filler pic x(26) value "1REMAINDER".
     03  filler pic x(26) value "1REMOVAL".
     03  filler pic x(26) value "1RENAMES".
     03  filler pic x(26) value "0REPLACE".
     03  filler pic x(26) value "1REPLACING".
     03  filler pic x(26) value "0REPORT".
     03  filler pic x(26) value "0REPORTING".
     03  filler pic x(26) value "0REPORTS".
     03  filler pic x(26) value "1REPOSITORY".
     03  filler pic x(26) value "0REPRESENTS-NOT-A-NUMBER".
     03  filler pic x(26) value "1REQUIRED".
     03  filler pic x(26) value "1RESERVE".
     03  filler pic x(26) value "0RESET".
     03  filler pic x(26) value "0RESUME".
     03  filler pic x(26) value "0RETRY".
     03  filler pic x(26) value "1RETURN".
     03  filler pic x(26) value "1RETURN-CODE".
     03  filler pic x(26) value "1RETURNING".
     03  filler pic x(26) value "1REVERSE-VIDEO".
     03  filler pic x(26) value "1REWIND".
     03  filler pic x(26) value "1REWRITE".
     03  filler pic x(26) value "0RF".
     03  filler pic x(26) value "0RH".
     03  filler pic x(26) value "1RIGHT".
     03  filler pic x(26) value "1ROLLBACK".
     03  filler pic x(26) value "1ROUNDED".
     03  filler pic x(26) value "1RUN".
     03  filler pic x(26) value "1SAME".
     03  filler pic x(26) value "1SCREEN".
     03  filler pic x(26) value "1SD".
     03  filler pic x(26) value "1SEARCH".
     03  filler pic x(26) value "0SECONDS".
     03  filler pic x(26) value "1SECTION".
     03  filler pic x(26) value "1SECURE".
     03  filler pic x(26) value "0SEGMENT".
     03  filler pic x(26) value "1SEGMENT-LIMIT".
     03  filler pic x(26) value "1SELECT".
     03  filler pic x(26) value "0SELF".
     03  filler pic x(26) value "0SEND".
     03  filler pic x(26) value "1SENTENCE".
     03  filler pic x(26) value "1SEPARATE".
     03  filler pic x(26) value "1SEQUENCE".
     03  filler pic x(26) value "1SEQUENTIAL".
     03  filler pic x(26) value "1SET".
     03  filler pic x(26) value "1SHARING".
     03  filler pic x(26) value "1SIGN".
     03  filler pic x(26) value "1SIGNED".
     03  filler pic x(26) value "1SIGNED-INT".
     03  filler pic x(26) value "1SIGNED-LONG".
     03  filler pic x(26) value "1SIGNED-SHORT".
     03  filler pic x(26) value "1SIZE".
     03  filler pic x(26) value "1SORT".
     03  filler pic x(26) value "1SORT-MERGE".
     03  filler pic x(26) value "1SORT-RETURN".
     03  filler pic x(26) value "1SOURCE".
     03  filler pic x(26) value "1SOURCE-COMPUTER".
     03  filler pic x(26) value "0SOURCES".
     03  filler pic x(26) value "1SPACE".
     03  filler pic x(26) value "1SPACES".
     03  filler pic x(26) value "1SPECIAL-NAMES".
     03  filler pic x(26) value "1STANDARD".
     03  filler pic x(26) value "1STANDARD-1".
     03  filler pic x(26) value "1STANDARD-2".
     03  filler pic x(26) value "1START".
     03  filler pic x(26) value "0STATEMENT".
     03  filler pic x(26) value "1STATUS".
     03  filler pic x(26) value "0STEP".
     03  filler pic x(26) value "1STOP".
     03  filler pic x(26) value "1STRING".
     03  filler pic x(26) value "0STRONG".
     03  filler pic x(26) value "0SUB-QUEUE-1".
     03  filler pic x(26) value "0SUB-QUEUE-2".
     03  filler pic x(26) value "0SUB-QUEUE-3".
     03  filler pic x(26) value "1SUBTRACT".
     03  filler pic x(26) value "0SUM".
     03  filler pic x(26) value "0SUPER".
     03  filler pic x(26) value "0SUPPRESS".
     03  filler pic x(26) value "0SYMBOL".
     03  filler pic x(26) value "1SYMBOLIC".
     03  filler pic x(26) value "1SYNC".
     03  filler pic x(26) value "1SYNCHRONIZED".
     03  filler pic x(26) value "0SYSTEM-DEFAULT".
     03  filler pic x(26) value "0TABLE".
     03  filler pic x(26) value "1TALLYING".
     03  filler pic x(26) value "1TAPE".
     03  filler pic x(26) value "0TERMINAL".
     03  filler pic x(26) value "0TERMINATE".
     03  filler pic x(26) value "1TEST".
     03  filler pic x(26) value "0TEXT".
     03  filler pic x(26) value "1THAN".
     03  filler pic x(26) value "1THEN".
     03  filler pic x(26) value "1THROUGH".
     03  filler pic x(26) value "1THRU".
     03  filler pic x(26) value "1TIME".
     03  filler pic x(26) value "1TIMES".
     03  filler pic x(26) value "1TO".
     03  filler pic x(26) value "1TOP".
     03  filler pic x(26) value "1TRAILING".
     03  filler pic x(26) value "1TRANSFORM".
     03  filler pic x(26) value "1TRUE".
     03  filler pic x(26) value "0TYPE".
     03  filler pic x(26) value "0TYPEDEF".
     03  filler pic x(26) value "0UCS-4".
     03  filler pic x(26) value "1UNDERLINE".
     03  filler pic x(26) value "1UNIT".
     03  filler pic x(26) value "0UNIVERSAL".
     03  filler pic x(26) value "1UNLOCK".
     03  filler pic x(26) value "1UNSIGNED".
     03  filler pic x(26) value "1UNSIGNED-INT".
     03  filler pic x(26) value "1UNSIGNED-LONG".
     03  filler pic x(26) value "1UNSIGNED-SHORT".
     03  filler pic x(26) value "1UNSTRING".
     03  filler pic x(26) value "1UNTIL".
     03  filler pic x(26) value "1UP".
     03  filler pic x(26) value "1UPDATE".
     03  filler pic x(26) value "1UPON".
     03  filler pic x(26) value "1USAGE".
     03  filler pic x(26) value "1USE".
     03  filler pic x(26) value "0USER-DEFAULT".
     03  filler pic x(26) value "1USING".
     03  filler pic x(26) value "0UTF-16".
     03  filler pic x(26) value "0UTF-8".
     03  filler pic x(26) value "0VAL-STATUS".
     03  filler pic x(26) value "0VALID".
     03  filler pic x(26) value "0VALIDATE".
     03  filler pic x(26) value "0VALIDATE-STATUS".
     03  filler pic x(26) value "1VALUE".
     03  filler pic x(26) value "1VALUES".
     03  filler pic x(26) value "1VARYING".
     03  filler pic x(26) value "1WAIT".
     03  filler pic x(26) value "1WHEN".
     03  filler pic x(26) value "1WITH".
     03  filler pic x(26) value "1WORDS".
     03  filler pic x(26) value "1WORKING-STORAGE".
     03  filler pic x(26) value "1WRITE".
     03  filler pic x(26) value "1YYYYDDD".
     03  filler pic x(26) value "1YYYYMMDD".
     03  filler pic x(26) value "1ZERO".
     03  filler pic x(26) value "1ZEROES".
     03  filler pic x(26) value "1ZEROS".
*>
 01  filler redefines Additional-Reserved-Words.
     03  Reserved-Names                occurs 529
                  ascending key Resvd-Word indexed by Resvd-Idx.
         05  Resvd-Implemented pic x.
         05  Resvd-Word        pic x(25).
 01  Resvd-Table-Size        pic s9(5)   comp    value 529.
*>
 01  Condition-Table                           value high-values.
     03  Con-Tab-Blocks occurs 10 to 5001
                                       depending on Con-Tab-Size.
*> +1 used, when testing for max table size
         05  Conditions      pic x(32).
         05  Variables       pic x(32).
         05  CT-In-Use-Flag  pic x.
         05  filler          pic x.
 01  Con-Tab-Size          Binary-Long value 10.
 01  Con-Tab-Count         Binary-Long value zero.
*>
 01  Global-Item-Table                         value high-values.
     03  Git-Elements  occurs 10 to 10001
                                     depending on Git-Table-Size.
*> +1 used, when testing for max table size
       05  Git-Word        pic x(32).
       05  Git-Prog-Name   pic x(32).
       05  Git-RefNo       pic 9(6).
       05  Git-HoldWSorPD  pic 9.
       05  Git-HoldWSorPD2 pic 9.
       05  Git-Build-No    pic 99.
       05  Git-In-Use-Flag pic x.
       05  filler          pic x.
 01  Git-Table-Size        Binary-Long value 10.
 01  Git-Table-Count       Binary-Long value zero.
*>
 procedure division.
 aa000-xref-Data    section.
*>**************************
*>  TODO & BUGS:
*>************************************************************************
*> AAnnn Section:
*>  THIS ENTIRE SECTION NEEDS A REWRITE, TOO MUCH TAKEN FROM THE VERY OLD
*>   CODE BASE. DOES READ-A-WORD CATER FOR MULTIPLE STATEMENTS PER LINE
*>    WITH PERIODS ENDING EACH STATEMENT? IF SO, WHY ARE WE CHECKING FOR
*>     WORD-DELIMIT = "." THEN.
*>  THIS ALL NEEDS A GOOD LOOK AT, SO MUST DONE SOON but with fresh eyes
*> SUGGEST COMMON CODE LEFT HERE WITH NEW SECTIONS DEALING WITH EACH
*>  SECTION OR MAIN ENTRY
*>^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*>
*>  Quesions, Questions, Questions,  all I have, is questions!
*>************************************************************************
*>
*>
     perform  zz190-Init-Program thru zz190-Exit.
     move     high-values to Global-Item-Table.
*>
*> Just in case someone's added names in source code out of sort order
*>  We MUST have all tables in sorted order
*>
     sort     Reserved-Names ascending Resvd-Word.
     sort     All-Functions ascending P-Function.
*>
     perform  zz180-Open-Source-File thru zz180-Exit.
*>
*> Dump All reserved words from tables then stop
*>
     if       Dump-Reserved-Words
              perform varying a from 1 by 1
                  until a > Resvd-Table-Size
                    display Resvd-Word (a)
                    end-display
              end-perform
              perform varying a from 1 by 1
                  until a > Function-Table-Size
                    display P-Function (a)
                    end-display
              end-perform
              move zero to return-code
              goback
     end-if
*>
     open     output Source-Listing.
     if       Reports-In-Lower
              move function lower-case (Prog-BaseName (1:CWS))
                                    to HoldID
     else
              move function upper-case (Prog-BaseName (1:CWS))
                                    to HoldID
     end-if
     move     HoldID to HoldID-Module.
     move     spaces to Arg-Vals.
*>
*> get program id frm source filename in case prog-id not present
*>
 aa020-Bypass-Open.
     open     output Supplemental-Part1-Out.
*>
*> Now add in contents of Global table if processing nested modules
*>   and we have processed first one by loading sort file
*>
     if       Git-Table-Count not = zero
              initialize SortRecord
              perform varying a from 1 by 1
                       until a > Git-Table-Count
                   move Git-HoldWSorPD  (a) to SkaWSorPD
                   move Git-HoldWSorPD2 (a) to SkaWSorPD2
                   if Reports-In-Lower
                      move function lower-case (Git-Word (a))
                                            to SkaDataName
                   else
                      move Git-Word (a) to SkaDataName
                   end-if
                   move Git-RefNo (a) to SkaRefNo
                   move 1 to USect (Git-HoldWSorPD (a))
                   write SortRecord
              end-perform
     end-if
*>
*> HoldID gets updated with program-id name when found later
*>   but we can print 1st report headings using the sourcefile name
*>    we are assuming the user knows what s/he is doing......:)
*>
     move     Prog-Name to H1Prog-Name.
     if       List-Source
              perform  zz150-WriteHdb.
*>
     perform  zz100-Get-A-Source-Record thru zz100-Exit.
     move     1 to q S-Pointer F-Pointer.
*>
 aa030-ReadLoop1.
     if       Source-Eof
           or End-Prog
              display Msg2
              close Supplemental-Part1-Out Source-Listing
              close SourceInput
              move 16 to return-code
              goback.
     perform  zz110-Get-A-Word thru zz110-Exit.
     IF       SourceInWS = "DATA DIVISION.  "
                       or  "FILE SECTION.   "
                       or  "WORKING-STORAGE SECTION."
                       or  "PROCEDURE DIVISION."
              go to aa060-ReadLoop3a.
*>
*> The above should never happen, as all modules have a program-id
*>   but who knows what new standards will allow
*>
     if       wsFoundWord2 not = "PROGRAM-ID"
              go to aa030-ReadLoop1.
     perform  zz110-Get-A-Word thru zz110-Exit.
*>
*> got program name so if 1st prog id -> hold-id
*>               else -> holdid-module (for reports)
*>  but 1st check if its a literal & if so remove quotes and use 1st CWS chars
*>
     if       wsf1-1 = quote or = "'"
              unstring wsFoundWord2 (2:32) delimited by quote or "'"
                        into wsFoundNewWord
              end-unstring
              move wsFoundNewWord (1:CWS) to  wsFoundWord2
     end-if
     if       not Have-Nested
        if       Reports-In-Lower
                 move function lower-case (wsFoundWord2)
                                      to HoldID
        else
                 move function upper-case (wsFoundWord2)
                                      to HoldID.
     if       Have-Nested  *> found more than 1 module in source
        if       Reports-In-Lower
                 move function lower-case (wsFoundWord2)
                                      to HoldID-Module
        else
                 move function upper-case (wsFoundWord2)
                                      to HoldID-Module.
*>
*> We now have the program-id name so update our info, for reports
*> Next block of interest is special-names and then file-control
*>
 aa040-ReadLoop2.
     perform  zz100-Get-A-Source-Record thru zz100-Exit.
     if       SourceInWS (1:14) = "SPECIAL-NAMES."
              go to aa041-Get-SN.
     if       SourceInWS (1:13) = "FILE-CONTROL."   *> selects
              go to aa047-GetIO.
     if       SourceInWS (1:12) = "I-O-CONTROL."    *> same area etc
              go to aa048-GetIOC.
     if       SourceInWS (1:12) = "DATA DIVISIO"
              go to aa041-Get-SN.
     perform  aa045-Test-Section thru aa045-Exit.
*>
*> if not zero we've got Data Div onwards
*>
     if       a not = zero
              go to aa060-ReadLoop3a.
     go       to aa040-ReadLoop2.
*>
 aa041-Get-SN.
*>
*> Get special names
*>
     perform  zz100-Get-A-Source-Record thru zz100-Exit.
     perform  aa045-Test-Section thru aa045-Exit.
     if       a not = zero
              go to aa060-ReadLoop3a.
     if       SourceInWS (1:13) = "INPUT-OUTPUT "
                             or = "DATA DIVISION"
              go to aa041-Get-SN.
     IF       SourceInWS (1:13) = "FILE-CONTROL."
              go to aa047-GetIO.
     IF       SourceInWS (1:12) = "I-O-CONTROL."
              go to aa048-GetIOC.
*>
 aa042-Getword.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       Word-Delimit = "."
              go to aa041-Get-SN.
     if       wsFoundWord2 (1:9) = "CURRENCY "
              perform aa046-Get-Currency
              go to aa042-Getword.
     if       wsFoundWord2 (1:3) not = "IS "
              go to aa042-Getword.
*>
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       wsf1-1 = quote or = "'" or wsf3-1-numeric
              go to aa042-Getword.
     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
     if       a not = zero
              go to aa042-Getword.
     move     wsFoundWord2 (1:CWS) to Saved-Variable.
*>
 aa044-Getword3.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       Word-Delimit = "."
              go to aa041-Get-SN.
     if       wsFoundWord2 (1:9) = "CURRENCY "
              perform aa046-Get-Currency
              go to aa044-Getword3.
     if       wsFoundWord2 (1:2) not = "ON"
          and wsFoundWord2 (1:3) not = "OFF"
              go to aa044-Getword3.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       wsf1-1 = quote or = "'" or wsf3-1-numeric
              go to aa044-Getword3.
     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
     if       a not = zero
              go to aa044-Getword3.
*>
     if       Con-Tab-Size not < Con-Tab-Count
              add 10 to Con-Tab-Size.
     add      1 to Con-Tab-Count.
     move     Saved-Variable to Variables (Con-Tab-Count).
     move     Space  to CT-In-Use-Flag (Con-Tab-Count).
     move     wsFoundWord2 (1:CWS) to Conditions (Con-Tab-Count).
     if       Word-Delimit = "."
              go to aa041-Get-SN.
     go       to aa044-Getword3.
*>
 aa045-Test-Section.
     perform  varying a from 1 by 1 until a > 8
              if SourceInWS (1:24) = Full-Section-Name (a)
                  exit perform
              end-if
     end-perform.
     if       a > 8
              move zero to a.
*>
 aa045-Exit.
     exit.
*>
 aa046-Get-Currency.
*>
*> got 'Currency', so process as needed for pic tests in zz110
*>
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       wsFoundWord2 (1:5) = "SIGN "
           or wsFoundWord2 (1:3) = "IS "
              go to aa046-Get-Currency.
*>
*> Now Ive got the literal "x"
*>
     move     wsFoundWord2 (2:1) to Currency-Sign.
     if we-are-testing
        display " Now got currency = " Currency-Sign
     end-if.
*>
 aa047-GetIO.
*>
*> now got file control so it's SELECT ..
*>
     perform  zz100-Get-A-Source-Record thru zz100-Exit.
     perform  aa045-Test-Section thru aa045-Exit.
     if       a not = zero
              go to aa060-ReadLoop3a.
     IF       SourceInWS (1:12) = "I-O-CONTROL."
              go to aa048-GetIOC.
     if       SourceInWS (1:12) = "DATA DIVISIO"
              go to aa050-ReadLoop3.
     if       SourceInWS (1:12) = "FILE SECTION"
              go to aa060-ReadLoop3a.
*>
 aa047-Getword.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       Word-Delimit = "."
              go to aa047-GetIO.
*>
*> now looking at selects: so looking for non reserved words
*>
     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
     if       a not = zero
              go to aa047-Getword.
     if       Word-Delimit = "."
              go to aa047-GetIO.
*> Now have filename-1
     move     1 to HoldWSorPD.
     move     0 to HoldWSorPD2.
     perform  zz030-Write-Sort.
*>
 aa047-Getword2.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       Source-Eof
              display Msg16
              close Supplemental-Part1-Out Source-Listing
              close SourceInput
              move 16 to return-code
              goback.
*>
*> should have assign
*>
     if       wsFoundWord2 (1:7) not = "ASSIGN "
              go to aa047-Getword2.
*>
 aa047-Getword3.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       (wsf1-1 = quote or = "'") AND Word-Delimit = "."
              go to aa047-GetIO.
     if       wsf1-1 = quote or = "'" or wsf3-1-numeric
              go to aa047-Getword3.
     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
     if       a not = zero and Word-Delimit = "."
              go to aa047-GetIO.
     if       a not = zero
              go to aa047-Getword3.
     if       word-length = zero
              go to aa047-GetIO.
*>
*> Now have filename
*> filenames / datanames declared in Selects are shown as in data division
*>
     move     1 to HoldWSorPD.
     move     0 to HoldWSorPD2.
     perform  zz030-Write-Sort.
     if       Word-Delimit = "."
              go to aa047-GetIO.
     go       to aa047-Getword3.
*>
 aa048-GetIOC.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       wsf1-1 = quote or = "'" or wsf3-1-numeric
              go to aa048-GetIOC.
 aa048-Get-Next.
     if       Word-Delimit = "."
              perform zz100-Get-A-Source-Record thru zz100-Exit
              perform aa045-Test-Section thru aa045-Exit
              if      a not = zero
                      go to aa060-ReadLoop3a
              else
                      perform  zz110-Get-A-Word thru zz110-Exit
              end-if
     end-if
     if       wsFoundWord2 (1:5) not = "SAME "
              go to aa048-GetIOC.
*>
 aa049-Getword.
     perform  zz110-Get-A-Word thru zz110-Exit.
     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
     if       a not = zero
              go to aa049-Getword.
*> Now have filename
     move     1 to HoldWSorPD.
     move     0 to HoldWSorPD2.
     perform  zz030-Write-Sort.
     if       Word-Delimit = "."
              go to aa048-Get-Next.
     go       to aa049-Getword.
*>
 aa050-ReadLoop3.
*>
*>    Now for the data division or beyond
*>
     perform  zz100-Get-A-Source-Record thru zz100-Exit.
*>
 aa060-ReadLoop3a.
     perform  zz170-Check-4-Section thru zz170-Exit.
     if       GotASection = "Y"
              go to aa050-ReadLoop3.
     if       HoldWSorPD > zero and < 8
              move 1 to S-Pointer2
              perform ba000-Process-WS.
*>
     if       HoldWSorPD = zero
              go to aa050-ReadLoop3.
*>
     perform  bb000-Process-Procedure.
     if       End-Prog
              close Supplemental-Part1-Out
     else
              close SourceInput Supplemental-Part1-Out.
     perform  bc000-Last-Act.
     if       not End-Prog
              perform  bc620-Do-Global-Conditions thru bc629-Exit
              close Source-Listing.
*>
     if       not We-Are-Testing
          and not End-Prog
*>            call "CBL_DELETE_FILE" using SourceFileName
*> kill temp input file (anything else?) but not yet Use when in OC
              call "CBL_DELETE_FILE" using Supp-File-2
              call "CBL_DELETE_FILE" using Supp-File-1.
*>
     if       End-Prog
              perform  zz190-Init-Program thru zz190-Exit
              move  spaces to PrintLine
              write PrintLine
              write PrintLine
              write PrintLine
              move  zero to sw-End-Prog
              go    to aa020-Bypass-Open
     end-if
     move     zero to return-code.
     goback.
*>
 ba000-Process-WS Section.
 ba020-GetAWord.
*>
*> this should be getting first word of source record
*>
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       word-length = zero
              go to ba020-GetAWord.
     if       GotASection = "Y" *> check for Proc. Div
         and  HoldWSorPD = 8
              go to ba000-Exit. *> done, so process proc. div
     if       GotASection = "Y"
              move space to GotASection
              perform zz100-Get-A-Source-Record thru zz100-Exit
              go to ba020-GetAWord.
*>
*> lets get a file section element out of the way
*>
     if       wsFoundWord2 (1:3) = "FD " or = "RD "
              move zero to Global-Current-Level  *> Global only
     else
      if      wsFoundWord2 (1:3) = "CD " or = "SD " *> not these
              move high-values to Global-Current-Level.
*> Clears Global-Active
*>
*> note that for CD & SD setting Global-current-* not needed
*>                           is it a problem
     if       wsFoundWord2 (1:3) = "FD " or = "SD "
                              or = "RD " or = "CD "
              perform zz110-Get-A-Word thru zz110-Exit  *> get fn
              move zero to HoldWSorPD2
              move zero to sw-Git            *> reset Global flag
              move wsFoundWord2 (1:32) to Global-Current-Word
              move Gen-RefNo1   to Global-Current-RefNo
              perform zz030-Write-Sort
              perform ba040-Clear-To-Next-Period thru ba049-Exit
              go to ba020-GetAWord.
*>
*> we now have basic ws records, ie starting 01-49,66,77,78,88 etc
*>
      if      wsFoundWord2 (1:Word-Length) not numeric
              display "ba020:" Msg4 wsFoundWord2 (1:Word-Length)
                      " prog = " HoldID " line = " Gen-RefNo1
              close Source-Listing SourceInput
                    Supplemental-Part1-Out
              move 16 to return-code
              goback.    *> if here, its broke
*>
*> word = Build-Number
*>
      perform zz160-Clean-Number thru zz160-Exit.
      if      Build-Number > 0 and < 50
              move spaces to Saved-Variable.
*>
      if      Build-Number = 01
         and  (Global-Current-Level = high-values
           or HoldWSorPD > 1)
              move zero to sw-Git
              move 1 to Global-Current-Level.
*>
      if      Build-Number = 88 or = 78 or = 77 or = 66
                                or (Build-Number > 0 and < 50)
              go to ba050-Get-User-Word.
*>
*> getting here Should never happen
*>
      display "ba020:" Msg5 "bld=" Build-Number
              " word=" wsFoundWord2 (1:CWS)
                      " prog = " HoldID " line = " Gen-RefNo1.
     close    Source-Listing SourceInput Supplemental-Part1-Out.
     move     20 to return-code.
     goback.                            *> if here, its broke
*>
 ba040-Clear-To-Next-Period.
     if       Word-Delimit = "."
          and S-Pointer2 not < Source-Line-End
              add 1 to S-Pointer2
              move space to Word-Delimit
              go to ba049-Exit.
     if       Word-Delimit = "."
              go to ba049-Exit.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       WasPicture = 1     *> current word is a pic sub-clause
              move zero to WasPicture
              go to ba040-Clear-To-Next-Period.
     if       wsFoundWord2 (1:7) = "GLOBAL "
              move 1 to sw-Git
              perform zz200-Load-Git thru zz200-Exit
              go to ba040-Clear-To-Next-Period.
     if       wsFoundWord2 (1:8) = "INDEXED "
              perform ba052-After-Index
              go to ba040-Clear-To-Next-Period.
     if       wsFoundWord2 (1:10) = "DEPENDING "
              perform ba053-After-Depending
              go to ba040-Clear-To-Next-Period.
     if       HoldWSorPD = 7 and
              (wsFoundWord2 (1:6) = "TO    "
                    or "FROM  " or "USING ")
              perform zz110-Get-A-Word thru zz110-Exit
              inspect wsFoundWord2 tallying a for all "("
              if a not = zero
                 move wsFoundWord2 to wsFoundNewWord5
                 unstring wsFoundNewWord5 delimited by "(" into wsFoundWord2
              end-if
              perform zz030-Write-Sort
              go to ba040-Clear-To-Next-Period.
*>
*> Now looking for other non res words but not literals or numerics
*>
     if       wsf1-1 = quote or = "'"
              go to ba040-Clear-To-Next-Period.
     if       wsf1-1 = "-" or = "+"
              go to ba040-Clear-To-Next-Period.
     if       wsFoundWord2 (1:z) numeric
              go to ba040-Clear-To-Next-Period.
     if       wsf3-1-numeric
              go to ba040-Clear-To-Next-Period.
     if       wsf1-1 = "("
              go to ba040-Clear-To-Next-Period.
*> dont have literals or numerics
     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
     if       a > zero              *> reserved word
              go to ba040-Clear-To-Next-Period.
*>
*> if here must have user defined word (unless I have forgotten anything)
*>     no check for global
*>
     perform  zz030-Write-Sort.
     go       to ba040-Clear-To-Next-Period.
*>
 ba049-Exit.
     exit.
*>
 ba050-Get-User-Word.
*>
*> to here with nn ^ word but word could be pic/value etc ie no dataname
*>
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       wsFoundWord2 (1:7) = "FILLER "
              move "FILLER" to Saved-Variable
              go to ba051-After-DataName.
     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
*>
*> Trap for no dataname, ie reserved word
*>   this [the 'if'] MUST be left in here
*>
     if       a not = zero
              move "FILLER" to Saved-Variable
              go to ba051-After-New-Word.
*>
*> not a reserved word AND a 88, looking for 01 - 49 [ or 77]
*>
     if       (Build-Number > 0 and < 50) or = 77
              move wsFoundWord2 (1:CWS) to Saved-Variable.
*>
     if       Build-Number = 88
          and Con-Tab-Count not < Con-Tab-Size
              add 10 to    Con-Tab-Size.
     if       Con-Tab-Size > 5000
              move 5001 to Con-Tab-Size           *> just in case
              display Msg6
              go to ba050-Bypass-Add-2-Con-Table.
*>
*> add 88 dataname to constant table
*>
     if       Build-Number = 88
          and Con-Tab-Count < Con-Tab-Size
              add 1 to Con-Tab-Count
              if  Reports-In-Lower
                  move function lower-case (Saved-Variable) to
                          Variables (Con-Tab-Count)
                  move function lower-case (wsFoundWord2 (1:CWS))
                       to Conditions (Con-Tab-Count)
              else
                  move Saved-Variable to Variables (Con-Tab-Count)
                  move wsFoundWord2 (1:CWS)
                                     to Conditions (Con-Tab-Count)
              end-if
     end-if
     .
*>
 ba050-Bypass-Add-2-Con-Table.
*>
*> we don't have a reserved word! a = 0 = no
*>
      if      Global-Current-Level not = high-values
              move Gen-RefNo1   to Global-Current-RefNo
              move wsFoundWord2 (1:32) to Global-Current-Word.
*>
      perform zz030-Write-Sort.
*>
 ba051-After-DataName.
     if       Word-Delimit = "."
          and Build-Number not = 66 and not = 77 and not = 78
          and Saved-Variable not = "FILLER"
          and Global-Active
              perform zz200-Load-Git thru zz200-Exit.
     if       Word-Delimit = "."
              go to ba020-GetAWord.
     if       Global-Active
          and Build-Number = 88
              perform zz200-Load-Git thru zz200-Exit
              perform ba040-Clear-To-Next-Period thru ba049-Exit
              go to ba020-GetAWord.
     perform  zz110-Get-A-Word thru zz110-Exit.
*>
 ba051-After-New-Word.
     if       wsFoundWord2 (1:10) = "REDEFINES " or
              wsFoundWord2 (1:8) = "RENAMES "
              perform zz110-Get-A-Word thru zz110-Exit
              perform zz030-Write-Sort
     else
      if      wsFoundWord2 (1:7) = "GLOBAL "
              move 1 to sw-Git
              perform zz200-Load-Git thru zz200-Exit
      else
       if     Global-Active
          and Build-Number not = 66 and not = 77 and not = 78
          and Saved-Variable not = "FILLER"
              perform zz200-Load-Git thru zz200-Exit.
*>
     if       HoldWSorPD = 7 and
              (wsFoundWord2 (1:6) = "TO    "
                    or "FROM  " or "USING ")
              perform zz110-Get-A-Word thru zz110-Exit
              inspect wsFoundWord2 tallying a for all "("
              if a not = zero
                 move wsFoundWord2 to wsFoundNewWord5
                 unstring wsFoundNewWord5 delimited by "(" into wsFoundWord2
              end-if
              perform zz030-Write-Sort
     end-if
*>
     perform  ba040-Clear-To-Next-Period thru ba049-Exit.
     go       to ba020-GetAWord.
*>
 ba052-After-Index.
*>
*> if Index found ignore 'by' if present
*>
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       wsFoundWord2 (1:3) = "BY "
              go to ba052-After-Index.
*>
*> Should have index name and might be global
*>
     perform  zz030-Write-Sort.
     if       Global-Active
              move wsFoundWord2 (1:32) to Global-Current-Word
              perform zz200-Load-Git thru zz200-Exit.
*>
 ba053-After-Depending.
*>
*> If depending found ignore 'on' if present, no global processing
*>
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       wsFoundWord2 (1:3) = "ON "
              go to ba053-After-Depending.
*>
*> Should have depending name
*>
     perform  zz030-Write-Sort.
*>
 ba000-Exit.
     exit.
*>
 bb000-Process-Procedure Section.
 bb010-New-Record.
*>
*> at this point we need to get a word but have
*>                 PROCEDURE (as in DIVISION) as wsFoundWord2
*> but 1st, sort Global  table prior to running search(es)
*>  and I know it will happen for every module in src after 1st one
*>    this needs a rewrite as well as process a word etc complete mess
     if       Git-Table-Count > 1
              sort  Git-Elements ascending Git-Word.
*>
 bb020-GetAWord.
     perform  zz110-Get-A-Word thru zz110-Exit.
     if       End-Prog
              go to bb000-Exit.
     if       Source-Eof
              go to bb000-Exit.
     if       Word-Delimit = "."
         and  wsf1-1 = space
              go to bb020-GetAWord.
*>
 bb030-Chk1.
     if       wsFoundWord2 (1:1) alphabetic
           perform zz130-Extra-Reserved-Word-Check thru zz130-Exit
     else
              move zero to a.
*>
*> Do we have a reserved word? a = 0 means no or a number so ignore
*>
     if       a > zero
              go to bb020-GetAWord.
     if       wsf1-1 numeric
              go to bb020-GetAWord.
     if       (wsf1-1 = "-" or = "+")
        and   wsFoundWord2 (2:1) numeric
              go to bb020-GetAWord.
     if       wsf1-1 = quote or = "'"
              go to bb020-GetAWord.
     if       (wsf1-1 = "X" or = "H")
        and   (wsFoundWord2 (2:1) = quote or = "'")
              go to bb020-GetAWord.
     if       wsf1-1 = ":"
        and   Word-Length = 1
              go to bb020-GetAWord.
     if       wsf1-1 = "("
              go to bb050-Check-SubScripts.
*>
 bb040-chk2.
*>
*> check for arithmetic operators
*>
     if       wsf1-3 = "-  " or = "+  " or = "*  " or = "/  "
                             or = "** "
              go to bb020-GetAWord.
*>
*> check for relational Conditions
*>
     if       wsf1-2 = "> " or = "< " or = "= "
              go to bb020-GetAWord.
     if       wsf1-3 = ">= " or = "<= " or = "<> "
              go to bb020-GetAWord.
*>
*> we have a dataname and are we at word one with period delimiter
*> is it a paragraph?
*>
     move     2 to HoldWSorPD2.
     if       Word-Delimit = "."
          and Source-Words = 1
              move zero to HoldWSorPD2.
*>
*> Check if we have a section name if so set wdorpd2 = 1
*>
     string   wsFoundWord2 (1:Word-Length) delimited by size
              " SECTION" delimited by size
                into HoldFoundWord.
     add      Word-Length 8 giving a.
     if       HoldWSorPD2 not = zero
         and  SourceInWS (1:a) = HoldFoundWord (1:a)
              move 1 to HoldWSorPD2.
     if       wsFoundWord2 (Word-Length:1) = ")"
              move space to wsFoundWord2 (Word-Length:1)
              if  Word-Length > 1
                  subtract 1 from Word-Length
              end-if
              go to bb030-Chk1
     end-if
     perform  zz030-Write-Sort.
     go       to bb020-GetAWord.
*>
 bb050-Check-SubScripts.
*>
*> arrives here with (xxxx) or any variation ie (((xxx etc
*>   xxx)))
*>
     move     spaces to wsFoundNewWord3.
     move     zero to a c d q y s s2 z2 z3.
     move     1 to s.                   *> Working Word start point
     move     Word-Length to z z2.      *> Working Word Length
 bb051-Clear-Left-Brace.
     if       z2 < 1                    *>  Should never happen but!
              go to bb020-GetAWord.
     if       wsFoundWord2 (s:1) = "("
              add      1 to s
              subtract 1 from z2
              go to bb051-clear-Left-brace.
*>
*> Now we have abcde))) or "abcd"))) or word:word)) or sim.
*>
 bb052-Clear-Right-Brace.
     if       z2 < 1                    *>  Should never happen but!
              go to bb020-GetAWord.     *>  ie empty braces
     if       wsFoundWord2 (z:1) = ")"
              move space to wsFoundWord2 (z:1)
              subtract 1 from z
              subtract 1 from z2
              subtract 1 from Word-Length
              go to bb052-Clear-Right-Brace.
*>
*> s  = left char pos         in wsFoundWord2
*> z  = right most char pos   in wsFoundWord2
*> z2 = current word length   in wsFoundWord2
*> WL = orig length minus No. of ')'
*>
 bb053-numerics.                        *> not interested in
     if       wsFoundWord2 (s:z2) numeric
              go to bb020-GetAWord.
     if       s < z
              subtract 1 from z2 giving z3
              add 1 s giving s2
              if  (wsFoundWord2 (s:1) = "+" or = "-")
               and wsFoundWord2 (s2:z3) numeric
                   go to bb020-GetAWord
              end-if
     end-if
*>
     inspect  wsFoundWord2 (s:z2) tallying a for all "(".
     inspect  wsFoundWord2 (s:z2) tallying a for all ")".
     if       a > zero                  *> should not have braces now
              display "bb053:Logic Error (=" a " B=" b " on " wsFoundWord2 (1:80)
              go to bb020-GetAWord
     end-if
*>
     inspect  wsFoundWord2 (s:z2) tallying y for all quote.
     inspect  wsFoundWord2 (s:z2) tallying y for all "'".
*>
     if       y > zero                  *> quotes?
              move  zero to b      q t
              subtract 1 from s giving a
              go to bb060-Scan4-Quotes
     end-if
     inspect  wsFoundWord2 (s:z2) tallying c for all ":".
     if       c > zero                  *> a colon?
              move  zero to b q t
              go to bb100-scan4-colon.
 bb054-spaces.
*>  left over from old code ??
     inspect  wsFoundWord2 (s:z2) tallying d for all space.
     if       d = zero
              move spaces to wsFoundNewWord
              if   z2 < 33
                   move wsFoundWord2 (s:z2) to wsFoundNewWord
              else
                   move wsFoundWord2 (s:32) to wsFoundNewWord
                   if we-are-testing
                      display "bb054:logic err?: " wsFoundWord2 (s:32)
                   end-if
              end-if
              move wsFoundNewWord to wsFoundWord2
              perform zz130-Extra-Reserved-Word-Check
                                              thru zz130-Exit
              if  a > zero              *> reserved word
                      go to bb020-GetAWord
              end-if
              perform zz030-Write-Sort
              go to bb020-GetAWord
     end-if
*> cockup trap
     display Msg7.
     display "bb054b: wsfw2=" wsFoundWord2 (1:64).
     go to bb020-GetAWord.
*>
 bb060-Scan4-Quotes.
*>
*> we are testing if more than 1 word present inc. a literal but it shouldn't
*>
     add      1 to a.        *>  q now a = field start,  s now b, z = rightmost char
     if       a not > z      *> check for end of data in field
        and   wsFoundWord2 (a:1) not = quote and not = "'"
              add 1 to b
              move wsFoundWord2 (a:1) to wsFoundNewWord3 (b:1)
              go to bb060-Scan4-Quotes.
*>
*> wsFoundNewWord3 = non quoted field so far
*>
 bb070-Got-Quote.        *> starts at 1st quote
     add      1 to a.
     add      1 to t.  *> t = literal length (no quotes)
     if       a > z                       *> Word-Length
              go to bb090-Recover-Word.
     if       wsFoundWord2 (a:1) not = quote and not = "'"
              go to bb070-Got-Quote.
     add      1 to a. *> a = next char after 2nd quote
     add      1 to t.
*>
*> t = quoted lit length including quotes
*>   and we are now at end quote + 1
 bb080-Quote-Clean.
     if       a > z                       *> Word-Length
              go to bb090-Recover-Word.
     if we-are-testing
         display "bb080: found 2nd word in scan=" wsFoundWord2
     end-if
     add      1 to b.
     move     wsFoundWord2 (a:1) to wsFoundNewWord3 (b:1).
     add      1 to a.
     go       to bb080-Quote-Clean.
*>
 bb090-Recover-Word.
*>
*> Word-Length and wsFoundWord2 less quoted field could be > 1 word in wsfnw3
*>
     subtract t from Word-Length.
     if       Word-Length < 1
              go to bb020-GetAWord.
     move     wsFoundNewWord3 (1:CWS) to wsFoundWord2 (1:CWS).
     go       to bb050-Check-SubScripts.
*>
 bb100-scan4-colon.
*>
*> now we can have num:num DataName:DN num:DN DN:num
*> z2 = current WL, s = leftmost char & z= rightmost char in wsFW2
*>
     move     spaces to wsFoundNewWord wsFoundNewWord2.
     move     1 to t.
     unstring wsFoundWord2 (s:z2) delimited by ":"
              into wsFoundNewWord
              count q
              pointer t.
*> t now : +1
     unstring wsFoundWord2 (s:z2) delimited by " "
              into wsFoundNewWord2
              count b
              pointer t.
     if     t not > z2 or not = Word-Length
            display "bb100 Error: t=" t " word-len="
            Word-Length " z2=" z2.
*> this numeric test may not work?
     if       wsFoundNewWord (1:q) not numeric
         and  wsFoundNewWord (1:1) not = "-" and not = "+"
              move spaces to wsFoundWord2
              move wsFoundNewWord (1:q) to wsFoundWord2
              perform zz030-Write-Sort.
*> this numeric test may not work?
     if       b > zero
        and   wsFoundNewWord2 (1:b) not numeric
         and  wsFoundNewWord2 (1:1) not = "-" and not = "+"
              move spaces to wsFoundWord2
              move wsFoundNewWord2 (1:b) to wsFoundWord2
              perform zz030-Write-Sort.
     go       to bb020-GetAWord.
 bb000-Exit.
     exit.
*>
 bc000-Last-Act Section.
*>*********************
*>  Report Phase
*>
     sort     SortFile
              ascending key SdSortKey
              using  Supplemental-Part1-Out
              giving Supplemental-Part2-In.
     if       Git-Table-Count > 1
              sort  Git-Elements ascending Git-Word.
*> Print order:
*> Note that although some sections are not yet supported in OC they
*>       are, in cobxref.
*>   Xref'd -
*>     At bc090 = In order: File Section, Working-Storage, Local-Storage,
*>                 Linkage, Communication, Report, Screen
*>     At bc600 = Globals (in nested modules)
*>     At bc190 = Special-names & Conditions (& linked variables),
*>     At bc300 = Functions,
*>     At bc200 = Procedure Div,
*>     At bc400 = Unreferenced: File & WS,
*>     At bc500 = Unreferenced Procedure,
*>     At bc620 = Unreferenced Globals (throughout source)
*>
     if       not All-Reports
              go to bc090-Last-Pass2.
*>
*> produce group W-S xref & procedure used in testing
*>  and taken from original code circa 1983.
*>  ------- Leave in just in case needed for testing ----
*>
 bc010-group-report.
     move     spaces to saveSkaDataName.
     open     input Supplemental-Part2-In.
     read     Supplemental-Part2-In at end
              display Msg1
              go to bc000-Exit.
     perform  zz150-WriteHdb thru zz150-Exit.
     perform  zz150-WriteHdb8 thru zz150-Exit.
     move     zero to q.
     go       to bc030-IsX.
*>
 bc020-Read-Sorter.
     read     Supplemental-Part2-In at end
              perform bc050-Check-Q
              close Supplemental-Part2-In
              go to bc090-Last-Pass2.
*>
 bc030-IsX.
     if       SkaDataName = spaces
              go to bc020-Read-Sorter.
     perform  bc040-PrintXRef thru bc080-Exit.
     go       to bc020-Read-Sorter.
*>
 bc040-PrintXRef.
     if       SkaDataName = saveSkaDataName
              go to bc070-ConnectD.
     move     SkaDataName to saveSkaDataName.
*>
 bc050-Check-Q.
     if       XrDataName not = spaces
         and  q = zero
              move 1 to q.
     if       q > zero
              write PrintLine
              move zero to q
              move spaces to PrintLine.
*>
 bc060-ConnectC.
     move     spaces to PrintLine.
     move     SkaDataName to XrDataName.
     move     SkaRefNo to XrDefn.
     move     LSect (SkaWSorPD) to XrType.
     go       to bc080-Exit.
*>
 bc070-ConnectD.
     if       q > 7
              perform bc050-Check-Q.
     add      1 to q.
     move     SkaRefNo to XrReference (q).
*>
 bc080-Exit.
     Exit.
*>
 bc090-Last-Pass2.
*>****************
*> printout W-S section blocks as needed
*> Check if any w-s used in module if not, do conditions, functions etc
*>
     move     70 to Line-Count.
     if       Section-Used-Table not = zeros
              move  1 to WS-Anal1
              perform bc100-Working-Storage-Report
                    thru bc180-Exit 7 times.
*>
     if       Git-Table-Count > zero
              perform bc600-Print-Globals thru bc600-Exit.
     go       to bc190-Do-Conditions.
*>
 bc100-Working-Storage-Report.
*>****************************
*>  skip section if no data
*>
     if       USect (WS-Anal1) = zero
              add 1 to WS-Anal1
              go to bc180-Exit.
*>
     move     spaces to saveSkaDataName.
     open     input Supplemental-Part2-In.
     read     Supplemental-Part2-In at end
              display Msg1
              go to bc000-Exit.
     perform  zz150-WriteHdb thru zz150-Exit.
     perform  zz150-WriteHdb2 thru zz150-Exit.
     move     zero to q.
*>
*> group report
*>
     go       to bc120-IsX2.
*>
 bc110-Read-Sorter.
     read     Supplemental-Part2-In at end
              add 1 to WS-Anal1
              perform  bc140-Check-Q
              close Supplemental-Part2-In
              go to bc180-Exit.
*>
 bc120-IsX2.
     if       SkaDataName = spaces
              go to bc110-Read-Sorter.
     perform  bc130-PrintXRef2 thru bc170-Exit.
     go       to bc110-Read-Sorter.
*>
 bc130-PrintXRef2.
*>      test was 8
     if       SkaDataName = saveSkaDataName
              go to bc160-ConnectD2.
*>
     if       SkaWSorPD > WS-Anal1
              go to bc170-Exit.
     if       SkaWSorPD not = WS-Anal1
              go to bc170-Exit.
*>
*> new variable groups 1 thru 7
*>
     move     SkaDataName to saveSkaDataName.
     move     SkaWSorPD   to saveSkaWSorPD.
     move     SkaWSorPD2  to saveSkaWSorPD2.
*>
 bc140-Check-Q.
     if       XrDataName not = spaces
         and  q = zero
              move 1 to q.
     if       q > zero
              write PrintLine
              move zero to q
              move 1 to q2
              move spaces to PrintLine.
*>
 bc150-ConnectC2.
     move     spaces to PrintLine.
     move     SkaDataName to XrDataName.
     move     SkaRefNo to XrDefn.
     move     LSect (SkaWSorPD) to XrType.
     go       to bc170-Exit.
*>
 bc160-ConnectD2.
     if       q > 7
              perform bc140-Check-Q.
     add      1 to q.
     move     SkaRefNo to XrReference (q).
 bc170-Exit.
     exit.
*>
 bc180-Exit.
     exit.
*>
 bc190-Do-Conditions.
*>
*> start with sorted variables
*>
     if       Con-Tab-Count = zero
              go to bc195-Done.
     if       Con-Tab-Count > 1
              sort  Con-Tab-Blocks ascending Variables.
     move     "[S]" to hdr11a-sorted.
     move     spaces to hdr11b-sorted.
     perform  zz150-WriteHdb.
     perform  zz150-WriteHdb7 thru zz150-Exit.
     move     zero to a.
     perform  bc192-Print-Conditions.
     go       to bc194-Now-Reverse.
 bc192-Print-Conditions.
     if       a < Con-Tab-Count
              add 1 to a
              move spaces to PrintLine2
              move  Conditions (a) to P-Variables
              move  Variables (a) to P-Conditions
              write PrintLine2
              go to bc192-Print-Conditions.
*>
 bc194-Now-Reverse.
*>
*> now sort conditions if more than 1 element in table
*>   and print else don't
*>
     if       Con-Tab-Count > 1
              sort  Con-Tab-Blocks ascending Conditions
              move     "[S]" to hdr11b-sorted
              move     spaces to hdr11a-sorted
              perform  zz150-WriteHdb
              perform  zz150-WriteHdb7 thru zz150-Exit
              move     zero to a
              perform  bc192-Print-Conditions.
     move     spaces to PrintLine2.
 bc195-Done.
     perform  bc300-Last-Pass4 thru bc399-Exit.
*>
*> now pass3 (fall thru)
*>
 bc200-Last-Pass3.
*>****************
*> now do procedure div and ref to procedure div but no functions
*>
     move     spaces to saveSkaDataName.
     move     zero to saveSkaWSorPD saveSkaWSorPD2 q2.
     open     input Supplemental-Part2-In.
     read     Supplemental-Part2-In at end
              display Msg1
              go to bc000-Exit.
     perform  zz150-WriteHdb.
     move     "Procedure" to hdr8-hd
     perform  zz150-WriteHdb3 thru zz150-Exit.
     move     zero to q.
     go       to bc220-IsX3.
 bc210-Read-Sorter3.
     read     Supplemental-Part2-In at end
              perform bc140-Check-Q
              close Supplemental-Part2-In
              if   q2 = zero
                   move spaces to PrintLine
                   move "None" to XrDataName
                   write PrintLine
              end-if
              go to bc400-Last-Pass5.
*>
 bc220-IsX3.
     if       SkaDataName = spaces
              go to bc210-Read-Sorter3.
     perform  bc230-PrintXRef3 thru bc270-Exit.
     go       to bc210-Read-Sorter3.
*>
 bc230-PrintXRef3.
*>
*> ignore all working-storage
*>
     if       SkaDataName not = saveSkaDataName
         and  SkaWSorPD not = 8
              move  SkaDataName to saveSkaDataName
              move  SkaWSorPD   to saveSkaWSorPD
              move  SkaWSorPD2  to saveSkaWSorPD2
              go to bc270-Exit.
*>
*> catch any redefines
*>
     if       SkaDataName = saveSkaDataName
         and  saveSkaWSorPD not = 8
              go to bc270-Exit.
*>
*> catch any procedure followed by functions
*>   dont think this can happen
*>
     if       SkaDataName = saveSkaDataName
         and  saveSkaWSorPD = 8
         and  SkaWSorPD > 8
              go to bc270-Exit.
*>
     if       SkaDataName = saveSkaDataName
              go to bc260-ConnectD3.
     move     SkaDataName to saveSkaDataName.
     move     SkaWSorPD   to saveSkaWSorPD.
     move     SkaWSorPD2  to saveSkaWSorPD2.
     perform  bc140-Check-Q.
 bc250-ConnectC3.
     move     spaces to PrintLine.
     move     SkaDataName to XrDataName.
     move     SkaRefNo to XrDefn.
*>
*> process sections
*>
     if       SkaWSorPD2 not = 1
              move LSect (SkaWSorPD) to XrType
     else
              move "S" to XrType.
     go       to bc270-Exit.
 bc260-ConnectD3.
     if       q > 7
              perform bc140-Check-Q.
     add      1 to q.
     move     SkaRefNo to XrReference (q).
 bc270-Exit.
     exit.
*>
 bc300-Last-Pass4.
*>****************
*> now do functions
*>
     if       USect (9) = zero
              go to bc399-Exit.
     move     spaces to saveSkaDataName.
     move     zero to saveSkaWSorPD saveSkaWSorPD2 q2.
     move     70 to Line-Count.
     open     input Supplemental-Part2-In.
     read     Supplemental-Part2-In at end
              display Msg1
              go to bc000-Exit.
     move     zero to q.
     go       to bc320-IsX4.
*>
 bc310-Read-Sorter4.
     read     Supplemental-Part2-In at end
              perform bc335-Check-Q
              close Supplemental-Part2-In
              go to bc399-Exit.
 bc320-IsX4.
     if       SkaDataName = spaces
              go to bc310-Read-Sorter4.
     perform  bc330-PrintXRef4 thru bc360-Exit.
     go       to bc310-Read-Sorter4.
 bc330-PrintXRef4.
*>
*> ignore all working-storage & procedure
*>
     if       SkaWSorPD not = 9
              go to bc360-Exit.
*>
     if       Line-Count > 60
              move "Functions" to hdr8-hd
              move zero to Line-Count
              perform zz150-WriteHdb
              perform zz150-WriteHdb3 thru zz150-Exit.
*>
     if       SkaDataName = saveSkaDataName
              go to bc350-ConnectD4.
     move     SkaDataName to saveSkaDataName.
 bc335-Check-Q.
     if       XrDataName not = spaces
         and  q = zero
              move 1 to q.
     if       q > zero
              write PrintLine
              move zero to q
              move 1 to q2
              move spaces to PrintLine.
 bc340-ConnectC4.
     move     spaces to PrintLine.
     move     SkaDataName to XrDataName.
     move     SkaRefNo to XrDefn.
     move     LSect (SkaWSorPD) to XrType.
     go       to bc360-Exit.
 bc350-ConnectD4.
     if       q > 7
              perform bc335-Check-Q.
     add      1 to q.
     move     SkaRefNo to XrReference (q).
 bc360-Exit.
     exit.
*>
 bc399-Exit.
     exit.
*>
 bc400-Last-Pass5.
*>****************
*> now do non referenced ws but ignore references of zero (Globals).
*>
     move     spaces to saveSkaDataName.
     move     zero to saveSkaWSorPD saveSkaWSorPD2 S-Pointer.
     open     input Supplemental-Part2-In.
     read     Supplemental-Part2-In at end
              display Msg1
              go to bc000-Exit.
     perform  zz150-WriteHdb.
     perform  zz150-WriteHdb4 thru zz150-Exit.
     move     zero to q.
     go       to bc420-IsX5.
*>
 bc410-Read-Sorter5.
     read     Supplemental-Part2-In at end
              perform bc440-Check-4Old
              close Supplemental-Part2-In
              if   S-Pointer = zero
                   move spaces to PrintLine
                   move "None" to XrDataName
                   write PrintLine
              end-if
              go to bc500-Last-Pass6.
 bc420-IsX5.
*>
*> ignore zero refs = Globals  ??????????
*>
     if       SkaDataName = spaces
           or SkaRefNo = zeros
              go to bc410-Read-Sorter5.
     perform  bc430-PrintXRef5 thru bc450-Exit.
     go       to bc410-Read-Sorter5.
 bc430-PrintXRef5.
*>
*> ignore redefines - No I won't
*>
*>     if       SkaDataName = saveSkaDataName
*>         and  SkaWSorPD < 8
*>              go to bc450-Exit.
     if       SkaDataName = saveSkaDataName
              move 2 to q
              go to bc450-Exit.
*> 1st copy of a name can't be non w-s
     if       SkaWSorPD > 7
              go to bc450-Exit.
*> print Only occurance then store new one
     perform  bc440-Check-4Old.
*>
     move     SkaDataName to saveSkaDataName.
*>
*> first record for a given name
*>
     move     spaces to PrintLine.
     move     SkaDataName to XrDataName.
     move     SkaRefNo to XrDefn.
     move     LSect (SkaWSorPD) to XrType.
     move     1 to q.
     go       to bc450-Exit.
 bc440-Check-4Old.
     if       q = 1
              move 1 to S-Pointer
              write PrintLine.
 bc450-Exit.
     exit.
*>
 bc500-Last-Pass6.
*>****************
*> now do non referenced procedure paragraphs.
*>
     move     spaces to saveSkaDataName.
     move     zero to saveSkaWSorPD S-Pointer.
     open     input Supplemental-Part2-In.
     read     Supplemental-Part2-In at end
              display Msg1
              go to bc000-Exit.
     perform  zz150-WriteHdb.
     perform  zz150-WriteHdb5 thru zz150-Exit.
     move     zero to q.
     go       to bc520-IsX6.
 bc510-Read-Sorter6.
     read     Supplemental-Part2-In at end
              perform bc540-Check-4Old
              perform bc540-Check-4Old6
              close Supplemental-Part2-In
              go to bc000-Exit.
 bc520-IsX6.
     if       SkaDataName = spaces
              go to bc510-Read-Sorter6.
     perform  bc530-PrintXRef6 thru bc550-Exit.
     go       to bc510-Read-Sorter6.
 bc530-PrintXRef6.
*>
*> ignore all non procedure
*>
     if       SkaDataName = saveSkaDataName
              move zero to q
              go to bc550-Exit.
*> print only occurance then store new one
     if       q = 1
        and   saveSkaWSorPD = 8
              move 1 to S-Pointer
              write PrintLine.
*>
     move     SkaDataName to saveSkaDataName.
     move     SkaWSorPD to saveSkaWSorPD.
*>
*> first record for a given name
*>
     move     spaces to PrintLine.
     move     SkaDataName to XrDataName.
     move     SkaRefNo to XrDefn.
     if       SkaWSorPD2 not = 1
              move LSect (SkaWSorPD) to XrType
     else
              move "S" to XrType.
     move     1 to q.
     go       to bc550-Exit.
 bc540-Check-4Old.
     if       q = 1 and saveSkaWSorPD = 8
              move 1 to S-Pointer
              write PrintLine.
 bc540-Check-4Old6.
     if       S-Pointer = zero
              move spaces to PrintLine
              move "None" to XrDataName
              write PrintLine.
 bc550-Exit.
     exit.
*>
 bc600-Print-Globals.
*>*******************
*>  Print Global List for all xrefd modules
*>
     perform  zz150-WriteHdb thru zz150-Exit.
     perform  zz150-WriteHdb2b thru zz150-Exit.
     move     spaces to PrintLine.
     perform  varying a from 1 by 1 until a > Git-Table-Count
              move Git-RefNo (a) to XrDefn
              move Git-HoldWSorPD (a) to b
              if Reports-In-Lower
                  move function lower-case (Git-Word (a))
                                                   to XrDataName
                  move function lower-case (Git-Prog-Name (a))
                                                   to PL-Prog-Name
              else
                  move Git-Word (a) to XrDataName
                  move Git-Prog-Name (a) to PL-Prog-Name
              end-if
              move LSect (b) to XrType
              write PrintLine
     end-perform.
*>
 bc600-Exit.
     exit.
*>
 bc620-Do-Global-Conditions.
*>**************************
*> Produce report of unused Global Conditions if any
*>
     if       Git-Table-Count = zero
              go to bc629-Exit.
*>
     perform  zz150-WriteHdb.
     perform  zz150-WriteHdb6 thru zz150-Exit.
     move     zero to a b.
     perform  varying a from 1 by 1 until a > Git-Table-Count
              if    Git-In-Use-Flag (a) = space
                    move  spaces to PrintLine
                    move  Git-Word (a)  to XrDataName
                    move  git-RefNo (a) to XrDefn
                    move LSect (Git-HoldWsorPD (a)) to XrType
                    if  Git-Build-No (a) = 88
                        move "C" to XrCond
                    else
                        move space to XrCond
                    end-if
                    move 1 to b
                    write PrintLine
              end-if
     end-perform
     if       b = zero
              move spaces to PrintLine
              move "None" to XrDataName
              write PrintLine.
 bc629-Exit.
     exit.
 bc000-Exit.
     exit.
*>
 zz000-Routines Section.
 zz000-Inc-CobolRefNo.
     add      1 to Gen-RefNo1.
*>
 zz000-OutputSource.
     if       List-Source
              move  spaces to Source-List
              move  SourceRecIn to SourceOutput
              move  Gen-RefNo1 to sl-Gen-RefNo1
              write Source-List.
*>
 zz030-Write-Sort.
     move     HoldWSorPD to SkaWSorPD.
     move     HoldWSorPD2 to SkaWSorPD2.
     move     wsFoundWord2 (1:CWS) to wsFoundNewWord4.
     if       Reports-In-Lower
              move function lower-case (wsFoundWord2 (1:CWS)) to
                    wsFoundNewWord4.
     if       HoldWSorPD > 7
              perform zz140-Function-Check thru zz140-Exit.
*>
*> stops dups on same fn and refno
*>move 9 to SkaWSorPD
     if       wsFoundNewWord4 not = SkaDataName
         or   Gen-RefNo1 not = SkaRefNo
              move wsFoundNewWord4 to SkaDataName
              move Gen-RefNo1 to SkaRefNo
              move 1 to USect (SkaWSorPD)
              write SortRecord
              if   HoldWSorPD > 7  *> only do for proc div
                   perform zz310-Check-For-Globals thru zz319-Exit
              end-if
     end-if.
*>
 zz100-Get-A-Source-Record.
*>*************************
*> reads a source record, ignoring comments cleans out excessive
*>   spaces, ';', ',' etc
*>
     if       Had-End-Prog
              move zero to sw-Had-End-Prog
              go to zz100-New-Program-point.
     if       End-Prog
              go to zz100-Exit.
     if       Source-Eof
              display Msg8
              go to zz100-Exit.
*>
     move     spaces to SourceRecIn SourceInWS.
     read     SourceInput at end
              move 1 to sw-Source-Eof
              GO TO zz100-Exit.
     move     function upper-case (SourceRecIn)
                   to SourceInWS.
*>
*> change tabs to spaces prior to printing & remove OC comment lines eg '#'
*>
     if       (SourceInWS (1:1) = "#" or = "$")
              go to zz100-Get-A-Source-Record.
*> next won't happen with fn.i or .t input
     if       (SourceInWS (1:1) = "*" or = "/")
              perform zz000-Inc-CobolRefNo
              perform zz000-Outputsource
              go to zz100-Get-A-Source-Record.
*>
*> remove unwanted chars and all multi spaces so that unstrings
*>  can work easier Includes literals " " etc
*> Doesn't matter if literals get screwed up in this way
*>
*>    inspect  SourceInWS replacing all x"09" by space.
     inspect  SourceInWS replacing all ";" by space.
*>
*> This could cause a problem in ws so do in proc div
*>
     if       HoldWSorPD = 8
              inspect SourceInWS replacing all "," by space
     end-if
     inspect  SourceInWS replacing all "&" by space.
     perform  zz120-Replace-Multi-Spaces thru zz120-Exit.
     move     Line-End to Source-Line-End.
*>
*> count but do not O/P blank lines
*>
      if       d < 1
               perform zz000-Inc-CobolRefNo
               go to zz100-Get-A-Source-Record.
*>
     if       SourceInWS (1:12) = "END PROGRAM "
              perform zz000-Inc-CobolRefNo
              perform zz000-Outputsource
              go to zz100-Get-A-Source-Record.
*>
     if       HoldWSorPD > 7
        and   (SourceInWS (1:12) = "ID DIVISION."
         or   SourceInWS (1:20) = "IDENTIFICATION DIVIS")
              move 1 to sw-End-Prog sw-Had-End-Prog sw-Nested
              move 1 to S-Pointer2
              go to zz100-Exit.
*>
 zz100-New-Program-point.
     perform  zz000-Inc-CobolRefNo.
     perform  zz000-Outputsource.
     move     1 to S-Pointer2.
     move     zero to Source-Words.
*> == cobol85/NC/NC113M.CBL
*> Check if we have a section name or proc. 1st word name only
*> ie SECTION or DIVISION is on next line
*> but that cant happen if line-end > 15
*>
     if       Source-Line-End > 15
              move zero to HoldFoundWord2-Size
                           HoldFoundWord2-Type
              perform  zz170-Check-4-Section thru zz170-Exit
              go to zz100-Exit.
*>
*> now it could be the 1st word, 2nd word and . for line 2 or 3.
*> Got it? Good, now explain it to me !
*>
     if       HoldFoundWord2-Size = zero
              perform  varying d from 1 by 1 until d > 8
               if Sht-Section-Name (d) = SourceInWS (1:Source-Line-End)
                 move Spaces               to HoldFoundWord2
                 move Sht-Section-Name (d) to HoldFoundWord2
                 add 1 Source-Line-End giving HoldFoundWord2-Size
                 go to zz100-Get-A-Source-Record
               end-if
              end-perform
     else
            if   HoldFoundWord2-Type > zero
             and (SourceInWS (1:7) = "SECTION" or = "DIVISIO")
                 add 1 HoldFoundWord2-Size giving d
                 string SourceInWS (1:Line-End) delimited by size
                        into HoldFoundWord2  pointer d
                 move HoldFoundWord2 to SourceInWS
                 move zero to HoldFoundWord2-Size
            end-if
     end-if
*>
*> Ignoring fact if period missing, ASSUMING get-a-word covers it
*>   Here I go, Ass-uming again
*>
*> need this here
     perform  zz170-Check-4-Section thru zz170-Exit.
 zz100-Exit.
     exit.
*>
 zz110-Get-A-Word.
*>****************
*>  S-Pointer2 must be set to => 1 prior to call
*> pointer is a tally of init leading spaces
*>
     if       Source-Eof
          or  End-Prog
              go to zz110-Exit.
     if       S-Pointer2 not < Source-Line-End
         and  SourceInWS (S-Pointer2:1) = "."
              move "." to Word-Delimit
              move zero to Word-Length
              move space to SourceInWS (S-Pointer2:1)
              move spaces to wsFoundWord2
              go to zz110-Exit.
*>     if       S-Pointer2 < Source-Line-End
*>              inspect SourceInWS tallying S-Pointer2 for leading spaces.
*>
     if       S-Pointer2 > Source-Line-End
          or  S-Pointer2 > 1024
              go to zz110-Get-A-Word-OverFlow.
*>
*> S-Pointer2 = 1st non space
*>
 zz110-Get-A-Word-Unstring.
     move     spaces to wsFoundWord2.
     move     S-Pointer2 to s.
*>*****************************************************************
*> Note that after unstring sp2 will be at 1st char AFTER delimiter
*>*****************************************************************
     unstring SourceInWS delimited by " " or "."
              into wsFoundWord2
               delimiter in Word-Delimit
                with pointer S-Pointer2.
*> check 1st char
     if       S-Pointer2 > 1024
              go to zz110-Get-A-Word-OverFlow.
     if       wsf1-1 = space
         and  SourceInWS (S-Pointer2:1) = "."
              move "." to Word-Delimit
              move zero to Word-Length
              move spaces to wsFoundWord2
              go to zz110-Exit.
     if       wsf1-1 = space
              go to zz110-Get-A-Word-Unstring.
     if       (wsf1-1 numeric
           or wsf1-1 = "-"
           or wsf1-1 = "+")
         and  SourceInWS (S-Pointer2:1) not = space
              move s to S-Pointer2
              unstring SourceInWS delimited by " "
                into wsFoundWord2
                 delimiter in Word-Delimit
                  with pointer S-Pointer2.
*>
     subtract 2 from S-Pointer2 giving e.
     if       Word-Delimit = space
         and  SourceInWS (e:1) = "."
              move "." to Word-Delimit.
*>
     if       GotPicture = 1
          and SourceInWS (s:3) not = "IS "
*> this next test may not be needed ????
*>**************        and   Word-Delimit = "."
        and   (SourceInWS (s:1) = "$" or = Currency-Sign
                             or = "/" or = "B" or = "0" or = "."
                             or = "," or = "+" or = "-" or = "C"
                             or = "D" or = "*" or = "Z" or = "9"
                             or = "X" or = "A" or = "S" or = "V"
                             or = "P" or = "1" or = "N" or = "E")
              move s to S-Pointer2
              unstring SourceInWS delimited by " " into wsFoundWord2
                 delimiter in Word-Delimit
                  with pointer S-Pointer2
              end-unstring
              subtract 2 from S-Pointer2 giving e
              if  SourceInWS (e:1) = "."
                   move "." to Word-Delimit
              end-if
              move 1 to WasPicture
     end-if
*>
*> This could cause a problem ??????
*>
     if       GotPicture = zero
              inspect  wsFoundWord2 replacing all "," by space
     end-if
*>
     if       wsf1-1 = "("
         and (wsFoundWord2 (2:1) = quote or = "'")
              add 2 to s giving S-Pointer2
              move wsFoundWord2 (2:1) to wsFoundWord2 (1:1)
                                         Word-Delimit2
              go to zz110-Get-A-Word-Literal2.
*>
     if       wsf1-1 = "("
         and  wsFoundWord2 (2:1) = space
              add 1 to S-Pointer2
              go to zz110-Get-A-Word.
     if       wsf1-1 = ")"
              go to zz110-Get-A-Word.
*>
     if       wsf1-1 not = quote and not = "'"
              perform  varying z from 1024 by -1
                  until wsFoundWord2 (z:1) not = space
              end-perform
              move z to Word-Length
              go to zz110-Get-A-Word-Copy-Check.
*>
 zz110-Get-A-Word-Literal.
     move     wsf1-1 to Word-Delimit2.
     add      1 to s giving S-Pointer2.
 zz110-Get-A-Word-Literal2.
     move     spaces to wsFoundWord2 (2:1023).
     unstring SourceInWS delimited by Word-Delimit2
              into wsFoundWord2 (2:1023)
               delimiter in Word-Delimit
                with pointer S-Pointer2.
*>
*> so S-Pointer2 = " +1 & s = starter "
*>     have we another Word-Delimit?
*>
     if       Word-Delimit not = Word-Delimit2
              perform  varying z from 1024 by -1
                  until wsFoundWord2 (z:1) not = space
              end-perform
              add 1 to z
     else
              subtract s from S-Pointer2 giving z.
     move     Word-Delimit2 to wsFoundWord2 (z:1).
     move     z to Word-Length.
*>
*>  word is quoted literal or word so we are done
*>
     go       to zz110-Get-A-Word-Copy-Check.
 zz110-Get-A-Word-OverFlow.
     move     1 to S-Pointer2.
     perform  zz100-Get-A-Source-Record thru zz100-Exit.
     if       Source-Eof
              go to zz110-Exit.
     go       to zz110-Get-A-Word.
 zz110-Get-A-Word-Copy-Check.
*>
     add      1 to Source-Words.
     if we-are-testing
        display "zz110: WD=" word-delimit
                " WSF2=" wsfoundword2 (1:word-length).
     if       Word-Length < 1
              display "zz110-GAWCH: Oops, zero length word"
              display " Report this to support".
*>
*> if the leading char check when delim is period dont work
*>   then this will be tested higher up in code !
*>
     if       wsFoundWord2 (1:3) not = "IS "
          and GotPicture = 1
              move zero to GotPicture.
*>
     if       wsFoundWord2 (1:4) = "PIC "
           or wsFoundWord2 (1:8) = "PICTURE "
              move 1 to GotPicture.
 zz110-Exit.
     exit.
*>
 zz120-Replace-Multi-Spaces.
*>**************************
*> remove any multi spaces within a source line
*>   find actual lengh of record in d
*>
*> run profiler against these routines and tidy 'em up if needed
*>
     perform  varying d from 1024 by -1
                   until SourceInWS (d:1) not = space
     end-perform
     if       d < 1
              go to zz120-Exit.
*>
     move     zero to a b c.
     move     spaces to wsFoundNewWord5.
     perform  zz120-Kill-Space thru zz120-Kill-Space-Exit.
     move     spaces to SourceInWS.
     move     wsFoundNewWord5 (1:b) to SourceInWS.
     move     b to Line-End d.
     if we-are-testing
        display "zz120A b=" b " after=" SourceInWS (1:b).
     go       to zz120-Exit.
*>
 zz120-Kill-Space.
     add      1 to a.
     if       a > d
              go to zz120-Kill-Space-Exit.
     if       SourceInWS (a:1) = space and c = 1
              add 1 to b
              move zero to c
              go to zz120-Kill-Space.
*>
     if       SourceInWS (a:1) = space
              go to zz120-Kill-Space.
     subtract 1 from a giving e.         *> a will always be 2 or more here
     if       SourceInWS (a:1) = "("
         and  SourceInWS (e:1) not = space
         and  HoldWSorPD > 7
              add 2 to b
     else
              add 1 to b.
     move     SourceInWS (a:1) to wsFoundNewWord5 (b:1).
     move     1 to c.
     go       to zz120-Kill-Space.
 zz120-Kill-Space-Exit.
     exit.
*>
 zz120-Exit.
     exit.
*>
 zz130-Extra-Reserved-Word-Check.
*>*******************************
*>  Check for any other reserved words not in other checks
*>  note that max reserved word is 25 characters, so compare like 4 like
*>
     move     zero to a.
     search   all Reserved-Names
                  at end go to zz130-exit
              when Resvd-Word (Resvd-Idx) = wsFoundWord2 (1:25)
                set a to Resvd-Idx.
 zz130-Exit.
     exit.
*>
 zz140-Function-Check.
*>********************
*> CALLS:  Only after moving all values to SortRecord and before
*>         write verb.
*>
*> Do we have an intrinsic function name
*>           if so modify sort rec for section printing
*> Note that P-oc-implemented = zero if not implemented,
*>    but treated as the same as its still a reserved word
*>
     move     zero to F-Pointer.
     search   all All-Functions
                  at end go to zz140-exit
              when P-function (All-Fun-Idx) = wsFoundNewWord4
                move 9 to SkaWSorPD
                move 1 to SkaWSorPD2
                set F-Pointer to All-Fun-Idx.
 zz140-Exit.
     exit.
*>
 zz150-WriteHdb.
     move     spaces to h1programid.
     accept   hddate from date.
     if       hddate not = "000000"
              move hd-y to hd2-y
              move hd-m to hd2-m
              move hd-d to hd2-d.
     accept   hdtime from time.
     if       hdtime not = "00000000"
              move hd-hh to hd2-hh
              move hd-mm to hd2-mm
              move hd-ss to hd2-ss
              move hd-uu to hd2-uu.
     string   HoldID delimited by space
              "    " delimited by size
              hd-date-time delimited by size
              into h1programid.
     move     function when-compiled to WS-When-Compiled.
     move     WS-WC-DD  to H1-DD.
     move     WS-WC-MM  to H1-MM.
     move     WS-WC-YY  to H1-YY.
     move     WS-WC-HH  to H1-HH.
     move     WS-WC-Min to H1-Min.
     move     spaces to PrintLine.
     write    PrintLine.
     write    PrintLine from hdr1.
     move     spaces to PrintLine.
     write    PrintLine.
 zz150-WriteHdb1.
     move     spaces to Hdr5-Prog-Name.
     string   HoldID delimited by space
              " (" delimited by size
              HoldID-Module delimited by space
              ")"  delimited by size
              into Hdr5-Prog-Name.
     move     Hdr5-Prog-Name to Hdr6-Hyphens.
     inspect  hdr6-hyphens replacing characters by "-"
              before initial "  ".
     write    PrintLine from hdr5-symbols.
     write    PrintLine from hdr6-symbols.
     go       to zz150-Exit.
 zz150-WriteHdb2.
     move     spaces to PrintLine.
     write    PrintLine.
     move     spaces to hdr7-variable.
     string   Full-Section-Name (WS-Anal1) delimited space
                ")" delimited by size into hdr7-variable.
     write    PrintLine from hdr7-ws.
     write    PrintLine from hdr3.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-WriteHdb2b.
     move     spaces to PrintLine.
     write    PrintLine.
     move    "ALL GLOBALS)" to hdr7-variable.
     write    PrintLine from hdr7-ws.
     write    PrintLine from hdr3.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-WriteHdb3.
     write    PrintLine from hdr8-ws.
     write    PrintLine from hdr3.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-WriteHdb4.
     write    PrintLine from hdr9.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-WriteHdb5.
     write    PrintLine from hdr10.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-WriteHdb6.
     write    PrintLine from hdr9B.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-WriteHdb7.
     write    PrintLine from hdr11.
     write    PrintLine from hdr12-hyphens.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-WriteHdb8.
     write    PrintLine from hdr2.
     write    PrintLine from hdr3.
     move     spaces to PrintLine.
     write    PrintLine.
     go       to zz150-Exit.
 zz150-Exit.
     exit.
*>
 zz160-Clean-Number.
      move    zero to Build-Number.
      if      Word-Length = 1
              move wsf3-1 to Build-Number
              go to zz160-Exit.
      if      Word-Length = 2
              compute Build-Number =
                            (wsf3-1 * 10) +
                             wsf3-2.
 zz160-Exit.
     exit.
*>
 zz170-Check-4-Section.
     move     space to GotASection.
     if       HoldWSorPD = 8
              go to zz170-Exit.
     if       sv1what = Section-Name (1)
              move 1 to HoldWSorPD
              move "Y" to GotASection
     else
      if      sv1what = Section-Name (2)
              move 2 to HoldWSorPD
              move "Y" to GotASection
      else
       if     sv1what = Section-Name (3)
              move 3 to HoldWSorPD
              move "Y" to GotASection
       else
        if    sv1what = Section-Name (4)
              move 4 to HoldWSorPD
              move "Y" to GotASection
        else
         if   sv1what = Section-Name (5)
              move 5 to HoldWSorPD
              move "Y" to GotASection
         else
          if  sv1what = Section-Name (6)
              move 6 to HoldWSorPD
              move "Y" to GotASection
          else
           if sv1what = Section-Name (7)
              move 7 to HoldWSorPD
              move "Y" to GotASection
           else
            if sv1what = Section-Name (8)
              move 8 to HoldWSorPD
              move "Y" to GotASection
              move zero to HoldWSorPD2.
*>
*> Changed section so we can clear Global flag
*>
     if       GotASection = "Y"
              move zero to sw-Git.
 zz170-Exit.
     exit.
*>
 zz180-Open-Source-File.
*>*********************
*> get source filename
*>
     accept   Arg-Number from argument-number.
     if       Arg-Number > zero
              move zero to String-Pointer
              perform zz180-Get-Program-Args Arg-Number times
     else     go to zz180-Check-For-Param-Errors.
*>
*> setup source filename
*>    dont need the pointers - kill it after next test
     move     1 to String-Pointer.
     unstring Arg-Value (1) delimited by spaces
              into SourceFileName
               with pointer String-Pointer.
*>
*> Now get temp environment variable & build temp sort file names
*>
     perform  zz182-Get-Env-Set-TempFiles thru zz182-Exit.
*>
 zz180-Check-For-Param-Errors.
     if       SourceFileName = spaces or
              String-Pointer < 5
              display Prog-Name
              display "Copyright (C) 1967-2009 Vincent Bryan Coen"
              display " "
              display "Parameters are"
              display " "
              display "1: Source File name (Mandatory)"
              display "2: -R    Print out source code prior to xreference " &
                                "listings in cobc free form"
              display "3: -L    reports in lowercase else upper"
              display "4: -TEST produces testing info"
              display "5: -DR   Display All reserved words & stop"
              display "6: -G    produce only group xref: Comp. MF"
              display "7: -H    Display this help message"
              display "   --H   as -H"
              move zero to return-code
              goback.
*>
     move     1 to String-Pointer String-Pointer2.
     perform  varying a from 1024 by -1 until Sourcefilename (a:1) not = space
     end-perform
     move     a to b.
     perform  varying b from b by -1 until b < 2 or SourceFileName (b:1) = "."
     end-perform
     if       b not < 2
              subtract 1 from b
              move SourceFileName (1:b) to Prog-BaseName
              add 1 to b
     end-if

*>     unstring Arg-Value (1) delimited by "." into Prog-BaseName
*>              with pointer String-Pointer.
     if       Prog-BaseName = SourceFileName
              string  Prog-BaseName  delimited by space
              ".pre"        delimited by size into SourceFileName.
     string   Prog-BaseName delimited by space
              ".lst"        delimited by size into Print-FileName
              with pointer String-Pointer2.
*>
*> Can now convert to upper-case as source filename is processed
*>
     move     function upper-case (Arg-Vals) to Arg-Vals.
*>
*> Check if help requested
*>
     if       "-H" = Arg-Value (2) or Arg-Value (3)
           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
              move zero to String-Pointer
              go to zz180-Check-For-Param-Errors.
     if       "--H" = Arg-Value (2) or Arg-Value (3)
           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
              move zero to String-Pointer
              go to zz180-Check-For-Param-Errors.
*>
*> Check v2 if we are listing the source
*>
      if      "-R" = Arg-Value (2) or Arg-Value (3)
           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
              move "Y" to sw-2.
*>
*> Check v4 if we are dumping all reserved words
*>
     if       "-DR" = Arg-Value (2) or Arg-Value (3)
           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
              move 1 to sw-4
              go to zz180-Exit.
*>
*> Check v5 if we are testing
*>
     if       "-TEST" = Arg-Value (2) or Arg-Value (3)
           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
              display " extra information for testing"
              move "Y" to sw-5.
*>
*> Check v6 if we are are doing Lower case reports insted of upper
*>
     if       "-L" = Arg-Value (2) or Arg-Value (3)
           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
              move 1 to sw-6.
*>***************************************************************
*>  THIS BLOCK FOR TESING and Comparing listing against MF etc  *
*>***************************************************************
*>
*> Check v1 if we are are only doing a group xref ie W-S and procedure
*>
     if       "-G " = Arg-Value (2) or Arg-Value (3)
           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
              move "A" to sw-1.
*>***************************************************************
*>    END OF SPECIAL TEST BLOCK but with bc030 - bc080 also     *
*>***************************************************************
     open     input SourceInput.
     if       fs-reply not = zero
              display Msg9
              move 16 to return-code
              goback.
     go       to zz180-Exit.
*>
 zz180-Get-Program-Args.
     add      1 to String-Pointer.
     accept   Arg-Value (String-Pointer) from argument-value.
*>
 zz182-Get-Env-Set-TempFiles.
*>**************************
     accept   Temp-PathName from Environment "TMPDIR".
     if       Temp-PathName = spaces
              accept Temp-PathName from Environment "TMP"
              if  Temp-PathName = spaces
                  accept Temp-PathName from Environment "TEMP"
                  if  Temp-PathName = spaces
                      move "/tmp" to Temp-PathName.
     if       Temp-PathName (1:1) = "/"   *> Its Linux/Unix
              move "/" to OS-Delimiter.
     if       Temp-PathName (1:1) = "\"   *> Its Windoz
              inspect Temp-PathName replacing all "/" by "\"   *> in case of /tmp
              move "\" to OS-Delimiter.
     string   Temp-PathName delimited by space
               OS-Delimiter delimited by size
                "Part1.tmp" delimited by size
              into Supp-File-1.
     string   Temp-PathName delimited by space
               OS-Delimiter delimited by size
                "Part2.tmp" delimited by size
              into Supp-File-2.
     string   Temp-PathName delimited by space
               OS-Delimiter delimited by size
                 "Sort1tmp" delimited by size
              into Sort1tmp.
     if we-are-testing
           display  "Temp path used is " Temp-PathName.
 zz182-Exit.
     Exit.
*>
 zz180-Exit.
     exit.
*>
 zz190-Init-Program.
*>
*>****************************************************************
*> initialise all Variables should we be processing nested modules
*>****************************************************************
*>
     move     spaces to PrintLine Global-Current-Word SortRecord
              saveSkaDataName SourceFileName Print-FileName
              wsFoundNewWord4 wsFoundNewWord3
              wsFoundNewWord2 wsFoundNewWord.
     move     high-values to Condition-Table.
     move     10 to Con-Tab-Size.
     move     zeros to GotEndProgram sw-Source-Eof Section-Used-Table
              HoldWSorPD HoldWSorPD2 Con-Tab-Count.
     move     1 to S-Pointer F-Pointer S-Pointer2.
 zz190-Exit.
     exit.
*>
 zz200-Load-Git.
*>
*> Load the Global Item Table with item associated with 01/FD Global
*>
     if       Global-Current-Level = high-values
              go to zz200-Exit.
     add      1 to Git-Table-Count.
     if       Git-Table-Count > Git-Table-Size
         and  Git-Table-Size < 10000
              add 10 to Git-Table-Size.
     if       Git-Table-Size > 10000
              move 10001 to Git-Table-Size        *> just in case
              display Msg10
              go to zz200-Exit.
     move     Global-Current-Word to Git-Word (Git-Table-Count).
     move     space to Git-In-Use-Flag (Git-Table-Count).
     move     Global-Current-RefNo to Git-RefNo (Git-Table-Count).
     move     Build-Number to Git-Build-No (Git-Table-Count).
     move     HoldID to Git-Prog-Name (Git-Table-Count).
     move     HoldWSorPD  to Git-HoldWSorPD (Git-Table-Count).
     move     HoldWSorPD2 to Git-HoldWSorPD2 (Git-Table-Count).
 zz200-Exit.
     exit.
*>
 zz310-Check-For-Globals.
*>**********************
     move zero to a1.
     perform  varying a1 from 1 by 1 until a1 > Git-Table-Count
              if  Git-Word (a1) = wsFoundNewWord4
                  move "1" to Git-In-Use-Flag (a1)
                  exit perform
              end-if
     end-perform.
*>
 zz319-Exit.
     exit.

 zz999-xtra-test-for-xref.
*>
*> this may not compile without error in OC but is 4 testing xref
*>
    display "zz999: THIS SHOULD NOT BE STARTED and is an ERROR".
    go to zz999-exit.
      MOVE s (FUNCTION ABS (t) : 3) to q.
     move FUNCTION TRIM (FUNCTION REVERSE (FUNCTION UPPER-CASE (wsfoundnewword)))
                              to wsfoundnewword4.
zz999-exit.  exit.
