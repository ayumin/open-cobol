       IDENTIFICATION DIVISION.
       PROGRAM-ID. RWTST2.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
           SELECT CUST-ORDER-FILE ASSIGN TO EXTERNAL CUSTORD
                          ORGANIZATION IS LINE SEQUENTIAL. 
           SELECT CUST-PRINT-FILE ASSIGN TO EXTERNAL 
                          LINE ADVANCING REPORT2.

       DATA DIVISION.
       FILE SECTION.
       FD  CUST-ORDER-FILE
            RECORD CONTAINS 30 CHARACTERS.
       01  CUST-ORDER-REC.
           05  CUST-NUM      PIC 9(5).
           05  ITEM-NUM      PIC 9(6).
           05  NUM-ORD       PIC 999.
           05  PRICE         PIC 999V99.
           05  SHIPPING      PIC 99V99.
           05  FILLER        PIC X(7).

       FD  CUST-PRINT-FILE
            REPORT IS ORDER-REPORT.

       WORKING-STORAGE SECTION.
       01    INDICATORS.
           05  ARE-THERE-MORE-RECORDS     PIC XXX   VALUE 'YES'.
               88  THERE-ARE-NO-MORE-RECORDS        VALUE 'NO '.
       01    CONSTANTS.
           05  SALES-TAX     PIC 9V99        VALUE 0.05.
       01      WORK-AREAS.
           05  AMT-TAX       PIC 9999V99      VALUE 0.
           05  AMT-ORDER     PIC 9(5)V99      VALUE 0.
           05  TOT-ORDER     PIC 9(6)V99      VALUE 0.
       
       REPORT SECTION.
       RD    ORDER-REPORT
           CONTROLS ARE FINAL
           PAGE 55 LINES
           FIRST DETAIL 6.
       01    TYPE REPORT HEADING
                  LINE 1.
           10    COLUMN 44    PIC X(21)    
                                  VALUE 'CUSTOMER ORDER REPORT'.
       01  TYPE PAGE HEADING.
           05  LINE 2.
               10  COLUMN  94   PIC X(5) VALUE 'PAGE'.
               10  COLUMN 106    PIC ZZ9
                      SOURCE PAGE-COUNTER.
           05  LINE 4.
               10  COLUMN 11    PIC X(8) VALUE 'CUST NUM'.
               10  COLUMN 26    PIC XXXX VALUE 'PART'.
               10  COLUMN 39    PIC X(7) VALUE '# ITEMS'.
               10  COLUMN 50    PIC X(5) VALUE 'PRICE'.
               10  COLUMN 66    PIC X(8) VALUE 'QUANTITY'.
               10  COLUMN 82    PIC XXX  VALUE 'TAX'.
               10  COLUMN 91    PIC X(8) VALUE 'SHIPPING'.
               10  COLUMN 108   PIC X(5) VALUE 'TOTAL'.

       01    DETAIL-LINE TYPE IS DETAIL
             LINE PLUS 1.
           05  COLUMN 12        PIC 9(5)
                      SOURCE CUST-NUM.
           05  COLUMN 25        PIC 9(6)
                      SOURCE ITEM-NUM.
           05  COLUMN 41        PIC 999
                      SOURCE NUM-ORD.
           05  COLUMN 49        PIC ZZZ.99
                      SOURCE PRICE.
           05  COLUMN 64        PIC ZZ,ZZZ.99
                      SOURCE AMT-ORDER.
           05  COLUMN 80        PIC Z,ZZZ.99
                      SOURCE AMT-TAX.
           05  COLUMN 93        PIC ZZ.99
                      SOURCE SHIPPING.
           05  COLUMN 104        PIC ZZZ,ZZZ.99
                      SOURCE TOT-ORDER.
           
       
       01     TYPE CONTROL FOOTING FINAL
           LINE PLUS 2.
           05  COLUMN 42        PIC X(12)
                      VALUE 'FINAL TOTALS'.
           05  COLUMN 63        PIC ZZZ,ZZZ.99
                      SOURCE AMT-ORDER.
           05  COLUMN 79        PIC ZZ,ZZZ.99
                      SUM AMT-TAX.
           05  COLUMN 92        PIC ZZZ.99
                      SUM SHIPPING.
           05  COLUMN 102        PIC Z,ZZZ,ZZZ.99
                      SUM TOT-ORDER.

       PROCEDURE DIVISION.
       A000-MAINLINE.
           DISPLAY "Report test 2" UPON CONSOLE.
           OPEN INPUT  CUST-ORDER-FILE
                OUTPUT CUST-PRINT-FILE.
           INITIATE ORDER-REPORT.
           READ CUST-ORDER-FILE
                AT END
                    MOVE 'NO' TO ARE-THERE-MORE-RECORDS.
           PERFORM A001-LOOP
                UNTIL THERE-ARE-NO-MORE-RECORDS.
           TERMINATE ORDER-REPORT.
           CLOSE CUST-ORDER-FILE
                  CUST-PRINT-FILE.
           DISPLAY "Report test 2 completed" UPON CONSOLE.
           STOP RUN.
       A001-LOOP.
           MULTIPLY NUM-ORD BY PRICE GIVING AMT-ORDER.
           MULTIPLY AMT-ORDER BY SALES-TAX GIVING AMT-TAX.
           ADD AMT-ORDER SHIPPING AMT-TAX GIVING TOT-ORDER.
           GENERATE DETAIL-LINE.
           READ CUST-ORDER-FILE
                AT END
                    MOVE 'NO' TO ARE-THERE-MORE-RECORDS.
