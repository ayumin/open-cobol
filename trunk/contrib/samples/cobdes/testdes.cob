 IDENTIFICATION DIVISION.
 PROGRAM-ID. TESTDES.
*>**********************************************************************
*> Purpose:      Test program for COBDES 
*>
*> Author:       Laszlo Erdos
*>               https://www.facebook.com/wortfee
*>
*> Tectonics:    cobc -x -free testdes.cob
*>
*> Date-Written: 04-10-2013 
*>**********************************************************************
*> Date       Change description 
*> ========== ==========================================================
*>  
*>**********************************************************************

*>**********************************************************************
*> License: TESTDES is free for use in any environment, including but 
*> not necessarily limited to: personal, academic, commercial, 
*> government, business, non-profit, and for-profit. You may modify, 
*> adapt, rent, lease, loan, sell, or create derivative works based upon
*> the Software or any part thereof.
*> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
*> EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*> MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
*> NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY 
*> CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*> TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*> SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
*>**********************************************************************

 ENVIRONMENT DIVISION.

 DATA DIVISION.

*>**********************************************************************
 WORKING-STORAGE SECTION.

 01 WS-NUM2HEX-IN                      PIC 9(2) COMP-5.
 01 WS-NUM2HEX-OUT                     PIC X(2).
 01 WS-NUM2HEX-QUOTIENT                PIC 9(2) COMP-5.
 01 WS-NUM2HEX-REMAINDER               PIC 9(2) COMP-5.
 01 WS-HEX-CHAR                        PIC X(16) 
                                           VALUE "0123456789ABCDEF".
 01 WS-IND-1                           PIC 9(2) COMP-5.
 01 WS-IND-2                           PIC 9(2) COMP-5.

 01 WS-NUM-DATA                        PIC X(8).
 01 WS-NUM-TABLE REDEFINES WS-NUM-DATA.
   02 WS-NUM                           PIC 9(2) COMP-5 OCCURS 8.
 
 01 WS-HEX-DATA                        PIC X(16).
 01 WS-HEX-TABLE REDEFINES WS-HEX-DATA.
   02 WS-HEX                           PIC X(2) OCCURS 8.
 
 01 COBDES-LNK.
*> Input flag, DF = 0 -> encryption, DF = 1 -> decryption 
   02 DF                               PIC 9.
*> Input password
   02 PW                               PIC X(8).
*> Input / Output data block
   02 DATA-BUFF                        PIC X(8).
 
 PROCEDURE DIVISION.

*>----------------------------------------------------------------------
 TESTDES-MAIN SECTION.
*>----------------------------------------------------------------------

*>  Test 1 ********************

    DISPLAY "Test 1 ---------------------------------------------------"
    DISPLAY " "
    
*>  DF = 0 -> encryption
    MOVE 0                   TO DF                 OF COBDES-LNK
    MOVE "12345678"          TO PW                 OF COBDES-LNK
    MOVE "ABCDEFGH"          TO DATA-BUFF          OF COBDES-LNK

    DISPLAY "DF        OF COBDES-LNK = " DF        OF COBDES-LNK
    DISPLAY "PW        OF COBDES-LNK = " PW        OF COBDES-LNK
    DISPLAY "DATA-BUFF OF COBDES-LNK = " DATA-BUFF OF COBDES-LNK
    DISPLAY " "
    DISPLAY "        expected output = X""96DE603EAED6256F"" in hexa"
    DISPLAY " "
    DISPLAY "encryption..."
     
    CALL "COBDES" USING COBDES-LNK

*>  convert in hexa
    MOVE DATA-BUFF OF COBDES-LNK TO WS-NUM-DATA
    PERFORM DATA-BUFF-IN-HEXA
    
    DISPLAY " " 
    DISPLAY "output:"
    DISPLAY "DATA-BUFF OF COBDES-LNK =   " WS-HEX-DATA  "  in hexa"

*>  DF = 1 -> decryption
    MOVE 1                   TO DF                 OF COBDES-LNK
    MOVE "12345678"          TO PW                 OF COBDES-LNK
    MOVE X"96DE603EAED6256F" TO DATA-BUFF          OF COBDES-LNK

    DISPLAY " "
    DISPLAY "DF        OF COBDES-LNK = " DF        OF COBDES-LNK
    DISPLAY "PW        OF COBDES-LNK = " PW        OF COBDES-LNK
    DISPLAY "DATA-BUFF OF COBDES-LNK = X""96DE603EAED6256F"" in hexa"
    DISPLAY " "
    DISPLAY "        expected output = ABCDEFGH"
    DISPLAY " "
    DISPLAY "decryption..."
     
    CALL "COBDES" USING COBDES-LNK
    
    DISPLAY " " 
    DISPLAY "output:"
    DISPLAY "DATA-BUFF OF COBDES-LNK = " DATA-BUFF OF COBDES-LNK

*>  Test 2 ********************

    DISPLAY " "
    DISPLAY "Test 2 ---------------------------------------------------"
    DISPLAY " "
    
*>  DF = 0 -> encryption
    MOVE 0                   TO DF                 OF COBDES-LNK
    MOVE X"133457799BBCDFF1" TO PW                 OF COBDES-LNK
    MOVE X"0123456789ABCDEF" TO DATA-BUFF          OF COBDES-LNK

    DISPLAY "DF        OF COBDES-LNK = " DF        OF COBDES-LNK
    DISPLAY "PW        OF COBDES-LNK = X""133457799BBCDFF1"" in hexa"
    DISPLAY "DATA-BUFF OF COBDES-LNK = X""0123456789ABCDEF"" in hexa"
    DISPLAY " "
    DISPLAY "        expected output = X""85E813540F0AB405"" in hexa"
    DISPLAY " "
    DISPLAY "encryption..."
     
    CALL "COBDES" USING COBDES-LNK

*>  convert in hexa
    MOVE DATA-BUFF OF COBDES-LNK TO WS-NUM-DATA
    PERFORM DATA-BUFF-IN-HEXA
    
    DISPLAY " " 
    DISPLAY "output:"
    DISPLAY "DATA-BUFF OF COBDES-LNK =   " WS-HEX-DATA  "  in hexa"

*>  DF = 1 -> decryption
    MOVE 1                   TO DF                 OF COBDES-LNK
    MOVE X"133457799BBCDFF1" TO PW                 OF COBDES-LNK
    MOVE X"85E813540F0AB405" TO DATA-BUFF          OF COBDES-LNK

    DISPLAY " "
    DISPLAY "DF        OF COBDES-LNK = " DF        OF COBDES-LNK
    DISPLAY "PW        OF COBDES-LNK = X""133457799BBCDFF1"" in hexa"
    DISPLAY "DATA-BUFF OF COBDES-LNK = X""85E813540F0AB405"" in hexa"
    DISPLAY " "
    DISPLAY "        expected output = X""0123456789ABCDEF"" in hexa"
    DISPLAY " "
    DISPLAY "decryption..."
     
    CALL "COBDES" USING COBDES-LNK

*>  convert in hexa
    MOVE DATA-BUFF OF COBDES-LNK TO WS-NUM-DATA
    PERFORM DATA-BUFF-IN-HEXA
    
    DISPLAY " " 
    DISPLAY "output:"
    DISPLAY "DATA-BUFF OF COBDES-LNK =   " WS-HEX-DATA  "  in hexa"
    
    STOP RUN
    
    . 
 TESTDES-MAIN-EX.
    EXIT.

*>----------------------------------------------------------------------
 DATA-BUFF-IN-HEXA SECTION.
*>----------------------------------------------------------------------

    INITIALIZE WS-HEX-DATA
    
    PERFORM VARYING WS-IND-2 FROM 1 BY 1
            UNTIL   WS-IND-2 > 8

       MOVE WS-NUM(WS-IND-2) TO WS-NUM2HEX-IN
       PERFORM NUM2HEX
       MOVE WS-NUM2HEX-OUT   TO WS-HEX(WS-IND-2)       
    END-PERFORM
    
    .
 DATA-BUFF-IN-HEXA-EX.
    EXIT.
    
*>----------------------------------------------------------------------
 NUM2HEX SECTION.
*>----------------------------------------------------------------------

    INITIALIZE WS-NUM2HEX-OUT

    PERFORM VARYING WS-IND-1 FROM 2 BY -1
            UNTIL   WS-IND-1 < 1

       DIVIDE WS-NUM2HEX-IN BY 16
          GIVING    WS-NUM2HEX-QUOTIENT
          REMAINDER WS-NUM2HEX-REMAINDER
       END-DIVIDE

       ADD 1 TO WS-NUM2HEX-REMAINDER

       MOVE WS-HEX-CHAR(WS-NUM2HEX-REMAINDER:1)
         TO WS-NUM2HEX-OUT(WS-IND-1:1)

       MOVE WS-NUM2HEX-QUOTIENT
         TO WS-NUM2HEX-IN
    END-PERFORM
    
    .
 NUM2HEX-EX.
    EXIT.
