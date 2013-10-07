 IDENTIFICATION DIVISION.
 PROGRAM-ID. COBDES.
*>**********************************************************************
*> Purpose:      DES (Data Encryption Standard) in COBOL
*>               http://en.wikipedia.org/wiki/Data_Encryption_Standard
*>
*>               To use this subroutine, simply CALL it as follows: 
*>               CALL "COBDES" USING COBDES-LNK
*>               Fields in COBDES-LNK:
*>                 <df> - input flag, 0 encryption, 1 decryption 
*>                 <pw> - input password
*>                 <data-buff> - input / output data block
*>
*> Author:       Laszlo Erdos
*>               https://www.facebook.com/wortfee
*>
*> Tectonics:    cobc -free cobdes.cob
*>
*> Date-Written: 21-12-1997 
*>**********************************************************************
*> Date       Change description 
*> ========== ==========================================================
*> 04.10.2013 Converted to GNU Cobol 
*>**********************************************************************

*>**********************************************************************
*> License: COBDES is free for use in any environment, including but 
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
*> Initial permutation.
 01 IP-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    58.
     03  FILLER      PIC 9(2) COMP-5 VALUE    50.
     03  FILLER      PIC 9(2) COMP-5 VALUE    42.
     03  FILLER      PIC 9(2) COMP-5 VALUE    34.
     03  FILLER      PIC 9(2) COMP-5 VALUE    26.
     03  FILLER      PIC 9(2) COMP-5 VALUE    18.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE    60.
     03  FILLER      PIC 9(2) COMP-5 VALUE    52.
     03  FILLER      PIC 9(2) COMP-5 VALUE    44.
     03  FILLER      PIC 9(2) COMP-5 VALUE    36.
     03  FILLER      PIC 9(2) COMP-5 VALUE    28.
     03  FILLER      PIC 9(2) COMP-5 VALUE    20.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE    62.
     03  FILLER      PIC 9(2) COMP-5 VALUE    54.
     03  FILLER      PIC 9(2) COMP-5 VALUE    46.
     03  FILLER      PIC 9(2) COMP-5 VALUE    38.
     03  FILLER      PIC 9(2) COMP-5 VALUE    30.
     03  FILLER      PIC 9(2) COMP-5 VALUE    22.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE    64.
     03  FILLER      PIC 9(2) COMP-5 VALUE    56.
     03  FILLER      PIC 9(2) COMP-5 VALUE    48.
     03  FILLER      PIC 9(2) COMP-5 VALUE    40.
     03  FILLER      PIC 9(2) COMP-5 VALUE    32.
     03  FILLER      PIC 9(2) COMP-5 VALUE    24.
     03  FILLER      PIC 9(2) COMP-5 VALUE    16.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
*> 5
     03  FILLER      PIC 9(2) COMP-5 VALUE    57.
     03  FILLER      PIC 9(2) COMP-5 VALUE    49.
     03  FILLER      PIC 9(2) COMP-5 VALUE    41.
     03  FILLER      PIC 9(2) COMP-5 VALUE    33.
     03  FILLER      PIC 9(2) COMP-5 VALUE    25.
     03  FILLER      PIC 9(2) COMP-5 VALUE    17.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
*> 6
     03  FILLER      PIC 9(2) COMP-5 VALUE    59.
     03  FILLER      PIC 9(2) COMP-5 VALUE    51.
     03  FILLER      PIC 9(2) COMP-5 VALUE    43.
     03  FILLER      PIC 9(2) COMP-5 VALUE    35.
     03  FILLER      PIC 9(2) COMP-5 VALUE    27.
     03  FILLER      PIC 9(2) COMP-5 VALUE    19.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
*> 7
     03  FILLER      PIC 9(2) COMP-5 VALUE    61.
     03  FILLER      PIC 9(2) COMP-5 VALUE    53.
     03  FILLER      PIC 9(2) COMP-5 VALUE    45.
     03  FILLER      PIC 9(2) COMP-5 VALUE    37.
     03  FILLER      PIC 9(2) COMP-5 VALUE    29.
     03  FILLER      PIC 9(2) COMP-5 VALUE    21.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
*> 8
     03  FILLER      PIC 9(2) COMP-5 VALUE    63.
     03  FILLER      PIC 9(2) COMP-5 VALUE    55.
     03  FILLER      PIC 9(2) COMP-5 VALUE    47.
     03  FILLER      PIC 9(2) COMP-5 VALUE    39.
     03  FILLER      PIC 9(2) COMP-5 VALUE    31.
     03  FILLER      PIC 9(2) COMP-5 VALUE    23.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.

 01  IP-TABLE    REDEFINES   IP-TABLE-DATA.
     03  IP          PIC 9(2) COMP-5  OCCURS  64.
*>----------------------------------------------------------------------

*> Final permutation. FP = IP (-1)
 01 FP-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    40.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    48.
     03  FILLER      PIC 9(2) COMP-5 VALUE    16.
     03  FILLER      PIC 9(2) COMP-5 VALUE    56.
     03  FILLER      PIC 9(2) COMP-5 VALUE    24.
     03  FILLER      PIC 9(2) COMP-5 VALUE    64.
     03  FILLER      PIC 9(2) COMP-5 VALUE    32.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE    39.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    47.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    55.
     03  FILLER      PIC 9(2) COMP-5 VALUE    23.
     03  FILLER      PIC 9(2) COMP-5 VALUE    63.
     03  FILLER      PIC 9(2) COMP-5 VALUE    31.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE    38.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    46.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    54.
     03  FILLER      PIC 9(2) COMP-5 VALUE    22.
     03  FILLER      PIC 9(2) COMP-5 VALUE    62.
     03  FILLER      PIC 9(2) COMP-5 VALUE    30.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE    37.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    45.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    53.
     03  FILLER      PIC 9(2) COMP-5 VALUE    21.
     03  FILLER      PIC 9(2) COMP-5 VALUE    61.
     03  FILLER      PIC 9(2) COMP-5 VALUE    29.
*> 5
     03  FILLER      PIC 9(2) COMP-5 VALUE    36.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    44.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    52.
     03  FILLER      PIC 9(2) COMP-5 VALUE    20.
     03  FILLER      PIC 9(2) COMP-5 VALUE    60.
     03  FILLER      PIC 9(2) COMP-5 VALUE    28.
*> 6
     03  FILLER      PIC 9(2) COMP-5 VALUE    35.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    43.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    51.
     03  FILLER      PIC 9(2) COMP-5 VALUE    19.
     03  FILLER      PIC 9(2) COMP-5 VALUE    59.
     03  FILLER      PIC 9(2) COMP-5 VALUE    27.
*> 7
     03  FILLER      PIC 9(2) COMP-5 VALUE    34.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    42.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    50.
     03  FILLER      PIC 9(2) COMP-5 VALUE    18.
     03  FILLER      PIC 9(2) COMP-5 VALUE    58.
     03  FILLER      PIC 9(2) COMP-5 VALUE    26.
*> 8
     03  FILLER      PIC 9(2) COMP-5 VALUE    33.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    41.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    49.
     03  FILLER      PIC 9(2) COMP-5 VALUE    17.
     03  FILLER      PIC 9(2) COMP-5 VALUE    57.
     03  FILLER      PIC 9(2) COMP-5 VALUE    25.

 01  FP-TABLE    REDEFINES   FP-TABLE-DATA.
     03  FP          PIC 9(2) COMP-5  OCCURS  64.
*>----------------------------------------------------------------------

*> Permuted key selection bits.
*> The results are in the C and D arrays.
*> Every 8-bits are skipped, they are only for parity checking.
 01 PC1-C-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    57.
     03  FILLER      PIC 9(2) COMP-5 VALUE    49.
     03  FILLER      PIC 9(2) COMP-5 VALUE    41.
     03  FILLER      PIC 9(2) COMP-5 VALUE    33.
     03  FILLER      PIC 9(2) COMP-5 VALUE    25.
     03  FILLER      PIC 9(2) COMP-5 VALUE    17.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    58.
     03  FILLER      PIC 9(2) COMP-5 VALUE    50.
     03  FILLER      PIC 9(2) COMP-5 VALUE    42.
     03  FILLER      PIC 9(2) COMP-5 VALUE    34.
     03  FILLER      PIC 9(2) COMP-5 VALUE    26.
     03  FILLER      PIC 9(2) COMP-5 VALUE    18.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    59.
     03  FILLER      PIC 9(2) COMP-5 VALUE    51.
     03  FILLER      PIC 9(2) COMP-5 VALUE    43.
     03  FILLER      PIC 9(2) COMP-5 VALUE    35.
     03  FILLER      PIC 9(2) COMP-5 VALUE    27.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE    19.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    60.
     03  FILLER      PIC 9(2) COMP-5 VALUE    52.
     03  FILLER      PIC 9(2) COMP-5 VALUE    44.
     03  FILLER      PIC 9(2) COMP-5 VALUE    36.

 01  PC1-C-TABLE    REDEFINES   PC1-C-TABLE-DATA.
     03  PC1-C1      PIC 9(2) COMP-5  OCCURS  28.
*>----------------------------------------------------------------------

 01  PC1-D-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    63.
     03  FILLER      PIC 9(2) COMP-5 VALUE    55.
     03  FILLER      PIC 9(2) COMP-5 VALUE    47.
     03  FILLER      PIC 9(2) COMP-5 VALUE    39.
     03  FILLER      PIC 9(2) COMP-5 VALUE    31.
     03  FILLER      PIC 9(2) COMP-5 VALUE    23.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    62.
     03  FILLER      PIC 9(2) COMP-5 VALUE    54.
     03  FILLER      PIC 9(2) COMP-5 VALUE    46.
     03  FILLER      PIC 9(2) COMP-5 VALUE    38.
     03  FILLER      PIC 9(2) COMP-5 VALUE    30.
     03  FILLER      PIC 9(2) COMP-5 VALUE    22.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    61.
     03  FILLER      PIC 9(2) COMP-5 VALUE    53.
     03  FILLER      PIC 9(2) COMP-5 VALUE    45.
     03  FILLER      PIC 9(2) COMP-5 VALUE    37.
     03  FILLER      PIC 9(2) COMP-5 VALUE    29.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE    21.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    28.
     03  FILLER      PIC 9(2) COMP-5 VALUE    20.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.

 01  PC1-D-TABLE    REDEFINES   PC1-D-TABLE-DATA.
     03  PC1-D1      PIC 9(2) COMP-5  OCCURS  28.
*>----------------------------------------------------------------------

*> For the key scheduler. 
*> Rotate order of cycle.
 01  SS-TABLE-DATA.
     03  FILLER      PIC 9(2) COMP-5 VALUE    1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    1.

 01  SS-TABLE    REDEFINES   SS-TABLE-DATA.
     03  SS          PIC 9(2) COMP-5  OCCURS  16.
*>----------------------------------------------------------------------

*> Permuted selection for the 48-bits key cycle.
*> The result is in the key scheduler.
 01  PC2-C-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    17.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    24.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    28.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    21.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE    23.
     03  FILLER      PIC 9(2) COMP-5 VALUE    19.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    26.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE    16.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    27.
     03  FILLER      PIC 9(2) COMP-5 VALUE    20.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.

 01  PC2-C-TABLE    REDEFINES   PC2-C-TABLE-DATA.
     03  PC2-C2      PIC 9(2) COMP-5  OCCURS  24.
*>----------------------------------------------------------------------

 01  PC2-D-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    41.
     03  FILLER      PIC 9(2) COMP-5 VALUE    52.
     03  FILLER      PIC 9(2) COMP-5 VALUE    31.
     03  FILLER      PIC 9(2) COMP-5 VALUE    37.
     03  FILLER      PIC 9(2) COMP-5 VALUE    47.
     03  FILLER      PIC 9(2) COMP-5 VALUE    55.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE    30.
     03  FILLER      PIC 9(2) COMP-5 VALUE    40.
     03  FILLER      PIC 9(2) COMP-5 VALUE    51.
     03  FILLER      PIC 9(2) COMP-5 VALUE    45.
     03  FILLER      PIC 9(2) COMP-5 VALUE    33.
     03  FILLER      PIC 9(2) COMP-5 VALUE    48.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE    44.
     03  FILLER      PIC 9(2) COMP-5 VALUE    49.
     03  FILLER      PIC 9(2) COMP-5 VALUE    39.
     03  FILLER      PIC 9(2) COMP-5 VALUE    56.
     03  FILLER      PIC 9(2) COMP-5 VALUE    34.
     03  FILLER      PIC 9(2) COMP-5 VALUE    53.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE    46.
     03  FILLER      PIC 9(2) COMP-5 VALUE    42.
     03  FILLER      PIC 9(2) COMP-5 VALUE    50.
     03  FILLER      PIC 9(2) COMP-5 VALUE    36.
     03  FILLER      PIC 9(2) COMP-5 VALUE    29.
     03  FILLER      PIC 9(2) COMP-5 VALUE    32.

 01  PC2-D-TABLE    REDEFINES   PC2-D-TABLE-DATA.
     03  PC2-D2      PIC 9(2) COMP-5  OCCURS  24.
*>----------------------------------------------------------------------

*> C and D arrays for creation of the key scheduler.
 01  C-TABLE.
     03  C           PIC 9(2) COMP-5  OCCURS  28.

 01  D-TABLE.
     03  D           PIC 9(2) COMP-5  OCCURS  28.
*>----------------------------------------------------------------------

*> The key scheduler, created from the password.
 01  KS-TABLE.
     03  KS-ROW          OCCURS 16.
         05  KS-COL      OCCURS 48.
             07  KS      PIC 9(2) COMP-5.
*>----------------------------------------------------------------------

*> This table extends 32-bits to 48-bits.
 01  EX-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    32.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    16.
     03  FILLER      PIC 9(2) COMP-5 VALUE    17.
*> 5
     03  FILLER      PIC 9(2) COMP-5 VALUE    16.
     03  FILLER      PIC 9(2) COMP-5 VALUE    17.
     03  FILLER      PIC 9(2) COMP-5 VALUE    18.
     03  FILLER      PIC 9(2) COMP-5 VALUE    19.
     03  FILLER      PIC 9(2) COMP-5 VALUE    20.
     03  FILLER      PIC 9(2) COMP-5 VALUE    21.
*> 6
     03  FILLER      PIC 9(2) COMP-5 VALUE    20.
     03  FILLER      PIC 9(2) COMP-5 VALUE    21.
     03  FILLER      PIC 9(2) COMP-5 VALUE    22.
     03  FILLER      PIC 9(2) COMP-5 VALUE    23.
     03  FILLER      PIC 9(2) COMP-5 VALUE    24.
     03  FILLER      PIC 9(2) COMP-5 VALUE    25.
*> 7
     03  FILLER      PIC 9(2) COMP-5 VALUE    24.
     03  FILLER      PIC 9(2) COMP-5 VALUE    25.
     03  FILLER      PIC 9(2) COMP-5 VALUE    26.
     03  FILLER      PIC 9(2) COMP-5 VALUE    27.
     03  FILLER      PIC 9(2) COMP-5 VALUE    28.
     03  FILLER      PIC 9(2) COMP-5 VALUE    29.
*> 8
     03  FILLER      PIC 9(2) COMP-5 VALUE    28.
     03  FILLER      PIC 9(2) COMP-5 VALUE    29.
     03  FILLER      PIC 9(2) COMP-5 VALUE    30.
     03  FILLER      PIC 9(2) COMP-5 VALUE    31.
     03  FILLER      PIC 9(2) COMP-5 VALUE    32.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.

 01  EX-TABLE    REDEFINES       EX-TABLE-DATA.
     03  EX          PIC 9(2) COMP-5  OCCURS  48.
*>----------------------------------------------------------------------

*> 8 S-boxes.
 01  S-TABLE-DATA.
*> 1-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.

*> 1-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.

*> 1-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.

*> 1-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.

*> 2-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.

*> 2-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.

*> 2-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.

*> 2-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.

*> 3-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.

*> 3-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.

*> 3-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.

*> 3-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.

*> 4-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.

*> 4-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.

*> 4-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.

*> 4-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.

*> 5-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.

*> 5-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.

*> 5-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.

*> 5-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.

*> 6-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.

*> 6-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.

*> 6-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.

*> 6-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.

*> 7-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.

*> 7-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.

*> 7-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.

*> 7-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.

*> 8-1/4
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.

*> 8-2/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.

*> 8-3/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.

*> 8-4/4
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
     03  FILLER      PIC 9(2) COMP-5 VALUE     0.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.

 01  S-TABLE     REDEFINES       S-TABLE-DATA.
     03  S-ROW       OCCURS  8.
         05  S-COL   OCCURS 64.
             07  S   PIC 9(2) COMP-5.
*>----------------------------------------------------------------------

*> Permutation of the S-box outputs.
 01  P-TABLE-DATA.
*> 1
     03  FILLER      PIC 9(2) COMP-5 VALUE    16.
     03  FILLER      PIC 9(2) COMP-5 VALUE     7.
     03  FILLER      PIC 9(2) COMP-5 VALUE    20.
     03  FILLER      PIC 9(2) COMP-5 VALUE    21.
*> 2
     03  FILLER      PIC 9(2) COMP-5 VALUE    29.
     03  FILLER      PIC 9(2) COMP-5 VALUE    12.
     03  FILLER      PIC 9(2) COMP-5 VALUE    28.
     03  FILLER      PIC 9(2) COMP-5 VALUE    17.
*> 3
     03  FILLER      PIC 9(2) COMP-5 VALUE     1.
     03  FILLER      PIC 9(2) COMP-5 VALUE    15.
     03  FILLER      PIC 9(2) COMP-5 VALUE    23.
     03  FILLER      PIC 9(2) COMP-5 VALUE    26.
*> 4
     03  FILLER      PIC 9(2) COMP-5 VALUE     5.
     03  FILLER      PIC 9(2) COMP-5 VALUE    18.
     03  FILLER      PIC 9(2) COMP-5 VALUE    31.
     03  FILLER      PIC 9(2) COMP-5 VALUE    10.
*> 5
     03  FILLER      PIC 9(2) COMP-5 VALUE     2.
     03  FILLER      PIC 9(2) COMP-5 VALUE     8.
     03  FILLER      PIC 9(2) COMP-5 VALUE    24.
     03  FILLER      PIC 9(2) COMP-5 VALUE    14.
*> 6
     03  FILLER      PIC 9(2) COMP-5 VALUE    32.
     03  FILLER      PIC 9(2) COMP-5 VALUE    27.
     03  FILLER      PIC 9(2) COMP-5 VALUE     3.
     03  FILLER      PIC 9(2) COMP-5 VALUE     9.
*> 7
     03  FILLER      PIC 9(2) COMP-5 VALUE    19.
     03  FILLER      PIC 9(2) COMP-5 VALUE    13.
     03  FILLER      PIC 9(2) COMP-5 VALUE    30.
     03  FILLER      PIC 9(2) COMP-5 VALUE     6.
*> 8
     03  FILLER      PIC 9(2) COMP-5 VALUE    22.
     03  FILLER      PIC 9(2) COMP-5 VALUE    11.
     03  FILLER      PIC 9(2) COMP-5 VALUE     4.
     03  FILLER      PIC 9(2) COMP-5 VALUE    25.

 01  P-TABLE     REDEFINES   P-TABLE-DATA.
     03  P           PIC 9(2) COMP-5  OCCURS  32.
*>----------------------------------------------------------------------

*> The two sides of the splitted block.
 01  LEFT-RIGHT-TABLE.
     03  LR-TABLE    PIC 9(2) COMP-5  OCCURS  64.
 01  LR-TABLE-RE REDEFINES LEFT-RIGHT-TABLE.
     03  LLEFT       PIC 9(2) COMP-5  OCCURS  32.
     03  RRIGHT      PIC 9(2) COMP-5  OCCURS  32.
*>----------------------------------------------------------------------

*> Left half block temp storage.
 01  TEMPL-TABLE.
     03  TEMPL       PIC 9(2) COMP-5  OCCURS  32.
*>----------------------------------------------------------------------

*> This 32-bits block will be created from 
*> the right half block and the key scheduler.
 01  F-TABLE.
     03  F           PIC 9(2) COMP-5  OCCURS  32.
*>----------------------------------------------------------------------

*> The input and the iteration key modulo 2 sum.
 01  PRES-TABLE.
     03  PRES        PIC 9(2) COMP-5  OCCURS  48.
*>----------------------------------------------------------------------

*> Indices for cycles and temp vars.
 01  I               PIC 9(2) COMP-5.
 01  J               PIC 9(2) COMP-5.
 01  K               PIC 9(2) COMP-5.
 01  L               PIC 9(2) COMP-5.
 01  M               PIC 9(2) COMP-5.
 01  N               PIC 9(2) COMP-5.
 01  T               PIC 9(2) COMP-5. 

*> Character processing.
 01  CHAR            PIC 9(2) COMP-5.
 01  AND-VAL         PIC 9(2) COMP-5  VALUE 1.

*> For BIN2CHAR / CHAR2BIN.
 01  BIN-DATA        PIC X(8).
 01  BIN-TABLE REDEFINES BIN-DATA.
     03  BIN         PIC 9(2) COMP-5  OCCURS   8.

*> The block array.
 01  BLK-TABLE.
     03  BLK         PIC 9(2) COMP-5  OCCURS  64.
 
*>**********************************************************************
 LINKAGE SECTION.
 01  COBDES-LNK.
*> Input flag, DF = 0 -> encryption, DF = 1 -> decryption. 
     02 DF           PIC 9.
*> Input password.
     02 PW           PIC X(8).
*> Input / Output data block.
     02 DATA-BUFF    PIC X(8).

*>**********************************************************************
 PROCEDURE DIVISION USING COBDES-LNK.        

*>----------------------------------------------------------------------
 DES-MAIN SECTION.
*>----------------------------------------------------------------------

*>  Password in bin.
    MOVE PW                            OF COBDES-LNK 
      TO BIN-DATA
 
*>  Convert password in block.
    PERFORM BIN2CHAR

*>  Create key scheduler from password.     
    PERFORM SETKEY

*>  Input data in bin.
    MOVE DATA-BUFF                     OF COBDES-LNK 
      TO BIN-DATA
      
*>  Convert input data in block.
    PERFORM BIN2CHAR

*>  One block encryption (DF = 0) or decryption (DF = 1).
    PERFORM CRYPT
    
*>  Convert block in bin.
    PERFORM CHAR2BIN
    
*>  Move output data in linkage.
    MOVE BIN-DATA 
      TO DATA-BUFF                     OF COBDES-LNK

    . 
 DES-MAIN-EX.
    GOBACK.

*>----------------------------------------------------------------------
 BIN2CHAR SECTION.
*>----------------------------------------------------------------------
*> Input:  BIN -  8 char array.
*> Output: BLK - 64 char array.

    PERFORM VARYING I FROM 1 BY 1 UNTIL I > 64
       MOVE ZEROES TO BLK( I )
    END-PERFORM

    MOVE 1 TO I
    MOVE 1 TO K

    PERFORM UNTIL I > 64
       MOVE BIN( K ) TO CHAR
       MOVE BIN( K ) TO N

       ADD 1 TO K

       PERFORM VARYING J FROM 1 BY 1 UNTIL J > 8
          COMPUTE M = 8 - J END-COMPUTE

          PERFORM M TIMES
             COMPUTE L = N / 2 END-COMPUTE
             MOVE L TO N
          END-PERFORM

          CALL "CBL_AND" USING AND-VAL N
                         BY VALUE LENGTH OF AND-VAL

          MOVE N    TO BLK( I )
          MOVE CHAR TO N
          ADD  1    TO I
       END-PERFORM
    END-PERFORM

    .     
 BIN2CHAR-EX.
     EXIT.

*>----------------------------------------------------------------------
 CHAR2BIN SECTION.
*>----------------------------------------------------------------------
*> Input:  BLK - 64 char array.
*> Output: BIN -  8 char array.

    PERFORM VARYING I FROM 1 BY 1 UNTIL I > 8
       MOVE ZEROES TO BIN( I )
    END-PERFORM

    MOVE 1 TO K

    PERFORM VARYING I FROM 1 BY 1 UNTIL I > 8
       PERFORM VARYING J FROM 1 BY 1 UNTIL J > 8
          COMPUTE BIN( I ) = BIN( I ) * 2 END-COMPUTE
          MOVE BLK( K ) TO N
          MOVE BIN( I ) TO L

          CALL "CBL_AND" USING AND-VAL N
                         BY VALUE LENGTH OF AND-VAL

          CALL "CBL_OR"  USING L N
                         BY VALUE LENGTH OF L

          MOVE N TO BIN( I )
          ADD 1  TO K
       END-PERFORM
    END-PERFORM

    .
 CHAR2BIN-EX.
    EXIT.
	 
*>----------------------------------------------------------------------
 SETKEY SECTION.
*>----------------------------------------------------------------------
*> Create the key scheduler from the password. 
*> Input:  BLK - 64 char array.
*> Output: KS  - 16x48 char array, the key scheduler.

*>  Permuted selection 1.
    PERFORM VARYING I FROM 1 BY 1 UNTIL I > 28
       MOVE PC1-C1( I ) TO K
       MOVE BLK( K )    TO C( I )
       MOVE PC1-D1( I ) TO L
       MOVE BLK( L )    TO D( I )
    END-PERFORM

*>  Iteration key generation for the key scheduler.
    PERFORM VARYING I FROM 1 BY 1 UNTIL I > 16
*>     Cycle rotation.
       PERFORM VARYING K FROM 1 BY 1 UNTIL K > SS( I )
          MOVE C( 1 ) TO N

          PERFORM VARYING J FROM 1 BY 1 UNTIL J > 27
             MOVE C( J + 1 ) TO  C( J )
          END-PERFORM

          MOVE N      TO  C( 28 )
          MOVE D( 1 ) TO  N

          PERFORM VARYING J FROM 1 BY 1 UNTIL J > 27
             MOVE D( J + 1 ) TO  D( J )
          END-PERFORM

          MOVE N TO D( 28 )
       END-PERFORM

*>     Permuted selection 2.
*>     The result are in the key scheduler.
       PERFORM VARYING J FROM 1 BY 1 UNTIL J > 24
          MOVE PC2-C2( J ) TO K
          MOVE C( K )      TO KS( I, J )

          COMPUTE L = PC2-D2( J ) - 28 END-COMPUTE

          MOVE D( L ) TO KS( I, J + 24 )
       END-PERFORM
    END-PERFORM
    
    .
 SETKEY-EX.
    EXIT.
     
*>----------------------------------------------------------------------
 CRYPT SECTION.
*>----------------------------------------------------------------------
*> One block encryption (df = 0), or decryption (df = 1).
*> Input: DF - flag
*> Input / Output:  BLK - 64 char array. 

*>  Permutation of the input bits. 
    PERFORM VARYING J FROM 1 BY 1 UNTIL J > 64
       MOVE BLK( IP( J ) ) TO LR-TABLE( J )
    END-PERFORM

*>  The 16-times main cycle.
    PERFORM VARYING I FROM 1 BY 1 UNTIL I > 16

*>     Save the R (right) half block, this will be later the L (left).
       PERFORM VARYING J FROM 1 BY 1 UNTIL J > 32
          MOVE RRIGHT( J ) TO TEMPL( J )
       END-PERFORM

*>     Extends R to 48-bits with EX.       
*>     Modulo 2 sum with the actual iteration key.
       PERFORM VARYING J FROM 1 BY 1 UNTIL J > 48
*>        Encryption (df = 0), or decryption (df = 1).
          COMPUTE K = 17 * DF + I * (1 - 2 * DF) END-COMPUTE
          
          MOVE KS( K, J )        TO L
          MOVE RRIGHT( EX( J ) ) TO N

          CALL "CBL_XOR" USING L N
                         BY VALUE LENGTH OF L

          MOVE N TO PRES( J ) 
       END-PERFORM
       
*>     Cut the 48-bits in 8 parts 6-bits, and
*>     replace them with the S-boxes corresponding elements. 
       PERFORM VARYING J FROM 0 BY 1 UNTIL J > 7
          COMPUTE T = 6 * J END-COMPUTE
          
          COMPUTE M = PRES( T + 1 ) * ( 2 ** 5 ) +
                      PRES( T + 2 ) * ( 2 ** 3 ) +
                      PRES( T + 3 ) * ( 2 ** 2 ) +
                      PRES( T + 4 ) * ( 2 ** 1 ) +
                      PRES( T + 5 ) * ( 2 ** 0 ) +
                      PRES( T + 6 ) * ( 2 ** 4 ) 
          END-COMPUTE

          MOVE S( J + 1, M + 1 ) TO K

          COMPUTE T = 4 * J END-COMPUTE

          COMPUTE N = K / ( 2 ** 3 ) END-COMPUTE
          CALL "CBL_AND" USING AND-VAL N
                         BY VALUE LENGTH OF AND-VAL
          MOVE N TO F( T + 1 ) 
          
          COMPUTE N = K / ( 2 ** 2 ) END-COMPUTE
          CALL "CBL_AND" USING AND-VAL N
                         BY VALUE LENGTH OF AND-VAL
          MOVE N TO F( T + 2 ) 

          COMPUTE N = K / ( 2 ** 1 ) END-COMPUTE
          CALL "CBL_AND" USING AND-VAL N
                         BY VALUE LENGTH OF AND-VAL
          MOVE N TO F( T + 3 ) 

          COMPUTE N = K / ( 2 ** 0 ) END-COMPUTE
          CALL "CBL_AND" USING AND-VAL N
                         BY VALUE LENGTH OF AND-VAL
          MOVE N TO F( T + 4 ) 
       END-PERFORM

*>     P permutation.
*>     R half block new value is the L half block modulo 2 F(R,K).
       PERFORM VARYING J FROM 1 BY 1 UNTIL J > 32
          MOVE F( P( J ) ) TO L
          MOVE LLEFT( J )  TO N

          CALL "CBL_XOR" USING L N
                         BY VALUE LENGTH OF L

          MOVE N TO RRIGHT( J ) 
       END-PERFORM
       
*>     R half block old value in the L half block.
       PERFORM VARYING J FROM 1 BY 1 UNTIL J > 32
          MOVE TEMPL( J ) TO LLEFT( J ) 
       END-PERFORM
    END-PERFORM

*>  Change L and R content.
    PERFORM VARYING J FROM 1 BY 1 UNTIL J > 32
       MOVE LLEFT( J )  TO N
       MOVE RRIGHT( J ) TO LLEFT( J )
       MOVE N           TO RRIGHT( J )
    END-PERFORM

*>  After the last permutation, the result is in the block.
    PERFORM VARYING J FROM 1 BY 1 UNTIL J > 64
       MOVE LR-TABLE( FP( J ) ) TO BLK( J ) 
    END-PERFORM
    
    .
 CRYPT-EX.
    EXIT.
     
 