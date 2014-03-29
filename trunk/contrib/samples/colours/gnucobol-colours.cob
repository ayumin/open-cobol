GNU    >>SOURCE FORMAT IS FIXED
Cobol *> ***************************************************************
      *> Author:    Brian Tiffin
      *> Date:      20131026
      *> License:   Public Domain
Colors*> Purpose:   Show the GNU Cobol default colour palette
      *> Tectonics: cobc -x gnucobol-colours.cob
      *> ***************************************************************
       identification division.
       program-id. gnucobol-colours.

       environment division.
       configuration section.
       repository.
           function all intrinsic.

       data division.
       working-storage section.
       01 black   constant as 0.
       01 blue    constant as 1.
       01 green   constant as 2.
       01 cyan    constant as 3.
       01 red     constant as 4.
       01 magenta constant as 5.
       01 brown   constant as 6.
       01 white   constant as 7.

       01 anykey  pic x.

       screen section.
       01 gnu-cobol-colours.
          05 line   1 column 1 value "GNU Cobol Colours".
          05 line   2 column 1 value "-----------------".
          05 line   3 column 1
               value "default          highlight        "
                   & "lowlight         reverse-video    "
                   & "blink".
          05 line  +4 column 1 value "Black   0" foreground-color black.
          05 line  +5 column 1 value "Blue    1" foreground-color blue.
          05 line  +6 column 1 value "Green   2" foreground-color green.
          05 line  +7 column 1 value "Cyan    3" foreground-color cyan.
          05 line  +8 column 1 value "Red     4" foreground-color red.
          05 line  +9 column 1 value "Magenta 5"
                                         foreground-color magenta.
          05 line +10 column 1 value "Brown   6" foreground-color brown.
          05 line +11 column 1 value "White   7"
                                         foreground-color white
                                         background-color black.

          05 line  +4 column 18 value "Black   0"
                               highlight foreground-color black
                                         background-color white.
          05 line  +5 column 18 value "Blue    1"
                               highlight foreground-color blue.
          05 line  +6 column 18 value "Green   2"
                               highlight foreground-color green.
          05 line  +7 column 18 value "Cyan    3"
                               highlight foreground-color cyan.
          05 line  +8 column 18 value "Red     4"
                               highlight foreground-color red.
          05 line  +9 column 18 value "Magenta 5"
                               highlight foreground-color magenta.
          05 line +10 column 18 value "Brown   6"
                               highlight foreground-color brown.
          05 line +11 column 18 value "White   7"
                               highlight foreground-color white
                                         background-color black.

          05 line  +4 column 35 value "Black   0"
                               lowlight  foreground-color black
                                         background-color white.
          05 line  +5 column 35 value "Blue    1"
                               lowlight  foreground-color blue.
          05 line  +6 column 35 value "Green   2"
                               lowlight  foreground-color green.
          05 line  +7 column 35 value "Cyan    3"
                               lowlight  foreground-color cyan.
          05 line  +8 column 35 value "Red     4"
                               lowlight  foreground-color red.
          05 line  +9 column 35 value "Magenta 5"
                               lowlight  foreground-color magenta.
          05 line +10 column 35 value "Brown   6"
                               lowlight  foreground-color brown.
          05 line +11 column 35 value "White   7"
                               lowlight  foreground-color white
                                         background-color black.

          05 line  +4 column 52 value "Black   0"
                          reverse-video  foreground-color black
                                         background-color white.
          05 line  +5 column 52 value "Blue    1"
                          reverse-video  foreground-color blue.
          05 line  +6 column 52 value "Green   2"
                          reverse-video  foreground-color green.
          05 line  +7 column 52 value "Cyan    3"
                          reverse-video  foreground-color cyan.
          05 line  +8 column 52 value "Red     4"
                          reverse-video  foreground-color red.
          05 line  +9 column 52 value "Magenta 5"
                          reverse-video  foreground-color magenta.
          05 line +10 column 52 value "Brown   6"
                          reverse-video  foreground-color brown.
          05 line +11 column 52 value "White   7"
                          reverse-video  foreground-color white
                                         background-color black.

          05 line  +4 column 69 value "Black   0"
                                  blink  foreground-color black
                                         background-color white.
          05 line  +5 column 69 value "Blue    1"
                                  blink  foreground-color blue.
          05 line  +6 column 69 value "Green   2"
                                  blink  foreground-color green.
          05 line  +7 column 69 value "Cyan    3"
                                  blink  foreground-color cyan.
          05 line  +8 column 69 value "Red     4"
                                  blink  foreground-color red.
          05 line  +9 column 69 value "Magenta 5"
                                  blink  foreground-color magenta.
          05 line +10 column 69 value "Brown   6"
                                  blink  foreground-color brown.
          05 line +11 column 69 value "White   7"
                                  blink  foreground-color white
                                         background-color black.

          05 line +13 column 30 value "Enter to exit".
          05 line +13 column 44 using anykey.

      *> ***************************************************************
       procedure division.

       accept gnu-cobol-colours end-accept

       goback.
       end program gnucobol-colours.
