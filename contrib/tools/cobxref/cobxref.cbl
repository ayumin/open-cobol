000100 Identification division.
000200 program-id.            cobxref.
000300*>author.               Vincent Bryan Coen, Applewood Computers,
000310*>                      Applewood, Epping Road, Roydon, Essex, UK.
000400*>date-written.         28 July 1983 with code going back to 1967.
000500*>date-rewriten.        10 March 2007 with code going back to 1967.
000600*>date-compiled.        Today & Don't forget to update prog-name for builds
000700*>Security.             Copyright (C) 1967-2009, Vincent Bryan Coen.
000800*>                      Distributed under the GNU General Public License
000900*>                      v2.0. Only. See the file COPYING for details.
001100*>
001200*> Usage.               Cobol Cross Referencer for Open Cobol from v1.0.
001300*>
001400*> Changes.             See Changelog & Prog-Name.
      *
      *TODO: 20.01.09 change WS proc to cater for datanames and not whatever:
      * re: line|col|column [number|linage is]
      *     fore|background||control|size|key [is]
      *     thru|through
      *     start|length [of]
      *     footings [at]
      *     top|bottom
      *
001500*>*************************************************************************
001600*>
001700*> Copyright Notice.
001800*>*****************
001900*>
002000*> This file/program is part of Cobxref & Open Cobol
002010*>   and is copyright (c) Vincent B Coen.
002100*>
002200*> This program is free software; you can redistribute it and/or modify it
002300*> under the terms of the GNU General Public License as published by the
002400*> Free Software Foundation; version 2 ONLY.
002500*>
002600*> Cobxref is distributed in the hope that it will be useful, but WITHOUT
002700*> ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
002800*> FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
002900*> for more details. If it breaks, you own both pieces but I will endevor
002910*> to fix it, providing you tell me about the problem.
003000*>
003100*> You should have received a copy of the GNU General Public License along
003200*> with Cobxref; see the file COPYING.  If not, write to the Free Software
003300*> Foundation, 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
003400*>*************************************************************************
003500*>
003600 environment division.
003700 configuration section.
003800 source-computer.      linux.
003900 object-computer.      linux.
004000 special-names.
004100*> This lot is not needed by prog but used to see if OC accepts them
004200      switch-1 is sn-Test-1 on snt1-on off snt1-off.
004300*>      uspi-0 is sn-Test-2 on snt2-on off snt2-off.
004400*>      currency sign is "£".
004500*>      decimal-point is comma.
004600*>      call-convention 1 is cc-fred.
004700*>      console is crt
004800*>       cursor is fs-reply
004900*>       crt status fs-reply.
005000*>     command-line is prog-param-line.
005100*>      argument-value is prog-param-values.
005200*>      argument-number is prog-param-count.
005300 input-Output section.
005400 file-control.
005500*>
005600     select   Supplemental-Part2-In assign Supp-File-2
005700              organization line sequential.
005800*>
005900     select   Supplemental-Part1-Out assign Supp-File-1
006000              organization line sequential.
006100*>
006200     select   Source-Listing assign Print-FileName
006300              organization line sequential.
006400*>
006500     select   SourceInput assign SourceFileName
006600              organization line sequential
006700              file status fs-reply.
006800*>
006900     select   SortFile assign Sort1tmp.
007000*>
007100 i-o-control.
007200*>
007300     same record area for Supplemental-Part1-Out
007400                          Supplemental-Part2-In.
007500*>
007600 data division.
007700 file section.
007800 fd  Source-Listing.
007900 01  Source-List.
008000     03  sl-Gen-RefNo1     pic z(5)9bb.
008100     03  SourceOutput      pic x(255).
008200*>
008300 01  PrintLine.
008400     02  XrDataName        pic x(33).
008500     02  XrDefn            pic 9(6).
008600     02  XrType            pic x.
000610     02  XrCond            pic x.
008700     02  filler            pic x.
008800     02  filler     occurs 8.
008900       03  XrReference     pic 9(6).
009000       03  filler          pic x.
009100     02  filler            pic x(62).
009200*>
009300 01  filler.
009400     03  filler            pic x(42).
009500     03  PL-Prog-Name      pic x(32).
009600*>
009700 01  PrintLine2.
009800     03  P-Conditions      pic x(32).
009900     03  P-Variables       pic x(32).
010000*>
010100 fd  SourceInput.
010300 01  SourceRecIn           pic x(255).
010400*>
010500 fd  Supplemental-Part1-Out.
010700 01  SortRecord.
010800     03  SkaDataName       pic x(32).
010900     03  SkaWSorPD         pic 9.
011000     03  SkaWSorPD2        pic 9.
011100     03  SkaRefNo          pic 9(6).
011200*>
011300 fd  Supplemental-Part2-In.
011500 01  filler                pic x(40).
011600*>
011700 sd  SortFile.
011800 01  filler.
011900     03  SdSortKey         pic x(40).
012000*>
012100 working-storage section.
012200 77  Prog-Name             pic x(13) value "Xref v0.95.44".
012300 77  String-Pointer        Binary-Long  value 1.
012400 77  String-Pointer2       Binary-Long  value 1.
012500 77  S-Pointer             Binary-Long  value zero.
012600 77  S-Pointer2            Binary-Long  value zero.
012700 77  S-Pointer3            Binary-Long  value zero.
012800 77  S-Pointer4            Binary-Long  value zero.
012900 77  Line-Count            Binary-Long  value 70.
013000 77  Word-Length           Binary-Long  value zero.
013100 77  Line-End              Binary-Long  value zero.
013200 77  Source-Line-End       Binary-Long  value zero.
013300 77  Source-Words          Binary-Long  value zero.
013400 77  F-Pointer             Binary-Long  value zero.
013800 77  a                     Binary-Long  value zero.
013800 77  a1                    Binary-Long  value zero.
013900 77  b                     Binary-Long  value zero.
014000 77  c                     Binary-Long  value zero.
014100 77  d                     Binary-Long  value zero.
014200 77  e                     Binary-Long  value zero.
014300 77  s                     Binary-Long  value zero.
014400 77  t                     Binary-Long  value zero.
014500 77  y                     Binary-Long  value zero.
014600 77  y2                    Binary-Long  value zero.
014700 77  z                     Binary-Long  value zero.
014800 77  q                     Binary-Long  value zero.
014800 77  q2                    Binary-Long  value zero.
014900*>
015000*> System parameters control how xref works or reports
015100*>  May be add extra func for default.conf ?
015200*>
016800 77  sw-1                    pic x         value "N".
016900*  command line input -G
017200  88 All-Reports                           value "A".
015300 77  sw-2                  pic x           value "N".
015400  88 List-Source                           value "Y".
015500 77  sw-4                  pic 9           value zero.
015600  88  Dump-Reserved-Words                  value 1.
015700 77  sw-5                  pic x           value "N".
015800  88 We-Are-Testing                        value "Y".
015900 77  sw-6                  pic 9           value zero.
016000  88  Reports-In-Lower                     value 1.
016100*>
016200*> Switches used during processing
016300*>
      *> And these two are the size of any Cobol word currently set
      *> to value specified in PL22.4 20xx
      *>
       78  Cobol-Word-Size                       value 31.
       78  CWS                                   value 31.
      *>
016400 77  sw-Source-Eof         pic 9           value 0.
016500  88 Source-Eof                            value 1.
016600*> got end of program
016700 77  sw-End-Prog           pic 9           value zero.
016800  88 End-Prog                              value 1.
016900*> Had end of program (nested) - Confused yet? you will be!
017000 77  sw-Had-End-Prog       pic 9           value zero.
017100  88 Had-End-Prog                          value 1.
017200*> We have found a Global verb
017300 77  sw-Git                pic 9           value zero.
017400  88 Global-Active                         value 1.
017500*>  Multi modules in one source file flag
017600 77  sw-Nested             pic 9           value zero.
017700  88 Have-Nested                           value 1.
017800*>
013500 77  Arg-Number            pic 99          value zero.
013600 77  Gen-RefNo1            pic 9(6)        value zero.
013700 77  Build-Number          pic 99          value zero.
018200 77  GotEndProgram         pic 9           value zero.
018300 77  HoldWSorPD            pic 9           value 0.
018400 77  HoldWSorPD2           pic 9           value 0.
017900 77  Word-Delimit          pic x           value space.
018000 77  Word-Delimit2         pic x           value space.
       77  OS-Delimiter          pic x           value space.
018100 77  GotASection           pic x           value space.
       *> section name + 8 chars
018500 77  HoldFoundWord         pic x(40)       value spaces.
018600 77  saveSkaDataName       pic x(32)       value spaces.
018700 77  Saved-Variable        pic x(32)       value spaces.
018800 77  saveSkaWSorPD         pic 9           value zero.
018900 77  saveSkaWSorPD2        pic 9           value zero.
019000 77  WS-Anal1              pic 9           value zero.
019100 77  fs-reply              pic xx          value zeros.
019200 77  SourceFileName        pic x(64)       value spaces.
019300 77  Print-FileName        pic x(64)       value spaces.
019400 77  Prog-BaseName         pic x(60)       value spaces.
      *>
      *> in theory Linux can go to 4096 and Windoz 32,767
      *>
019410 77  Temp-Pathname         pic x(1024)     value spaces.
019420 77  Supp-File-1           pic x(1036)     value spaces.
019430 77  Supp-File-2           pic x(1036)     value spaces.
       77  Sort1tmp              pic x(1036)     value spaces.
019500 77  Global-Current-Word   pic x(32)       value spaces.
019600 77  Global-Current-Refno  pic 9(6)        value zero.
019700 77  Global-Current-Level  pic 99          value zero.
019800*>
019900 01  HoldID                pic x(32)       value spaces.
020000 01  HoldID-Module         pic x(32)       value spaces.
020100*>
020500 01  SourceInWS.
020900     03  sv1what           pic x(16).
021000     03  filler            pic x(239).
021100*>
021200 01  wsFoundWord.
021300     03  wsf1-3.
021400      04  wsf1-2.
021500       05  wsf1-1          pic x.
021600       05  filler          pic x.
021700      04  filler           pic x.
021900     03  filler            pic x(252).
022000*>
022100 01  wsFoundWord2 redefines wsFoundWord.
022200     03  wsf3-1            pic 9.    *> only used for Build-Number
022300     03  wsf3-2            pic 9.    *>   processing
022400     03  filler            pic x(253).
022500*>
022600 01  wsFoundNewWord        pic x(32).
022700 01  wsFoundNewWord2       pic x(32).
022800 01  wsFoundNewWord3       pic x(255).  *> max size quot lit 1 lin
022900 01  wsFoundNewWord4       pic x(32).
023000 01  wsFoundNewWord5       pic x(255). *> space removal source i/p
023100*>
023200 01  HDR1.
023300     03  filler            pic X(26)
023400                               value "ACS Cobol Cross Reference ".
023500     03  H1Prog-Name       pic x(14) value spaces.
023600     03  filler            pic x     value "(".
023700     03  H1-dd             pic 99.
023800     03  filler            pic x     value "/".
023900     03  H1-MM             pic 99.
024000     03  filler            pic x     value "/".
024100     03  H1-YY             pic 9(4).
024200     03  filler            pic x     value "@".
024300     03  H1-HH             pic 99.
024400     03  filler            pic x     value ":".
024500     03  H1-Min            pic 99.
024600     03  filler            pic xx    value ") ".
024700     03  filler            pic x(20) value "Dictionary File for ".
024800     03  h1programid       pic x(60) value spaces.
028000*>
028100 01  HDR2.
028200     03  filler            pic X(34) value "All Data/Proc Names".
028300     03  filler            pic X(19) value "Defn     Reference".
024900*>
025000 01  hdr3.
025100     03  filler            pic x(33) value all "-".
025200     03  filler            pic x     value "+".
025300     03  filler            pic x(63) value all "-".
025400*>
025500 01  hdr5-symbols.
025600     03  filler            pic x(19) value "Symbols of Module: ".
025700     03  hdr5-Prog-Name    pic x(67) value spaces.
025800*>
025900 01  hdr6-symbols.
026000     03  filler            pic x(19) value all "-".
026100*>
026200*> below is replaced with hyphens to size of Prog-Name
026300*>
026400     03  hdr6-hyphens      pic x(67) value spaces.
026500*>
026600 01  hdr7-ws.
026700     03  filler            pic x(14) value "Data Section (".
026800     03  hdr7-variable     pic x(20) value spaces.
026900     03  filler            pic x(8)  value "Defn".
027000     03  filler            pic x(9)  value "Locations".
027100*>
027200 01  hdr8-ws.
027300     03  hdr8-hd           pic x(9)  value "Procedure".
027400     03  filler            pic x(25) value spaces.
027500     03  filler            pic x(8)  value "Defn".
027600     03  filler            pic x(9)  value "Locations".
027700*>
027800 01  hdr9.
027900     03  filler            pic x(36)
028000                     value "Unreferenced Working Storage Symbols".
028100*>
027800 01  hdr9B.
027900     03  filler            pic x(38)
028000                   value "Unreferenced Globals throughout Source".
028100*>
028200 01  hdr10.
028300     03  filler            pic x(23)
028400                                  value "Unreferenced Procedures".
028500*>
028600 01  hdr11.
028700     03  filler            pic x(16) value "Variable Tested".
028800     03  hdr11a-sorted     pic xxx   value spaces.
028900     03  filler            pic x(12) value spaces.
029000     03  filler            pic x(8)  value "Symbol (".
029100     03  filler            pic x(15) value "88-Conditions)".
029200     03  hdr11b-sorted     pic xxx   value spaces.
029300     03  filler            pic x(5)  value spaces.
029400*>
029500 01  hdr12-hyphens.
029600     03  filler            pic x(62) value all "-".
029700*>
029800 01  hdtime                          value spaces.
029900     03  hd-hh             pic xx.
030000     03  hd-mm             pic xx.
030100     03  hd-ss             pic xx.
030200     03  hd-uu             pic xx.
030300 01  hddate                          value spaces.
030400     03  hd-y              pic xx.
030500     03  hd-m              pic xx.
030600     03  hd-d              pic xx.
030700*>
030800 01  hd-date-time.
030900     03  hd2-d             pic xx.
031000     03  filler            pic x     value "/".
031100     03  hd2-m             pic xx.
031200     03  filler            pic x     value "/".
031300     03  hd2-y             pic xx.
031400     03  filler            pic xx    value spaces.
031500     03  hd2-hh            pic xx.
031600     03  filler            pic x     value ":".
031700     03  hd2-mm            pic xx.
031800     03  filler            pic x     value ":".
031900     03  hd2-ss            pic xx.
032000     03  filler            pic x     value ":".
032100     03  hd2-uu            pic xx.
032200*>
032300 01  WS-When-Compiled.
032400     03  WS-WC-YY          pic 9(4).
032500     03  WS-WC-MM          pic 99.
032600     03  WS-WC-DD          pic 99.
032700     03  WS-WC-HH          pic 99.
032800     03  WS-WC-Min         pic 99.
032900     03  filler            pic x(9).
033000*>
033100 01  Error-messages. *> Sorry, English msgs Only
033200     03 Msg1      pic x(28) value "Aborting: No input stream".
033300     03 Msg2      pic x(29) value "Aborting: Early eof on source".
033400     03 Msg4      pic x(42)
033500               value "Logic Error:Lost1 wsFoundWord2 numeric? = ".
033600     03 Msg5      pic x(32)
033700                     value "Logic Error:Lost2 wsFoundWord2 =".
033800     03 Msg6      pic x(34)
033900                     value "Error: Con table size needs > 5000".
034000     03 Msg7      pic x(24) value "bb050 Error: Logic error".
034100     03 Msg8      pic x(26) value "Error: Eof on source again".
034200     03 Msg9      pic x(34)
034300                    value "Error: File not present Try Again!".
034400     03 Msg10     pic x(36)
034500                    value "Error: Git Table size exceeds 10,000".
034600     03 Msg16     pic x(66)  value "Error: " &
034610     "Eof on source possible logic error at aa047 ASSUMING again".
034800*>
034900 01  SectTable.
035000     03  filler            pic x(9) value "FWLKCRSPI".
035100 01  filler  redefines SectTable.
035200     03  LSect             pic x  occurs 9.
035300*> Keep track of sections used in analysed module
035400 01  Section-Used-Table  value zeros.
035500     03  USect             pic 9  occurs 9.
035600*> holds program parameter values from command line
035700 01  Arg-Vals                       value spaces.
035800     03  Arg-Value         pic x(128)  occurs 6.
035900*>
036000 01  Section-Names-Table.
036100     03  filler pic x(24) value "FILE SECTION.           ".
036200     03  filler pic x(24) value "WORKING-STORAGE SECTION.".
036300     03  filler pic x(24) value "LOCAL-STORAGE SECTION.  ".
036400     03  filler pic x(24) value "LINKAGE SECTION.        ".
036500     03  filler pic x(24) value "COMMUNICATION SECTION.  ".
036600     03  filler pic x(24) value "REPORT SECTION.         ".
036700     03  filler pic x(24) value "SCREEN SECTION.         ".
036800     03  filler pic x(24) value "PROCEDURE DIVISION.     ".
036900 01  filler   redefines Section-Names-Table.
037000     03  Full-Section-Name          occurs 8.
037100         05  Section-Name  pic x(16).
037200         05  filler        pic x(08).
037300*>
037400*> Here for cb_intrinsic_table in OC see :
037500*>   cobc/reserved.c in the open-cobol source directory but
037600*>    Totally ingoring the system_table as not needed/used by xref
037700*>
037800*> Also note that the number 0 or 1 indicates if the
037900*>  function/reserved word is implemented in Open Cobol
038000*>   but xref treats all as being reserved as they are so
038200*>
038300 01  Function-Table.
038400     03  filler pic x(28) value "1ABS                        ".
038500     03  filler pic X(28) value "1ACOS                       ".
038600     03  filler pic X(28) value "1ANNUITY                    ".
038700     03  filler pic X(28) value "1ASIN                       ".
038800     03  filler pic X(28) value "1ATAN                       ".
038900     03  filler pic X(28) value "0BOOLEAN-OF-INTEGER         ".
039000     03  filler pic X(28) value "1BYTE-LENGTH                ".
039100     03  filler pic X(28) value "1CHAR                       ".
039200     03  filler pic X(28) value "0CHAR-NATIONAL              ".
039300     03  filler pic X(28) value "1COMBINED-DATETIME          ".
039300     03  filler pic X(28) value "1CONCATENATE                ".
039400     03  filler pic X(28) value "1COS                        ".
039500     03  filler pic X(28) value "1CURRENT-DATE               ".
039600     03  filler pic X(28) value "1DATE-OF-INTEGER            ".
039700     03  filler pic X(28) value "1DATE-TO-YYYYMMDD           ".
039800     03  filler pic X(28) value "1DAY-OF-INTEGER             ".
039900     03  filler pic X(28) value "1DAY-TO-YYYYDDD             ".
040000     03  filler pic X(28) value "0DISPLAY-OF                 ".
040500     03  filler pic X(28) value "0E                          ".
040600     03  filler pic X(28) value "1EXCEPTION-FILE             ".
040700     03  filler pic X(28) value "0EXCEPTION-FILE-N           ".
040800     03  filler pic X(28) value "1EXCEPTION-LOCATION         ".
040900     03  filler pic X(28) value "0EXCEPTION-LOCATION-N       ".
041000     03  filler pic X(28) value "1EXCEPTION-STATEMENT        ".
041100     03  filler pic X(28) value "1EXCEPTION-STATUS           ".
041200     03  filler pic X(28) value "1EXP                        ".
041300     03  filler pic X(28) value "1EXP10                      ".
041400     03  filler pic X(28) value "1FACTORIAL                  ".
041500     03  filler pic X(28) value "1FRACTION-PART              ".
041600     03  filler pic X(28) value "0HIGHEST-ALGEBRAIC          ".
041700     03  filler pic X(28) value "1INTEGER                    ".
041800     03  filler pic X(28) value "0INTEGER-OF-BOOLEAN         ".
041900     03  filler pic X(28) value "1INTEGER-OF-DATE            ".
042000     03  filler pic X(28) value "1INTEGER-OF-DAY             ".
042100     03  filler pic X(28) value "1INTEGER-PART               ".
042200     03  filler pic X(28) value "1LENGTH                     ".
042300     03  filler pic X(28) value "0LOCALE-COMPARE             ".
042400     03  filler pic X(28) value "1LOCALE-DATE                ".
042500     03  filler pic X(28) value "1LOCALE-TIME                ".
042600     03  filler pic X(28) value "1LOCALE-TIME-FROM-SECONDS   ".
042700     03  filler pic X(28) value "1LOG                        ".
042800     03  filler pic X(28) value "1LOG10                      ".
042900     03  filler pic X(28) value "1LOWER-CASE                 ".
043000     03  filler pic X(28) value "0LOWEST-ALGEBRAIC           ".
043100     03  filler pic X(28) value "1MAX                        ".
043200     03  filler pic X(28) value "1MEAN                       ".
043300     03  filler pic X(28) value "1MEDIAN                     ".
043400     03  filler pic X(28) value "1MIDRANGE                   ".
043500     03  filler pic X(28) value "1MIN                        ".
043600     03  filler pic X(28) value "1MOD                        ".
043700     03  filler pic X(28) value "0NATIONAL-OF                ".
043800     03  filler pic X(28) value "1NUMVAL                     ".
043900     03  filler pic X(28) value "1NUMVAL-C                   ".
044000     03  filler pic X(28) value "0NUMVAL-F                   ".
044100     03  filler pic X(28) value "1ORD                        ".
044200     03  filler pic X(28) value "1ORD-MAX                    ".
044300     03  filler pic X(28) value "1ORD-MIN                    ".
044400     03  filler pic X(28) value "0PI                         ".
044500     03  filler pic X(28) value "1PRESENT-VALUE              ".
044600     03  filler pic X(28) value "1RANDOM                     ".
044700     03  filler pic X(28) value "1RANGE                      ".
044800     03  filler pic X(28) value "1REM                        ".
044900     03  filler pic X(28) value "1REVERSE                    ".
045000     03  filler pic X(28) value "1SECONDS-FROM-FORMATTED-TIME".
045100     03  filler pic X(28) value "1SECONDS-PAST-MIDNIGHT      ".
045200     03  filler pic X(28) value "1SIGN                       ".
045300     03  filler pic X(28) value "1SIN                        ".
045400     03  filler pic X(28) value "1SQRT                       ".
045500     03  filler pic X(28) value "0STANDARD-COMPARE           ".
045600     03  filler pic X(28) value "1STANDARD-DEVIATION         ".
045700     03  filler pic X(28) value "1STORED-CHAR-LENGTH         ".
045800     03  filler pic X(28) value "1SUBSTITUTE                 ".
045800     03  filler pic X(28) value "1SUBSTITUTE-CASE            ".
045900     03  filler pic X(28) value "1SUM                        ".
046000     03  filler pic X(28) value "1TAN                        ".
046100     03  filler pic X(28) value "1TEST-DATE-YYYYMMDD         ".
046200     03  filler pic X(28) value "1TEST-DAY-YYYYDDD           ".
046300     03  filler pic X(28) value "0TEST-NUMVAL                ".
046400     03  filler pic X(28) value "0TEST-NUMVAL-C              ".
046500     03  filler pic X(28) value "0TEST-NUMVAL-F              ".
046600     03  filler pic X(28) value "1TRIM                       ".
046700     03  filler pic X(28) value "1UPPER-CASE                 ".
046800     03  filler pic X(28) value "1VARIANCE                   ".
046900     03  filler pic X(28) value "1WHEN-COMPILED              ".
047000     03  filler pic X(28) value "1YEAR-TO-YYYY               ".
047100*>
047200 01  filler redefines Function-Table.
047300     03  All-Functions                 occurs 85
047400               ascending key P-Function indexed by All-Fun-Idx.
047500         05  P-oc-implemented pic x.
047600         05  P-Function       pic x(27).
047700 01  Function-Table-Size   pic s9(5)  comp  value 85.
047800*>
047900*> Note that system names are omitted so thatr they turn up
048000*>  in the cross refs
048100*>
048200*> Here for all reserved words in OC see :
048300*>           struct reserved reserved_words in
048400*>   cobc/reserved.c in the open-cobol source directory
048500*>
048600 01  Additional-Reserved-Words.
048700     03  filler pic x(24) value "1ACCEPT             ".
048800     03  filler pic x(24) value "1ACCESS             ".
048900     03  filler pic x(24) value "0ACTIVE-CLASS       ".
049000     03  filler pic x(24) value "1ADD                ".
049100     03  filler pic x(24) value "1ADDRESS            ".
049200     03  filler pic x(24) value "1ADVANCING          ".
049300     03  filler pic x(24) value "1AFTER              ".
049400     03  filler pic x(24) value "0ALIGNED            ".
049500     03  filler pic x(24) value "1ALL                ".
049600     03  filler pic x(24) value "1ALLOCATE           ".
049700     03  filler pic x(24) value "1ALPHABET           ".
049800     03  filler pic x(24) value "1ALPHABETIC         ".
049900     03  filler pic x(24) value "1ALPHABETIC-LOWER   ".
050000     03  filler pic x(24) value "1ALPHABETIC-UPPER   ".
050100     03  filler pic x(24) value "1ALPHANUMERIC       ".
050200     03  filler pic x(24) value "1ALPHANUMERIC-EDITED".
050300     03  filler pic x(24) value "1ALSO".
050400     03  filler pic x(24) value "1ALTER".
050500     03  filler pic x(24) value "1ALTERNATE".
050600     03  filler pic x(24) value "1AND".
050700     03  filler pic x(24) value "1ANY".
050800     03  filler pic x(24) value "0ANYCASE".
050900     03  filler pic x(24) value "1ARE".
051000     03  filler pic x(24) value "1AREA".
051100     03  filler pic x(24) value "1AREAS".
051200     03  filler pic x(24) value "1ARGUMENT-NUMBER".
051300     03  filler pic x(24) value "1ARGUMENT-VALUE".
051400     03  filler pic x(24) value "0ARITHMETIC".
051500     03  filler pic x(24) value "1AS".
051600     03  filler pic x(24) value "1ASCENDING".
051700     03  filler pic x(24) value "1ASSIGN".
051800     03  filler pic x(24) value "1AT".
051900     03  filler pic x(24) value "0ATTRIBUTE".
052000     03  filler pic x(24) value "1AUTO".
052100     03  filler pic x(24) value "1AUTO-SKIP".
052200     03  filler pic x(24) value "1AUTOMATIC".
052300     03  filler pic x(24) value "1AUTOTERMINATE".
052400     03  filler pic x(24) value "0B-AND".
052500     03  filler pic x(24) value "0B-NOT".
052600     03  filler pic x(24) value "0B-OR".
052700     03  filler pic x(24) value "0B-XOR".
052800     03  filler pic x(24) value "1BACKGROUND-COLOR".
052900     03  filler pic x(24) value "1BASED".
053000     03  filler pic x(24) value "1BELL".
053100     03  filler pic x(24) value "1BEFORE".
053200     03  filler pic x(24) value "1BELL".
053300     03  filler pic x(24) value "1BINARY".
053400     03  filler pic x(24) value "1BINARY-CHAR".
053500     03  filler pic x(24) value "1BINARY-DOUBLE".
053600     03  filler pic x(24) value "1BINARY-LONG".
053700     03  filler pic x(24) value "1BINARY-SHORT".
053800     03  filler pic x(24) value "0BIT".
053900     03  filler pic x(24) value "1BLANK".
054000     03  filler pic x(24) value "1BLINK".
054100     03  filler pic x(24) value "1BLOCK".
054200     03  filler pic x(24) value "0BOOLEAN".
054300     03  filler pic x(24) value "1BOTTOM".
054400     03  filler pic x(24) value "1BY".
054500     03  filler pic x(24) value "0BYTE-LENGTH".
054600     03  filler pic x(24) value "1CALL".
054700     03  filler pic x(24) value "1CANCEL".
054800     03  filler pic x(24) value "0CD".
054900     03  filler pic x(24) value "0CENTER".
055000     03  filler pic x(24) value "0CF".
055100     03  filler pic x(24) value "0CH".
055200     03  filler pic x(24) value "0CHAIN".
055300     03  filler pic x(24) value "1CHAINING".
055400     03  filler pic x(24) value "1CHARACTER".
055500     03  filler pic x(24) value "1CHARACTERS".
055600     03  filler pic x(24) value "1CLASS".
055700     03  filler pic x(24) value "0CLASS-ID".
055800     03  filler pic x(24) value "0CLASSIFICATION".
055900     03  filler pic x(24) value "1CLOSE".
056000     03  filler pic x(24) value "0CODE".
056100     03  filler pic x(24) value "1CODE-SET".
056200     03  filler pic x(24) value "1COL".
056300     03  filler pic x(24) value "1COLLATING".
056400     03  filler pic x(24) value "1COLS".
056500     03  filler pic x(24) value "1COLUMN".
056600     03  filler pic x(24) value "1COLUMNS".
056700     03  filler pic x(24) value "1COMMA".
056800     03  filler pic x(24) value "1COMMAND-LINE".
056900     03  filler pic x(24) value "1COMMIT".
057000     03  filler pic x(24) value "1COMMON".
057100     03  filler pic x(24) value "0COMMUNICATION".
057200     03  filler pic x(24) value "1COMP".
057300     03  filler pic x(24) value "1COMP-1".
057400     03  filler pic x(24) value "1COMP-2".
057500     03  filler pic x(24) value "1COMP-3".
057600     03  filler pic x(24) value "1COMP-4".
057700     03  filler pic x(24) value "1COMP-5".
057800     03  filler pic x(24) value "1COMP-X".
057900     03  filler pic x(24) value "1COMPUTATIONAL".
058000     03  filler pic x(24) value "1COMPUTATIONAL-1".
058100     03  filler pic x(24) value "1COMPUTATIONAL-2".
058200     03  filler pic x(24) value "1COMPUTATIONAL-3".
058300     03  filler pic x(24) value "1COMPUTATIONAL-4".
058400     03  filler pic x(24) value "1COMPUTATIONAL-5".
058500     03  filler pic x(24) value "1COMPUTATIONAL-X".
058600     03  filler pic x(24) value "1COMPUTE".
058700     03  filler pic x(24) value "0CONDITION".
058800     03  filler pic x(24) value "1CONFIGURATION".
058900     03  filler pic x(24) value "1CONSTANT".
059000     03  filler pic x(24) value "1CONTAINS".
059100     03  filler pic x(24) value "1CONTENT".
059200     03  filler pic x(24) value "1CONTINUE".
059300     03  filler pic x(24) value "0CONTROL".
059400     03  filler pic x(24) value "0CONTROLS".
059500     03  filler pic x(24) value "1CONVERTING".
059600     03  filler pic x(24) value "1COPY".
059700     03  filler pic x(24) value "1CORR".
059800     03  filler pic x(24) value "1CORRESPONDING".
059900     03  filler pic x(24) value "1COUNT".
060000     03  filler pic x(24) value "1CRT".
060100     03  filler pic x(24) value "1CURRENCY".
060200     03  filler pic x(24) value "1CURSOR".
060300     03  filler pic x(24) value "1CYCLE".
060400     03  filler pic x(24) value "1DATA".
060500     03  filler pic x(24) value "0DATA-POINTER".
060600     03  filler pic x(24) value "1DATE".
060700     03  filler pic x(24) value "1DAY".
060800     03  filler pic x(24) value "1DAY-OF-WEEK".
060900     03  filler pic x(24) value "0DE".
061000     03  filler pic x(24) value "1DEBUGGING".
061100     03  filler pic x(24) value "1DECIMAL-POINT".
061200     03  filler pic x(24) value "1DECLARATIVES".
061300     03  filler pic x(24) value "1DEFAULT".
061400     03  filler pic x(24) value "1DELETE".
061500     03  filler pic x(24) value "1DELIMITED".
061600     03  filler pic x(24) value "1DELIMITER".
061700     03  filler pic x(24) value "1DEPENDING".
061800     03  filler pic x(24) value "1DESCENDING".
061900     03  filler pic x(24) value "0DESTINATION".
062000     03  filler pic x(24) value "0DETAIL".
062100     03  filler pic x(24) value "0DISABLE".
062200     03  filler pic x(24) value "1DISK".
062300     03  filler pic x(24) value "1DISPLAY".
062400     03  filler pic x(24) value "1DIVIDE".
062500     03  filler pic x(24) value "1DIVISION".
062600     03  filler pic x(24) value "1DOWN".
062700     03  filler pic x(24) value "1DUPLICATES".
062800     03  filler pic x(24) value "1DYNAMIC".
062900     03  filler pic x(24) value "1EBCDIC".
063000     03  filler pic x(24) value "0EC".
063100     03  filler pic x(24) value "0EGI".
063200     03  filler pic x(24) value "1ELSE".
063300     03  filler pic x(24) value "0EMI".
063400     03  filler pic x(24) value "0ENABLE".
063500     03  filler pic x(24) value "1END".
063600     03  filler pic x(24) value "1END-ACCEPT".
063700     03  filler pic x(24) value "1END-ADD".
063800     03  filler pic x(24) value "1END-CALL".
063900     03  filler pic x(24) value "1END-COMPUTE".
064000     03  filler pic x(24) value "1END-DELETE".
064100     03  filler pic x(24) value "1END-DISPLAY".
064200     03  filler pic x(24) value "1END-DIVIDE".
064300     03  filler pic x(24) value "1END-EVALUATE".
064400     03  filler pic x(24) value "1END-IF".
064500     03  filler pic x(24) value "1END-MULTIPLY".
064600     03  filler pic x(24) value "1END-OF-PAGE".
064700     03  filler pic x(24) value "1END-PERFORM".
064800     03  filler pic x(24) value "1END-READ".
064900     03  filler pic x(24) value "0END-RECEIVE".
065000     03  filler pic x(24) value "1END-RETURN".
065100     03  filler pic x(24) value "1END-REWRITE".
065200     03  filler pic x(24) value "1END-SEARCH".
065300     03  filler pic x(24) value "1END-START".
065400     03  filler pic x(24) value "1END-STRING".
065500     03  filler pic x(24) value "1END-SUBTRACT".
065600     03  filler pic x(24) value "1END-UNSTRING".
065700     03  filler pic x(24) value "1END-WRITE".
065800     03  filler pic x(24) value "1ENTRY".
065900     03  filler pic x(24) value "0ENTRY-CONVENTION".
066000     03  filler pic x(24) value "1ENVIRONMENT".
066100     03  filler pic x(24) value "1ENVIRONMENT-NAME".
066200     03  filler pic x(24) value "1ENVIRONMENT-VALUE".
066300     03  filler pic x(24) value "0EO".
066400     03  filler pic x(24) value "1EOL".
066500     03  filler pic x(24) value "1EOP".
066600     03  filler pic x(24) value "1EOS".
066700     03  filler pic x(24) value "1EQUAL".
066800     03  filler pic x(24) value "1EQUALS".
066900     03  filler pic x(24) value "1ERASE".
067000     03  filler pic x(24) value "1ERROR".
067100     03  filler pic x(24) value "1ESCAPE".
067200     03  filler pic x(24) value "0ESI".
067300     03  filler pic x(24) value "1EVALUATE".
067400     03  filler pic x(24) value "1EXCEPTION".
067500     03  filler pic x(24) value "0EXCEPTION-OBJECT".
067600     03  filler pic x(24) value "1EXCLUSIVE".
067700     03  filler pic x(24) value "1EXIT".
067800     03  filler pic x(24) value "0EXPANDS".
067900     03  filler pic x(24) value "1EXTEND".
068000     03  filler pic x(24) value "1EXTERNAL".
068100     03  filler pic x(24) value "0FACTORY".
068200     03  filler pic x(24) value "1FALSE".
068300     03  filler pic x(24) value "1FD".
068400     03  filler pic x(24) value "1FILE".
068500     03  filler pic x(24) value "1FILE-CONTROL".
068600     03  filler pic x(24) value "1FILE-ID".
068700     03  filler pic x(24) value "1FILLER".
068800     03  filler pic x(24) value "0FINAL".
068900     03  filler pic x(24) value "1FIRST".
069000     03  filler pic x(24) value "0FLOAT-BINARY-16".
069100     03  filler pic x(24) value "0FLOAT-BINARY-34".
069200     03  filler pic x(24) value "0FLOAT-BINARY-7".
069300     03  filler pic x(24) value "0FLOAT-DECIMAL-16".
069400     03  filler pic x(24) value "0FLOAT-DECIMAL-34".
069500     03  filler pic x(24) value "0FLOAT-EXTENDED".
069600     03  filler pic x(24) value "1FLOAT-LONG".
069700     03  filler pic x(24) value "1FLOAT-SHORT".
069800     03  filler pic x(24) value "1FOOTING".
069900     03  filler pic x(24) value "1FOR".
070000     03  filler pic x(24) value "1FOREGROUND-COLOR".
070100     03  filler pic x(24) value "1FOREVER".
070200     03  filler pic x(24) value "0FORMAT".
070300     03  filler pic x(24) value "1FREE".
070400     03  filler pic x(24) value "1FROM".
070500     03  filler pic x(24) value "1FULL".
070600     03  filler pic x(24) value "1FUNCTION".
070700     03  filler pic x(24) value "0FUNCTION-ID".
070800     03  filler pic x(24) value "0FUNCTION-POINTER".
070900     03  filler pic x(24) value "0GENERATE".
071000     03  filler pic x(24) value "0GET".
071100     03  filler pic x(24) value "1GIVING".
071200     03  filler pic x(24) value "1GLOBAL".
071300     03  filler pic x(24) value "1GO".
071400     03  filler pic x(24) value "1GOBACK".
071500     03  filler pic x(24) value "1GREATER".
071600     03  filler pic x(24) value "0GROUP".
071700     03  filler pic x(24) value "0GROUP-USAGE".
071800     03  filler pic x(24) value "0HEADING".
071900     03  filler pic x(24) value "1HIGH-VALUE".
072000     03  filler pic x(24) value "1HIGH-VALUES".
072100     03  filler pic x(24) value "1HIGHLIGHT".
072200     03  filler pic x(24) value "1I-O".
072300     03  filler pic x(24) value "1I-O-CONTROL".
072400     03  filler pic x(24) value "1ID".
072500     03  filler pic x(24) value "1IDENTIFICATION".
072600     03  filler pic x(24) value "1IF".
072700     03  filler pic x(24) value "1IGNORE".
072800     03  filler pic x(24) value "1IGNORING".
072900     03  filler pic x(24) value "0IMPLEMENTS".
073000     03  filler pic x(24) value "1IN".
073100     03  filler pic x(24) value "1INDEX".
073200     03  filler pic x(24) value "1INDEXED".
073300     03  filler pic x(24) value "0INDICATE".
073400     03  filler pic x(24) value "0INFINITY".
073500     03  filler pic x(24) value "0INHERITS".
073600     03  filler pic x(24) value "1INITIAL".
073700     03  filler pic x(24) value "1INITIALIZE".
073800     03  filler pic x(24) value "1INITIALIZED".
073900     03  filler pic x(24) value "0INITIATE".
074000     03  filler pic x(24) value "1INPUT".
074100     03  filler pic x(24) value "1INPUT-OUTPUT".
074200     03  filler pic x(24) value "1INSPECT".
074300     03  filler pic x(24) value "0INTERFACE".
074400     03  filler pic x(24) value "0INTERFACE-ID".
074500     03  filler pic x(24) value "1INTO".
074600     03  filler pic x(24) value "0INTRINSIC".
074700     03  filler pic x(24) value "1INVALID".
074800     03  filler pic x(24) value "0INVOKE".
074900     03  filler pic x(24) value "1IS".
075000     03  filler pic x(24) value "1JUST".
075100     03  filler pic x(24) value "1JUSTIFIED".
075200     03  filler pic x(24) value "1KEY".
075300     03  filler pic x(24) value "1LABEL".
075400     03  filler pic x(24) value "0LAST".
075500     03  filler pic x(24) value "0LC_ALL".
075600     03  filler pic x(24) value "0LC_COLLATE".
075700     03  filler pic x(24) value "0LC_CTYPE".
075800     03  filler pic x(24) value "0LC_MESSAGES".
075900     03  filler pic x(24) value "0LC_MONETARY".
076000     03  filler pic x(24) value "0LC_NUMERIC".
076100     03  filler pic x(24) value "0LC_TIME".
076200     03  filler pic x(24) value "1LEADING".
076300     03  filler pic x(24) value "1LEFT".
076400     03  filler pic x(24) value "1LENGTH".
076500     03  filler pic x(24) value "1LESS".
076600     03  filler pic x(24) value "0LIMIT".
076700     03  filler pic x(24) value "0LIMITS".
076800     03  filler pic x(24) value "1LINAGE".
076900     03  filler pic x(24) value "1LINAGE-COUNTER".
077000     03  filler pic x(24) value "1LINE".
077100     03  filler pic x(24) value "0LINE-COUNTER".
077200     03  filler pic x(24) value "1LINES".
077300     03  filler pic x(24) value "1LINKAGE".
077400     03  filler pic x(24) value "1LOCAL-STORAGE".
077500     03  filler pic x(24) value "1LOCALE".
077600     03  filler pic x(24) value "1LOCK".
077700     03  filler pic x(24) value "1LOW-VALUE".
077800     03  filler pic x(24) value "1LOW-VALUES".
077900     03  filler pic x(24) value "1LOWLIGHT".
078000     03  filler pic x(24) value "1MANUAL".
078100     03  filler pic x(24) value "1MEMORY".
078200     03  filler pic x(24) value "1MERGE".
078300     03  filler pic x(24) value "0MESSAGE".
078400     03  filler pic x(24) value "0METHOD".
078500     03  filler pic x(24) value "0METHOD-ID".
078600     03  filler pic x(24) value "1MINUS".
078700     03  filler pic x(24) value "1MODE".
078800     03  filler pic x(24) value "1MOVE".
078900     03  filler pic x(24) value "1MULTIPLE".
079000     03  filler pic x(24) value "1MULTIPLY".
079100     03  filler pic x(24) value "1NATIONAL".
079200     03  filler pic x(24) value "1NATIONAL-EDITED".
079300     03  filler pic x(24) value "1NATIVE".
079400     03  filler pic x(24) value "1NEGATIVE".
079500     03  filler pic x(24) value "0NESTED".
079600     03  filler pic x(24) value "1NEXT".
079700     03  filler pic x(24) value "1NO".
079800     03  filler pic x(24) value "0NONE".
079900     03  filler pic x(24) value "0NORMAL".
080000     03  filler pic x(24) value "1NOT".
080100     03  filler pic x(24) value "1NULL".
080200     03  filler pic x(24) value "1NULLS".
080300     03  filler pic x(24) value "1NUMBER".
080400     03  filler pic x(24) value "1NUMBERS".
080500     03  filler pic x(24) value "1NUMERIC".
080600     03  filler pic x(24) value "1NUMERIC-EDITED".
080700     03  filler pic x(24) value "0OBJECT".
080800     03  filler pic x(24) value "1OBJECT-COMPUTER".
080900     03  filler pic x(24) value "0OBJECT-REFERENCE".
081000     03  filler pic x(24) value "1OCCURS".
081100     03  filler pic x(24) value "1OF".
081200     03  filler pic x(24) value "1OFF".
081300     03  filler pic x(24) value "1OMITTED".
081400     03  filler pic x(24) value "1ON".
081500     03  filler pic x(24) value "1ONLY".
081600     03  filler pic x(24) value "1OPEN".
081700     03  filler pic x(24) value "1OPTIONAL".
081800     03  filler pic x(24) value "0OPTIONS".
081900     03  filler pic x(24) value "1OR".
082000     03  filler pic x(24) value "1ORDER".
082100     03  filler pic x(24) value "1ORGANIZATION".
082200     03  filler pic x(24) value "1OTHER".
082300     03  filler pic x(24) value "1OUTPUT".
082400     03  filler pic x(24) value "1OVERFLOW".
082500     03  filler pic x(24) value "1OVERLINE".
082600     03  filler pic x(24) value "0OVERRIDE".
082700     03  filler pic x(24) value "1PACKED-DECIMAL".
082800     03  filler pic x(24) value "1PADDING".
082900     03  filler pic x(24) value "1PAGE".
083000     03  filler pic x(24) value "0PAGE-COUNTER".
083100     03  filler pic x(24) value "1PARAGRAPH".
083200     03  filler pic x(24) value "1PERFORM".
083300     03  filler pic x(24) value "0PF".
083400     03  filler pic x(24) value "0PH".
083500     03  filler pic x(24) value "1PIC".
083600     03  filler pic x(24) value "1PICTURE".
083700     03  filler pic x(24) value "1PLUS".
083800     03  filler pic x(24) value "1POINTER".
083900     03  filler pic x(24) value "1POSITION".
084000     03  filler pic x(24) value "1POSITIVE".
084100     03  filler pic x(24) value "0PRESENT".
084200     03  filler pic x(24) value "1PREVIOUS".
084300     03  filler pic x(24) value "1PRINTER".
084400     03  filler pic x(24) value "0PRINTING".
084500     03  filler pic x(24) value "1PROCEDURE".
084600     03  filler pic x(24) value "1PROCEDURE-POINTER".
084700     03  filler pic x(24) value "1PROCEDURES".
084800     03  filler pic x(24) value "1PROCEED".
084900     03  filler pic x(24) value "1PROGRAM".
085000     03  filler pic x(24) value "1PROGRAM-ID".
085100     03  filler pic x(24) value "1PROGRAM-POINTER".
085200     03  filler pic x(24) value "1PROMPT".
085300     03  filler pic x(24) value "0PROPERTY".
085400     03  filler pic x(24) value "0PROTOTYPE".
085500     03  filler pic x(24) value "0PURGE".
085600     03  filler pic x(24) value "0QUEUE".
085700     03  filler pic x(24) value "1QUOTE".
085800     03  filler pic x(24) value "1QUOTES".
085900     03  filler pic x(24) value "0RAISE".
086000     03  filler pic x(24) value "0RAISING".
086100     03  filler pic x(24) value "1RANDOM".
086200     03  filler pic x(24) value "0RD".
086300     03  filler pic x(24) value "1READ".
086400     03  filler pic x(24) value "0RECEIVE".
086500     03  filler pic x(24) value "1RECORD".
086600     03  filler pic x(24) value "1RECORDING".
086700     03  filler pic x(24) value "1RECORDS".
086800     03  filler pic x(24) value "1RECURSIVE".
086900     03  filler pic x(24) value "1REDEFINES".
087000     03  filler pic x(24) value "1REEL".
087100     03  filler pic x(24) value "1REFERENCE".
087200     03  filler pic x(24) value "0RELATION".
087300     03  filler pic x(24) value "1RELATIVE".
087400     03  filler pic x(24) value "1RELEASE".
087500     03  filler pic x(24) value "1REMAINDER".
087600     03  filler pic x(24) value "1REMOVAL".
087700     03  filler pic x(24) value "1RENAMES".
087800     03  filler pic x(24) value "0REPLACE".
087900     03  filler pic x(24) value "1REPLACING".
088000     03  filler pic x(24) value "0REPORT".
088100     03  filler pic x(24) value "0REPORTING".
088200     03  filler pic x(24) value "0REPORTS".
088300     03  filler pic x(24) value "1REPOSITORY".
088400     03  filler pic x(24) value "0REPRESENTS-NOT-A-NUMBER".
088500     03  filler pic x(24) value "1REQUIRED".
088600     03  filler pic x(24) value "1RESERVE".
088700     03  filler pic x(24) value "0RESET".
088800     03  filler pic x(24) value "0RESUME".
088900     03  filler pic x(24) value "0RETRY".
089000     03  filler pic x(24) value "1RETURN".
089100     03  filler pic x(24) value "1RETURNING".
089200     03  filler pic x(24) value "1REVERSE-VIDEO".
089300     03  filler pic x(24) value "1REWIND".
089400     03  filler pic x(24) value "1REWRITE".
089500     03  filler pic x(24) value "0RF".
089600     03  filler pic x(24) value "0RH".
089700     03  filler pic x(24) value "1RIGHT".
089800     03  filler pic x(24) value "1ROLLBACK".
089900     03  filler pic x(24) value "1ROUNDED".
090000     03  filler pic x(24) value "1RUN".
090100     03  filler pic x(24) value "1SAME".
090200     03  filler pic x(24) value "1SCREEN".
090300     03  filler pic x(24) value "1SD".
090400     03  filler pic x(24) value "1SEARCH".
090500     03  filler pic x(24) value "0SECONDS".
090600     03  filler pic x(24) value "1SECTION".
090700     03  filler pic x(24) value "1SECURE".
090800     03  filler pic x(24) value "0SEGMENT".
090900     03  filler pic x(24) value "1SEGMENT-LIMIT".
091000     03  filler pic x(24) value "1SELECT".
091100     03  filler pic x(24) value "0SELF".
091200     03  filler pic x(24) value "0SEND".
091300     03  filler pic x(24) value "1SENTENCE".
091400     03  filler pic x(24) value "1SEPARATE".
091500     03  filler pic x(24) value "1SEQUENCE".
091600     03  filler pic x(24) value "1SEQUENTIAL".
091700     03  filler pic x(24) value "1SET".
091800     03  filler pic x(24) value "1SHARING".
091900     03  filler pic x(24) value "1SIGN".
092000     03  filler pic x(24) value "1SIGNED".
092100     03  filler pic x(24) value "1SIGNED-INT".
092200     03  filler pic x(24) value "1SIGNED-LONG".
092300     03  filler pic x(24) value "1SIGNED-SHORT".
092400     03  filler pic x(24) value "1SIZE".
092500     03  filler pic x(24) value "1SORT".
092600     03  filler pic x(24) value "1SORT-MERGE".
092700     03  filler pic x(24) value "1SOURCE".
092800     03  filler pic x(24) value "1SOURCE-COMPUTER".
092900     03  filler pic x(24) value "0SOURCES".
093000     03  filler pic x(24) value "1SPACE".
093100     03  filler pic x(24) value "1SPACES".
093200     03  filler pic x(24) value "1SPECIAL-NAMES".
093300     03  filler pic x(24) value "1STANDARD".
093400     03  filler pic x(24) value "1STANDARD-1".
093500     03  filler pic x(24) value "1STANDARD-2".
093600     03  filler pic x(24) value "1START".
093700     03  filler pic x(24) value "0STATEMENT".
093800     03  filler pic x(24) value "1STATUS".
093900     03  filler pic x(24) value "0STEP".
094000     03  filler pic x(24) value "1STOP".
094100     03  filler pic x(24) value "1STRING".
094200     03  filler pic x(24) value "0STRONG".
094300     03  filler pic x(24) value "0SUB-QUEUE-1".
094400     03  filler pic x(24) value "0SUB-QUEUE-2".
094500     03  filler pic x(24) value "0SUB-QUEUE-3".
094600     03  filler pic x(24) value "1SUBTRACT".
094700     03  filler pic x(24) value "0SUM".
094800     03  filler pic x(24) value "0SUPER".
094900     03  filler pic x(24) value "0SUPPRESS".
095000     03  filler pic x(24) value "0SYMBOL".
095100     03  filler pic x(24) value "1SYMBOLIC".
095200     03  filler pic x(24) value "1SYNC".
095300     03  filler pic x(24) value "1SYNCHRONIZED".
095400     03  filler pic x(24) value "0SYSTEM-DEFAULT".
095500     03  filler pic x(24) value "0TABLE".
095600     03  filler pic x(24) value "1TALLYING".
095700     03  filler pic x(24) value "1TAPE".
095800     03  filler pic x(24) value "0TERMINAL".
095900     03  filler pic x(24) value "0TERMINATE".
096000     03  filler pic x(24) value "1TEST".
096100     03  filler pic x(24) value "0TEXT".
096200     03  filler pic x(24) value "1THAN".
096300     03  filler pic x(24) value "1THEN".
096400     03  filler pic x(24) value "1THROUGH".
096500     03  filler pic x(24) value "1THRU".
096600     03  filler pic x(24) value "1TIME".
096700     03  filler pic x(24) value "1TIMES".
096800     03  filler pic x(24) value "1TO".
096900     03  filler pic x(24) value "1TOP".
097000     03  filler pic x(24) value "1TRAILING".
097100     03  filler pic x(24) value "1TRANSFORM".
097200     03  filler pic x(24) value "1TRUE".
097300     03  filler pic x(24) value "0TYPE".
097400     03  filler pic x(24) value "0TYPEDEF".
097500     03  filler pic x(24) value "0UCS-4".
097600     03  filler pic x(24) value "1UNDERLINE".
097700     03  filler pic x(24) value "1UNIT".
097800     03  filler pic x(24) value "0UNIVERSAL".
097900     03  filler pic x(24) value "1UNLOCK".
098000     03  filler pic x(24) value "1UNSIGNED".
098100     03  filler pic x(24) value "1UNSIGNED-INT".
098200     03  filler pic x(24) value "1UNSIGNED-LONG".
098300     03  filler pic x(24) value "1UNSIGNED-SHORT".
098400     03  filler pic x(24) value "1UNSTRING".
098500     03  filler pic x(24) value "1UNTIL".
098600     03  filler pic x(24) value "1UP".
098700     03  filler pic x(24) value "1UPDATE".
098800     03  filler pic x(24) value "1UPON".
098900     03  filler pic x(24) value "1USAGE".
099000     03  filler pic x(24) value "1USE".
099100     03  filler pic x(24) value "0USER-DEFAULT".
099200     03  filler pic x(24) value "1USING".
099300     03  filler pic x(24) value "0UTF-16".
099400     03  filler pic x(24) value "0UTF-8".
099500     03  filler pic x(24) value "0VAL-STATUS".
099600     03  filler pic x(24) value "0VALID".
099700     03  filler pic x(24) value "0VALIDATE".
099800     03  filler pic x(24) value "0VALIDATE-STATUS".
099900     03  filler pic x(24) value "1VALUE".
100000     03  filler pic x(24) value "1VALUES".
100100     03  filler pic x(24) value "1VARYING".
100200     03  filler pic x(24) value "1WAIT".
100300     03  filler pic x(24) value "1WHEN".
100400     03  filler pic x(24) value "1WITH".
100500     03  filler pic x(24) value "1WORDS".
100600     03  filler pic x(24) value "1WORKING-STORAGE".
100700     03  filler pic x(24) value "1WRITE".
100800     03  filler pic x(24) value "1YYYYDDD".
100900     03  filler pic x(24) value "1YYYYMMDD".
101000     03  filler pic x(24) value "1ZERO".
101100     03  filler pic x(24) value "1ZEROES".
101200     03  filler pic x(24) value "1ZEROS".
101300*>
101400 01  filler redefines Additional-Reserved-Words.
101500     03  Reserved-Names                occurs 526
101600             ascending key Resvd-Word indexed by Resvd-Idx.
101700       05  Resvd-Implemented pic x.
101800       05  Resvd-Word        pic x(23).
101900 01  Resvd-Table-Size        pic s9(5)   comp    value 526.
102000*>
102100 01  Condition-Table                           value high-values.
102200     03  Con-Tab-Blocks occurs 10 to 5001
102300                                       depending on Con-Tab-Size.
102400*> +1 used, when testing for max table size
102500       05  Conditions      pic x(32).
102600       05  Variables       pic x(32).
102610       05  CT-In-Use-Flag  pic x.
102620       05  filler          pic x.
102700 01  Con-Tab-Size          Binary-Long value 10.
102800 01  Con-Tab-Count         Binary-Long value zero.
102900*>
103000 01  Global-Item-Table                         value high-values.
103100     03  Git-Elements  occurs 10 to 10001
103200                                     depending on Git-Table-Size.
103300*> +1 used, when testing for max table size
103400       05  Git-Word        pic x(32).
103500       05  Git-Prog-Name   pic x(32).
103600       05  Git-RefNo       pic 9(6).
103700       05  Git-HoldWSorPD  pic 9.
103800       05  Git-HoldWSorPD2 pic 9.
103900       05  Git-Build-No    pic 99.
103910       05  Git-In-Use-Flag pic x.
103920       05  filler          pic x.
104000 01  Git-Table-Size        Binary-Long value 10.
104100 01  Git-Table-Count       Binary-Long value zero.
104200*>
104300 procedure division.
104400 aa000-xref-Data    section.
104500*>**************************
104600*>  TODO & BUGS:
104700*>************************************************************************
104800*> AAnnn Section:
104900*>  THIS ENTIRE SECTION NEEDS A REWRITE, TOO MUCH TAKEN FROM THE VERY OLD
105000*>   CODE BASE. DOES READ-A-WORD CATER FOR MULTIPLE STATEMENTS PER LINE
105100*>    WITH PERIODS ENDING EACH STATEMENT? IF SO, WHY ARE WE CHECKING FOR
105200*>     WORD-DELIMIT = "." THEN.
105300*>  THIS ALL NEEDS A GOOD LOOK AT, SO MUST DONE SOON but with fresh eyes
105400*> SUGGEST COMMON CODE LEFT HERE WITH NEW SECTIONS DEALING WITH EACH
105500*>  SECTION OR MAIN ENTRY
105600*>^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
106000*>
106100*>  Quesions, Questions, Questions,  all I have, is questions!
106200*>************************************************************************
106300*>
106400*>
106600     perform  zz190-Init-Program thru zz190-Exit.
106700     move     high-values to Global-Item-Table.
106800*>
106900*> Just in case someone's added names in source code out of sort order
107000*>  We MUST have all tables in sorted order
107100*>
107200     sort     Reserved-Names ascending Resvd-Word.
107300     sort     All-Functions ascending P-Function.
107500     perform  zz180-Open-Source-File thru zz180-Exit.
107600*>
107700*> Dump All reserved words from tables then stop
107800*>
107900     if       Dump-Reserved-Words
108000              perform varying a from 1 by 1
108100                  until a > Resvd-Table-Size
108200                    display Resvd-Word (a)
                          end-display
108300              end-perform
108400              perform varying a from 1 by 1
108500                  until a > Function-Table-Size
108600                    display P-Function (a)
                          end-display
108700              end-perform
139810              move zero to return-code
139900              goback
           end-if
108900*>
109000     open     output Source-Listing.
109100     if       Reports-In-Lower
109200              move function lower-case (Prog-BaseName (1:CWS))
                                          to HoldID
109300     else
109400              move function upper-case (Prog-BaseName (1:CWS))
                                          to HoldID
109500     end-if
109600     move     HoldID to HoldID-Module.
109700     move     spaces to Arg-Vals.
109800*>
109900*> get program id frm source filename in case prog-id not present
110000*>
110100 aa020-Bypass-Open.
110200     open     output Supplemental-Part1-Out.
110300*>
110400*> Now add in contents of Global table if processing nested modules
      *>   and we have processed first one by loading sort file
110700*>
110800     if       Git-Table-Count not = zero
110900              move zeros to SortRecord
111000              perform varying a from 1 by 1
111100                       until a > Git-Table-Count
111200                   move Git-HoldWSorPD  (a) to SkaWSorPD
111300                   move Git-HoldWSorPD2 (a) to SkaWSorPD2
111400                   if Reports-In-Lower
111500                      move function lower-case (Git-Word (a))
111600                                            to SkaDataName
111700                   else
111800                      move Git-Word (a) to SkaDataName
111900                   end-if
112000                   move Git-RefNo (a) to SkaRefNo
112100                   move 1 to USect (Git-HoldWSorPD (a))
112200                   write SortRecord
112300              end-perform
112400     end-if
112500*>
112600*> HoldID gets updated with program-id name when found later
112700*>   but we can print 1st report headings using the sourcefile name
112800*>    we are assuming the user knows what s/he is doing......:)
112900*>
113000     move     Prog-Name to H1Prog-Name.
113100     if       List-Source
113200              perform  zz150-WriteHdb.
113300*>
113400     perform  zz100-Get-A-Source-Record thru zz100-Exit.
113500     move     1 to q S-Pointer F-Pointer.
113600*>
113700 aa030-ReadLoop1.
113800     if       Source-Eof
113900           or End-Prog
114000              display Msg2
114100              close Supplemental-Part1-Out Source-Listing
114200              close SourceInput
139810              move 16 to return-code
114300              goback.
114400     perform  zz110-Get-A-Word thru zz110-Exit.
114500     IF       SourceInWS = "DATA DIVISION.  "
114600                       or  "FILE SECTION.   "
114700                       or  "WORKING-STORAGE SECTION."
114800                       or  "PROCEDURE DIVISION."
114900              go to aa060-ReadLoop3a.
115000*>
115100*> The above should never happen, as all modules have a program-id
115200*>   but who knows what new standards will allow
      *>
115300     if       wsFoundWord2 not = "PROGRAM-ID"
115400              go to aa030-ReadLoop1.
115500     perform  zz110-Get-A-Word thru zz110-Exit.
115600*>
115700*> got program name so if 1st prog id -> hold-id
115800*>               else -> holdid-module (for reports)
115900*>
116000     if       not Have-Nested
116100        if       Reports-In-Lower
116200                 move function lower-case (wsFoundWord2)
116300                                      to HoldID
116400        else
116500                 move function upper-case (wsFoundWord2)
116600                                      to HoldID.
116700     if       Have-Nested  *> found more than 1 module in source
116800        if       Reports-In-Lower
116900                 move function lower-case (wsFoundWord2)
117000                                      to HoldID-Module
117100        else
117200                 move function upper-case (wsFoundWord2)
117300                                      to HoldID-Module.
117400*>
117500*> We now have the program-id name so update our info, for reports
117600*>
117700 aa040-ReadLoop2.
117800     perform  zz100-Get-A-Source-Record thru zz100-Exit.
117900     if       SourceInWS (1:14) = "SPECIAL-NAMES."
118000              go to aa041-Get-SN.
118100     move     zero to a.
118200     perform  aa045-Test-Section thru aa045-Exit.
118300*>
118400*> if < 9 we've got Data Div onwards
118500*>
118600     if       a < 9
118700              go to aa060-ReadLoop3a.
118900     go       to aa040-ReadLoop2.
119000*>
119100 aa041-Get-SN.
119200*>
119300*> Get special names
119400*>
119500     perform  zz100-Get-A-Source-Record thru zz100-Exit.
119600     move     zero to a.
119700     perform  aa045-Test-Section thru aa045-Exit.
119800     if       a < 9
119900              go to aa060-ReadLoop3a.
120000     if       SourceInWS (1:13) = "INPUT-OUTPUT "
120100                             or = "DATA DIVISION"
120200              go to aa041-Get-SN.
120300     IF       SourceInWS (1:13) = "FILE-CONTROL."
120400              go to aa047-GetIO.
120500     IF       SourceInWS (1:12) = "I-O-CONTROL."
120600              go to aa048-GetIOC.
120700*>
120800 aa042-Getword.
120900     perform  zz110-Get-A-Word thru zz110-Exit.
121000     if       Word-Delimit = "."
121100              go to aa041-Get-SN.
121200     if       wsFoundWord2 (1:3) not = "IS "
121300              go to aa042-Getword.
121400*>
121500     perform  zz110-Get-A-Word thru zz110-Exit.
121600     move     wsFoundWord2 (1:CWS) to Saved-Variable.
121700*>
121800 aa044-Getword3.
121900     perform  zz110-Get-A-Word thru zz110-Exit.
122000     if       Word-Delimit = "."
122100              go to aa041-Get-SN.
122200     if       wsFoundWord2 (1:2) not = "ON"
122300          and wsFoundWord2 (1:3) not = "OFF"
122400              go to aa044-Getword3.
122500     perform  zz110-Get-A-Word thru zz110-Exit.
122600*>
122700     if       Con-Tab-Size not < Con-Tab-Count
122800              add 10 to Con-Tab-Size.
122900     add      1 to Con-Tab-Count.
123000     move     Saved-Variable to Variables (Con-Tab-Count).
123000     move     Space  to CT-In-Use-Flag (Con-Tab-Count).
123100     move     wsFoundWord2 (1:CWS) to Conditions (Con-Tab-Count).
123200     if       Word-Delimit = "."
123300              go to aa041-Get-SN.
123400     go       to aa044-Getword3.
123500*>
123600 aa045-Test-Section.
123700     add      1 to a.
123800     if       a > 8
123900              go to aa045-Exit.
124000     if       SourceInWS (1:24) not = Full-Section-Name (a)
124100              go to aa045-Test-Section.
124200*>
124300 aa045-Exit.
124400     exit.
124500*>
125800 aa047-GetIO.
125900*>
126000*> now got file control
126100*>
126200     perform  zz100-Get-A-Source-Record thru zz100-Exit.
126300     move     zero to a.
126400     perform  aa045-Test-Section thru aa045-Exit.
126500     if       a < 9
126600              go to aa060-ReadLoop3a.
126700     IF       SourceInWS (1:12) = "I-O-CONTROL."
126800              go to aa048-GetIOC.
126900     if       SourceInWS (1:12) = "DATA DIVISIO"
127000              go to aa050-ReadLoop3.
127100     if       SourceInWS (1:12) = "FILE SECTION"
127200              go to aa060-ReadLoop3a.
127300*>
127400 aa047-Getword.
127500     perform  zz110-Get-A-Word thru zz110-Exit.
127600     if       Word-Delimit = "."
127700              go to aa047-GetIO.
127800*>
127900*> now looking at selects: so looking for non reserved words
128000*>
128100     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
128200     if       a not = zero
128300              go to aa047-Getword.
128400     if       Word-Delimit = "."
128500              go to aa047-GetIO.
128600*> Now have filename
128700     move     1 to HoldWSorPD.
128800     move     0 to HoldWSorPD2.
128900     perform  zz030-Write-Sort.
129000*>
129100 aa047-Getword2.
129200     perform  zz110-Get-A-Word thru zz110-Exit.
129300     if       Source-Eof
129400              display Msg16
114100              close Supplemental-Part1-Out Source-Listing
114200              close SourceInput
139810              move 16 to return-code
139900              goback.
129600*>
129700*> Above condition is a Logic error: Should nolonger happen.
129900*>
130000*> should have assign
130100*>
130200     if       wsFoundWord2 (1:7) not = "ASSIGN "
130300              go to aa047-Getword2.
130400*>
130500 aa047-Getword3.
130600     perform  zz110-Get-A-Word thru zz110-Exit.
130700     if       (wsf1-1 = quote or = "'") AND Word-Delimit = "."
130800              go to aa047-GetIO.
130900     if       wsf1-1 = quote or = "'"
131000              go to aa047-Getword3.
131100     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
131200     if       a not = zero and Word-Delimit = "."
131300              go to aa047-GetIO.
131400     if       a not = zero
131500              go to aa047-Getword3.
131800     if       word-length = zero
131900              go to aa047-GetIO.
132000*>
132100*> Now have filename
132200*> filenames / datanames declared in Selects are shown as in data division
132300*>
132400     move     1 to HoldWSorPD.
132500     move     0 to HoldWSorPD2.
132600     perform  zz030-Write-Sort.
132700     if       Word-Delimit = "."
132800              go to aa047-GetIO.
132900     go       to aa047-Getword3.
133000*>
133100 aa048-GetIOC.
133200     perform  zz110-Get-A-Word thru zz110-Exit.
133300     if       wsf1-1 = quote or = "'"
133400              go to aa048-GetIOC.
133500     if       Word-Delimit = "."
133600              perform zz100-Get-A-Source-Record thru zz100-Exit
133700              move    zero to a
133800              perform aa045-Test-Section thru aa045-Exit
133900              if      a < 9
134000                      go to aa060-ReadLoop3a.
134100     if       wsFoundWord2 (1:5) not = "SAME "
134200              go to aa048-GetIOC.
134300*>
134400 aa049-Getword.
134500     perform  zz110-Get-A-Word thru zz110-Exit.
134600     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
134700     if       a not = zero
134800              go to aa049-Getword.
134900*> Now have filename
135000     move     1 to HoldWSorPD.
135100     move     0 to HoldWSorPD2.
135200     perform  zz030-Write-Sort.
135300     if       Word-Delimit = "."
135400              go to aa047-GetIO.
135500     go       to aa049-Getword.
135600*>
135700 aa050-ReadLoop3.
135800*>
135900*>    Now for the data division or beyond
136000*>
136100     perform  zz100-Get-A-Source-Record thru zz100-Exit.
136300*>
136400 aa060-ReadLoop3a.   *> a < 9  ??
136500     perform  zz170-Check-4-Section thru zz170-Exit.
136600     if       GotASection = "Y"
136700              go to aa050-ReadLoop3.
136800     if       HoldWSorPD > zero and < 8
136900              move 1 to S-Pointer2
137000              perform ba000-Process-WS.
137100*>
137200     if       HoldWSorPD = zero
137300              go to aa050-ReadLoop3.
137400*>
137500     perform  bb000-Process-Procedure.
137600     if       End-Prog
137700              close Supplemental-Part1-Out
137800     else
137900              close SourceInput Supplemental-Part1-Out.
138000     perform  bc000-Last-Act.
138100     if       not End-Prog
                    perform  bc620-Do-Global-Conditions thru bc629-Exit
138200              close Source-Listing.
138300*>
138400     if       not We-Are-Testing
138500          and not End-Prog
138600*>            call "CBL_DELETE_FILE" using SourceFileName
138700*> kill temp input file (anything else?) but not yet Use when in OC
138800              call "CBL_DELETE_FILE" using Supp-File-2
138900              call "CBL_DELETE_FILE" using Supp-File-1.
139000*>
139100     if       End-Prog
139200              perform  zz190-Init-Program thru zz190-Exit
139300              move  spaces to PrintLine
139400              write PrintLine
139500              write PrintLine
139600              write PrintLine
139700              move  zero to sw-End-Prog
139800              go    to aa020-Bypass-Open
           end-if
139810     move     zero to return-code.
139900     goback.
140300*>
140400 ba000-Process-WS Section.
140500 ba020-GetAWord.
140600*>
140700*> this should be getting first word of source record
140800*>
140900     perform  zz110-Get-A-Word thru zz110-Exit.
141000     if       GotASection = "Y" *> check for Proc. Div
141100         and  HoldWSorPD = 8
141200              go to ba000-Exit. *> done, so process proc. div
141300     if       GotASection = "Y"
141400              move space to GotASection
141500              perform zz100-Get-A-Source-Record thru zz100-Exit
141600              go to ba020-GetAWord.
141700*>
141800*> lets get a file section element out of the way
141900*>
142000     if       wsFoundWord2 (1:3) = "FD " or = "RD "
142100              move zero to Global-Current-Level  *> Global only
142200     else
142300      if      wsFoundWord2 (1:3) = "CD " or = "SD " *> not these
142400              move high-values to Global-Current-Level.
142500*> Clears Global-Active
142600*>
142700*> note that for CD & SD setting Global-current-* not needed
142800*>                           is it a problem
142900     if       wsFoundWord2 (1:3) = "FD " or = "SD "
143000                                or = "RD " or = "CD "
143100              perform zz110-Get-A-Word thru zz110-Exit  *> get fn
143200              move zero to HoldWSorPD2
143300              move zero to sw-Git            *> reset Global flag
143400              move wsFoundWord2 (1:32) to Global-Current-Word
143500              move Gen-RefNo1   to Global-Current-RefNo
143600              perform zz030-Write-Sort
143700              perform ba040-Clear-To-Next-Period thru ba040-Exit
143800              go to ba020-GetAWord.
143900*>
144000*> we now have basic ws records, ie starting 01-49,66,77,78,88 etc
144100*>
144200      if      wsFoundWord2 (1:Word-Length) not numeric
144300              display "ba020:" Msg4 wsFoundWord2 (1:Word-Length)
144500              close Source-Listing SourceInput
                          Supplemental-Part1-Out
139810              move 16 to return-code
139900              goback.    *> if here, its broke
144800*>
144900*> word = Build-Number
145000*>
145100      perform zz160-Clean-Number thru zz160-Exit.
145200      if      Build-Number > 0 and < 50
145300              move spaces to Saved-Variable.
145400*>
145500      if      Build-Number = 01
145600         and  (Global-Current-Level = high-values
145700           or HoldWSorPD > 1)
145800              move zero to sw-Git
145900              move 1 to Global-Current-Level.
146000*>
146100      if      Build-Number = 88 or = 78 or = 77 or = 66
146200                                or (Build-Number > 0 and < 50)
146300              go to ba050-Get-User-Word.
      *>
146400*> getting here Should never happen
      *>
146500      display "ba020:" Msg5 "bld=" Build-Number
146600              " word=" wsFoundWord2 (1:CWS).
146800     close    Source-Listing SourceInput Supplemental-Part1-Out.
139810     move     20 to return-code.
146900     goback.                            *> if here, its broke
151100*>
151200 ba040-Clear-To-Next-Period.
151300     if       Word-Delimit = "."
151400              go to ba040-Exit.
151500     perform  zz110-Get-A-Word thru zz110-Exit.
151600     if       wsFoundWord2 (1:7) = "GLOBAL "
151700              move 1 to sw-Git
151800              perform zz200-Load-Git thru zz200-Exit.
151900     if       wsFoundWord2 (1:8) = "INDEXED "
152000              perform ba052-After-Index.
           if       wsFoundWord2 (1:10) = "DEPENDING "
                    perform ba053-After-Depending.
           if       HoldWSorPD = 7 and
                    (wsFoundWord2 (1:6) = "TO    "
                          or "FROM  " or "USING ")
161300              perform zz110-Get-A-Word thru zz110-Exit
161400              perform zz030-Write-Sort.
152100     go       to ba040-Clear-To-Next-Period.
      *>
152200 ba040-Exit.
152300     exit.
152400*>
152500 ba050-Get-User-Word.
152600*>
152700*> to here with nn ^ word but word could be pic/value etc ie no dataname
152800*>
152900     perform  zz110-Get-A-Word thru zz110-Exit.
153000     if       wsFoundWord2 (1:7) = "FILLER "
153100              move "FILLER" to Saved-Variable
153200              go to ba051-After-DataName.
153300     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
153400*>
153500*> Trap for no dataname, ie reserved word
153600*>   this [the 'if'] MUST be left in here
153700*>
153800     if       a not = zero
153900              move "FILLER" to Saved-Variable
154000              go to ba051-After-New-Word.
154100*>
154200*> not a reserved word AND a 88, looking for 01 - 49 [ or 77]
154500*>
154600     if       (Build-Number > 0 and < 50) or = 77
154700              move wsFoundWord2 (1:CWS) to Saved-Variable.
154800*>
154900     if       Build-Number = 88
155000          and Con-Tab-Count not < Con-Tab-Size
155100              add 10 to    Con-Tab-Size.
155200     if       Con-Tab-Size > 5000
155300              move 5001 to Con-Tab-Size           *> just in case
155400              display Msg6
155500              go to ba050-Bypass-Add-2-Con-Table.
      *>
155600*> add 88 dataname to constant table
155700*>
155800     if       Build-Number = 88
155900          and Con-Tab-Count < Con-Tab-Size
156000              add 1 to Con-Tab-Count
156100              if  Reports-In-Lower
156200                  move function lower-case (Saved-Variable) to
156300                          Variables (Con-Tab-Count)
156400                  move function lower-case (wsFoundWord2 (1:CWS))
156500                       to Conditions (Con-Tab-Count)
156600              else
156700                  move Saved-Variable to Variables (Con-Tab-Count)
156800                  move wsFoundWord2 (1:CWS)
156900                                     to Conditions (Con-Tab-Count)
157000              end-if
157100     end-if
           .
157200*>
157800 ba050-Bypass-Add-2-Con-Table.
157900*>
158000*> we don't have a reserved word! a = 0 = no
158100*>
158200      if      Global-Current-Level not = high-values
158300              move Gen-RefNo1   to Global-Current-RefNo
158400              move wsFoundWord2 (1:32) to Global-Current-Word.
158500*>
158600      perform zz030-Write-Sort.
158700      go      to ba051-After-DataName.
      *>
158800*> YES, Should never happen  but it does often enough if no dataname??
      *>   this should now be fixed
      *>
158900     display  "ba050: Major logic error 01".
159000     close    Source-Listing SourceInput Supplemental-Part1-Out.
139810     move     24 to return-code.
159100     goback.                   *> its broke & I've cocked it again
159400*>
159500 ba051-After-DataName.
159600     if       Word-Delimit = "."
159700          and Build-Number not = 66 and not = 77 and not = 78
159800          and Saved-Variable not = "FILLER"
159900          and Global-Active
160000              perform zz200-Load-Git thru zz200-Exit.
160100     if       Word-Delimit = "."
160200              go to ba020-GetAWord.
160300     if       Global-Active
160400          and Build-Number = 88
160500              perform zz200-Load-Git thru zz200-Exit
160600              perform ba040-Clear-To-Next-Period thru ba040-Exit
160700              go to ba020-GetAWord.
160800     perform  zz110-Get-A-Word thru zz110-Exit.
160900*>
161000 ba051-After-New-Word.
161100     if       wsFoundWord2 (1:10) = "REDEFINES " or
161200              wsFoundWord2 (1:8) = "RENAMES "
161300              perform zz110-Get-A-Word thru zz110-Exit
161400              perform zz030-Write-Sort
161500     else
161600      if      wsFoundWord2 (1:7) = "GLOBAL "
161700              move 1 to sw-Git
161800              perform zz200-Load-Git thru zz200-Exit
161900      else
162000       if     Global-Active
162100          and Build-Number not = 66 and not = 77 and not = 78
162200          and Saved-Variable not = "FILLER"
162300              perform zz200-Load-Git thru zz200-Exit.
162400*>
           if       HoldWSorPD = 7 and
                    (wsFoundWord2 (1:6) = "TO    "
                          or "FROM  " or "USING ")
161300              perform zz110-Get-A-Word thru zz110-Exit
161400              perform zz030-Write-Sort.
      *>
162500     perform  ba040-Clear-To-Next-Period thru ba040-Exit.
162600     go       to ba020-GetAWord.
162700*>
162800 ba052-After-Index.
162900*>
163000*> if Index found ignore 'by' if present
163100*>
163200     perform  zz110-Get-A-Word thru zz110-Exit.
163300     if       wsFoundWord2 (1:3) = "BY "
163400              go to ba052-After-Index.
163500*>
163600*> Should have index name and might be global
163700*>
163800     perform  zz030-Write-Sort.
160300     if       Global-Active
158400              move wsFoundWord2 (1:32) to Global-Current-Word
160500              perform zz200-Load-Git thru zz200-Exit.
163900*>
       ba053-After-Depending.
      *>
      *> If depending found ignore 'on' if present, no global processing
      *>
163200     perform  zz110-Get-A-Word thru zz110-Exit.
163300     if       wsFoundWord2 (1:3) = "ON "
163400              go to ba053-After-Depending.
163500*>
163600*> Should have depending name
163700*>
163800     perform  zz030-Write-Sort.
163900*>
164000 ba000-Exit.
164100     exit.
164200*>
164300 bb000-Process-Procedure Section.
164400 bb010-New-Record.
164500*>
164600*> at this point we need to get a word but have
164700*>                 PROCEDURE (as in DIVISION) as wsFoundWord2
      *> but 1st, sort Global  table prior to running search(es)
164800*>  and I know it will happen for every module in src after 1st one
      *>    this needs a rewrite as well as process a word etc complete mess
           if       Git-Table-Count > 1
186100              sort  Git-Elements ascending Git-Word.
      *>
164900 bb020-GetAWord.
165000     perform  zz110-Get-A-Word thru zz110-Exit.
165100     if       End-Prog
165200              go to bb000-Exit.
165300     if       Source-Eof
165400              go to bb000-Exit.
165500     if       Word-Delimit = "."
165600         and  wsf1-1 = space
165700              go to bb020-GetAWord.
165800*>
165900 bb030-Chk1.
           if       wsFoundWord2 (1:1) alphabetic
166000           perform zz130-Extra-Reserved-Word-Check thru zz130-Exit
           else
                    move zero to a.
166100*>
166200*> Do we have a reserved word? a = 0 means no or a number so ignore
166300*>
166400     if       a > zero
166500              go to bb020-GetAWord.
166600     if       wsf1-1 numeric
166700              go to bb020-GetAWord.
166800     if       wsf1-1 = "-"
166900        and   wsFoundWord2 (2:1) numeric
167000              go to bb020-GetAWord.
167100     if       wsf1-1 = "+"
167200        and   wsFoundWord2 (2:1) numeric
167300              go to bb020-GetAWord.
167400     if       wsf1-1 = quote or = "'"
167500              go to bb020-GetAWord.
167600     if       wsf1-1 = "X"
167700        and   (wsFoundWord2 (2:1) = quote or = "'")
167800              go to bb020-GetAWord.
167900     if       wsf1-1 = "H"
168000        and   (wsFoundWord2 (2:1) = quote or = "'")
168100              go to bb020-GetAWord.
           if       wsf1-1 = ":"
              and   Word-Length = 1
                    go to bb020-GetAWord.
168200     if       wsf1-1 = "("
168300              go to bb050-Check-SubScripts.
168400*>
168500 bb040-chk2.
168600*>
168700*> check for arithmetic operators
168800*>
168900     if       wsf1-3 = "-  " or = "+  " or = "*  " or = "/  "
169000                             or = "** "
169100              go to bb020-GetAWord.
169200*>
169300*> check for relational Conditions
169400*>
169500     if       wsf1-2 = "> " or = "< " or = "= "
169600              go to bb020-GetAWord.
169700     if       wsf1-3 = ">= " or = "<= " or = "<> "
169800              go to bb020-GetAWord.
169900*>
170000*> we have a dataname and are we at word one with period delimiter
170100*> is it a paragraph?
170200*>
170300     move     2 to HoldWSorPD2.
170400     if       Word-Delimit = "."
170500          and Source-Words = 1
170600              move zero to HoldWSorPD2.
170700*>
170800*> Check if we have a section name if so set wdorpd2 = 1
170900*>
171000     string   wsFoundWord2 (1:Word-Length) delimited by size
171100              " SECTION" delimited by size
171200                into HoldFoundWord.
171300     add      Word-Length 8 giving a.
171400     if       HoldWSorPD2 not = zero
171500         and  SourceInWS (1:a) = HoldFoundWord (1:a)
171600              move 1 to HoldWSorPD2.
171700     if       wsFoundWord2 (Word-Length:1) = ")"
171800              move space to wsFoundWord2 (Word-Length:1)
                    if  Word-Length > 1
                        subtract 1 from Word-Length
                    end-if
171900              go to bb030-Chk1
           end-if
172000     perform  zz030-Write-Sort.
172100     go       to bb020-GetAWord.
172200*>
172300 bb050-Check-SubScripts.
172400*>
172500*> arrives here with (xxxx
172600*>
172700     move     spaces to wsFoundNewWord3.
172800     move     zero to a b c d q s y y2.
172900     subtract 2 from Word-Length giving z.
           if       z < 1
                    move 1 to z.
173000*> z = subscript length less () & here we skip 1st char '('
173100     inspect  wsFoundWord2 (2:z) tallying a for all "(".
173200     inspect  wsFoundWord2 (2:z) tallying b for all ")".
173300     inspect  wsFoundWord2 (2:z) tallying c for all ":".
173400     inspect  wsFoundWord2 (2:z) tallying d for all space.
173500     inspect  wsFoundWord2 (2:z) tallying y for all quote.
173600     inspect  wsFoundWord2 (2:z) tallying y2 for all "'".
173700     add      y2 to y.
173800     if       a > b
173900              add 1 to z
174000              add 1 to Word-Length
174100              move ")" to wsFoundWord2 (Word-Length:1).
174200*>   abc)
174300     if       b > a and a = zero
174400              move space to wsFoundWord2 (Word-Length:1)
174500              subtract 1 from Word-Length.
174600*> still need to deal with (aaa))
174700     subtract 1 from Word-Length giving t.
           if       t < 1
                    move 1 to t.
174800     if       b > a
174900         and  wsFoundWord2 (Word-Length:1) = ")"
175000         and  wsFoundWord2 (t:1) = ")"
175100              move space to wsFoundWord2 (Word-Length:1)
175200              move t to Word-Length.
175300     if       y > zero   *> quotes?
175400              move  zero to q s t
175500              go to bb060-Scan4-Quotes.
175600     if       c > zero   *> colon?
175700              move  zero to q s t
175800              go to bb100-scan4-colon.
175900*>
176000     subtract 2 from Word-Length giving z.
176100     if       z < 1
176200              move 1 to z.
176300     if       d = zero
176400          and wsFoundWord2 (2:z) numeric
176500              go to bb020-GetAWord.
176600*> for (abcd  instance
176700     if       wsFoundWord2 (Word-Length:1) not = ")"
176800         and  d = zero
176900              add 1 to Word-Length.
177000*> err word and length is pointing to (
           if       d = zero
                    move spaces to wsFoundNewWord
                    subtract 2 from Word-Length giving z
                    if   z < 33
                         move wsFoundWord2 (2:z) to wsFoundNewWord
                    else
                         move wsFoundWord2 (2:32) to wsFoundNewWord
                    end-if
                    move wsFoundNewWord to wsFoundWord2
                    perform zz130-Extra-Reserved-Word-Check
                                                   thru zz130-Exit
                    if  a > zero
                        go to bb020-GetAWord
                    end-if
177600              perform zz030-Write-Sort
177700              go to bb020-GetAWord.
177800*> cockup trap
177900     display Msg7
178000     go to bb020-GetAWord.
178100*>
178200 bb060-Scan4-Quotes.
178300     add      1 to q.
178400     if       wsFoundWord2 (q:1) not = quote and not = "'"
178500              add 1 to s
178600              move wsFoundWord2 (q:1) to wsFoundNewWord3 (s:1)
178700              go to bb060-Scan4-Quotes.
178800*>
178900*> wsFoundNewWord = non quoted field so far
179000*>
179100 bb070-Got-Quote.
179200     add      1 to q.
179300     add      1 to t.
179400     if       q > Word-Length
179500              go to bb090-Recover-Word.
179600     if       wsFoundWord2 (q:1) not = quote and not = "'"
179700              go to bb070-Got-Quote.
179800     add      1 to q.
179900     add      1 to t.
180000*>
180100*> t = quoted lit length including quotes
180200*>   and we are now at end quote + 1
180300 bb080-Quote-Clean.
180400     if       q > Word-Length
180500              go to bb090-Recover-Word.
180600     add      1 to s.
180700     move     wsFoundWord2 (q:1) to wsFoundNewWord3 (s:1).
180800     add      1 to q.
180900     go       to bb080-Quote-Clean.
      *>
181000 bb090-Recover-Word.
181200*>
181300*> Word-Length and wsFoundWord2 less quoted field
181400*>
181100     subtract t from Word-Length.
181500     move     wsFoundNewWord3 (1:CWS) to wsFoundWord2 (1:CWS).
181600     go       to bb050-Check-SubScripts.
181700*>
181800 bb100-scan4-colon.
181900*>
182000*> done already =  move     zero to q s t.
182100*> now we can have num:num DataName:DN num:DN DN:num
182200*>
182300     subtract 1 from Word-Length giving z.
182400     move     spaces to wsFoundNewWord wsFoundNewWord2.
182500     move     1 to t.
182600     unstring wsFoundWord2 (2:z) delimited by ":"
182700              into wsFoundNewWord
182800              count q
182900              pointer t.
183000*> t now : +1
183100     unstring wsFoundWord2 (2:z) delimited by ")"
183200              into wsFoundNewWord2
183300              count s
183400              pointer t.
183500     if     t not = Word-Length
183600            display "bb100 Error: t=" t " word-len="
183700            Word-Length " z=" z.
183800     if       wsFoundNewWord (1:q) not numeric
183900              move spaces to wsFoundWord2
184000              move wsFoundNewWord (1:q) to wsFoundWord2
184100              perform zz030-Write-Sort.
184200     if       s > zero
              and   wsFoundNewWord2 (1:s) not numeric
184300              move spaces to wsFoundWord2
184400              move wsFoundNewWord2 (1:s) to wsFoundWord2
184500              perform zz030-Write-Sort.
184600     go       to bb020-GetAWord.
184800 bb000-Exit.
184900     exit.
185000*>
185100 bc000-Last-Act Section.
185200*>*********************
185300*>  Report Phase
185400*>
185600     sort     SortFile
185700              ascending key SdSortKey
185800              using  Supplemental-Part1-Out
185900              giving Supplemental-Part2-In.
186000     if       Git-Table-Count > 1
186100              sort  Git-Elements ascending Git-Word.
186200*> Print order:
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
179700     if       not All-Reports
179800              go to bc090-Last-Pass2.
179900*
180000* produce group W-S xref & procedure used in testing
180100*  and taken from original code circa 1983.
180200*  ------- Leave in just in case needed for testing ----
180300*
       bc010-group-report.
180400     move     spaces to saveSkaDataName.
180500     open     input Supplemental-Part2-In.
180600     read     Supplemental-Part2-In at end
180700              display Msg1
180800              go to bc000-Exit.
180900     perform  zz150-WriteHdb thru zz150-Exit.
181000     perform  zz150-WriteHdb8 thru zz150-Exit.
181100     move     zero to q.
181200     go       to bc030-IsX.
181300*
181400 bc020-Read-Sorter.
181500     read     Supplemental-Part2-In at end
181600              perform bc050-Check-Q
181700              close Supplemental-Part2-In
181800              go to bc090-Last-Pass2.
181900*
182000 bc030-IsX.
182100     if       SkaDataName = spaces
182200              go to bc020-Read-Sorter.
182300     perform  bc040-PrintXRef thru bc080-Exit.
182400     go       to bc020-Read-Sorter.
182500*
182600 bc040-PrintXRef.
182700     if       SkaDataName = saveSkaDataName
182800              go to bc070-ConnectD.
182900     move     SkaDataName to saveSkaDataName.
183000*
183100 bc050-Check-Q.
183200     if       XrDataName not = spaces
183300         and  q = zero
183400              move 1 to q.
183500     if       q > zero
183600              write PrintLine
183700              move zero to q
183800              move spaces to PrintLine.
183900*
184000 bc060-ConnectC.
184100     move     spaces to PrintLine.
184200     move     SkaDataName to XrDataName.
184300     move     SkaRefNo to XrDefn.
184400     move     LSect (SkaWSorPD) to XrType.
184500     go       to bc080-Exit.
184600*
184700 bc070-ConnectD.
184800     if       q > 7
184900              perform bc050-Check-Q.
185000     add      1 to q.
185100     move     SkaRefNo to XrReference (q).
185200*
185300 bc080-Exit.
           Exit.
185500*
186300 bc090-Last-Pass2.
186400*>****************
186500*> printout W-S section blocks as needed
186600*> Check if any w-s used in module if not, do conditions, functions etc
186700*>
186800     move     70 to Line-Count.
186900     if       Section-Used-Table not = zeros
187000              move  1 to WS-Anal1
187100              perform bc100-Working-Storage-Report
187200                    thru bc180-Exit 7 times.
187300*>
187400     if       Git-Table-Count > zero
187500              perform bc600-Print-Globals thru bc600-Exit.
187600     go       to bc190-Do-Conditions.
187700*>
187800 bc100-Working-Storage-Report.
187900*>****************************
188000*>  skip section if no data
188100*>
188200     if       USect (WS-Anal1) = zero
188300              add 1 to WS-Anal1
188400              go to bc180-Exit.
188500*>
188600     move     spaces to saveSkaDataName.
188700     open     input Supplemental-Part2-In.
188800     read     Supplemental-Part2-In at end
188900              display Msg1
189000              go to bc000-Exit.
189100     perform  zz150-WriteHdb thru zz150-Exit.
189200     perform  zz150-WriteHdb2 thru zz150-Exit.
189300     move     zero to q.
189400*>
189500*> group report
189600*>
189700     go       to bc120-IsX2.
189800*>
189900 bc110-Read-Sorter.
190000     read     Supplemental-Part2-In at end
190100              add 1 to WS-Anal1
190200              perform  bc140-Check-Q
190300              close Supplemental-Part2-In
190400              go to bc180-Exit.
190500*>
190600 bc120-IsX2.
190700     if       SkaDataName = spaces
190800              go to bc110-Read-Sorter.
190900     perform  bc130-PrintXRef2 thru bc170-Exit.
191000     go       to bc110-Read-Sorter.
191100*>
191200 bc130-PrintXRef2.
191300*>      test was 8
191400     if       SkaDataName = saveSkaDataName
191500              go to bc160-ConnectD2.
191600*>
191700     if       SkaWSorPD > WS-Anal1
191800              go to bc170-Exit.
191900     if       SkaWSorPD not = WS-Anal1
192000              go to bc170-Exit.
192100*>
192200*> new variable groups 1 thru 7
192300*>
192400     move     SkaDataName to saveSkaDataName.
192500     move     SkaWSorPD   to saveSkaWSorPD.
192600     move     SkaWSorPD2  to saveSkaWSorPD2.
192700*>
192800 bc140-Check-Q.
192900     if       XrDataName not = spaces
193000         and  q = zero
193100              move 1 to q.
193200     if       q > zero
193300              write PrintLine
193400              move zero to q
                    move 1 to q2
193500              move spaces to PrintLine.
193600*>
193700 bc150-ConnectC2.
193800     move     spaces to PrintLine.
193900     move     SkaDataName to XrDataName.
194000     move     SkaRefNo to XrDefn.
194100     move     LSect (SkaWSorPD) to XrType.
194200     go       to bc170-Exit.
194300*>
194400 bc160-ConnectD2.
194500     if       q > 7
194600              perform bc140-Check-Q.
194700     add      1 to q.
194800     move     SkaRefNo to XrReference (q).
195000 bc170-Exit.
195100     exit.
195200*>
195300 bc180-Exit.
195400     exit.
195500*>
195600 bc190-Do-Conditions.
195700*>
195800*> start with sorted variables
195900*>
196000     if       Con-Tab-Count = zero
196100              go to bc195-Done.
196200     if       Con-Tab-Count > 1
196300              sort  Con-Tab-Blocks ascending Variables.
196400     move     "[S]" to hdr11a-sorted.
196500     move     spaces to hdr11b-sorted.
196600     perform  zz150-WriteHdb.
196700     perform  zz150-WriteHdb7 thru zz150-Exit.
196800     move     zero to a.
196900     perform  bc192-Print-Conditions.
197000     go       to bc194-Now-Reverse.
197200 bc192-Print-Conditions.
197300     if       a < Con-Tab-Count
197400              add 1 to a
197500              move spaces to PrintLine2
197600              move  Conditions (a) to P-Variables
197700              move  Variables (a) to P-Conditions
197800              write PrintLine2
197900              go to bc192-Print-Conditions.
198000*>
198100 bc194-Now-Reverse.
198200*>
198300*> now sort conditions if more than 1 element in table
198400*>   and print else don't
      *>
198500     if       Con-Tab-Count > 1
198600              sort  Con-Tab-Blocks ascending Conditions
198700              move     "[S]" to hdr11b-sorted
198800              move     spaces to hdr11a-sorted
198900              perform  zz150-WriteHdb
199000              perform  zz150-WriteHdb7 thru zz150-Exit
199100              move     zero to a
199200              perform  bc192-Print-Conditions.
197500     move     spaces to PrintLine2.
199400 bc195-Done.
199500     perform  bc300-Last-Pass4 thru bc399-Exit.
      *>
199600*> now pass3 (fall thru)
      *>
199700 bc200-Last-Pass3.
199800*>****************
199900*> now do procedure div and ref to procedure div but no functions
200000*>
200100     move     spaces to saveSkaDataName.
200200     move     zero to saveSkaWSorPD saveSkaWSorPD2 q2.
200300     open     input Supplemental-Part2-In.
200400     read     Supplemental-Part2-In at end
200500              display Msg1
200600              go to bc000-Exit.
200700     perform  zz150-WriteHdb.
200800     perform  zz150-WriteHdb3 thru zz150-Exit.
200900     move     zero to q.
201100     go       to bc220-IsX3.
201300 bc210-Read-Sorter3.
201400     read     Supplemental-Part2-In at end
201500              perform bc140-Check-Q
201600              close Supplemental-Part2-In
222000              if   q2 = zero
222100                   move spaces to PrintLine
222200                   move "None" to XrDataName
222300                   write PrintLine
                    end-if
201700              go to bc400-Last-Pass5.
201800*>
201900 bc220-IsX3.
202000     if       SkaDataName = spaces
202100              go to bc210-Read-Sorter3.
202200     perform  bc230-PrintXRef3 thru bc270-Exit.
202300     go       to bc210-Read-Sorter3.
202400*>
202500 bc230-PrintXRef3.
202600*>
202700*> ignore all working-storage
202800*>
202900     if       SkaDataName not = saveSkaDataName
203000         and  SkaWSorPD not = 8
203100              move  SkaDataName to saveSkaDataName
203200              move  SkaWSorPD   to saveSkaWSorPD
203300              move  SkaWSorPD2  to saveSkaWSorPD2
203400              go to bc270-Exit.
203500*>
203600*> catch any redefines
203700*>
203800     if       SkaDataName = saveSkaDataName
203900         and  saveSkaWSorPD not = 8
204000              go to bc270-Exit.
204100*>
204200*> catch any procedure followed by functions
204300*>   dont think this can happen
204400*>
204500     if       SkaDataName = saveSkaDataName
204600         and  saveSkaWSorPD = 8
204700         and  SkaWSorPD > 8
204800              go to bc270-Exit.
204900*>
205000     if       SkaDataName = saveSkaDataName
205100              go to bc260-ConnectD3.
205200     move     SkaDataName to saveSkaDataName.
205300     move     SkaWSorPD   to saveSkaWSorPD.
205400     move     SkaWSorPD2  to saveSkaWSorPD2.
205600     perform  bc140-Check-Q.
205800 bc250-ConnectC3.
205900     move     spaces to PrintLine.
206000     move     SkaDataName to XrDataName.
206100     move     SkaRefNo to XrDefn.
206200*>
206300*> process sections
206400*>
206500     if       SkaWSorPD2 not = 1
206600              move LSect (SkaWSorPD) to XrType
206700     else
206800              move "S" to XrType.
206900     go       to bc270-Exit.
207100 bc260-ConnectD3.
207200     if       q > 7
207300              perform bc140-Check-Q.
207400     add      1 to q.
207500     move     SkaRefNo to XrReference (q).
207700 bc270-Exit.
207800     exit.
207900*>
208000 bc300-Last-Pass4.
208100*>****************
208200*> now do functions
208300*>
188200     if       USect (9) = zero
188400              go to bc399-Exit.
208400     move     spaces to saveSkaDataName.
208500     move     zero to saveSkaWSorPD saveSkaWSorPD2 q2.
208600     move     70 to Line-Count.
208700     open     input Supplemental-Part2-In.
208800     read     Supplemental-Part2-In at end
208900              display Msg1
209000              go to bc000-Exit.
209100     move     zero to q.
209200     go       to bc320-IsX4.
209300*>
209400 bc310-Read-Sorter4.
209500     read     Supplemental-Part2-In at end
209600              perform bc335-Check-Q
209700              close Supplemental-Part2-In
209900              go to bc399-Exit.
210100 bc320-IsX4.
210200     if       SkaDataName = spaces
210300              go to bc310-Read-Sorter4.
210400     perform  bc330-PrintXRef4 thru bc360-Exit.
210500     go       to bc310-Read-Sorter4.
210700 bc330-PrintXRef4.
210800*>
210900*> ignore all working-storage & procedure
211000*>
211100     if       SkaWSorPD not = 9
211200              go to bc360-Exit.
211300*>
211400     if       Line-Count > 60
211500              move "Functions" to hdr8-hd
211600              move zero to Line-Count
211700              perform zz150-WriteHdb
211800              perform zz150-WriteHdb3 thru zz150-Exit.
211900*>
212000     if       SkaDataName = saveSkaDataName
212100              go to bc350-ConnectD4.
212200     move     SkaDataName to saveSkaDataName.
212400 bc335-Check-Q.
212500     if       XrDataName not = spaces
212600         and  q = zero
212700              move 1 to q.
212800     if       q > zero
212900              write PrintLine
213000              move zero to q
                    move 1 to q2
213100              move spaces to PrintLine.
213300 bc340-ConnectC4.
213400     move     spaces to PrintLine.
213500     move     SkaDataName to XrDataName.
213600     move     SkaRefNo to XrDefn.
213700     move     LSect (SkaWSorPD) to XrType.
213800     go       to bc360-Exit.
214000 bc350-ConnectD4.
214100     if       q > 7
214200              perform bc335-Check-Q.
214300     add      1 to q.
214400     move     SkaRefNo to XrReference (q).
214600 bc360-Exit.
214700     exit.
214800*>
214600 bc399-Exit.
214700     exit.
214800*>
214900 bc400-Last-Pass5.
215000*>****************
215100*> now do non referenced ws but ignore references of zero (Globals).
215200*>
215300     move     spaces to saveSkaDataName.
215400     move     zero to saveSkaWSorPD saveSkaWSorPD2 S-Pointer.
215500     open     input Supplemental-Part2-In.
215600     read     Supplemental-Part2-In at end
215700              display Msg1
215800              go to bc000-Exit.
215900     perform  zz150-WriteHdb.
216000     perform  zz150-WriteHdb4 thru zz150-Exit.
216100     move     zero to q.
216300     go       to bc420-IsX5.
216400*>
216500 bc410-Read-Sorter5.
216600     read     Supplemental-Part2-In at end
216700              perform bc440-Check-4Old
216800              close Supplemental-Part2-In
222000              if   S-Pointer = zero
222100                   move spaces to PrintLine
222200                   move "None" to XrDataName
222300                   write PrintLine
                    end-if
216900              go to bc500-Last-Pass6.
217100 bc420-IsX5.
217200*>
217300*> ignore zero refs = Globals  ??????????
217400*>
217500     if       SkaDataName = spaces
217600           or SkaRefNo = zeros
217700              go to bc410-Read-Sorter5.
217800     perform  bc430-PrintXRef5 thru bc450-Exit.
217900     go       to bc410-Read-Sorter5.
218100 bc430-PrintXRef5.
218200*>
218300*> ignore redefines - No I won't
218400*>
218500*>     if       SkaDataName = saveSkaDataName
218600*>         and  SkaWSorPD < 8
218700*>              go to bc450-Exit.
218800     if       SkaDataName = saveSkaDataName
218900              move 2 to q
219000              go to bc450-Exit.
219100*> 1st copy of a name can't be non w-s
219200     if       SkaWSorPD > 7
219300              go to bc450-Exit.
219400*> print Only occurance then store new one
219500     perform  bc440-Check-4Old.
219600*>
219700     move     SkaDataName to saveSkaDataName.
219800*>
219900*> first record for a given name
220000*>
220100     move     spaces to PrintLine.
220200     move     SkaDataName to XrDataName.
220300     move     SkaRefNo to XrDefn.
220400     move     LSect (SkaWSorPD) to XrType.
220500     move     1 to q.
220600     go       to bc450-Exit.
220800 bc440-Check-4Old.
220900     if       q = 1
221000              move 1 to S-Pointer
221100              write PrintLine.
221300 bc450-Exit.
221400     exit.
221500*>
221600 bc500-Last-Pass6.
221700*>****************
221800*> now do non referenced procedure paragraphs.
221900*>
222400     move     spaces to saveSkaDataName.
222500     move     zero to saveSkaWSorPD S-Pointer.
222600     open     input Supplemental-Part2-In.
222700     read     Supplemental-Part2-In at end
222800              display Msg1
222900              go to bc000-Exit.
223000     perform  zz150-WriteHdb.
223100     perform  zz150-WriteHdb5 thru zz150-Exit.
223200     move     zero to q.
223400     go       to bc520-IsX6.
223600 bc510-Read-Sorter6.
223700     read     Supplemental-Part2-In at end
223800              perform bc540-Check-4Old
223900              perform bc540-Check-4Old6
224000              close Supplemental-Part2-In
224100              go to bc000-Exit.
224300 bc520-IsX6.
224400     if       SkaDataName = spaces
224500              go to bc510-Read-Sorter6.
224600     perform  bc530-PrintXRef6 thru bc550-Exit.
224700     go       to bc510-Read-Sorter6.
224900 bc530-PrintXRef6.
225000*>
225100*> ignore all non procedure
225200*>
225300     if       SkaDataName = saveSkaDataName
225400              move zero to q
225500              go to bc550-Exit.
225600*> print only occurance then store new one
225700     if       q = 1
225800        and   saveSkaWSorPD = 8
225900              move 1 to S-Pointer
226000              write PrintLine.
226100*>
226200     move     SkaDataName to saveSkaDataName.
226300     move     SkaWSorPD to saveSkaWSorPD.
226400*>
226500*> first record for a given name
226600*>
226700     move     spaces to PrintLine.
226800     move     SkaDataName to XrDataName.
226900     move     SkaRefNo to XrDefn.
227000     if       SkaWSorPD2 not = 1
227100              move LSect (SkaWSorPD) to XrType
227200     else
227300              move "S" to XrType.
227400     move     1 to q.
227500     go       to bc550-Exit.
227700 bc540-Check-4Old.
227800     if       q = 1 and saveSkaWSorPD = 8
227900              move 1 to S-Pointer
228000              write PrintLine.
228200 bc540-Check-4Old6.
228300     if       S-Pointer = zero
228400              move spaces to PrintLine
228500              move "None" to XrDataName
228600              write PrintLine.
228800 bc550-Exit.
228900     exit.
229000*>
229100 bc600-Print-Globals.
229200*>*******************
229300*>  Print Global List for all xrefd modules
229400*>
229500     perform  zz150-WriteHdb thru zz150-Exit.
229600     perform  zz150-WriteHdb2b thru zz150-Exit.
229700     move     spaces to PrintLine.
229800     perform  varying a from 1 by 1 until a > Git-Table-Count
229900              move Git-RefNo (a) to XrDefn
230000              move Git-HoldWSorPD (a) to b
230100              if Reports-In-Lower
230200                  move function lower-case (Git-Word (a))
230300                                                   to XrDataName
230400                  move function lower-case (Git-Prog-Name (a))
230500                                                   to PL-Prog-Name
230600              else
230700                  move Git-Word (a) to XrDataName
230800                  move Git-Prog-Name (a) to PL-Prog-Name
230900              end-if
231000              move LSect (b) to XrType
231100              write PrintLine
231200     end-perform.
231300*>
231400 bc600-Exit.
231500     exit.
      *>
195600 bc620-Do-Global-Conditions.
195700*>**************************
195800*> Produce report of unused Global Conditions if any
195900*>
196000     if       Git-Table-Count = zero
196100              go to bc629-Exit.
      *>
196600     perform  zz150-WriteHdb.
196700     perform  zz150-WriteHdb6 thru zz150-Exit.
196800     move     zero to a b.
           perform  varying a from 1 by 1 until a > Git-Table-Count
                    if    Git-In-Use-Flag (a) = space
197500                    move  spaces to PrintLine
197600                    move  Git-Word (a)  to XrDataName
                          move  git-RefNo (a) to XrDefn
                          move LSect (Git-HoldWsorPD (a)) to XrType
                          if  Git-Build-No (a) = 88
                              move "C" to XrCond
                          else
                              move space to XrCond
                          end-if
                          move 1 to b
197800                    write PrintLine
                    end-if
           end-perform
           if       b = zero
222100              move spaces to PrintLine
222200              move "None" to XrDataName
222300              write PrintLine.
       bc629-Exit.
           exit.
231700 bc000-Exit.
231800     exit.
231900*>
232000 zz000-Routines Section.
232100 zz000-Inc-CobolRefNo.
232200     add      1 to Gen-RefNo1.
232300*>
232400 zz000-OutputSource.
232500     if       List-Source
232600              move  spaces to Source-List
232700              move  SourceRecIn to SourceOutput
232800              move  Gen-RefNo1 to sl-Gen-RefNo1
232900              write Source-List.
233000*>
233100 zz030-Write-Sort.
233200     move     HoldWSorPD to SkaWSorPD.
233300     move     HoldWSorPD2 to SkaWSorPD2.
233400     move     wsFoundWord2 (1:CWS) to wsFoundNewWord4.
233700     if       Reports-In-Lower
233800              move function lower-case (wsFoundWord2 (1:CWS)) to
233900                    wsFoundNewWord4.
233500     if       HoldWSorPD > 7
233600              perform zz140-Function-Check thru zz140-Exit.
234200*>
234300*> stops dups on same fn and refno
234400*>
234500     if       wsFoundNewWord4 not = SkaDataName
234600         or   Gen-RefNo1 not = SkaRefNo
234700              move wsFoundNewWord4 to SkaDataName
234800              move Gen-RefNo1 to SkaRefNo
234900              move 1 to USect (HoldWSorPD)
235000              write SortRecord
233500              if   HoldWSorPD > 7  *> only do for proc div.
                         perform zz310-Check-For-Globals thru zz319-Exit
                    end-if
           end-if.
235100*>
235200 zz100-Get-A-Source-Record.
235300*>*************************
235400*> reads a source record, ignoring comments cleans out excessive
235500*>   spaces, ';', ',' etc
235600*>
235700     if       Had-End-Prog
235800              move zero to sw-Had-End-Prog
235900              go to zz100-New-Program-point.
236000     if       End-Prog
236100              go to zz100-Exit.
236200     if       Source-Eof
236300              display Msg8
236400              go to zz100-Exit.
236500*>
236600     move     spaces to SourceRecIn SourceInWS.
236700     read     SourceInput at end
236800              move 1 to sw-Source-Eof
236900              GO TO zz100-Exit.
237100     move     function upper-case (SourceRecIn)
237200                   to SourceInWS.
      *>
237300*> change tabs to spaces prior to printing & remove OC comment lines eg '#'
237500*>
237600     if       (SourceInWS (1:1) = "#" or = "$")
237700              go to zz100-Get-A-Source-Record.
237800*> won't happen with fn.i or .t input
237900     if       (SourceInWS (1:1) = "*" or = "/")
238000              perform zz000-Inc-CobolRefNo
238100              perform zz000-Outputsource
238200              go to zz100-Get-A-Source-Record.
238300*>
238400*> remove unwanted chars and all multi spaces so that unstrings
      *>  can work easier Includes literals " " etc
238600*> Doesn't matter if literals get screwed up in this way
      *>
238700     inspect  SourceInWS replacing all x"09" by space.
238800     inspect  SourceInWS replacing all ";" by space.
238900     inspect  SourceInWS replacing all "," by space.
239000     inspect  SourceInWS replacing all "&" by space.
239100     perform  zz120-Replace-Multi-Spaces thru zz120-Exit.
239200     move     Line-End to Source-Line-End.
239300*>
239400*> count but do not O/P blank lines
239500*>
239600      if       d < 1
239700               perform zz000-Inc-CobolRefNo
239800               go to zz100-Get-A-Source-Record.
239900*>
240000     if       SourceInWS (1:12) = "END PROGRAM "
240100              perform zz000-Inc-CobolRefNo
240200              perform zz000-Outputsource
240300              go to zz100-Get-A-Source-Record.
240400*>
240500     if       HoldWSorPD > 7
240600        and   (SourceInWS (1:12) = "ID DIVISION."
240700         or   SourceInWS (1:20) = "IDENTIFICATION DIVIS")
240800              move 1 to sw-End-Prog sw-Had-End-Prog sw-Nested
241200              go to zz100-Exit.
241300*>
242000 zz100-New-Program-point.
242100     perform  zz000-Inc-CobolRefNo.
242200     perform  zz000-Outputsource.
242300     move     1 to S-Pointer2.
242400     move     zero to Source-Words.
242500     perform  zz170-Check-4-Section thru zz170-Exit.
242600     go       to zz100-Exit.
242800 zz100-Exit.
242900     exit.
243000*>
243100 zz110-Get-A-Word.
243200*>****************
243300*>  S-Pointer2 must be set to => 1 prior to call
243400*> pointer is a tally of init leading spaces
243500*>
243600     if       Source-Eof
243700          or  End-Prog
243800              go to zz110-Exit.
243900     if       S-Pointer2 not < Source-Line-End
244000         and  SourceInWS (S-Pointer2:1) = "."
244100              move "." to Word-Delimit
244200              move zero to Word-Length
244300              move space to SourceInWS (S-Pointer2:1)
244400              move spaces to wsFoundWord2
244500              go to zz110-Exit.
244600     inspect SourceInWS tallying S-Pointer2 for leading spaces.
244700     if       S-Pointer2 not < Source-Line-End
244800          or  S-Pointer2 > 255
244900              go to zz110-Get-A-Word-OverFlow.
245000*>
245100*> S-Pointer2 = 1st non space
245200*>
245300 zz110-Get-A-Word-Unstring.
245400     move     spaces to wsFoundWord2.
245500     move     S-Pointer2 to s.
245600     unstring SourceInWS delimited by " " or "."
245700              into wsFoundWord2
245800               delimiter in Word-Delimit
245900                with pointer S-Pointer2.
246000*> check 1st char
246100     if       S-Pointer2 > 255
246200              go to zz110-Get-A-Word-OverFlow.
246300     if       wsf1-1 = space
246400         and  SourceInWS (S-Pointer2:1) = "."
246500              move "." to Word-Delimit
246600              move zero to Word-Length
246700              move spaces to wsFoundWord2
246800              go to zz110-Exit.
246900     if       wsf1-1 = space
247000              go to zz110-Get-A-Word-Unstring.
247100     if       (wsf1-1 numeric
247200           or wsf1-1 = "-"
247300           or wsf1-1 = "+")
247400         and  SourceInWS (S-Pointer2:1) not = space
247500              move s to S-Pointer2
247600              unstring SourceInWS delimited by " "
247700                into wsFoundWord2
247800                 delimiter in Word-Delimit
247900                  with pointer S-Pointer2.
248000*>
248100     subtract 2 from S-Pointer2 giving e.
248200     if       Word-Delimit = space
248300         and  SourceInWS (e:1) = "."
248400              move "." to Word-Delimit.
248500
248600     move     S-Pointer2 to e.
248700     if       Word-Delimit = "."
248800        and   (SourceInWS (e:1) = "9" or = "X" or = "A"
                                   or = "Z" or = "B")
248900              move s to S-Pointer2
249000              unstring SourceInWS delimited by " "
249100                into wsFoundWord2
249200                 delimiter in Word-Delimit
249300                  with pointer S-Pointer2
249400              end-unstring
249500              subtract 2 from S-Pointer2 giving e
249600              if  SourceInWS (e:1) = "."
249700                   move "." to Word-Delimit.
249800     if       wsf1-1 = "("
249900         and (wsFoundWord2 (2:1) = quote or = "'")
250000              add 2 to s giving S-Pointer2
250100              move wsFoundWord2 (2:1) to wsFoundWord2 (1:1)
250200                                         Word-Delimit2
250300              go to zz110-Get-A-Word-Literal2.
250400*>
250500     if       wsf1-1 = "("
250600         and  wsFoundWord2 (2:1) = space
250700              add 1 to S-Pointer2
250800              go to zz110-Get-A-Word.
250900     if       wsf1-1 = ")"
251100              go to zz110-Get-A-Word.
251200*>
251300     if       wsf1-1 not = quote and not = "'"
251400              perform  varying z from 255 by -1
251500                  until wsFoundWord2 (z:1) not = space
251600              end-perform
251700              move z to Word-Length
251800              go to zz110-Get-A-Word-Copy-Check.
251900*>
252000 zz110-Get-A-Word-Literal.
252100     move     wsf1-1 to Word-Delimit2.
252200     add      1 to s giving S-Pointer2.
252300 zz110-Get-A-Word-Literal2.
252400     move     spaces to wsFoundWord2 (2:254).
252500     unstring SourceInWS delimited by Word-Delimit2
252600              into wsFoundWord2 (2:254)
252700               delimiter in Word-Delimit
252800                with pointer S-Pointer2.
252900*>
253000*> so S-Pointer2 = " +1 & s = starter "
      *>     have we another Word-Delimit?
253200*>
253300     if       Word-Delimit not = Word-Delimit2
253400              perform  varying z from 255 by -1
253500                  until wsFoundWord2 (z:1) not = space
253600              end-perform
253700              add 1 to z
253800     else
253900              subtract s from S-Pointer2 giving z.
254000     move     Word-Delimit2 to wsFoundWord2 (z:1).
254100     move     z to Word-Length.
254200*>
254300*>  word is quoted literal or word so we are done
254400*>
254500     go       to zz110-Get-A-Word-Copy-Check.
254700 zz110-Get-A-Word-OverFlow.
254800     move     1 to S-Pointer2.
254900     perform  zz100-Get-A-Source-Record thru zz100-Exit.
255000     if       Source-Eof
255100              go to zz110-Exit.
255200     go       to zz110-Get-A-Word.
255400 zz110-Get-A-Word-Copy-Check.
255500*>
255600     add      1 to Source-Words.
255700     if we-are-testing
255800        display "zz110: WD=" word-delimit
255900                " WSF2=" wsfoundword2 (1:word-length).
           if       Word-Length < 1
                    display "zz110-GAWCH: Oops, zero length word"
                    display " Report this to support".
256100 zz110-Exit.
256200     exit.
256300*>
256400 zz120-Replace-Multi-Spaces.
256500*>**************************
256600*> remove any multi spaces within a source line
256700*>   find actual lengh of record in d
257000*>
257100*> run profiler against these routines and tidy 'em up if needed
257200*>
257300     perform  varying d from 255 by -1
257400                   until SourceInWS (d:1) not = space
257500     end-perform
257800     if       d < 1
257900              go to zz120-Exit.
258000*>
258100     move     zero to a b c.
258200     move     spaces to wsFoundNewWord5.
259900     perform  zz120-Kill-Space thru zz120-Kill-Space-Exit.
260000     move     spaces to SourceInWS.
260100     move     wsFoundNewWord5 (1:b) to SourceInWS.
260200     move     b to Line-End.
259300     if we-are-testing
259400        display "zz120A b=" b " after=" SourceInWS (1:b).
259500     go       to zz120-Exit.
260300*>
260400 zz120-Kill-Space.
260500     add      1 to a.
260600     if       a > d
260700              go to zz120-Kill-Space-Exit.
260800     if       SourceInWS (a:1) = space and c = 1
260900              add 1 to b
261000              move zero to c
261100              go to zz120-Kill-Space.
261200*>
261300     if       SourceInWS (a:1) = space
261400              go to zz120-Kill-Space.
261500     subtract 1 from a giving e.
261600     if       SourceInWS (a:1) = "("
261700         and  SourceInWS (e:1) not = space
261800         and  HoldWSorPD > 7
261900              add 2 to b
262000     else
262100              add 1 to b.
262200     move     SourceInWS (a:1) to wsFoundNewWord5 (b:1).
262300     move     1 to c.
262400     go       to zz120-Kill-Space.
262600 zz120-Kill-Space-Exit.
262700     exit.
262800*>
262900 zz120-Exit.
263000     exit.
263100*>
263200 zz130-Extra-Reserved-Word-Check.
263300*>*******************************
263400*>  Check for any other reserved words not in other checks
263500*>  note that max reserved word is 23 characters, so compare like 4 like
263600*>
263700     move     zero to a.
263800     search   all Reserved-Names
263900                  at end go to zz130-exit
264000              when Resvd-Word (Resvd-Idx) = wsFoundWord2 (1:23)
264100                set a to Resvd-Idx
264200                go to zz130-Exit.
264300     display  "Oops: logic error at zz130-reserved-word-check".
264400     display  "Problem with search verb".
139810     move     16 to return-code.
264500     goback.
264700 zz130-Exit.
264800     exit.
264900*>
265000 zz140-Function-Check.
265100*>********************
265200*> CALLS:  Only after moving all values to SortRecord and before
265300*>         write verb.
265400*>
265500*> Do we have an intrinsic function name
265600*>           if so modify sort rec for section printing
265700*> Note that P-oc-implemented = zero if not implemented,
265800*>    but treated as the same as its still a reserved word
265900*>
266000     move     zero to F-Pointer.
266100     search   all All-Functions
266200                  at end go to zz140-exit
266300              when P-function (All-Fun-Idx) = wsFoundNewWord4
266400                move 9 to SkaWSorPD
266500                move 1 to SkaWSorPD2
266600                set F-Pointer to All-Fun-Idx
266700                go to zz140-Exit.
266800     display  "Oops: logic error at zz140-function-check".
266900     display  "Problem with search verb".
139810     move     16 to return-code
267000     goback.
267200 zz140-Exit.
267300     exit.
267400*>
267500 zz150-WriteHdb.
           move     spaces to h1programid.
267600     accept   hddate from date.
267700     if       hddate not = "000000"
267800              move hd-y to hd2-y
267900              move hd-m to hd2-m
268000              move hd-d to hd2-d.
268100     accept   hdtime from time.
268200     if       hdtime not = "00000000"
268300              move hd-hh to hd2-hh
268400              move hd-mm to hd2-mm
268500              move hd-ss to hd2-ss
268600              move hd-uu to hd2-uu.
268700     string   HoldID delimited by space
268800              "    " delimited by size
268900              hd-date-time delimited by size
269000              into h1programid.
269100     move     function when-compiled to WS-When-Compiled.
269200     move     WS-WC-DD  to H1-DD.
269300     move     WS-WC-MM  to H1-MM.
269400     move     WS-WC-YY  to H1-YY.
269500     move     WS-WC-HH  to H1-HH.
269600     move     WS-WC-Min to H1-Min.
269700     move     spaces to PrintLine.
269800     write    PrintLine.
269900     write    PrintLine from hdr1.
270000     move     spaces to PrintLine.
270100     write    PrintLine.
270200 zz150-WriteHdb1.
270300     move     spaces to Hdr5-Prog-Name.
270400     string   HoldID delimited by space
270500              " (" delimited by size
270600              HoldID-Module delimited by space
270700              ")"  delimited by size
270800              into Hdr5-Prog-Name.
270900     move     Hdr5-Prog-Name to Hdr6-Hyphens.
271000     inspect  hdr6-hyphens replacing characters by "-"
271100              before initial "  ".
271200     write    PrintLine from hdr5-symbols.
271300     write    PrintLine from hdr6-symbols.
271400     go       to zz150-Exit.
271500 zz150-WriteHdb2.
271600     move     spaces to PrintLine.
271700     write    PrintLine.
271800     move     spaces to hdr7-variable.
271900     string   Full-Section-Name (WS-Anal1) delimited space
272000                ")" delimited by size into hdr7-variable.
272100     write    PrintLine from hdr7-ws.
272200     write    PrintLine from hdr3.
272300     move     spaces to PrintLine.
272400     write    PrintLine.
272500     go       to zz150-Exit.
272600 zz150-WriteHdb2b.
272700     move     spaces to PrintLine.
272800     write    PrintLine.
272900     move    "ALL GLOBALS)" to hdr7-variable.
273000     write    PrintLine from hdr7-ws.
273100     write    PrintLine from hdr3.
273200     move     spaces to PrintLine.
273300     write    PrintLine.
273400     go       to zz150-Exit.
273500 zz150-WriteHdb3.
273600     write    PrintLine from hdr8-ws.
273700     write    PrintLine from hdr3.
273800     move     spaces to PrintLine.
273900     write    PrintLine.
274000     go       to zz150-Exit.
274100 zz150-WriteHdb4.
274200     write    PrintLine from hdr9.
274300     move     spaces to PrintLine.
274400     write    PrintLine.
274500     go       to zz150-Exit.
274600 zz150-WriteHdb5.
274700     write    PrintLine from hdr10.
274800     move     spaces to PrintLine.
274900     write    PrintLine.
275000     go       to zz150-Exit.
274100 zz150-WriteHdb6.
274200     write    PrintLine from hdr9B.
274300     move     spaces to PrintLine.
274400     write    PrintLine.
274500     go       to zz150-Exit.
275100 zz150-WriteHdb7.
275200     write    PrintLine from hdr11.
275300     write    PrintLine from hdr12-hyphens.
275400     move     spaces to PrintLine.
275500     write    PrintLine.
274500     go       to zz150-Exit.
313100 zz150-WriteHdb8.
313200     write    PrintLine from hdr2.
313300     write    PrintLine from hdr3.
313400     move     spaces to PrintLine.
313500     write    PrintLine.
313600     go       to zz150-Exit.
275600 zz150-Exit.
275700     exit.
275800*>
275900 zz160-Clean-Number.
276000      move    zero to Build-Number.
276100      if      Word-Length = 1
276200              move wsf3-1 to Build-Number
276300              go to zz160-Exit.
276400      if      Word-Length = 2
276500              compute Build-Number =
276600                            (wsf3-1 * 10) +
276700                             wsf3-2.
276800 zz160-Exit.
276900     exit.
277000*>
277100 zz170-Check-4-Section.
277200     move     space to GotASection.
277300     if       HoldWSorPD = 8
277400              go to zz170-Exit.
277500     if       sv1what = Section-Name (1)
277600              move 1 to HoldWSorPD
277700              move "Y" to GotASection
277800     else
277900      if      sv1what = Section-Name (2)
278000              move 2 to HoldWSorPD
278100              move "Y" to GotASection
278200      else
278300       if     sv1what = Section-Name (3)
278400              move 3 to HoldWSorPD
278500              move "Y" to GotASection
278600       else
278700        if    sv1what = Section-Name (4)
278800              move 4 to HoldWSorPD
278900              move "Y" to GotASection
279000        else
279100         if   sv1what = Section-Name (5)
279200              move 5 to HoldWSorPD
279300              move "Y" to GotASection
279400         else
279500          if  sv1what = Section-Name (6)
279600              move 6 to HoldWSorPD
279700              move "Y" to GotASection
279800          else
279900           if sv1what = Section-Name (7)
280000              move 7 to HoldWSorPD
280100              move "Y" to GotASection
280200           else
280300            if sv1what = Section-Name (8)
280400              move 8 to HoldWSorPD
280500              move "Y" to GotASection
280600              move zero to HoldWSorPD2.
280700*>
280800*> Changed section so we can clear Global flag
280900*>
281000     if       GotASection = "Y"
281100              move zero to sw-Git.
281200 zz170-Exit.
281300     exit.
281400*>
281500 zz180-Open-Source-File.
281600*>*********************
281700*> get source filename
281800*>
281900     accept   Arg-Number from argument-number.
282000     if       Arg-Number > zero
282100              move zero to String-Pointer
282200              perform zz180-Get-Program-Args Arg-Number times
282300     else     go to zz180-Check-For-Param-Errors.
282400*>
282500*> setup source filename
282600*>    dont need the pointers - kill it after next test
282700     move     1 to String-Pointer.
282800     unstring Arg-Value (1) delimited by spaces
282900              into SourceFileName
283000               with pointer String-Pointer.
      *>
      *> Now get temp environment variable & build temp sort file names
      *>
           perform  zz182-Get-Env-Set-TempFiles thru zz182-Exit.
      *>
283200 zz180-Check-For-Param-Errors.
283400     if       SourceFileName = spaces or
283500              String-Pointer < 5
283600              display Prog-Name
283700              display "Copyright (C) 1967-2009 Vincent Bryan Coen"
283800              display " "
283900              display "Parameters are"
284000              display " "
284100              display "1: Source File name (Mandatory)"
284200              display "2: -R    Print out source code prior to xre
284300-             "ference listings in cobc free form"
284400              display "3: -L    reports in lowercase else upper"
284500              display "4: -TEST produces testing info"
284600              display "5: -DR   Display All reserved words & stop"
                    display "6: -G    produce only group xref: Comp. MF"
284700              display "7: -H    Display this help message"
284800              display "   --H   as -H"
                    move zero to return-code
284900              goback.
285000*>
285100     move     1 to String-Pointer String-Pointer2.
285200     unstring Arg-Value (1) delimited by "." into Prog-BaseName
285300              with pointer String-Pointer.
           if       Prog-BaseName = SourceFileName
285400              string  Prog-BaseName  delimited by space
285500              ".i"        delimited by size into SourceFileName.
285400     string   Prog-BaseName delimited by space
285500              ".lst"        delimited by size into Print-FileName
285600              with pointer String-Pointer2.
285700*>
285800*> Can now convert to upper-case as source filename is processed
285900*>
286000     move     function upper-case (Arg-Vals) to Arg-Vals.
286100*>
286200*> Check if help requested
286300*>
286400     if       "-H" = Arg-Value (2) or Arg-Value (3)
286500           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
286600              move zero to String-Pointer
286700              go to zz180-Check-For-Param-Errors.
286800     if       "--H" = Arg-Value (2) or Arg-Value (3)
286900           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
287000              move zero to String-Pointer
287100              go to zz180-Check-For-Param-Errors.
287200*>
287300*> Check v2 if we are listing the source
287400*>
287500      if      "-R" = Arg-Value (2) or Arg-Value (3)
287600           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
287700              move "Y" to sw-2.
287800*>
287900*> Check v4 if we are dumping all reserved words
288000*>
288100     if       "-DR" = Arg-Value (2) or Arg-Value (3)
288200           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
288300              move 1 to sw-4
288400              go to zz180-Exit.
288500*>
288600*> Check v5 if we are testing
288700*>
288800     if       "-TEST" = Arg-Value (2) or Arg-Value (3)
288900           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
289000              display " extra information for testing"
289100              move "Y" to sw-5.
289200*>
289300*> Check v6 if we are are doing Lower case reports insted of upper
289400*>
289500     if       "-L" = Arg-Value (2) or Arg-Value (3)
289600           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
289700              move 1 to sw-6.
      *>***************************************************************
      *>  THIS BLOCK FOR TESING and Comparing listing against MF etc  *
289800*>***************************************************************
330200*
330300* Check v1 if we are are only doing a group xref ie W-S and procedure
330400*
330500     if       "-G " = Arg-Value (2) or Arg-Value (3)
330600           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
330900              move "A" to sw-1.
      *>***************************************************************
      *>    END OF SPECIAL TEST BLOCK but with bc030 - bc080 also     *
      *>***************************************************************
289900     open     input SourceInput.
290000     if       fs-reply not = "00"
290100              display Msg9
                    move 16 to return-code
290200              goback.
290400     go       to zz180-Exit.
290500*>
290600 zz180-Get-Program-Args.
290700     add      1 to String-Pointer.
290800     accept   Arg-Value (String-Pointer) from argument-value.
290900*>
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
       zz182-Exit.
           Exit.
      *>
291000 zz180-Exit.
291100     exit.
291200*>
291300 zz190-Init-Program.
291400*>
291500*>****************************************************************
291600*> initialise all Variables should we be processing nested modules
291700*>****************************************************************
291800*>
291900     move     spaces to PrintLine Global-Current-Word SortRecord
292000              saveSkaDataName SourceFileName Print-FileName
292100              wsFoundNewWord4 wsFoundNewWord3
292200              wsFoundNewWord2 wsFoundNewWord.
292400     move     high-values to Condition-Table.
           move     10 to Con-Tab-Size.
292600     move     zeros to GotEndProgram sw-Source-Eof
292700              Section-Used-Table
292800              HoldWSorPD HoldWSorPD2 Con-Tab-Count.
293000     move     1 to S-Pointer F-Pointer S-Pointer2 S-Pointer3
293100                   S-Pointer4.
293300 zz190-Exit.
293400     exit.
293500*>
293600 zz200-Load-Git.
293700*>
293800*> Load the Global Item Table with item associated with 01/FD Global
293900*>
294000     if       Global-Current-Level = high-values
294100              go to zz200-Exit.
294200     add      1 to Git-Table-Count.
294300     if       Git-Table-Count > Git-Table-Size
294400         and  Git-Table-Size < 10000
294500              add 10 to Git-Table-Size.
294600     if       Git-Table-Size > 10000
294700              move 10001 to Git-Table-Size        *> just in case
294800              display Msg10
294900              go to zz200-Exit.
295000     move     Global-Current-Word to Git-Word (Git-Table-Count).
295010     move     space to Git-In-Use-Flag (Git-Table-Count).
295100     move     Global-Current-RefNo to Git-RefNo (Git-Table-Count).
295200     move     Build-Number to Git-Build-No (Git-Table-Count).
295300     move     HoldID to Git-Prog-Name (Git-Table-Count).
295400     move     HoldWSorPD  to Git-HoldWSorPD (Git-Table-Count).
295500     move     HoldWSorPD2 to Git-HoldWSorPD2 (Git-Table-Count).
296100 zz200-Exit.
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
       zz319-Exit.
           exit.