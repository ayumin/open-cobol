      *>******************************************************
      *> star_trek simulates an outer space adventure game   *
      *> on a remote terminal.  The user commands the U.S.S. *
      *> Enterprise, and thru various offensive and defen-   *
      *> sive commands, travels throughout the galaxy on a   *
      *> mission to destroy all Klingons, which also maneu-  *
      *> ver and fire on the Enterprise.                     *
      *>******************************************************
      *> Tectonics: cobc -free -x ctrek.cob
      *>******************************************************

       identification division.
       program-id. star_trek.
      *>author.  Kurt Wilhelm.
      *>installation.  Oakland University.
      *>date-written.  Completed September 1, 1979.

      *> Harald Arnesen <harald@skogtun.org>, 2010-03-24:
      *>
      *> Ported to OpenCobol 1.1 by changing the comments
      *> to free format, as some lines are too long for fixed format.
      *>
      *> I haven't played it, just checked that it compiles and runs!
      *>
      *> Original source:
      *> <http://www.dunnington.u-net.com/public/startrek/ctrek.cob>

       environment division.
       configuration section.
       source-computer.  multics.
       object-computer.  multics.

       data division.
       working-storage section.
       01  eof-flag                  pic x value "n".
       01  star-table.
           05  row      occurs 42 times.
               10  kolumn            pic x occurs 42 times.
       01  rctr                      pic 99.
       01  kctr                      pic 99.
       01  commands-x.
           05  command               pic x(3).
               88  navigate          value "nav".
               88  phasers           value "pha".
               88  torpedo           value "tor".
               88  shields           value "def".
               88  dock              value "doc".
               88  lib-com           value "com".
               88  nav-c             value "NAV".
               88  pha-c             value "PHA".
               88  tor-c             value "TOR".
               88  def-c             value "DEF".
               88  doc-c             value "DOC".
               88  com-c             value "COM".
           05  entry1                pic 9.
           05  entry2                pic 9.
       01  mini-table.
           05  mrow     occurs 14 times.
               10  mcol              pic x occurs 14 times.
       01  rcntr                     pic 99.
       01  kcntr                     pic 99.
       01  x                         pic 999.
       01  y                         pic 999.
       01  ws-date                   pic 9(4) comp-5.
       01  time-flag                 pic 9.
           88  time-flag-set         value 1.
       01  max-no                    pic 999.
       01  hq1                       pic 9.
       01  hq2                       pic 9.
       01  t-store                   pic 9(4) comp-5.
       01  attack-flag               pic 9.
           88  klingons-attacking    value 1.
       01  too-late-flag             pic 9.
           88  too-late              value 1.
       01  bye-k                     pic 99.
       01  var1                      pic 99 value 1.
       01  var2                      pic 9(6) comp-5.
       01  var3                      pic 9(6) comp-5.
       01  var4                      pic 9(4) comp-5.
       01  var4-an                   pic x(4).
       01  var5                      pic zzz999.
       01  var6                      pic zzzz99.
       01  return-x                  pic x.
       01  comp-com                  pic 9.
       01  base-cnt                  pic 9 value 0.
       01  nx                        pic 99 value 0.
       01  a                         pic 999.
       01  b                         pic 999.
       01  warp1                     pic 99.
       01  warp2                     pic 99.
       01  warp3                     pic 99.
       01  warp4                     pic 99.
       01  generate-table.
           05  char                  pic x occurs 25 times.
       01  seed-table                pic x(25) value
               "a4hfxnc89kd3jxf5dks3hb3m1".
       01  genrte-result             pic 9.
           88  no-way                value 1.
       01  fuel-count                pic s9(5) comp-5.
       01  torps                     pic 9 value 5.
       01  prt-lines.
           05  con-red.
               10  filler            pic x(16) value
                   "*Condition RED* ".
               10  klgns             pic 99.
               10  filler            pic x(21) value
                   " Klingons in quadrant".
           05  con-green.
               10  filler            pic x(17) value
                   "*Condition GREEN*".
           05  com-req.
               10  filler            pic x(22) value
                   "What is your command? ".
       01  master-tbl.
           05  marow     occurs 126 times.
               10  macol             pic x occurs 126 times.
       01  mrctr                     pic 999.
       01  mkctr                     pic 999.
       01  vab1                      pic 9.
       01  vab2                      pic 99.
       01  roll-x                    pic 999v.
       01  shield-cnt                pic s9(4) comp-5.
       01  shield-cnt-an             pic x(4).
       01  damage-cnt                pic 9(6) comp-5.
       01  scan-keep.
           05  cv                    pic 99 occurs 18 times.
       01  scan-ctr                  pic 99.
       01  scan-table.
           05  scan-row     occurs 14 times.
               10 scan-col           pic x occurs 14 times.
       01  rx-s                      pic 99v99.
       01  qt                        pic 99.
       01  rt                        pic 99.
       01  qx                        pic 99.
       01  rx                        pic 99.
       01  tr1                       pic 9.
       01  tr2                       pic 9.
       01  ktctr                     pic 99.
       01  rtctr                     pic 99.
       01  name-var.
           05  name-x                pic x(12).
       01  inst-reply                pic x(3).
           88  yes-reply             value "yes".
       01  indicate-y                pic 9.
           88  trap-vec              value 1.
       01  indicate-x                pic 9.
           88  bye-bye               value 1.
       01  indicate-z                pic 9.
           88  just-starting         value 0.
       01  quadrant.
           05  filler                pic x(9) value "Quadrant ".
           05  q1                    pic 9.
           05  filler                pic x value ",".
           05  q2                    pic 9.
           05  filler                pic x(15) value
               "    STAR DATE: ".
           05  s-date                pic 9(4).
       01  ds-date                   pic 9(4).
       01  ds-table.
           05  ds-min                pic 99.
           05  ds-sec                pic 99.
       01  klingons                  pic 99.
       01  romulons                  pic 99.
       01  lst-reply                 pic x(3).
           88  yes-lst               value "yes".
       01  rev-str                   pic 9(6) comp-5.
       01  seed-x                    pic v9(6) comp-5.
       01  seed-ast                  pic 9(6)v9(6) comp-5.
       01  ws-time.
           05  ws-hour               pic 99.
           05  ws-min                pic 99.
           05  ws-sec                pic 99.
           05  ws-sixty              pic 99.
       01  time-rev.
           05  ws-sixty              pic 99.
           05  ws-sec                pic 99.
           05  ws-min                pic 99.
       01  warp-speed.
           05  warp-a                pic 9.
           05  warp-pt               pic x.
           05  warp-b                pic 99.
       01  course-x.
           05  course-a              pic 9.
           05  course-pt             pic x.
           05  course-b              pic 99.
       01  vab5                      pic 99.
       01  vab6                      pic 99.
       01  vae1                      pic z9.
       01  k-or                      pic 99.
       01  qs-1                      pic 9.
       01  qs-2                      pic 9.
       01  srctr                     pic s999.
       01  skctr                     pic s999.
       01  mod-ctr                   pic 99.
       01  md-row.
           05  md-sub                pic x occurs 28 times.
       01  dm-var4                   pic 9(4) comp-5.

       01  ct-k                      pic 99.
       01  ct-r                      pic 99.
       01  dist-x                    pic 99.
       01  dist-r                    pic 99.
       01  dist-b                    pic 99.
       01  tal4                      pic 9.
       01  kh-tl                     pic 9(5) comp-5.
       01  str-a                     pic 99.
       01  str-r                     pic 99.
       01  str-x                     pic 99.
       01  cx                        pic 999 comp-5.
       01  dx                        pic 999 comp-5.
       01  cx-1                      pic 9.
       01  dx-1                      pic 9.
       01  e1                        pic 99.
       01  e2                        pic 99.
       01  r1                        pic 99.
       01  r2                        pic 99.
       01  k1                        pic 99.
       01  k2                        pic 99.
       01  b1                        pic 99.
       01  b2                        pic 99.
       01  star-ctr                  pic 999.
       01  rep-ctr                   pic 99.
       01  fuel-co                   pic zzz99.
       01  shield-co                 pic zz99.
       01  sbl                       pic 9.
       01  qt1                       pic 9.
       01  qt2                       pic 9.
       01  qt3                       pic 9.
       01  qt4                       pic 9.
       01  r9                        pic 9.
       01  q9                        pic 9.
       01  w                         pic 999.
       01  z                         pic 999.
       01  skill-lev                 pic 9.
       01  dist-k-str.
           05  dkc                   pic 99 occurs 45 times.
       01  dist-r-str.
           05  drc                   pic 99 occurs 60 times.

       procedure division.

       0000-control section.
       0000-program-control.
           perform 0100-housekeeping thru 0100-exit.
           perform 1000-mainline thru 1000-exit.
           perform 9000-end-of-job thru 9000-exit.
           stop run.

      *>***********************************************
      *> 0100-housekeeping initializes variables, and *
      *> asks the user for a name and skill level.    *
      *> It then determines the quantity of bases,    *
      *> klingons, and romulons in the galaxy.        *
      *> Instructions are a user option.              *
      *>***********************************************

       0100-housekeeping-section section.
       0100-housekeeping.
           move 0 to shield-cnt.
           move 0 to damage-cnt.
           move 40000 to fuel-count.
           move 0 to indicate-z.
           move 0 to genrte-result.
           move spaces to md-row.
           move seed-table to generate-table.
           move 0 to indicate-x.
           move 0 to indicate-y.
           move 0 to attack-flag.
           move 0 to too-late-flag.
           display "      ".
           display "      *STAR TREK* ".
           display "      ".
           display "Congratulations - you have just been appointed ".
           display "Captain of the U.S.S. Enterprise. ".
           display "      ".
           display "Please enter your name, Captain ".
           accept name-x.
           display "And your skill level (1-4)? ".
           accept skill-lev.
           if skill-lev not numeric or skill-lev < 1 or skill-lev > 4
               display "INVALID SKILL LEVEL "
               display "Enter your skill level (1-4) "
               accept skill-lev
               if skill-lev not numeric or skill-lev < 1 or skill-lev > 4
                   move 1 to skill-lev
                   display "Your skill level must be 1 ".
           move 0 to vab5.
           move 0 to vab6.
           inspect name-x tallying vab6 for all "a".
           inspect name-x tallying vab6 for all "e".
           add 1 to vab6.
           inspect name-x tallying vab5 for all " ".
           compute vab6 rounded = (vab5 / 1.75) + (vab6 / skill-lev).
           compute k-or rounded = (skill-lev * 4) + vab6 + 5.
           compute vab1 = 9 - skill-lev.
           compute vab2 rounded = (skill-lev / 3) * k-or.
           move k-or to klingons.
           move vab1 to vae1.
           accept ws-time from time.
           move ws-min of ws-time to ds-min.
           move ws-sec of ws-time to ds-sec.
           move ds-table to s-date.
           add 16 to ds-min.
           if ds-min > 59
               move 1 to time-flag
           else
               move 0 to time-flag.
           move ds-table to ds-date.
           display "      ".
           display "      *MESSAGE FROM STAR FLEET COMMAND* ".
           display "      ".
           display "Attention - Captain " name-x.
           display "Your mission is to destroy the ".
           display k-or " Klingon ships that have invaded ".
           display "the galaxy to attack Star Fleet HQ ".
           display "on star date " ds-date " - giving you 16 star dates.".
           perform 1200-initialize-galaxy thru 1200-exit.
           display "      ".
           display "Do you require instructions? ".
           accept inst-reply.
           if yes-reply
               perform 0500-prt-inst thru 0500-exit
               perform 0550-add-inst thru 0550-exit.
       0100-exit.  exit.

       0500-prt-inst.
           display "      ".
           display "You may use the following commands: ".
           display "       nav  (to navigate) ".
           display "       pha  (to fire phasers) ".
           display "       tor  (to fire torpedo) ".
           display "       def  (to raise or lower shields) ".
           display "       doc  (to dock at a star base) ".
           display "       com  (to request info from the library computer) ".
           display "      ".
           display "COURSE PLOT: ".
           display "      ".
           display "    1 ".
           display "  8   2 ".
           display "7  -x-  3 ".
           display "  6   4 ".
           display "    5 ".
           display "      ".
       0500-exit.  exit.

       0550-add-inst.
           display "There are " vae1 " star bases located somewhere in the galaxy, ".
           display "which is made up of 81 quadrants, 1,1 thru 9,9. ".
           display "You may dock at a star base to refuel and effect repairs ".
           display "when there is a base in your quadrant.  You are authorized ".
           display "to destroy Romulon vessels if they interfere with your mission. ".
           display "      ".
           display "Hit RETURN ".
           accept return-x.
       0550-exit.  exit.

       1000-mainline.
           perform 4000-display-g thru 4000-exit.
           move 1 to indicate-z.
           perform 2000-process thru 2000-exit
               until klingons < 1 or bye-bye.
           perform 8500-finish-game thru 8500-exit.
       1000-exit.  exit.

       1100-chk-galaxy.
           add 1 to var1.
           if var1 = 7
               inspect master-tbl replacing all "      K" by "K      "
               perform 1120-reset thru 1120-exit
           else
               if var1 = 12
                   inspect master-tbl replacing all "R      " by "      R"
                   perform 1120-reset thru 1120-exit
               else
                   if var1 = 15
                       inspect master-tbl replacing all "K           " by "           K"
                       perform 1120-reset thru 1120-exit
                   else
                       if var1 > 20
                           inspect master-tbl replacing all "         R" by "R         "
                           perform 1120-reset thru 1120-exit
                           move 1 to var1.
       1100-exit.  exit.

       1120-reset.
           perform 5900-trans thru 5900-exit.
           move 0 to klgns.
           move 0 to romulons.
           move 0 to base-cnt.
           inspect mini-table tallying klgns for all "K".
           inspect mini-table tallying romulons for all "R".
           inspect mini-table tallying base-cnt for all "B".
       1120-exit.  exit.

       1145-ck-flag.
           if time-flag-set and ds-min < 40

           add 60 to ds-min.
       1145-exit.  exit.

       1150-ck-time.
           if klingons > 0
               accept ws-time from time
               move ws-min of ws-time to ds-min
               perform 1145-ck-flag thru 1145-exit
               move ws-sec of ws-time to ds-sec
               move ds-table to s-date
           else
               go to 1150-exit.
           compute t-store = ds-date - s-date.
           if t-store < 90 and not klingons-attacking
               move 14 to max-no
               compute w = ((hq2 - 1) * 14)
               compute z = ((hq1 - 1) * 14)
               inspect master-tbl replacing all "K" by " "
               move 0 to rx
               perform 1170-move-on-hq thru 1170-exit
                   varying kctr from 1 by 1 until kctr > klingons
               move 1 to attack-flag
               perform 5900-trans thru 5900-exit
               if (q1 not = hq1 or q2 not = hq2)
                   display "WARNING - STAR DATE: " s-date
                   display "Science Officer Spock advises"
                   display "you navigate to quadrant " hq1 "," hq2
                   display "to defend Star Fleet Headquarters".
           if not too-late
               move ds-date to ws-date.
           if s-date > ws-date and q1 = hq1 and q2 = hq2 and not too-late
               move 1 to too-late-flag
               add 230 to ws-date
           else
               if s-date > ws-date
                   move 1 to indicate-x
                   perform 8200-ck-done thru 8200-exit.
       1150-exit.  exit.

       1160-dbl-k.
           perform 1225-dbl-roll thru 1225-exit.
           add 1 to rx.
           compute a = w + a.
           compute b = z + b.
       1160-exit.  exit.

       1170-move-on-hq.
           move 0 to a.
           perform 1160-dbl-k thru 1160-exit
               until macol (a , b) = " " and a > 0.
           move "K" to macol (a , b).
       1170-exit.  exit.

      *>*********************************************
      *> 1200-initialize-galaxy moves stars, kling- *
      *> ons, romulons, bases, and finally, the en- *
      *> terprise to master-tbl in random position, *
      *> and in the quantities determined in 0100-  *
      *> housekeeping.                              *
      *>*********************************************

       1200-initialize-galaxy.
           move spaces to master-tbl.
           accept ws-time from time.
           move corresponding ws-time to time-rev.
           move time-rev to rev-str.
           compute seed-x = (rev-str / 1000000).
           move 126 to max-no.
           perform 1230-move-stars thru 1230-exit
               varying star-ctr from 1 by 1 until star-ctr > 275.
           perform 1240-move-romulons thru 1240-exit
               varying star-ctr from 1 by 1 until star-ctr > vab2.
           perform 1250-move-klingons thru 1250-exit
               varying star-ctr from 1 by 1 until star-ctr > k-or.
           perform 1260-move-base thru 1260-exit
               varying star-ctr from 1 by 1 until star-ctr > vab1.
           perform 1270-move-e thru 1270-exit.
           perform 1280-move-hq thru 1280-exit.
       1200-exit.  exit.

       1220-roll.
           compute seed-ast = (262147.0 * seed-x).
           move seed-ast to seed-x.
           compute roll-x = (seed-x * max-no) + 1.
       1220-exit.  exit.

       1225-dbl-roll.
           perform 1220-roll thru 1220-exit.
           move roll-x to a.
           perform 1220-roll thru 1220-exit.
           move roll-x to b.
       1225-exit.  exit.

       1230-move-stars.
           perform 1225-dbl-roll thru 1225-exit.
           move "*" to macol (a , b).
       1230-exit.  exit.

       1240-move-romulons.
           perform 1225-dbl-roll thru 1225-exit.
           move "R" to macol (a , b).
       1240-exit.  exit.

       1250-move-klingons.
           perform 1225-dbl-roll thru 1225-exit
               until macol (a , b) = " ".
           move "K" to macol (a , b).
       1250-exit.  exit.

       1260-move-base.
           perform 1225-dbl-roll thru 1225-exit
               until macol (a , b) = " ".
           move "B" to macol (a , b).
       1260-exit.  exit.

       1270-move-e.
           perform 1225-dbl-roll thru 1225-exit
               until macol (a , b) = " ".
           move a to mrctr.
           move b to mkctr.
           move "E" to macol (mrctr , mkctr).
       1270-exit.  exit.

       1280-move-hq.
           perform 1225-dbl-roll thru 1225-exit
               until macol (a , b) = " ".
           move "H" to macol (a , b).
           compute hq1 = (b - 1) / 14 + 1.
           compute hq2 = (a - 1) / 14 + 1.
       1280-exit.  exit.

       1700-ck-var-warp.
           inspect course-b replacing all " " by zeros.
           inspect warp-a replacing all " " by zeros.
           inspect warp-b replacing all " " by zeros.
           if course-b not numeric
               move zero to course-b.
           if warp-a not numeric
               move zero to warp-a.
           if warp-b not numeric
               move zero to warp-b.
       1700-exit.  exit.

      *>*******************************************
      *> 2000-process is an iterative loop that   *
      *> requests and executes a command until    *
      *> all klingons are destroyed, or the en-   *
      *> terprise is no longer able to continue.  *
      *>*******************************************

       2000-process.
           perform 8400-generate thru 8400-exit.
           if no-way or klgns > 1
               add 4 to nx.
           display com-req.
           accept commands-x.
           if navigate or nav-c
               if entry1 not numeric or entry1 < 1 or entry1 > 8 or entry2 not numeric
                   display "What course (1 - 8.99)? "
                   accept course-x
                   display "What warp factor (0 - 9.99)? "
                   accept warp-speed
                   perform 1700-ck-var-warp thru 1700-exit
                   perform 7100-nav thru 7100-exit
                   perform 4000-display-g thru 4000-exit
               else
                   move entry1 to course-a
                   move entry2 to warp-a
                   move 0 to course-b
                   move 0 to warp-b
                   perform 7100-nav thru 7100-exit
                   perform 4000-display-g thru 4000-exit
           else
               if phasers or pha-c
                   perform 7200-pha thru 7200-exit
               else
                   if torpedo or tor-c
                       perform 7300-tor thru 7300-exit
                   else
                       if shields or def-c
                           perform 7500-def thru 7500-exit
                       else
                           if dock or doc-c
                               perform 7600-doc thru 7600-exit
                           else
                               if lib-com or com-c
                                   perform 3000-com-fun thru 3000-exit
                               else
                                   display "INVALID COMMAND - Do you want a list of commands? "
                                   accept lst-reply
                                   if yes-lst
                                       perform 0500-prt-inst thru 0500-exit.
           perform 1150-ck-time thru 1150-exit.
           perform 1100-chk-galaxy thru 1100-exit.
       2000-exit.  exit.

      *>**************************************
      *> 3000-com-fun simulates the opera-   *
      *> tion of an on-board library compu-  *
      *> ter, and responds to numeric com-   *
      *> mands , range 1 - 6.                *
      *>**************************************

       3000-com-fun.
           display "      ".
           if entry1 not numeric or entry1 < 1 or entry1 > 6
               display "*COMPUTER ACTIVE AND AWAITING COMMAND* "
               accept comp-com
           else
               move entry1 to comp-com.
           if comp-com not numeric or comp-com < 1 or comp-com > 6
               display "INVALID COMPUTER COMMAND "
               display "Do you want a list  of computer commands? "

               accept lst-reply
               if yes-lst
                   display "Functions available from the library computer: "
                   display "     1  To request ship status "
                   display "     2  To request short range scan of quadrant "
                   display "     3  To request long range scan "
                   display "     4  To request tally of Klingons "
                   display "     5  To request intelligence report "
                   display "     6  To terminate program execution "
                   display "      "
                   display "*COMPUTER ACTIVE AND AWAITING COMMAND* "
                   accept comp-com
               else
                   display "COMPUTER COMMAND?"
                   accept comp-com.
           go to
               3010-com
               3020-com
               3030-com
               3040-com
               3050-com
               3060-com
                   depending on comp-com.
           display " INVALID COMPUTER COMMAND ".
           go to 3000-exit.

       3010-com.
           perform 7400-sta thru 7400-exit.
           go to 3000-exit.

       3020-com.
           perform 4000-display-g thru 4000-exit.
           go to 3000-exit.

       3030-com.
           perform 7700-lrs thru 7700-exit.
           go to 3000-exit.

       3040-com.
           compute bye-k = k-or - klingons.
           display "      ".
           display bye-k " Klingons destroyed, " klingons " remain ".
           display "ATTACK DATE: " ds-date.
           display "STAR DATE: " s-date.
           display "      ".
           perform 8100-dmg-com thru 8100-exit.
           go to 3000-exit.

       3050-com.
           perform 7800-int thru 7800-exit.
           go to 3000-exit.

       3060-com.
           move 1 to indicate-x.
           display "      ".
           display "*ENTERPRISE STRANDED - CAPTAIN BOOKED* ".
           display "      ".
           perform 8200-ck-done thru 8200-exit.
           go to 3000-exit.

       3000-exit.  exit.

      *>******************************************
      *> 4000-display-g determines what quadrant *
      *> the enterprise is in, and displays the  *
      *> quadrant, notifying user of presence of *
      *> klingons in quadrant.                   *
      *>******************************************

       4000-display-g.
           move 0 to klgns.
           move 0 to romulons.
           move 0 to base-cnt.
           move q1 to qs-1.
           move q2 to qs-2.
           compute q1 = (mkctr - 1) / 14 + 1.
           compute q2 = (mrctr - 1) / 14 + 1.
           if q1 not = qs-1 or q2 not = qs-2
               move 0 to kh-tl.
           compute x = (q1 - 1) * 14.
           compute y = (q2 - 1) * 14.
           perform 5900-trans thru 5900-exit.
           inspect mini-table tallying klgns for all "K".
           inspect mini-table tallying romulons for all "R".
           inspect mini-table tallying base-cnt for all "B".
           display "      ".
           if just-starting
               display "You begin in quadrant " q1 "," q2 " with 40,000 "
               display "units of fuel and 5 photon torpedoes. "
               display "      "
               display "Good luck, Captain " name-x
               display "      "
               if klgns > 0
                   display con-red
               else
                   display con-green
           else
               if klgns > 0
                   display con-red
                   compute var2 = klgns * fuel-count / (shield-cnt + 27)
                   perform 4200-test-var thru 4200-exit
                   compute var3 = .75 * var2
                   add var2 to damage-cnt
                   subtract var3 from shield-cnt
                   display "*ENTERPRISE ENCOUNTERING KLINGON FIRE* "
                   perform 4500-disp-hit thru 4500-exit
               else
                   display con-green.
           display quadrant.
           perform 6500-display-mt thru 6500-exit
               varying rcntr from 1 by 1 until rcntr > 14.
           display "      ".
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       4000-exit.  exit.

       4200-test-var.
           if var2 < 1776 and klgns > 0
               add 223 to var2
               compute var2 = (klgns * var2 / 3.5) + (var2 * damage-cnt / 760) + (nx * 17).
       4200-exit.  exit.

       4500-disp-hit.
           move var2 to var5.
           display var5 " unit hit on Enterprise ".
       4500-exit.  exit.

       4700-disp-hit.
           move var4 to var5.
           display var5 " unit hit on Klingon ".
       4700-exit.  exit.

       5400-trans-back.
           perform 5500-transfer-back thru 5500-exit
               varying kcntr from 1 by 1 until kcntr > 14
               after rcntr from 1 by 1 until rcntr > 14.
       5400-exit.  exit.

       5500-transfer-back.
           compute a = y + rcntr.
           compute b = x + kcntr.
           move mcol (rcntr , kcntr) to macol (a , b).
       5500-exit.  exit.

       5900-trans.
           perform 6000-transfer thru 6000-exit
               varying kcntr from 1 by 1 until kcntr > 14
               after rcntr from 1 by 1 until rcntr > 14.
       5900-exit.  exit.

       6000-transfer.
           compute a = y + rcntr.
           compute b = x + kcntr.
           move macol (a , b) to mcol (rcntr , kcntr).
       6000-exit.  exit.

       6500-display-mt.
           display "= = = = = = = = = = = = = = = =".
           perform 6600-mini-dis thru 6600-exit
               varying rcntr from 1 by 1 until rcntr > 14.
           display "= = = = = = = = = = = = = = = =".
       6500-exit.  exit.

       6600-mini-dis.
           perform 6700-mini-mod thru 6700-exit
               varying kcntr from 1 by 1 until kcntr > 14.
           display "=" md-row " =".
       6600-exit.  exit.

       6700-mini-mod.
           compute mod-ctr = 2 * kcntr.
           move mcol (rcntr , kcntr) to md-sub (mod-ctr).
       6700-exit.  exit.

       7000-nav-ck.
           if srctr < 1 or srctr > 126 or skctr < 1 or skctr > 126
               display "Warp drive shut down - "
               display "UNAUTHORIZED ATTEMPT TO LEAVE GALAXY "
               perform 8100-dmg-com thru 8100-exit
               go to 2000-exit
           else
               move " " to macol (mrctr , mkctr)
               move srctr to mrctr.
               move skctr to mkctr.
               if macol (mrctr , mkctr) = "K" or macol (mrctr , mkctr) = "R" or macol (mrctr , mkctr) = "B"
                   perform 8000-bomb thru 8000-exit
               else
                   move "E" to macol (mrctr , mkctr).
       7000-exit.  exit.

      *>*******************************************
      *> 7100-nav thru 7800-int execute various   *
      *> commands from the user, and present the  *
      *> results and consequences of each command *
      *>                                          *
      *> Called from 2000-process or 3000-com-fun *
      *>*******************************************

       7100-nav.
           perform 8340-ck-fl thru 8340-exit.
           compute fuel-count = fuel-count - (200 * warp-a).
           if warp-a > 0
               move warp-a to rx-s
           else
               compute rx-s rounded = warp-b / 100.
           move mrctr to srctr.
           move mkctr to skctr.
           compute warp1 rounded = (warp-a * 5) + (warp-b * .05).
           compute warp2 rounded = (warp-a * 8) + (warp-b * .08).
           compute warp3 rounded = (course-b * .05) * rx-s.
           compute warp4 rounded = (course-b * .03) * rx-s.
           go to
               7110-nav
               7120-nav
               7130-nav
               7140-nav
               7150-nav
               7160-nav
               7170-nav
               7180-nav
                   depending on course-a.
           display "INVALID COURSE".
           go to 7100-exit.
       7110-nav.
           compute srctr = srctr - warp2 + warp4.
           compute skctr = skctr + warp3.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7120-nav.
           compute srctr = srctr - warp1 + warp3.
           compute skctr = skctr + warp1 + warp4.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7130-nav.
           compute srctr = srctr + warp3.
           compute skctr = skctr + warp2 - warp4.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7140-nav.
           compute srctr = srctr + warp1 + warp4.
           compute skctr = skctr + warp1 - warp3.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7150-nav.
           compute srctr = srctr + warp2 - warp4.
           compute skctr = skctr - warp3.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7160-nav.
           compute srctr = srctr + warp1 - warp3.
           compute skctr = skctr - warp1 - warp4.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7170-nav.
           compute srctr = srctr - warp3.
           compute skctr = skctr - warp2 + warp4.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7180-nav.
           compute srctr = srctr - warp1 - warp4.
           compute skctr = skctr - warp1 + warp3.
           perform 7000-nav-ck thru 7000-exit.
           go to 7100-exit.
       7100-exit.  exit.

       7200-pha.
           if klgns < 1 and romulons < 1
               display "Science Officer Spock reports no enemy "
               display "vessels in this quadrant, " name-x
               go to 7200-exit.
           perform 8340-ck-fl thru 8340-exit.
           if fuel-count < 9999
               move fuel-count to fuel-co
               display "Maximum of " fuel-co " units available to phasers ".
           display "How many units to phaser banks? ".
           accept var4-an.
           perform 7210-rep-bl thru 7210-exit.
           perform 7220-compute-dist thru 7220-exit.
           compute var2 = 450000 / (shield-cnt + 100).
           perform 8150-test-agn thru 8150-exit.
           if klgns > 1 and trap-vec
               display "*ENTERPRISE DESTROYED* "
               display "Direct hits from " klgns " klingons "
               move 1 to indicate-x.
               perform 8200-ck-done thru 8200-exit.
           compute dm-var4 = var4 - (damage-cnt / 15).
           compute var3 = var2 / 2.
           if romulons > 0
               display "*ROMULON VESSELS PRESENT IN QUADRANT* "
               display "Do you want to fire on Romulons? "
               accept lst-reply
               if yes-lst
                   perform 7250-romulon-ck thru 7250-exit
                   go to 7200-exit.
           if klgns > 0
               compute var2 = var2 / (dist-x / 10)
               subtract var4 from fuel-count
               move dm-var4 to var4
               add kh-tl to var4
               if var4 < 400
                   perform 4700-disp-hit thru 4700-exit
                   display "*KLINGON DISABLED* "
                   perform 4500-disp-hit thru 4500-exit
                   compute var4 = .75 * var4
                   add var4 to kh-tl
                   add var2 to damage-cnt
                   subtract var3 from shield-cnt
               else
                   perform 7201-replace thru 7201-exit
                       varying rep-ctr from 1 by 1 until rep-ctr > rx
                   inspect mini-table replacing first "K" by " "
                   inspect mini-table replacing all "x" by "K"
                   compute var4 = var4 / (dist-x ** .224)
                   perform 4700-disp-hit thru 4700-exit
                   display "*KLINGON DESTROYED* "
                   move 0 to kh-tl
                   subtract 1 from klgns
                   subtract 1 from klingons
                   perform 5400-trans-back thru 5400-exit
                   if klgns > 0
                       perform 4500-disp-hit thru 4500-exit
                       add var2 to damage-cnt
                       compute var2 = .75 * var2
                       subtract var2 from shield-cnt
                   else
                       move var3 to var2
                       perform 4500-disp-hit thru 4500-exit
                       add var3 to damage-cnt
                       subtract var3 from shield-cnt
           else
               display "There are 0 Klingons in this quadrant, " name-x.
           perform 8120-dam-com thru 8120-exit.
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       7200-exit.  exit.

       7201-replace.
           inspect mini-table replacing first "K" by "x".
       7201-exit.  exit.

       7202-replace.
           inspect mini-table replacing first "R" by "x".
       7202-exit.  exit.

       7210-rep-bl.
           move 0 to tal4.
           inspect var4-an tallying tal4 for all " ".
           if tal4 > 0
               inspect var4-an replacing all " " by zeros
               if var4-an numeric
                   move var4-an to var4
                   compute var4 = var4 / (10 ** tal4)
               else
                   move 300 to var4
           else
               if var4-an numeric
                   move var4-an to var4
               else
                   move 300 to var4.
           if var4 < 300
               move 300 to var4.
       7210-exit.  exit.

       7220-compute-dist.
           move 30 to dist-b.
           move 30 to dist-x.
           move 30 to dist-r.
           move 0 to ct-k.
           move 0 to ct-r.
           perform 7225-find-e thru 7225-exit
               varying rcntr from 1 by 1 until rcntr > 14
               after kcntr from 1 by 1 until kcntr > 14.
           perform 7230-compute thru 7230-exit
               varying rcntr from 1 by 1 until rcntr > 14
               after kcntr from 1 by 1 until kcntr > 14.
           perform 7247-est-nbr thru 7247-exit.
       7220-exit.  exit.

       7225-find-e.
           if mcol (rcntr , kcntr) = "E"
               move rcntr to e1
               move kcntr to e2.
       7225-exit.  exit.

       7230-compute.
           if mcol (rcntr , kcntr) = "K"
               move rcntr to k1
               move kcntr to k2
               add 1 to ct-k
               move dist-x to str-a
               perform 7240-dist-k thru 7240-exit
               if dist-x > str-a
                   move str-a to dist-x.
           if mcol (rcntr , kcntr) = "R"
               move rcntr to r1
               move kcntr to r2
               add 1 to ct-r
               move dist-r to str-r
               perform 7243-dist-r thru 7243-exit
               if dist-r > str-r
                   move str-r to dist-r.
           if mcol (rcntr , kcntr) = "B"
               move rcntr to b1
               move kcntr to b2
               move dist-b to str-x
               perform 7245-dist-b thru 7245-exit
               if dist-b > str-x
                   move str-x to dist-b.
       7230-exit.  exit.

       7240-dist-k.
           if k1 > e1
               compute k1 = k1 - e1
           else
               compute k1 = e1 - k1.
           if k2 > e2
               compute k2 = k2 - e2
           else
               compute k2 = e2 - k2.
           compute dist-x rounded = ((k1 ** 2) + (k2 ** 2)) ** .5.
           move dist-x to dkc (ct-k).
       7240-exit.  exit.

       7243-dist-r.
           if r1 > e1
               compute r1 = r1 - e1
           else
               compute r1 = e1 - r1.
           if r2 > e2
               compute r2 = r2 - e2
           else
               compute r2 = e2 - r2.
           compute dist-r rounded = ((r1 ** 2) + (r2 ** 2)) ** .5.
           move dist-r to drc (ct-r).
       7243-exit.  exit.

       7245-dist-b.
           if b1 > e1
               compute b1 = b1 - e1
           else
               compute b1 = e1 - b1.
           if b2 > e2
               compute b2 = b2 - e2
           else
               compute b2 = e2 - b2.
           compute dist-b rounded = ((b1 ** 2) + (b2 ** 2)) ** .5.
       7245-exit.  exit.

       7247-est-nbr.
           move 30 to str-x.
           perform 7248-est-k thru 7248-exit

           varying rt from 1 by 1 until rt > ct-k.
           perform 7249-est-r thru 7249-exit
               varying qt from 1 by 1 until qt > ct-r.
       7247-exit.  exit.

       7248-est-k.
           if dkc (rt) < str-x
               move dkc (rt) to str-x
               compute rx = rt - 1.
       7248-exit.  exit.

       7249-est-r.
           if drc (qt) < str-r
               move drc (qt) to str-r
               compute qx = qt - 1.
       7249-exit.  exit.

       7250-romulon-ck.
           if romulons > 2 and no-way
               display "*ENTERPRISE FIRING ON ROMULONS*"
               display "*ROMULONS RETURNING FIRE* "
               display "Simultaneous hits from " romulons " Romulons "
               display "*ENTERPRISE DESTROYED*"
               move 1 to indicate-x
               perform 8200-ck-done thru 8200-exit
           else
               perform 8400-generate thru 8400-exit
               display "*ENTERPRISE FIRING ON ROMULONS* "
               subtract var4 from fuel-count
               if no-way or var4 < 447
                   compute var4 = var4 / (dist-r ** .224)
                   move var4 to var5
                   display var5 " unit hit on Romulon "
                   display "*ROMULON RETURNING FIRE*"
                   perform 8400-generate thru 8400-exit
                   if no-way
                       display "*ENTERPRISE DESTROYED BY ROMULON TORPEDO* "
                       move 1 to indicate-x
                       perform 8200-ck-done thru 8200-exit
                   else
                       compute var2 = 3 * var2 / (dist-r / 10)
                       perform 4500-disp-hit thru 4500-exit
                       add var2 to damage-cnt
                       compute var3 = var2 / 2
                       if var3 < 9999
                           subtract var3 from shield-cnt
                       else
                           move 0 to shield-cnt

               else
                   compute var4 = var4 / (dist-x ** .125)
                   move var4 to var5
                   display var5 " unit hit on Romulon "
                   display "*ROMULON DESTROYED*"
                   perform 7202-replace thru 7202-exit
                       varying rep-ctr from 1 by 1 until rep-ctr > qx
                   inspect mini-table replacing first "R" by " "
                   inspect mini-table replacing all "x" by "R"
                   subtract 1 from romulons
                   perform 5400-trans-back thru 5400-exit.
           perform 8100-dmg-com thru 8100-exit.
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       7250-exit.  exit.

       7300-tor.
           if klgns < 1 and romulons < 1
               display "There are 0 enemy vessels in this quadrant, " name-x
               go to 7300-exit.
           perform 8400-generate thru 8400-exit.
           compute var2 = 250000 / (shield-cnt + 100).
           perform 8150-test-agn thru 8150-exit.
           perform 7220-compute-dist thru 7220-exit.
           if klgns > 2
               compute var2 = var2 * (klgns + 1) / 2.
           compute var3 = .75 * var2.
           if romulons > 0 and torps > 0
               display "*ROMULONS PRESENT IN QUADRANT*"
               display "Do you want to fire on them? "
               accept lst-reply
               if yes-lst
                   perform 7350-romulon-ck thru 7350-exit
                   go to 7300-exit.
           if torps > 0
               if klgns > 0
                   if shield-cnt < 475 and no-way
                       display "*ENTERPRISE DESTROYED*"
                       display "Low shields at time of enemy attack "
                       move 1 to indicate-x
                       perform 8200-ck-done thru 8200-exit
                   else
                       if no-way and dist-x > 4
                           compute var2 = var2 / (dist-x / 10)
                           display "torpedo missed "
                           perform 4500-disp-hit thru 4500-exit
                           add var2 to damage-cnt
                           subtract 1 from torps
                           subtract var3 from shield-cnt
                           perform 8120-dam-com thru 8120-exit
                       else
                           display "*KLINGON DESTROYED*"
                           subtract var3 from damage-cnt
                           perform 7201-replace thru 7201-exit
                               varying rep-ctr from 1 by 1 until rep-ctr > rx
                           inspect mini-table replacing first "K" by " "
                           inspect mini-table replacing all "x" by "K"
                           subtract 1 from torps
                           subtract 1 from klgns
                           subtract 1 from klingons
                           perform 5400-trans-back thru 5400-exit
                           if klgns > 0
                               perform 4500-disp-hit thru 4500-exit
                               add var2 to damage-cnt
                               subtract var3 from shield-cnt
                               perform 8120-dam-com thru 8120-exit
                           else
                               perform 8120-dam-com thru 8120-exit
               else
                   display "There are 0 Klingon vessels in this quadrant, " name-x
           else
               display "0 torpedoes remaining, " name-x.
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       7300-exit.  exit.

       7350-romulon-ck.
           if romulons > 1 and no-way
               display "*ENTERPRISE FIRING ON ROMULONS*"
               display "*ROMULONS RETURNING FIRE*"
               display "Simultaneous hits from " romulons " Romulons "
               display "*ENTERPRISE DESTROYED*"
               move 1 to indicate-x
               perform 8200-ck-done thru 8200-exit
           else
               display "*ENTERPRISE FIRING ON ROMULONS*"
               subtract 1 from torps
               if no-way and dist-r > 4
                   display "torpedo missed "
                   display "*ROMULONS RETURNING FIRE*"
                   perform 8400-generate thru 8400-exit
                   if no-way and shield-cnt < 4000
                       display "*ENTERPRISE DESTROYED BY ROMULON TORPEDO*"
                       move 1 to indicate-x
                       perform 8200-ck-done thru 8200-exit
                   else
                       compute var2 = 3 * var2 / (dist-r / 10)
                       perform 4500-disp-hit thru 4500-exit
                       add var2 to damage-cnt
                       compute var3 = var2 / 2
                       subtract var3 from shield-cnt
               else
                   display "*ROMULON DESTROYED*"
                   perform 7202-replace thru 7202-exit
                       varying rep-ctr from 1 by 1 until rep-ctr > qx
                   inspect mini-table replacing first "R" by " "
                   inspect mini-table replacing all "x" by "R"
                   subtract 1 from romulons
                   perform 5400-trans-back thru 5400-exit.
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       7350-exit.  exit.

       7400-sta.
           compute var3 = (damage-cnt / 60).
           move var3 to var6.
           move fuel-count to fuel-co.
           move shield-cnt to shield-co.
           display "      ".
           display "FUEL UNITS   DAMAGE ".
           display "REMAINING    LEVEL  ".
           display "      ".
           display "   " fuel-co "  " var6 "%".
           display "      ".
           display "===================".
           display "      ".
           display " PHOTON      SHIELD ".
           display "TORPEDOES    LEVEL ".
           display "      ".
           display "    " torps "         " shield-co.
           display "      ".
           perform 8100-dmg-com thru 8100-exit.
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       7400-exit.  exit.

       7500-def.
           add shield-cnt to fuel-count.
           display "How many units to shields (0 - 9999)? ".
           perform 7520-asc thru 7520-exit.
           if shield-cnt < fuel-count
               subtract shield-cnt from fuel-count
           else
               move fuel-count to fuel-co
               display "Maximum amount to shields: " fuel-co
               display "How many units to shields? "
               perform 7520-asc thru 7520-exit
               subtract shield-cnt from fuel-count.
           move shield-cnt to shield-co.
           display "Shields at " shield-co " per your command ".
       7500-exit.  exit.

       7520-asc.
           accept shield-cnt-an.
           move 0 to sbl.
           inspect shield-cnt-an tallying sbl for all " ".
           inspect shield-cnt-an replacing all " " by zeros.
           if shield-cnt-an not numeric
               move 0 to sbl
               display "INVALID - Entry must be numeric "
               display "How many units to shields? "
               accept shield-cnt-an
               inspect shield-cnt-an tallying sbl for all " "
               inspect shield-cnt-an replacing all " " by zeros
               if shield-cnt-an not numeric
                   move 0 to shield-cnt
                   go to 7520-exit.
           move shield-cnt-an to shield-cnt.
           if sbl > 0
               compute shield-cnt = shield-cnt / (10 ** sbl).
       7520-exit.  exit.

       7600-doc.
           perform 8400-generate thru 8400-exit.
           if base-cnt > 0
               perform 7220-compute-dist thru 7220-exit
               if dist-b < 7
                   if no-way
                       display "*UNSUCCESSFUL DOCKING ATTEMPT* "
                       display "Star base reports all bays in use "
                       perform 8100-dmg-com thru 8100-exit
                   else
                       move 5 to torps
                       move 25000 to fuel-count
                       move 0 to damage-cnt
                       move 0 to shield-cnt
                       display "Shields dropped to dock at star base "
                       display "*DOCK SUCCESSFUL* "
               else
                   display "The nearest star base is " dist-b " parsecs "
                   display "You must maneuver to within 6 parsecs to dock "
           else
               display "There are 0 star bases in this quadrant, " name-x.
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       7600-exit.  exit.

       7650-trans-star.
           if q1 = 1
               move 2 to q9
           else
               if q1 = 9
                   move 8 to q9
               else
                   move q1 to q9.
           if q2 = 1
               move 2 to r9
           else
               if q2 = 9
                   move 8 to r9
               else
                   move q2 to r9.
           compute w = (q9 - 2) * 14.
           compute z = (r9 - 2) * 14.
           perform 7670-strans thru 7670-exit
               varying rctr from 1 by 1 until rctr > 42
               after kctr from 1 by 1 until kctr > 42.
       7650-exit.  exit.

       7670-strans.
           compute a = z + rctr.
           compute b = w + kctr.
           move macol (a , b) to kolumn (rctr , kctr).
       7670-exit.  exit.

       7700-lrs.
           perform 7650-trans-star thru 7650-exit.
           move zeros to scan-keep.
           move 0 to scan-ctr.
           if q1 = 1
               move 1 to qt1
               move 3 to qt3
           else
               if q1 = 9
                   move 7 to qt1
                   move 9 to qt3
               else
                   compute qt1 = q1 - 1
                   compute qt3 = q1 + 1.
           if q2 = 1
               move 1 to qt2
               move 3 to qt4
           else
               if q2 = 9
                   move 7 to qt2
                   move 9 to qt4
               else
                   compute qt2 = q2 - 1
                   compute qt4 = q2 + 1.
           perform 7730-trade-tbl thru 7730-exit
               varying tr2 from 0 by 1 until tr2 > 2
               after tr1 from 0 by 1 until tr1 > 2.
           display "      ".
           display "=========================".
           display "=       =       =       =".
           display "= " cv (1) "," cv (2) " = " cv (3) "," cv (4) " = " cv (5) "," cv (6) " = ".
           display "=       =       =       =".
           display "=========================".
           display "=       =       =       =".
           display "= " cv (7) "," cv (8) " = " cv (9) "," cv (10) " = " cv (11) "," cv (12) " =".
           display "=       =       =       =".
           display "=========================".
           display "=       =       =       =".
           display "= " cv (13) "," cv (14) " = " cv (15) "," cv (16) " = " cv (17) "," cv (18) " =".
           display "=       =       =       =".
           display "=========================".
           display "KEY: ".
           display "Quadrants " qt1 "," qt2 " thru " qt3 "," qt4.
           display "Format - KLINGONS,STAR BASES ".
           if q1 = 1 or q1 = 9 or q2 = 1 or q2 = 9
               display "*ENTERPRISE ON GALACTIC BOUNDARY*".
           display "Enterprise in quadrant " q1 "," q2.
           display "      ".
           perform 8100-dmg-com thru 8100-exit.
           perform 8300-ck-fuel-damage thru 8300-exit.
           perform 8200-ck-done thru 8200-exit.
       7700-exit.  exit.

       7730-trade-tbl.
           compute qt = (tr1 * 14).
           compute rt = (tr2 * 14).
           perform 7750-trade-act thru 7750-exit
               varying ktctr from 1 by 1 until ktctr > 14
               after rtctr from 1 by 1 until rtctr > 14.
           perform 7770-inspect-scan thru 7770-exit.
       7730-exit.  exit.

       7750-trade-act.
           compute qx = qt + ktctr.
           compute rx = rt + rtctr.
           move kolumn (rx , qx) to scan-col (rtctr , ktctr).
       7750-exit.  exit.

       7770-inspect-scan.
           add 1 to scan-ctr.
           inspect scan-table tallying cv (scan-ctr) for all "K".
           add 1 to scan-ctr.
           inspect scan-table tallying cv (scan-ctr) for all "B".
       7770-exit.  exit.

       7800-int.
           if klingons > 0
               move 1 to cx
               move 1 to dx
               perform 7850-search thru 7850-exit
                   until macol (cx , dx) = "K" or dx > 126
               compute cx-1 = (dx - 1) / 14 + 1
               compute dx-1 = (cx - 1) / 14 + 1
               display " "
               display "Latest intelligence gathering reports "
               display "indicate 1 or more Klingon vessels "
               display "in the vicinity of quadrant " cx-1 "," dx-1
               display " "
               display "Enterprise in quadrant " q1 "," q2
               display " ".
       7800-exit.  exit.

       7850-search.
           add 1 to cx.
           if cx > 126
               add 1 to dx
               move 1 to cx.
       7850-exit.  exit.

       8000-bomb.
           if macol (mrctr , mkctr) = "K"
               display "*ENTERPRISE DESTROYED IN COLLISION WITH KLINGON*"
           else
               if macol (mrctr , mkctr) = "R"
                   display "*ENTERPRISE DESTROYED IN COLLISION WITH ROMULON*"
               else
                   display "*ENTERPRISE DESTROYED IN COLLISION WITH STAR BASE*".
           move 1 to indicate-x.
           perform 8200-ck-done thru 8200-exit.
       8000-exit.  exit.

      *>***************************************************
      *> 8100-dmg-com and 8120-dam-com calculate and dis- *
      *> play hits on the enterprise from enemy vessels   *
      *> in quadrant.  --  Called following possible con- *
      *> tact with enemy vessels.                         *
      *>***************************************************

       8100-dmg-com.
           if klgns > 0
               compute var2 = (k-or - klingons) * klgns * fuel-count / (shield-cnt + 21)
               perform 8150-test-agn thru 8150-exit
               compute var3 = .75 * var2
               display "*ENTERPRISE ENCOUNTERING KLINGON FIRE*"
               perform 4500-disp-hit thru 4500-exit
               add var2 to damage-cnt
               subtract var3 from shield-cnt.
       8100-exit.  exit.

       8120-dam-com.
           if romulons > 0
               compute var2 = romulons * fuel-count / (shield-cnt + 7)
               perform 8160-test-agn thru 8160-exit
               compute var3 = .75 * var2
               display "*ENTERPRISE ENCOUNTERING ROMULON FIRE*"
               perform 4500-disp-hit thru 4500-exit
               add var2 to damage-cnt
               subtract var3 from shield-cnt.
       8120-exit.  exit.

       8150-test-agn.
           if var2 < 325 and klgns > 0
               add 177 to var2
               compute var2 = (klgns * var2 / 2.7) + (var2 * damage-cnt / 980).
       8150-exit.  exit.

       8160-test-agn.
           if var2 < 525 and romulons > 0
               add 254 to var2
               compute var2 = (romulons * var2 / 4.7) + (var2 * damage-cnt / 365).
       8160-exit.  exit.

       8200-ck-done.
           if bye-bye
               go to 2000-exit.
       8200-exit.  exit.

      *>************************************************
      *> 8300-ck-fuel-damage checks and notifies the   *
      *> user of low shields, low fuel reserves, or    *
      *> high damage to the ship, in order that he may *
      *> attempt to dock before the enterprise is      *
      *> disabled.   --  Called following possible     *
      *> contact with enemy vessels.                   *
      *>************************************************

       8300-ck-fuel-damage.
           if fuel-count < 4500 and fuel-count > 0
               display "Lt. Scott reports fuel is running low, " name-x
           else
               if fuel-count not > 0
                   display "Fuel reserves depleted "
                   display "the Enterprise is drifting in space "
                   perform 8350-ck-shift thru 8350-exit.
           if damage-cnt > 6000
               display "Enterprise stranded because of heavy damage "
               move 1 to indicate-x
               perform 8200-ck-done thru 8200-exit.
           if damage-cnt > 4500
               display "Damage Control reports heavy damage to Enterprise, " name-x.
           if shield-cnt < 800 and (klgns > 0 or romulons > 0)
               display "Lt. Sulu reports shields dangerously low, " name-x.
       8300-exit.  exit.

       8340-ck-fl.
           if fuel-count not > 180
               display "*INSUFFICIENT FUEL TO CONTINUE*"
               perform 8350-ck-shift thru 8350-exit
               go to 2000-exit.
       8340-exit.  exit.

       8350-ck-shift.
           if shield-cnt > 200
               display "Lt. Sulu advises you lower shields "
               display "to increase fuel supply, " name-x
           else
               move 1 to indicate-x
               perform 8200-ck-done thru 8200-exit.
       8350-exit.  exit.

       8400-generate.
           if nx > 24
               move 0 to nx.
           add 1 to nx.
      *> Used to be if char (nx) numeric
           if nx equal nx
               move 1 to genrte-result
           else
               move 0 to indicate-y
               move 0 to genrte-result
               if char (nx) = "f"
                   move 1 to indicate-y.
       8400-exit.  exit.

       8500-finish-game.
           display "      ".
           if bye-bye
               if s-date > ds-date
                   move klingons to vae1
                   move ws-date to ds-date
                   display "It is now star date " s-date
                   display "STAR DATE " ds-date " Star Fleet HQ"
                   display "was destroyed by " vae1 " klingon vessels"
                   display name-x " COURT MARTIALED"
               else
                   display name-x " COURT MARTIALED"
           else
               display "Congratulations on a job well done. "
               display "The Federation is proud of you, " name-x.
           display "      ".
       8500-exit.  exit.

       9000-end-of-job-section section.
       9000-end-of-job.
           display "      ".
       9000-exit.  exit.
