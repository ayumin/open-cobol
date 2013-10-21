      *>----------------------------------------------------------------
      *> Authors:   Brian Tiffin, Asger Kjelstrup, Simon Sobisch,
      *>            Roger While
      *> Purpose:   Hex Dump display
      *> Tectonics: cobc -m -std=mf -O2 CBL_OC_DUMP.cob
      *>     Usage: export OC_DUMP_EXT=1 for explanatory text on dumps
      *>            (memory address and dump length)
      *>            export OC_DUMP_EXT=Y for extended explanatory text
      *>            (architecture   and endian-order plus above)
      *>----------------------------------------------------------------
      *>
      *>  This file is part of OpenCOBOL.
      *>
      *>  The OpenCOBOL compiler is free software: you can redistribute
      *>  it and/or modify it under the terms of the GNU General Public
      *>  License as published by the Free Software Foundation, either
      *>  version 2 of the License, or (at your option) any later
      *>  version.
      *>
      *>  OpenCOBOL is distributed in the hope that it will be useful,
      *>  but WITHOUT ANY WARRANTY; without even the implied warranty of
      *>  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      *>  GNU General Public License for more details.
      *>
      *>  You should have received a copy of the GNU General Public
      *>  License along with OpenCOBOL.
      *>  If not, see <http://www.gnu.org/licenses/>.

       IDENTIFICATION   DIVISION.
       PROGRAM-ID.      CBL_OC_DUMP.
       ENVIRONMENT      DIVISION.
       CONFIGURATION    SECTION.
       DATA             DIVISION.
       WORKING-STORAGE  SECTION.
       77  addr                             usage pointer.
       77  addr2addr                        usage pointer.
       77  counter               pic 999999 usage comp-5.
       77  byline                pic 999    usage comp-5.
       01  was-called-before     usage binary-long unsigned value 0.
           88  called-before     value 1.
      *
       01  some                  pic 999    usage comp-5.
           88 some-is-printable-iso88591
              values 32 thru 126, 160 thru 255.
           88 some-is-printable-ebcdic
              values 64, 65, 74 thru 80, 90 thru 97,
                     106 thru 111, 121 thru 127, 129 thru 137, 143,
                     145 thru 153, 159, 161 thru 169, 176,
                     186 thru 188, 192 thru 201, 208 thru 217, 224,
                     226 thru 233, 240 thru 249.
       77  high-var              pic 99     usage comp-5.
       77  low-var               pic 99     usage comp-5.
      *
       01  char-set              pic x(06).
           88 is-ascii           value 'ASCII'.
           88 is-ebdic           value 'EBCDIC'.
           88 is-unknown         value '?'.
       01  architecture          pic x(06).
           88 is-32-bit          value '32-bit'.
           88 is-64-bit          value '64-bit'.
       01  endian-order          pic x(13).
           88 is-big-endian-no   value 'little endian'.
           88 is-big-endian-yes  value 'big endian'.
       01  dots                  pic x value '.'.
       01  dump-dots             pic x.

       77  hex-line-pointer      pic 9(02) value 1.
       01  disp-line.
           03  offset            pic 999999.
           03                    pic xx     value space.
           03  hex-line          pic x(48).
           03                    pic xx     value space.
           03  show              pic x(16).
       77  hex-digit             pic x(16)  value '0123456789abcdef'.

       01  extended-infos        pic x.
           88 show-extended-infos      values '1', '2', 'Y', 'y'.
           88 show-very-extended-infos values '2', 'Y', 'y'.

       77  len                   pic 999999 usage comp-5.
       77  len-display           pic ZZZZZ9.

       LINKAGE SECTION.
       01  buffer                pic x any length.
       01  valuelen              pic 9 any length.
      *
       01  byte                  pic x.
       01  byte-redef redefines  byte  usage binary-char unsigned.
      *>----------------------------------------------------------------
       PROCEDURE DIVISION USING buffer valuelen.
       MAIN SECTION.
       MAIN00.
           if number-of-call-parameters < 1
              display 'CBL_OC_DUMP: No parameter supplied'
                       upon SYSERR
              end-display
              goback
           end-if

           if not called-before
              *> First time through
              set called-before to true
              *> If wanted, set dot to something other than point
              accept dump-dots from environment 'OC_DUMP_DOTS'
                     not on exception
                         move dump-dots to dots
              end-accept
              *> Discover if running ASCII or EBCDIC
              perform TEST-ASCII
              *> Discover endianness
              perform TEST-ENDIAN

              *> Get and display characteristics and headline
              accept extended-infos from environment 'OC_DUMP_EXT'
              end-accept

              if show-very-extended-infos
                 *> Stuff that we only need to display once
                 *> Longer pointers in 64-bit architecture
                 perform TEST-64BIT

                 display 'Program runs on '
                         architecture ' architecture. '
                         upon SYSERR
                 end-display
                 display 'Character set is '
                         function trim (char-set) '.'
                         upon SYSERR
                 end-display
                 display 'Byte order is '
                         function trim (endian-order)
                         upon SYSERR
                 end-display
              end-if
           end-if

           *> Get the length of the parameter
           call 'C$PARAMSIZE' using 1
                giving len
           end-call

           *> Check if the user specified a length
           if number-of-call-parameters > 1
              if valuelen not numeric
                 display 'CBL_OC_DUMP: Length parameter is not numeric'
                         upon SYSERR
                 end-display
                 goback
              end-if
              if valuelen < 0
                 display 'CBL_OC_DUMP: Invalid length parameter: '
                         valuelen
                         upon SYSERR
                 end-display
                 goback
              end-if
              if valuelen < len
                 move valuelen to len
              end-if
           end-if
      *
           set addr      to address of buffer
           set addr2addr to address of addr
      *
           if len > 0
      * To show hex-address, reverse if Big-Little Endian
              if is-big-endian-yes
                 set addr2addr up   by LENGTH OF addr
                 set addr2addr down by 1
              end-if
              move 1 to hex-line-pointer
              perform varying byline from 1 by 1
                      until byline > LENGTH OF addr
                 set address of byte to addr2addr
                 perform calc-hex-value
                 if is-big-endian-yes
                    set addr2addr down by 1
                 else
                    set addr2addr up   by 1
                 end-if
              end-perform
           end-if

           if show-extended-infos
              display ' '
                      upon SYSERR
              end-display
              if len > 0
                 display 'Dump of memory beginning at address: '
                          hex-line (1 : 3 * (byline - 1) )
                          upon SYSERR
                 end-display
              end-if
              move len to len-display
              display 'Length of memory dump is: ' len-display
                       upon SYSERR
              end-display
           end-if

           *> Do we have anything to dump?
           if len = 0
              display ' '
                      upon SYSERR
              end-display
              display 'CBL_OC_DUMP: Nothing to dump.'
                      upon SYSERR
              end-display
              goback
           end-if

           *> Ensure that the passed size is not too big
           if len > 999998
              move 999998 to len, len-display
              display 'CBL_OC_DUMP: Warning, only the first '
                      len-display  ' bytes are shown!'
                      upon SYSERR
              end-display
           end-if

           display ' '
                   upon SYSERR
           end-display
           display 'Offset  ' &
                   'HEX-- -- -- -5 -- -- -- -- 10 ' &
                   '-- -- -- -- 15 --   ' &
                   'CHARS----1----5-'
                   upon SYSERR
           end-display

           *> Main loop
           perform varying counter from 0 by 16
                   until   counter  >=   len
              move counter to offset
              move spaces  to hex-line, show
              move '-'     to hex-line (24:01)
              move 1       to hex-line-pointer
              perform varying byline from 1 by 1
                      until   byline  >  16
                 if (counter + byline) > len
                    if byline < 9
                       move space to hex-line (24:01)
                    end-if
                    inspect show (byline:) replacing all spaces by dots
                    exit perform
                 end-if
                 move buffer (counter + byline : 1) to byte
                 perform CALC-HEX-VALUE
                 if ((some-is-printable-iso88591 and is-ascii) or
                     (some-is-printable-ebcdic   and is-ebdic)   )
                    move byte to show (byline:1)
                 else
                    move dots to show (byline:1)
                 end-if
              end-perform
              move counter to offset
              display disp-line
                      upon SYSERR
              end-display
           end-perform

           display ' '
                   upon SYSERR
           end-display

           goback
           .
      *-----------------------------------------------------------------
       TEST-ASCII SECTION.
      *Function: Discover if running Ascii or Ebcdic
      *00.
           evaluate space
              when x'20'
                 set  is-ascii   to true
              when x'40'
                 set  is-ebdic   to true
              when other
                 set  is-unknown to true
           end-evaluate
      *
           continue.
      *-----------------------------------------------------------------
       TEST-64BIT SECTION.
      *Function: Discover if running 32/64 bit
      *00.
      *    Longer pointers in 64-bit architecture
           if function length (addr) <= 4
              set  is-32-bit to true
           else
              set  is-64-bit to true
           end-if
      *
           continue.
      *-----------------------------------------------------------------
       TEST-ENDIAN SECTION.
      *00.
      *    Number-bytes are shuffled in Big-Little endian
           move 128 to byline
           set  address of byte to address of byline
           if function ord(byte) > 0
              set  is-big-endian-yes to true
           else
              set  is-big-endian-no  to true
           end-if
      *
           continue.
      *-----------------------------------------------------------------
       CALC-HEX-VALUE SECTION.
      *00.
           subtract 1 from function ord(byte) giving some
           end-subtract
           divide   some by 16 giving high-var remainder low-var
           end-divide
           string hex-digit (high-var + 1:1)
                  hex-digit (low-var  + 1:1)
                  space
                  delimited by size
                  into hex-line
                  with pointer hex-line-pointer
           end-string
      *
           continue.
      *-----------------------------------------------------------------
       end program CBL_OC_DUMP.
