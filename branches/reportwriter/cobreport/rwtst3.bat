       IDENTIFICATION DIVISION.
       PROGRAM-ID. RWTST3.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
           SELECT STUDENT-FILE ASSIGN TO EXTERNAL STUDREC
                          ORGANIZATION IS LINE SEQUENTIAL. 
           SELECT PRINT-FILE ASSIGN TO EXTERNAL
                          LINE ADVANCING REPORT3.

       DATA DIVISION.
       FILE SECTION.
       FD    STUDENT-FILE.
       01    STUDENT-REC        PIC X(60).

       FD    PRINT-FILE
           REPORT IS CONTROL-BREAK.
           
       WORKING-STORAGE SECTION.
       01    INDICATORS.
           05  ARE-THERE-MORE-RECORDS PIC XXX VALUE 'YES'.
             88 THERE-ARE-NO-MORE-RECORDS VALUE 'NO'.

       01     CONSTANTS.
           05  NUM        PIC 99 VALUE 1.

       01    STUDENT-AREA.
           05  STUDENT-NAME   PIC X(20).
           05  COURSE-PTS     PIC 99.
           05  MAJOR          PIC XXX.
           05  ADVISOR        PIC X(20).
           05  CAMPUS         PIC X(15).

       REPORT SECTION.
       RD    CONTROL-BREAK
           CONTROLS ARE MAJOR ADVISOR
           PAGE LIMIT 50 LINES
           HEADING 1
           FIRST DETAIL 5
           FOOTING 48.
       01  TYPE IS PAGE HEADING.
           05  LINE 1.
                10  COLUMN 61    PIC X(4) VALUE 'PAGE'.
                10  COLUMN 66    PIC ZZZ9 SOURCE PAGE-COUNTER.
           05  LINE PLUS 2.
                10  COLUMN 26     PIC X(23)
                       VALUE 'STUDENT ADVISEMENT LIST'.

       01  TYPE IS CONTROL HEADING MAJOR.
           05     LINE 5.
                10  COLUMN 37    PIC X(5)  VALUE 'MAJOR'.
                10  COLUMN 44    PIC X(20) SOURCE MAJOR.

           05     LINE 7.
                10  COLUMN  4    PIC X(12) VALUE 'STUDENT NAME'.
                10  COLUMN 25    PIC XXX   VALUE 'PTS'.
                10  COLUMN 34    PIC X(6)  VALUE 'CAMPUS'.
                10  COLUMN 60    PIC X(8)  VALUE 'ADVISOR'.

       01    TRANS-LINE TYPE IS DETAIL.
           05     LINE NUMBER PLUS 1.
                10  COLUMN  3    PIC X(20) SOURCE STUDENT-NAME.
                10  COLUMN 26    PIC 99    SOURCE COURSE-PTS.
                10  COLUMN 34    PIC X(15) SOURCE CAMPUS.
                10  COLUMN 60    PIC X(20) SOURCE ADVISOR 
		                           GROUP INDICATE.

       01    TYPE IS CONTROL FOOTING ADVISOR.
           05     LINE PLUS 2.
                10  COLUMN 5     PIC X(8)  VALUE 'ADVISOR'.
                10  COLUMN 13    PIC X(20) SOURCE ADVISOR.
                10  COLUMN 34    PIC X(6)  VALUE 'TOTAL'.
                10  ADV-TOTAL
                    COLUMN 40    PIC ZZ9   SUM NUM.
           05     LINE PLUS 1.
                10  COLUMN 1     PIC X(8)  VALUE ' '.
       
       01    TYPE IS CONTROL FOOTING MAJOR.
           05     LINE PLUS 2.
                10  COLUMN 5    PIC X(11)  VALUE 'MAJOR TOTAL'.
                10  MAJ-TOTAL
                    COLUMN 22    PIC ZZ9   SUM ADV-TOTAL.

       01    TYPE IS CONTROL FOOTING FINAL.
           05  LINE PLUS 3.
                10  COLUMN 10    PIC X(11) VALUE 'FINAL TOTAL'.
                10  STU-TOTAL
                    COLUMN 21    PIC ZZZ9 SUM MAJ-TOTAL.

       PROCEDURE DIVISION.
       A000-CREATE-REPORTS.
           OPEN INPUT STUDENT-FILE
                OUTPUT PRINT-FILE.
           INITIATE CONTROL-BREAK.
           READ STUDENT-FILE INTO STUDENT-AREA
                AT END
                    MOVE 'NO ' TO ARE-THERE-MORE-RECORDS.
           PERFORM A001-LOOP
                UNTIL THERE-ARE-NO-MORE-RECORDS.
           TERMINATE CONTROL-BREAK.
           CLOSE STUDENT-FILE
                   PRINT-FILE.
           STOP RUN.

       A001-LOOP.
           GENERATE TRANS-LINE.
           READ STUDENT-FILE INTO STUDENT-AREA
                AT END
                    MOVE 'NO ' TO ARE-THERE-MORE-RECORDS.
