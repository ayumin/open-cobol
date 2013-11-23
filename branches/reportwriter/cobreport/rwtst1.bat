       IDENTIFICATION DIVISION.
       PROGRAM-ID. RWTST1.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
               SELECT INPUT-FILE ASSIGN TO EXTERNAL STUDENT
                              ORGANIZATION IS LINE SEQUENTIAL. 
               SELECT PRINT-FILE ASSIGN TO EXTERNAL 
                              LINE ADVANCING REPORT1.

       DATA DIVISION.
       FILE SECTION.
       FD   INPUT-FILE
            RECORD CONTAINS 30 CHARACTERS.
       01   INPUT-REC.
               05  STUDENT-ID               PIC  9(5).
               05  STUDENT-NAME             PIC  X(20).
               05  MAJOR                    PIC  XXX.
               05  NUM-COURSES              PIC  99.

       FD   PRINT-FILE
             REPORT IS STUDENT-REPORT STUDENT-REPORT2.

       WORKING-STORAGE SECTION.
       01   ARE-THERE-MORE-RECORDS       PIC  XXX   VALUE  "YES".          
       01   REPORT-DUMMY.
            05  FILLER        PIC X(3) VALUE SPACES.
            05  COLUMN-4      PIC 9(6).
            05  FILLER        PIC X(5) VALUE SPACES.
            05  COLUMN-15     PIC X(20).
            05  FILLER        PIC X(5) VALUE SPACES.
            05  COLUMN-40     PIC XXX.
            05  FILLER        PIC X(4) VALUE SPACES.
            05  COLUMN-46     PIC Z99.9.

       REPORT SECTION.
       RD   STUDENT-REPORT
           PAGE LIMIT 50 LINES
           HEADING 2
           FIRST DETAIL 5
           LAST DETAIL 45
           FOOTING 48.
       01   REPORT-LINE
            TYPE DETAIL
             LINE PLUS  1.
            05  COLUMN 1 PIC 9(2) 
                  SOURCE LINE-COUNTER OF STUDENT-REPORT.
            05  COLUMN 4      PIC 9(6)     SOURCE    STUDENT-ID.
            05  COLUMN 15     PIC X(20)    SOURCE    STUDENT-NAME.
            05  COLUMN 40     PIC XXX      SOURCE    MAJOR.
            05  COLUMN 45     PIC XXX      VALUE "-*-".
            05  COLUMN 52     PIC 99       SOURCE    NUM-COURSES.

       RD  STUDENT-REPORT2
           PAGE LIMIT 60 LINES
           HEADING 2
           FIRST DETAIL 5
           LAST DETAIL 55
           FOOTING 58.
       01   REPORT-LINE2
            TYPE DETAIL
             LINE PLUS  1.
            05  COLUMN 4      PIC 9(6)     SOURCE    STUDENT-ID.
            05  COLUMN 15     PIC X(20)    SOURCE    STUDENT-NAME.
            05  COLUMN 40     PIC XXX      SOURCE    MAJOR.
            05  COLUMN 45     PIC 99       SOURCE    NUM-COURSES.
       01   REPORT-LINE3
            TYPE DETAIL
             LINE PLUS  2.
            05  COLUMN 4      PIC 9(6)     SOURCE    STUDENT-ID.
            05  COLUMN 15     PIC X(20)    SOURCE    STUDENT-NAME.
            05  COLUMN 40     PIC XXX      SOURCE    MAJOR.

       PROCEDURE DIVISION.
       A000-MAINLINE.
           DISPLAY "Report Test 1 " UPON CONSOLE.
           OPEN  INPUT  INPUT-FILE
                 OUTPUT PRINT-FILE
           MOVE SPACES TO REPORT-DUMMY.
           MOVE 5 TO COLUMN-4.
           MOVE "Hello" TO COLUMN-15.
           MOVE "Bye" TO COLUMN-40.
           MOVE 75 TO COLUMN-46.
           MOVE REPORT-DUMMY (2:47) TO REPORT-DUMMY.
           DISPLAY REPORT-DUMMY UPON CONSOLE.
           INITIATE STUDENT-REPORT
           READ INPUT-FILE
               AT END
                   MOVE "NO" TO ARE-THERE-MORE-RECORDS.
           PERFORM A001-LOOP
               UNTIL ARE-THERE-MORE-RECORDS = "NO ".
           TERMINATE STUDENT-REPORT.
           CLOSE INPUT-FILE
                 PRINT-FILE.
           STOP RUN.

       A001-LOOP.
           GENERATE REPORT-LINE.
           READ INPUT-FILE
               AT END
                   MOVE "NO " TO ARE-THERE-MORE-RECORDS.
