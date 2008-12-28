000100 Identification division.
000200 program-id.           cobxref.
000300*author.               Vincent Bryan Coen, Applewood Computers, UK.
000400*date-written.         28 July 1983 with code going back to 1967.
000500*date-rewriten.        10 March 2007 with code going back to 1967.
000600*date-compiled.        Today.
000700*Security.             Copyright (C) 1967-2009, Vincent Bryan Coen.
000800*                      Distributed under the GNU General Public License
000900*                      v2.0. Only.
001000*                      See the file COPYING for details.
001100*
001200* Usage.               Cobol Cross Referencer for Open Cobol from v1.0.
001300*
001400* Changes.             As of 16-12-2008 see Changelog.
001500**************************************************************************
001600*
001700* Copyright Notice.
001800******************
001900*
002000* This file/program is part of Cobxref and is copyright (c) Vincent B Coen.
002100*
002200* This program is free software; you can redistribute it and/or modify it
002300* under the terms of the GNU General Public License as published by the
002400* Free Software Foundation; version 2.
002500*
002600* Cobxref is distributed in the hope that it will be useful, but WITHOUT
002700* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
002800* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
002900* for more details.
003000*
003100* You should have received a copy of the GNU General Public License along
003200* with Cobxref; see the file COPYING.  If not, write to the Free Software
003300* Foundation, 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
003400**************************************************************************
003500*
003600 environment division.
003700 configuration section.
003800 source-computer.      linux.
003900 object-computer.      linux.
004000 special-names.
004100* This lot is not needed by prog but used to see if OC accepts them
004200      switch-1 is sn-Test-1 on snt1-on off snt1-off.
004300*      uspi-0 is sn-Test-2 on snt2-on off snt2-off.
004400*      currency sign is "£".
004500*      decimal-point is comma.
004600*      call-convention 1 is cc-fred.
004700*      console is crt
004800*       cursor is fs-reply
004900*       crt status fs-reply.
005000*     command-line is prog-param-line.
005100*      argument-value is prog-param-values.
005200*      argument-number is prog-param-count.
005300 input-Output section.
005400 file-control.
005500*
005600     select Supplemental-Part2-In assign "Part2.tmp"
005700         organization line sequential.
005800*
005900     select Supplemental-Part1-Out assign "Part1.tmp"
006000         organization line sequential.
006100*
006200     select Source-Listing assign Print-FileName
006300         organization line sequential.
006400*
006500     select SourceInput assign SourceFileName
006600         organization line sequential
006700         file status fs-reply.
006800*
006900     select SortFile assign "sort1tmp".
007000*
007100 i-o-control.
007200*
007300     same record area for Supplemental-Part1-Out
007400                          Supplemental-Part2-In.
007500/
007600 data division.
007700 file section.
007800 fd  Source-Listing.
007900 01  Source-List.
008000     03  sl-Gen-RefNo1     pic z(5)9bb.
008100     03  SourceOutput      pic x(162).
008200*
008300 01  PrintLine.
008400     02  XrDataName        pic x(33).
008500     02  XrDefn            pic 9(6).
008600     02  XrType            pic x.
008700     02  filler            pic xx.
008800     02  filler     occurs 8.
008900       03  XrReference     pic 9(6).
009000       03  filler          pic x.
009100     02  filler            pic x(22).
009200*
009300 01  filler.
009400     03  filler            pic x(42).
009500     03  PL-Prog-Name      pic x(30).
009600*
009700 01  PrintLine2.
009800     03  P-Conditions      pic x(31).
009900     03  P-Variables       pic x(31).
010000*
010100 fd  SourceInput.
010200*
010300 01  SourceRecIn           pic x(160).
010400*
010500 fd  Supplemental-Part1-Out.
010600*
010700 01  SortRecord.
010800     03  SkaDataName       pic x(32).
010900     03  SkaWSorPD         pic 9.
011000     03  SkaWSorPD2        pic 9.
011100     03  SkaRefNo          pic 9(6).
011200*
011300 fd  Supplemental-Part2-In.
011400*
011500 01  filler                pic x(40).
011600*
011700 sd  SortFile.
011800 01  filler.
011900     03  SdSortKey         pic x(40).
012000/
012100 working-storage section.
012200 77  Prog-Name             pic x(13) value "Xref v0.95.15".
012300 77  String-Pointer        pic s9(5) comp  value 1.
012400 77  String-Pointer2       pic s9(5) comp  value 1.
012500 77  S-Pointer             pic s9(5) comp  value zero.
012600 77  S-Pointer2            pic s9(5) comp  value zero.
012700 77  S-Pointer3            pic s9(5) comp  value zero.
012800 77  S-Pointer4            pic s9(5) comp  value zero.
012900 77  Line-Count            pic s9(5) comp  value 70.
013000 77  Word-Length           pic s9(5) comp  value zero.
013100 77  Line-End              pic s9(5) comp  value zero.
013200 77  Source-Line-End       pic s9(5) comp  value zero.
013300 77  Source-Words          pic s9(5) comp  value zero.
013400 77  F-Pointer             pic s9(5) comp  value zero.
013500 77  Arg-Number            pic 99          value zero.
013600 77  Gen-RefNo1            pic 9(6)        value zero.
013700 77  Build-Number          pic 9(6)        value zero.
013800 77  Saved-Build-Number    pic 9(6)        value zero.
013900 77  Saved-a               pic s9(5) comp  value zero.
014000 77  a                     pic s9(5) comp  value zero.
014100 77  b                     pic s9(5) comp  value zero.
014200 77  c                     pic s9(5) comp  value zero.
014300 77  d                     pic s9(5) comp  value zero.
014400 77  e                     pic s9(5) comp  value zero.
014500 77  s                     pic s9(5) comp  value zero.
014600 77  t                     pic s9(5) comp  value zero.
014700 77  v                     pic s9(5) comp  value zero.
014800 77  y                     pic s9(5) comp  value zero.
014900 77  y2                    pic s9(5) comp  value zero.
015000 77  z                     pic s9(5) comp  value zero.
015100 77  q                     pic s9(5) comp  value zero.
015200*
015300* System parameters control how xref works or reports
015400*  May be add extra func for default.conf ?
015500*
015600 77  sw-1                  pic x           value "N".
015700*  command line input -G, -GA or -GB
015800  88 Group-Report-Only                     value "Y".
015900  88 Both-Reports                          value "B".
016000  88 All-Reports                           value "A".
016100  88 Block-Group                           value "C".
016200 77  sw-2                  pic x           value "N".
016300  88 List-Source                           value "Y".
016400 77  sw-3                  pic x           value space.
016500  88  Do-One-Only                          value "Y".
016600*  Command line input -Test
016700 77  sw-5                  pic x           value "N".
016800  88 We-Are-Testing                        value "Y".
016900*  Command line input -L
017000 77  sw-6                  pic 9           value zero.
017100  88  Reports-In-Lower                     value 1.
017200 77  sw-7                  pic 9           value zero.
017300  88  Condition-Sort                       value 1.
017400 77  sw-8                  pic 9           value zero.
017500  88  Dump-Reserved-Words                  value 1.
017600 77  sw-Source-Eof         pic 9           value 0.
017700  88 Source-Eof                            value 1.
017800 77 sw-11                  pic x           value "N".
017900  88 Verbose-Output                        value "Y".
018000 77  sw-End-Prog           pic 9           value zero.
018100  88 End-Prog                              value 1.
018200 77  sw-Had-End-Prog       pic 9           value zero.
018300  88 Had-End-Prog                          value 1.
018400 77  sw-Git                pic 9           value zero.
018500  88 Global-Active                         value 1.
018600*  Multi modules in one source file flag
018700 77  sw-Nested             pic 9           value zero.
018800  88 Have-Nested                           value 1.
018900*
019000 77  Word-Delimit          pic x           value space.
019100 77  Word-Delimit2         pic x           value space.
019200 77  GotASection           pic x           value space.
019300 77  GotEndProgram         pic 9           value zero.
019400 77  HoldWSorPD            pic 9           value 0.
019500 77  HoldWSorPD2           pic 9           value 0.
019600 77  HoldFoundWord         pic x(40)       value spaces.
019700 77  Save-Res-Word         pic x(23)       value spaces.
019800 77  saveSkaDataName       pic x(32)       value spaces.
019900 77  Saved-Variable        pic x(30)       value spaces.
020000 77  saveSkaWSorPD         pic 9           value zero.
020100 77  saveSkaWSorPD2        pic 9           value zero.
020200 77  WS-Anal1              pic 9           value zero.
020300 77  line-word-1           pic 9           value zero.
020400 77  fs-reply              pic xx          value zeros.
020500 77  SourceFileName        pic x(64)       value spaces.
020600 77  Print-FileName        pic x(64)       value spaces.
020700 77  Prog-BaseName         pic x(60)       value spaces.
020800 77  Global-Current-Word   pic x(30)       value spaces.
020900 77  Global-Current-Refno  pic 9(6)        value zero.
021000 77  Global-Current-Level  pic 99          value zero.
021100/
021200 01  HoldID                pic x(30)       value spaces.
021300 01  HoldID-Module         pic x(30)       value spaces.
021400*
021500* Note that SourceInWS has extra 7 chars for free format source.
021600*   and no I don't remember why
021700*
021800 01  SourceInWS.
021900     03  cobolseqno        pic x(6).
022000     03  filler            pic x.
022100     03  SourceIn8-160.
022200         05  sv1what       pic x(16).
022300         05  filler        pic x(144).
022500*
022600 01  wsFoundWord.
022700     03  wsf1-3.
022800      04  wsf1-2.
022900       05  wsf1-1          pic x.
023000       05  filler          pic x.
023100      04  filler           pic x.
023200     03  filler            pic x.
023300     03  filler            pic x(158).
023400*
023500 01  wsFoundWord2 redefines wsFoundWord.
023600     03  wsf3-1            pic 9.
023700     03  wsf3-2            pic 9.
023800     03  filler            pic x(160).
023900*
024000 01  wsFoundNewWord        pic x(32).
024100 01  wsFoundNewWord2       pic x(32).
024200 01  wsFoundNewWord3       pic x(162).
024300 01  wsFoundNewWord4       pic x(32).
024400 01  wsFoundNewWord5       pic x(160).
024500*
024600 01  HDR1.
024700     03  filler            pic X(26)
024800                               value "ACS Cobol Cross Reference ".
024900     03  H1Prog-Name       pic x(14).
025000     03  filler            pic x    value "(".
025100     03  H1-dd             pic xx.
025200     03  filler            pic x     value "/".
025300     03  H1-MM             pic xx.
025400     03  filler            pic x     value "/".
025500     03  H1-YY             pic x(4).
025600     03  filler            pic x   value "@".
025700     03  H1-HH             pic xx.
025800     03  filler            pic x     value ":".
025900     03  H1-Min            pic xx.
026000     03  filler            pic xx   value ") ".
026100     03  filler            pic x(20) value "Dictionary file for ".
026200     03  h1programid       pic x(60).
026300*
026400 01  HDR2.
026500     03  filler            pic X(34) value "All Data/Proc Names".
026600     03  filler            pic X(19) value "Defn     Reference".
026700*
026800 01  hdr3.
026900     03  filler            pic x(33) value all "-".
027000     03  filler            pic x     value "+".
027100     03  filler            pic x(63) value all "-".
027200*
027300 01  hdr5-symbols.
027400     03  filler            pic x(19) value "Symbols of module: ".
027500     03  hdr5-Prog-Name    pic x(67) value spaces.
027600*
027700 01  hdr6-symbols.
027800     03  filler            pic x(19) value "-------------------".
027900*
028000* below is replaced with hyphens to size of Prog-Name
028100*
028200     03  hdr6-hyphens      pic x(67) value spaces.
028300*
028400 01  hdr7-ws.
028500     03  filler            pic x(14) value "Data Section (".
028600     03  hdr7-variable     pic x(20) value spaces.
028700     03  filler            pic x(8)  value "Defn".
028800     03  filler            pic x(9)  value "Locations".
028900*
029000 01  hdr8-ws.
029100     03  hdr8-hd           pic x(9)  value "Procedure".
029200     03  filler            pic x(25) value spaces.
029300     03  filler            pic x(8)  value "Defn".
029400     03  filler            pic x(9)  value "Locations".
029500*
029600 01  hdr9.
029700     03  filler            pic x(36)
029800                     value "Unreferenced Working Storage symbols".
029900*
030000 01  hdr10.
030100     03  filler            pic x(23)
030200                                  value "Unreferenced Procedures".
030300*
030400 01  hdr11.
030500     03  filler            pic x(31) value "Variable tested".
030600     03  filler            pic x(8)  value "Symbol (".
030700     03  filler            pic x(23) value "88-Conditions)".
030800*
030900 01  hdr12-hyphens.
031000     03  filler            pic x(62) value all "-".
031100*
031200 01  hdtime                       value spaces.
031300     03  hd-hh             pic xx.
031400     03  hd-mm             pic xx.
031500     03  hd-ss             pic xx.
031600     03  hd-uu             pic xx.
031700 01  hddate                       value spaces.
031800     03  hd-y              pic xx.
031900     03  hd-m              pic xx.
032000     03  hd-d              pic xx.
032100*
032200 01  hd-date-time.
032300     03  hd2-d             pic xx.
032400     03  filler            pic x   value "/".
032500     03  hd2-m             pic xx.
032600     03  filler            pic x   value "/".
032700     03  hd2-y             pic xx.
032800     03  filler            pic xx  value spaces.
032900     03  hd2-hh            pic xx.
033000     03  filler            pic x   value ":".
033100     03  hd2-mm            pic xx.
033200     03  filler            pic x   value ":".
033300     03  hd2-ss            pic xx.
033400     03  filler            pic x   value ":".
033500     03  hd2-uu            pic xx.
033600*
033700 01  WS-When-Compiled.
033800     03  WS-WC-YY          pic x(4).
033900     03  WS-WC-MM          pic xx.
034000     03  WS-WC-DD          pic xx.
034100     03  WS-WC-HH          pic xx.
034200     03  WS-WC-Min         pic xx.
034300     03  filler            pic x(9).
034400*
034500 01  Error-messages.
034600     03 Msg1      pic x(28) value "Aborting: No records present".
034700     03 Msg2      pic x(29) value "Aborting: Early eof on source".
034800     03 Msg4      pic x(42)
034900               value "Logic Error:Lost1 wsFoundWord2 numeric? = ".
035000     03 Msg5      pic x(32) 
035100                     value "Logic Error:Lost2 wsFoundWord2 =".
035200     03 Msg6      pic x(34)
035300                     value "Error: Con table size needs > 5000".
035400     03 Msg7      pic x(24) value "bb050 Error: Logic error".
035500     03 Msg8      pic x(26) value "Error: Eof on source again".
035600     03 Msg9      pic x(34) 
035700                    value "Error: File not present Try Again!".
035800     03 Msg10     pic x(36) 
035900                    value "Error: Git Table size exceeds 10,000".
036000     03 Msg16     pic x(66)  value "Error: Eof on source possible 
036100-              "logic error at aa047 ASSUMING again".
036200*
036300 01  SectTable.
036400     03  filler            pic x(9) value "FWLKCRSPI".
036500 01  filler  redefines SectTable.
036600     03  LSect             pic x  occurs 9.
036700* Keep track of sections used in analysed module
036800 01  Section-Used-Table  value zeros.
036900     03  USect             pic 9  occurs 9.
037000* holds program parameter values from command line
037100 01  Arg-Vals                       value spaces.
037200     03  Arg-Value         pic x(128)  occurs 10.
037300*
037400 01  Section-Names-Table.
037500     03  filler pic x(24) value "FILE SECTION.           ".
037600     03  filler pic x(24) value "WORKING-STORAGE SECTION.".
037700     03  filler pic x(24) value "LOCAL-STORAGE SECTION.  ".
037800     03  filler pic x(24) value "LINKAGE SECTION.        ".
037900     03  filler pic x(24) value "COMMUNICATION SECTION.  ".
038000     03  filler pic x(24) value "REPORT SECTION.         ".
038100     03  filler pic x(24) value "SCREEN SECTION.         ".
038200     03  filler pic x(24) value "PROCEDURE DIVISION.     ".
038300 01  filler   redefines Section-Names-Table.
038400     03  Full-Section-Name          occurs 8.
038500         05  Section-Name  pic x(16).
038600         05  filler        pic x(08).
038700*
038800* Here for cb_intrinsic_table in OC see :
038900*   cobc/reserved.c in the open-cobol source directory but
039000*    Totally ingoring the system_table as not needed/used by xref
039100*
039200* Also note that the number 0 or 1 indicates if the 
039300*  function/reserved word is implemented in Open Cobol
039400*   but xref treats all as being reserved except 'E' (see below)
039500*     as I don't know how to handle that one
039600*
039700 01  Function-Table.
039800     03  filler pic x(28) value "1ABS                        ".
039900     03  filler pic X(28) value "1ACOS                       ".
040000     03  filler pic X(28) value "1ANNUITY                    ".
040100     03  filler pic X(28) value "1ASIN                       ".
040200     03  filler pic X(28) value "1ATAN                       ".
040300     03  filler pic X(28) value "0BOOLEAN-OF-INTEGER         ".
040400     03  filler pic X(28) value "1BYTE-LENGTH                ".
040500     03  filler pic X(28) value "1CHAR                       ".
040600     03  filler pic X(28) value "0CHAR-NATIONAL              ".
040700     03  filler pic X(28) value "1COMBINED-DATETIME          ".
040800     03  filler pic X(28) value "1COS                        ".
040900     03  filler pic X(28) value "1CURRENT-DATE               ".
041000     03  filler pic X(28) value "1DATE-OF-INTEGER            ".
041100     03  filler pic X(28) value "1DATE-TO-YYYYMMDD           ".
041200     03  filler pic X(28) value "1DAY-OF-INTEGER             ".
041300     03  filler pic X(28) value "1DAY-TO-YYYYDDD             ".
041400     03  filler pic X(28) value "0DISPLAY-OF                 ".
041500*
041600* Can't deal with the next one so rem'd out
041700*    Alright so, I don't know how to!
041800*
041900*     03  filler pic X(28) value "0E                          ".
042000     03  filler pic X(28) value "1EXCEPTION-FILE             ".
042100     03  filler pic X(28) value "0EXCEPTION-FILE-N           ".
042200     03  filler pic X(28) value "1EXCEPTION-LOCATION         ".
042300     03  filler pic X(28) value "0EXCEPTION-LOCATION-N       ".
042400     03  filler pic X(28) value "1EXCEPTION-STATEMENT        ".
042500     03  filler pic X(28) value "1EXCEPTION-STATUS           ".
042600     03  filler pic X(28) value "1EXP                        ".
042700     03  filler pic X(28) value "1EXP10                      ".
042800     03  filler pic X(28) value "1FACTORIAL                  ".
042900     03  filler pic X(28) value "1FRACTION-PART              ".
043000     03  filler pic X(28) value "0HIGHEST-ALGEBRAIC          ".
043100     03  filler pic X(28) value "1INTEGER                    ".
043200     03  filler pic X(28) value "0INTEGER-OF-BOOLEAN         ".
043300     03  filler pic X(28) value "1INTEGER-OF-DATE            ".
043400     03  filler pic X(28) value "1INTEGER-OF-DAY             ".
043500     03  filler pic X(28) value "1INTEGER-PART               ".
043600     03  filler pic X(28) value "1LENGTH                     ".
043700     03  filler pic X(28) value "0LOCALE-COMPARE             ".
043800     03  filler pic X(28) value "1LOCALE-DATE                ".
043900     03  filler pic X(28) value "1LOCALE-TIME                ".
044000     03  filler pic X(28) value "1LOCALE-TIME-FROM-SECONDS   ".
044100     03  filler pic X(28) value "1LOG                        ".
044200     03  filler pic X(28) value "1LOG10                      ".
044300     03  filler pic X(28) value "1LOWER-CASE                 ".
044400     03  filler pic X(28) value "0LOWEST-ALGEBRAIC           ".
044500     03  filler pic X(28) value "1MAX                        ".
044600     03  filler pic X(28) value "1MEAN                       ".
044700     03  filler pic X(28) value "1MEDIAN                     ".
044800     03  filler pic X(28) value "1MIDRANGE                   ".
044900     03  filler pic X(28) value "1MIN                        ".
045000     03  filler pic X(28) value "1MOD                        ".
045100     03  filler pic X(28) value "0NATIONAL-OF                ".
045200     03  filler pic X(28) value "1NUMVAL                     ".
045300     03  filler pic X(28) value "1NUMVAL-C                   ".
045400     03  filler pic X(28) value "0NUMVAL-F                   ".
045500     03  filler pic X(28) value "1ORD                        ".
045600     03  filler pic X(28) value "1ORD-MAX                    ".
045700     03  filler pic X(28) value "1ORD-MIN                    ".
045800     03  filler pic X(28) value "0PI                         ".
045900     03  filler pic X(28) value "1PRESENT-VALUE              ".
046000     03  filler pic X(28) value "1RANDOM                     ".
046100     03  filler pic X(28) value "1RANGE                      ".
046200     03  filler pic X(28) value "1REM                        ".
046300     03  filler pic X(28) value "1REVERSE                    ".
046400     03  filler pic X(28) value "1SECONDS-FROM-FORMATTED-TIME".
046500     03  filler pic X(28) value "1SECONDS-PAST-MIDNIGHT      ".
046600     03  filler pic X(28) value "1SIGN                       ".
046700     03  filler pic X(28) value "1SIN                        ".
046800     03  filler pic X(28) value "1SQRT                       ".
046900     03  filler pic X(28) value "0STANDARD-COMPARE           ".
047000     03  filler pic X(28) value "1STANDARD-DEVIATION         ".
047100     03  filler pic X(28) value "1STORED-CHAR-LENGTH         ".
047200     03  filler pic X(28) value "1SUBSTITUTE                 ".
047300     03  filler pic X(28) value "1SUM                        ".
047400     03  filler pic X(28) value "1TAN                        ".
047500     03  filler pic X(28) value "1TEST-DATE-YYYYMMDD         ".
047600     03  filler pic X(28) value "1TEST-DAY-YYYYDDD           ".
047700     03  filler pic X(28) value "0TEST-NUMVAL                ".
047800     03  filler pic X(28) value "0TEST-NUMVAL-C              ".
047900     03  filler pic X(28) value "0TEST-NUMVAL-F              ".
048000     03  filler pic X(28) value "1TRIM                       ".
048100     03  filler pic X(28) value "1UPPER-CASE                 ".
048200     03  filler pic X(28) value "1VARIANCE                   ".
048300     03  filler pic X(28) value "1WHEN-COMPILED              ".
048400     03  filler pic X(28) value "1YEAR-TO-YYYY               ".
048500*
048600 01  filler redefines Function-Table.
048700     03  All-Functions                 occurs 82
                     ascending key P-Function indexed by All-Fun-Idx.
048800         05  P-oc-implemented pic x.
048900         05  P-Function       pic x(27).
049000 01  Function-Table-Size   pic s99  comp  value 82.
049100*
049200* Note that system names are omitted so thatr they turn up
049300*  in the cross refs
049400*
049500* Here for all reserved words in OC see :
049600*           struct reserved reserved_words in
049700*   cobc/reserved.c in the open-cobol source directory
049800*
049900 01  Additional-Reserved-Words.
050000     03  filler pic x(24) value "1ACCEPT             ".
050100     03  filler pic x(24) value "1ACCESS             ".
050200     03  filler pic x(24) value "0ACTIVE-CLASS       ".
050300     03  filler pic x(24) value "1ADD                ".
050400     03  filler pic x(24) value "1ADDRESS            ".
050500     03  filler pic x(24) value "1ADVANCING          ".
050600     03  filler pic x(24) value "1AFTER              ".
050700     03  filler pic x(24) value "0ALIGNED            ".
050800     03  filler pic x(24) value "1ALL                ".
050900     03  filler pic x(24) value "1ALLOCATE           ".
051000     03  filler pic x(24) value "1ALPHABET           ".
051100     03  filler pic x(24) value "1ALPHABETIC         ".
051200     03  filler pic x(24) value "1ALPHABETIC-LOWER   ".
051300     03  filler pic x(24) value "1ALPHABETIC-UPPER   ".
051400     03  filler pic x(24) value "1ALPHANUMERIC       ".
051500     03  filler pic x(24) value "1ALPHANUMERIC-EDITED".
051600     03  filler pic x(24) value "1ALSO".
051700     03  filler pic x(24) value "1ALTER".
051800     03  filler pic x(24) value "1ALTERNATE".
051900     03  filler pic x(24) value "1AND".
052000     03  filler pic x(24) value "1ANY".
052100     03  filler pic x(24) value "0ANYCASE".
052200     03  filler pic x(24) value "1ARE".
052300     03  filler pic x(24) value "1AREA".
052400     03  filler pic x(24) value "1AREAS".
052500     03  filler pic x(24) value "1ARGUMENT-NUMBER".
052600     03  filler pic x(24) value "1ARGUMENT-VALUE".
052700     03  filler pic x(24) value "0ARITHMETIC".
052800     03  filler pic x(24) value "1AS".
052900     03  filler pic x(24) value "1ASCENDING".
053000     03  filler pic x(24) value "1ASSIGN".
053100     03  filler pic x(24) value "1AT".
053200     03  filler pic x(24) value "0ATTRIBUTE".
053300     03  filler pic x(24) value "1AUTO".
053400     03  filler pic x(24) value "1AUTO-SKIP".
053500     03  filler pic x(24) value "1AUTOMATIC".
053600     03  filler pic x(24) value "1AUTOTERMINATE".
053700     03  filler pic x(24) value "0B-AND".
053800     03  filler pic x(24) value "0B-NOT".
053900     03  filler pic x(24) value "0B-OR".
054000     03  filler pic x(24) value "0B-XOR".
054100     03  filler pic x(24) value "1BACKGROUND-COLOR".
054200     03  filler pic x(24) value "1BASED".
054300     03  filler pic x(24) value "1BELL".
054400     03  filler pic x(24) value "1BEFORE".
054500     03  filler pic x(24) value "1BELL".
054600     03  filler pic x(24) value "1BINARY".
054700     03  filler pic x(24) value "1BINARY-CHAR".
054800     03  filler pic x(24) value "1BINARY-DOUBLE".
054900     03  filler pic x(24) value "1BINARY-LONG".
055000     03  filler pic x(24) value "1BINARY-SHORT".
055100     03  filler pic x(24) value "0BIT".
055200     03  filler pic x(24) value "1BLANK".
055300     03  filler pic x(24) value "1BLINK".
055400     03  filler pic x(24) value "1BLOCK".
055500     03  filler pic x(24) value "0BOOLEAN".
055600     03  filler pic x(24) value "1BOTTOM".
055700     03  filler pic x(24) value "1BY".
055800     03  filler pic x(24) value "0BYTE-LENGTH".
055900     03  filler pic x(24) value "1CALL".
056000     03  filler pic x(24) value "1CANCEL".
056100     03  filler pic x(24) value "0CD".
056200     03  filler pic x(24) value "0CENTER".
056300     03  filler pic x(24) value "0CF".
056400     03  filler pic x(24) value "0CH".
056500     03  filler pic x(24) value "0CHAIN".
056600     03  filler pic x(24) value "1CHAINING".
056700     03  filler pic x(24) value "1CHARACTER".
056800     03  filler pic x(24) value "1CHARACTERS".
056900     03  filler pic x(24) value "1CLASS".
057000     03  filler pic x(24) value "0CLASS-ID".
057100     03  filler pic x(24) value "0CLASSIFICATION".
057200     03  filler pic x(24) value "1CLOSE".
057300     03  filler pic x(24) value "0CODE".
057400     03  filler pic x(24) value "1CODE-SET".
057500     03  filler pic x(24) value "1COL".
057600     03  filler pic x(24) value "1COLLATING".
057700     03  filler pic x(24) value "1COLS".
057800     03  filler pic x(24) value "1COLUMN".
057900     03  filler pic x(24) value "1COLUMNS".
058000     03  filler pic x(24) value "1COMMA".
058100     03  filler pic x(24) value "1COMMAND-LINE".
058200     03  filler pic x(24) value "1COMMIT".
058300     03  filler pic x(24) value "1COMMON".
058400     03  filler pic x(24) value "0COMMUNICATION".
058500     03  filler pic x(24) value "1COMP".
058600     03  filler pic x(24) value "1COMP-1".
058700     03  filler pic x(24) value "1COMP-2".
058800     03  filler pic x(24) value "1COMP-3".
058900     03  filler pic x(24) value "1COMP-4".
059000     03  filler pic x(24) value "1COMP-5".
059100     03  filler pic x(24) value "1COMP-X".
059200     03  filler pic x(24) value "1COMPUTATIONAL".
059300     03  filler pic x(24) value "1COMPUTATIONAL-1".
059400     03  filler pic x(24) value "1COMPUTATIONAL-2".
059500     03  filler pic x(24) value "1COMPUTATIONAL-3".
059600     03  filler pic x(24) value "1COMPUTATIONAL-4".
059700     03  filler pic x(24) value "1COMPUTATIONAL-5".
059800     03  filler pic x(24) value "1COMPUTATIONAL-X".
059900     03  filler pic x(24) value "1COMPUTE".
060000     03  filler pic x(24) value "0CONDITION".
060100     03  filler pic x(24) value "1CONFIGURATION".
060200     03  filler pic x(24) value "1CONSTANT".
060300     03  filler pic x(24) value "1CONTAINS".
060400     03  filler pic x(24) value "1CONTENT".
060500     03  filler pic x(24) value "1CONTINUE".
060600     03  filler pic x(24) value "0CONTROL".
060700     03  filler pic x(24) value "0CONTROLS".
060800     03  filler pic x(24) value "1CONVERTING".
060900     03  filler pic x(24) value "1COPY".
061000     03  filler pic x(24) value "1CORR".
061100     03  filler pic x(24) value "1CORRESPONDING".
061200     03  filler pic x(24) value "1COUNT".
061300     03  filler pic x(24) value "1CRT".
061400     03  filler pic x(24) value "1CURRENCY".
061500     03  filler pic x(24) value "1CURSOR".
061600     03  filler pic x(24) value "1CYCLE".
061700     03  filler pic x(24) value "1DATA".
061800     03  filler pic x(24) value "0DATA-POINTER".
061900     03  filler pic x(24) value "1DATE".
062000     03  filler pic x(24) value "1DAY".
062100     03  filler pic x(24) value "1DAY-OF-WEEK".
062200     03  filler pic x(24) value "0DE".
062300     03  filler pic x(24) value "1DEBUGGING".
062400     03  filler pic x(24) value "1DECIMAL-POINT".
062500     03  filler pic x(24) value "1DECLARATIVES".
062600     03  filler pic x(24) value "1DEFAULT".
062700     03  filler pic x(24) value "1DELETE".
062800     03  filler pic x(24) value "1DELIMITED".
062900     03  filler pic x(24) value "1DELIMITER".
063000     03  filler pic x(24) value "1DEPENDING".
063100     03  filler pic x(24) value "1DESCENDING".
063200     03  filler pic x(24) value "0DESTINATION".
063300     03  filler pic x(24) value "0DETAIL".
063400     03  filler pic x(24) value "0DISABLE".
063500     03  filler pic x(24) value "1DISK".
063600     03  filler pic x(24) value "1DISPLAY".
063700     03  filler pic x(24) value "1DIVIDE".
063800     03  filler pic x(24) value "1DIVISION".
063900     03  filler pic x(24) value "1DOWN".
064000     03  filler pic x(24) value "1DUPLICATES".
064100     03  filler pic x(24) value "1DYNAMIC".
064200     03  filler pic x(24) value "1EBCDIC".
064300     03  filler pic x(24) value "0EC".
064400     03  filler pic x(24) value "0EGI".
064500     03  filler pic x(24) value "1ELSE".
064600     03  filler pic x(24) value "0EMI".
064700     03  filler pic x(24) value "0ENABLE".
064800     03  filler pic x(24) value "1END".
064900     03  filler pic x(24) value "1END-ACCEPT".
065000     03  filler pic x(24) value "1END-ADD".
065100     03  filler pic x(24) value "1END-CALL".
065200     03  filler pic x(24) value "1END-COMPUTE".
065300     03  filler pic x(24) value "1END-DELETE".
065400     03  filler pic x(24) value "1END-DISPLAY".
065500     03  filler pic x(24) value "1END-DIVIDE".
065600     03  filler pic x(24) value "1END-EVALUATE".
065700     03  filler pic x(24) value "1END-IF".
065800     03  filler pic x(24) value "1END-MULTIPLY".
065900     03  filler pic x(24) value "1END-OF-PAGE".
066000     03  filler pic x(24) value "1END-PERFORM".
066100     03  filler pic x(24) value "1END-READ".
066200     03  filler pic x(24) value "0END-RECEIVE".
066300     03  filler pic x(24) value "1END-RETURN".
066400     03  filler pic x(24) value "1END-REWRITE".
066500     03  filler pic x(24) value "1END-SEARCH".
066600     03  filler pic x(24) value "1END-START".
066700     03  filler pic x(24) value "1END-STRING".
066800     03  filler pic x(24) value "1END-SUBTRACT".
066900     03  filler pic x(24) value "1END-UNSTRING".
067000     03  filler pic x(24) value "1END-WRITE".
067100     03  filler pic x(24) value "1ENTRY".
067200     03  filler pic x(24) value "0ENTRY-CONVENTION".
067300     03  filler pic x(24) value "1ENVIRONMENT".
067400     03  filler pic x(24) value "1ENVIRONMENT-NAME".
067500     03  filler pic x(24) value "1ENVIRONMENT-VALUE".
067600     03  filler pic x(24) value "0EO".
067700     03  filler pic x(24) value "1EOL".
067800     03  filler pic x(24) value "1EOP".
067900     03  filler pic x(24) value "1EOS".
068000     03  filler pic x(24) value "1EQUAL".
068100     03  filler pic x(24) value "1EQUALS".
068200     03  filler pic x(24) value "1ERASE".
068300     03  filler pic x(24) value "1ERROR".
068400     03  filler pic x(24) value "1ESCAPE".
068500     03  filler pic x(24) value "0ESI".
068600     03  filler pic x(24) value "1EVALUATE".
068700     03  filler pic x(24) value "1EXCEPTION".
068800     03  filler pic x(24) value "0EXCEPTION-OBJECT".
068900     03  filler pic x(24) value "1EXCLUSIVE".
069000     03  filler pic x(24) value "1EXIT".
069100     03  filler pic x(24) value "0EXPANDS".
069200     03  filler pic x(24) value "1EXTEND".
069300     03  filler pic x(24) value "1EXTERNAL".
069400     03  filler pic x(24) value "0FACTORY".
069500     03  filler pic x(24) value "1FALSE".
069600     03  filler pic x(24) value "1FD".
069700     03  filler pic x(24) value "1FILE".
069800     03  filler pic x(24) value "1FILE-CONTROL".
069900     03  filler pic x(24) value "1FILE-ID".
070000     03  filler pic x(24) value "1FILLER".
070100     03  filler pic x(24) value "0FINAL".
070200     03  filler pic x(24) value "1FIRST".
070300     03  filler pic x(24) value "0FLOAT-BINARY-16".
070400     03  filler pic x(24) value "0FLOAT-BINARY-34".
070500     03  filler pic x(24) value "0FLOAT-BINARY-7".
070600     03  filler pic x(24) value "0FLOAT-DECIMAL-16".
070700     03  filler pic x(24) value "0FLOAT-DECIMAL-34".
070800     03  filler pic x(24) value "0FLOAT-EXTENDED".
070900     03  filler pic x(24) value "1FLOAT-LONG".
071000     03  filler pic x(24) value "1FLOAT-SHORT".
071100     03  filler pic x(24) value "1FOOTING".
071200     03  filler pic x(24) value "1FOR".
071300     03  filler pic x(24) value "1FOREGROUND-COLOR".
071400     03  filler pic x(24) value "1FOREVER".
071500     03  filler pic x(24) value "0FORMAT".
071600     03  filler pic x(24) value "1FREE".
071700     03  filler pic x(24) value "1FROM".
071800     03  filler pic x(24) value "1FULL".
071900     03  filler pic x(24) value "1FUNCTION".
072000     03  filler pic x(24) value "0FUNCTION-ID".
072100     03  filler pic x(24) value "0FUNCTION-POINTER".
072200     03  filler pic x(24) value "0GENERATE".
072300     03  filler pic x(24) value "0GET".
072400     03  filler pic x(24) value "1GIVING".
072500     03  filler pic x(24) value "1GLOBAL".
072600     03  filler pic x(24) value "1GO".
072700     03  filler pic x(24) value "1GOBACK".
072800     03  filler pic x(24) value "1GREATER".
072900     03  filler pic x(24) value "0GROUP".
073000     03  filler pic x(24) value "0GROUP-USAGE".
073100     03  filler pic x(24) value "0HEADING".
073200     03  filler pic x(24) value "1HIGH-VALUE".
073300     03  filler pic x(24) value "1HIGH-VALUES".
073400     03  filler pic x(24) value "1HIGHLIGHT".
073500     03  filler pic x(24) value "1I-O".
073600     03  filler pic x(24) value "1I-O-CONTROL".
073700     03  filler pic x(24) value "1ID".
073800     03  filler pic x(24) value "1IDENTIFICATION".
073900     03  filler pic x(24) value "1IF".
074000     03  filler pic x(24) value "1IGNORE".
074100     03  filler pic x(24) value "1IGNORING".
074200     03  filler pic x(24) value "0IMPLEMENTS".
074300     03  filler pic x(24) value "1IN".
074400     03  filler pic x(24) value "1INDEX".
074500     03  filler pic x(24) value "1INDEXED".
074600     03  filler pic x(24) value "0INDICATE".
074700     03  filler pic x(24) value "0INFINITY".
074800     03  filler pic x(24) value "0INHERITS".
074900     03  filler pic x(24) value "1INITIAL".
075000     03  filler pic x(24) value "1INITIALIZE".
075100     03  filler pic x(24) value "1INITIALIZED".
075200     03  filler pic x(24) value "0INITIATE".
075300     03  filler pic x(24) value "1INPUT".
075400     03  filler pic x(24) value "1INPUT-OUTPUT".
075500     03  filler pic x(24) value "1INSPECT".
075600     03  filler pic x(24) value "0INTERFACE".
075700     03  filler pic x(24) value "0INTERFACE-ID".
075800     03  filler pic x(24) value "1INTO".
075900     03  filler pic x(24) value "0INTRINSIC".
076000     03  filler pic x(24) value "1INVALID".
076100     03  filler pic x(24) value "0INVOKE".
076200     03  filler pic x(24) value "1IS".
076300     03  filler pic x(24) value "1JUST".
076400     03  filler pic x(24) value "1JUSTIFIED".
076500     03  filler pic x(24) value "1KEY".
076600     03  filler pic x(24) value "1LABEL".
076700     03  filler pic x(24) value "0LAST".
076800     03  filler pic x(24) value "0LC_ALL".
076900     03  filler pic x(24) value "0LC_COLLATE".
077000     03  filler pic x(24) value "0LC_CTYPE".
077100     03  filler pic x(24) value "0LC_MESSAGES".
077200     03  filler pic x(24) value "0LC_MONETARY".
077300     03  filler pic x(24) value "0LC_NUMERIC".
077400     03  filler pic x(24) value "0LC_TIME".
077500     03  filler pic x(24) value "1LEADING".
077600     03  filler pic x(24) value "1LEFT".
077700     03  filler pic x(24) value "1LENGTH".
077800     03  filler pic x(24) value "1LESS".
077900     03  filler pic x(24) value "0LIMIT".
078000     03  filler pic x(24) value "0LIMITS".
078100     03  filler pic x(24) value "1LINAGE".
078200     03  filler pic x(24) value "1LINAGE-COUNTER".
078300     03  filler pic x(24) value "1LINE".
078400     03  filler pic x(24) value "0LINE-COUNTER".
078500     03  filler pic x(24) value "1LINES".
078600     03  filler pic x(24) value "1LINKAGE".
078700     03  filler pic x(24) value "1LOCAL-STORAGE".
078800     03  filler pic x(24) value "1LOCALE".
078900     03  filler pic x(24) value "1LOCK".
079000     03  filler pic x(24) value "1LOW-VALUE".
079100     03  filler pic x(24) value "1LOW-VALUES".
079200     03  filler pic x(24) value "1LOWLIGHT".
079300     03  filler pic x(24) value "1MANUAL".
079400     03  filler pic x(24) value "1MEMORY".
079500     03  filler pic x(24) value "1MERGE".
079600     03  filler pic x(24) value "0MESSAGE".
079700     03  filler pic x(24) value "0METHOD".
079800     03  filler pic x(24) value "0METHOD-ID".
079900     03  filler pic x(24) value "1MINUS".
080000     03  filler pic x(24) value "1MODE".
080100     03  filler pic x(24) value "1MOVE".
080200     03  filler pic x(24) value "1MULTIPLE".
080300     03  filler pic x(24) value "1MULTIPLY".
080400     03  filler pic x(24) value "1NATIONAL".
080500     03  filler pic x(24) value "1NATIONAL-EDITED".
080600     03  filler pic x(24) value "1NATIVE".
080700     03  filler pic x(24) value "1NEGATIVE".
080800     03  filler pic x(24) value "0NESTED".
080900     03  filler pic x(24) value "1NEXT".
081000     03  filler pic x(24) value "1NO".
081100     03  filler pic x(24) value "0NONE".
081200     03  filler pic x(24) value "0NORMAL".
081300     03  filler pic x(24) value "1NOT".
081400     03  filler pic x(24) value "1NULL".
081500     03  filler pic x(24) value "1NULLS".
081600     03  filler pic x(24) value "1NUMBER".
081700     03  filler pic x(24) value "1NUMBERS".
081800     03  filler pic x(24) value "1NUMERIC".
081900     03  filler pic x(24) value "1NUMERIC-EDITED".
082000     03  filler pic x(24) value "0OBJECT".
082100     03  filler pic x(24) value "1OBJECT-COMPUTER".
082200     03  filler pic x(24) value "0OBJECT-REFERENCE".
082300     03  filler pic x(24) value "1OCCURS".
082400     03  filler pic x(24) value "1OF".
082500     03  filler pic x(24) value "1OFF".
082600     03  filler pic x(24) value "1OMITTED".
082700     03  filler pic x(24) value "1ON".
082800     03  filler pic x(24) value "1ONLY".
082900     03  filler pic x(24) value "1OPEN".
083000     03  filler pic x(24) value "1OPTIONAL".
083100     03  filler pic x(24) value "0OPTIONS".
083200     03  filler pic x(24) value "1OR".
083300     03  filler pic x(24) value "1ORDER".
083400     03  filler pic x(24) value "1ORGANIZATION".
083500     03  filler pic x(24) value "1OTHER".
083600     03  filler pic x(24) value "1OUTPUT".
083700     03  filler pic x(24) value "1OVERFLOW".
083800     03  filler pic x(24) value "1OVERLINE".
083900     03  filler pic x(24) value "0OVERRIDE".
084000     03  filler pic x(24) value "1PACKED-DECIMAL".
084100     03  filler pic x(24) value "1PADDING".
084200     03  filler pic x(24) value "1PAGE".
084300     03  filler pic x(24) value "0PAGE-COUNTER".
084400     03  filler pic x(24) value "1PARAGRAPH".
084500     03  filler pic x(24) value "1PERFORM".
084600     03  filler pic x(24) value "0PF".
084700     03  filler pic x(24) value "0PH".
084800     03  filler pic x(24) value "1PIC".
084900     03  filler pic x(24) value "1PICTURE".
085000     03  filler pic x(24) value "1PLUS".
085100     03  filler pic x(24) value "1POINTER".
085200     03  filler pic x(24) value "1POSITION".
085300     03  filler pic x(24) value "1POSITIVE".
085400     03  filler pic x(24) value "0PRESENT".
085500     03  filler pic x(24) value "1PREVIOUS".
085600     03  filler pic x(24) value "1PRINTER".
085700     03  filler pic x(24) value "0PRINTING".
085800     03  filler pic x(24) value "1PROCEDURE".
085900     03  filler pic x(24) value "1PROCEDURE-POINTER".
086000     03  filler pic x(24) value "1PROCEDURES".
086100     03  filler pic x(24) value "1PROCEED".
086200     03  filler pic x(24) value "1PROGRAM".
086300     03  filler pic x(24) value "1PROGRAM-ID".
086400     03  filler pic x(24) value "1PROGRAM-POINTER".
086500     03  filler pic x(24) value "1PROMPT".
086600     03  filler pic x(24) value "0PROPERTY".
086700     03  filler pic x(24) value "0PROTOTYPE".
086800     03  filler pic x(24) value "0PURGE".
086900     03  filler pic x(24) value "0QUEUE".
087000     03  filler pic x(24) value "1QUOTE".
087100     03  filler pic x(24) value "1QUOTES".
087200     03  filler pic x(24) value "0RAISE".
087300     03  filler pic x(24) value "0RAISING".
087400     03  filler pic x(24) value "1RANDOM".
087500     03  filler pic x(24) value "0RD".
087600     03  filler pic x(24) value "1READ".
087700     03  filler pic x(24) value "0RECEIVE".
087800     03  filler pic x(24) value "1RECORD".
087900     03  filler pic x(24) value "1RECORDING".
088000     03  filler pic x(24) value "1RECORDS".
088100     03  filler pic x(24) value "1RECURSIVE".
088200     03  filler pic x(24) value "1REDEFINES".
088300     03  filler pic x(24) value "1REEL".
088400     03  filler pic x(24) value "1REFERENCE".
088500     03  filler pic x(24) value "0RELATION".
088600     03  filler pic x(24) value "1RELATIVE".
088700     03  filler pic x(24) value "1RELEASE".
088800     03  filler pic x(24) value "1REMAINDER".
088900     03  filler pic x(24) value "1REMOVAL".
089000     03  filler pic x(24) value "1RENAMES".
089100     03  filler pic x(24) value "0REPLACE".
089200     03  filler pic x(24) value "1REPLACING".
089300     03  filler pic x(24) value "0REPORT".
089400     03  filler pic x(24) value "0REPORTING".
089500     03  filler pic x(24) value "0REPORTS".
089600     03  filler pic x(24) value "1REPOSITORY".
089700     03  filler pic x(24) value "0REPRESENTS-NOT-A-NUMBER".
089800     03  filler pic x(24) value "1REQUIRED".
089900     03  filler pic x(24) value "1RESERVE".
090000     03  filler pic x(24) value "0RESET".
090100     03  filler pic x(24) value "0RESUME".
090200     03  filler pic x(24) value "0RETRY".
090300     03  filler pic x(24) value "1RETURN".
090400     03  filler pic x(24) value "1RETURNING".
090500     03  filler pic x(24) value "1REVERSE-VIDEO".
090600     03  filler pic x(24) value "1REWIND".
090700     03  filler pic x(24) value "1REWRITE".
090800     03  filler pic x(24) value "0RF".
090900     03  filler pic x(24) value "0RH".
091000     03  filler pic x(24) value "1RIGHT".
091100     03  filler pic x(24) value "1ROLLBACK".
091200     03  filler pic x(24) value "1ROUNDED".
091300     03  filler pic x(24) value "1RUN".
091400     03  filler pic x(24) value "1SAME".
091500     03  filler pic x(24) value "1SCREEN".
091600     03  filler pic x(24) value "1SD".
091700     03  filler pic x(24) value "1SEARCH".
091800     03  filler pic x(24) value "0SECONDS".
091900     03  filler pic x(24) value "1SECTION".
092000     03  filler pic x(24) value "1SECURE".
092100     03  filler pic x(24) value "0SEGMENT".
092200     03  filler pic x(24) value "1SEGMENT-LIMIT".
092300     03  filler pic x(24) value "1SELECT".
092400     03  filler pic x(24) value "0SELF".
092500     03  filler pic x(24) value "0SEND".
092600     03  filler pic x(24) value "1SENTENCE".
092700     03  filler pic x(24) value "1SEPARATE".
092800     03  filler pic x(24) value "1SEQUENCE".
092900     03  filler pic x(24) value "1SEQUENTIAL".
093000     03  filler pic x(24) value "1SET".
093100     03  filler pic x(24) value "1SHARING".
093200     03  filler pic x(24) value "1SIGN".
093300     03  filler pic x(24) value "1SIGNED".
093400     03  filler pic x(24) value "1SIGNED-INT".
093500     03  filler pic x(24) value "1SIGNED-LONG".
093600     03  filler pic x(24) value "1SIGNED-SHORT".
093700     03  filler pic x(24) value "1SIZE".
093800     03  filler pic x(24) value "1SORT".
093900     03  filler pic x(24) value "1SORT-MERGE".
094000     03  filler pic x(24) value "1SOURCE".
094100     03  filler pic x(24) value "1SOURCE-COMPUTER".
094200     03  filler pic x(24) value "0SOURCES".
094300     03  filler pic x(24) value "1SPACE".
094400     03  filler pic x(24) value "1SPACES".
094500     03  filler pic x(24) value "1SPECIAL-NAMES".
094600     03  filler pic x(24) value "1STANDARD".
094700     03  filler pic x(24) value "1STANDARD-1".
094800     03  filler pic x(24) value "1STANDARD-2".
094900     03  filler pic x(24) value "1START".
095000     03  filler pic x(24) value "0STATEMENT".
095100     03  filler pic x(24) value "1STATUS".
095200     03  filler pic x(24) value "0STEP".
095300     03  filler pic x(24) value "1STOP".
095400     03  filler pic x(24) value "1STRING".
095500     03  filler pic x(24) value "0STRONG".
095600     03  filler pic x(24) value "0SUB-QUEUE-1".
095700     03  filler pic x(24) value "0SUB-QUEUE-2".
095800     03  filler pic x(24) value "0SUB-QUEUE-3".
095900     03  filler pic x(24) value "1SUBTRACT".
096000     03  filler pic x(24) value "0SUM".
096100     03  filler pic x(24) value "0SUPER".
096200     03  filler pic x(24) value "0SUPPRESS".
096300     03  filler pic x(24) value "0SYMBOL".
096400     03  filler pic x(24) value "1SYMBOLIC".
096500     03  filler pic x(24) value "1SYNC".
096600     03  filler pic x(24) value "1SYNCHRONIZED".
096700     03  filler pic x(24) value "0SYSTEM-DEFAULT".
096800     03  filler pic x(24) value "0TABLE".
096900     03  filler pic x(24) value "1TALLYING".
097000     03  filler pic x(24) value "1TAPE".
097100     03  filler pic x(24) value "0TERMINAL".
097200     03  filler pic x(24) value "0TERMINATE".
097300     03  filler pic x(24) value "1TEST".
097400     03  filler pic x(24) value "0TEXT".
097500     03  filler pic x(24) value "1THAN".
097600     03  filler pic x(24) value "1THEN".
097700     03  filler pic x(24) value "1THROUGH".
097800     03  filler pic x(24) value "1THRU".
097900     03  filler pic x(24) value "1TIME".
098000     03  filler pic x(24) value "1TIMES".
098100     03  filler pic x(24) value "1TO".
098200     03  filler pic x(24) value "1TOP".
098300     03  filler pic x(24) value "1TRAILING".
098400     03  filler pic x(24) value "1TRANSFORM".
098500     03  filler pic x(24) value "1TRUE".
098600     03  filler pic x(24) value "0TYPE".
098700     03  filler pic x(24) value "0TYPEDEF".
098800     03  filler pic x(24) value "0UCS-4".
098900     03  filler pic x(24) value "1UNDERLINE".
099000     03  filler pic x(24) value "1UNIT".
099100     03  filler pic x(24) value "0UNIVERSAL".
099200     03  filler pic x(24) value "1UNLOCK".
099300     03  filler pic x(24) value "1UNSIGNED".
099400     03  filler pic x(24) value "1UNSIGNED-INT".
099500     03  filler pic x(24) value "1UNSIGNED-LONG".
099600     03  filler pic x(24) value "1UNSIGNED-SHORT".
099700     03  filler pic x(24) value "1UNSTRING".
099800     03  filler pic x(24) value "1UNTIL".
099900     03  filler pic x(24) value "1UP".
100000     03  filler pic x(24) value "1UPDATE".
100100     03  filler pic x(24) value "1UPON".
100200     03  filler pic x(24) value "1USAGE".
100300     03  filler pic x(24) value "1USE".
100400     03  filler pic x(24) value "0USER-DEFAULT".
100500     03  filler pic x(24) value "1USING".
100600     03  filler pic x(24) value "0UTF-16".
100700     03  filler pic x(24) value "0UTF-8".
100800     03  filler pic x(24) value "0VAL-STATUS".
100900     03  filler pic x(24) value "0VALID".
101000     03  filler pic x(24) value "0VALIDATE".
101100     03  filler pic x(24) value "0VALIDATE-STATUS".
101200     03  filler pic x(24) value "1VALUE".
101300     03  filler pic x(24) value "1VALUES".
101400     03  filler pic x(24) value "1VARYING".
101500     03  filler pic x(24) value "1WAIT".
101600     03  filler pic x(24) value "1WHEN".
101700     03  filler pic x(24) value "1WITH".
101800     03  filler pic x(24) value "1WORDS".
101900     03  filler pic x(24) value "1WORKING-STORAGE".
102000     03  filler pic x(24) value "1WRITE".
102100     03  filler pic x(24) value "1YYYYDDD".
102200     03  filler pic x(24) value "1YYYYMMDD".
102300     03  filler pic x(24) value "1ZERO".
102400     03  filler pic x(24) value "1ZEROES".
102500     03  filler pic x(24) value "1ZEROS".
102600*
102700 01  filler redefines Additional-Reserved-Words.
102800     03  Reserved-Names                occurs 526
                   ascending key Resvd-Word indexed by Resvd-Idx.
102900       05  Resvd-Implemented pic x.
103000       05  Resvd-Word        pic x(23).
103100 01  Resvd-Table-Size        pic s999   comp    value 526.
103200*
103300 01  Condition-Table                           value high-values.
103400     03  Con-Tab-Blocks occurs 250 to 5001
103500                                       depending on Con-Tab-Size.
      * +1 used, when testing for max table size
103600       05  Conditions      pic x(30).
103700       05  Variables       pic x(30).
103800 01  Con-Tab-Size          pic s9(5) comp value 250.
103900 01  Con-Tab-Count         pic s9(5) comp value zero.
104000*
104100 01  Global-Item-Table                         value high-values.
104200     03  Git-Elements  occurs 250 to 10001
104300                                     depending on Git-Table-Size.
      * +1 used, when testing for max table size
104400       05  Git-Word        pic x(30).
104500       05  Git-Prog-Name   pic x(30).
104600       05  Git-RefNo       pic 9(6).
104700       05  Git-HoldWSorPD  pic 9.
104800       05  Git-HoldWSorPD2 pic 9.
             05  Git-Build-No    pic 99.
104900 01  Git-Table-Size        pic s9(5) comp value 250.
105000 01  Git-Table-Count       pic s9(5) comp value zero.
105100/
105200 procedure division.
105300 aa000-xref-Data    section.
105400***************************
105500*  TODO & BUGS:
105600*************************************************************************
105700* AAnnn Section:
105800*  THIS ENTIRE SECTION NEEDS A REWRITE, TOO MUCH TAKEN FROM THE VERY OLD
105900*   CODE BASE. DOES READ-A-WORD CATER FOR MULTIPLE STATEMENTS PER LINE
106000*    WITH PERIODS ENDING EACH STATEMENT? IF SO, WHY ARE WE CHECKING FOR 
106100*     WORD-DELIMIT = "." THEN.
106200*  THIS ALL NEEDS A GOOD LOOK AT, SO MUST DONE SOON but with fresh eyes
106300* SUGGEST COMMON CODE LEFT HERE WITH NEW SECTIONS DEALING WITH EACH
106400*  SECTION OR MAIN ENTRY
106500*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
106600* 10. Support for qualifiers? NO
106700* 17. Must rebuild test display coding to get values from selected WS 
106800*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
106900*
107000*  Quesions, Questions, Questions,  all I have, is questions!
107100*************************************************************************
107200*
107300*
107400 aa010-Init-Program.
107500     perform  zz190-Init-Program thru zz190-Exit.
107600     move     high-values to Global-Item-Table.
107700*
107800* Just in case someone's added names in source code out of sort order
107900*  We MUST have all tables in sorted order
108000*
108100     sort     Reserved-Names ascending Resvd-Word.
108200     sort     All-Functions ascending P-Function.
108300*
108400     perform  zz180-Open-Source-File thru zz180-Exit.
108500*
108600* Dump All reserved words from tables then stop
108700*
108800     if       Dump-Reserved-Words
108900              perform varying a from 1 by 1
109000                  until a > Resvd-Table-Size
109100                    display Resvd-Word (a)
109200              end-perform
109300              perform varying a from 1 by 1
109400                  until a > Function-Table-Size
109500                    display P-Function (a)
109600              end-perform
109700              stop run.
109800*
109900     open     output Source-Listing.
110000     if       Reports-In-Lower
110100              move function lower-case (Prog-BaseName) to HoldID
110200     else
110300              move function upper-case (Prog-BaseName) to HoldID.
110400
110500     move     HoldID to HoldID-Module.
110600     move     spaces to Arg-Vals.
110700*
110800* get program id from source file name in case prog-id not present
110900*
111000 aa020-Bypass-Open.
111100     open     output Supplemental-Part1-Out.
111200*
111300* Now add in contents of Global table if processing
111400* nested modules and we have processed first one by
111500*  loading sort file
111600*
111700     if       Git-Table-Count not = zero
111800              move zeros to SortRecord
111900              perform varying a from 1 by 1
112000                       until a > Git-Table-Count
112100                   move Git-HoldWSorPD  (a) to SkaWSorPD
112200                   move Git-HoldWSorPD2 (a) to SkaWSorPD2
112300                   if Reports-In-Lower
112400                      move function lower-case (Git-Word (a))
112500                                            to SkaDataName
112600                   else
112700                      move Git-Word (a) to SkaDataName
112800                   end-if
112900                   move Git-RefNo (a) to SkaRefNo
113000                   move 1 to USect (Git-HoldWSorPD (a))
113100                   write SortRecord
113200              end-perform
113300     end-if
113400*
113500* HoldID gets updated with program-id name when found later
113600*   but we can print 1st report headings using the sourcefile name
113700*    we are assuming the user knows what s/he is doing......:)
113800*
113900     move     Prog-Name to H1Prog-Name.
114000     if       List-Source
114100              perform  zz150-WriteHdb.
114200*
114300     perform  zz100-Get-A-Source-Record thru zz100-Exit.
114400     move     1 to q S-Pointer F-Pointer.
114500*
114600 aa030-ReadLoop1.
114700     if       Source-Eof
114800           or End-Prog
114900              display Msg2
115000              close Supplemental-Part1-Out Source-Listing
115100              close SourceInput
115200              stop run returning 16.
115300     perform  zz110-Get-A-Word thru zz110-Exit.
115400     IF       SourceIn8-160 = "DATA DIVISION.  "
115500                          or  "FILE SECTION.   "
115600                          or  "WORKING-STORAGE SECTION."
115700                          or  "PROCEDURE DIVISION."
115800              go to aa060-ReadLoop3a.
115900*
116000* The above should never happen, as all modules have a program-id
116100*
116200     if       wsFoundWord2 not = "PROGRAM-ID"
116300              go to aa030-ReadLoop1.
116400     perform  zz110-Get-A-Word thru zz110-Exit.
116500*
116600* got program name so if 1st prog id -> hold-id
116700*               else -> holdid-module (for reports)
116800*
116900     if       not Have-Nested
117000        if       Reports-In-Lower
117100                 move function lower-case (wsFoundWord2) 
117200                                      to HoldID
117300        else
117400                 move function upper-case (wsFoundWord2 (1:30))
117500                                      to HoldID.
117600     if       Have-Nested  *> found more than 1 module in source
117700        if       Reports-In-Lower
117800                 move function lower-case (wsFoundWord2) 
117900                                      to HoldID-Module
118000        else
118100                 move function upper-case (wsFoundWord2 (1:30)) 
118200                                      to HoldID-Module.
118300*
118400* We now have the program-id name so update our info, for reports
118500*
118600 aa040-ReadLoop2.
118700     perform  zz100-Get-A-Source-Record thru zz100-Exit.
118800     if       SourceIn8-160 = "SPECIAL-NAMES."
118900              go to aa041-Get-SN.
119000     move     zero to a.
119100     perform  aa045-Test-Section thru aa045-Exit.
119200*
119300* if < 9 we've got Data Div onwards
119400* 
119500     if       a < 9
119600              go to aa060-ReadLoop3a.
119700*     perform  aa046-Search-4-Copy thru aa046-Exit.  *>   ??????
119800     go       to aa040-ReadLoop2.
119900*
120000 aa041-Get-SN.
120100*
120200* Get special names
120300*
120400     perform  zz100-Get-A-Source-Record thru zz100-Exit.
120500     move     zero to a.
120600     perform  aa045-Test-Section thru aa045-Exit.
120700     if       a < 9
120800              go to aa060-ReadLoop3a.
120900     if       SourceIn8-160 (1:13) = "INPUT-OUTPUT "
121000                                or = "DATA DIVISION"
121100              go to aa041-Get-SN.
121200     IF       SourceIn8-160 (1:13) = "FILE-CONTROL."
121300              go to aa047-GetIO.
121400     IF       SourceIn8-160 (1:12) = "I-O-CONTROL."
121500              go to aa048-GetIOC.
121600*
121700 aa042-Getword.
121800     perform  zz110-Get-A-Word thru zz110-Exit.
121900     if       Word-Delimit = "."
122000              go to aa041-Get-SN.
122100     if       wsFoundWord2 (1:3) not = "IS "
122200              go to aa042-Getword.
122300*
122400     perform  zz110-Get-A-Word thru zz110-Exit.
122500     move     wsFoundWord2 (1:30) to Saved-Variable.
122600*
122700 aa044-Getword3.
122800     perform  zz110-Get-A-Word thru zz110-Exit.
122900     if       Word-Delimit = "."
123000              go to aa041-Get-SN.
123100     if       wsFoundWord2 (1:2) not = "ON"
123200          and wsFoundWord2 (1:3) not = "OFF"
123300              go to aa044-Getword3.
123400     perform  zz110-Get-A-Word thru zz110-Exit.
123500     add      1 to Con-Tab-Count.
123600     move     Saved-Variable to Variables (Con-Tab-Count).
123700     move     wsFoundWord2 (1:30) to Conditions (Con-Tab-Count).
123800     if       Word-Delimit = "."
123900              go to aa041-Get-SN.
124000     go       to aa044-Getword3.
124100*
124200 aa045-Test-Section.
124300     add      1 to a.
124400     if       a > 8
124500              go to aa045-Exit.
124600     if       SourceIn8-160 not = Full-Section-Name (a)
124700              go to aa045-Test-Section.
124800*
124900 aa045-Exit.
125000     exit.
125100*
125200* aa046-Search-4-Copy.  *> ????????????????????????????
125300*
125400*  This might be done with having removed the COPY verb processing
125500*
125600*     perform  zz110-Get-A-Word thru zz110-Exit.
125700*     subtract 1 from Source-Line-End giving a.
125800*     if       S-Pointer2 < a
125900*              go to aa046-Search-4-Copy.
126000*
126100* aa046-Exit.
126200*     exit.
126300*
126400 aa047-GetIO.
126500*
126600* now got file control
126700*
126800     perform  zz100-Get-A-Source-Record thru zz100-Exit.
126900     move     zero to a.
127000     perform  aa045-Test-Section thru aa045-Exit.
127100     if       a < 9
127200              go to aa060-ReadLoop3a.
127300     IF       SourceIn8-160 (1:12) = "I-O-CONTROL."
127400              go to aa048-GetIOC.
127500     if       SourceIn8-160 (1:12) = "DATA DIVISIO"
127600              go to aa050-ReadLoop3.
127700     if       SourceIn8-160 (1:12) = "FILE SECTION"
127800              go to aa060-ReadLoop3a.
127900*
128000 aa047-Getword.
128100     perform  zz110-Get-A-Word thru zz110-Exit.
128200     if       Word-Delimit = "."
128300              go to aa047-GetIO.
128400*
128500* now looking at selects: so looking for non reserved words
128600*
128700     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
128800     if       a not = zero
128900              go to aa047-Getword.
129000     if       Word-Delimit = "."
129100              go to aa047-GetIO.
129200* Now have filename
129300     move     1 to HoldWSorPD.
129400     move     0 to HoldWSorPD2.
129500     perform  zz030-Write-Sort.
129600*
129700 aa047-Getword2.
129800     perform  zz110-Get-A-Word thru zz110-Exit.
129900     if       Source-Eof
130000              display Msg16
130100              stop run.
130200*
130300* Above condition is a Logic error: Must trace reason: 
130400*                                   Should nolonger happen.
130500*
130600* should have assign
130700*
130800     if       wsFoundWord2 (1:7) not = "ASSIGN "
130900              go to aa047-Getword2.
131000*
131100 aa047-Getword3.
131200     perform  zz110-Get-A-Word thru zz110-Exit.
131300     if       (wsf1-1 = quote or = "'") AND Word-Delimit = "."
131400              go to aa047-GetIO.
131500     if       wsf1-1 = quote or = "'"
131600              go to aa047-Getword3.
131700     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
131800     if       a not = zero and Word-Delimit = "."
131900              go to aa047-GetIO.
132000     if       a not = zero
132100              go to aa047-Getword3.
132200*     if       Word-Delimit = "."
132300*              go to aa047-GetIO.
132400     if       word-length = zero
132500              go to aa047-GetIO.
132600* Now have filename
132700*
132800* filenames / datanames declared in Selects are shown as in data division
132900*
133000     move     1 to HoldWSorPD.
133100     move     0 to HoldWSorPD2.
133200     perform  zz030-Write-Sort.
133300     if       Word-Delimit = "."
133400              go to aa047-GetIO.
133500     go       to aa047-Getword3.
133600*
133700 aa048-GetIOC.
133800     perform  zz110-Get-A-Word thru zz110-Exit.
133900     if       wsf1-1 = quote or = "'"
134000              go to aa048-GetIOC.
134100     if       Word-Delimit = "."
134200              perform zz100-Get-A-Source-Record thru zz100-Exit
134300              move    zero to a
134400              perform aa045-Test-Section thru aa045-Exit
134500              if      a < 9
134600                      go to aa060-ReadLoop3a.
134700     if       wsFoundWord2 (1:5) not = "SAME "
134800              go to aa048-GetIOC.
134900*
135000 aa049-Getword.
135100     perform  zz110-Get-A-Word thru zz110-Exit.
135200     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
135300     if       a not = zero
135400              go to aa049-Getword.
135500* Now have filename
135600     move     1 to HoldWSorPD.
135700     move     0 to HoldWSorPD2.
135800     perform  zz030-Write-Sort.
135900     if       Word-Delimit = "."
136000              go to aa047-GetIO.
136100     go       to aa049-Getword.
136200*
136300 aa050-ReadLoop3.
136400*
136500*    Now for the data division or beyond
136600*
136700     perform  zz100-Get-A-Source-Record thru zz100-Exit.
136800*     perform  aa046-Search-4-Copy thru aa046-Exit. *> ??????????
136900*
137000 aa060-ReadLoop3a.   *> a < 9  ??
137100     perform  zz170-Check-4-Section thru zz170-Exit.
137200     if       GotASection = "Y"
137300              go to aa050-ReadLoop3.
137400     if       HoldWSorPD > zero and < 8
137500              move 1 to S-Pointer2
137600              perform ba000-Process-WS.
137700*
137800     if       HoldWSorPD = zero
137900              go to aa050-ReadLoop3.
138000*
138100     perform  bb000-Process-Procedure.
138200     if       End-Prog
138300              close Supplemental-Part1-Out
138400     else
138500              close SourceInput Supplemental-Part1-Out.
138600     perform  bc000-Last-Act.
138700     if       not End-Prog
138800              close Source-Listing.
138900*
139000     if       not We-Are-Testing
139100          and not End-Prog
139200*             call "CBL_DELETE_FILE" using SourceFileName  *> kill temp input file but not yet
139300              call "CBL_DELETE_FILE" using "Part2.tmp"
139400              call "CBL_DELETE_FILE" using "Part1.tmp".
139500*
139600     if       End-Prog
139700              perform  zz190-Init-Program thru zz190-Exit
139800              move  spaces to PrintLine
139900              write PrintLine
140000              write PrintLine
140100              write PrintLine
140200              move  zero to sw-End-Prog
140300              go    to aa020-Bypass-Open.
140400     goback.
      *> one of these is right for standalone and being called by cobc (C code).
140500     exit     program.
140600     stop     run.
140700/
140800 ba000-Process-WS Section.
140900 ba020-GetAWord.
141000*
141100* this should be getting first word of source record
141200*
141300     perform  zz110-Get-A-Word thru zz110-Exit.
141400     if       GotASection = "Y" *> check for Proc. Div
141500         and  HoldWSorPD = 8
141600              go to ba000-Exit. *> done, so process proc. div
141700     if       GotASection = "Y"
141800              move space to GotASection
141900              perform zz100-Get-A-Source-Record thru zz100-Exit
142000              go to ba020-GetAWord.
142100*
142200* lets get a file section element out of the way
142300*
142400     if       wsFoundWord2 (1:3) = "FD " or = "RD "
142500              move zero to Global-Current-Level  *> Global only for these
142600     else
142700      if      wsFoundWord2 (1:3) = "CD " or = "SD "   *> and not for these
142800              move high-values to Global-Current-Level.
142900* Clears Global-Active
      *
      * note that for CD & SD setting Global-current-* not needed
      *                           is it a problem
143000     if       wsFoundWord2 (1:3) = "FD " or = "SD "
143100                                or = "RD " or = "CD "
143200              perform zz110-Get-A-Word thru zz110-Exit   *> get filename
143300              move zero to HoldWSorPD2
143400              move zero to sw-Git                   *> reset Global flag
143500              move wsFoundWord2 (1:30) to Global-Current-Word
143600              move Gen-RefNo1 to Global-Current-RefNo
143700              perform zz030-Write-Sort
143800              perform ba040-Clear-To-Next-Period thru ba040-Exit
143900              go to ba020-GetAWord.
144000*
144100* we now have basic ws records, ie starting 01-49,66,77,78,88 etc
144200*
144300      if      wsFoundWord2 (1:Word-Length) not numeric
144400              display "ba020:" Msg4 wsFoundWord2 (1:Word-Length)
144500*              perform ba030-Word-Sweep thru ba030-Exit
                close Source-Listing SourceInput Supplemental-Part1-Out
                stop run. *> if here, its broke
144600*              go to ba020-GetAWord.
144700*
144800* word = Build-Number
144900*
145000      perform zz160-Clean-Number thru zz160-Exit.
            if      Build-Number > 0 and < 50
                    move spaces to Saved-Variable.
      *
145100      if      Build-Number = 01
145200         and  (Global-Current-Level = high-values
145300           or HoldWSorPD > 1)
145400              move zero to sw-Git
145500              move 1 to Global-Current-Level.
      *
145600      if      Build-Number = 88 or = 78 or = 77 or = 66
145700                                or (Build-Number > 0 and < 50)
145800              go to ba050-Get-User-Word.
145900* Should never happen
146000      display "ba020:" Msg5 "bld=" Build-Number
                    " word=" wsFoundWord2 (1:32).
146100      display "Source = " SourceInWS (1:60).
                close Source-Listing SourceInput Supplemental-Part1-Out
                stop run. *> if here, its broke
146200*      perform ba040-Clear-To-Next-Period thru ba040-Exit.
146300*      go      to ba020-GetAWord.
146400*
146500 ba030-Word-Sweep.
146600*
146700* abnormal processing such as screen section. could b here if lost
      *   This should now never be called  27/12/8 <<<<<<<<<<<<<<
      *  test with a screen section before removal  <<<<<<<<<<<<<
146800*  We will just look at each word until period if word not reserved
146900*   nor numeric add to sort
147000*
147100     if       wsFoundWord2 (1:1) = quote or = "'"
147200              go to ba030-GetNext.
147300     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
147400     if       wsFoundWord2 (1:4) = "PIC "
147500          or  wsFoundWord2 (1:8) = "PICTURE "
147600              perform zz110-Get-A-Word thru zz110-Exit
147700              go to ba030-GetNext.
147800     if       a not = zero
147900           or wsFoundWord2 (1:1) numeric
148000           or = "+" or = "-" or = quote or = "'"
148100              go to ba030-GetNext.
148200     perform  zz030-Write-Sort.
148300     if       Word-Delimit = "."
148400              go to ba030-Exit.
148500*
148600 ba030-GetNext.
148700     perform  zz110-Get-A-Word thru zz110-Exit.
148800     if       Word-Delimit = "."
148900          and (wsFoundWord2 (1:1) numeric
149000           or = "+" or = "-" or = quote or = "'")
149100              go to ba030-Exit.
149200     if       Word-Delimit = "."
149300          and wsFoundWord2 (1:1) not = space
149400              go to ba030-Word-Sweep.
149500     if       Word-Delimit = "."
149600              go to ba030-Exit.
149700     go       to ba030-Word-Sweep.
149800*
149900 ba030-Exit.
150000     exit.
150100*
150200 ba040-Clear-To-Next-Period.
150300     if       Word-Delimit = "."
150400              go to ba040-Exit.
150500     perform  zz110-Get-A-Word thru zz110-Exit.
150600     if       wsFoundWord2 (1:7) = "GLOBAL "
150700              move 1 to sw-Git
150800              perform zz200-Load-Git thru zz200-Exit.
150900     if       wsFoundWord2 (1:8) = "INDEXED "
151000              perform ba052-After-Index.
151100     go       to ba040-Clear-To-Next-Period.
151200 ba040-Exit.
151300     exit.
151400*
151500 ba050-Get-User-Word.
      *
      * to here with nn ^ word but word could be pic/value etc ie no dataname
      *
151600     perform  zz110-Get-A-Word thru zz110-Exit.
151700     if       wsFoundWord2 (1:7) = "FILLER "
                    move "FILLER" to Saved-Variable
151800              go to ba051-After-DataName.
151900     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
      *
      * Trap for no dataname, ie reserved word
      * this (if) MUST be left in here
      *
           if       a not = zero
              and   wsFoundWord2 (1:7) not = "FILLER "
                    display "Program Not been Syntax checked and it nee"
                    & "ds it:" wsFoundWord2.
           if       a not = zero
                    move "FILLER" to Saved-Variable
                    go to ba051-After-New-Word.
152000     move     wsFoundWord2 (1:23) to Saved-Variable.
152100     move     a to Saved-a.   *> these 2 not needed ???<<<<<<<
152200     move     Build-Number to Saved-Build-Number. *> ^^<<<<<<<
152300*
152400* not a reserved word and a 88
152500* looking for 01 - 49
152600*
152700*     if       a = zero
152800      if      Build-Number > 0 and < 50
152900              move wsFoundWord2 (1:30)
153000                   to Saved-Variable.
153100*     if       a = zero
153200      if      Build-Number = 88
153300          and Con-Tab-Count not < Con-Tab-Size
153400              add 250 to Con-Tab-Size.
153500     if       Con-Tab-Size > 5000
                    move 5001 to Con-Tab-Size             *> just in case
153600              display Msg6
153700              go to ba050-Bypass-Add-2-Con-Table.
153800* add 88 dataname to constant table
153900*     if       a = zero
154000      if      Build-Number = 88
154100          and Con-Tab-Count < Con-Tab-Size
154200              add 1 to Con-Tab-Count
154300              if  Reports-In-Lower
154400                  move function lower-case (Saved-Variable) to
154500                    Variables (Con-Tab-Count)
154600                  move function lower-case (wsFoundWord2 (1:30))
154700                     to Conditions (Con-Tab-Count)
154800              else
154900                  move Saved-Variable to Variables (Con-Tab-Count)
155000                  move wsFoundWord2 (1:30)
155100                     to Conditions (Con-Tab-Count)
155200              end-if
155300     end-if.
      *
      * Not coping with Global related Conditions for nested modules
      *    after module 1 or the defining module
      *  need to use the Git table and print it.
      *
155400*
155500 ba050-Bypass-Add-2-Con-Table.
155600*
155700* we don't have a reserved word! a = 0 = no
155800*
155900*     if       a = zero
156000      if      Global-Current-Level not = high-values
156100              move Gen-RefNo1 to Global-Current-RefNo
156200              move wsFoundWord2 (1:30) to Global-Current-Word.
156300*     if       a = zero
156400      perform zz030-Write-Sort.
156500      go      to ba051-After-DataName.
156600* YES, Should never happen  but it does often enough if no dataname??
           display "ba050: Major logic error 01".
              close Source-Listing SourceInput Supplemental-Part1-Out.
              stop run. *> if here, its broke
156700*     perform  ba030-Word-Sweep thru ba030-Exit.
156800*     go       to ba020-GetAWord.
156900*
157000 ba051-After-DataName.
157100     if       Word-Delimit = "."
157200          and Build-Number not = 66 and not = 77 and not = 78
                and Saved-Variable not = "FILLER"
157300          and Global-Active
157400              perform zz200-Load-Git thru zz200-Exit.
157500     if       Word-Delimit = "."
157600              go to ba020-GetAWord.
157700     perform  zz110-Get-A-Word thru zz110-Exit.
      *
       ba051-After-New-Word.
157800     if       wsFoundWord2 (1:10) = "REDEFINES " or
157900              wsFoundWord2 (1:8) = "RENAMES "
158000              perform zz110-Get-A-Word thru zz110-Exit
158100              perform zz030-Write-Sort
158200     else
158300      if      wsFoundWord2 (1:7) = "GLOBAL "
158400              move 1 to sw-Git
158500              perform zz200-Load-Git thru zz200-Exit
158600      else
158700       if     Global-Active
158800          and Build-Number not = 66 and not = 77 and not = 78
                and Saved-Variable not = "FILLER"
158900              perform zz200-Load-Git thru zz200-Exit.
159000*
159100     perform  ba040-Clear-To-Next-Period thru ba040-Exit.
159200     go       to ba020-GetAWord.
159300*
159400 ba052-After-Index.
159500*
159600* if Index found ignore 'by'
159700*
159800     perform zz110-Get-A-Word thru zz110-Exit.
159900     if      wsFoundWord2 (1:3) = "BY "
160000             go to ba052-After-Index.
160100*
160200* Should have index name
160300*
160400     perform   zz030-Write-Sort.
160500*
160600 ba000-Exit.
160700     exit.
160800/
160900 bb000-Process-Procedure Section.
161000 bb010-New-Record.
161100*
161200* at this point we need to get a word but have
161300*  PROCEDURE as wsFoundWord2
161400*
161500 bb020-GetAWord.
161600     perform  zz110-Get-A-Word thru zz110-Exit.
161700     if       End-Prog
161800              go to bb000-Exit.
161900     if       Source-Eof
162000              go to bb000-Exit.
162100     if       Word-Delimit = "."
162200         and  wsf1-1 = space
162300              go to bb020-GetAWord.
162400*
162500 bb030-Chk1.
162600     perform  zz130-Extra-Reserved-Word-Check thru zz130-Exit.
162700     move     wsFoundWord2 (1:23) to Save-Res-Word.
162800     move     a to Saved-a.
162900*
163000* Do we have a reserved word? a = 0 means no or a number so ignore
163100*
163200     if       a > zero
163300              go to bb020-GetAWord.
163400     if       wsf1-1 numeric
163500              go to bb020-GetAWord.
163600     if       wsf1-1 = "-"
163700        and   wsFoundWord2 (2:1) numeric
163800              go to bb020-GetAWord.
163900     if       wsf1-1 = "+"
164000        and   wsFoundWord2 (2:1) numeric
164100              go to bb020-GetAWord.
164200     if       wsf1-1 = quote or = "'"
164300              go to bb020-GetAWord.
164400     if       wsf1-1 = "X"
164500        and   wsFoundWord2 (2:1) = quote or = "'"
164600              go to bb020-GetAWord.
164700     if       wsf1-1 = "H"
164800        and   wsFoundWord2 (2:1) = quote or = "'"
164900              go to bb020-GetAWord.
165000     if       wsf1-1 = "("
165100              go to bb050-Check-SubScripts.
165200*
165300 bb040-chk2.
165400*
165500* check for arithmetic operators
165600*
165700     if       wsf1-3 = "-  " or = "+  " or = "*  " or = "/  "
165800                             or = "** "
165900              go to bb020-GetAWord.
166000*
166100* check for relational Conditions
166200*
166300     if       wsf1-2 = "> " or = "< " or = "= "
166400              go to bb020-GetAWord.
166500     if       wsf1-3 = ">= " or = "<= " or = "<> "
166600              go to bb020-GetAWord.
166700*
166800* we have a dataname and are we at word one with period delimiter
166900* is it a paragraph?
167000*
167100     move     2 to HoldWSorPD2.
167200     if       Word-Delimit = "."
167300          and Source-Words = 1
167400              move zero to HoldWSorPD2.
167500*
167600* Check if we have a section name if so set wdorpd2 = 1
167700*
167800     string   wsFoundWord2 (1:Word-Length) delimited by size
167900              " SECTION" delimited by size
168000                into HoldFoundWord.
168100     add      Word-Length 8 giving a.
168200     if       HoldWSorPD2 not = zero
168300         and  SourceIn8-160 (1:a) = HoldFoundWord (1:a)
168400              move 1 to HoldWSorPD2.
168500     if       wsFoundWord2 (Word-Length:1) = ")"
168600              move space to wsFoundWord2 (Word-Length:1)
168700              go to bb030-Chk1.
168800     perform  zz030-Write-Sort.
168900     go       to bb020-GetAWord.
169000*
169100 bb050-Check-SubScripts.
169200*
169300* arrives here with (xxxx
169400*
169500     move     spaces to wsFoundNewWord3.
169600     move     zero to a b c d q s y y2.
169700     subtract 2 from Word-Length giving z.
169800* z = subscript length less ()
169900     inspect  wsFoundWord2 (2:z) tallying a for all "(".
170000     inspect  wsFoundWord2 (2:z) tallying b for all ")".
170100     inspect  wsFoundWord2 (2:z) tallying c for all ":".
170200     inspect  wsFoundWord2 (2:z) tallying d for all space.
170300     inspect  wsFoundWord2 (2:z) tallying y for all quote.
170400     inspect  wsFoundWord2 (2:z) tallying y2 for all "'".
170500     add      y2 to y.
170600     if       a > b
170700              add 1 to z
170800              add 1 to Word-Length
170900              move ")" to wsFoundWord2 (Word-Length:1).
171000*   abc)
171100     if       b > a and a = zero
171200              move space to wsFoundWord2 (Word-Length:1)
171300              subtract 1 from Word-Length.
171400* still need to deal with (aaa))
171500     subtract 1 from Word-Length giving t
171600     if       b > a
171700         and  wsFoundWord2 (Word-Length:1) = ")"
171800         and  wsFoundWord2 (t:1) = ")"
171900              move space to wsFoundWord2 (Word-Length:1)
172000              move t to Word-Length.
172100     if       y > zero
172200              move  zero to q s t
172300              go to bb060-Scan4-Quotes.
172400     if       c > zero
172500              move  zero to q s t
172600              go to bb100-scan4-colon.
172700*
172800     subtract 2 from Word-Length giving z.
172900     if      z < 1
173000             move 1 to z.
173100     if      d = zero
173200         and wsFoundWord2 (2:z) numeric
173300             go to bb020-GetAWord.
173400* for (abcd  instance
173500     if       wsFoundWord2 (Word-Length:1) not = ")"
173600        and  d = zero
173700              add 1 to Word-Length.
173800*
173900     if      d = zero
174000             move spaces to wsFoundNewWord
174100             subtract 2 from Word-Length giving z
174200             move wsFoundWord2 (2:z) to wsFoundNewWord
174300             move wsFoundNewWord to wsFoundWord2
174400             perform zz030-Write-Sort
174500             go to bb020-GetAWord.
174600* cockup trap
174700     display Msg7
174800     go to bb020-GetAWord.
174900*
175000 bb060-Scan4-Quotes.
175100     add      1 to q.
175200     if       wsFoundWord2 (q:1) not = quote and not = "'"
175300              add 1 to s
175400              move wsFoundWord2 (q:1) to wsFoundNewWord3 (s:1)
175500              go to bb060-Scan4-Quotes.
175600*
175700* wsFoundNewWord = non quoted field so far
175800*
175900 bb070-Got-Quote.
176000     add      1 to q.
176100     add      1 to t.
176200     if       q > Word-Length
176300              go to bb090-Recover-Word.
176400     if       wsFoundWord2 (q:1) not = quote and not = "'"
176500              go to bb070-Got-Quote.
176600     add      1 to q.
176700     add      1 to t.
176800*
176900* t = quoted lit length including quotes
177000*   and we are now at end quote + 1
177100 bb080-Quote-Clean.
177200     if       q > Word-Length
177300              go to bb090-Recover-Word.
177400     add      1 to s.
177500     move     wsFoundWord2 (q:1) to wsFoundNewWord3 (s:1).
177600     add      1 to q.
177700     go       to bb080-Quote-Clean.
177800 bb090-Recover-Word.
177900     subtract t from Word-Length.
178000*
178100* Word-Length and wsFoundWord2 less quoted field
178200*
178300     move     wsFoundNewWord3 to wsFoundWord2 (1:32).
178400     go       to bb050-Check-SubScripts.
178500*
178600 bb100-scan4-colon.
178700*
178800* done already =  move     zero to q s t.
178900* now we can have num:num DataName:DN num:DN DN:num
179000*
179100     subtract 1 from Word-Length giving z.
179200     move     spaces to wsFoundNewWord wsFoundNewWord2.
179300     move     1 to t.
179400     unstring wsFoundWord2 (2:z) delimited by ":"
179500              into wsFoundNewWord
179600              count q
179700              pointer t.
179800* t now : +1
179900     unstring wsFoundWord2 (2:z) delimited by ")"
180000              into wsFoundNewWord2
180100              count s
180200              pointer t.
180300     if     t not = Word-Length
180400            display "bb100 Error: t=" t " word-len="
180500            Word-Length " z=" z.
180600     if       wsFoundNewWord (1:q) not numeric
180700              move spaces to wsFoundWord2
180800              move wsFoundNewWord (1:q) to wsFoundWord2
180900              perform zz030-Write-Sort.
181000     if       wsFoundNewWord2 (1:s) not numeric
181100              move spaces to wsFoundWord2
181200              move wsFoundNewWord2 (1:s) to wsFoundWord2
181300              perform zz030-Write-Sort.
181400     go       to bb020-GetAWord.
181500*
181600 bb000-Exit.
181700     exit.
181800/
181900 bc000-Last-Act Section.
182000***********************
182100*  Report Phase
182200*
182300 bc010-Start.
182400     sort     SortFile
182500              ascending key SdSortKey
182600              using  Supplemental-Part1-Out
182700              giving Supplemental-Part2-In.
182800     if       Condition-Sort
182900              sort Con-Tab-Blocks ascending Conditions
183000     else
183100              sort Con-Tab-Blocks ascending Variables.
183200     if       Git-Table-Count > 1
183300              sort  Git-Elements ascending Git-Word.
183400     if   not All-Reports and not Block-Group
183500              go to bc090-Last-Pass2.
183600*
183700* produce group W-S xref & procedure used in testing
183800*  and taken from original code circa 1983 and earlier.
183900*  ------- Leave in just in case needed for testing ----
184000*
184100     move     spaces to saveSkaDataName.
184200     open     input Supplemental-Part2-In.
184300     read     Supplemental-Part2-In at end
184400              display Msg1
184500              go to bc000-Exit.
184600     perform  zz150-WriteHdb thru zz150-Exit.
184700     perform  zz150-WriteHdb6 thru zz150-Exit.
184800     move     zero to q.
184900     go       to bc030-IsX.
185000*
185100 bc020-Read-Sorter.
185200     read     Supplemental-Part2-In at end
185300              perform bc050-Check-Q
185400              close Supplemental-Part2-In
185500              go to bc090-Last-Pass2.
185600*
185700 bc030-IsX.
185800     if       SkaDataName = spaces
185900              go to bc020-Read-Sorter.
186000     perform  bc040-PrintXRef thru bc080-Exit.
186100     go       to bc020-Read-Sorter.
186200*
186300 bc040-PrintXRef.
186400     if       SkaDataName = saveSkaDataName
186500              go to bc070-ConnectD.
186600     move     SkaDataName to saveSkaDataName.
186700*
186800 bc050-Check-Q.
186900     if       XrDataName not = spaces
187000         and  q = zero
187100              move 1 to q.
187200     if       q > zero
187300              write PrintLine
187400              move zero to q
187500              move spaces to PrintLine.
187600*
187700 bc060-ConnectC.
187800     move     spaces to PrintLine.
187900     move     SkaDataName to XrDataName.
188000     move     SkaRefNo to XrDefn.
188100     move     LSect (SkaWSorPD) to XrType.
188200     go       to bc080-Exit.
188300*
188400 bc070-ConnectD.
188500     if       q > 7
188600              perform bc050-Check-Q.
188700     add      1 to q.
188800     move     SkaRefNo to XrReference (q).
188900*
189000 bc080-Exit.
189100     exit.
189200*
189300 bc090-Last-Pass2.
189400*****************
189500* printout in W-S section blocks as requested
189600* Check if any w-s used in module if not, do procedure xref only
189700*
189800     if       Block-Group
189900              go to bc190-Do-Conditions.
190000     move     70 to Line-Count.
190100     if       Section-Used-Table = zeros
190200              go to bc091-Git.
190300*
190400     if       not Group-Report-Only
190500              move  1 to WS-Anal1
190600              move  "Y" to sw-3
190700              perform bc100-Working-Storage-Report
190800                    thru bc180-Exit 7 times.
190900*
191000     if       Group-Report-Only or Both-Reports
191100              move "N" to sw-3
191200              move 7 to WS-Anal1
191300              perform bc100-Working-Storage-Report
191400                thru bc180-Exit.
191500*
191600 bc091-Git.
191700     if       Git-Table-Count > zero
191800              perform bc600-Print-Globals thru bc600-Exit.
191900     go       to bc190-Do-Conditions.
192000*
192100 bc100-Working-Storage-Report.
192200*****************************
192300*  skip section if no data
192400*
192500     if       Do-One-Only
192600          and USect (WS-Anal1) = zero
192700              add 1 to WS-Anal1
192800              go to bc180-Exit.
192900*
193000     move     spaces to saveSkaDataName.
193100     open     input Supplemental-Part2-In.
193200     read     Supplemental-Part2-In at end
193300              display Msg1
193400              go to bc000-Exit.
193500     perform  zz150-WriteHdb thru zz150-Exit.
193600     perform  zz150-WriteHdb2 thru zz150-Exit.
193700     move     zero to q.
193800*
193900* group report
194000*
194100     go       to bc120-IsX2.
194200*
194300 bc110-Read-Sorter.
194400     read     Supplemental-Part2-In at end
194500              add 1 to WS-Anal1
194600              perform  bc050-Check-Q
194700              close Supplemental-Part2-In
194800              go to bc180-Exit.
194900*
195000 bc120-IsX2.
195100     if       SkaDataName = spaces
195200              go to bc110-Read-Sorter.
195300     perform  bc130-PrintXRef2 thru bc170-Exit.
195400     go       to bc110-Read-Sorter.
195500*
195600 bc130-PrintXRef2.
195700*  test was 8
195800     if       SkaDataName = saveSkaDataName
195900              go to bc160-ConnectD2.
196000*
196100     if       SkaWSorPD > WS-Anal1
196200              go to bc170-Exit.
196300     if       Do-One-Only
196400         and  SkaWSorPD not = WS-Anal1
196500              go to bc170-Exit.
196600*
196700* new variable groups 1 thru 7
196800*
196900     move     SkaDataName to saveSkaDataName.
197000     move     SkaWSorPD   to saveSkaWSorPD.
197100     move     SkaWSorPD2  to saveSkaWSorPD2.
197200*
197300     perform  bc050-Check-Q.
197400*
197500 bc150-ConnectC2.
197600     move     spaces to PrintLine.
197700     move     SkaDataName to XrDataName.
197800     move     SkaRefNo to XrDefn.
197900     move     LSect (SkaWSorPD) to XrType.
198000     go       to bc170-Exit.
198100*
198200 bc160-ConnectD2.
198300     if       q > 7
198400              perform bc050-Check-Q.
198500     add      1 to q.
198600     move     SkaRefNo to XrReference (q).
198700     go       to bc170-Exit.
198800*
198900 bc170-Exit.
199000     exit.
199100*
199200 bc180-Exit.
199300     exit.
199400*
199500 bc190-Do-Conditions.
199600     if       Con-Tab-Count = zero
199700              go to bc200-Last-Pass3.
199800     perform zz150-WriteHdb.
199900     perform zz150-WriteHdb7 thru zz150-Exit.
200000     move    zero to a.
200100     perform bc192-Print-Conditions thru bc192-Exit.
200200     go      to bc200-Last-Pass3.
200300*
200400 bc192-Print-Conditions.
200500     if       a < Con-Tab-Count
200600              add 1 to a
200700              move spaces to PrintLine2
200800              move  Conditions (a) to P-Variables
200900              move  Variables (a) to P-Conditions
201000              write PrintLine2
201100              go to bc192-Print-Conditions.
201200 bc192-Exit.
201300     exit.
201400*
201500 bc200-Last-Pass3.
201600*****************
201700* now do procedure div and ref to procedure div but no functions
201800*
201900     if       Block-Group
202000              go to bc300-Last-Pass4.
202100     move     spaces to saveSkaDataName.
202200     move     zero to saveSkaWSorPD saveSkaWSorPD2.
202300     open     input Supplemental-Part2-In.
202400     read     Supplemental-Part2-In at end
202500              display Msg1
202600              go to bc000-Exit.
202700     perform  zz150-WriteHdb.
202800     perform  zz150-WriteHdb3 thru zz150-Exit.
202900     move     zero to q.
203000*
203100     go       to bc220-IsX3.
203200*
203300 bc210-Read-Sorter3.
203400     read     Supplemental-Part2-In at end
203500              perform bc050-Check-Q
203600              close Supplemental-Part2-In
203700              go to bc300-Last-Pass4.
203800*
203900 bc220-IsX3.
204000     if       SkaDataName = spaces
204100              go to bc210-Read-Sorter3.
204200     perform  bc230-PrintXRef3 thru bc270-Exit.
204300     go       to bc210-Read-Sorter3.
204400*
204500 bc230-PrintXRef3.
204600*
204700* ignore all working-storage
204800*
204900     if       SkaDataName not = saveSkaDataName
205000         and  SkaWSorPD not = 8
205100              move  SkaDataName to saveSkaDataName
205200              move  SkaWSorPD   to saveSkaWSorPD
205300              move  SkaWSorPD2  to saveSkaWSorPD2
205400              go to bc270-Exit.
205500*
205600* catch any redefines
205700*
205800     if       SkaDataName = saveSkaDataName
205900         and  saveSkaWSorPD not = 8
206000              go to bc270-Exit.
206100*
206200* catch any procedure followed by functions
206300*   dont think this can happen
206400*
206500     if       SkaDataName = saveSkaDataName
206600         and  saveSkaWSorPD = 8
206700         and  SkaWSorPD > 8
206800              go to bc270-Exit.
206900*
207000     if       SkaDataName = saveSkaDataName
207100              go to bc260-ConnectD3.
207200     move     SkaDataName to saveSkaDataName.
207300     move     SkaWSorPD   to saveSkaWSorPD.
207400     move     SkaWSorPD2  to saveSkaWSorPD2.
207500*
207600     perform  bc050-Check-Q.
207700*
207800 bc250-ConnectC3.
207900     move     spaces to PrintLine.
208000     move     SkaDataName to XrDataName.
208100     move     SkaRefNo to XrDefn.
208200*
208300* process sections
208400*
208500     if       SkaWSorPD2 not = 1
208600              move LSect (SkaWSorPD) to XrType
208700     else
208800              move "S" to XrType.
208900     go       to bc270-Exit.
209000*
209100 bc260-ConnectD3.
209200     if       q > 7
209300              perform bc050-Check-Q.
209400     add      1 to q.
209500     move     SkaRefNo to XrReference (q).
209600*
209700 bc270-Exit.
209800     exit.
209900*
210000 bc300-Last-Pass4.
210100*****************
210200* now do functions
210300*
210400     move     spaces to saveSkaDataName.
210500     move     zero to saveSkaWSorPD saveSkaWSorPD2.
210600     move     70 to Line-Count.
210700     open     input Supplemental-Part2-In.
210800     read     Supplemental-Part2-In at end
210900              display Msg1
211000              go to bc000-Exit.
211100     move     zero to q.
211200     go       to bc320-IsX4.
211300*
211400 bc310-Read-Sorter4.
211500     read     Supplemental-Part2-In at end
211600              perform bc335-Check-Q
211700              close Supplemental-Part2-In
211800              move 70 to Line-Count
211900              go to bc400-Last-Pass5.
212000*
212100 bc320-IsX4.
212200     if       SkaDataName = spaces
212300              go to bc310-Read-Sorter4.
212400     perform  bc330-PrintXRef4 thru bc360-Exit.
212500     go       to bc310-Read-Sorter4.
212600*
212700 bc330-PrintXRef4.
212800*
212900* ignore all working-storage & procedure
213000*
213100     if       SkaWSorPD not = 9
213200              go to bc360-Exit.
213300*
213400     if       Line-Count > 60
213500              move "Functions" to hdr8-hd
213600              move zero to Line-Count
213700              perform zz150-WriteHdb
213800              perform zz150-WriteHdb3 thru zz150-Exit.
213900*
214000     if       SkaDataName = saveSkaDataName
214100              go to bc350-ConnectD4.
214200     move     SkaDataName to saveSkaDataName.
214300*
214400 bc335-Check-Q.
214500     if       XrDataName not = spaces
214600         and  q = zero
214700              move 1 to q.
214800     if       q > zero
214900              write PrintLine
215000              move zero to q
215100              move spaces to PrintLine.
215200*
215300 bc340-ConnectC4.
215400     move     spaces to PrintLine.
215500     move     SkaDataName to XrDataName.
215600     move     SkaRefNo to XrDefn.
215700     move     LSect (SkaWSorPD) to XrType.
215800     go       to bc360-Exit.
215900*
216000 bc350-ConnectD4.
216100     if       q > 7
216200              perform bc335-Check-Q.
216300     add      1 to q.
216400     move     SkaRefNo to XrReference (q).
216500*
216600 bc360-Exit.
216700     exit.
216800*
216900 bc400-Last-Pass5.
217000*****************
217100* now do non referenced ws but ignore references of zero (Globals).
217200*
217300     move     spaces to saveSkaDataName.
217400     move     zero to saveSkaWSorPD saveSkaWSorPD2 S-Pointer.
217500     open     input Supplemental-Part2-In.
217600     read     Supplemental-Part2-In at end
217700              display Msg1
217800              go to bc000-Exit.
217900     perform  zz150-WriteHdb.
218000     perform  zz150-WriteHdb4 thru zz150-Exit.
218100     move     zero to q.
218200*
218300     go       to bc420-IsX5.
218400*
218500 bc410-Read-Sorter5.
218600     read     Supplemental-Part2-In at end
218700              perform bc440-Check-4Old
218800              close Supplemental-Part2-In
218900              go to bc500-Last-Pass6.
219000*
219100 bc420-IsX5.
219200*
219300* ignore zero refs = Globals
219400*
219500     if       SkaDataName = spaces
219600           or SkaRefNo = zeros
219700              go to bc410-Read-Sorter5.
219800     perform  bc430-PrintXRef5 thru bc450-Exit.
219900     go       to bc410-Read-Sorter5.
220000*
220100 bc430-PrintXRef5.
220200*
220300* ignore redefines - No I won't
220400*
220500*     if       SkaDataName = saveSkaDataName
220600*         and  SkaWSorPD < 8
220700*              go to bc450-Exit.
220800     if       SkaDataName = saveSkaDataName
220900              move 2 to q
221000              go to bc450-Exit.
221100* 1st copy of a name can't be non w-s
221200     if       SkaWSorPD > 7
221300              go to bc450-Exit.
221400* print only occurance then store new one
221500     perform  bc440-Check-4Old.
221600*
221700     move     SkaDataName to saveSkaDataName.
221800*
221900* first record for a given name
222000*
222100     move     spaces to PrintLine.
222200     move     SkaDataName to XrDataName.
222300     move     SkaRefNo to XrDefn.
222400     move     LSect (SkaWSorPD) to XrType.
222500     move     1 to q.
222600     go       to bc450-Exit.
222700*
222800 bc440-Check-4Old.
222900     if       q = 1
223000              move 1 to S-Pointer
223100              write PrintLine.
223200*
223300 bc450-Exit.
223400     exit.
223500*
223600 bc500-Last-Pass6.
223700*****************
223800* now do non referenced procedure paragraphs.
223900*
224000     if       S-Pointer = zero
224100              move spaces to PrintLine
224200              move "None" to XrDataName
224300              write PrintLine.
224400     move     spaces to saveSkaDataName.
224500     move     zero to saveSkaWSorPD S-Pointer.
224600     open     input Supplemental-Part2-In.
224700     read     Supplemental-Part2-In at end
224800              display Msg1
224900              go to bc000-Exit.
225000     perform  zz150-WriteHdb.
225100     perform  zz150-WriteHdb5 thru zz150-Exit.
225200     move     zero to q.
225300*
225400     go       to bc520-IsX6.
225500*
225600 bc510-Read-Sorter6.
225700     read     Supplemental-Part2-In at end
225800              perform bc540-Check-4Old
225900              perform bc540-Check-4Old6
226000              close Supplemental-Part2-In
226100              go to bc000-Exit.
226200*
226300 bc520-IsX6.
226400     if       SkaDataName = spaces
226500              go to bc510-Read-Sorter6.
226600     perform  bc530-PrintXRef6 thru bc550-Exit.
226700     go       to bc510-Read-Sorter6.
226800*
226900 bc530-PrintXRef6.
227000*
227100* ignore all non procedure
227200*
227300     if       SkaDataName = saveSkaDataName
227400              move zero to q
227500              go to bc550-Exit.
227600* print only occurance then store new one
227700     if       q = 1
227800        and   saveSkaWSorPD = 8
227900              move 1 to S-Pointer
228000              write PrintLine.
228100*
228200     move     SkaDataName to saveSkaDataName.
228300     move     SkaWSorPD to saveSkaWSorPD.
228400*
228500* first record for a given name
228600*
228700     move     spaces to PrintLine.
228800     move     SkaDataName to XrDataName.
228900     move     SkaRefNo to XrDefn.
229000     if       SkaWSorPD2 not = 1
229100              move LSect (SkaWSorPD) to XrType
229200     else
229300              move "S" to XrType.
229400     move     1 to q.
229500     go       to bc550-Exit.
229600
229700 bc540-Check-4Old.
229800     if       q = 1 and saveSkaWSorPD = 8
229900              move 1 to S-Pointer
230000              write PrintLine.
230100*
230200 bc540-Check-4Old6.
230300     if       S-Pointer = zero
230400              move spaces to PrintLine
230500              move "none" to XrDataName
230600              write PrintLine.
230700*
230800 bc550-Exit.
230900     exit.
231000*
231100 bc600-Print-Globals.
231200********************
231300*  Print Global List for all xrefd modules
231400*
231500     perform  zz150-WriteHdb thru zz150-Exit.
231600     perform  zz150-WriteHdb2b thru zz150-Exit.
231700     move     spaces to PrintLine.
231800     perform  varying a from 1 by 1 until a > Git-Table-Count
231900              move Git-RefNo (a) to XrDefn
232000              move Git-HoldWSorPD (a) to b
232100              if Reports-In-Lower
232200                  move function lower-case (Git-Word (a))
232300                                                   to XrDataName
232400                  move function lower-case (Git-Prog-Name (a))
232500                                                   to PL-Prog-Name
232600              else
232700                  move Git-Word (a) to XrDataName
232800                  move Git-Prog-Name (a) to PL-Prog-Name
232900              end-if
233000              move LSect (b) to XrType
233100              write PrintLine
233200     end-perform.
233300*
233400 bc600-Exit.
233500     exit.
233600*
233700 bc000-Exit.
233800     exit.
233900/
234000 zz000-Routines Section.
234100 zz000-Inc-CobolRefNo.
234200     add      1 to Gen-RefNo1.
234300*
234400 zz000-OutputSource.
234500     if       List-Source
234600              move  spaces to Source-List
234700              move  SourceRecIn to SourceOutput
234800              move  Gen-RefNo1 to sl-Gen-RefNo1
234900              write Source-List.
235000*
235100 zz030-Write-Sort.
235200     move     HoldWSorPD to SkaWSorPD.
235300     move     HoldWSorPD2 to SkaWSorPD2.
235400     move     wsFoundWord2 (1:32) to wsFoundNewWord4.
235500     if       HoldWSorPD > 7
235600              perform zz140-Function-Check thru zz140-Exit.
235700     if       Reports-In-Lower
235800              move function lower-case (wsFoundWord2 (1:32)) to
235900                    wsFoundNewWord4
236000     else
236100              move wsFoundWord2 (1:32) to wsFoundNewWord4.
236200*
236300* stops dups on same fn and refno
236400*
236500     if       wsFoundNewWord4 not = SkaDataName
236600         or   Gen-RefNo1 not = SkaRefNo
236700              move wsFoundNewWord4 to SkaDataName
236800              move Gen-RefNo1 to SkaRefNo
236900              move 1 to USect (HoldWSorPD)
237000              write SortRecord.
237100/
237200 zz100-Get-A-Source-Record.
237300**************************
237400* reads a source record, ignoring comments cleans out excessive
237500*   spaces, ';', ',' etc
237600*
237700     if       Had-End-Prog
237800              move zero to sw-Had-End-Prog
237900              go to zz100-New-Program-point.
238000     if       End-Prog
238100              go to zz100-Exit.
238200     if       Source-Eof
238300              display Msg8
238400              go to zz100-Exit.
238500*
238600     move     spaces to SourceRecIn SourceInWS.
238700     read     SourceInput at end
238800              move 1 to sw-Source-Eof
238900              GO TO zz100-Exit.
239000     move     spaces to cobolseqno.
239100     move     function upper-case (SourceRecIn)
239200                   to SourceIn8-160.
239300* change tabs to spaces prior to printing
239400*  & remove OC comment lines eg '#'
239500*
239600     if       (SourceIn8-160 (1:1) = "#" or = "$")
239700              go to zz100-Get-A-Source-Record.
239800* won't happen with fn.i input
239900     if       (SourceIn8-160 (1:1) = "*" or = "/")
240000              perform zz000-Inc-CobolRefNo
240100              perform zz000-Outputsource
240200              go to zz100-Get-A-Source-Record.
240300*
240400* remove unwanted chars and all multi spaces
240500*  so that unstrings can work easier Includes literals " " etc
240600*
240700     inspect  SourceIn8-160 replacing all x"09" by space.
240800     inspect  SourceIn8-160 replacing all ";" by space.
240900     inspect  SourceIn8-160 replacing all "," by space.
241000     inspect  SourceIn8-160 replacing all "&" by space.
241100     perform  zz120-Replace-Multi-Spaces thru zz120-Exit.
241200     move     Line-End to Source-Line-End.
241300*
241400* count but do not O/P blank lines
241500*
241600      if       d < 1
241700               perform zz000-Inc-CobolRefNo
241800               go to zz100-Get-A-Source-Record.
241900*
242000     if       SourceIn8-160 (1:12) = "END PROGRAM "
242100              perform zz000-Inc-CobolRefNo
242200              perform zz000-Outputsource
242300              go to zz100-Get-A-Source-Record.
242400*
242500     if       HoldWSorPD > 7
242600        and   (SourceIn8-160 (1:12) = "ID DIVISION."
242700         or   SourceIn8-160 (1:20) = "IDENTIFICATION DIVIS")
242800              move 1 to sw-End-Prog sw-Had-End-Prog sw-Nested
                    if we-are-testing
                       display "Found a ID DIVISION"
                    end-if
242900              go to zz100-Exit.
243000*
           if we-are-testing  
            and HoldWSorPD < 8
            and SourceIn8-160 (1:15) = "PROCEDURE DIVIS"
            display "Found a PROCEDURE DIVISION"
           end-if
243100*  check if we have literals
243200*
243300     move     zero to v y2.
243400     inspect  SourceIn8-160 tallying v for all quotes.
243500     inspect  SourceIn8-160 tallying y2 for all "'".
243600     add      y2 to v.
243700*
243800 zz100-New-Program-point.
243900     perform  zz000-Inc-CobolRefNo.
244000     perform  zz000-Outputsource.
244100     move     1 to S-Pointer2.
244200     move     zero to Source-Words.
244300     perform  zz170-Check-4-Section thru zz170-Exit.
244400     go       to zz100-Exit.
244500*
244600 zz100-Exit.
244700     exit.
244800/
244900 zz110-Get-A-Word.
245000*****************
245100*  S-Pointer2 must be set to => 1 prior to call
245200* pointer is a tally of init leading spaces
245300*
245400     if       Source-Eof
245500          or  End-Prog
245600              go to zz110-Exit.
245700     if       S-Pointer2 not < Source-Line-End
245800         and  SourceIn8-160 (S-Pointer2:1) = "."
245900              move "." to Word-Delimit
246000              move zero to Word-Length
246100              move space to SourceIn8-160 (S-Pointer2:1)
246200              move spaces to wsFoundWord2
246300              go to zz110-Exit.
246400     inspect SourceIn8-160 tallying S-Pointer2 for leading spaces.
246500     if       S-Pointer2 not < Source-Line-End
246600          or  S-Pointer2 > 160
246700              go to zz110-Get-A-Word-OverFlow.
246800*
246900* S-Pointer2 = 1st non space
247000*
247100 zz110-Get-A-Word-Unstring.
247200     move     spaces to wsFoundWord2.
247300     move     S-Pointer2 to s.
247400     unstring SourceIn8-160 delimited by " " or "."
247500              into wsFoundWord2
247600               delimiter in Word-Delimit
247700                with pointer S-Pointer2.
247800* check 1st char
247900     if       S-Pointer2 > 160
248000              go to zz110-Get-A-Word-OverFlow.
248100     if       wsf1-1 = space
248200         and  SourceIn8-160 (S-Pointer2:1) = "."
248300              move "." to Word-Delimit
248400              move zero to Word-Length
248500              move spaces to wsFoundWord2
248600              go to zz110-Exit.
248700     if       wsf1-1 = space
248800              go to zz110-Get-A-Word-Unstring.
248900     if       (wsf1-1 numeric
249000           or wsf1-1 = "-"
249100           or wsf1-1 = "+")
249200         and  SourceIn8-160 (S-Pointer2:1) not = space
249300              move s to S-Pointer2
249400              unstring SourceIn8-160 delimited by " "
249500                into wsFoundWord2
249600                 delimiter in Word-Delimit
249700                  with pointer S-Pointer2.
249800*
249900     subtract 2 from S-Pointer2 giving e.
250000     if       Word-Delimit = space
250100         and  SourceIn8-160 (e:1) = "."
250200              move "." to Word-Delimit.
250300
250400     move     S-Pointer2 to e.
250500     if       Word-Delimit = "."
250600        and   (SourceIn8-160 (e:1) = "9" or = "X" or = "A")
250700              move s to S-Pointer2
250800              unstring SourceIn8-160 delimited by " "
250900                into wsFoundWord2
251000                 delimiter in Word-Delimit
251100                  with pointer S-Pointer2
251200              end-unstring
251300              subtract 2 from S-Pointer2 giving e
251400              if  SourceIn8-160 (e:1) = "."
251500                   move "." to Word-Delimit.
251600     if       wsf1-1 = "("
251700         and (wsFoundWord2 (2:1) = quote or = "'")
251800              add 2 to s giving S-Pointer2
251900              move wsFoundWord2 (2:1) to wsFoundWord2 (1:1)
252000                                         Word-Delimit2
252100              go to zz110-Get-A-Word-Literal2.
252200*
252300     if       wsf1-1 = "("
252400         and  wsFoundWord2 (2:1) = space
252500              add 1 to S-Pointer2
252600              go to zz110-Get-A-Word.
252700     if       wsf1-1 = ")"
252800*              add 1 to S-Pointer2 *> misses next char after ') '
252900              go to zz110-Get-A-Word.
253000*
253100     if       wsf1-1 not = quote and not = "'"
253200              perform  varying z from 160 by -1
253300                  until wsFoundWord2 (z:1) not = space
253400              end-perform
253500              move z to Word-Length
253600              go to zz110-Get-A-Word-Copy-Check.
253700*
253800 zz110-Get-A-Word-Literal.
253900     move     wsf1-1 to Word-Delimit2.
254000     add      1 to s giving S-Pointer2.
254100 zz110-Get-A-Word-Literal2.
254200     move     spaces to wsFoundWord2 (2:161).
254300     unstring SourceIn8-160 delimited by Word-Delimit2
254400              into wsFoundWord2 (2:161)
254500               delimiter in Word-Delimit
254600                with pointer S-Pointer2.
254700*
254800* so S-Pointer2 = " +1 and s = starter "
254900* have we another Word-Delimit?
255000*
255100     if       Word-Delimit not = Word-Delimit2
255200              perform  varying z from 160 by -1
255300                  until wsFoundWord2 (z:1) not = space
255400              end-perform
255500              add 1 to z
255600     else
255700              subtract s from S-Pointer2 giving z.
255800     move     Word-Delimit2 to wsFoundWord2 (z:1).
255900     move     z to Word-Length.
256000*
256100*  word is quoted literal or word so we are done
256200*
256300     go       to zz110-Get-A-Word-Copy-Check.
256400*
256500 zz110-Get-A-Word-OverFlow.
256600     move     1 to S-Pointer2.
256700     perform  zz100-Get-A-Source-Record thru zz100-Exit.
256800     if       Source-Eof
256900              go to zz110-Exit.
257000     go       to zz110-Get-A-Word.
257100*
257200 zz110-Get-A-Word-Copy-Check.
257300*
257400     add      1 to Source-Words.
           if we-are-testing
              display "zz110: WD=" word-delimit
                      " WSF2=" wsfoundword2 (1:word-length).
257500*
257600 zz110-Exit.
257700     exit.
257800/
257900 zz120-Replace-Multi-Spaces.
258000***************************
258100* remove any multi spaces within a source line
258200* Fixed: clear cols 73-80, now find actual lengh of record in d
258300*     Now that code is all free taken from fn.i this lot shouldnt be needed
258400*   nope need to start at cc1 and fn.i can start cc1 and cc2.
258500*
258600* run profiler against these routines and tidy 'em up if needed
258700*
258800     perform  varying d from 160 by -1
258900                   until SourceIn8-160 (d:1) not = space
259000     end-perform
      *     if       d > zero       *> d currently pointing to first tailing space
      *              subtract 1 from d.
259100     if       d < 1
259200              go to zz120-Exit.
259300*
259400     move     zero to a b c.
259500     move     spaces to wsFoundNewWord5.
      *
      * now that source is from OC lets clean up fast as cc1 is only 
      *   poss space filled
      *
           if       SourceIn8-160 (1:1) = space
                    move SourceIn8-160 (2:d) to wsFoundNewWord5
                    move wsFoundNewWord5 to SourceIn8-160
                    move spaces to wsFoundNewWord5.
      * this should not be needed
      *  so lets try & rem this all out
259700*     perform  zz120-Kill-Space thru zz120-Kill-Space-Exit.
259800*     move     spaces to SourceIn8-160.
259900*     move     wsFoundNewWord5 (1:b) to SourceIn8-160.
260000*     move     b to Line-End.
           if we-are-testing
              display "zz120A d=" d " after=" SourceIn8-160 (1:d).
260000     subtract 1 from d giving Line-End.
260100     go       to zz120-Exit.
260200*
260300 zz120-Kill-Space.
260400     add      1 to a.
260500     if       a > d
260600              go to zz120-Kill-Space-Exit.
260700     if       SourceIn8-160 (a:1) = space and c = 1
260800              add 1 to b
260900              move zero to c
261000              go to zz120-Kill-Space.
261100*
261200     if       SourceIn8-160 (a:1) = space
261300              go to zz120-Kill-Space.
261400     subtract 1 from a giving e.
261500     if       SourceIn8-160 (a:1) = "("
261600         and  SourceIn8-160 (e:1) not = space
261700         and  HoldWSorPD > 7
261800              add 2 to b
261900     else
262000              add 1 to b.
262100     move     SourceIn8-160 (a:1) to wsFoundNewWord5 (b:1).
262200     move     1 to c.
262300     go       to zz120-Kill-Space.
262400*
262500 zz120-Kill-Space-Exit.
262600     exit.
262700*
262800 zz120-Exit.
262900     exit.
263000/
263100 zz130-Extra-Reserved-Word-Check.
263200********************************
263300*  Check for any other reserved words not in other checks
263400*  note that max reserved word is 23 characters, so comare like 4 like
      *
263500     move     zero to a.
263600     search   all Reserved-Names
263700                  at end go to zz130-exit
263800              when Resvd-Word (Resvd-Idx) = wsFoundWord2 (1:23)
263900                set a to Resvd-Idx
264000                go to zz130-Exit.
264100     display "Oops: logic error at zz130-reserved-word-check".
264200     display "Problem with search verb".
264300     stop run.
264400*
264500 zz130-Exit.
264600     exit.
264700/
264800 zz140-Function-Check.
264900*********************
265000* CALLS:  Only after moving all values to SortRecord and before
265100*         write verb.
265200*
265300* Do we have an intrinsic function name
265400*           if so modify sort rec for section printing
265500* Note that P-oc-implemented = zero if not implemented,
265600*    but treated as the same
265700*
265800     move     zero to F-Pointer.
265900     search   all All-Functions
266000                  at end go to zz140-exit
266100              when P-function (All-Fun-Idx) = wsFoundNewWord4
266200                move 9 to SkaWSorPD
266300                move 1 to SkaWSorPD2
266400                set F-Pointer to All-Fun-Idx
266500                go to zz140-Exit.
266600     display "Oops: logic error at zz140-function-check".
266700     display "Problem with search verb".
266800     stop run.
266900*
267000 zz140-Exit.
267100     exit.
267200/
267300 zz150-WriteHdb.
267400     accept   hddate from date.
267500     if       hddate not = "000000"
267600              move hd-y to hd2-y
267700              move hd-m to hd2-m
267800              move hd-d to hd2-d.
267900     accept   hdtime from time.
268000     if       hdtime not = "00000000"
268100              move hd-hh to hd2-hh
268200              move hd-mm to hd2-mm
268300              move hd-ss to hd2-ss
268400              move hd-uu to hd2-uu.
268500     string   HoldID delimited by space
268600              "    " delimited by size
268700              hd-date-time delimited by size
268800              into h1programid.
268900     move     function when-compiled to WS-When-Compiled.
269000     move     WS-WC-DD  to H1-DD.
269100     move     WS-WC-MM  to H1-MM.
269200     move     WS-WC-YY  to H1-YY.
269300     move     WS-WC-HH  to H1-HH.
269400     move     WS-WC-Min to H1-Min.
269500     move     spaces to PrintLine.
269600     write    PrintLine.
269700     write    PrintLine from hdr1.
269800     move     spaces to PrintLine.
269900     write    PrintLine.
270000 zz150-WriteHdb1.
270010     move     spaces to Hdr5-Prog-Name.
270100     string   HoldID delimited by space
270200              " (" delimited by size
270300              HoldID-Module delimited by space
270400              ")"  delimited by size
270500              into Hdr5-Prog-Name.
270600     move     Hdr5-Prog-Name to Hdr6-Hyphens.
270700     inspect  hdr6-hyphens replacing characters by "-"
270800              before initial "  ".
270900     write    PrintLine from hdr5-symbols.
271000     write    PrintLine from hdr6-symbols.
271100     go       to zz150-Exit.
271200 zz150-WriteHdb2.
271300     move     spaces to PrintLine.
271400     write    PrintLine.
271500     if       Do-One-Only
271600              move spaces to hdr7-variable
271700              string Full-Section-Name (WS-Anal1) delimited space
271800                     ")" delimited by size
271900                     into hdr7-variable
272000     else
272100              move "ALL WORKING)" to hdr7-variable.
272200     write    PrintLine from hdr7-ws.
272300     write    PrintLine from hdr3.
272400     move     spaces to PrintLine.
272500     write    PrintLine.
272600     go       to zz150-Exit.
272700 zz150-WriteHdb2b.
272800     move     spaces to PrintLine.
272900     write    PrintLine.
273000     move    "ALL GLOBALS)" to hdr7-variable.
273100     write    PrintLine from hdr7-ws.
273200     write    PrintLine from hdr3.
273300     move     spaces to PrintLine.
273400     write    PrintLine.
273500     go       to zz150-Exit.
273600 zz150-WriteHdb3.
273700     write    PrintLine from hdr8-ws.
273800     write    PrintLine from hdr3.
273900     move     spaces to PrintLine.
274000     write    PrintLine.
274100     go       to zz150-Exit.
274200 zz150-WriteHdb4.
274300     write    PrintLine from hdr9.
274400     move     spaces to PrintLine.
274500     write    PrintLine.
274600     go       to zz150-Exit.
274700 zz150-WriteHdb5.
274800     write    PrintLine from hdr10.
274900     move     spaces to PrintLine.
275000     write    PrintLine.
275100     go       to zz150-Exit.
275200 zz150-WriteHdb6.
275300     write    PrintLine from hdr2.
275400     write    PrintLine from hdr3.
275500     move     spaces to PrintLine.
275600     write    PrintLine.
275700     go       to zz150-Exit.
275800 zz150-WriteHdb7.
275900     write    PrintLine from hdr11.
276000     write    PrintLine from hdr12-hyphens.
276100     move     spaces to PrintLine.
276200     write    PrintLine.
276300 zz150-Exit.
276400     exit.
276500/
276600 zz160-Clean-Number.
276700      move    zero to Build-Number.
276800      if      Word-Length = 1
276900              move wsf3-1 to Build-Number
277000              go to zz160-Exit.
277100      if      Word-Length = 2
277200              compute Build-Number =
277300                            (wsf3-1 * 10) +
277400                             wsf3-2.
277500 zz160-Exit.
277600     exit.
277700/
277800 zz170-Check-4-Section.
277900     move     space to GotASection.
278000     if       HoldWSorPD = 8
278100              go to zz170-Exit.
278200     if       sv1what = Section-Name (1)
278300              move 1 to HoldWSorPD
278400              move "Y" to GotASection
278500     else
278600      if      sv1what = Section-Name (2)
278700              move 2 to HoldWSorPD
278800              move "Y" to GotASection
278900      else
279000       if     sv1what = Section-Name (3)
279100              move 3 to HoldWSorPD
279200              move "Y" to GotASection
279300       else
279400        if    sv1what = Section-Name (4)
279500              move 4 to HoldWSorPD
279600              move "Y" to GotASection
279700        else
279800         if   sv1what = Section-Name (5)
279900              move 5 to HoldWSorPD
280000              move "Y" to GotASection
280100         else
280200          if  sv1what = Section-Name (6)
280300              move 6 to HoldWSorPD
280400              move "Y" to GotASection
280500          else
280600           if sv1what = Section-Name (7)
280700              move 7 to HoldWSorPD
280800              move "Y" to GotASection
280900           else
281000            if sv1what = Section-Name (8)
281100              move 8 to HoldWSorPD
281200              move "Y" to GotASection
281300              move zero to HoldWSorPD2.
      *
281400* Changed section so we can clear Global flag
      *
           if       GotASection = "Y"
                    move zero to sw-Git.
281500 zz170-Exit.
281600     exit.
281700/
281800 zz180-Open-Source-File.
281900***********************
282000* get source filename
282100*
282200     accept   Arg-Number from argument-number.
282300     if       Arg-Number > zero
282400              move zero to String-Pointer
282500              perform zz180-Get-Program-Args Arg-Number times
282600     else     go to zz180-Check-For-Param-Errors.
282700*
282800* setup printer filename and source rebuild filename
282900*
283000     move     1 to String-Pointer.
283100     unstring Arg-Value (1) delimited by spaces
283200              into SourceFileName
283300               with pointer String-Pointer.
283400*
283500 zz180-Check-For-Param-Errors.
283600*
283700     if       SourceFileName = spaces or
283800              String-Pointer < 7
283900              display Prog-Name
284000              display "Copyright (C) 1967-2008 Vincent Coen"
284100              display " "
284200              display "Parameters are"
284300              display " "
284400              display "1: Source File name (Mandatory)"
284500              display "2: -R    Print out source code prior to xre
284600-             "ference listings"
284700              display "3: -G    produce only group W-S xref"
284800              display "   -A    produce Full group/procedure only"
284900              display "   -GA   produce both Full group/procedure
285000-             "and individual"
285100              display "   -GB   produce both group and individual
285200-             "W-S xref"
285300              display "         Defaults to individual reports per
285400-             " section"
285500              display "4: -L    reports in lowercase else upper"
285600              display "5: -SC   Sort Conditions in Var/Cond Table
285700-             "instead of Variables"
285800              display "6: -DR   Display All reserved words & stop"
285900              display "7: -TEST produces testing info"
286000              display "8: -V    Verbose output"
286100              display "9: -H    Display this help message"
286200              display "   --H   as -H"
286300              stop run returning 16.
286400*
286500     move     1 to String-Pointer String-Pointer2.
286600     unstring Arg-Value (1) delimited by "." into Prog-BaseName
286700              with pointer String-Pointer.
286800*     unstring Arg-Value (1) delimited by space into Source-Extent
286900*              with pointer String-Pointer.
287000     string   Prog-BaseName delimited by space
287100              ".lst"        delimited by size into Print-FileName
287200              with pointer String-Pointer2.
287300*
287400* Can now convert to upper-case as source filename is processed
287500*
287600     move     function upper-case (Arg-Vals) to Arg-Vals.
287700*
287800* Check if help requested
287900*
288000     if       "-H" = Arg-Value (2) or Arg-Value (3)
288100           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
288200           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
288300              move zero to String-Pointer
288400              go to zz180-Check-For-Param-Errors.
288500     if       "--H" = Arg-Value (2) or Arg-Value (3)
288600           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
288700           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
288800              move zero to String-Pointer
288900              go to zz180-Check-For-Param-Errors.
289000*
289100* Check v11 if verbose output required
289200*
289300     if       "-V" = Arg-Value (2) or Arg-Value (3)
289400           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
289500           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
289600              move "Y" to sw-11.
289700*
289800* Check v8 if we are dumping all reserved words
289900*
290000     if       "-DR" = Arg-Value (2) or Arg-Value (3)
290100           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
290200           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
290300              move 1 to sw-8
290400              go to zz180-Exit.
290500*
290600     if       Verbose-Output
290700              display  "Using input = " SourceFileName
290800              display  "  list file = " Print-FileName.
290900*
291000*  Now have the file names for source, print & reseq (if wanted)
291100*
291200*
291300* Check v1 if we are are only doing a group xref ie W-S and procedure
291400*
291500     if       "-G " = Arg-Value (2) or Arg-Value (3)
291600           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
291700           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
291800              move "Y" to sw-1.
291900*
292000* Check v1 if we are are doing Both group xref
292100*
292200     if       "-GB" = Arg-Value (2) or Arg-Value (3)
292300           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
292400           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
292500              move "B" to sw-1.
292600*
292700* Check v1 if we are are doing All groups xref
292800*
292900     if       "-GA" = Arg-Value (2) or Arg-Value (3)
293000           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
293100           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
293200              move "A" to sw-1.
293300*
293400* Check v1 if we are are doing One group xref
293500*
293600     if       "-A" = Arg-Value (2) or Arg-Value (3)
293700           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
293800           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
293900              move "C" to sw-1.
294000*
294100* Check v2 if we are listing the source
294200*
294300      if      "-R" = Arg-Value (2) or Arg-Value (3)
294400           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
294500           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
294600              move "Y" to sw-2.
294700*
294800* Check v6 if we are are doing Lower case reports insted of upper
294900*
295000     if       "-L" = Arg-Value (2) or Arg-Value (3)
295100           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
295200           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
295300              move 1 to sw-6.
295400*
295500* Check v7 if we are sorting var/cond table different
295600*
295700     if       "-SC" = Arg-Value (2) or Arg-Value (3)
295800           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
295900           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
296000              move 1 to sw-7.
296100* finish off v?
296200     if       not Verbose-Output
296300              go to zz180-Test.
296400     if       Group-Report-Only
296500              display " Group xref only".
296600     if       Both-Reports
296700              display " Group & individual sections xref".
296800     if       Reports-In-Lower
296900              display " Reports in Lower Case"
297000      else
297100              display " Reports in Upper Case".
297200     if       Condition-Sort
297300              display " Selected Conditions Sort"
297400     else
297500              display " Selected Variables Sort".
297600 zz180-Test.
297700*
297800* Check v5 if we are testing
297900*
298000     if       "-TEST" = Arg-Value (2) or Arg-Value (3)
298100           or Arg-Value (4) or Arg-Value (5) or Arg-Value (6)
298200           or Arg-Value (7) or Arg-Value (8) or Arg-Value (9)
298300*           or Arg-Value (10)
298400              display " extra information for testing"
298500              move "Y" to sw-5.
298600*
298700     open     input SourceInput.
298800     if       fs-reply not = "00"
298900              display Msg9
299000              stop run returning 16.
299100*
299200     go       to zz180-Exit.
299300*
299400 zz180-Get-Program-Args.
299500     add      1 to String-Pointer.
299600     accept   Arg-Value (String-Pointer) from argument-value.
299700*
299800 zz180-Exit.
299900     exit.
300000*
300100 zz190-Init-Program.
300200*
300300*****************************************************************
300400* initialise all Variables should we be processing nested modules
300500*****************************************************************
300600*
300700     move     spaces to PrintLine Global-Current-Word SortRecord
300800              saveSkaDataName SourceFileName Print-FileName
300900              wsFoundNewWord4 wsFoundNewWord3
301000              wsFoundNewWord2 wsFoundNewWord.
301100*
301200     move     high-values to Condition-Table.
301300*
301400     move     zeros to GotEndProgram
301500              sw-Source-Eof line-word-1 Section-Used-Table 
301600              HoldWSorPD HoldWSorPD2 Con-Tab-Count.
301700*
301800     move     1 to S-Pointer F-Pointer S-Pointer2 S-Pointer3
301900                   S-Pointer4.
302000*
302100 zz190-Exit.
302200     exit.
302300*
302400 zz200-Load-Git.
302500*
302600* Load the Global Item Table with item associated with 01/FD Global
302700*
302800     if       Global-Current-Level = high-values
302900              go to zz200-Exit.
303000     add      1 to Git-Table-Count.
303100     if       Git-Table-Count > Git-Table-Size
303200         and  Git-Table-Size < 10000
303300              add 250 to Git-Table-Size.
303400     if       Git-Table-Size > 10000
303300              move 10001 to Git-Table-Size           *> just in case
303500              display Msg10
303600              go to zz200-Exit.
303700     move     Global-Current-Word to Git-Word (Git-Table-Count).
303800     move     Global-Current-RefNo to Git-RefNo (Git-Table-Count).
303800     move     Build-Number to Git-Build-No (Git-Table-Count).
303900     move     HoldID to Git-Prog-Name (Git-Table-Count).
304000     move     HoldWSorPD  to Git-HoldWSorPD (Git-Table-Count).
304100     move     HoldWSorPD2 to Git-HoldWSorPD2 (Git-Table-Count).
           if we-are-testing
              display "#=" Git-Table-Count
                      " BN=" Git-Build-No (Git-Table-Count)
                      " Git=" Git-Elements (Git-Table-Count).
304200*
304300 zz200-Exit.
304400     exit.
