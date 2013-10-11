000100********************************************************
000200*                                                      *
000300*    D e c i s i o n  T a b l e  T r a n s l a t o r   *
000400*                                                      *
000500********************************************************
000600*
000700 identification          division.
000800*================================
000900*
001000***
001100 program-id.           dectrans.
001200*Author.               V.B.Coen FBCS., via NAVY VER pre NOV 68.
001300*Date-rewritten.       7th August 1987 from code dated Nov 1968.
001400*Version.              See PROG-NAME in ws.
001500*Security.             Copyright (C) 1968-2012, Vincent Bryan Coen.
001600*                      Distributed under the GNU General Public License
001700*                      v3.0. Only.
001800*                      See the file COPYING for details.
001900*
002000* Usage.               Decision Table Translator for Cobol.
002010*                      it accepts and produces only in fixed format.
002100*
002200* Changes.             See Changelog.
002300**************************************************************************
002400*
002500* Copyright Notice.
002600******************
002700*
002800* This file/program is part of DecTrans and is copyright (c) Vincent B Coen.
002810*  parts of it come via the US Navy which is also Open Source.
002900*
003000* This program is free software; you can redistribute it and/or modify it
003100* under the terms of the GNU General Public License as published by the
003200* Free Software Foundation; version 333003300*
003400* Cobxref is distributed in the hope that it will be useful, but WITHOUT
003500* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
003600* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
003700* for more details.
003800*
003900* You should have received a copy of the GNU General Public License along
004000* with Cobxref; see the file COPYING.  If not, write to the Free Software
004100* Foundation, 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
004200**************************************************************************
004300*
004400*****
004500 environment             division.
004600*================================
004700*
004800 configuration section.
004900*---------------------
005000 source-computer.        Linux.
005100 object-computer.        Linux.
005200 special-names.
005300*     console is crt.
005400 input-output            section.
005500*-------------------------------
005600*
005700 file-control.
005800*------------
005900*
006000*
006100     select input-file      assign          Input-FileName
006200                            organization    line sequential
006300                            status          fs-reply.
006400*
006500     select transout        assign          Output-Filename
006600                            organization    line sequential
006700                            status          fs-reply.
006800*
006900     select transhist       assign          Report-FileName
007000                            organization    line sequential
007100                            status          fs-reply.
007200*
007300 data  division.
007400*===============
007500*
007600 file section.
007700*------------
007800*
007900 fd  input-file.
008000*
008100 01  table-header-card.
008200     03  filler                  pic xxx.
008300     03  id-field                pic x(4).
008400     03  filler                  pic x.
008500     03  header-field            pic x(44).
008600     03  filler                  pic x(20).
008700     03  idslot                  pic x(8).
008800*
008900 01  filler.
009000     03  cd-seq                  pic 9(4).
009100     03  filler                  pic x(76).
009200*
009300 01  card-buffer.
009400     03  card-image              pic x  occurs 80.
009500*
009600 fd  transout.
009700*
009800 01  a-card.
009900     03  sequence-field          pic x(6).
010000     03  continuation-column     pic x.
010100     03  a-margin                pic x(61).
010200     03  filler                  pic x(4).
010300     03  ident-field             pic x(8).
010400*
010500 01  b-card.
010600     03  filler                  pic x(11).
010700     03  b-margin                pic x(61).
010800     03  filler                  pic x(8).
010900*
011000 01  a2-card.
011100     03  a2-margin.
011200         05  filler              pic x.
011300         05  b2-margin           pic x(159).
011400*
011500 fd  transhist.
011600*
011700 01  log-record.
011800     03  message-portion.
011900         05  history-record      pic x(6).
012000         05  log-message.
012100             07  filler          pic x(6).
012200             07  lm-rule1        pic 99.
012300             07  filler          pic x(5).
012400             07  lm-rule2        pic 99.
012500             07  filler          pic x(57).
012600     03  log-rule                pic 99.
012700/
012800 working-storage section.
012900*=======================
013000*
013100 77  Prog-Name               pic x(17) value "DecTrans v1.01.04".
013200 77  index1                  pic s999  comp  value zero.
013300 77  index2                  pic s999  comp  value zero.
013400 77  index3                  pic s999  comp  value zero.
013500 77  index4                  pic s999  comp  value zero.
013600 77  index5                  pic s999  comp  value zero.
013700 77  index6                  pic s999  comp  value zero.
013800 77  index7                  pic s999  comp  value zero.
013900 77  kolumns                 pic s999  comp  value zero.
014000 77  row-count               pic s999  comp  value zero.
014100 77  deleted-conditions      pic s999  comp  value zero.
014200 77  rule-count              pic s999  comp  value zero.
014300 77  elseflag                pic s9    comp  value zero.
014400 77  actionflag              pic s9    comp  value zero.
014500 77  literal-flag            pic s9    comp  value zero.
014600 77  space-flag              pic s9    comp  value zero.
014700 77  a-margin-flag           pic s9    comp  value zero.
014800 77  in-table-flag           pic s9    comp  value zero.
014900 77  error-flag              pic s9    comp  value zero.
015000 77  warning-flag            pic s9    comp  value zero.
015100 77  line-cnt                pic 99    comp  value 66.
015200 77  page-cnt                pic 99    comp  value zero.
015300 77  current-sequence        pic 9(6)        value zero.
015400 77  users-sequence-inc      pic 9(6)        value 10.
015500 77  users-ident             pic x(8)        value space.
015600 77  ws-seq                  pic 9(4)        value zero.
015700 77  Arg-Number              pic 99          value zero.
015800*
015900 77  y-entry                 pic x(18)       value "Y".
016000 77  n-entry                 pic x(18)       value "N".
016100 77  x-entry                 pic x(18)       value "X".
016200 77  r-entry                 pic x(18)       value "R".
016300*
016400 77  Input-FileName          pic x(128)  value spaces.
016500 77  Output-FileName         pic x(128)  value spaces.
016600 77  Report-FileName         pic x(128)  value spaces.
016700*
016800 77  cbl-status              pic 9      value zero.
016900  88 cbl-fixed                          value zero.
017000  88 cbl-free                           value 1.
017100*
017200 01  fs-reply                pic xx          value zeros.
017300*
017400 01  tag-building-slot.
017500     03  sub-set-builder.
017600         05  tag-type        pic xxx.
017700         05  tag-number      pic 9(4).
017800     03  filler              pic x      value ".".
017900*
018000 01  rultag.
018100     03  sub-set-rultag.
018200         05  filler          pic xxx    value "RUL".
018300         05  rulinc          pic 9(4)   value zero.
018400     03  filler              pic x      value ".".
018500*
018600 01  acttag.
018700     03  sub-set-acttag.
018800         05  filler          pic xxx    value "ACT".
018900         05  actinc          pic 9(4)   value zero.
019000     03  filler              pic x      value ".".
019100*
019200 01  elstag.
019300     03  sub-set-elstag.
019400         05  filler          pic xxx    value "ELS".
019500         05  elsinc          pic 9(4)   value 1.
019600     03  filler              pic x      value ".".
019700*
019800 01  partag.
019900     03  sub-set-partag.
020000         05  filler          pic xxx    value "PAR".
020100         05  parinc          pic 9(4)   value zero.
020200     03  filler              pic x      value ".".
020300*
020400 01  tabext.
020500     03  sub-set-tabext.
020600         05  filler          pic xxx    value "END".
020700         05  tabinc          pic 9(4)   value 1.
020800     03  filler              pic x      value ".".
020900*
021000 01  first-action.
021100     03  filler              pic xxx    value "ACT".
021200     03  first-inc           pic 9(4)   value zero.
021300     03  filler              pic x      value ".".
021400*
021500 01  new-image.
021600     03  instruction-field   pic x   occurs 61.
021700*
021800 01  rough-statement.
021900     03  staging-area        pic x   occurs 137.
022000*
022100 01  patch-area redefines rough-statement.
022200     03  ifslot              pic xxx.
022300     03  stub-area           pic x(72).
022400     03  filler              pic x.
022500     03  value-slot          pic x(18).
022600     03  filler              pic x.
022700     03  true-action         pic x(13).
022800     03  filler              pic x.
022900     03  true-path           pic x(7).
023000     03  filler              pic x.
023100     03  false-action        pic x(10).
023200     03  filler              pic x.
023300     03  false-path          pic x(7).
023400     03  filler              pic x.
023500     03  period-slot         pic x.
023600*
023700 01  plug-set.
023800     03  if-plug             pic xxx    value "IF".
023900     03  go-to-plug          pic x(5)   value "GO TO".
024000     03  next-sentence-plug  pic x(13)  value "NEXT SENTENCE".
024100     03  else-go-to-plug     pic x(10)  value "ELSE GO TO".
024200
024300* no end-if, could be problems with no period
024400*
024500 01  yestagstack.
024600     03  true-tag            pic x(7)  occurs 25.
024700*
024800 01  notagstack.
024900     03  false-tag           pic x(7)  occurs 25.
025000*
025100 01  current-header.
025200     03  current-table-name  pic x(30).
025300     03  filler              pic x.
025400     03  form                pic x.
025500     03  number-of-conditions pic 999.
025600     03  number-of-actions   pic 999.
025700     03  number-of-rules     pic 999.
025800     03  filler              pic xx.
025900     03  g-check             pic x.
026000         88  g-suppress               value "G".
026100*
026200 01  dummy-stub.
026300     03  temp-stub           pic x    occurs 72.
026400*
026500 01  dummy-entry.
026600     03  temp-col            pic x    occurs 18.
026700*
026800 01  dummy-entry1.
026900     03  dumy-char           pic x    occurs 18.
027000*
027100 01  ycounttable.
027200     03  relative-y          pic 99   occurs 25.
027300 01  ncounttable.
027400     03  relative-n          pic 99   occurs 25.
027500 01  totaltable.
027600     03  total-rule          pic 99   occurs 26.
027700 01  stub-table.
027800     03  condition-stub      pic x(72)  occurs 26.
027900     03  action-stub         pic x(72)  occurs 26.
028000*
028100 01  rule-index.
028200     03  first-column        pic 999    occurs 26.
028300     03  number-of-columns   pic 999    occurs 26.
028400*
028500 01  error-message.
028600	   03  filler              pic x(3)   value "**E".
028700     03  error-type          pic 99     value zeroes.
028800     03  filler              pic x      value spaces.
028900*
029000* These msgs are deliberately uppercase so they stand out
029100*
029200 01  error-table.
029300     03  filler              pic x(72)  value
029400     "TABLE DELETED, ENTRY SIZE GREATER THAN RULE-ENTRY-LIMIT FOR
029500-    "RULE NUMBER ".
029600     03  filler              pic x(72)  value
029700     "STUB FIELD > 72 CHARACTERS".
029800     03  filler              pic x(72)  value
029900     "STUB FIELD < 10 CHARACTERS, TABLE DELETED".
030000     03  filler              pic x(72)  value
030100     "NUMBER OF RULES ON RHDR > INDICATOR IN THDR".
030200     03  filler              pic x(72)  value
030300     "TOTAL ENTRIES < OR > THDR INDICATORS, OR MISSING EODT".
030400     03  filler              pic x(72)  value
030500     "REDUNDANT OR CONTRADICTORY RULES HAVE BEEN FOUND, TABLE DELE
030600-    "TED".
030700     03  filler              pic x(72)  value
030800     "SOURCE CODE GENERATION BYPASSED, CORRECT AND RETRY".
030900     03  filler              pic x(72)  value
031000     "MAX NUMBER OF CONDITIONS EXCEEDED".
031100     03  filler              pic x(72)  value
031200     "MAX NUMBER OF ACTIONS EXCEEDED".
031300     03  filler              pic x(72)  value
031400     "MAX NUMBER OF RULES EXCEEDED".
031500     03  filler              pic x(72)  value
031600     "EODT ENCOUNTERED PRIOR TO END OF TABLE, CARD MISSING".
031700     03  filler              pic x(72)  value
031800     "ENTRY SIZE < 3 CHARACTERS, TABLE DELETED".
031900     03  filler              pic x(72)  value
032000     "RULES nn AND nn ARE EQUAL, CHECK FOR REDUNDANT AND BLANK ENT
032100-    "IES".
032200     03  filler              pic x(72)  value
032300     "NO RULE HEADER (RHDR) FOUND, TABLE DELETED".
032400     03  filler              pic x(72)  value
032500     "CONTROLS NOT IN SEQUENCE, PROCESSING SKIPPED UNTIL NEXT THDR
032600-    "".
032700     03  filler              pic x(72)  value
032800-    "Error: File not present Try Again!".
032900     03  filler              pic x(72)  value
033000     "Error: Cannot create output file/s".
033100 01  filler redefines error-table.
033200     03  error-line          pic x(72)  occurs 17.
033300*
033400 01  warning-message.
033500     03  filler              pic x(3)   value "* W".
033600     03  warning-type        pic 99     value zeroes.
033700     03  filler              pic x      value spaces.
033800*
033900 01  warning-table.
034000     03  filler              pic x(72)  value
034100	   "SEQUENCE ERROR".
034200	   03  filler              pic x(72)  value
034300	   "LAST RULE WAS NOT ELSE RULE, TREATED AS SUCH".
034400	   03  filler              pic x(72)  value
034500	   "TABLE IS LIMITED BUT LOGICALLY INCOMPLETE".
034600	   03  filler              pic x(72)  value
034700	   "ENIT NOT FOUND, RHDR TERMINATES INIT SECTION".
034800	   03  filler              pic x(72)  value
034900	   "AUTO GOTO SUPPRESSED, GOTO MUST BE PROVIDED TO LEAVE EACH SE
035000-    "T OF ACTIONS".
035100*
035200 01  filler redefines warning-table.
035300     03  warning-line        pic x(72)  occurs 5.
035400*
035500 01  table-array.
035600     03  row     occurs 26.
035700         05  entry-matrix    pic x(18)  occurs 25.
035800*
035900* holds program parameter values from command line
036000 01  Arg-Vals                           value spaces.
036100     03  Arg-Value           pic x(128)  occurs 4.
036200*
036300 01  ws-head1.
036400     03  p-prog-name         pic x(19).
036500     03  filler              pic x(8)   value spaces.
036600     03  filler              pic x(46)  value
036700       "Decision Table to Cobol Translator".
036800     03  filler              pic x(5)   value "Page".
036900     03  p-page              pic z9.
037000*
037100 01  ws-head2.
037200     03  filler              pic x(27)  value
037300	     "Table being processed is - ".
037400     03  p-section-name      pic x(30).
037500/
037600 procedure division.
037700*==================
037800*
037900 Trans68.
038000********
038100*
038200* get source, output & report filenames
038300*
038400     accept   Arg-Number from argument-number.
038500     if       Arg-Number > zero
038600              move zero to Index1
038700              perform Arg-Number times
038800                   add   1 to Index1
038900                   accept Arg-Value (Index1)
039000                                         from argument-value
039100              end-perform
039200              if Arg-Number = 1            *>  2 or 3
039300                  unstring Arg-Value (1) delimited by spaces
039400                       into Input-FileName
039500                  end-unstring
039600                  string Input-FileName delimited by "."
039700                                  ".cpy" delimited by size
039800                       into Output-FileName
039900                  end-string
040000                  string Input-FileName delimited by "."
040100                                  ".lst" delimited by size
040200                          into Report-FileName
040300                  end-string
040400              end-if
040500              if Arg-Number > 1            *>  2 or 3
040600                  unstring Arg-Value (1) delimited by spaces
040700                       into Input-FileName
040800                  end-unstring
040900                  unstring Arg-Value (2) delimited by spaces
041000                       into Output-FileName
041100                  end-unstring
041200                  string Input-FileName delimited by "."
041300                                  ".lst" delimited by size
041400                          into Report-FileName
041500                  end-string
041600              end-if
041700              if Arg-Number = 3
041800                  unstring Arg-Value (3) delimited by spaces
041900                          into Report-FileName
042000                  end-unstring
042100              end-if
042200              move zero to Index1
042300     end-if
042400*
042500* Give help if args empty
042600*
042700     if       Input-FileName = spaces
042800              display  space
042900              display  Prog-Name
043000                       "  Cobol Decision Table Translator"
043100              display "Copyright (C) 1968-2009 Vincent Bryan Coen"
043200              display " "
043300              display "Parameters are"
043400              display space
043500              display "1: Input  FileName (Mandatory)"
043600           display "2: Output FileName (Mandatory if not IFN.cpy)"
043700           display "3: Report FileName (Mandatory if not IFN.lst)"
043800              stop run returning 16.
043900*
044000     open     input input-file
044100     if       fs-reply not = "00"
044200              display error-line (16)
044300              stop run returning 16.
044400     open     output transout.
044500     if       fs-reply not = "00"
044600              display error-line (17) "(.out)"
044700              stop run returning 16.
044800     open     output transhist.
044900     if       fs-reply not = "00"
045000              display error-line (17) "(.lst)"
045100              stop run returning 16.
045200     move     prog-name to p-prog-name.
045300*
045400 main-loop.
045500**********
045600*
045700     move     zero to in-table-flag.
045800*
045900 main-loop1.
046000***********
046100*
046200     perform  card-read.
046300     if       id-field not = "THDR"
046400              move    card-buffer to a-card
046500*             move    idslot      to users-ident
046600              perform sequence-ident-fetch
046700              perform card-write
046800              go to   main-loop1.
046900     move     1 to in-table-flag.
047000*
047100 table-header-processor.
047200***********************
047300*
047400     move     header-field to current-header.
047500     move     current-table-name to p-section-name.
047600     perform  headings thru headings-exit.
047700     perform  history-write.
047800     move     card-buffer to log-record.
047900     perform  history-write 2 times.
048000*
048100     if       number-of-conditions not numeric or
048200              number-of-conditions > 25
048300              move 8 to error-type
048400              perform log-error
048500              go to main-loop.
048600*
048700     if       number-of-actions not numeric or
048800              number-of-actions > 25
048900              move 9 to error-type
049000              perform log-error
049100              go to main-loop.
049200*
049300     if       number-of-rules not numeric or
049400              number-of-rules > 25
049500              move 10 to error-type
049600              perform log-error
049700              go to main-loop.
049800*
049900     move     "L" to form.
050000     if       g-suppress
050100              move 5 to warning-type
050200              perform log-warning.
050300*
050400     move     spaces to a-card.
050500     string   current-table-name delimited by space
050600              " SECTION." delimited by size
050700              into a-margin.
050800     perform  sequence-ident-fetch thru card-write.
050900     add      1 to parinc.
051000     move     partag to a-margin.
051100     perform  sequence-ident-fetch thru card-write.
051200     perform  card-read.
051300*
051400*
051500* code here for INIT & ENIT & error checks
051600*
051700     if       id-field = "INIT"
051800              go to init-header-processor.
051900*
052000     if       id-field = "RHDR"
052100              go to rule-header-processor.
052200*
052300     move     14 to error-type.
052400     perform  log-error.
052500     go       to main-loop.
052600*
052700 init-header-processor.
052800**********************
052900*
053000     perform  list-input.
053100*
053200 ihp-read.
053300*********
053400*
053500     perform  card-read.
053600     if       id-field = "ENIT"
053700              perform list-input
053800              perform card-read
053900              go to ihp-check.
054000*
054100     if       id-field = "RHDR"
054200              move 4 to warning-type
054300              perform  log-warning
054400              go to rule-header-processor.
054500*
054600     if       id-field = "THDR" or "INIT" or "EODT"
054700              go to ihp-error.
054800*
054900     move     card-buffer to a-card.
055000     perform  sequence-ident-fetch thru card-write.
055100     go    to ihp-read.
055200*
055300 ihp-error.
055400**********
055500*
055600     perform  list-input.
055700     move     15 to error-type.
055800     perform  log-error.
055900     if       id-field = "THDR"
056000              go to table-header-processor.
056100     go       to main-loop.
056200*
056300 ihp-check.
056400**********
056500*
056600     if       id-field = "RHDR"
056700              go to rule-header-processor.
056800     go       to ihp-error.
056900*
057000 rule-header-processor.
057100**********************
057200*
057300*  index1 = input nonspace char
057400*
057500     move     zero to kolumns rule-count.
057600     move     1 to index1.
057700     move     9 to first-column (index1) index2.
057800     perform  list-input.
057900*
058000 rule-loop.
058100**********
058200*
058300     if       card-image (index2) = space
058400              go to rule-loop1.
058500     if       index1 = 1
058600              go to stub-check.
058700     add      1 to rule-count.
058800     if       rule-count > number-of-rules
058900              move 4 to error-type
059000              perform log-error
059100              go to main-loop.
059200     if       kolumns > 18
059300              move rule-count to log-rule
059400              move 1 to error-type
059500              perform log-error
059600              go to main-loop.
059700     if       kolumns < 3
059800              move 12 to error-type
059900              perform log-error
060000              go to main-loop.
060100     go       to sizeisok.
060200*
060300 stub-check.
060400***********
060500*
060600     if       kolumns < 10
060700              move 3 to error-type
060800              perform log-error
060900              go to main-loop.
061000     if       kolumns > 72
061100              move 2 to error-type
061200              perform log-error
061300              go to main-loop.
061400*
061500 sizeisok.
061600*********
061700*
061800     move     kolumns to number-of-columns (index1).
061900     add      1 to index1.
062000     move     index2 to first-column (index1) index3.
062100     add      3 to index2.
062200     move     3 to kolumns.
062300     if       card-image (index3) = "."
062400              go to end-of-header.
062500     go       to image-check.
062600*
062700 rule-loop1.
062800***********
062900*
063000     add      1 to kolumns
063100                   index2.
063200*
063300 image-check.
063400************
063500*
063600     if       index2 not > 80
063700              go to rule-loop.
063800*
063900*
064000 new-card.
064100*********
064200*
064300     perform  card-read.
064400     perform  list-input.
064500     move     9 to index2.
064600     go       to rule-loop.
064700*
064800 end-of-header.
064900**************
065000*
065100     subtract 1 from index1.
065200     move     first-column (index1) to index2.
065300     if       card-image (index2) not = "E"
065400              move 2 to warning-type
065500              perform log-warning.
065600*
065700 body-card-loader.
065800*****************
065900*
066000     move     1 to index4 index5.
066100     move     zero to index7 ws-seq.
066200     add      number-of-actions
066300                number-of-conditions giving row-count.
066400*
066500 nextcard.
066600*********
066700*
066800     perform  card-read.
066900     perform  list-input.
067000     move     1 to index6.
067100     if       id-field = "EODT"
067200              go to table-processor.
067300     add      1 to index7.
067400*
067500     if       index7 > row-count
067600              move    5 to error-type
067700              perform log-error
067800              go to main-loop.
067900     move     9 to index1.
068000     move     1 to index2 index3.
068100     move     spaces to dummy-stub.
068200*
068300 stub-mover.
068400***********
068500*
068600     if       cd-seq not numeric
068700              go to stub-mover2.
068800     if       cd-seq not > ws-seq
068900              perform warning1.
069000     move     cd-seq to ws-seq.
069100*
069200 stub-mover2.
069300************
069400*
069500     move     card-image (index1) to temp-stub (index2).
069600     if       index2 = number-of-columns (index3)
069700              go to stub-store.
069800     add      1 to index1  index2.
069900     if       index1 not > 80
070000              go to stub-mover2.
070100     perform  card-read.
070200     perform  list-input.
070300     move     1 to index1.
070400     go       to stub-mover.
070500*
070600 stub-store.
070700***********
070800*
070900     if       index4 > number-of-conditions
071000              go to action-store.
071100     move     dummy-stub to condition-stub (index4).
071200     add      1 to index4.
071300     go       to entry-loader.
071400*
071500 action-store.
071600*************
071700*
071800     move     dummy-stub to action-stub (index5).
071900     add      1 to index5.
072000*
072100 entry-loader.
072200*************
072300*
072400     add      1 to index3.
072500     move     1 to index2.
072600     move     spaces to dummy-entry.
072700     if       index1 = 80
072800              go to pcr.
072900     move     first-column (index3) to index1.
073000*
073100 rule-mover.
073200***********
073300*
073400     move     card-image (index1) to temp-col (index2)
073500     if       index2 = number-of-columns (index3)
073600              go to entry-store.
073700     add      1 to index1 index2.
073800     if       index1 not > 80
073900              go to rule-mover.
074000*
074100 pcr.
074200****
074300*
074400     perform  card-read.
074500     perform  list-input.
074600     move     1 to index1.
074700*
074800     if       cd-seq not numeric
074900              go to rule-mover.
075000     if       cd-seq not > ws-seq
075100              perform warning1.
075200     move     cd-seq to ws-seq.
075300*
075400     go       to rule-mover.
075500*
075600 entry-store.
075700************
075800*
075900     move     index1 to kolumns.
076000     perform  left-justifi thru justifi-exit.
076100     move     kolumns to index1.
076200     move     dummy-entry1 to entry-matrix (index7, index6).
076300     if       index7 > number-of-conditions
076400              go to skipformchange.
076500     if       dummy-entry1 = x-entry or y-entry or
076600                             n-entry or spaces
076700              go to skipformchange.
076800     move     space to form.
076900*
077000 skipformchange.
077100***************
077200*
077300     add      1 to index6.
077400     if       index6 = number-of-rules + 1
077500              go to nextcard.
077600     go       to entry-loader.
077700*
077800 left-justifi.
077900*************
078000*
078100     move     1 to index1 index2.
078200     move     spaces to dummy-entry1.
078300*
078400 justifi-loop.
078500*************
078600*
078700     if       temp-col (index1) = space
078800              go to inc1.
078900*
079000 move-entry.
079100***********
079200*
079300     move     temp-col (index1) to dumy-char (index2).
079400     add      1 to index1 index2.
079500     if       index1 not > 18
079600              go to move-entry.
079700     go       to justifi-exit.
079800*
079900 inc1.
080000*****
080100*
080200     add      1 to index1.
080300     if       index1 not > 18
080400              go to justifi-loop.
080500*
080600 justifi-exit.
080700*************
080800*
080900     exit.
081000*
081100 table-processor.
081200****************
081300*
081400     move     spaces to rough-statement new-image.
081500     move     spaces to a-card.
081600     move     zero to deleted-conditions a-margin-flag.
081700     move     1 to elseflag index1 index2.
081800*
081900 row-set.
082000********
082100*
082200     move     entry-matrix (index2, index1) to dummy-entry.
082300     add      1 to index1.
082400*
082500 find-loop.
082600**********
082700*
082800     if       index1 = number-of-rules
082900              go to row-found.
083000     if       entry-matrix (index2, index1) not = dummy-entry
083100              go to next-row.
083200     add      1 to index1.
083300     go       to find-loop.
083400*
083500 row-found.
083600**********
083700*
083800     add      1 to deleted-conditions.
083900     perform  mixed-statement-staging thru mssexit.
084000     move     spaces to row (index2).
084100*
084200 next-row.
084300*********
084400*
084500     move     1 to index1.
084600     add      1 to index2.
084700     if       index2 not > number-of-conditions
084800              go to row-set.
084900*
085000 mixed-table-processor.
085100***********************
085200*
085300     move     zero to elseflag actionflag.
085400     add      1 to actinc rulinc.
085500     move     acttag to first-action.
085600     move     1 to index1 index2.
085700     if       form = "L"
085800              go to limited-table-processor.
085900     move     zero to deleted-conditions.
086000*
086100 pick-entry.
086200***********
086300*
086400     if       entry-matrix (index2, index1) not = spaces
086500              go to test-rule.
086600*
086700 bump-ruleindex.
086800***************
086900*
087000     add      1 to index2.
087100     if       index2 not = number-of-conditions
087200              go to gp1.
087300     move     1 to actionflag.
087400*
087500 gp1.
087600****
087700*
087800     if       index2 not > number-of-conditions
087900              go to pick-entry.
088000     move     zero to actionflag elseflag.
088100     add      1 to actinc index1.
088200     move     1 to index2.
088300     if       index1 = number-of-rules
088400              go to generate-actions.
088500     if       index1 not = number-of-rules - 1
088600              go to gp2.
088700     move     1 to elseflag.
088800*
088900 gp2.
089000****
089100*
089200     move     rultag to a-margin.
089300     perform  sequence-ident-fetch thru card-write.
089400     add      1 to rulinc.
089500     go       to pick-entry.
089600*
089700 test-rule.
089800**********
089900*
090000     move     index1 to index6.
090100     move     index2 to index7.
090200*
090300 bumpi7.
090400*******
090500*
090600     add      1 to index7.
090700     if       index7 > number-of-conditions
090800              go to aset.
090900     if       entry-matrix (index7, index6) = spaces
091000              go to bumpi7.
091100     go       to typefinder.
091200*
091300 aset.
091400*****
091500*
091600     move     1 to actionflag.
091700*
091800 typefinder.
091900***********
092000*
092100     move     entry-matrix (index2, index1) to dummy-entry.
092200     perform  mixed-statement-staging thru mssexit.
092300     go       to bump-ruleindex.
092400*
092500 mixed-statement-staging.
092600************************
092700*
092800     if       dummy-entry = spaces
092900              go to mssexit.
093000     perform  stage11.
093100     if       dummy-entry = y-entry
093200              go to trueentry.
093300     if       dummy-entry = n-entry
093400              go to falseentry.
093500     if       actionflag = 1
093600              go to extendedact.
093700     if       elseflag = 1
093800              go to extendedels.
093900     go       to extendedok.
094000*
094100 trueentry.
094200**********
094300*
094400     if       actionflag = 1
094500              go to yesact.
094600     if       elseflag = 1
094700              go to yesels.
094800     go       to yesok.
094900*
095000 falseentry.
095100***********
095200*
095300     if       actionflag = 1
095400              go to noact.
095500     if       elseflag = 1
095600              go to noels.
095700     go       to nook.
095800*
095900 stage1.
096000*******
096100*
096200     move     sub-set-rultag to false-path.
096300*
096400 stage2.
096500*******
096600*
096700     move     else-go-to-plug to false-action.
096800*
096900 stage3.
097000*******
097100*
097200     move     next-sentence-plug to true-action.
097300*
097400 stage4.
097500*******
097600*
097700     move     sub-set-elstag to false-path.
097800*
097900 stage5.
098000*******
098100*
098200     move     sub-set-rultag to true-path.
098300*
098400 stage6.
098500*******
098600*
098700     move     go-to-plug to true-action.
098800*
098900 stage7.
099000*******
099100*
099200     move     sub-set-acttag to true-path.
099300*
099400 stage8.
099500*******
099600*
099700     move     sub-set-acttag to false-path.
099800*
099900 stage9.
100000*******
100100*
100200     move     sub-set-elstag to true-path.
100300*
100400 stage10.
100500********
100600*
100700     move     dummy-entry to value-slot.
100800*
100900 stage11.
101000********
101100*
101200     move     if-plug to ifslot.
101300     move     condition-stub (index2) to stub-area.
101400*
101500 yesok.
101600******
101700*
101800     perform  stage1 thru stage3.
101900     go       to reducer.
102000*
102100 yesact.
102200*******
102300*
102400     perform  stage6 thru stage7.
102500     go       to reducer.
102600*
102700 yesels.
102800*******
102900*
103000     perform  stage2 thru stage4.
103100     go       to reducer.
103200*
103300 nook.
103400*****
103500*
103600     perform  stage5 thru stage6.
103700     go       to reducer.
103800*
103900 noact.
104000******
104100*
104200     perform  stage2 thru stage3.
104300     perform  stage8.
104400     go       to reducer.
104500*
104600 noels.
104700******
104800*
104900     perform  stage6.
105000     perform  stage9.
105100     go       to reducer.
105200*
105300 extendedok.
105400***********
105500*
105600     perform  stage10.
105700     go       to yesok.
105800*
105900 extendedact.
106000************
106100*
106200     perform  stage10.
106300     go       to yesact.
106400*
106500 extendedels.
106600************
106700*
106800     perform  stage10.
106900     go       to yesels.
107000*
107100 reducer.
107200********
107300*
107400     perform  reduce-staging-area thru rsaexit.
107500*
107600 mssexit.     exit.
107700********
107800*
107900 limited-table-processor.
108000************************
108100*
108200     move     zeros to totaltable.
108300     move     1 to index1 index2.
108400*
108500 blank-count-loop.
108600*****************
108700*
108800     if       entry-matrix (index2, index1) = spaces
108900              add  1 to total-rule (index2).
109000*
109100 not-a-blank.
109200************
109300*
109400     add      1 to index1.
109500     if       index1 < number-of-rules
109600              go to blank-count-loop.
109700     move     1 to index1.
109800     add      1 to index2.
109900     if       index2 not > number-of-conditions
110000              go to blank-count-loop.
110100     move     1 to index1 index3.
110200     move     2 to index2 index4.
110300     move     26 to index5.
110400*
110500 sortloop.
110600*********
110700*
110800     if       total-rule (index1) not > total-rule (index2)
110900              go to srt1.
111000     move     condition-stub (index1) to condition-stub (index5).
111100     move     condition-stub (index2) to condition-stub (index1).
111200     move     condition-stub (index5) to condition-stub (index2).
111300     move     row (index1) to row (index5).
111400     move     row (index2) to row (index1).
111500     move     row (index5) to row (index2).
111600     move     total-rule (index1) to total-rule (index5).
111700     move     total-rule (index2) to total-rule (index1).
111800     move     total-rule (index5) to total-rule (index2).
111900     subtract 1 from index1.
112000     subtract 1 from index2.
112100     if       index1 not = zero
112200              go to sortloop.
112300*
112400 srt1.
112500*****
112600*
112700     add      1 to index3 index4.
112800     move     index3 to index1.
112900     move     index4 to index2.
113000     if       index2 not > number-of-conditions
113100              go to sortloop.
113200*
113300 scan-routine.
113400*************
113500*
113600     subtract deleted-conditions from number-of-conditions.
113700     move     zero to ycounttable ncounttable totaltable.
113800     move     spaces to yestagstack notagstack.
113900     move     1 to index1 index2 index3 index4.
114000*
114100 scan-loop.
114200**********
114300*
114400     move     zero to space-flag.
114500     add      1 to total-rule (index2).
114600     if       entry-matrix (index2, index1) = y-entry
114700              go to y-path.
114800     if       entry-matrix (index2, index1) = n-entry
114900              go to n-path.
115000     move     1 to space-flag.
115100*
115200 y-path.
115300*******
115400*
115500     add      1 to relative-y (index2).
115600     if       index2 = number-of-conditions
115700              go to set-yes-action.
115800     move     r-entry to entry-matrix (index2, index1).
115900     if       true-tag (index2) not = spaces
116000              go to skiptaginsert.
116100     move     sub-set-rultag to true-tag (index2).
116200     add      1 to rulinc.
116300*
116400 skiptaginsert.
116500**************
116600*
116700     if       space-flag = 1
116800              go to n-path.
116900     go       to rs1.
117000*
117100 set-yes-action.
117200***************
117300*
117400     compute  tag-number = first-inc + index1 - 1.
117500     move     "ACT" to tag-type.
117600     move     sub-set-builder to true-tag (index2).
117700     if       space-flag = zero
117800              go to rs1.
117900*
118000 n-path.
118100*******
118200*
118300     add      1 to relative-n (index2).
118400     if       index2 not = number-of-conditions
118500              go to skipdown.
118600     compute  tag-number = first-inc + index1 - 1.
118700     move     "ACT" to tag-type.
118800     move     sub-set-builder to false-tag (index2).
118900     go       to rs1.
119000*
119100 skipdown.
119200*********
119300*
119400     add      1 to index2.
119500     go       to scan-loop.
119600*
119700 rs1.
119800****
119900*
120000     move     index4 to index2.
120100     if       index2 not = 1
120200              go to resetscan.
120300     add      1 to index1.
120400     if       index1 = number-of-rules
120500              go to scancomplete.
120600     go       to scan-loop.
120700*
120800 resetscan.
120900**********
121000*
121100     subtract 1 from index2 giving index5.
121200*
121300 rs2.
121400****
121500*
121600     add      1 to index1.
121700     if       index1 = number-of-rules  go to scancomplete.
121800     if       entry-matrix (index5, index1) not = r-entry
121900              go to rs2.
122000     move     spaces to entry-matrix (index5, index1).
122100     go       to scan-loop.
122200*
122300 scancomplete.
122400*************
122500*
122600     move     number-of-conditions to index2.
122700     if       total-rule (index2) > 2
122800              perform error6
122900              perform error7
123000              go to main-loop.
123100     if       total-rule (index2) < 2
123200              go to check-spacing.
123300     if       relative-y (index2) not = 1 or
123400              relative-n (index2) not = 1
123500              perform error6
123600              perform error7
123700              go to main-loop.
123800     go       to check-spacing.
123900*
124000 check-spacing.
124100**************
124200*
124300     move     1 to index2.
124400*
124500 csloop.
124600*******
124700*
124800     if       relative-y (index2) = 1
124900              go to spacesearch.
125000*
125100 csinc.
125200******
125300*
125400     add      1 to index2.
125500     if       index2 not > number-of-conditions
125600              go to csloop.
125700     go       to checkystack.
125800*
125900 spacesearch.
126000************
126100*
126200     move     1 to index1.
126300     move     index2 to index7.
126400*
126500 ssloop.
126600*******
126700*
126800     if       entry-matrix (index2, index1) = r-entry
126900              go to spaceloop.
127000     add      1 to index1.
127100     if       index1 < number-of-rules
127200              go to ssloop.
127300     go       to csinc.
127400*
127500 spaceloop.
127600**********
127700*
127800     add      1 to index7.
127900     if       index7 > number-of-conditions
128000              go to set-action.
128100     if       entry-matrix (index7, index1) = spaces
128200              go to spaceloop.
128300     if       entry-matrix (index7, index1) = y-entry
128400              go to spaceloop.
128500     go       to csinc.
128600*
128700 set-action.
128800***********
128900*
129000     compute  tag-number = index1 + first-inc - 1.
129100     move     "ACT" to tag-type.
129200     move     sub-set-builder to true-tag (index2).
129300     move     y-entry to entry-matrix (index2, index1).
129400     go       to csinc.
129500*
129600 checkystack.
129700************
129800*
129900     move     index4 to index2.
130000*
130100 truestackloop.
130200**************
130300*
130400     if       true-tag (index2) not = spaces
130500              go to ryc2.
130600     move     sub-set-elstag to true-tag (index2).
130700*
130800 ryc2.
130900*****
131000*
131100     add      1 to index2.
131200     if       index2 > number-of-conditions
131300              go to checknos.
131400     go       to truestackloop.
131500*
131600 checknos.
131700*********
131800*
131900     move     index4 to index2.
132000*
132100 falsestackloop.
132200****************
132300*
132400     if       relative-n (index2) not = zeros
132500              go to rnc2.
132600     move     sub-set-elstag to false-tag (index2).
132700*
132800 rnc2.
132900*****
133000*
133100     add      1 to index2.
133200     if       index2 not > number-of-conditions
133300              go to falsestackloop.
133400     move     number-of-conditions to index2.
133500*
133600 checkforsamepath.
133700*****************
133800*
133900     if       true-tag (index2) not = false-tag (index2)
134000              go to decrement.
134100     move     index2 to index3.
134200     subtract 1 from index3.
134300     move     false-tag (index2) to false-tag (index3).
134400     move     spaces to true-tag (index2) false-tag (index2).
134500     move     zeros to total-rule (index2).
134600*
134700 decrement.
134800**********
134900*
135000     subtract 1 from index2.
135100     if       index2 not < index4
135200              go to checkforsamepath.
135300     move     index4 to index2.
135400*
135500 limited-coding-loop.
135600********************
135700*
135800     if       total-rule (index2) = zeros
135900              go to skip-coding.
136000     if       false-tag (index2) not = spaces
136100              go to lcl1.
136200     perform  stage-l1.
136300     go       to gpwrite.
136400*
136500 lcl1.
136600*****
136700*
136800     perform  stage-l1 thru stage-l2.
136900     go       to gpwrite.
137000*
137100 stage-l1.
137200*********
137300*
137400     move     if-plug to ifslot.
137500     move     condition-stub (index2) to stub-area.
137600     move     true-tag (index2) to true-path.
137700     move     go-to-plug to true-action.
137800*
137900 stage-l2.
138000*********
138100*
138200     move     else-go-to-plug to false-action.
138300     move     false-tag (index2) to false-path.
138400*
138500 gpwrite.
138600********
138700*
138800     perform  reduce-staging-area thru rsaexit.
138900*
139000 skip-coding.
139100************
139200*
139300     add      1 to index2.
139400     if       index2 not > number-of-conditions
139500              go to limited-coding-loop.
139600*
139700 tag-search-loop.
139800****************
139900*
140000     subtract 1 from index2.
140100     if       index2 = zero
140200              go to generate-actions.
140300     move     true-tag (index2) to sub-set-builder.
140400     move     spaces to true-tag (index2).
140500     if       tag-type not = "RUL"
140600              go to tag-search-loop.
140700     move     tag-building-slot to a-margin.
140800     perform  sequence-ident-fetch thru card-write.
140900     move     zeros to ycounttable ncounttable totaltable index1.
141000     move     spaces to notagstack.
141100     add      1 to index2.
141200     move     index2 to index4.
141300     go       to rs1.
141400*
141500 generate-actions.
141600*****************
141700*
141800* write else table
141900*
142000     move     first-inc to actinc.
142100     move     1 to index3.
142200     move     number-of-rules to index1.
142300     compute  index2 =
142400                    number-of-conditions + 1 + deleted-conditions.
142500     move     elstag to a-margin.
142600     perform  sequence-ident-fetch thru card-write.
142700*
142800 else1.
142900******
143000*
143100     if       entry-matrix (index2, index1) = spaces
143200              go to else2.
143300     perform  action-builder thru skipvalue.
143400*
143500 else2.
143600******
143700*
143800     add      1 to index3 index2.
143900     if       index2 not > row-count
144000              go to else1.
144100     move     1 to index1 index3.
144200     if       g-suppress
144300              go to action-stub-loop.
144400*
144500     move     go-to-plug to true-action.
144600     move     sub-set-tabext to true-path.
144700     perform  reduce-staging-area thru rsaexit.
144800*
144900 action-stub-loop.
145000*****************
145100*
145200* write action tables
145300*
145400     compute  index2 =
145500                   number-of-conditions + 1 + deleted-conditions.
145600     move     acttag to a-margin.
145700     perform  sequence-ident-fetch thru card-write.
145800*
145900 rule-scan.
146000**********
146100*
146200     if       entry-matrix (index2, index1) = spaces
146300              go to rule-scan1.
146400     perform  action-builder thru skipvalue.
146500*
146600 rule-scan1.
146700***********
146800*
146900     add      1 to index2 index3.
147000     if       index2 not > row-count
147100              go to rule-scan.
147200     if       not g-suppress
147300              move    sub-set-tabext to true-path
147400              move    go-to-plug to true-action
147500              perform reduce-staging-area thru rsaexit.
147600     add      1 to index1 actinc.
147700     move     1 to index3.
147800     if       index1 not = number-of-rules
147900              go to action-stub-loop.
148000*
148100 end-the-table.
148200**************
148300*
148400* write end table
148500*
148600     move     tabext to a-margin.
148700     perform  sequence-ident-fetch thru card-write.
148800     move     "EXIT." to b-margin.
148900     perform  sequence-ident-fetch thru card-write.
149000     add      1 to tabinc elsinc.
149100     move     spaces to yestagstack notagstack current-header.
149200     move     spaces to dummy-stub dummy-entry dummy-entry1.
149300     move     spaces to stub-table table-array.
149400     move     zeros to ycounttable ncounttable totaltable
149500                       rule-index.
149600     go       to main-loop.
149700*
149800 action-builder.
149900***************
150000*
150100     if       entry-matrix (index2, index1) = x-entry
150200              go to skipvalue.
150300     move     entry-matrix (index2, index1) to value-slot.
150400*
150500 skipvalue.
150600**********
150700*
150800     move     action-stub (index3) to stub-area.
150900     perform  reduce-staging-area thru rsaexit.
151000*
151100 reduce-staging-area.
151200********************
151300*
151400     move     zero to space-flag literal-flag.
151500     move     137 to index5.
151600*
151700 period-pack.
151800************
151900*
152000     subtract 1 from index5.
152100     if       staging-area (index5) = space
152200              go to period-pack.
152300     add      1 to index5.
152400     move     "." to staging-area (index5).
152500     move     1 to index6 index7.
152600     if       a-margin-flag = zero
152700              go to packing-loop.
152800     move     4 to index6.
152900*
153000 packing-loop.
153100*************
153200*
153300     if       staging-area (index6) = quote
153400              go to literal-handler.
153500     if       literal-flag = 1
153600              go to skip-space-check.
153700     if       staging-area (index6) = space
153800              go to space-accounting.
153900     move     zero to space-flag.
154000*
154100 skip-space-check.
154200*****************
154300*
154400     move     staging-area (index6) to instruction-field (index7).
154500     add      1 to index7.
154600*
154700 skip-move.
154800**********
154900*
155000     add      1 to index6.
155100     if       index6 > index5
155200              go to finish-path.
155300     if       index7 not > 61
155400              go to packing-loop.
155500     move     new-image to b-margin.
155600     move     spaces to new-image.
155700     perform  sequence-ident-fetch thru card-write.
155800     move     "-" to continuation-column.
155900     move     1 to index7.
156000     go       to packing-loop.
156100*
156200 literal-handler.
156300****************
156400*
156500     move     zero to space-flag.
156600     if       literal-flag = 1
156700              go to clearit.
156800     move     1 to literal-flag.
156900     go       to skip-space-check.
157000*
157100 clearit.
157200********
157300*
157400     move     zero to literal-flag.
157500     go       to skip-space-check.
157600*
157700 space-accounting.
157800*****************
157900*
158000     if       index7 < 49
158100              go to no-bias.
158200     move     new-image to b-margin.
158300     move     spaces to new-image.
158400     perform  sequence-ident-fetch thru card-write.
158500     move     4 to index7.
158600*
158700 no-bias.
158800********
158900*
159000     if       space-flag = 1
159100              go to skip-move.
159200     move     1 to space-flag.
159300     go       to skip-space-check.
159400*
159500 a1.
159600***
159700*
159800     move     new-image to a-margin.
159900     go       to areturn.
160000*
160100 finish-path.
160200************
160300*
160400     move     spaces to rough-statement.
160500     if       a-margin-flag = 1
160600              go to a1.
160700     move     new-image to b-margin.
160800*
160900 areturn.
161000********
161100*
161200     move     spaces to new-image.
161300     perform  sequence-ident-fetch thru card-write.
161400*
161500 rsaexit.     exit.
161600********      ****
161700*
161800 sequence-ident-fetch.
161900*********************
162000*
162100     add      users-sequence-inc to current-sequence.
162200     move     current-sequence to sequence-field.
162300*
162400*    move     users-ident to ident-field.   *> no longer needed
162500*
162600 card-write.
162700***********
162800*
162900* only print decision related data
163000*
163100     if       in-table-flag not = zero
163200              move a-card to log-record
163300              perform history-write.
163400     write    a-card.
163500     move     spaces to a-card.
163600*
163700 card-read.
163800**********
163900*
164000     read     input-file at end
164100              go to end-of-file.
164200*
164300 history-write.
164400**************
164500*
164600     write    log-record.
164700     move     spaces to log-record.
164800     add      1 to line-cnt.
164900     if       line-cnt > 60
165000              perform headings thru headings-exit.
165100*
165200 list-input.
165300***********
165400*
165500     move     card-buffer to log-record.
165600     perform  history-write.
165700*
165800 end-of-file.
165900************
166000*
166100     close    input-file transout transhist.
166200     if       warning-flag not = zero
166300              display "CAUTION:"
166400              display "Warnings".   *> upon crt-under.
166500     if       error-flag not = zero
166600              display "CAUTION:"
166700              display "Errors".     *> upon crt-under.
166800     stop     run.
166900*
167000 log-warning.
167100************
167200*
167300     move     1 to warning-flag.
167400     move     warning-line (warning-type) to log-message.
167500     move     warning-message to history-record.
167600     perform  history-write.
167700*
167800 warning1.
167900*********
168000*
168100     move     1 to warning-type.
168200     perform  log-warning.
168300*
168400 warning3.
168500*********
168600*
168700     move     3 to warning-type.
168800     perform  log-warning.
168900*
169000 log-error.
169100**********
169200*
169300     move     1 to error-flag.
169400     move     error-line (error-type) to log-message.
169500     move     error-message to history-record.
169600     perform  history-write.
169700*
169800 error6.
169900*******
170000*
170100     move     6 to error-type.
170200     perform  log-error.
170300*
170400 error7.
170500*******
170600*
170700     move     7 to error-type.
170800     perform  log-error.
170900*
171000 error11.
171100********
171200*
171300     move     11 to error-type.
171400     perform  log-error.
171500*
171600 error13.
171700********
171800*
171900     move     13 to error-type.
172000     perform  log-error.
172100*
172200 headings.
172300*********
172400*
172500     add      1 to page-cnt.
172600     move     page-cnt to p-page.
172700     move     zero to line-cnt.
172800     write    log-record from ws-head1.
172900     write    log-record from ws-head2.
173000     move     spaces to log-record.
173100*
173200 headings-exit. exit.
173300**************  ****
