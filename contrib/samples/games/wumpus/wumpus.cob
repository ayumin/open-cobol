           >>SOURCE FORMAT IS FREE 
Identification division. 
Program-id. wumpus. 

*> This is a translation of the BASIC wumpus game into COBOL. 
*> Translation published under GNU General Public License. 

Data division. 
Working-storage section. 

*> Number of arrows. 
01  A                              pic 9(02) binary. 
*> Number for display on screen. 
01  display-number                 pic Z9. 
*> Function, -1 = lose, 0 = game continues, 1 = win. 
01  F                              pic S9(02) binary. 
*> Flag for program control. 
01  flag-redo                      pic x(01). 
*> Random number function areas. 
01  ws-random                      pic v9(02). 
01  fna                            pic 9(02) binary. 
01  fnb                            pic 9(02) binary. 
01  fnc                            pic 9(02) binary. 
*> Accept options from screen. 
01  I                              pic x(01).  
01  J                              pic 9(02) binary. 
*> Number of rooms to shoot. 
01  J9                             pic 9(02) binary. 
01  K                              pic 9(02) binary. 
01  K1                             pic 9(02) binary. 
*> Your current location.  L2 was L in BASIC which had L () as a table and separate L variable. 
01  L2                             pic 9(02) binary. 
*> Locations of you (1), wumpus (2), 2 pits (3 & 4), and 2 bats (5 & 6). 
01  ls. 
    02 L                               pic 9(02) binary 
        occurs 6 times. 
*> Original L game settings for reset. 
01  ms. 
    02 M                               pic 9(02) binary 
        occurs 6 times. 
*> Option from screen, 1 = shoot  2 = move. 
01  O                              pic 9(02) binary. 
01  ps. 
    02  P                              pic 9(02) binary 
         occurs 5 times. 
*> Cave room numbers.  Rooms are in dodecahedral connected order. 
*> The first subscript is the room you are in and the second 
*> lists the rooms that are connected to this room. 
01  s-tables. 
    02 s-table. 
        03                                pic 9(02) binary value  2.
        03                                pic 9(02) binary value  5.
        03                                pic 9(02) binary value  8.
        03                                pic 9(02) binary value  1.
        03                                pic 9(02) binary value  3.
        03                                pic 9(02) binary value 10.
        03                                pic 9(02) binary value  2.
        03                                pic 9(02) binary value  4. 
        03                                pic 9(02) binary value 12.
        03                                pic 9(02) binary value  3.
        03                                pic 9(02) binary value  5.
        03                                pic 9(02) binary value 14.
        03                                pic 9(02) binary value  1.
        03                                pic 9(02) binary value  4.
        03                                pic 9(02) binary value  6.
        03                                pic 9(02) binary value  5.
        03                                pic 9(02) binary value  7.
        03                                pic 9(02) binary value 15.
        03                                pic 9(02) binary value  6.
        03                                pic 9(02) binary value  8.
        03                                pic 9(02) binary value 17.
        03                                pic 9(02) binary value  1. 
        03                                pic 9(02) binary value  7.
        03                                pic 9(02) binary value  9.
        03                                pic 9(02) binary value  8.
        03                                pic 9(02) binary value 10.
        03                                pic 9(02) binary value 18.
        03                                pic 9(02) binary value  2.
        03                                pic 9(02) binary value  9.
        03                                pic 9(02) binary value 11.
        03                                pic 9(02) binary value 10.
        03                                pic 9(02) binary value 12.
        03                                pic 9(02) binary value 19.
        03                                pic 9(02) binary value  3.
        03                                pic 9(02) binary value 11.
        03                                pic 9(02) binary value 13.
        03                                pic 9(02) binary value 12.
        03                                pic 9(02) binary value 14.
        03                                pic 9(02) binary value 20.
        03                                pic 9(02) binary value  4.
        03                                pic 9(02) binary value 13.
        03                                pic 9(02) binary value 15.
        03                                pic 9(02) binary value  6.
        03                                pic 9(02) binary value 14.
        03                                pic 9(02) binary value 16.
        03                                pic 9(02) binary value 15.
        03                                pic 9(02) binary value 17.
        03                                pic 9(02) binary value 20.
        03                                pic 9(02) binary value  7.
        03                                pic 9(02) binary value 16.
        03                                pic 9(02) binary value 18.
        03                                pic 9(02) binary value  9.
        03                                pic 9(02) binary value 17.
        03                                pic 9(02) binary value 19.
        03                                pic 9(02) binary value 11.
        03                                pic 9(02) binary value 18.
        03                                pic 9(02) binary value 20.
        03                                pic 9(02) binary value 13.
        03                                pic 9(02) binary value 16.
        03                                pic 9(02) binary value 19. 
    02 s-table-redf redefines s-table. 
        03 s-j occurs 20 times. 
            04 s-k occurs 3 times. 
                05 S                              pic 9(02) binary. 
*> Accept numbers from screen and check for numeric.
01  ws-x-1. 
    02 ws-9-1                         pic 9(01). 
01  ws-x-2. 
    02 ws-9-2                         pic 9(02). 

Procedure division. 

*> 0005 REM- HUNT THE WUMPUS 
*> 0015 PRINT "INSTRUCTIONS (Y-N)"; 
*> 0020 INPUT I$
*> 0025 IF I$="N" THEN 35
*> 0030 GOSUB 375 

Display "INSTRUCTIONS (Y-N) "               *> Print instructions yes or no. 
    with no advancing 
end-display. 
Perform ac-accept-character.                *> Accept I from keyboard.
If I is equal to "N" 
    Continue 
  else 
    Perform 375-line                        *> Display instructions. 
end-if. 

*> 0080 REM- SET UP CAVE (DODECAHEDRAL NODE LIST) 
*> 0085 DIM S(20,3)
*> 0090 FOR J=1 TO 20
*> 0095  FOR K=1 TO 3
*> 0100   READ S(J,K)
*> 0105  NEXT K
*> 0110 NEXT J
*> 0115 DATA 2,5,8,1,3,10,2,4,12,3,5,14,1,4,6
*> 0120 DATA 5,7,15,6,8,17,1,7,9,8,10,18,2,9,11
*> 0125 DATA 10,12,19,3,11,13,12,14,20,4,13,15,6,14,16
*> 0130 DATA 15,17,20,7,16,18,9,17,19,11,18,20,13,16,19 
*> 0135 DEF FNA(X)=INT(20*RND(1))+1 
*> 0140 DEF FNB(X)=INT(3*RND(1))+1 
*> 0145 DEF FNC(X)=INT(4*RND(1))+1 
*> 0150 REM-LOCATE L ARRAY ITEMS 
*> 0155 REM-1-YOU, 2-WUMPUS, 3&4-PITS, 5&6-BATS 
*> 0160 DIM L(6)
*> 0165 DIM M(6)
*> 0170 FOR J=1 TO 6
*> 0175  L(J)=FNA(0)
*> 0180  M(J)=L(J)
*> 0185 NEXT J
*> 0190 REM- CHECK FOR CROSSOVERS (IE L(1)=L(2), ETC)
*> 0195 FOR J=1 TO 6
*> 0200  FOR K=J TO 6
*> 0205   IF J=K THEN 215
*> 0210   IF L(J)=L(K) THEN 170
*> 0215  NEXT K
*> 0220 NEXT J  

170-line. 

Perform                                     *> Randomly place you, the wumpus, pits, and bats into rooms. 
    varying J 
       from 1 
         by 1 
    until J is greater than 6 
        Perform fna-line                    *> Random room number. 
        Move fna to L (J)                   *> Move to current game. 
                    M (J)                   *> Move to saved game for later reset. 
end-perform. 

Move low-value to flag-redo.                *> Check the room assignments. 
Perform 
    varying J 
       from 1
         by 1
    until J is greater than 6 
        Perform 
            varying K 
               from J 
                 by 1 
            until K is greater than 6 
                If  J is not equal to K 
                and L (J) is equal to L (K)  
                    Move high-value to flag-redo 
                end-if 
        end-perform 
end-perform. 
If flag-redo is equal to high-value         *> Do room assignments again if they are not all in separate rooms. 
    Go to 170-line 
end-if. 

*> 225 REM-SET# ARROWS 
*> 230 A=5
*> 235 L=L(1)
*> 240 REM- RUN THE GAME 
*> 245 PRINT "HUNT THE WUMPUS" 
*> 250 REM- HAZARD WARNINGS & LOCATION 
*> 255 GOSUB 585
*> 260 REM- MOVE OR SHOOT
*> 265 GOSUB 670

225-line. 

Move 5 to A.                                *> Set 5 arrows. 
Move L (1) to L2. 
Display "HUNT THE WUMPUS " 
end-display. 

250-line. 

Perform 585-line.                           *> Hazard warnings. 
Perform 670-line.                           *> Get shoot or move option from screen.

*> 270 GOTO O OF 280,300 
*> 275 REM-SHOOT 
*> 280 GOSUB 715
*> 285 IF F=0 THEN 255
*> 290 GOTO 310
*> 295 REM-MOVE 
*> 300 GOSUB 975
*> 305 IF F=0 THEN 255
*> 310 IF F>0 THEN 335
*> 315 REM-LOSE 
*> 320 PRINT "HA HA HA - YOU LOSE!"
*> 325 GOTO 340 
*> 330 REM-WIN 
*> 335 PRINT "HEE HEE HEE - THE WUMPUS'LL GETCHA NEXT TIME!!"
*> 340 FOR J=1 TO 6
*> 345  L(J)=M(J) 
*> 350 NEXT J 
*> 355 PRINT "SAME SETUP (Y-N)";
*> 360 INPUT I$ 
*> 365 IF I$#"Y" THEN 170
*> 370 GOTO 230 

Evaluate O 
    when 1 
        Perform 715-line thru 715-exit      *> Shoot. 
    when 2 
        Perform 975-line thru 975-exit      *> Move. 
end-evaluate. 
If F is equal to zero                       *> Move or shoot again. 
    Go to 250-line 
end-if. 
If F is greater than zero                   *> You win. 
    Display "HEE HEE HEE - THE WUMPUS'LL GETCHA NEXT TIME!! " 
    end-display
  else 
    Display  "HA HA HA - YOU LOSE! "        *> You lose. 
    end-display 
end-if. 

Perform                                     *> Reset game. 
    varying J 
       from 1 
         by 1 
    until J is greater than 6 
        Move M (J) to L (J) 
end-perform. 

Display "SAME SETUP (Y-N) "
    with no advancing 
end-display. 
Perform ac-accept-character.                *> Accept I from keyboard.
If I is equal to "Y" 
    Go to 225-line                          *> Same setup. 
end-if. 
Go to 170-line.                             *> New setup. 

*> 375 REM-INSTRUCTIONS 
*> 380 PRINT "WELCOME TO 'HUNT THE WUMPUS'"
*> 385 PRINT "  THE WUMPUS LIVES IN A CAVE OF 20 ROOMS. EACH ROOM"
*> 390 PRINT "HAS 3 TUNNELS LEADING TO OTHER ROOMS. (LOOK AT A"
*> 395 PRINT "DODECAHEDRON TO SEE HOW THIS WORKS-IF YOU DON'T KNOW"
*> 400 PRINT "WHAT A DODECAHEDRON IS, ASK SOMEONE)"
*> 405 PRINT
*> 410 PRINT "     HAZARDS:"
*> 415 PRINT " BOTTOMLESS PITS - TWO ROOMS HAVE BOTTOMLESS PITS IN THEM"
*> 420 PRINT "     IF YOU GO THERE, YOU FALL INTO THE PIT (& LOSE!)"
*> 425 PRINT " SUPERBATS - TWO OTHER ROOMS HAVE SUPER BATS. IF YOU"
*> 430 PRINT "     GO THERE, A BAT GRABS YOU AND TAKES YOU TO SOME OTHER"
*> 435 PRINT "     ROOM AT RANDOM. (WHICH MIGHT BE TROUBLESOME)"
*> 440 PRINT 
*> 445 PRINT "     WUMPUS:"
*> 450 PRINT " THE WUMPUS IS NOT BOTHERED BY HAZARDS (HE HAS SUCKER"
*> 455 PRINT " FEET AND IS TOO BIG FOR A BAT TO LIFT).  USUALLY"
*> 460 PRINT " HE IS ASLEEP.  TWO THINGS WAKE HIM UP: YOUR ENTERING"  
*> 465 PRINT " HIS ROOM OR YOUR SHOOTING AN ARROW."
*> 470 PRINT "     IF THE WUMPUS WAKES, HE MOVES (P=.75) ONE ROOM"
*> 475 PRINT " OR STAYS STILL (P=.25). AFTER THAT, IF HE IS WHERE YOU"
*> 480 PRINT " ARE, HE EATS YOU UP (& YOU LOSE!)"
*> 485 PRINT
*> 490 PRINT "     YOU:"
*> 495 PRINT " EACH TURN YOU MAY MOVE OR SHOOT A CROOKED ARROW"
*> 500 PRINT "   MOVING: YOU CAN GO ONE ROOM (THRU ONE TUNNEL)"
*> 505 PRINT "   ARROWS: YOU HAVE 5 ARROWS. YOU LOSE WHEN YOU RUN OUT"
*> 510 PRINT "   EACH ARROW CAN GO FROM 1 TO 5 ROOMS. YOU AIM BY TELLING"
*> 515 PRINT "   THE COMPUTER THE ROOM#S YOU WANT THE ARROW TO GO TO."
*> 520 PRINT "   IF THE ARROW CAN'T GO THAT WAY(IE NO TUNNEL) IT MOVES"
*> 525 PRINT "   AT RANDOM TO THE NEXT ROOM."
*> 530 PRINT "     IF THE ARROW HITS THE WUMPUS, YOU WIN."
*> 535 PRINT "     IF THE ARROW HITS YOU, YOU LOSE." 
*> 540 PRINT 
*> 545 PRINT "    WARNINGS:"
*> 550 PRINT "     WHEN YOU ARE ONE ROOM AWAY FROM WUMPUS OR HAZARD,"
*> 555 PRINT "    THE COMPUTER SAYS:"
*> 560 PRINT " WUMPUS-  'I SMELL A WUMPUS'"
*> 565 PRINT " BAT   -  'BATS NEARBY'"
*> 570 PRINT " PIT   -  'I FEEL A DRAFT'"
*> 575 PRINT
*> 580 RETURN

375-line.

Display "WELCOME TO 'HUNT THE WUMPUS'"                                 end-display.
Display "  THE WUMPUS LIVES IN A CAVE OF 20 ROOMS. EACH ROOM"          end-display.
Display "HAS 3 TUNNELS LEADING TO OTHER ROOMS. (LOOK AT A"             end-display.
Display "DODECAHEDRON TO SEE HOW THIS WORKS-IF YOU DON'T KNOW"         end-display.
Display "WHAT A DODECAHEDRON IS, ASK SOMEONE)"                         end-display.
Display " "                                                            end-display.
Display "     HAZARDS:"                                                end-display.
Display " BOTTOMLESS PITS - TWO ROOMS HAVE BOTTOMLESS PITS IN THEM"    end-display.
Display "     IF YOU GO THERE, YOU FALL INTO THE PIT (& LOSE!)"        end-display.
Display " SUPERBATS - TWO OTHER ROOMS HAVE SUPER BATS. IF YOU"         end-display.
Display "     GO THERE, A BAT GRABS YOU AND TAKES YOU TO SOME OTHER"   end-display.
Display "     ROOM AT RANDOM. (WHICH MIGHT BE TROUBLESOME)"            end-display.
Display " "                                                            end-display.
Display "     WUMPUS:"                                                 end-display.
Display " THE WUMPUS IS NOT BOTHERED BY THE HAZARDS (HE HAS SUCKER"    end-display.
Display " FEET AND IS TOO BIG FOR A BAT TO LIFT).  USUALLY"            end-display.
Display " HE IS ASLEEP. TWO THINGS WAKE HIM UP: YOUR ENTERING"         end-display.
Display " HIS ROOM OR YOUR SHOOTING AN ARROW."                         end-display.
Display "     IF THE WUMPUS WAKES, HE MOVES (P=.75) ONE ROOM"          end-display.
Display " OR STAYS STILL (P=.25). AFTER THAT, IF HE IS WHERE YOU"      end-display.
Display " ARE, HE EATS YOU UP (& YOU LOSE!)"                           end-display.
Display " "                                                            end-display.
Display "     YOU:"                                                    end-display.
Display " EACH TURN YOU MAY MOVE OR SHOOT A CROOKED ARROW"             end-display.
Display "   MOVING: YOU CAN GO ONE ROOM (THRU ONE TUNNEL)"             end-display.
Display "   ARROWS: YOU HAVE 5 ARROWS. YOU LOSE WHEN YOU RUN OUT."     end-display.
Display "   EACH ARROW CAN GO FROM 1 TO 5 ROOMS. YOU AIM BY TELLING"   end-display.
Display "   THE COMPUTER THE ROOMS YOU WANT THE ARROW TO GO TO."       end-display.
Display "   IF THE ARROW CAN'T GO THAT WAY(IE NO TUNNEL) IT MOVES"     end-display.
Display "   AT RANDOM TO THE NEXT ROOM."                               end-display.
Display "     IF THE ARROW HITS THE WUMPUS, YOU WIN."                  end-display.
Display "     IF THE ARROW HITS YOU, YOU LOSE."                        end-display.
Display " "                                                            end-display.
Display "    WARNINGS:"                                                end-display.
Display "     WHEN YOU ARE ONE ROOM AWAY FROM A WUMPUS OR HAZARD,"     end-display.
Display "    THE COMPUTER SAYS:"                                       end-display.
Display " WUMPUS-  'I SMELL A WUMPUS'"                                 end-display.
Display " BAT   -  'BATS NEARBY'"                                      end-display.
Display " PIT   -  'I FEEL A DRAFT'"                                   end-display.
Display " "                                                            end-display.

*> 585 REM-PRINT LOCATION & HAZARD WARNINGS 
*> 590 PRINT
*> 595 FOR J=2 TO 6
*> 600  FOR K=1 TO 3
*> 605   IF S(L(1),K)#L(J) THEN 640
*> 610   GOTO J-1 OF 615,625,625,635,635
*> 615   PRINT "I SMELL A WUMPUS!"
*> 620   GOTO 640
*> 625   PRINT "I FEEL A DRAFT"
*> 630   GOTO 640
*> 635   PRINT "BATS NEARBY!"
*> 640  NEXT K
*> 645 NEXT J
*> 650 PRINT "YOU ARE IN ROOM "L(1)
*> 655 PRINT "TUNNELS LEAD TO "S(L,1);S(L,2);S(L,3) 
*> 660 PRINT
*> 665 RETURN

585-line. 

Display " " 
end-display. 

Perform                                     *> Show hazard warnings. 
    varying J 
       from 2 
         by 1 
    until J is greater than 6 
        Perform 
            varying K 
               from 1 
                 by 1 
            until K is greater than 3  
                If S (L (1), K) is equal to L (J) 
                    If J is equal to 2 
                        Display "I SMELL A WUMPUS! " 
                        end-display
                    end-if 
                    If J is equal to 3 
                    or J is equal to 4 
                        Display "I FEEL A DRAFT " 
                        end-display
                    end-if 
                    If J is equal to 5 
                    or J is equal to 6  
                        Display "BATS NEARBY! " 
                        end-display
                    end-if 
                end-if 
        end-perform 
end-perform. 

Move L (1) to display-number.               *> Your room number. 
Display "YOU ARE IN ROOM " display-number
end-display. 

Move S (L2, 1) to display-number.           *> Tunnels lead to room numbers. 
Display "TUNNELS LEAD TO " display-number 
   with no advancing 
end-display. 
Move S (L2, 2) to display-number.
Display " " display-number 
   with no advancing 
end-display. 
Move S (L2, 3) to display-number. 
Display " " display-number 
end-display. 

Display " " 
end-display. 

*> 670 REM-CHOOSE OPTION 
*> 675 PRINT "SHOOT OR MOVE (S-M)";
*> 680 INPUT I$ 
*> 685 IF I$#"S" THEN 700
*> 690 O=1
*> 695 RETURN 
*> 700 IF I$#"M" THEN 675
*> 705 O=2
*> 710 RETURN

670-line. 

Move zero to O.                             *> Get shoot or move option. 
Perform until O is not equal to zero 
    Display "SHOOT OR MOVE (S-M) "
        with no advancing
    end-display
    Perform ac-accept-character             *> Accept I from keyboard.
    Evaluate I 
        when "S" 
            Move 1 to O                     *> Shoot. 
        when "M" 
            Move 2 to O                     *> Move. 
    end-evaluate
end-perform. 

*> 715 REM-ARROW ROUTINE
*> 720 F=0
*> 725 REM-PATH OF ARROW
*> 730 DIM P(5) 
*> 735 PRINT "NO. OF ROOMS (1-5)";
*> 740 INPUT J9
*> 745 IF J9<1 OR J9>5 THEN 735
*> 755 FOR K=1 TO J9
*> 760  PRINT "ROOM #";
*> 765  INPUT P(K)
*> 770  IF K <= 2 THEN 790
*> 775  IF P(K) <> P(K-2) THEN 790
*> 780  PRINT "ARROWS AREN'T THAT CROOKED - TRY ANOTHER ROOM"
*> 785  GOTO 760
*> 790 NEXT K

715-line.                                   *> Arrow routine. 

Move zero to F. 
Move zero to J9.                            *> Enter how many rooms to shoot the arrow. 
Perform 
    until J9 is greater than zero 
    and   J9 is less than 6 
        Display "NO. OF ROOMS (1-5) " 
            with no advancing  
        end-display
        Accept ws-x-1 
        end-accept
        If ws-9-1 is numeric 
            Move ws-9-1 to J9 
        end-if 
end-perform. 

Perform                                     *> Enter up to 5 rooms for the the arrow. 
    varying K 
       from 1 
         by 1 
    until K is greater than J9 
        Display "ROOM # " 
            with no advancing  
        end-display
        Perform ar-accept-room 
        Move ws-9-2 to P (K) 
        If K is greater than 2              *> Check that arrows can't go backwards to the same room. 
        and P (K) is equal to P (K - 2) 
            Display "ARROWS AREN'T THAT CROOKED - TRY ANOTHER ROOM "  
            end-display
            Subtract 1 from K 
            end-subtract 
        end-if 
end-perform. 

*> 795 REM-SHOOT ARROW 
*> 800 L=L(1)
*> 805 FOR K=1 TO J9
*> 810  FOR K1=1 TO 3
*> 815   IF S(L,K1)=P(K) THEN 895
*> 820  NEXT K1
*> 825  REM-NO TUNNEL FOR ARROW 
*> 830  L=S(L,FNB(1))
*> 835  GOTO 900
*> 840 NEXT K

*> There is a BASIC GOTO 840 into this FOR loop from elsewhere (wrong use of a GOTO).
*> So the elegance of a COBOL Perform varying can not be used here. 

Move L (1) to L2.                           *> Shoot arrow up to 5 rooms. 
Move zero to K. 

805-line.                                   *> The first loop. 

Add 1 to K
end-add. 
If K is greater than J9 
    Go to 845-line 
end-if. 
Move zero to K1. 

810-line.                                   *> The second loop. 

Add 1 to K1
end-add. 
If K1 is greater than 3 
    Go to 825-line
end-if. 

If S (L2, K1) is equal to P (K) 
    Go to 890-line 
end-if. 
Go to 810-line. 

825-line.                                   *> No tunnel for arrow. 

Perform fnb-line.                           *> Random move for arrow to one of the rooms connected to this room.
Move S (L2, fnb) to L2. 
Go to 900-line. 

*> 845 PRINT "MISSED" 
*> 850 L=L(1)
*> 855 REM-MOVE WUMPUS 
*> 860 GOSUB 935
*> 865 REM-AMMO CHECK
*> 870 A=A-1
*> 875 IF A>0 THEN 885
*> 880 F=-1
*> 885 RETURN 

845-line. 

Display "MISSED "                           *> Arrow missed the wumpus. 
end-display. 
Move L (1) to L2. 

Perform 935-line thru 935-exit.             *> Randomly move the wumpus one room. 

Subtract 1 from A                           *> Shot an arrow, check if any left. 
end-subtract. 
If A is equal to zero                       *> Out of arrows, lose. 
    Move -1 to F
end-if. 
Go to 715-exit. 

*> 890 REM-SEE IF ARROW IS AT L(1) OR AT L(2)
*> 895 L=P(K)
*> 900 IF L#L(2) THEN 920
*> 905 PRINT "AHA! YOU GOT THE WUMPUS!"
*> 910 F=1 
*> 915 RETURN
*> 920 IF L#L(1) THEN 840
*> 925 PRINT "OUCH! ARROW GOT YOU!"
*> 930 GOTO 880

890-line. 

Move P (K) to L2.                           *> Check if arrow got wumpus or you. 

900-line. 

If L2 is equal to L (2) 
    Display "AHA! YOU GOT THE WUMPUS! "     *> You got the wumpus. 
    end-display
    Move 1 to F                             *> Win. 
    Go to 715-exit 
end-if.
If L2 is equal to L (1)               
    Display "OUCH! ARROW GOT YOU! "         *> Arrow got you.  
    end-display
    Move -1 to F                            *> Lose. 
    Go to 715-exit 
end-if. 
Go to 805-line.                             *> Return to shoot arrow up to 5 rooms loop. 
 
*> 935 REM-MOVE WUMPUS ROUTINE 
*> 940 K=FNC(0)
*> 945 IF K=4 THEN 955
*> 950 L(2)=S(L(2),K)
*> 955 IF L(2)#L THEN 970
*> 960 PRINT "TSK TSK TSK- WUMPUS GOT YOU!" 
*> 965 F=-1
*> 970 RETURN

935-line. 

Perform fnc-line.                           *> Random wumpus move 1 through 4.   
Move fnc to K. 
If K is not equal to 4                      *> Move to room subscripted 1, 2, or 3.  If 4 stay still. 
    Move S (L (2), K) to L (2) 
end-if. 
If L (2) is equal to L2                     *> Wumpus in your room, got you. 
    Display "TSK TSK TSK- WUMPUS GOT YOU! "  
    end-display
    Move -1 to F                            *> Lose. 
end-if. 

935-exit. 
    Exit. 

715-exit. 
    Exit. 

*> 975 REM- MOVE ROUTINE 
*> 980 F=0
*> 985 PRINT "WHERE TO";
*> 990 INPUT L
*> 995 IF L<1 OR L>20 THEN 985 
*> 1005 FOR K=1 TO 3
*> 1010  REM- CHECK IF LEGAL MOVE 
*> 1015  IF S(L(1),K)=L THEN 1045
*> 1020 NEXT K 
*> 1025 IF L=L(1) THEN 1045 
*> 1030 PRINT "NOT POSSIBLE -";
*> 1035 GOTO 985 
*> 1040 REM-CHECK FOR HAZARDS 
*> 1045 L(1)=L
*> 1050 REM-WUMPUS 
*> 1055 IF L#L(2) THEN 1090
*> 1060 PRINT "... OOPS! BUMPED A WUMPUS!"
*> 1065 REM-MOVE WUMPUS
*> 1070 GOSUB 940
*> 1075 IF F=0 THEN 1090
*> 1080 RETURN
*> 1085 REM-PIT 
*> 1090 IF L#L(3) AND L#L(4) THEN 1120 
*> 1100 PRINT "YYYIIIIEEEE . . . FELL IN PIT"
*> 1105 F=-1
*> 1110 RETURN
*> 1115 REM-BATS 
*> 1120 IF L#L(5) AND L#L(6) THEN 1145 
*> 1130 PRINT "ZAP--SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!"
*> 1135 L=FNA(1)
*> 1140 GOTO 1045 
*> 1145 RETURN 
*> 1150 END 

975-line. 

Move zeros to F                             *> Get room number to move to. 
              L2. 
Perform 
    until L2 is greater than zero 
    and   L2 is less than 21 
        Display "WHERE TO "
            with no advancing 
        end-display
        Perform ar-accept-room
        Move ws-9-2 to L2
end-perform. 

Perform                                     *> Check for legal move. 
    varying K 
       from 1 
         by 1
    until K is greater than 3 
        If S (L (1), K) is equal to L2
            Go to 1040-line 
        end-if 
end-perform. 

If L2 is equal to L (1)                 
    Go to 1040-line 
end-if. 
Display  "NOT POSSIBLE - "                  *> Not possible to move to that room. 
end-display. 
Go to 975-line. 

1040-line. 

Move L2 to L (1).                           *> Check for hazards. 
If L2 is equal to L (2) 
    Display "... OOPS! BUMPED A WUMPUS! "   *> Bumped a wumpus. 
    end-display
    Perform 935-line thru 935-exit          *> Move wumpus.
    If F is not equal to zero             
        Go to 975-exit                      *> Wumpus got you. 
    end-if
end-if. 

If L2 is equal to L (3)                     *> Check for pits.
or L2 is equal to L (4) 
    Display "YYYIIIIEEEE . . . FELL IN PIT "  
    end-display
    Move -1 to F                            *> Lose. 
    Go to 975-exit 
end-if. 

If L2 is equal to L (5)                     *> Check for bats.
or L2 is equal to L (6)                     
    Display "ZAP--SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU! "  
    end-display
    Perform fna-line                        *> Random room move to any of the 20 rooms. 
    Move fna to L2
    Go to 1040-line
end-if. 

975-exit. 
    Exit. 

fna-line.                                   *> Random room assignments 1 through 20. 

Perform rn-random-number. 
Compute fna = 20 * ws-random + 1
end-compute. 

fnb-line.                                   *> Random arrow move 1 through 3. 

Perform rn-random-number. 
Compute fnb = 3 * ws-random + 1
end-compute. 

fnc-line.                                   *> Random wumpus move 1 through 4. 

Perform rn-random-number. 
Compute fnc = 4 * ws-random + 1
end-compute. 

rn-random-number.                           *> Get a random number from .00 to .99. 

Move function random() to ws-random. 
Move ws-random (1:1) to ws-x-1.             *> Add a little extra randomness. 
Move ws-random (2:1) to ws-random (1:1). 
Move ws-x-1 to ws-random (2:1). 

ac-accept-character.                        *> Accept character input from keyboard. 

Accept I                                    *> Accept character. 
end-accept. 
Inspect I                                   *> Early BASIC programs did not accommodate lower case characters, 
  converting "abcdefghijklmnopqrstuvwxyz"   *> since Teletype devices did not have them. 
          to "ABCDEFGHIJKLMNOPQRSTUVWXYZ".  *> Convert input to upper case. 

ar-accept-room.                             *> Accept room number from keyboard into ws-9-2.

Accept ws-x-2                               *> Accept room number. 
end-accept. 
If ws-x-2 is numeric                        *> Validate numeric 2 digit room number.
    Continue 
  else 
    Move ws-x-2 (1:1) to ws-x-1             *> Validate numeric 1 digit room number. 
    If ws-x-1 is numeric 
        Move ws-9-1 to ws-9-2
      else 
        Move zero to ws-9-2  
    end-if 
end-if. 
