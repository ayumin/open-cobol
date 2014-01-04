/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_EOF = 0,
     ACCEPT = 258,
     ACCESS = 259,
     ADD = 260,
     ADDRESS = 261,
     ADVANCING = 262,
     AFTER = 263,
     ALL = 264,
     ALLOCATE = 265,
     ALPHABET = 266,
     ALPHABETIC = 267,
     ALPHABETIC_LOWER = 268,
     ALPHABETIC_UPPER = 269,
     ALPHANUMERIC = 270,
     ALPHANUMERIC_EDITED = 271,
     ALSO = 272,
     ALTER = 273,
     ALTERNATE = 274,
     AND = 275,
     ANY = 276,
     ARE = 277,
     AREA = 278,
     ARGUMENT_NUMBER = 279,
     ARGUMENT_VALUE = 280,
     AS = 281,
     ASCENDING = 282,
     ASCII = 283,
     ASSIGN = 284,
     AT = 285,
     ATTRIBUTE = 286,
     AUTO = 287,
     AUTOMATIC = 288,
     AWAY_FROM_ZERO = 289,
     BACKGROUND_COLOR = 290,
     BASED = 291,
     BEFORE = 292,
     BELL = 293,
     BINARY = 294,
     BINARY_C_LONG = 295,
     BINARY_CHAR = 296,
     BINARY_DOUBLE = 297,
     BINARY_LONG = 298,
     BINARY_SHORT = 299,
     BLANK = 300,
     BLINK = 301,
     BLOCK = 302,
     BOTTOM = 303,
     BY = 304,
     BYTE_LENGTH = 305,
     CALL = 306,
     CANCEL = 307,
     CF = 308,
     CH = 309,
     CHAINING = 310,
     CHARACTER = 311,
     CHARACTERS = 312,
     CLASS = 313,
     CLASSIFICATION = 314,
     CLOSE = 315,
     CODE = 316,
     CODE_SET = 317,
     COLLATING = 318,
     COL = 319,
     COLS = 320,
     COLUMN = 321,
     COLUMNS = 322,
     COMMA = 323,
     COMMAND_LINE = 324,
     COMMA_DELIM = 325,
     COMMIT = 326,
     COMMON = 327,
     COMP = 328,
     COMPUTE = 329,
     COMP_1 = 330,
     COMP_2 = 331,
     COMP_3 = 332,
     COMP_4 = 333,
     COMP_5 = 334,
     COMP_6 = 335,
     COMP_X = 336,
     CONCATENATE_FUNC = 337,
     CONDITION = 338,
     CONFIGURATION = 339,
     CONSTANT = 340,
     CONTAINS = 341,
     CONTENT = 342,
     CONTINUE = 343,
     CONTROL = 344,
     CONTROLS = 345,
     CONVERSION = 346,
     CONVERTING = 347,
     COPY = 348,
     CORRESPONDING = 349,
     COUNT = 350,
     CRT = 351,
     CRT_UNDER = 352,
     CURRENCY = 353,
     CURRENT_DATE_FUNC = 354,
     CURSOR = 355,
     CYCLE = 356,
     DATA = 357,
     DATE = 358,
     DAY = 359,
     DAY_OF_WEEK = 360,
     DE = 361,
     DEBUGGING = 362,
     DECIMAL_POINT = 363,
     DECLARATIVES = 364,
     DEFAULT = 365,
     DELETE = 366,
     DELIMITED = 367,
     DELIMITER = 368,
     DEPENDING = 369,
     DESCENDING = 370,
     DETAIL = 371,
     DISC = 372,
     DISK = 373,
     DISPLAY = 374,
     DISPLAY_OF_FUNC = 375,
     DIVIDE = 376,
     DIVISION = 377,
     DOWN = 378,
     DUPLICATES = 379,
     DYNAMIC = 380,
     EBCDIC = 381,
     EC = 382,
     ELSE = 383,
     END = 384,
     END_ACCEPT = 385,
     END_ADD = 386,
     END_CALL = 387,
     END_COMPUTE = 388,
     END_DELETE = 389,
     END_DISPLAY = 390,
     END_DIVIDE = 391,
     END_EVALUATE = 392,
     END_FUNCTION = 393,
     END_IF = 394,
     END_MULTIPLY = 395,
     END_PERFORM = 396,
     END_PROGRAM = 397,
     END_READ = 398,
     END_RETURN = 399,
     END_REWRITE = 400,
     END_SEARCH = 401,
     END_START = 402,
     END_STRING = 403,
     END_SUBTRACT = 404,
     END_UNSTRING = 405,
     END_WRITE = 406,
     ENTRY = 407,
     ENVIRONMENT = 408,
     ENVIRONMENT_NAME = 409,
     ENVIRONMENT_VALUE = 410,
     EOL = 411,
     EOP = 412,
     EOS = 413,
     EQUAL = 414,
     ERASE = 415,
     ERROR = 416,
     ESCAPE = 417,
     EVALUATE = 418,
     EVENT_STATUS = 419,
     EXCEPTION = 420,
     EXCEPTION_CONDITION = 421,
     EXCLUSIVE = 422,
     EXIT = 423,
     EXPONENTIATION = 424,
     EXTEND = 425,
     EXTERNAL = 426,
     FD = 427,
     FILE_CONTROL = 428,
     FILE_ID = 429,
     FILLER = 430,
     FINAL = 431,
     FIRST = 432,
     FLOAT_BINARY_128 = 433,
     FLOAT_BINARY_32 = 434,
     FLOAT_BINARY_64 = 435,
     FLOAT_DECIMAL_16 = 436,
     FLOAT_DECIMAL_34 = 437,
     FLOAT_DECIMAL_7 = 438,
     FLOAT_EXTENDED = 439,
     FLOAT_LONG = 440,
     FLOAT_SHORT = 441,
     FOOTING = 442,
     FOR = 443,
     FOREGROUND_COLOR = 444,
     FOREVER = 445,
     FORMATTED_CURRENT_FUNC = 446,
     FORMATTED_DATE_FUNC = 447,
     FORMATTED_DATETIME_FUNC = 448,
     FORMATTED_TIME_FUNC = 449,
     FREE = 450,
     FROM = 451,
     FROM_CRT = 452,
     FULL = 453,
     FUNCTION = 454,
     FUNCTION_ID = 455,
     FUNCTION_NAME = 456,
     GENERATE = 457,
     GIVING = 458,
     GLOBAL = 459,
     GO = 460,
     GOBACK = 461,
     GREATER = 462,
     GREATER_OR_EQUAL = 463,
     GROUP = 464,
     HEADING = 465,
     HIGHLIGHT = 466,
     HIGH_VALUE = 467,
     ID = 468,
     IDENTIFICATION = 469,
     IF = 470,
     IGNORE = 471,
     IGNORING = 472,
     IN = 473,
     INDEX = 474,
     INDEXED = 475,
     INDICATE = 476,
     INITIALIZE = 477,
     INITIALIZED = 478,
     INITIATE = 479,
     INPUT = 480,
     INPUT_OUTPUT = 481,
     INSPECT = 482,
     INTO = 483,
     INTRINSIC = 484,
     INVALID = 485,
     INVALID_KEY = 486,
     IS = 487,
     I_O = 488,
     I_O_CONTROL = 489,
     JUSTIFIED = 490,
     KEPT = 491,
     KEY = 492,
     KEYBOARD = 493,
     LABEL = 494,
     LAST = 495,
     LEADING = 496,
     LEFT = 497,
     LEFTLINE = 498,
     LENGTH = 499,
     LENGTH_OF = 500,
     LESS = 501,
     LESS_OR_EQUAL = 502,
     LIMIT = 503,
     LIMITS = 504,
     LINAGE = 505,
     LINAGE_COUNTER = 506,
     LINE = 507,
     LINE_COUNTER = 508,
     LINES = 509,
     LINKAGE = 510,
     LITERAL = 511,
     LOCALE = 512,
     LOCALE_DATE_FUNC = 513,
     LOCALE_TIME_FUNC = 514,
     LOCALE_TIME_FROM_FUNC = 515,
     LOCAL_STORAGE = 516,
     LOCK = 517,
     LOWER = 518,
     LOWER_CASE_FUNC = 519,
     LOWLIGHT = 520,
     LOW_VALUE = 521,
     MANUAL = 522,
     MEMORY = 523,
     MERGE = 524,
     MINUS = 525,
     MNEMONIC_NAME = 526,
     MODE = 527,
     MOVE = 528,
     MULTIPLE = 529,
     MULTIPLY = 530,
     NAME = 531,
     NATIONAL = 532,
     NATIONAL_EDITED = 533,
     NATIONAL_OF_FUNC = 534,
     NATIVE = 535,
     NEAREST_AWAY_FROM_ZERO = 536,
     NEAREST_EVEN = 537,
     NEAREST_TOWARD_ZERO = 538,
     NEGATIVE = 539,
     NEXT = 540,
     NEXT_PAGE = 541,
     NO = 542,
     NO_ECHO = 543,
     NORMAL = 544,
     NOT = 545,
     NOT_END = 546,
     NOT_EOP = 547,
     NOT_EQUAL = 548,
     NOT_EXCEPTION = 549,
     NOT_INVALID_KEY = 550,
     NOT_OVERFLOW = 551,
     NOT_SIZE_ERROR = 552,
     NO_ADVANCING = 553,
     NUMBER = 554,
     NUMBERS = 555,
     NUMERIC = 556,
     NUMERIC_EDITED = 557,
     NUMVALC_FUNC = 558,
     OBJECT_COMPUTER = 559,
     OCCURS = 560,
     OF = 561,
     OFF = 562,
     OMITTED = 563,
     ON = 564,
     ONLY = 565,
     OPEN = 566,
     OPTIONAL = 567,
     OR = 568,
     ORDER = 569,
     ORGANIZATION = 570,
     OTHER = 571,
     OUTPUT = 572,
     OVERLINE = 573,
     PACKED_DECIMAL = 574,
     PADDING = 575,
     PAGE = 576,
     PAGE_COUNTER = 577,
     PARAGRAPH = 578,
     PERFORM = 579,
     PH = 580,
     PF = 581,
     PICTURE = 582,
     PICTURE_SYMBOL = 583,
     PLUS = 584,
     POINTER = 585,
     POSITION = 586,
     POSITIVE = 587,
     PRESENT = 588,
     PREVIOUS = 589,
     PRINTER = 590,
     PRINTING = 591,
     PROCEDURE = 592,
     PROCEDURES = 593,
     PROCEED = 594,
     PROGRAM = 595,
     PROGRAM_ID = 596,
     PROGRAM_NAME = 597,
     PROGRAM_POINTER = 598,
     PROHIBITED = 599,
     PROMPT = 600,
     QUOTE = 601,
     RANDOM = 602,
     RD = 603,
     READ = 604,
     READY_TRACE = 605,
     RECORD = 606,
     RECORDING = 607,
     RECORDS = 608,
     RECURSIVE = 609,
     REDEFINES = 610,
     REEL = 611,
     REFERENCE = 612,
     REFERENCES = 613,
     RELATIVE = 614,
     RELEASE = 615,
     REMAINDER = 616,
     REMOVAL = 617,
     RENAMES = 618,
     REPLACE = 619,
     REPLACING = 620,
     REPORT = 621,
     REPORTING = 622,
     REPORTS = 623,
     REPOSITORY = 624,
     REPO_FUNCTION = 625,
     REQUIRED = 626,
     RESERVE = 627,
     RESET = 628,
     RESET_TRACE = 629,
     RETURN = 630,
     RETURNING = 631,
     REVERSE_FUNC = 632,
     REVERSE_VIDEO = 633,
     REVERSED = 634,
     REWIND = 635,
     REWRITE = 636,
     RF = 637,
     RH = 638,
     RIGHT = 639,
     ROLLBACK = 640,
     ROUNDED = 641,
     RUN = 642,
     SAME = 643,
     SCREEN = 644,
     SCREEN_CONTROL = 645,
     SCROLL = 646,
     SD = 647,
     SEARCH = 648,
     SECTION = 649,
     SECURE = 650,
     SEGMENT_LIMIT = 651,
     SELECT = 652,
     SEMI_COLON = 653,
     SENTENCE = 654,
     SEPARATE = 655,
     SEQUENCE = 656,
     SEQUENTIAL = 657,
     SET = 658,
     SHARING = 659,
     SIGN = 660,
     SIGNED = 661,
     SIGNED_INT = 662,
     SIGNED_LONG = 663,
     SIGNED_SHORT = 664,
     SIZE = 665,
     SIZE_ERROR = 666,
     SORT = 667,
     SORT_MERGE = 668,
     SOURCE = 669,
     SOURCE_COMPUTER = 670,
     SPACE = 671,
     SPECIAL_NAMES = 672,
     STANDARD = 673,
     STANDARD_1 = 674,
     STANDARD_2 = 675,
     START = 676,
     STATIC = 677,
     STATUS = 678,
     STDCALL = 679,
     STEP = 680,
     STOP = 681,
     STRING = 682,
     SUBSTITUTE_FUNC = 683,
     SUBSTITUTE_CASE_FUNC = 684,
     SUBTRACT = 685,
     SUM = 686,
     SUPPRESS = 687,
     SYMBOLIC = 688,
     SYNCHRONIZED = 689,
     SYSTEM_DEFAULT = 690,
     TALLYING = 691,
     TAPE = 692,
     TERMINATE = 693,
     TEST = 694,
     THAN = 695,
     THEN = 696,
     THRU = 697,
     TIME = 698,
     TIMEOUT = 699,
     TIMES = 700,
     TO = 701,
     TOK_AMPER = 702,
     TOK_CLOSE_PAREN = 703,
     TOK_COLON = 704,
     TOK_DIV = 705,
     TOK_DOT = 706,
     TOK_EQUAL = 707,
     TOK_FALSE = 708,
     TOK_FILE = 709,
     TOK_GREATER = 710,
     TOK_INITIAL = 711,
     TOK_LESS = 712,
     TOK_MINUS = 713,
     TOK_MUL = 714,
     TOK_NULL = 715,
     TOK_OVERFLOW = 716,
     TOK_OPEN_PAREN = 717,
     TOK_PLUS = 718,
     TOK_TRUE = 719,
     TOP = 720,
     TOWARD_GREATER = 721,
     TOWARD_LESSER = 722,
     TRAILING = 723,
     TRANSFORM = 724,
     TRIM_FUNC = 725,
     TRUNCATION = 726,
     TYPE = 727,
     UNDERLINE = 728,
     UNIT = 729,
     UNLOCK = 730,
     UNSIGNED = 731,
     UNSIGNED_INT = 732,
     UNSIGNED_LONG = 733,
     UNSIGNED_SHORT = 734,
     UNSTRING = 735,
     UNTIL = 736,
     UP = 737,
     UPDATE = 738,
     UPON = 739,
     UPON_ARGUMENT_NUMBER = 740,
     UPON_COMMAND_LINE = 741,
     UPON_ENVIRONMENT_NAME = 742,
     UPON_ENVIRONMENT_VALUE = 743,
     UPPER = 744,
     UPPER_CASE_FUNC = 745,
     USAGE = 746,
     USE = 747,
     USER = 748,
     USER_DEFAULT = 749,
     USER_FUNCTION_NAME = 750,
     USER_REPO_FUNCTION = 751,
     USING = 752,
     VALUE = 753,
     VARYING = 754,
     WAIT = 755,
     WHEN = 756,
     WHEN_COMPILED_FUNC = 757,
     WITH = 758,
     WORD = 759,
     WORDS = 760,
     WORKING_STORAGE = 761,
     WRITE = 762,
     YYYYDDD = 763,
     YYYYMMDD = 764,
     ZERO = 765,
     SHIFT_PREFER = 766
   };
#endif
/* Tokens.  */
#define TOKEN_EOF 0
#define ACCEPT 258
#define ACCESS 259
#define ADD 260
#define ADDRESS 261
#define ADVANCING 262
#define AFTER 263
#define ALL 264
#define ALLOCATE 265
#define ALPHABET 266
#define ALPHABETIC 267
#define ALPHABETIC_LOWER 268
#define ALPHABETIC_UPPER 269
#define ALPHANUMERIC 270
#define ALPHANUMERIC_EDITED 271
#define ALSO 272
#define ALTER 273
#define ALTERNATE 274
#define AND 275
#define ANY 276
#define ARE 277
#define AREA 278
#define ARGUMENT_NUMBER 279
#define ARGUMENT_VALUE 280
#define AS 281
#define ASCENDING 282
#define ASCII 283
#define ASSIGN 284
#define AT 285
#define ATTRIBUTE 286
#define AUTO 287
#define AUTOMATIC 288
#define AWAY_FROM_ZERO 289
#define BACKGROUND_COLOR 290
#define BASED 291
#define BEFORE 292
#define BELL 293
#define BINARY 294
#define BINARY_C_LONG 295
#define BINARY_CHAR 296
#define BINARY_DOUBLE 297
#define BINARY_LONG 298
#define BINARY_SHORT 299
#define BLANK 300
#define BLINK 301
#define BLOCK 302
#define BOTTOM 303
#define BY 304
#define BYTE_LENGTH 305
#define CALL 306
#define CANCEL 307
#define CF 308
#define CH 309
#define CHAINING 310
#define CHARACTER 311
#define CHARACTERS 312
#define CLASS 313
#define CLASSIFICATION 314
#define CLOSE 315
#define CODE 316
#define CODE_SET 317
#define COLLATING 318
#define COL 319
#define COLS 320
#define COLUMN 321
#define COLUMNS 322
#define COMMA 323
#define COMMAND_LINE 324
#define COMMA_DELIM 325
#define COMMIT 326
#define COMMON 327
#define COMP 328
#define COMPUTE 329
#define COMP_1 330
#define COMP_2 331
#define COMP_3 332
#define COMP_4 333
#define COMP_5 334
#define COMP_6 335
#define COMP_X 336
#define CONCATENATE_FUNC 337
#define CONDITION 338
#define CONFIGURATION 339
#define CONSTANT 340
#define CONTAINS 341
#define CONTENT 342
#define CONTINUE 343
#define CONTROL 344
#define CONTROLS 345
#define CONVERSION 346
#define CONVERTING 347
#define COPY 348
#define CORRESPONDING 349
#define COUNT 350
#define CRT 351
#define CRT_UNDER 352
#define CURRENCY 353
#define CURRENT_DATE_FUNC 354
#define CURSOR 355
#define CYCLE 356
#define DATA 357
#define DATE 358
#define DAY 359
#define DAY_OF_WEEK 360
#define DE 361
#define DEBUGGING 362
#define DECIMAL_POINT 363
#define DECLARATIVES 364
#define DEFAULT 365
#define DELETE 366
#define DELIMITED 367
#define DELIMITER 368
#define DEPENDING 369
#define DESCENDING 370
#define DETAIL 371
#define DISC 372
#define DISK 373
#define DISPLAY 374
#define DISPLAY_OF_FUNC 375
#define DIVIDE 376
#define DIVISION 377
#define DOWN 378
#define DUPLICATES 379
#define DYNAMIC 380
#define EBCDIC 381
#define EC 382
#define ELSE 383
#define END 384
#define END_ACCEPT 385
#define END_ADD 386
#define END_CALL 387
#define END_COMPUTE 388
#define END_DELETE 389
#define END_DISPLAY 390
#define END_DIVIDE 391
#define END_EVALUATE 392
#define END_FUNCTION 393
#define END_IF 394
#define END_MULTIPLY 395
#define END_PERFORM 396
#define END_PROGRAM 397
#define END_READ 398
#define END_RETURN 399
#define END_REWRITE 400
#define END_SEARCH 401
#define END_START 402
#define END_STRING 403
#define END_SUBTRACT 404
#define END_UNSTRING 405
#define END_WRITE 406
#define ENTRY 407
#define ENVIRONMENT 408
#define ENVIRONMENT_NAME 409
#define ENVIRONMENT_VALUE 410
#define EOL 411
#define EOP 412
#define EOS 413
#define EQUAL 414
#define ERASE 415
#define ERROR 416
#define ESCAPE 417
#define EVALUATE 418
#define EVENT_STATUS 419
#define EXCEPTION 420
#define EXCEPTION_CONDITION 421
#define EXCLUSIVE 422
#define EXIT 423
#define EXPONENTIATION 424
#define EXTEND 425
#define EXTERNAL 426
#define FD 427
#define FILE_CONTROL 428
#define FILE_ID 429
#define FILLER 430
#define FINAL 431
#define FIRST 432
#define FLOAT_BINARY_128 433
#define FLOAT_BINARY_32 434
#define FLOAT_BINARY_64 435
#define FLOAT_DECIMAL_16 436
#define FLOAT_DECIMAL_34 437
#define FLOAT_DECIMAL_7 438
#define FLOAT_EXTENDED 439
#define FLOAT_LONG 440
#define FLOAT_SHORT 441
#define FOOTING 442
#define FOR 443
#define FOREGROUND_COLOR 444
#define FOREVER 445
#define FORMATTED_CURRENT_FUNC 446
#define FORMATTED_DATE_FUNC 447
#define FORMATTED_DATETIME_FUNC 448
#define FORMATTED_TIME_FUNC 449
#define FREE 450
#define FROM 451
#define FROM_CRT 452
#define FULL 453
#define FUNCTION 454
#define FUNCTION_ID 455
#define FUNCTION_NAME 456
#define GENERATE 457
#define GIVING 458
#define GLOBAL 459
#define GO 460
#define GOBACK 461
#define GREATER 462
#define GREATER_OR_EQUAL 463
#define GROUP 464
#define HEADING 465
#define HIGHLIGHT 466
#define HIGH_VALUE 467
#define ID 468
#define IDENTIFICATION 469
#define IF 470
#define IGNORE 471
#define IGNORING 472
#define IN 473
#define INDEX 474
#define INDEXED 475
#define INDICATE 476
#define INITIALIZE 477
#define INITIALIZED 478
#define INITIATE 479
#define INPUT 480
#define INPUT_OUTPUT 481
#define INSPECT 482
#define INTO 483
#define INTRINSIC 484
#define INVALID 485
#define INVALID_KEY 486
#define IS 487
#define I_O 488
#define I_O_CONTROL 489
#define JUSTIFIED 490
#define KEPT 491
#define KEY 492
#define KEYBOARD 493
#define LABEL 494
#define LAST 495
#define LEADING 496
#define LEFT 497
#define LEFTLINE 498
#define LENGTH 499
#define LENGTH_OF 500
#define LESS 501
#define LESS_OR_EQUAL 502
#define LIMIT 503
#define LIMITS 504
#define LINAGE 505
#define LINAGE_COUNTER 506
#define LINE 507
#define LINE_COUNTER 508
#define LINES 509
#define LINKAGE 510
#define LITERAL 511
#define LOCALE 512
#define LOCALE_DATE_FUNC 513
#define LOCALE_TIME_FUNC 514
#define LOCALE_TIME_FROM_FUNC 515
#define LOCAL_STORAGE 516
#define LOCK 517
#define LOWER 518
#define LOWER_CASE_FUNC 519
#define LOWLIGHT 520
#define LOW_VALUE 521
#define MANUAL 522
#define MEMORY 523
#define MERGE 524
#define MINUS 525
#define MNEMONIC_NAME 526
#define MODE 527
#define MOVE 528
#define MULTIPLE 529
#define MULTIPLY 530
#define NAME 531
#define NATIONAL 532
#define NATIONAL_EDITED 533
#define NATIONAL_OF_FUNC 534
#define NATIVE 535
#define NEAREST_AWAY_FROM_ZERO 536
#define NEAREST_EVEN 537
#define NEAREST_TOWARD_ZERO 538
#define NEGATIVE 539
#define NEXT 540
#define NEXT_PAGE 541
#define NO 542
#define NO_ECHO 543
#define NORMAL 544
#define NOT 545
#define NOT_END 546
#define NOT_EOP 547
#define NOT_EQUAL 548
#define NOT_EXCEPTION 549
#define NOT_INVALID_KEY 550
#define NOT_OVERFLOW 551
#define NOT_SIZE_ERROR 552
#define NO_ADVANCING 553
#define NUMBER 554
#define NUMBERS 555
#define NUMERIC 556
#define NUMERIC_EDITED 557
#define NUMVALC_FUNC 558
#define OBJECT_COMPUTER 559
#define OCCURS 560
#define OF 561
#define OFF 562
#define OMITTED 563
#define ON 564
#define ONLY 565
#define OPEN 566
#define OPTIONAL 567
#define OR 568
#define ORDER 569
#define ORGANIZATION 570
#define OTHER 571
#define OUTPUT 572
#define OVERLINE 573
#define PACKED_DECIMAL 574
#define PADDING 575
#define PAGE 576
#define PAGE_COUNTER 577
#define PARAGRAPH 578
#define PERFORM 579
#define PH 580
#define PF 581
#define PICTURE 582
#define PICTURE_SYMBOL 583
#define PLUS 584
#define POINTER 585
#define POSITION 586
#define POSITIVE 587
#define PRESENT 588
#define PREVIOUS 589
#define PRINTER 590
#define PRINTING 591
#define PROCEDURE 592
#define PROCEDURES 593
#define PROCEED 594
#define PROGRAM 595
#define PROGRAM_ID 596
#define PROGRAM_NAME 597
#define PROGRAM_POINTER 598
#define PROHIBITED 599
#define PROMPT 600
#define QUOTE 601
#define RANDOM 602
#define RD 603
#define READ 604
#define READY_TRACE 605
#define RECORD 606
#define RECORDING 607
#define RECORDS 608
#define RECURSIVE 609
#define REDEFINES 610
#define REEL 611
#define REFERENCE 612
#define REFERENCES 613
#define RELATIVE 614
#define RELEASE 615
#define REMAINDER 616
#define REMOVAL 617
#define RENAMES 618
#define REPLACE 619
#define REPLACING 620
#define REPORT 621
#define REPORTING 622
#define REPORTS 623
#define REPOSITORY 624
#define REPO_FUNCTION 625
#define REQUIRED 626
#define RESERVE 627
#define RESET 628
#define RESET_TRACE 629
#define RETURN 630
#define RETURNING 631
#define REVERSE_FUNC 632
#define REVERSE_VIDEO 633
#define REVERSED 634
#define REWIND 635
#define REWRITE 636
#define RF 637
#define RH 638
#define RIGHT 639
#define ROLLBACK 640
#define ROUNDED 641
#define RUN 642
#define SAME 643
#define SCREEN 644
#define SCREEN_CONTROL 645
#define SCROLL 646
#define SD 647
#define SEARCH 648
#define SECTION 649
#define SECURE 650
#define SEGMENT_LIMIT 651
#define SELECT 652
#define SEMI_COLON 653
#define SENTENCE 654
#define SEPARATE 655
#define SEQUENCE 656
#define SEQUENTIAL 657
#define SET 658
#define SHARING 659
#define SIGN 660
#define SIGNED 661
#define SIGNED_INT 662
#define SIGNED_LONG 663
#define SIGNED_SHORT 664
#define SIZE 665
#define SIZE_ERROR 666
#define SORT 667
#define SORT_MERGE 668
#define SOURCE 669
#define SOURCE_COMPUTER 670
#define SPACE 671
#define SPECIAL_NAMES 672
#define STANDARD 673
#define STANDARD_1 674
#define STANDARD_2 675
#define START 676
#define STATIC 677
#define STATUS 678
#define STDCALL 679
#define STEP 680
#define STOP 681
#define STRING 682
#define SUBSTITUTE_FUNC 683
#define SUBSTITUTE_CASE_FUNC 684
#define SUBTRACT 685
#define SUM 686
#define SUPPRESS 687
#define SYMBOLIC 688
#define SYNCHRONIZED 689
#define SYSTEM_DEFAULT 690
#define TALLYING 691
#define TAPE 692
#define TERMINATE 693
#define TEST 694
#define THAN 695
#define THEN 696
#define THRU 697
#define TIME 698
#define TIMEOUT 699
#define TIMES 700
#define TO 701
#define TOK_AMPER 702
#define TOK_CLOSE_PAREN 703
#define TOK_COLON 704
#define TOK_DIV 705
#define TOK_DOT 706
#define TOK_EQUAL 707
#define TOK_FALSE 708
#define TOK_FILE 709
#define TOK_GREATER 710
#define TOK_INITIAL 711
#define TOK_LESS 712
#define TOK_MINUS 713
#define TOK_MUL 714
#define TOK_NULL 715
#define TOK_OVERFLOW 716
#define TOK_OPEN_PAREN 717
#define TOK_PLUS 718
#define TOK_TRUE 719
#define TOP 720
#define TOWARD_GREATER 721
#define TOWARD_LESSER 722
#define TRAILING 723
#define TRANSFORM 724
#define TRIM_FUNC 725
#define TRUNCATION 726
#define TYPE 727
#define UNDERLINE 728
#define UNIT 729
#define UNLOCK 730
#define UNSIGNED 731
#define UNSIGNED_INT 732
#define UNSIGNED_LONG 733
#define UNSIGNED_SHORT 734
#define UNSTRING 735
#define UNTIL 736
#define UP 737
#define UPDATE 738
#define UPON 739
#define UPON_ARGUMENT_NUMBER 740
#define UPON_COMMAND_LINE 741
#define UPON_ENVIRONMENT_NAME 742
#define UPON_ENVIRONMENT_VALUE 743
#define UPPER 744
#define UPPER_CASE_FUNC 745
#define USAGE 746
#define USE 747
#define USER 748
#define USER_DEFAULT 749
#define USER_FUNCTION_NAME 750
#define USER_REPO_FUNCTION 751
#define USING 752
#define VALUE 753
#define VARYING 754
#define WAIT 755
#define WHEN 756
#define WHEN_COMPILED_FUNC 757
#define WITH 758
#define WORD 759
#define WORDS 760
#define WORKING_STORAGE 761
#define WRITE 762
#define YYYYDDD 763
#define YYYYMMDD 764
#define ZERO 765
#define SHIFT_PREFER 766




/* Copy the first part of user declarations.  */
#line 28 "parser.y"

#include "config.h"

#include <stdlib.h>
#include <string.h>

#define	COB_IN_PARSER	1
#include "cobc.h"
#include "tree.h"

#ifndef	_STDLIB_H
#define	_STDLIB_H 1
#endif

#define YYSTYPE			cb_tree
#define yyerror			cb_error

#define PENDING(x)		cb_warning (_("'%s' not implemented"), x)
#define PENDINGDEV(x)		cb_warning (_("'%s' currently in development"), x)

#define emit_statement(x) \
do { \
  if (!skip_statements) { \
	CB_ADD_TO_CHAIN (x, current_program->exec_list); \
  } \
} while (0)

#define push_expr(type, node) \
  current_expr = cb_build_list (cb_int (type), node, current_expr)

/* Statement terminator definitions */
#define TERM_NONE		0
#define TERM_ACCEPT		1U
#define TERM_ADD		2U
#define TERM_CALL		3U
#define TERM_COMPUTE		4U
#define TERM_DELETE		5U
#define TERM_DISPLAY		6U
#define TERM_DIVIDE		7U
#define TERM_EVALUATE		8U
#define TERM_IF			9U
#define TERM_MULTIPLY		10U
#define TERM_PERFORM		11U
#define TERM_READ		12U
#define TERM_RECEIVE		13U
#define TERM_RETURN		14U
#define TERM_REWRITE		15U
#define TERM_SEARCH		16U
#define TERM_START		17U
#define TERM_STRING		18U
#define TERM_SUBTRACT		19U
#define TERM_UNSTRING		20U
#define TERM_WRITE		21U
#define TERM_MAX		22U

#define	TERMINATOR_WARNING(x,z)	terminator_warning (x, TERM_##z, #z)
#define	TERMINATOR_ERROR(x,z)	terminator_error (x, TERM_##z, #z)
#define	TERMINATOR_CLEAR(x,z)	terminator_clear (x, TERM_##z)

/* Defines for duplicate checks */
/* Note - We use <= 16 for common item definitons and */
/* > 16 for non-common item definitions eg. REPORT and SCREEN */
#define	SYN_CLAUSE_1		(1U << 0)
#define	SYN_CLAUSE_2		(1U << 1)
#define	SYN_CLAUSE_3		(1U << 2)
#define	SYN_CLAUSE_4		(1U << 3)
#define	SYN_CLAUSE_5		(1U << 4)
#define	SYN_CLAUSE_6		(1U << 5)
#define	SYN_CLAUSE_7		(1U << 6)
#define	SYN_CLAUSE_8		(1U << 7)
#define	SYN_CLAUSE_9		(1U << 8)
#define	SYN_CLAUSE_10		(1U << 9)
#define	SYN_CLAUSE_11		(1U << 10)
#define	SYN_CLAUSE_12		(1U << 11)
#define	SYN_CLAUSE_13		(1U << 12)
#define	SYN_CLAUSE_14		(1U << 13)
#define	SYN_CLAUSE_15		(1U << 14)
#define	SYN_CLAUSE_16		(1U << 15)
#define	SYN_CLAUSE_17		(1U << 16)
#define	SYN_CLAUSE_18		(1U << 17)
#define	SYN_CLAUSE_19		(1U << 18)
#define	SYN_CLAUSE_20		(1U << 19)
#define	SYN_CLAUSE_21		(1U << 20)
#define	SYN_CLAUSE_22		(1U << 21)
#define	SYN_CLAUSE_23		(1U << 22)
#define	SYN_CLAUSE_24		(1U << 23)
#define	SYN_CLAUSE_25		(1U << 24)
#define	SYN_CLAUSE_26		(1U << 25)
#define	SYN_CLAUSE_27		(1U << 26)
#define	SYN_CLAUSE_28		(1U << 27)
#define	SYN_CLAUSE_29		(1U << 28)
#define	SYN_CLAUSE_30		(1U << 29)
#define	SYN_CLAUSE_31		(1U << 30)
#define	SYN_CLAUSE_32		(1U << 31)

#define	EVAL_DEPTH		32
#define	PROG_DEPTH		16

/* Global variables */

struct cb_program		*current_program = NULL;
struct cb_statement		*current_statement = NULL;
struct cb_label			*current_section = NULL;
struct cb_label			*current_paragraph = NULL;
char				*cobc_glob_line = NULL;

cb_tree				cobc_printer_node = NULL;
int				functions_are_all = 0;
int				non_const_word = 0;
unsigned int			cobc_in_procedure = 0;
unsigned int			cobc_in_repository = 0;
unsigned int			cobc_force_literal = 0;
unsigned int			cobc_cs_check = 0;

/* Local variables */

static struct cb_statement	*main_statement;

static cb_tree			current_expr;
static struct cb_field		*current_field;
static struct cb_field		*control_field;
static struct cb_field		*description_field;
static struct cb_file		*current_file;
static struct cb_report		*current_report;
static struct cb_report		*report_instance;

static struct cb_file		*linage_file;
static cb_tree			next_label_list;

static char			*stack_progid[PROG_DEPTH];

static enum cb_storage		current_storage;

static cb_tree			perform_stack;
static cb_tree			qualifier;

static cb_tree			save_tree;
static cb_tree			start_tree;

static unsigned int		check_unreached;
static unsigned int		in_declaratives;
static unsigned int		in_debugging;
static unsigned int		current_linage;
static unsigned int		report_count;
static unsigned int		prog_end;
static unsigned int		use_global_ind;
static unsigned int		samearea;
static unsigned int		inspect_keyword;
static unsigned int		main_flag_set;
static int			next_label_id;
static int			eval_level;
static int			eval_inc;
static int			eval_inc2;
static int			depth;
static int			call_mode;
static int			size_mode;
static int			setattr_val_on;
static int			setattr_val_off;
static unsigned int		check_duplicate;
static unsigned int		check_pic_duplicate;
static unsigned int		check_comp_duplicate;
static unsigned int		skip_statements;
static unsigned int		start_debug;
static unsigned int		save_debug;
static unsigned int		needs_field_debug;
static unsigned int		needs_debug_item;
static unsigned int		env_div_seen;
static unsigned int		header_check;

static int			term_array[TERM_MAX];
static cb_tree			eval_check[EVAL_DEPTH][EVAL_DEPTH];

/* Defines for header presence */

#define	COBC_HD_ENVIRONMENT_DIVISION	(1U << 0)
#define	COBC_HD_CONFIGURATION_SECTION	(1U << 1)
#define	COBC_HD_SPECIAL_NAMES		(1U << 2)
#define	COBC_HD_INPUT_OUTPUT_SECTION	(1U << 3)
#define	COBC_HD_FILE_CONTROL		(1U << 4)
#define	COBC_HD_I_O_CONTROL		(1U << 5)
#define	COBC_HD_DATA_DIVISION		(1U << 6)
#define	COBC_HD_FILE_SECTION		(1U << 7)
#define	COBC_HD_WORKING_STORAGE_SECTION	(1U << 8)
#define	COBC_HD_LOCAL_STORAGE_SECTION	(1U << 9)
#define	COBC_HD_LINKAGE_SECTION		(1U << 10)
#define	COBC_HD_COMMUNICATIONS_SECTION	(1U << 11)
#define	COBC_HD_REPORT_SECTION		(1U << 12)
#define	COBC_HD_SCREEN_SECTION		(1U << 13)
#define	COBC_HD_PROCEDURE_DIVISION	(1U << 14)
#define	COBC_HD_PROGRAM_ID		(1U << 15)

/* Static functions */

static void
begin_statement (const char *name, const unsigned int term)
{
	if (cb_warn_unreachable && check_unreached) {
		cb_warning (_("Unreachable statement '%s'"), name);
	}
	current_paragraph->flag_statement = 1;
	current_statement = cb_build_statement (name);
	CB_TREE (current_statement)->source_file = cb_source_file;
	CB_TREE (current_statement)->source_line = cb_source_line;
	current_statement->statement = cobc_glob_line;
	current_statement->flag_in_debug = in_debugging;
	emit_statement (CB_TREE (current_statement));
	if (term) {
		term_array[term]++;
	}
	main_statement = current_statement;
}

static void
begin_implicit_statement (void)
{
	current_statement = cb_build_statement (NULL);
	current_statement->flag_in_debug = !!in_debugging;
	main_statement->body = cb_list_add (main_statement->body,
					    CB_TREE (current_statement));
}

static void
emit_entry (const char *name, const int encode, cb_tree using_list)
{
	cb_tree		l;
	cb_tree		label;
	cb_tree		x;
	struct cb_field	*f;
	int		parmnum;
	char		buff[COB_MINI_BUFF];

	snprintf (buff, (size_t)COB_MINI_MAX, "E$%s", name);
	label = cb_build_label (cb_build_reference (buff), NULL);
	if (encode) {
		CB_LABEL (label)->name = cb_encode_program_id (name);
		CB_LABEL (label)->orig_name = name;
	} else {
		CB_LABEL (label)->name = name;
		CB_LABEL (label)->orig_name = current_program->orig_program_id;
	}
	CB_LABEL (label)->flag_begin = 1;
	CB_LABEL (label)->flag_entry = 1;
	label->source_file = cb_source_file;
	label->source_line = cb_source_line;
	emit_statement (label);

	if (current_program->flag_debugging) {
		emit_statement (cb_build_debug (cb_debug_contents,
						"START PROGRAM", NULL));
	}

	parmnum = 1;
	for (l = using_list; l; l = CB_CHAIN (l)) {
		x = CB_VALUE (l);
		if (CB_VALID_TREE (x) && cb_ref (x) != cb_error_node) {
			f = CB_FIELD (cb_ref (x));
			if (f->level != 01 && f->level != 77) {
				cb_error_x (x, _("'%s' not level 01 or 77"), cb_name (x));
			}
			if (!current_program->flag_chained) {
				if (f->storage != CB_STORAGE_LINKAGE) {
					cb_error_x (x, _("'%s' is not in LINKAGE SECTION"), cb_name (x));
				}
				if (f->flag_item_based || f->flag_external) {
					cb_error_x (x, _("'%s' can not be BASED/EXTERNAL"), cb_name (x));
				}
				f->flag_is_pdiv_parm = 1;
			} else {
				if (f->storage != CB_STORAGE_WORKING) {
					cb_error_x (x, _("'%s' is not in WORKING-STORAGE SECTION"), cb_name (x));
				}
				f->flag_chained = 1;
				f->param_num = parmnum;
				parmnum++;
			}
			if (f->redefines) {
				cb_error_x (x, _("'%s' REDEFINES field not allowed here"), cb_name (x));
			}
		}
	}

	/* Check dangling LINKAGE items */
	if (cb_warn_linkage) {
		for (f = current_program->linkage_storage; f; f = f->sister) {
			if (current_program->returning) {
				if (cb_ref (current_program->returning) != cb_error_node) {
					if (f == CB_FIELD (cb_ref (current_program->returning))) {
						continue;
					}
				}
			}
			for (l = using_list; l; l = CB_CHAIN (l)) {
				x = CB_VALUE (l);
				if (CB_VALID_TREE (x) && cb_ref (x) != cb_error_node) {
					if (f == CB_FIELD (cb_ref (x))) {
						break;
					}
				}
			}
			if (!l && !f->redefines) {
				cb_warning (_("LINKAGE item '%s' is not a PROCEDURE USING parameter"), f->name);
			}
		}
	}

	/* Check returning item against using items when FUNCTION */
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		for (l = using_list; l; l = CB_CHAIN (l)) {
			x = CB_VALUE (l);
			if (CB_VALID_TREE (x) && current_program->returning &&
			    cb_ref (x) == cb_ref (current_program->returning)) {
				cb_error_x (x, _("'%s' USING item duplicates RETURNING item"), cb_name (x));
			}
		}
	}

	for (l = current_program->entry_list; l; l = CB_CHAIN (l)) {
		if (strcmp ((const char *)name,
			    (const char *)(CB_LABEL(CB_PURPOSE(l))->name)) == 0) {
			cb_error_x (CB_TREE (current_statement),
				    _("ENTRY '%s' duplicated"), name);
		}
	}

	current_program->entry_list =
		cb_list_append (current_program->entry_list,
				CB_BUILD_PAIR (label, using_list));
}

static size_t
increment_depth (void)
{
	if (++depth >= PROG_DEPTH) {
		cb_error (_("Maximum nested program depth exceeded (%d)"),
			  PROG_DEPTH);
		return 1;
	}
	return 0;
}

static void
terminator_warning (cb_tree stmt, const unsigned int termid,
		    const char *name)
{
	check_unreached = 0;
	if (term_array[termid]) {
		term_array[termid]--;
		if (cb_warn_terminator) {
			cb_warning_x (stmt,
				_("%s statement not terminated by END-%s"),
				name, name);
		}
	}
	/* Free tree assocated with terminator */
	cobc_parse_free (stmt);
}

static void
terminator_error (cb_tree stmt, const unsigned int termid, const char *name)
{
	check_unreached = 0;
	cb_error_x (CB_TREE (current_statement),
			_("%s statement not terminated by END-%s"),
			name, name);
	if (term_array[termid]) {
		term_array[termid]--;
	}
	/* Free tree assocated with terminator */
	cobc_parse_free (stmt);
}

static void
terminator_clear (cb_tree stmt, const unsigned int termid)
{
	check_unreached = 0;
	if (term_array[termid]) {
		term_array[termid]--;
	}
	/* Free tree assocated with terminator */
	cobc_parse_free (stmt);
}

static int
literal_value (cb_tree x)
{
	if (x == cb_space) {
		return ' ';
	} else if (x == cb_zero) {
		return '0';
	} else if (x == cb_quote) {
		return cb_flag_apostrophe ? '\'' : '"';
	} else if (x == cb_null) {
		return 0;
	} else if (x == cb_low) {
		return 0;
	} else if (x == cb_high) {
		return 255;
	} else if (CB_TREE_CLASS (x) == CB_CLASS_NUMERIC) {
		return cb_get_int (x);
	} else {
		return CB_LITERAL (x)->data[0];
	}
}

static void
setup_use_file (struct cb_file *fileptr)
{
	struct cb_file	*newptr;

	if (fileptr->organization == COB_ORG_SORT) {
		cb_error (_("USE statement invalid for SORT file"));
	}
	if (fileptr->flag_global) {
		newptr = cobc_parse_malloc (sizeof(struct cb_file));
		*newptr = *fileptr;
		newptr->handler = current_section;
		newptr->handler_prog = current_program;
		if (!use_global_ind) {
			current_program->local_file_list =
				cb_list_add (current_program->local_file_list,
					     CB_TREE (newptr));
		} else {
			current_program->global_file_list =
				cb_list_add (current_program->global_file_list,
					     CB_TREE (newptr));
		}
	} else {
		fileptr->handler = current_section;
	}
}

static void
build_nested_special (const int ndepth)
{
	cb_tree		x;
	cb_tree		y;

	if (!ndepth) {
		return;
	}

	/* Inherit special name mnemonics from parent */
	for (x = current_program->mnemonic_spec_list; x; x = CB_CHAIN (x)) {
		y = cb_build_reference (cb_name(CB_PURPOSE(x)));
		if (CB_SYSTEM_NAME_P (CB_VALUE(x))) {
			cb_define (y, CB_VALUE(x));
		} else {
			cb_build_constant (y, CB_VALUE(x));
		}
	}
}

static void
clear_initial_values (void)
{
	perform_stack = NULL;
	current_statement = NULL;
	main_statement = NULL;
	qualifier = NULL;
	in_declaratives = 0;
	in_debugging = 0;
	use_global_ind = 0;
	check_duplicate = 0;
	check_pic_duplicate = 0;
	check_comp_duplicate = 0;
	skip_statements = 0;
	start_debug = 0;
	save_debug = 0;
	needs_field_debug = 0;
	needs_debug_item = 0;
	env_div_seen = 0;
	header_check = 0;
	next_label_id = 0;
	current_linage = 0;
	setattr_val_on = 0;
	setattr_val_off = 0;
	report_count = 0;
	current_storage = CB_STORAGE_WORKING;
	eval_level = 0;
	eval_inc = 0;
	eval_inc2 = 0;
	inspect_keyword = 0;
	check_unreached = 0;
	cobc_in_procedure = 0;
	cobc_in_repository = 0;
	cobc_force_literal = 0;
	non_const_word = 0;
	samearea = 1;
	memset ((void *)eval_check, 0, sizeof(eval_check));
	memset ((void *)term_array, 0, sizeof(term_array));
	linage_file = NULL;
	current_file = NULL;
	current_report = NULL;
	report_instance = NULL;
	next_label_list = NULL;
	if (cobc_glob_line) {
		free (cobc_glob_line);
		cobc_glob_line = NULL;
	}
}

static void
check_repeated (const char *clause, const unsigned int bitval)
{
	if (check_duplicate & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		check_duplicate |= bitval;
	}
}

static void
check_pic_repeated (const char *clause, const unsigned int bitval)
{
	if (check_pic_duplicate & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		check_pic_duplicate |= bitval;
	}
}

static void
check_comp_repeated (const char *clause, const unsigned int bitval)
{
	if (check_comp_duplicate & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		check_comp_duplicate |= bitval;
	}
}

static void
check_screen_attr (const char *clause, const int bitval)
{
	if (current_field->screen_flag & bitval) {
		if (cb_relaxed_syntax_check) {
			cb_warning (_("Duplicate %s clause"), clause);
		} else {
			cb_error (_("Duplicate %s clause"), clause);
		}
	} else {
		current_field->screen_flag |= bitval;
	}
}

static void
bit_set_attr (const cb_tree onoff, const int attrval)
{
	if (onoff == cb_int1) {
		setattr_val_on |= attrval;
	} else {
		setattr_val_off |= attrval;
	}
}

static void
check_attribs (cb_tree fgc, cb_tree bgc, cb_tree scroll,
	       cb_tree timeout, cb_tree prompt, int attribs)
{
	/* Attach attributes to current_statement */
	if (!current_statement->attr_ptr) {
		current_statement->attr_ptr =
			cobc_parse_malloc (sizeof(struct cb_attr_struct));
	}
	if (fgc) {
		current_statement->attr_ptr->fgc = fgc;
	}
	if (bgc) {
		current_statement->attr_ptr->bgc = bgc;
	}
	if (scroll) {
		current_statement->attr_ptr->scroll = scroll;
	}
	if (timeout) {
		current_statement->attr_ptr->timeout = timeout;
	}
	if (prompt) {
		current_statement->attr_ptr->prompt = prompt;
	}
	current_statement->attr_ptr->dispattrs |= attribs;
}

static void
check_set_usage (const enum cb_usage usage)
{
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	current_field->usage = usage;
}

static void
check_relaxed_syntax (const unsigned int lev)
{
	const char	*s;

	switch (lev) {
	case COBC_HD_ENVIRONMENT_DIVISION:
		s = "ENVIRONMENT DIVISION";
		break;
	case COBC_HD_CONFIGURATION_SECTION:
		s = "CONFIGURATION SECTION";
		break;
	case COBC_HD_SPECIAL_NAMES:
		s = "SPECIAL-NAMES";
		break;
	case COBC_HD_INPUT_OUTPUT_SECTION:
		s = "INPUT-OUTPUT SECTION";
		break;
	case COBC_HD_FILE_CONTROL:
		s = "FILE-CONTROL";
		break;
	case COBC_HD_I_O_CONTROL:
		s = "I-O-CONTROL";
		break;
	case COBC_HD_DATA_DIVISION:
		s = "DATA DIVISION";
		break;
	case COBC_HD_FILE_SECTION:
		s = "FILE SECTION";
		break;
	case COBC_HD_WORKING_STORAGE_SECTION:
		s = "WORKING-STORAGE SECTION";
		break;
	case COBC_HD_LOCAL_STORAGE_SECTION:
		s = "LOCAL-STORAGE SECTION";
		break;
	case COBC_HD_LINKAGE_SECTION:
		s = "LINKAGE SECTION";
		break;
	case COBC_HD_COMMUNICATIONS_SECTION:
		s = "COMMUNICATIONS SECTION";
		break;
	case COBC_HD_REPORT_SECTION:
		s = "REPORT SECTION";
		break;
	case COBC_HD_SCREEN_SECTION:
		s = "SCREEN SECTION";
		break;
	case COBC_HD_PROCEDURE_DIVISION:
		s = "PROCEDURE DIVISION";
		break;
	case COBC_HD_PROGRAM_ID:
		s = "PROGRAM-ID";
		break;
	default:
		s = "Unknown";
		break;
	}
	if (cb_relaxed_syntax_check) {
		cb_warning (_("%s header missing - assumed"), s);
	} else {
		cb_error (_("%s header missing"), s);
	}
}

static void
check_headers_present (const unsigned int lev1, const unsigned int lev2,
		       const unsigned int lev3, const unsigned int lev4)
{
	/* Lev1 is always present and checked */
	/* Lev2/3/4, if non-zero (forced) may be present */
	if (!(header_check & lev1)) {
		header_check |= lev1;
		check_relaxed_syntax (lev1);
	}
	if (lev2) {
		if (!(header_check & lev2)) {
			header_check |= lev2;
			check_relaxed_syntax (lev2);
		}
	}
	if (lev3) {
		if (!(header_check & lev3)) {
			header_check |= lev3;
			check_relaxed_syntax (lev3);
		}
	}
	if (lev4) {
		if (!(header_check & lev4)) {
			header_check |= lev4;
			check_relaxed_syntax (lev4);
		}
	}
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1828 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  512
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  813
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1898
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2706

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   766

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    16,    18,
      20,    21,    24,    29,    34,    38,    39,    41,    44,    45,
      47,    51,    52,    54,    58,    59,    60,    61,    82,    83,
      91,    97,    99,   101,   102,   105,   106,   110,   112,   115,
     117,   119,   121,   123,   124,   128,   129,   133,   134,   137,
     139,   141,   143,   145,   147,   148,   153,   154,   158,   159,
     163,   164,   169,   170,   173,   177,   180,   182,   185,   187,
     189,   191,   193,   199,   203,   207,   212,   214,   216,   218,
     220,   222,   225,   226,   231,   232,   235,   239,   241,   244,
     248,   252,   256,   258,   260,   261,   264,   266,   269,   272,
     275,   279,   281,   284,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   304,   306,   308,   309,   313,   316,   320,
     324,   326,   327,   329,   333,   338,   339,   345,   347,   349,
     351,   353,   355,   357,   359,   362,   364,   368,   369,   374,
     376,   380,   382,   384,   386,   388,   390,   392,   395,   396,
     399,   403,   405,   408,   412,   414,   417,   419,   422,   427,
     429,   432,   434,   438,   443,   449,   450,   454,   458,   464,
     468,   473,   477,   481,   482,   486,   487,   490,   491,   494,
     495,   498,   499,   506,   510,   511,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540,
     546,   552,   558,   564,   570,   572,   574,   576,   578,   579,
     583,   584,   586,   588,   590,   592,   593,   595,   597,   602,
     604,   606,   608,   615,   619,   624,   625,   627,   629,   630,
     636,   639,   642,   644,   645,   650,   656,   659,   663,   665,
     667,   671,   673,   676,   681,   686,   691,   693,   697,   702,
     707,   711,   713,   715,   719,   722,   725,   728,   729,   732,
     736,   738,   741,   743,   745,   751,   752,   754,   756,   758,
     759,   766,   768,   771,   774,   775,   778,   779,   783,   784,
     788,   789,   792,   795,   796,   802,   806,   808,   810,   811,
     814,   817,   820,   822,   824,   826,   828,   830,   832,   834,
     836,   838,   844,   845,   847,   849,   854,   861,   871,   872,
     876,   877,   880,   881,   884,   888,   894,   900,   902,   904,
     906,   908,   912,   918,   919,   922,   924,   926,   928,   933,
     936,   939,   944,   948,   951,   954,   957,   959,   962,   963,
     964,   970,   971,   972,   975,   978,   982,   985,   987,   988,
     993,   997,  1000,  1001,  1003,  1005,  1007,  1008,  1011,  1013,
    1016,  1019,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,
    1039,  1041,  1043,  1045,  1047,  1050,  1052,  1054,  1056,  1058,
    1060,  1062,  1064,  1066,  1068,  1074,  1077,  1080,  1081,  1084,
    1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,
    1106,  1108,  1110,  1112,  1115,  1119,  1120,  1123,  1126,  1128,
    1130,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1177,  1180,  1183,  1186,  1189,  1192,  1195,  1198,
    1201,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,  1220,
    1222,  1224,  1228,  1232,  1239,  1240,  1243,  1251,  1252,  1255,
    1256,  1260,  1262,  1263,  1269,  1271,  1273,  1274,  1278,  1280,
    1283,  1285,  1288,  1291,  1295,  1297,  1298,  1304,  1306,  1309,
    1311,  1315,  1316,  1321,  1324,  1329,  1332,  1335,  1336,  1337,
    1343,  1344,  1345,  1351,  1352,  1353,  1359,  1360,  1363,  1364,
    1371,  1372,  1375,  1378,  1381,  1385,  1387,  1389,  1392,  1395,
    1397,  1399,  1401,  1403,  1406,  1408,  1413,  1415,  1418,  1423,
    1425,  1427,  1428,  1431,  1433,  1435,  1437,  1439,  1441,  1445,
    1450,  1455,  1460,  1464,  1465,  1468,  1469,  1475,  1476,  1479,
    1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,  1499,
    1501,  1503,  1505,  1507,  1509,  1511,  1513,  1517,  1519,  1521,
    1524,  1527,  1529,  1531,  1533,  1534,  1536,  1538,  1539,  1541,
    1543,  1548,  1550,  1553,  1556,  1558,  1561,  1563,  1565,  1567,
    1572,  1573,  1577,  1580,  1582,  1584,  1588,  1595,  1598,  1601,
    1603,  1606,  1609,  1610,  1613,  1615,  1617,  1620,  1624,  1627,
    1631,  1634,  1637,  1639,  1644,  1647,  1651,  1652,  1653,  1659,
    1660,  1662,  1665,  1669,  1671,  1672,  1677,  1681,  1682,  1685,
    1688,  1691,  1693,  1695,  1698,  1701,  1703,  1705,  1707,  1709,
    1711,  1713,  1715,  1717,  1719,  1721,  1726,  1728,  1730,  1736,
    1742,  1746,  1750,  1752,  1754,  1756,  1758,  1760,  1762,  1764,
    1766,  1769,  1772,  1775,  1777,  1779,  1781,  1783,  1784,  1786,
    1788,  1789,  1791,  1793,  1797,  1800,  1801,  1802,  1803,  1813,
    1814,  1819,  1820,  1821,  1825,  1826,  1830,  1832,  1835,  1840,
    1841,  1844,  1847,  1848,  1852,  1856,  1861,  1866,  1870,  1871,
    1873,  1874,  1877,  1878,  1879,  1887,  1888,  1891,  1893,  1895,
    1898,  1900,  1902,  1903,  1910,  1911,  1914,  1917,  1919,  1920,
    1922,  1923,  1924,  1928,  1929,  1932,  1935,  1937,  1939,  1941,
    1943,  1945,  1947,  1949,  1951,  1953,  1955,  1957,  1959,  1961,
    1963,  1965,  1967,  1969,  1971,  1973,  1975,  1977,  1979,  1981,
    1983,  1985,  1987,  1989,  1991,  1993,  1995,  1997,  1999,  2001,
    2003,  2005,  2007,  2009,  2011,  2013,  2015,  2017,  2019,  2021,
    2023,  2025,  2027,  2029,  2031,  2033,  2036,  2039,  2040,  2045,
    2052,  2056,  2060,  2065,  2069,  2074,  2078,  2082,  2087,  2092,
    2096,  2101,  2105,  2110,  2116,  2120,  2125,  2129,  2133,  2135,
    2137,  2139,  2142,  2143,  2145,  2149,  2153,  2156,  2159,  2162,
    2166,  2170,  2174,  2175,  2177,  2178,  2182,  2183,  2186,  2188,
    2191,  2193,  2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,
    2211,  2213,  2218,  2220,  2222,  2224,  2226,  2228,  2230,  2232,
    2236,  2240,  2244,  2248,  2252,  2253,  2255,  2256,  2261,  2266,
    2272,  2279,  2280,  2283,  2284,  2286,  2287,  2291,  2295,  2300,
    2301,  2304,  2305,  2309,  2311,  2314,  2319,  2320,  2323,  2324,
    2329,  2336,  2337,  2339,  2341,  2343,  2344,  2345,  2349,  2351,
    2354,  2357,  2361,  2362,  2365,  2368,  2371,  2372,  2376,  2379,
    2384,  2386,  2388,  2390,  2392,  2393,  2396,  2397,  2400,  2401,
    2403,  2404,  2408,  2410,  2413,  2414,  2418,  2421,  2425,  2426,
    2428,  2432,  2436,  2439,  2440,  2445,  2450,  2451,  2453,  2455,
    2457,  2458,  2463,  2467,  2470,  2472,  2475,  2476,  2478,  2479,
    2484,  2488,  2492,  2496,  2500,  2505,  2508,  2513,  2515,  2516,
    2520,  2526,  2527,  2530,  2533,  2536,  2539,  2540,  2543,  2545,
    2547,  2548,  2551,  2552,  2554,  2556,  2559,  2561,  2564,  2567,
    2569,  2571,  2574,  2577,  2579,  2581,  2583,  2585,  2587,  2591,
    2595,  2599,  2603,  2604,  2606,  2607,  2612,  2617,  2624,  2631,
    2640,  2649,  2650,  2652,  2653,  2657,  2660,  2661,  2666,  2669,
    2671,  2675,  2677,  2679,  2681,  2684,  2686,  2688,  2691,  2694,
    2698,  2701,  2705,  2707,  2711,  2714,  2716,  2718,  2720,  2721,
    2724,  2725,  2727,  2728,  2732,  2733,  2735,  2737,  2740,  2742,
    2744,  2746,  2747,  2751,  2753,  2754,  2758,  2760,  2761,  2765,
    2769,  2770,  2774,  2776,  2777,  2784,  2788,  2791,  2793,  2794,
    2796,  2797,  2801,  2807,  2808,  2811,  2812,  2816,  2820,  2821,
    2824,  2826,  2829,  2834,  2836,  2838,  2840,  2842,  2844,  2846,
    2848,  2849,  2853,  2854,  2858,  2860,  2863,  2864,  2868,  2871,
    2873,  2875,  2877,  2880,  2882,  2884,  2886,  2887,  2891,  2894,
    2900,  2902,  2905,  2908,  2911,  2913,  2915,  2917,  2920,  2922,
    2925,  2930,  2933,  2934,  2936,  2938,  2940,  2942,  2947,  2948,
    2951,  2955,  2959,  2960,  2964,  2965,  2969,  2973,  2978,  2979,
    2984,  2989,  2996,  2997,  2999,  3000,  3004,  3009,  3015,  3017,
    3019,  3021,  3023,  3024,  3028,  3029,  3033,  3036,  3038,  3039,
    3043,  3046,  3047,  3052,  3055,  3056,  3058,  3060,  3062,  3064,
    3068,  3069,  3072,  3074,  3078,  3082,  3083,  3087,  3089,  3091,
    3093,  3097,  3105,  3106,  3111,  3119,  3120,  3123,  3124,  3127,
    3130,  3134,  3138,  3142,  3145,  3146,  3150,  3152,  3154,  3155,
    3157,  3159,  3160,  3164,  3167,  3169,  3170,  3175,  3180,  3181,
    3183,  3184,  3189,  3194,  3195,  3198,  3202,  3203,  3205,  3207,
    3208,  3213,  3218,  3225,  3226,  3229,  3230,  3233,  3235,  3238,
    3242,  3243,  3245,  3246,  3250,  3252,  3254,  3256,  3258,  3260,
    3262,  3264,  3266,  3268,  3270,  3275,  3279,  3281,  3284,  3287,
    3290,  3293,  3296,  3299,  3302,  3305,  3308,  3313,  3317,  3322,
    3324,  3327,  3331,  3333,  3336,  3340,  3344,  3345,  3349,  3350,
    3358,  3359,  3365,  3366,  3369,  3370,  3373,  3374,  3378,  3379,
    3382,  3387,  3388,  3391,  3396,  3397,  3402,  3407,  3408,  3412,
    3413,  3418,  3420,  3422,  3424,  3427,  3430,  3433,  3436,  3438,
    3440,  3443,  3445,  3446,  3448,  3449,  3454,  3457,  3458,  3461,
    3464,  3469,  3474,  3475,  3477,  3479,  3481,  3483,  3485,  3486,
    3491,  3497,  3499,  3502,  3504,  3508,  3512,  3513,  3518,  3519,
    3521,  3522,  3527,  3532,  3539,  3546,  3547,  3549,  3552,  3553,
    3555,  3556,  3560,  3562,  3565,  3566,  3570,  3576,  3577,  3581,
    3584,  3585,  3587,  3589,  3590,  3595,  3602,  3603,  3607,  3609,
    3613,  3616,  3619,  3622,  3626,  3627,  3631,  3632,  3636,  3637,
    3641,  3642,  3644,  3645,  3649,  3651,  3653,  3655,  3657,  3665,
    3666,  3668,  3670,  3672,  3674,  3676,  3678,  3683,  3685,  3688,
    3690,  3693,  3697,  3698,  3700,  3703,  3705,  3710,  3712,  3714,
    3716,  3717,  3722,  3728,  3729,  3732,  3733,  3738,  3742,  3746,
    3748,  3750,  3752,  3754,  3755,  3757,  3760,  3761,  3764,  3765,
    3768,  3771,  3772,  3775,  3776,  3779,  3782,  3783,  3786,  3787,
    3790,  3793,  3794,  3797,  3798,  3801,  3804,  3806,  3809,  3811,
    3813,  3816,  3819,  3822,  3824,  3826,  3829,  3832,  3835,  3836,
    3839,  3840,  3843,  3844,  3847,  3849,  3851,  3852,  3855,  3857,
    3860,  3863,  3865,  3867,  3869,  3871,  3873,  3875,  3877,  3879,
    3881,  3883,  3885,  3887,  3889,  3891,  3893,  3895,  3897,  3899,
    3901,  3903,  3905,  3907,  3909,  3911,  3913,  3916,  3918,  3920,
    3922,  3924,  3926,  3928,  3930,  3934,  3935,  3937,  3939,  3943,
    3947,  3949,  3953,  3957,  3959,  3963,  3965,  3968,  3971,  3973,
    3977,  3979,  3981,  3985,  3987,  3991,  3993,  3997,  3999,  4002,
    4005,  4007,  4009,  4011,  4014,  4016,  4018,  4020,  4023,  4025,
    4026,  4029,  4031,  4033,  4035,  4039,  4041,  4043,  4046,  4048,
    4050,  4052,  4055,  4057,  4059,  4061,  4063,  4065,  4067,  4070,
    4072,  4074,  4078,  4080,  4083,  4085,  4087,  4089,  4091,  4094,
    4097,  4100,  4105,  4109,  4111,  4113,  4116,  4118,  4120,  4122,
    4124,  4126,  4128,  4130,  4133,  4136,  4139,  4141,  4143,  4145,
    4147,  4149,  4151,  4153,  4155,  4157,  4159,  4161,  4163,  4165,
    4167,  4169,  4171,  4173,  4175,  4177,  4179,  4181,  4183,  4185,
    4187,  4189,  4191,  4194,  4196,  4200,  4203,  4206,  4208,  4210,
    4212,  4216,  4219,  4222,  4224,  4226,  4230,  4234,  4239,  4245,
    4247,  4249,  4251,  4253,  4255,  4257,  4259,  4261,  4263,  4265,
    4267,  4270,  4272,  4276,  4278,  4280,  4282,  4284,  4286,  4288,
    4290,  4293,  4299,  4305,  4311,  4316,  4322,  4328,  4334,  4337,
    4340,  4342,  4344,  4346,  4348,  4350,  4352,  4354,  4356,  4357,
    4362,  4368,  4369,  4373,  4376,  4378,  4382,  4386,  4388,  4392,
    4394,  4398,  4399,  4400,  4402,  4403,  4405,  4406,  4408,  4409,
    4412,  4413,  4416,  4417,  4419,  4421,  4422,  4424,  4425,  4427,
    4430,  4431,  4434,  4435,  4439,  4441,  4443,  4445,  4447,  4449,
    4451,  4453,  4455,  4456,  4459,  4461,  4463,  4465,  4467,  4469,
    4471,  4473,  4475,  4477,  4479,  4481,  4483,  4485,  4487,  4489,
    4491,  4493,  4495,  4497,  4499,  4501,  4503,  4505,  4507,  4509,
    4511,  4513,  4515,  4517,  4519,  4521,  4523,  4525,  4527,  4529,
    4531,  4533,  4535,  4537,  4539,  4541,  4543,  4545,  4547,  4549,
    4551,  4553,  4555,  4557,  4559,  4561,  4563,  4565,  4567,  4569,
    4571,  4573,  4575,  4577,  4579,  4581,  4583,  4585,  4587,  4589,
    4591,  4593,  4595,  4597,  4599,  4600,  4602,  4603,  4605,  4606,
    4608,  4609,  4611,  4612,  4614,  4615,  4617,  4618,  4620,  4621,
    4623,  4624,  4626,  4627,  4629,  4630,  4632,  4633,  4635,  4636,
    4638,  4639,  4641,  4642,  4644,  4645,  4647,  4648,  4650,  4653,
    4654,  4656,  4657,  4659,  4660,  4662,  4663,  4665,  4666,  4668,
    4670,  4671,  4673,  4674,  4676,  4678,  4679,  4681,  4683,  4684,
    4687,  4690,  4691,  4693,  4694,  4696,  4697,  4699,  4700,  4702,
    4704,  4705,  4707,  4708,  4710,  4711,  4714,  4716,  4718,  4719,
    4721,  4722,  4724,  4725,  4727,  4728,  4730,  4731,  4733,  4734,
    4736,  4737,  4739,  4740,  4742,  4745,  4746,  4748,  4749,  4751,
    4752,  4754,  4755,  4757,  4758,  4760,  4761,  4763,  4764,  4766,
    4767,  4769,  4771,  4772,  4774,  4775,  4779,  4780,  4782,  4785,
    4787,  4789,  4791,  4793,  4795,  4797,  4799,  4801,  4803,  4805,
    4807,  4809,  4811,  4813,  4815,  4817,  4819,  4821,  4823,  4825,
    4827,  4830,  4833,  4835,  4837,  4839,  4841,  4843,  4845,  4848,
    4850,  4854,  4857,  4859,  4861,  4863,  4866,  4868,  4871,  4873,
    4876,  4878,  4881,  4883,  4886,  4888,  4891,  4893,  4896
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     513,     0,    -1,    -1,   514,   515,    -1,   518,    -1,   516,
      -1,   517,    -1,   516,   517,    -1,   520,    -1,   522,    -1,
      -1,   519,   528,    -1,   532,   528,   523,   524,    -1,   532,
     528,   523,   525,    -1,   534,   528,   526,    -1,    -1,   521,
      -1,   523,   521,    -1,    -1,   525,    -1,   142,   535,   451,
      -1,    -1,   527,    -1,   138,   535,   451,    -1,    -1,    -1,
      -1,   540,   541,   542,   603,   604,   606,   605,   638,   529,
     648,   649,   650,   530,   679,   732,   734,   736,   787,   531,
     801,    -1,    -1,   341,   451,   535,   536,   533,   537,   451,
      -1,   200,   451,   535,   536,   451,    -1,   342,    -1,   256,
      -1,    -1,    26,   256,    -1,    -1,  1268,   538,  1283,    -1,
      72,    -1,    72,   539,    -1,   539,    -1,   171,    -1,   456,
      -1,   354,    -1,    -1,   153,   122,   451,    -1,    -1,    84,
     394,   451,    -1,    -1,   542,   543,    -1,   544,    -1,   548,
      -1,   567,    -1,   568,    -1,   559,    -1,    -1,   415,   451,
     545,   546,    -1,    -1,   558,   547,   451,    -1,    -1,  1299,
     107,   272,    -1,    -1,   304,   451,   549,   550,    -1,    -1,
     558,   451,    -1,   558,   551,   451,    -1,   551,   451,    -1,
     552,    -1,   551,   552,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   268,   410,  1268,  1218,  1310,    -1,  1316,
    1268,  1185,    -1,   396,  1268,  1218,    -1,  1256,    59,  1268,
     557,    -1,  1185,    -1,   257,    -1,   494,    -1,   435,    -1,
     504,    -1,   558,   504,    -1,    -1,   369,   451,   560,   561,
      -1,    -1,   562,   451,    -1,   562,     1,   451,    -1,   563,
      -1,   562,   563,    -1,   199,     9,   229,    -1,   199,   564,
     565,    -1,   199,   566,   229,    -1,   370,    -1,   496,    -1,
      -1,    26,   256,    -1,   370,    -1,   566,   370,    -1,   417,
     451,    -1,   569,   451,    -1,   569,     1,   451,    -1,   570,
      -1,   569,   570,    -1,   571,    -1,   576,    -1,   584,    -1,
     594,    -1,   591,    -1,   595,    -1,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,    -1,   504,
     572,   573,    -1,  1268,    96,    -1,  1218,  1268,  1189,    -1,
    1268,  1189,   574,    -1,   575,    -1,    -1,   575,    -1,  1036,
    1280,  1189,    -1,   575,  1036,  1280,  1189,    -1,    -1,    11,
    1189,   577,  1268,   578,    -1,   280,    -1,   419,    -1,   420,
      -1,   126,    -1,    28,    -1,   579,    -1,   580,    -1,   579,
     580,    -1,   583,    -1,   583,   442,   583,    -1,    -1,   583,
      17,   581,   582,    -1,   583,    -1,   582,    17,   583,    -1,
     256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,    -1,
     266,    -1,   586,   585,    -1,    -1,   218,   504,    -1,   433,
    1257,   587,    -1,   588,    -1,   587,   588,    -1,   589,  1269,
     590,    -1,  1190,    -1,   589,  1190,    -1,  1219,    -1,   590,
    1219,    -1,    58,  1189,  1268,   592,    -1,   593,    -1,   592,
     593,    -1,  1221,    -1,  1221,   442,  1221,    -1,   257,  1189,
    1268,   256,    -1,    98,  1286,  1268,   256,   596,    -1,    -1,
    1299,   328,   256,    -1,   108,  1268,    68,    -1,   301,   405,
    1268,   468,   400,    -1,   100,  1268,  1184,    -1,    96,   423,
    1268,  1184,    -1,   390,  1268,  1184,    -1,   164,  1268,  1184,
      -1,    -1,   226,   394,   451,    -1,    -1,   173,   451,    -1,
      -1,   234,   451,    -1,    -1,   606,   607,    -1,    -1,   397,
    1242,  1189,   608,   609,   451,    -1,   397,     1,   451,    -1,
      -1,   609,   610,    -1,   611,    -1,   617,    -1,   619,    -1,
     620,    -1,   621,    -1,   623,    -1,   627,    -1,   629,    -1,
     630,    -1,   631,    -1,   633,    -1,   634,    -1,   636,    -1,
      29,  1296,   614,   613,   615,    -1,    29,  1296,   614,   612,
     616,    -1,    29,  1296,   614,   119,   616,    -1,    29,  1296,
     614,   238,   616,    -1,    29,  1296,   614,   335,   616,    -1,
     117,    -1,   118,    -1,   437,    -1,   347,    -1,    -1,   252,
       7,  1260,    -1,    -1,   171,    -1,   125,    -1,   256,    -1,
    1215,    -1,    -1,   256,    -1,  1215,    -1,     4,  1275,  1268,
     618,    -1,   402,    -1,   125,    -1,   347,    -1,    19,  1284,
    1270,  1268,   632,  1236,    -1,  1300,  1268,   504,    -1,   622,
     423,  1268,  1184,    -1,    -1,   454,    -1,   412,    -1,    -1,
     624,   262,  1275,  1268,   625,    -1,   267,   626,    -1,    33,
     626,    -1,   167,    -1,    -1,   503,   262,   309,  1309,    -1,
     503,   262,   309,   274,  1309,    -1,   503,   385,    -1,   315,
    1268,   628,    -1,   628,    -1,   220,    -1,  1284,  1254,   402,
      -1,   359,    -1,   252,   402,    -1,   320,  1256,  1268,  1188,
      -1,   351,   113,  1268,   419,    -1,   351,  1270,  1268,   632,
      -1,  1184,    -1,  1184,   452,  1183,    -1,  1184,   414,  1268,
    1183,    -1,   359,  1270,  1268,  1184,    -1,   372,   635,  1251,
      -1,   287,    -1,  1218,    -1,   404,  1299,   637,    -1,     9,
    1281,    -1,   287,  1281,    -1,   349,   310,    -1,    -1,   639,
     451,    -1,   639,     1,   451,    -1,   640,    -1,   639,   640,
      -1,   641,    -1,   643,    -1,   388,   642,  1251,  1261,  1174,
      -1,    -1,   351,    -1,   412,    -1,   413,    -1,    -1,   274,
     644,  1260,  1292,  1258,   645,    -1,   646,    -1,   645,   646,
      -1,  1175,   647,    -1,    -1,   331,  1218,    -1,    -1,   102,
     122,   451,    -1,    -1,   454,   394,   451,    -1,    -1,   650,
     651,    -1,   652,   681,    -1,    -1,   654,  1175,   653,   655,
     451,    -1,   654,     1,   451,    -1,   172,    -1,   392,    -1,
      -1,   655,   656,    -1,  1268,   171,    -1,  1268,   204,    -1,
     657,    -1,   659,    -1,   663,    -1,   664,    -1,   667,    -1,
     668,    -1,   674,    -1,   675,    -1,   676,    -1,    47,  1258,
    1218,   662,   658,    -1,    -1,   353,    -1,    57,    -1,   351,
    1258,  1218,  1257,    -1,   351,  1258,  1218,   446,  1218,  1257,
      -1,   351,  1268,   499,  1263,  1289,   661,   662,  1257,   660,
      -1,    -1,   114,  1279,  1184,    -1,    -1,  1262,  1218,    -1,
      -1,   446,  1218,    -1,   239,  1311,  1307,    -1,   498,   306,
     665,  1268,   666,    -1,   498,   306,   174,  1268,   666,    -1,
     504,    -1,   213,    -1,   256,    -1,  1215,    -1,   102,  1311,
    1186,    -1,   250,  1268,  1188,  1274,   669,    -1,    -1,   669,
     670,    -1,   671,    -1,   672,    -1,   673,    -1,  1299,   187,
    1253,  1188,    -1,   465,  1188,    -1,    48,  1188,    -1,   352,
    1275,  1268,   504,    -1,    62,  1268,   504,    -1,   677,   678,
      -1,   366,  1268,    -1,   368,  1250,    -1,  1189,    -1,   678,
    1189,    -1,    -1,    -1,   506,   394,   451,   680,   681,    -1,
      -1,    -1,   682,   683,    -1,   684,   451,    -1,   683,   684,
     451,    -1,   683,   451,    -1,   696,    -1,    -1,   686,   687,
     685,   698,    -1,   686,     1,   451,    -1,  1234,   504,    -1,
      -1,   175,    -1,   504,    -1,   504,    -1,    -1,  1268,   204,
      -1,  1222,    -1,   245,   691,    -1,   244,   691,    -1,    50,
    1278,   691,    -1,  1212,    -1,    41,    -1,    44,    -1,    43,
      -1,    42,    -1,    40,    -1,   695,    -1,   707,    -1,   708,
      -1,   692,    -1,   693,    -1,   694,    -1,     1,   451,    -1,
     179,    -1,   183,    -1,   180,    -1,   181,    -1,   178,    -1,
     182,    -1,   184,    -1,   330,    -1,   343,    -1,   686,   688,
      85,   689,   697,    -1,  1252,   690,    -1,   196,   504,    -1,
      -1,   698,   699,    -1,   700,    -1,   701,    -1,   703,    -1,
     704,    -1,   705,    -1,   709,    -1,   712,    -1,   721,    -1,
     722,    -1,   723,    -1,   724,    -1,   725,    -1,   730,    -1,
     731,    -1,   355,  1212,    -1,  1268,   171,   702,    -1,    -1,
      26,   256,    -1,  1268,   204,    -1,   327,    -1,   706,    -1,
     491,  1268,   706,    -1,    39,    -1,    73,    -1,   707,    -1,
     708,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   119,    -1,   219,    -1,   319,    -1,   330,    -1,
     343,    -1,   409,    -1,   407,    -1,   408,    -1,   479,    -1,
     477,    -1,   478,    -1,    41,  1287,    -1,    41,   476,    -1,
      44,  1287,    -1,    44,   476,    -1,    43,  1287,    -1,    43,
     476,    -1,    42,  1287,    -1,    42,   476,    -1,    40,  1287,
      -1,    40,   476,    -1,   179,    -1,   180,    -1,   178,    -1,
     181,    -1,   182,    -1,   277,    -1,    75,    -1,   186,    -1,
      76,    -1,   185,    -1,  1288,   241,  1246,    -1,  1288,   468,
    1246,    -1,   305,  1218,   713,  1294,   714,   711,    -1,    -1,
     425,  1218,    -1,   305,  1218,   713,  1294,   714,   715,   718,
      -1,    -1,   446,  1218,    -1,    -1,   114,  1279,  1184,    -1,
     716,    -1,    -1,   716,   717,  1270,  1268,  1183,    -1,    27,
      -1,   115,    -1,    -1,   220,  1255,   719,    -1,   720,    -1,
     719,   720,    -1,   504,    -1,   235,  1285,    -1,   434,  1271,
      -1,    45,  1297,   510,    -1,    36,    -1,    -1,   498,  1269,
     727,   726,   729,    -1,   728,    -1,   727,   728,    -1,  1222,
      -1,  1222,   442,  1222,    -1,    -1,  1298,   453,  1268,  1222,
      -1,   363,  1215,    -1,   363,  1215,   442,  1215,    -1,    21,
     244,    -1,    21,   301,    -1,    -1,    -1,   261,   394,   451,
     733,   681,    -1,    -1,    -1,   255,   394,   451,   735,   681,
      -1,    -1,    -1,   366,   394,   451,   737,   738,    -1,    -1,
     738,   739,    -1,    -1,   348,  1176,   740,   741,   451,   758,
      -1,    -1,   741,   742,    -1,     1,   451,    -1,  1268,   204,
      -1,    61,  1268,  1202,    -1,   743,    -1,   748,    -1,  1324,
     744,    -1,   745,   746,    -1,   745,    -1,   746,    -1,   176,
      -1,   747,    -1,   746,   747,    -1,  1211,    -1,   321,  1273,
     749,   751,    -1,   750,    -1,   750,  1308,    -1,   750,  1308,
     750,  1302,    -1,  1220,    -1,  1211,    -1,    -1,   751,   752,
      -1,   753,    -1,   754,    -1,   755,    -1,   756,    -1,   757,
      -1,   210,  1268,   750,    -1,   177,  1317,  1268,   750,    -1,
     240,  1318,  1268,   750,    -1,   240,  1317,  1268,   750,    -1,
     187,  1268,   750,    -1,    -1,   758,   759,    -1,    -1,   686,
     687,   760,   761,   451,    -1,    -1,   761,   762,    -1,   763,
      -1,   767,    -1,   775,    -1,   780,    -1,   704,    -1,   786,
      -1,   709,    -1,   721,    -1,   781,    -1,   723,    -1,   784,
      -1,   770,    -1,   725,    -1,   773,    -1,   785,    -1,   710,
      -1,   774,    -1,   472,  1268,   764,    -1,  1322,    -1,  1320,
      -1,  1318,   765,    -1,  1319,   766,    -1,  1317,    -1,  1321,
      -1,  1323,    -1,    -1,  1211,    -1,   176,    -1,    -1,  1211,
      -1,   176,    -1,   285,   209,  1268,   768,    -1,  1218,    -1,
     329,  1218,    -1,   463,  1218,    -1,   769,    -1,   285,   321,
      -1,   286,    -1,   321,    -1,   285,    -1,   431,  1278,  1195,
     771,    -1,    -1,   373,  1279,   772,    -1,   484,  1211,    -1,
    1211,    -1,   176,    -1,   333,   501,  1151,    -1,   499,  1211,
     196,  1197,    49,  1197,    -1,   776,   777,    -1,   252,   778,
      -1,   779,    -1,   329,   779,    -1,   463,   779,    -1,    -1,
     299,   232,    -1,   299,    -1,  1220,    -1,   285,   321,    -1,
     309,   285,   321,    -1,   782,   783,    -1,  1301,  1277,  1269,
      -1,  1302,  1250,    -1,   329,  1218,    -1,  1220,    -1,   414,
    1268,  1197,  1243,    -1,   209,  1265,    -1,   491,  1268,   119,
      -1,    -1,    -1,   389,   394,   451,   788,   789,    -1,    -1,
     790,    -1,   791,   451,    -1,   790,   791,   451,    -1,   696,
      -1,    -1,   686,   687,   792,   793,    -1,   686,     1,   451,
      -1,    -1,   793,   794,    -1,    45,   252,    -1,    45,   389,
      -1,    38,    -1,    46,    -1,   160,   156,    -1,   160,   158,
      -1,   211,    -1,   265,    -1,   378,    -1,   473,    -1,   318,
      -1,   243,    -1,    32,    -1,   395,    -1,   371,    -1,   198,
      -1,   345,    56,  1268,  1202,    -1,   345,    -1,   456,    -1,
     252,  1276,  1268,   797,  1204,    -1,  1301,  1276,  1268,   798,
    1204,    -1,   189,  1268,  1204,    -1,    35,  1268,  1204,    -1,
     705,    -1,   723,    -1,   800,    -1,   721,    -1,   709,    -1,
     725,    -1,   704,    -1,   799,    -1,   497,  1211,    -1,   196,
    1203,    -1,   446,  1211,    -1,   329,    -1,   463,    -1,   270,
      -1,   458,    -1,    -1,   795,    -1,   796,    -1,    -1,   795,
      -1,   796,    -1,   305,  1218,  1294,    -1,  1268,   204,    -1,
      -1,    -1,    -1,   337,   122,   805,   813,   451,   802,   814,
     803,   816,    -1,    -1,   804,   827,   451,   816,    -1,    -1,
      -1,   497,   806,   808,    -1,    -1,    55,   807,   808,    -1,
     809,    -1,   808,   809,    -1,   810,   811,   812,   504,    -1,
      -1,  1255,   357,    -1,  1255,   498,    -1,    -1,   410,  1268,
      32,    -1,   410,  1268,   110,    -1,   476,   410,  1268,    32,
      -1,   476,   410,  1268,  1218,    -1,   410,  1268,  1218,    -1,
      -1,   312,    -1,    -1,   376,   504,    -1,    -1,    -1,   109,
     451,   815,   816,   129,   109,   451,    -1,    -1,   816,   817,
      -1,   818,    -1,   821,    -1,   827,   451,    -1,   822,    -1,
     451,    -1,    -1,   504,   394,   823,   451,   819,   820,    -1,
      -1,  1107,   451,    -1,   504,   451,    -1,   504,    -1,    -1,
    1218,    -1,    -1,    -1,   825,   826,   827,    -1,    -1,   828,
     829,    -1,   827,   829,    -1,   830,    -1,   845,    -1,   850,
      -1,   854,    -1,   859,    -1,   874,    -1,   877,    -1,   885,
      -1,   881,    -1,   886,    -1,   887,    -1,   892,    -1,   906,
      -1,   910,    -1,   913,    -1,   927,    -1,   930,    -1,   933,
      -1,   936,    -1,   940,    -1,   941,    -1,   945,    -1,   955,
      -1,   958,    -1,   975,    -1,   977,    -1,   980,    -1,   984,
      -1,   990,    -1,  1002,    -1,  1010,    -1,  1011,    -1,  1014,
      -1,  1015,    -1,  1019,    -1,  1024,    -1,  1025,    -1,  1033,
      -1,  1048,    -1,  1058,    -1,  1067,    -1,  1072,    -1,  1079,
      -1,  1083,    -1,  1085,    -1,  1088,    -1,  1091,    -1,  1095,
      -1,  1120,    -1,   285,   399,    -1,     1,  1247,    -1,    -1,
       3,   831,   832,   844,    -1,   833,   835,   839,   840,   841,
    1128,    -1,  1211,   196,   834,    -1,  1211,   196,  1302,    -1,
    1211,   196,   103,   509,    -1,  1211,   196,   103,    -1,  1211,
     196,   104,   508,    -1,  1211,   196,   104,    -1,  1211,   196,
     105,    -1,  1211,   196,   162,   237,    -1,  1211,   196,   165,
     423,    -1,  1211,   196,   443,    -1,  1211,   196,   493,   276,
      -1,  1211,   196,    69,    -1,  1211,   196,   155,  1128,    -1,
    1211,   196,   153,  1200,  1128,    -1,  1211,   196,    24,    -1,
    1211,   196,    25,  1128,    -1,  1211,   196,  1178,    -1,  1211,
     196,   504,    -1,  1211,    -1,   308,    -1,   254,    -1,   252,
     299,    -1,    -1,   836,    -1,  1253,   837,   838,    -1,  1253,
     838,   837,    -1,  1253,   837,    -1,  1253,   838,    -1,    30,
    1200,    -1,   252,  1276,  1204,    -1,  1301,  1276,  1204,    -1,
     331,  1276,  1204,    -1,    -1,   197,    -1,    -1,   272,  1268,
      47,    -1,    -1,   503,   842,    -1,   843,    -1,   842,   843,
      -1,    32,    -1,    38,    -1,    46,    -1,    91,    -1,   198,
      -1,   211,    -1,   243,    -1,   263,    -1,   265,    -1,   288,
      -1,   318,    -1,   345,    56,  1268,  1202,    -1,   345,    -1,
     371,    -1,   378,    -1,   395,    -1,   473,    -1,   483,    -1,
     489,    -1,   189,  1268,  1204,    -1,    35,  1268,  1204,    -1,
     391,   482,  1150,    -1,   391,   123,  1150,    -1,   444,  1249,
    1205,    -1,    -1,   130,    -1,    -1,     5,   846,   847,   849,
      -1,  1193,   446,  1170,  1134,    -1,  1193,   848,   203,  1170,
    1134,    -1,    94,  1211,   446,  1211,  1243,  1134,    -1,    -1,
     446,  1194,    -1,    -1,   131,    -1,    -1,    10,   851,   852,
      -1,  1211,  1237,   853,    -1,  1164,    57,  1238,   853,    -1,
      -1,   376,  1192,    -1,    -1,    18,   855,   856,    -1,   857,
      -1,   856,   857,    -1,  1180,   446,   858,  1180,    -1,    -1,
     339,   446,    -1,    -1,    51,   860,   861,   873,    -1,   862,
    1203,   863,   868,   871,   872,    -1,    -1,   422,    -1,   424,
      -1,   271,    -1,    -1,    -1,   497,   864,   865,    -1,   866,
      -1,   865,   866,    -1,   867,   308,    -1,   867,   811,  1194,
      -1,    -1,  1255,   357,    -1,  1255,    87,    -1,  1255,   498,
      -1,    -1,   869,  1267,  1211,    -1,   869,   870,    -1,   869,
       6,  1278,  1211,    -1,   376,    -1,   203,    -1,   460,    -1,
     308,    -1,    -1,  1305,   824,    -1,    -1,   294,   824,    -1,
      -1,   132,    -1,    -1,    52,   875,   876,    -1,  1202,    -1,
     876,  1202,    -1,    -1,    60,   878,   879,    -1,  1175,   880,
      -1,   879,  1175,   880,    -1,    -1,  1312,    -1,  1312,  1261,
     362,    -1,  1299,   287,   380,    -1,  1299,   262,    -1,    -1,
      74,   882,   883,   884,    -1,  1170,  1303,  1164,  1134,    -1,
      -1,   133,    -1,    71,    -1,    88,    -1,    -1,   111,   888,
     889,   891,    -1,  1175,  1284,  1147,    -1,   454,   890,    -1,
    1175,    -1,   890,  1175,    -1,    -1,   134,    -1,    -1,   119,
     893,   894,   905,    -1,  1202,   487,  1131,    -1,  1202,   488,
    1131,    -1,  1202,   485,  1131,    -1,  1202,   486,  1131,    -1,
    1193,   898,   902,  1131,    -1,   895,  1131,    -1,  1194,   503,
     903,  1131,    -1,   897,    -1,    -1,   895,   896,   897,    -1,
    1194,   836,   899,   840,   901,    -1,    -1,   484,  1178,    -1,
     484,   504,    -1,   484,   335,    -1,   484,    96,    -1,    -1,
     484,   900,    -1,    96,    -1,    97,    -1,    -1,   503,   903,
      -1,    -1,   298,    -1,   904,    -1,   903,   904,    -1,    38,
      -1,    45,   252,    -1,    45,   389,    -1,    46,    -1,    91,
      -1,   160,   156,    -1,   160,   158,    -1,   211,    -1,   265,
      -1,   318,    -1,   378,    -1,   473,    -1,   189,  1268,  1204,
      -1,    35,  1268,  1204,    -1,   391,   482,  1150,    -1,   391,
     123,  1150,    -1,    -1,   135,    -1,    -1,   121,   907,   908,
     909,    -1,  1194,   228,  1170,  1134,    -1,  1194,   228,  1194,
     203,  1170,  1134,    -1,  1194,    49,  1194,   203,  1170,  1134,
      -1,  1194,   228,  1194,   203,  1171,   361,  1171,  1134,    -1,
    1194,    49,  1194,   203,  1171,   361,  1171,  1134,    -1,    -1,
     136,    -1,    -1,   152,   911,   912,    -1,   256,   863,    -1,
      -1,   163,   914,   915,   926,    -1,   916,   918,    -1,   917,
      -1,   916,    17,   917,    -1,  1152,    -1,   464,    -1,   453,
      -1,   919,   921,    -1,   919,    -1,   920,    -1,   919,   920,
      -1,   922,   824,    -1,   501,   316,   824,    -1,   501,   923,
      -1,   922,   501,   923,    -1,   924,    -1,   923,    17,   924,
      -1,  1153,   925,    -1,    21,    -1,   464,    -1,   453,    -1,
      -1,   442,  1152,    -1,    -1,   137,    -1,    -1,   168,   928,
     929,    -1,    -1,   340,    -1,   199,    -1,   324,   101,    -1,
     324,    -1,   394,    -1,   323,    -1,    -1,   195,   931,   932,
      -1,  1191,    -1,    -1,   202,   934,   935,    -1,  1215,    -1,
      -1,   205,   937,   938,    -1,  1295,  1179,   939,    -1,    -1,
     114,  1279,  1211,    -1,   206,    -1,    -1,   215,   942,  1151,
    1293,   943,   944,    -1,   824,   128,   824,    -1,   128,   824,
      -1,   824,    -1,    -1,   139,    -1,    -1,   222,   946,   947,
      -1,  1191,   948,   949,   950,   954,    -1,    -1,  1299,   175,
      -1,    -1,     9,  1295,   498,    -1,   953,  1295,   498,    -1,
      -1,   365,   951,    -1,   952,    -1,   951,   952,    -1,   953,
    1259,    49,  1194,    -1,    12,    -1,    15,    -1,   301,    -1,
      16,    -1,   302,    -1,   277,    -1,   278,    -1,    -1,  1293,
    1295,   110,    -1,    -1,   224,   956,   957,    -1,  1176,    -1,
     957,  1176,    -1,    -1,   227,   959,   960,    -1,   961,   962,
      -1,  1211,    -1,  1222,    -1,  1225,    -1,   963,   965,    -1,
     963,    -1,   965,    -1,   966,    -1,    -1,   436,   964,   967,
      -1,   365,   969,    -1,    92,  1200,   446,  1201,   973,    -1,
     968,    -1,   967,   968,    -1,  1200,   188,    -1,    57,   973,
      -1,     9,    -1,   241,    -1,   468,    -1,  1200,   973,    -1,
     970,    -1,   969,   970,    -1,    57,    49,  1200,   973,    -1,
     971,   972,    -1,    -1,     9,    -1,   241,    -1,   177,    -1,
     468,    -1,  1200,    49,  1201,   973,    -1,    -1,   973,   974,
      -1,    37,  1266,  1194,    -1,     8,  1266,  1194,    -1,    -1,
     269,   976,  1050,    -1,    -1,   273,   978,   979,    -1,  1194,
     446,  1191,    -1,    94,  1194,   446,  1191,    -1,    -1,   275,
     981,   982,   983,    -1,  1194,    49,  1170,  1134,    -1,  1194,
      49,  1194,   203,  1170,  1134,    -1,    -1,   140,    -1,    -1,
     311,   985,   986,    -1,   987,   988,  1174,   989,    -1,   986,
     987,   988,  1174,   989,    -1,   225,    -1,   317,    -1,   233,
      -1,   170,    -1,    -1,   404,  1299,   637,    -1,    -1,  1299,
     287,   380,    -1,  1299,   262,    -1,   379,    -1,    -1,   324,
     991,   992,    -1,   996,   997,    -1,    -1,   997,   993,   824,
     994,    -1,   997,   995,    -1,    -1,   141,    -1,   141,    -1,
     451,    -1,  1180,    -1,  1180,   442,  1180,    -1,    -1,  1203,
     445,    -1,   190,    -1,   998,   481,   999,    -1,   998,   499,
    1000,    -1,    -1,  1299,   439,  1125,    -1,   168,    -1,  1151,
      -1,  1001,    -1,  1000,     8,  1001,    -1,  1211,   196,  1194,
      49,  1194,   481,  1151,    -1,    -1,   349,  1003,  1004,  1009,
      -1,  1175,  1240,  1284,  1005,  1006,  1007,  1008,    -1,    -1,
     228,  1211,    -1,    -1,   217,   262,    -1,  1299,   262,    -1,
    1299,   236,   262,    -1,  1299,   287,   262,    -1,  1299,   216,
     262,    -1,  1299,   500,    -1,    -1,   237,  1268,  1211,    -1,
    1147,    -1,  1141,    -1,    -1,   143,    -1,   350,    -1,    -1,
     360,  1012,  1013,    -1,  1172,  1123,    -1,   374,    -1,    -1,
     375,  1016,  1017,  1018,    -1,  1175,  1284,  1005,  1140,    -1,
      -1,   144,    -1,    -1,   381,  1020,  1021,  1023,    -1,  1172,
    1123,  1022,  1147,    -1,    -1,  1299,   262,    -1,  1299,   287,
     262,    -1,    -1,   145,    -1,   385,    -1,    -1,   393,  1026,
    1027,  1032,    -1,  1173,  1028,  1029,  1030,    -1,     9,  1173,
    1029,   501,  1152,   824,    -1,    -1,   499,  1211,    -1,    -1,
     129,   824,    -1,  1031,    -1,  1031,  1030,    -1,   501,  1151,
     824,    -1,    -1,   146,    -1,    -1,   403,  1034,  1035,    -1,
    1038,    -1,  1039,    -1,  1042,    -1,  1043,    -1,  1044,    -1,
    1046,    -1,   309,    -1,   307,    -1,   482,    -1,   123,    -1,
     153,  1200,   446,  1200,    -1,  1208,    31,  1040,    -1,  1041,
      -1,  1040,  1041,    -1,    38,  1036,    -1,    46,  1036,    -1,
     211,  1036,    -1,   265,  1036,    -1,   378,  1036,    -1,   473,
    1036,    -1,   243,  1036,    -1,   318,  1036,    -1,  1191,   446,
     152,  1199,    -1,  1191,   446,  1194,    -1,  1191,  1037,    49,
    1194,    -1,  1045,    -1,  1044,  1045,    -1,  1177,   446,  1036,
      -1,  1047,    -1,  1046,  1047,    -1,  1191,   446,   464,    -1,
    1191,   446,   453,    -1,    -1,   412,  1049,  1050,    -1,    -1,
    1209,  1052,  1054,  1055,  1051,  1056,  1057,    -1,    -1,  1052,
    1279,   717,  1270,  1053,    -1,    -1,  1053,  1215,    -1,    -1,
    1315,  1264,    -1,    -1,  1300,  1268,  1184,    -1,    -1,   497,
    1174,    -1,   225,   337,  1268,   996,    -1,    -1,   203,  1174,
      -1,   317,   337,  1268,   996,    -1,    -1,   421,  1059,  1060,
    1066,    -1,  1175,  1062,  1061,  1147,    -1,    -1,  1299,  1314,
    1164,    -1,    -1,   237,  1268,  1063,  1211,    -1,   177,    -1,
     240,    -1,  1157,    -1,  1241,  1158,    -1,  1241,  1159,    -1,
    1241,  1160,    -1,  1241,  1161,    -1,  1064,    -1,  1065,    -1,
     290,  1157,    -1,   293,    -1,    -1,   147,    -1,    -1,   426,
     387,  1068,  1069,    -1,   426,  1071,    -1,    -1,   376,  1194,
      -1,   203,  1194,    -1,  1299,   161,  1291,  1070,    -1,  1299,
     289,  1291,  1070,    -1,    -1,  1194,    -1,   256,    -1,   416,
      -1,   510,    -1,   346,    -1,    -1,   427,  1073,  1074,  1078,
      -1,  1075,   228,  1211,  1077,  1137,    -1,  1076,    -1,  1075,
    1076,    -1,  1194,    -1,   112,  1255,   410,    -1,   112,  1255,
    1194,    -1,    -1,  1299,   330,  1268,  1211,    -1,    -1,   148,
      -1,    -1,   430,  1080,  1081,  1082,    -1,  1193,   196,  1170,
    1134,    -1,  1193,   196,  1194,   203,  1170,  1134,    -1,    94,
    1211,   196,  1211,  1243,  1134,    -1,    -1,   149,    -1,   432,
    1084,    -1,    -1,   336,    -1,    -1,   438,  1086,  1087,    -1,
    1176,    -1,  1087,  1176,    -1,    -1,   469,  1089,  1090,    -1,
    1211,   196,  1200,   446,  1201,    -1,    -1,   475,  1092,  1093,
      -1,  1175,  1094,    -1,    -1,   351,    -1,   353,    -1,    -1,
     480,  1096,  1097,  1106,    -1,  1211,  1098,  1101,  1077,  1105,
    1137,    -1,    -1,   112,  1255,  1099,    -1,  1100,    -1,  1099,
     313,  1100,    -1,  1235,  1200,    -1,   228,  1102,    -1,  1101,
    1102,    -1,  1211,  1103,  1104,    -1,    -1,   113,  1263,  1211,
      -1,    -1,    95,  1263,  1211,    -1,    -1,   436,  1263,  1211,
      -1,    -1,   150,    -1,    -1,   492,  1108,  1109,    -1,  1110,
      -1,  1113,    -1,  1117,    -1,  1118,    -1,  1111,  1249,  1290,
    1304,  1282,  1279,  1112,    -1,    -1,   204,    -1,  1174,    -1,
     225,    -1,   317,    -1,   233,    -1,   170,    -1,  1261,   107,
    1279,  1114,    -1,  1115,    -1,  1114,  1115,    -1,  1181,    -1,
       9,   338,    -1,     9,  1116,  1215,    -1,    -1,   358,    -1,
     358,   306,    -1,   306,    -1,  1111,    37,   367,  1211,    -1,
    1119,    -1,   166,    -1,   127,    -1,    -1,   507,  1121,  1122,
    1127,    -1,  1172,  1123,  1124,  1022,  1126,    -1,    -1,   196,
    1207,    -1,    -1,  1125,  1248,  1204,  1272,    -1,  1125,  1248,
    1178,    -1,  1125,  1248,   321,    -1,    37,    -1,     8,    -1,
    1147,    -1,  1144,    -1,    -1,   151,    -1,  1129,  1130,    -1,
      -1,   165,   824,    -1,    -1,   294,   824,    -1,  1132,  1133,
      -1,    -1,   165,   824,    -1,    -1,   294,   824,    -1,  1135,
    1136,    -1,    -1,   411,   824,    -1,    -1,   297,   824,    -1,
    1138,  1139,    -1,    -1,   461,   824,    -1,    -1,   296,   824,
      -1,  1142,  1143,    -1,  1142,    -1,  1142,  1143,    -1,  1142,
      -1,  1143,    -1,   129,   824,    -1,   291,   824,    -1,  1145,
    1146,    -1,  1145,    -1,  1146,    -1,   157,   824,    -1,   292,
     824,    -1,  1148,  1149,    -1,    -1,   231,   824,    -1,    -1,
     295,   824,    -1,    -1,  1206,  1313,    -1,  1152,    -1,  1153,
      -1,    -1,  1154,  1155,    -1,  1156,    -1,  1155,   232,    -1,
    1155,  1156,    -1,  1194,    -1,   462,    -1,   448,    -1,   463,
      -1,   458,    -1,   459,    -1,   450,    -1,   169,    -1,  1157,
      -1,  1158,    -1,  1159,    -1,  1160,    -1,  1161,    -1,   293,
      -1,   290,    -1,    20,    -1,   313,    -1,   308,    -1,   301,
      -1,    12,    -1,    13,    -1,    14,    -1,   332,    -1,   284,
      -1,   452,    -1,   159,  1295,    -1,   455,    -1,   207,    -1,
     457,    -1,   246,    -1,   208,    -1,   247,    -1,  1164,    -1,
    1162,  1163,  1164,    -1,    -1,    70,    -1,   398,    -1,  1164,
     463,  1165,    -1,  1164,   458,  1165,    -1,  1165,    -1,  1165,
     459,  1166,    -1,  1165,   450,  1166,    -1,  1166,    -1,  1167,
     169,  1166,    -1,  1167,    -1,   463,  1168,    -1,   458,  1168,
      -1,  1168,    -1,   462,  1164,   448,    -1,  1197,    -1,   251,
      -1,   251,  1306,   504,    -1,   253,    -1,   253,  1306,   504,
      -1,   322,    -1,   322,  1306,   504,    -1,  1171,    -1,  1170,
    1171,    -1,  1192,  1243,    -1,  1215,    -1,  1215,    -1,  1175,
      -1,  1174,  1175,    -1,   504,    -1,   504,    -1,  1178,    -1,
    1177,  1178,    -1,   271,    -1,    -1,  1179,  1180,    -1,  1181,
      -1,  1215,    -1,  1182,    -1,  1182,  1306,  1182,    -1,   256,
      -1,  1184,    -1,  1183,  1184,    -1,  1215,    -1,   504,    -1,
    1187,    -1,  1186,  1187,    -1,   504,    -1,  1184,    -1,   256,
      -1,   504,    -1,   504,    -1,  1192,    -1,  1191,  1192,    -1,
    1213,    -1,  1223,    -1,     6,  1278,  1212,    -1,  1194,    -1,
    1193,  1194,    -1,  1211,    -1,  1222,    -1,  1225,    -1,  1169,
      -1,   245,  1212,    -1,   245,  1223,    -1,   245,  1225,    -1,
       6,  1278,  1198,  1199,    -1,     6,  1278,  1212,    -1,   271,
      -1,  1197,    -1,  1195,  1197,    -1,  1211,    -1,  1223,    -1,
    1225,    -1,  1211,    -1,  1223,    -1,  1225,    -1,  1169,    -1,
     245,  1212,    -1,   245,  1223,    -1,   245,  1225,    -1,   340,
      -1,   152,    -1,  1212,    -1,   256,    -1,  1211,    -1,  1223,
      -1,  1211,    -1,  1222,    -1,  1211,    -1,   256,    -1,  1211,
      -1,   256,    -1,  1225,    -1,  1208,    -1,  1218,    -1,   510,
      -1,  1208,    -1,  1220,    -1,  1208,    -1,  1218,    -1,  1211,
      -1,  1222,    -1,  1225,    -1,  1210,    -1,  1210,    -1,  1215,
      -1,  1215,  1216,    -1,  1212,    -1,  1215,  1216,  1217,    -1,
    1215,  1216,    -1,  1215,  1217,    -1,  1215,    -1,  1214,    -1,
    1169,    -1,  1215,  1216,  1217,    -1,  1215,  1216,    -1,  1215,
    1217,    -1,  1215,    -1,   504,    -1,   504,  1306,  1215,    -1,
     462,  1162,   448,    -1,   462,  1164,   449,   448,    -1,   462,
    1164,   449,  1164,   448,    -1,   256,    -1,   256,    -1,   256,
      -1,   256,    -1,   416,    -1,   510,    -1,   346,    -1,   212,
      -1,   266,    -1,   460,    -1,  1223,    -1,     9,  1224,    -1,
    1224,    -1,  1223,   447,  1224,    -1,   256,    -1,   416,    -1,
     510,    -1,   346,    -1,   212,    -1,   266,    -1,   460,    -1,
    1226,  1229,    -1,  1227,   462,  1196,   448,  1229,    -1,  1228,
     462,  1162,   448,  1229,    -1,   470,   462,  1231,   448,  1229,
      -1,   303,   462,  1232,   448,    -1,   258,   462,  1233,   448,
    1229,    -1,   259,   462,  1233,   448,  1229,    -1,   260,   462,
    1233,   448,  1229,    -1,   201,  1230,    -1,   495,  1230,    -1,
      99,    -1,   502,    -1,   490,    -1,   264,    -1,   377,    -1,
      82,    -1,   428,    -1,   429,    -1,    -1,   462,  1164,   449,
     448,    -1,   462,  1164,   449,  1164,   448,    -1,    -1,   462,
    1162,   448,    -1,   462,   448,    -1,  1196,    -1,  1196,  1163,
     241,    -1,  1196,  1163,   468,    -1,  1196,    -1,  1196,  1163,
    1196,    -1,  1164,    -1,  1164,  1163,  1184,    -1,    -1,    -1,
       9,    -1,    -1,  1315,    -1,    -1,   223,    -1,    -1,   223,
    1239,    -1,    -1,   446,  1201,    -1,    -1,   285,    -1,   334,
      -1,    -1,   290,    -1,    -1,   312,    -1,   290,   312,    -1,
      -1,   386,  1244,    -1,    -1,   272,  1268,  1245,    -1,    34,
      -1,   281,    -1,   282,    -1,   283,    -1,   344,    -1,   466,
      -1,   467,    -1,   471,    -1,    -1,   400,  1256,    -1,   451,
      -1,     3,    -1,     5,    -1,    10,    -1,    18,    -1,    51,
      -1,    52,    -1,    60,    -1,    71,    -1,    74,    -1,    88,
      -1,   111,    -1,   119,    -1,   121,    -1,   128,    -1,   152,
      -1,   163,    -1,   168,    -1,   195,    -1,   202,    -1,   205,
      -1,   206,    -1,   215,    -1,   222,    -1,   224,    -1,   227,
      -1,   269,    -1,   273,    -1,   275,    -1,   285,    -1,   311,
      -1,   324,    -1,   349,    -1,   360,    -1,   375,    -1,   381,
      -1,   385,    -1,   393,    -1,   403,    -1,   412,    -1,   421,
      -1,   426,    -1,   427,    -1,   430,    -1,   432,    -1,   438,
      -1,   469,    -1,   475,    -1,   480,    -1,   507,    -1,   130,
      -1,   131,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,   137,    -1,   139,    -1,   140,    -1,   141,
      -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,   147,
      -1,   148,    -1,   149,    -1,   150,    -1,   151,    -1,    -1,
       7,    -1,    -1,     8,    -1,    -1,    22,    -1,    -1,    23,
      -1,    -1,    26,    -1,    -1,    30,    -1,    -1,    39,    -1,
      -1,    49,    -1,    -1,    56,    -1,    -1,    57,    -1,    -1,
      86,    -1,    -1,   102,    -1,    -1,   454,    -1,    -1,   188,
      -1,    -1,   196,    -1,    -1,   218,    -1,    -1,   314,    -1,
     218,   314,    -1,    -1,   221,    -1,    -1,   456,    -1,    -1,
     228,    -1,    -1,   232,    -1,    -1,   232,    -1,    22,    -1,
      -1,   237,    -1,    -1,   242,    -1,   384,    -1,    -1,   252,
      -1,   254,    -1,    -1,   248,  1268,    -1,   249,  1250,    -1,
      -1,   254,    -1,    -1,   272,    -1,    -1,   299,    -1,    -1,
     299,    -1,   300,    -1,    -1,   306,    -1,    -1,   309,    -1,
      -1,   423,   232,    -1,   423,    -1,   232,    -1,    -1,   316,
      -1,    -1,   337,    -1,    -1,   340,    -1,    -1,   351,    -1,
      -1,   384,    -1,    -1,   405,    -1,    -1,   406,    -1,    -1,
     405,    -1,   405,   232,    -1,    -1,   410,    -1,    -1,   418,
      -1,    -1,   423,    -1,    -1,   437,    -1,    -1,   441,    -1,
      -1,   445,    -1,    -1,   446,    -1,    -1,   446,    -1,   497,
      -1,    -1,   501,    -1,    -1,   501,   403,   446,    -1,    -1,
     503,    -1,    63,   401,    -1,   401,    -1,    66,    -1,    64,
      -1,    67,    -1,    65,    -1,   452,    -1,   159,    -1,   165,
      -1,   161,    -1,   165,    -1,   461,    -1,   218,    -1,   306,
      -1,   418,    -1,   308,    -1,   252,    -1,   254,    -1,   351,
      -1,   353,    -1,    57,    -1,   505,    -1,   351,  1268,    -1,
     353,  1250,    -1,   356,    -1,   474,    -1,   252,    -1,   254,
      -1,   410,    -1,   244,    -1,   503,   124,    -1,   124,    -1,
     340,    63,   401,    -1,    63,   401,    -1,   401,    -1,   116,
      -1,   106,    -1,    89,   210,    -1,    54,    -1,    89,   187,
      -1,    53,    -1,   321,   210,    -1,   325,    -1,   321,   187,
      -1,   326,    -1,   366,   210,    -1,   383,    -1,   366,   187,
      -1,   382,    -1,    89,  1268,    -1,    90,  1250,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1343,  1343,  1343,  1375,  1376,  1380,  1381,  1385,  1386,
    1390,  1390,  1413,  1420,  1427,  1433,  1434,  1435,  1439,  1440,
    1444,  1468,  1469,  1473,  1507,  1513,  1525,  1499,  1535,  1534,
    1572,  1607,  1608,  1612,  1613,  1616,  1617,  1621,  1630,  1639,
    1640,  1644,  1648,  1657,  1658,  1666,  1667,  1677,  1678,  1682,
    1683,  1684,  1685,  1686,  1693,  1692,  1705,  1706,  1709,  1710,
    1724,  1723,  1733,  1734,  1735,  1736,  1740,  1741,  1745,  1746,
    1747,  1748,  1752,  1759,  1766,  1773,  1784,  1788,  1792,  1796,
    1803,  1804,  1811,  1810,  1821,  1822,  1823,  1830,  1831,  1835,
    1839,  1851,  1855,  1856,  1861,  1864,  1871,  1876,  1887,  1900,
    1901,  1909,  1910,  1914,  1915,  1916,  1917,  1918,  1919,  1920,
    1921,  1922,  1923,  1924,  1925,  1933,  1932,  1951,  1961,  1974,
    1982,  1985,  1986,  1990,  2000,  2016,  2015,  2039,  2045,  2051,
    2057,  2063,  2069,  2079,  2083,  2090,  2094,  2099,  2098,  2109,
    2113,  2120,  2121,  2122,  2123,  2124,  2125,  2132,  2147,  2150,
    2157,  2165,  2169,  2180,  2200,  2208,  2219,  2220,  2226,  2247,
    2248,  2252,  2256,  2277,  2300,  2382,  2385,  2394,  2413,  2429,
    2447,  2465,  2482,  2498,  2499,  2506,  2507,  2516,  2517,  2528,
    2529,  2534,  2533,  2554,  2564,  2565,  2569,  2570,  2571,  2572,
    2573,  2574,  2575,  2576,  2577,  2578,  2579,  2580,  2581,  2588,
    2594,  2604,  2617,  2630,  2646,  2647,  2648,  2649,  2652,  2653,
    2659,  2660,  2664,  2668,  2669,  2674,  2677,  2678,  2685,  2693,
    2694,  2695,  2702,  2729,  2740,  2747,  2749,  2750,  2756,  2756,
    2763,  2768,  2773,  2780,  2781,  2782,  2786,  2797,  2798,  2802,
    2807,  2812,  2817,  2828,  2839,  2849,  2857,  2858,  2859,  2865,
    2876,  2883,  2884,  2890,  2898,  2899,  2900,  2906,  2907,  2908,
    2915,  2916,  2920,  2921,  2927,  2955,  2956,  2957,  2958,  2965,
    2964,  2980,  2981,  2985,  2988,  2989,  2995,  2996,  3004,  3005,
    3013,  3014,  3018,  3039,  3038,  3055,  3062,  3066,  3072,  3073,
    3077,  3087,  3102,  3103,  3104,  3105,  3106,  3107,  3108,  3109,
    3110,  3117,  3124,  3124,  3124,  3130,  3150,  3184,  3215,  3216,
    3223,  3224,  3228,  3229,  3236,  3247,  3252,  3263,  3264,  3268,
    3269,  3275,  3286,  3304,  3305,  3309,  3310,  3311,  3315,  3322,
    3329,  3338,  3350,  3402,  3417,  3418,  3422,  3434,  3476,  3478,
    3477,  3493,  3496,  3496,  3514,  3515,  3517,  3521,  3523,  3522,
    3557,  3570,  3578,  3583,  3589,  3598,  3608,  3611,  3623,  3624,
    3625,  3626,  3630,  3634,  3638,  3642,  3646,  3650,  3654,  3658,
    3662,  3666,  3670,  3674,  3678,  3689,  3690,  3694,  3695,  3699,
    3700,  3701,  3705,  3706,  3710,  3736,  3740,  3749,  3753,  3762,
    3763,  3764,  3765,  3766,  3767,  3768,  3769,  3770,  3771,  3772,
    3773,  3774,  3775,  3782,  3806,  3834,  3837,  3846,  3871,  3882,
    3883,  3887,  3891,  3895,  3899,  3903,  3907,  3911,  3915,  3919,
    3923,  3927,  3931,  3935,  3940,  3945,  3949,  3953,  3961,  3965,
    3969,  3977,  3981,  3985,  3989,  3993,  3997,  4001,  4005,  4009,
    4017,  4025,  4029,  4033,  4037,  4041,  4045,  4053,  4054,  4058,
    4059,  4065,  4071,  4083,  4101,  4102,  4111,  4135,  4136,  4139,
    4140,  4147,  4171,  4172,  4189,  4190,  4193,  4194,  4201,  4202,
    4207,  4218,  4229,  4240,  4251,  4280,  4279,  4288,  4289,  4293,
    4294,  4297,  4298,  4311,  4324,  4345,  4354,  4368,  4370,  4369,
    4389,  4391,  4390,  4406,  4408,  4407,  4418,  4419,  4426,  4425,
    4454,  4455,  4456,  4463,  4469,  4473,  4474,  4480,  4487,  4488,
    4489,  4493,  4500,  4501,  4505,  4515,  4566,  4574,  4582,  4598,
    4599,  4602,  4603,  4608,  4609,  4610,  4611,  4612,  4616,  4627,
    4638,  4649,  4660,  4670,  4671,  4676,  4675,  4696,  4697,  4701,
    4702,  4703,  4704,  4705,  4706,  4707,  4708,  4709,  4710,  4711,
    4712,  4713,  4714,  4715,  4716,  4717,  4721,  4728,  4732,  4736,
    4737,  4738,  4742,  4746,  4753,  4756,  4761,  4768,  4771,  4776,
    4783,  4790,  4799,  4804,  4809,  4816,  4817,  4818,  4819,  4823,
    4831,  4832,  4833,  4840,  4844,  4851,  4859,  4863,  4871,  4875,
    4876,  4880,  4886,  4887,  4888,  4892,  4902,  4906,  4913,  4920,
    4921,  4925,  4930,  4940,  4948,  4956,  4964,  4966,  4965,  4986,
    4987,  4991,  4992,  4996,  4998,  4997,  5054,  5072,  5073,  5077,
    5081,  5085,  5089,  5093,  5097,  5101,  5105,  5109,  5113,  5117,
    5121,  5125,  5129,  5133,  5137,  5141,  5146,  5150,  5154,  5159,
    5164,  5169,  5174,  5175,  5176,  5177,  5178,  5179,  5180,  5181,
    5182,  5189,  5194,  5203,  5204,  5208,  5209,  5214,  5217,  5221,
    5229,  5232,  5236,  5244,  5255,  5263,  5265,  5275,  5264,  5302,
    5302,  5335,  5339,  5338,  5352,  5351,  5371,  5372,  5377,  5384,
    5386,  5390,  5400,  5402,  5410,  5418,  5426,  5455,  5486,  5488,
    5498,  5503,  5526,  5528,  5527,  5563,  5564,  5568,  5569,  5570,
    5587,  5588,  5599,  5598,  5648,  5649,  5653,  5701,  5714,  5717,
    5736,  5741,  5735,  5754,  5754,  5784,  5791,  5792,  5793,  5794,
    5795,  5796,  5797,  5798,  5799,  5800,  5801,  5802,  5803,  5804,
    5805,  5806,  5807,  5808,  5809,  5810,  5811,  5812,  5813,  5814,
    5815,  5816,  5817,  5818,  5819,  5820,  5821,  5822,  5823,  5824,
    5825,  5826,  5827,  5828,  5829,  5830,  5831,  5832,  5833,  5834,
    5835,  5836,  5837,  5838,  5839,  5840,  5854,  5866,  5865,  5874,
    5880,  5884,  5888,  5893,  5898,  5903,  5908,  5912,  5916,  5920,
    5924,  5929,  5933,  5937,  5941,  5945,  5949,  5953,  5960,  5961,
    5968,  5969,  5973,  5974,  5978,  5979,  5980,  5981,  5982,  5986,
    5990,  5991,  5994,  5995,  5998,  5999,  6005,  6006,  6010,  6011,
    6015,  6019,  6023,  6027,  6031,  6035,  6039,  6043,  6047,  6051,
    6055,  6059,  6063,  6067,  6071,  6075,  6079,  6083,  6087,  6091,
    6095,  6099,  6103,  6107,  6114,  6118,  6129,  6128,  6137,  6141,
    6145,  6151,  6152,  6159,  6163,  6174,  6173,  6182,  6186,  6198,
    6199,  6207,  6206,  6215,  6216,  6220,  6226,  6226,  6233,  6232,
    6242,  6262,  6266,  6271,  6276,  6297,  6301,  6300,  6317,  6318,
    6323,  6331,  6355,  6357,  6361,  6370,  6383,  6386,  6390,  6394,
    6417,  6418,  6422,  6423,  6428,  6431,  6439,  6443,  6451,  6455,
    6466,  6465,  6473,  6477,  6488,  6487,  6495,  6500,  6508,  6509,
    6510,  6511,  6512,  6520,  6519,  6528,  6535,  6539,  6549,  6560,
    6578,  6577,  6586,  6590,  6594,  6599,  6607,  6611,  6622,  6621,
    6631,  6635,  6639,  6643,  6647,  6651,  6652,  6661,  6663,  6662,
    6670,  6679,  6686,  6690,  6694,  6698,  6708,  6710,  6714,  6715,
    6718,  6720,  6727,  6728,  6732,  6733,  6738,  6742,  6746,  6750,
    6754,  6758,  6762,  6766,  6770,  6774,  6778,  6782,  6786,  6790,
    6794,  6798,  6805,  6809,  6820,  6819,  6828,  6832,  6836,  6840,
    6844,  6851,  6855,  6866,  6865,  6873,  6893,  6892,  6916,  6924,
    6925,  6930,  6941,  6952,  6966,  6970,  6977,  6978,  6983,  6992,
    7001,  7006,  7015,  7016,  7021,  7083,  7084,  7085,  7089,  7090,
    7094,  7098,  7109,  7108,  7120,  7121,  7139,  7153,  7175,  7197,
    7217,  7243,  7242,  7250,  7261,  7260,  7269,  7282,  7281,  7294,
    7303,  7307,  7318,  7331,  7330,  7339,  7343,  7347,  7354,  7358,
    7369,  7368,  7376,  7384,  7385,  7389,  7390,  7391,  7396,  7399,
    7406,  7410,  7418,  7425,  7426,  7427,  7428,  7429,  7430,  7431,
    7436,  7439,  7449,  7448,  7456,  7463,  7476,  7475,  7484,  7488,
    7492,  7496,  7503,  7504,  7505,  7506,  7513,  7512,  7526,  7536,
    7545,  7546,  7550,  7551,  7552,  7553,  7554,  7555,  7559,  7560,
    7564,  7569,  7576,  7577,  7578,  7579,  7580,  7584,  7612,  7615,
    7622,  7626,  7636,  7635,  7648,  7647,  7655,  7659,  7670,  7669,
    7678,  7682,  7689,  7693,  7704,  7703,  7711,  7732,  7756,  7757,
    7758,  7759,  7763,  7764,  7768,  7769,  7770,  7771,  7783,  7782,
    7793,  7799,  7798,  7809,  7817,  7825,  7832,  7836,  7849,  7856,
    7868,  7871,  7876,  7880,  7891,  7898,  7899,  7903,  7904,  7907,
    7908,  7913,  7924,  7923,  7932,  7959,  7960,  7965,  7968,  7972,
    7976,  7980,  7984,  7988,  7995,  7996,  8000,  8001,  8005,  8009,
    8019,  8030,  8029,  8037,  8047,  8058,  8057,  8066,  8073,  8077,
    8088,  8087,  8099,  8108,  8111,  8115,  8122,  8126,  8136,  8148,
    8147,  8156,  8160,  8169,  8170,  8175,  8178,  8186,  8190,  8197,
    8205,  8209,  8220,  8219,  8233,  8234,  8235,  8236,  8237,  8238,
    8242,  8243,  8247,  8248,  8254,  8263,  8270,  8271,  8275,  8279,
    8283,  8287,  8291,  8295,  8299,  8303,  8312,  8316,  8325,  8334,
    8335,  8339,  8348,  8349,  8353,  8357,  8368,  8367,  8376,  8375,
    8406,  8409,  8429,  8430,  8433,  8434,  8442,  8443,  8448,  8453,
    8463,  8479,  8484,  8494,  8511,  8510,  8520,  8533,  8536,  8544,
    8547,  8552,  8557,  8565,  8566,  8567,  8568,  8569,  8570,  8574,
    8582,  8583,  8587,  8591,  8602,  8601,  8611,  8624,  8627,  8631,
    8635,  8643,  8655,  8658,  8665,  8666,  8667,  8668,  8675,  8674,
    8683,  8690,  8691,  8695,  8696,  8697,  8701,  8702,  8706,  8710,
    8721,  8720,  8729,  8733,  8737,  8744,  8748,  8758,  8769,  8770,
    8777,  8776,  8784,  8791,  8804,  8803,  8811,  8825,  8824,  8832,
    8845,  8847,  8848,  8856,  8855,  8864,  8872,  8873,  8878,  8879,
    8884,  8891,  8892,  8897,  8904,  8905,  8909,  8910,  8914,  8915,
    8919,  8923,  8934,  8933,  8942,  8943,  8944,  8945,  8949,  8976,
    8979,  8991,  9001,  9006,  9011,  9016,  9024,  9062,  9063,  9067,
    9105,  9115,  9138,  9139,  9140,  9141,  9145,  9176,  9185,  9186,
    9193,  9192,  9204,  9214,  9215,  9220,  9223,  9227,  9231,  9238,
    9239,  9243,  9244,  9248,  9252,  9264,  9267,  9268,  9277,  9278,
    9287,  9290,  9291,  9300,  9301,  9312,  9315,  9316,  9325,  9326,
    9338,  9341,  9343,  9353,  9354,  9366,  9367,  9371,  9372,  9373,
    9377,  9386,  9397,  9398,  9399,  9403,  9412,  9423,  9428,  9429,
    9438,  9439,  9450,  9454,  9464,  9471,  9478,  9478,  9488,  9489,
    9490,  9494,  9503,  9504,  9506,  9507,  9508,  9509,  9510,  9512,
    9513,  9514,  9515,  9516,  9517,  9519,  9520,  9521,  9523,  9524,
    9525,  9526,  9527,  9530,  9531,  9535,  9536,  9540,  9541,  9545,
    9546,  9550,  9554,  9560,  9564,  9570,  9571,  9572,  9576,  9577,
    9578,  9582,  9583,  9584,  9588,  9592,  9596,  9597,  9598,  9601,
    9602,  9612,  9624,  9633,  9649,  9658,  9674,  9689,  9690,  9695,
    9704,  9710,  9730,  9734,  9755,  9796,  9810,  9811,  9816,  9822,
    9823,  9828,  9840,  9841,  9842,  9849,  9860,  9861,  9865,  9873,
    9881,  9885,  9892,  9901,  9902,  9908,  9922,  9939,  9943,  9950,
    9951,  9952,  9959,  9963,  9970,  9971,  9972,  9973,  9974,  9978,
    9982,  9986,  9990,  9994, 10015, 10019, 10026, 10027, 10028, 10032,
   10033, 10034, 10035, 10036, 10040, 10044, 10051, 10052, 10056, 10057,
   10061, 10062, 10066, 10067, 10078, 10079, 10083, 10084, 10085, 10089,
   10090, 10091, 10098, 10099, 10103, 10104, 10108, 10109, 10110, 10116,
   10120, 10124, 10125, 10129, 10133, 10140, 10147, 10154, 10164, 10168,
   10175, 10185, 10195, 10205, 10218, 10222, 10230, 10238, 10242, 10252,
   10267, 10290, 10313, 10329, 10330, 10331, 10332, 10333, 10334, 10338,
   10342, 10359, 10363, 10370, 10371, 10372, 10373, 10374, 10375, 10376,
   10382, 10386, 10390, 10394, 10398, 10402, 10406, 10410, 10414, 10418,
   10425, 10426, 10430, 10431, 10432, 10436, 10437, 10438, 10442, 10446,
   10450, 10457, 10461, 10465, 10472, 10479, 10486, 10496, 10503, 10513,
   10520, 10532, 10540, 10541, 10545, 10546, 10550, 10551, 10556, 10559,
   10567, 10570, 10577, 10579, 10580, 10584, 10585, 10589, 10590, 10591,
   10596, 10599, 10612, 10616, 10624, 10628, 10632, 10636, 10640, 10644,
   10648, 10652, 10659, 10660, 10666, 10667, 10668, 10669, 10670, 10671,
   10672, 10673, 10674, 10675, 10676, 10677, 10678, 10679, 10680, 10681,
   10682, 10683, 10684, 10685, 10686, 10687, 10688, 10689, 10690, 10691,
   10692, 10693, 10694, 10695, 10696, 10697, 10698, 10699, 10700, 10701,
   10702, 10703, 10704, 10705, 10706, 10707, 10708, 10709, 10710, 10711,
   10712, 10713, 10714, 10715, 10716, 10717, 10718, 10719, 10720, 10721,
   10722, 10723, 10724, 10725, 10726, 10727, 10728, 10729, 10730, 10731,
   10732, 10733, 10734, 10735, 10742, 10742, 10743, 10743, 10744, 10744,
   10745, 10745, 10746, 10746, 10747, 10747, 10748, 10748, 10749, 10749,
   10750, 10750, 10751, 10751, 10752, 10752, 10753, 10753, 10754, 10754,
   10755, 10755, 10756, 10756, 10757, 10757, 10758, 10758, 10758, 10759,
   10759, 10760, 10760, 10761, 10761, 10762, 10762, 10763, 10763, 10763,
   10764, 10764, 10765, 10765, 10765, 10766, 10766, 10766, 10767, 10767,
   10767, 10768, 10768, 10769, 10769, 10770, 10770, 10771, 10771, 10771,
   10772, 10772, 10773, 10773, 10774, 10774, 10774, 10774, 10775, 10775,
   10776, 10776, 10777, 10777, 10778, 10778, 10779, 10779, 10780, 10780,
   10781, 10781, 10782, 10782, 10782, 10783, 10783, 10784, 10784, 10785,
   10785, 10786, 10786, 10787, 10787, 10788, 10788, 10789, 10789, 10790,
   10790, 10790, 10791, 10791, 10792, 10792, 10793, 10793, 10797, 10797,
   10798, 10798, 10799, 10799, 10800, 10800, 10801, 10801, 10802, 10802,
   10803, 10803, 10804, 10804, 10805, 10805, 10806, 10806, 10807, 10807,
   10808, 10808, 10809, 10809, 10810, 10810, 10811, 10811, 10812, 10812,
   10815, 10816, 10817, 10821, 10821, 10822, 10822, 10823, 10823, 10824,
   10824, 10825, 10825, 10826, 10826, 10827, 10827, 10828, 10828
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "ACCEPT", "ACCESS", "ADD",
  "ADDRESS", "ADVANCING", "AFTER", "ALL", "ALLOCATE", "ALPHABET",
  "ALPHABETIC", "\"ALPHABETIC-LOWER\"", "\"ALPHABETIC-UPPER\"",
  "ALPHANUMERIC", "\"ALPHANUMERIC-EDITED\"", "ALSO", "ALTER", "ALTERNATE",
  "AND", "ANY", "ARE", "AREA", "\"ARGUMENT-NUMBER\"", "\"ARGUMENT-VALUE\"",
  "AS", "ASCENDING", "ASCII", "ASSIGN", "AT", "ATTRIBUTE", "AUTO",
  "AUTOMATIC", "\"AWAY-FROM-ZERO\"", "\"BACKGROUND-COLOR\"", "BASED",
  "BEFORE", "BELL", "BINARY", "\"BINARY-C-LONG\"", "\"BINARY-CHAR\"",
  "\"BINARY-DOUBLE\"", "\"BINARY-LONG\"", "\"BINARY-SHORT\"", "BLANK",
  "BLINK", "BLOCK", "BOTTOM", "BY", "\"BYTE-LENGTH\"", "CALL", "CANCEL",
  "CF", "CH", "CHAINING", "CHARACTER", "CHARACTERS", "CLASS",
  "CLASSIFICATION", "CLOSE", "CODE", "\"CODE-SET\"", "COLLATING", "COL",
  "COLS", "COLUMN", "COLUMNS", "COMMA", "\"COMMAND-LINE\"",
  "\"comma delimiter\"", "COMMIT", "COMMON", "COMP", "COMPUTE",
  "\"COMP-1\"", "\"COMP-2\"", "\"COMP-3\"", "\"COMP-4\"", "\"COMP-5\"",
  "\"COMP-6\"", "\"COMP-X\"", "\"FUNCTION CONCATENATE\"", "CONDITION",
  "CONFIGURATION", "CONSTANT", "CONTAINS", "CONTENT", "CONTINUE",
  "CONTROL", "CONTROLS", "CONVERSION", "CONVERTING", "COPY",
  "CORRESPONDING", "COUNT", "CRT", "\"CRT-UNDER\"", "CURRENCY",
  "\"FUNCTION CURRENT-DATE\"", "CURSOR", "CYCLE", "DATA", "DATE", "DAY",
  "\"DAY-OF-WEEK\"", "DE", "DEBUGGING", "\"DECIMAL-POINT\"",
  "DECLARATIVES", "DEFAULT", "DELETE", "DELIMITED", "DELIMITER",
  "DEPENDING", "DESCENDING", "DETAIL", "DISC", "DISK", "DISPLAY",
  "\"FUNCTION DISPLAY-OF\"", "DIVIDE", "DIVISION", "DOWN", "DUPLICATES",
  "DYNAMIC", "EBCDIC", "EC", "ELSE", "END", "\"END-ACCEPT\"",
  "\"END-ADD\"", "\"END-CALL\"", "\"END-COMPUTE\"", "\"END-DELETE\"",
  "\"END-DISPLAY\"", "\"END-DIVIDE\"", "\"END-EVALUATE\"",
  "\"END FUNCTION\"", "\"END-IF\"", "\"END-MULTIPLY\"", "\"END-PERFORM\"",
  "\"END PROGRAM\"", "\"END-READ\"", "\"END-RETURN\"", "\"END-REWRITE\"",
  "\"END-SEARCH\"", "\"END-START\"", "\"END-STRING\"", "\"END-SUBTRACT\"",
  "\"END-UNSTRING\"", "\"END-WRITE\"", "ENTRY", "ENVIRONMENT",
  "\"ENVIRONMENT-NAME\"", "\"ENVIRONMENT-VALUE\"", "EOL", "EOP", "EOS",
  "EQUAL", "ERASE", "ERROR", "ESCAPE", "EVALUATE", "\"EVENT STATUS\"",
  "EXCEPTION", "\"EXCEPTION CONDITION\"", "EXCLUSIVE", "EXIT",
  "\"Exponentiation operator\"", "EXTEND", "EXTERNAL", "FD",
  "\"FILE-CONTROL\"", "\"FILE-ID\"", "FILLER", "FINAL", "FIRST",
  "\"FLOAT-BINARY-128\"", "\"FLOAT-BINARY-32\"", "\"FLOAT-BINARY-64\"",
  "\"FLOAT-DECIMAL-16\"", "\"FLOAT-DECIMAL-34\"", "\"FLOAT-DECIMAL-7\"",
  "\"FLOAT-EXTENDED\"", "\"FLOAT-LONG\"", "\"FLOAT-SHORT\"", "FOOTING",
  "FOR", "\"FOREGROUND-COLOR\"", "FOREVER",
  "\"FUNCTION FORMATTED-CURRENT-DATE\"", "\"FUNCTION FORMATTED-DATE\"",
  "\"FUNCTION FORMATTED-DATETIME\"", "\"FUNCTION FORMATTED-TIME\"", "FREE",
  "FROM", "\"FROM CRT\"", "FULL", "FUNCTION", "\"FUNCTION-ID\"",
  "\"FUNCTION\"", "GENERATE", "GIVING", "GLOBAL", "GO", "GOBACK",
  "GREATER", "\"GREATER OR EQUAL\"", "GROUP", "HEADING", "HIGHLIGHT",
  "\"HIGH-VALUE\"", "ID", "IDENTIFICATION", "IF", "IGNORE", "IGNORING",
  "IN", "INDEX", "INDEXED", "INDICATE", "INITIALIZE", "INITIALIZED",
  "INITIATE", "INPUT", "\"INPUT-OUTPUT\"", "INSPECT", "INTO", "INTRINSIC",
  "INVALID", "\"INVALID KEY\"", "IS", "\"I-O\"", "\"I-O-CONTROL\"",
  "JUSTIFIED", "KEPT", "KEY", "KEYBOARD", "LABEL", "LAST", "LEADING",
  "LEFT", "LEFTLINE", "LENGTH", "\"LENGTH OF\"", "LESS",
  "\"LESS OR EQUAL\"", "LIMIT", "LIMITS", "LINAGE", "\"LINAGE-COUNTER\"",
  "LINE", "\"LINE-COUNTER\"", "LINES", "LINKAGE", "\"Literal\"", "LOCALE",
  "\"FUNCTION LOCALE-DATE\"", "\"FUNCTION LOCALE-TIME\"",
  "\"FUNCTION LOCALE-TIME-FROM-SECONDS\"", "\"LOCAL-STORAGE\"", "LOCK",
  "LOWER", "\"FUNCTION LOWER-CASE\"", "LOWLIGHT", "\"LOW-VALUE\"",
  "MANUAL", "MEMORY", "MERGE", "MINUS", "\"MNEMONIC NAME\"", "MODE",
  "MOVE", "MULTIPLE", "MULTIPLY", "NAME", "NATIONAL",
  "\"NATIONAL-EDITED\"", "\"FUNCTION NATIONAL-OF\"", "NATIVE",
  "\"NEAREST-AWAY-FROM-ZERO\"", "\"NEAREST-EVEN\"",
  "\"NEAREST-TOWARD-ZERO\"", "NEGATIVE", "NEXT", "\"NEXT PAGE\"", "NO",
  "\"NO-ECHO\"", "NORMAL", "NOT", "\"NOT END\"", "\"NOT EOP\"",
  "\"NOT EQUAL\"", "\"NOT EXCEPTION\"", "\"NOT INVALID KEY\"",
  "\"NOT OVERFLOW\"", "\"NOT SIZE ERROR\"", "\"NO ADVANCING\"", "NUMBER",
  "NUMBERS", "NUMERIC", "\"NUMERIC-EDITED\"", "\"FUNCTION NUMVAL-C\"",
  "\"OBJECT-COMPUTER\"", "OCCURS", "OF", "OFF", "OMITTED", "ON", "ONLY",
  "OPEN", "OPTIONAL", "OR", "ORDER", "ORGANIZATION", "OTHER", "OUTPUT",
  "OVERLINE", "\"PACKED-DECIMAL\"", "PADDING", "PAGE", "\"PAGE-COUNTER\"",
  "PARAGRAPH", "PERFORM", "PH", "PF", "PICTURE", "\"PICTURE SYMBOL\"",
  "PLUS", "POINTER", "POSITION", "POSITIVE", "PRESENT", "PREVIOUS",
  "PRINTER", "PRINTING", "PROCEDURE", "PROCEDURES", "PROCEED", "PROGRAM",
  "\"PROGRAM-ID\"", "\"Program name\"", "\"PROGRAM-POINTER\"",
  "PROHIBITED", "PROMPT", "QUOTE", "RANDOM", "RD", "READ",
  "\"READY TRACE\"", "RECORD", "RECORDING", "RECORDS", "RECURSIVE",
  "REDEFINES", "REEL", "REFERENCE", "REFERENCES", "RELATIVE", "RELEASE",
  "REMAINDER", "REMOVAL", "RENAMES", "REPLACE", "REPLACING", "REPORT",
  "REPORTING", "REPORTS", "REPOSITORY", "\"Intrinsic function name\"",
  "REQUIRED", "RESERVE", "RESET", "\"RESET TRACE\"", "RETURN", "RETURNING",
  "\"FUNCTION REVERSE\"", "\"REVERSE-VIDEO\"", "REVERSED", "REWIND",
  "REWRITE", "RF", "RH", "RIGHT", "ROLLBACK", "ROUNDED", "RUN", "SAME",
  "SCREEN", "\"SCREEN-CONTROL\"", "SCROLL", "SD", "SEARCH", "SECTION",
  "SECURE", "\"SEGMENT-LIMIT\"", "SELECT", "\"semi-colon\"", "SENTENCE",
  "SEPARATE", "SEQUENCE", "SEQUENTIAL", "SET", "SHARING", "SIGN", "SIGNED",
  "\"SIGNED-INT\"", "\"SIGNED-LONG\"", "\"SIGNED-SHORT\"", "SIZE",
  "\"SIZE ERROR\"", "SORT", "\"SORT-MERGE\"", "SOURCE",
  "\"SOURCE-COMPUTER\"", "SPACE", "\"SPECIAL-NAMES\"", "STANDARD",
  "\"STANDARD-1\"", "\"STANDARD-2\"", "START", "STATIC", "STATUS",
  "STDCALL", "STEP", "STOP", "STRING", "\"FUNCTION SUBSTITUTE\"",
  "\"FUNCTION SUBSTITUTE-CASE\"", "SUBTRACT", "SUM", "SUPPRESS",
  "SYMBOLIC", "SYNCHRONIZED", "\"SYSTEM-DEFAULT\"", "TALLYING", "TAPE",
  "TERMINATE", "TEST", "THAN", "THEN", "THRU", "TIME", "TIMEOUT", "TIMES",
  "TO", "\"&\"", "\")\"", "\":\"", "\"/\"", "\".\"", "\"=\"", "\"FALSE\"",
  "\"FILE\"", "\">\"", "\"INITIAL\"", "\"<\"", "\"-\"", "\"*\"",
  "\"NULL\"", "\"OVERFLOW\"", "\"(\"", "\"+\"", "\"TRUE\"", "TOP",
  "\"TOWARD-GREATER\"", "\"TOWARD-LESSER\"", "TRAILING", "TRANSFORM",
  "\"FUNCTION TRIM\"", "TRUNCATION", "TYPE", "UNDERLINE", "UNIT", "UNLOCK",
  "UNSIGNED", "\"UNSIGNED-INT\"", "\"UNSIGNED-LONG\"",
  "\"UNSIGNED-SHORT\"", "UNSTRING", "UNTIL", "UP", "UPDATE", "UPON",
  "\"UPON ARGUMENT-NUMBER\"", "\"UPON COMMAND-LINE\"",
  "\"UPON ENVIRONMENT-NAME\"", "\"UPON ENVIRONMENT-VALUE\"", "UPPER",
  "\"FUNCTION UPPER-CASE\"", "USAGE", "USE", "USER", "\"USER-DEFAULT\"",
  "\"User FUNCTION\"", "\"User FUNCTION name\"", "USING", "VALUE",
  "VARYING", "WAIT", "WHEN", "\"FUNCTION WHEN-COMPILED\"", "WITH",
  "\"Identifier\"", "WORDS", "\"WORKING-STORAGE\"", "WRITE", "YYYYDDD",
  "YYYYMMDD", "ZERO", "SHIFT_PREFER", "$accept", "start", "@1",
  "nested_list", "nested_progs", "source_element", "simple_prog", "@2",
  "program_definition", "program_mandatory", "function_definition",
  "nested_prog", "end_program", "end_mandatory", "end_function",
  "end_function_mandatory", "program_body", "@3", "@4", "@5",
  "program_identification", "@6", "function_identification",
  "program_name", "as_literal", "program_type", "program_type_clause",
  "_init_or_recurs", "environment_header", "configuration_header",
  "configuration_list", "configuration_paragraph",
  "source_computer_paragraph", "@7", "source_computer_entry",
  "with_debugging_mode", "object_computer_paragraph", "@8",
  "object_computer_entry", "object_clauses_list", "object_clauses",
  "object_computer_memory", "object_computer_sequence",
  "object_computer_segment", "object_computer_class", "locale_class",
  "computer_words", "repository_paragraph", "@9", "repository_entry",
  "repository_list", "repository_name", "user_or_intrinsic",
  "_as_literal_intrinsic", "repository_name_list",
  "special_names_paragraph", "special_names_entry", "special_name_list",
  "special_name", "mnemonic_name_clause", "@10", "mnemonic_choices",
  "special_name_mnemonic_on_off", "on_off_clauses", "alphabet_name_clause",
  "@11", "alphabet_definition", "alphabet_literal_list",
  "alphabet_literal", "@12", "alphabet_also_sequence", "alphabet_lits",
  "symbolic_characters_clause", "sym_in_word", "symbolic_collection",
  "symbolic_chars_list", "symbolic_chars_phrase", "char_list",
  "integer_list", "class_name_clause", "class_item_list", "class_item",
  "locale_clause", "currency_sign_clause", "with_pic_symbol",
  "decimal_point_clause", "numeric_sign_clause", "cursor_clause",
  "crt_status_clause", "screen_control", "event_status",
  "input_output_header", "file_control_header", "i_o_control_header",
  "file_control_sequence", "file_control_entry", "@13",
  "select_clause_sequence", "select_clause", "assign_clause",
  "device_name", "_line_adv_file", "_ext_clause", "assignment_name",
  "opt_assignment_name", "access_mode_clause", "access_mode",
  "alternative_record_key_clause", "collating_sequence_clause",
  "file_status_clause", "file_or_sort", "lock_mode_clause", "@14",
  "lock_mode", "lock_with", "organization_clause", "organization",
  "padding_character_clause", "record_delimiter_clause",
  "record_key_clause", "opt_splitk", "relative_key_clause",
  "reserve_clause", "no_or_integer", "sharing_clause", "sharing_option",
  "opt_i_o_control", "i_o_control_list", "i_o_control_clause",
  "same_clause", "same_option", "multiple_file_tape_clause", "@15",
  "multiple_file_list", "multiple_file", "multiple_file_position",
  "data_division_header", "file_section_header",
  "file_description_sequence", "file_description",
  "file_description_entry", "@16", "file_type",
  "file_description_clause_sequence", "file_description_clause",
  "block_contains_clause", "_records_or_characters", "record_clause",
  "record_depending", "opt_from_integer", "opt_to_integer",
  "label_records_clause", "value_of_clause", "file_id", "valueof_name",
  "data_records_clause", "linage_clause", "linage_sequence",
  "linage_lines", "linage_footing", "linage_top", "linage_bottom",
  "recording_mode_clause", "code_set_clause", "report_clause",
  "report_keyword", "rep_name_list", "working_storage_section", "@17",
  "record_description_list", "@18", "record_description_list_2",
  "data_description", "@19", "level_number", "entry_name", "const_name",
  "const_global", "lit_or_length", "con_identifier", "fp32_usage",
  "fp64_usage", "fp128_usage", "pointer_len", "constant_entry",
  "constant_source", "data_description_clause_sequence",
  "data_description_clause", "redefines_clause", "external_clause",
  "as_extname", "global_clause", "picture_clause", "usage_clause", "usage",
  "float_usage", "double_usage", "sign_clause", "report_occurs_clause",
  "occurs_step", "occurs_clause", "occurs_to_integer", "occurs_depending",
  "occurs_keys", "occurs_key_list", "ascending_or_descending",
  "occurs_indexed", "occurs_index_list", "occurs_index",
  "justified_clause", "synchronized_clause", "blank_clause",
  "based_clause", "value_clause", "@20", "value_item_list", "value_item",
  "false_is", "renames_clause", "any_length_clause",
  "local_storage_section", "@21", "linkage_section", "@22",
  "report_section", "@23", "report_description_sequence",
  "report_description", "@24", "report_description_options",
  "report_description_option", "control_clause", "control_field_list",
  "control_final_tag", "identifier_list", "control_identifier",
  "page_limit_clause", "page_line_column", "report_int_ident",
  "page_heading_list", "page_detail", "heading_clause", "first_detail",
  "last_heading", "last_detail", "footing_clause",
  "report_group_description_list", "report_group_description_entry", "@25",
  "report_group_options", "report_group_option", "type_clause",
  "type_option", "control_heading_final", "control_footing_final",
  "next_group_clause", "next_group_plus", "next_page", "sum_clause_list",
  "reset_clause", "data_or_final", "present_when_condition",
  "varying_clause", "line_clause", "line_keyword_clause",
  "line_clause_options", "number_is", "line_clause_integer",
  "line_clause_next_page", "column_clause", "col_keyword_clause",
  "col_or_plus", "source_clause", "group_indicate_clause",
  "report_usage_clause", "screen_section", "@26",
  "opt_screen_description_list", "screen_description_list",
  "screen_description", "@27", "screen_options", "screen_option",
  "plus_plus", "minus_minus", "screen_line_plus_minus",
  "screen_col_plus_minus", "screen_occurs_clause", "global_screen_opt",
  "procedure_division", "@28", "@29", "@30", "procedure_using_chaining",
  "@31", "@32", "procedure_param_list", "procedure_param",
  "procedure_type", "size_optional", "procedure_optional",
  "procedure_returning", "procedure_declaratives", "@33", "procedure_list",
  "procedure", "section_header", "@34", "opt_use_statement",
  "paragraph_header", "invalid_statement", "opt_segment", "statement_list",
  "@35", "@36", "statements", "@37", "statement", "accept_statement",
  "@38", "accept_body", "accp_identifier", "lines_or_number",
  "opt_at_line_column", "at_line_column", "line_number", "column_number",
  "opt_at_from", "opt_at_block", "opt_accp_attr", "accp_attrs",
  "accp_attr", "end_accept", "add_statement", "@39", "add_body", "add_to",
  "end_add", "allocate_statement", "@40", "allocate_body",
  "allocate_returning", "alter_statement", "@41", "alter_body",
  "alter_entry", "_proceed_to", "call_statement", "@42", "call_body",
  "mnemonic_conv", "call_using", "@43", "call_param_list", "call_param",
  "call_type", "call_returning", "return_give", "null_or_omitted",
  "call_on_exception", "call_not_on_exception", "end_call",
  "cancel_statement", "@44", "cancel_body", "close_statement", "@45",
  "close_body", "close_option", "compute_statement", "@46", "compute_body",
  "end_compute", "commit_statement", "continue_statement",
  "delete_statement", "@47", "delete_body", "delete_file_list",
  "end_delete", "display_statement", "@48", "display_body", "display_list",
  "@49", "display_atom", "display_upon", "display_upon_crt", "crt_under",
  "with_clause", "with_no_adv_clause", "disp_attrs", "disp_attr",
  "end_display", "divide_statement", "@50", "divide_body", "end_divide",
  "entry_statement", "@51", "entry_body", "evaluate_statement", "@52",
  "evaluate_body", "evaluate_subject_list", "evaluate_subject",
  "evaluate_condition_list", "evaluate_case_list", "evaluate_case",
  "evaluate_other", "evaluate_when_list", "evaluate_object_list",
  "evaluate_object", "opt_evaluate_thru_expr", "end_evaluate",
  "exit_statement", "@53", "exit_body", "free_statement", "@54",
  "free_body", "generate_statement", "@55", "generate_body",
  "goto_statement", "@56", "go_body", "goto_depending", "goback_statement",
  "if_statement", "@57", "if_else_statements", "end_if",
  "initialize_statement", "@58", "initialize_body", "initialize_filler",
  "initialize_value", "initialize_replacing", "initialize_replacing_list",
  "initialize_replacing_item", "initialize_category", "initialize_default",
  "initiate_statement", "@59", "initiate_body", "inspect_statement", "@60",
  "inspect_body", "send_identifier", "inspect_list", "inspect_tallying",
  "@61", "inspect_replacing", "inspect_converting", "tallying_list",
  "tallying_item", "replacing_list", "replacing_item", "rep_keyword",
  "replacing_region", "inspect_region", "inspect_before_after",
  "merge_statement", "@62", "move_statement", "@63", "move_body",
  "multiply_statement", "@64", "multiply_body", "end_multiply",
  "open_statement", "@65", "open_body", "open_mode", "open_sharing",
  "open_option", "perform_statement", "@66", "perform_body", "@67",
  "end_perform", "term_or_dot", "perform_procedure", "perform_option",
  "perform_test", "cond_or_exit", "perform_varying_list",
  "perform_varying", "read_statement", "@68", "read_body", "read_into",
  "with_lock", "read_key", "read_handler", "end_read", "ready_statement",
  "release_statement", "@69", "release_body", "reset_statement",
  "return_statement", "@70", "return_body", "end_return",
  "rewrite_statement", "@71", "rewrite_body", "write_lock", "end_rewrite",
  "rollback_statement", "search_statement", "@72", "search_body",
  "search_varying", "search_at_end", "search_whens", "search_when",
  "end_search", "set_statement", "@73", "set_body", "on_or_off",
  "up_or_down", "set_environment", "set_attr", "set_attr_clause",
  "set_attr_one", "set_to", "set_up_down", "set_to_on_off_sequence",
  "set_to_on_off", "set_to_true_false_sequence", "set_to_true_false",
  "sort_statement", "@74", "sort_body", "@75", "sort_key_list",
  "opt_key_list", "sort_duplicates", "sort_collating", "sort_input",
  "sort_output", "start_statement", "@76", "start_body", "sizelen_clause",
  "start_key", "start_op", "disallowed_op", "not_equal_op", "end_start",
  "stop_statement", "@77", "stop_returning", "_opt_status", "stop_literal",
  "string_statement", "@78", "string_body", "string_item_list",
  "string_item", "opt_with_pointer", "end_string", "subtract_statement",
  "@79", "subtract_body", "end_subtract", "suppress_statement",
  "_printing", "terminate_statement", "@80", "terminate_body",
  "transform_statement", "@81", "transform_body", "unlock_statement",
  "@82", "unlock_body", "opt_record", "unstring_statement", "@83",
  "unstring_body", "unstring_delimited", "unstring_delimited_list",
  "unstring_delimited_item", "unstring_into", "unstring_into_item",
  "unstring_into_delimiter", "unstring_into_count", "unstring_tallying",
  "end_unstring", "use_statement", "@84", "use_phrase",
  "use_file_exception", "use_global", "use_file_exception_target",
  "use_debugging", "debugging_list", "debugging_target", "all_refs",
  "use_reporting", "use_exception", "use_ex_keyw", "write_statement",
  "@85", "write_body", "from_option", "write_option", "before_or_after",
  "write_handler", "end_write", "on_accp_exception",
  "opt_on_accp_exception", "opt_not_on_accp_exception",
  "on_disp_exception", "opt_on_disp_exception",
  "opt_not_on_disp_exception", "on_size_error", "opt_on_size_error",
  "opt_not_on_size_error", "on_overflow", "opt_on_overflow",
  "opt_not_on_overflow", "return_at_end", "at_end", "at_end_clause",
  "not_at_end_clause", "at_eop", "at_eop_clause", "not_at_eop_clause",
  "invalid_key", "opt_invalid_key_sentence",
  "opt_not_invalid_key_sentence", "_opt_scroll_lines", "condition", "expr",
  "partial_expr", "@86", "expr_tokens", "expr_token", "eq", "gt", "lt",
  "ge", "le", "exp_list", "e_sep", "exp", "exp_term", "exp_factor",
  "exp_unary", "exp_atom", "line_linage_page_counter", "arithmetic_x_list",
  "arithmetic_x", "record_name", "table_name", "file_name_list",
  "file_name", "report_name", "mnemonic_name_list", "mnemonic_name",
  "procedure_name_list", "procedure_name", "label", "integer_label",
  "reference_list", "reference", "single_reference", "opt_reference_list",
  "opt_reference", "reference_or_literal", "undefined_word", "unique_word",
  "target_x_list", "target_x", "x_list", "x", "report_x_list", "expr_x",
  "arith_x", "prog_or_entry", "alnum_or_id", "simple_value",
  "simple_all_value", "id_or_lit", "id_or_lit_or_func", "num_id_or_lit",
  "positive_id_or_lit", "pos_num_id_or_lit", "from_parameter",
  "sub_identifier", "sort_identifier", "sub_identifier_1", "identifier",
  "identifier_1", "target_identifier", "target_identifier_1",
  "qualified_word", "subref", "refmod", "integer", "symbolic_integer",
  "report_integer", "class_value", "literal", "basic_literal",
  "basic_value", "function", "func_no_parm", "func_one_parm",
  "func_multi_parm", "func_refmod", "func_args", "trim_args",
  "numvalc_args", "locale_dt_args", "not_const_word", "flag_all",
  "flag_duplicates", "flag_initialized", "flag_initialized_to",
  "to_init_val", "flag_next", "flag_not", "flag_optional", "flag_rounded",
  "round_mode", "round_choice", "flag_separate", "error_stmt_recover",
  "_advancing", "_after", "_are", "_area", "_as", "_at", "_binary", "_by",
  "_character", "_characters", "_contains", "_data", "_file", "_for",
  "_from", "_in", "_in_order", "_indicate", "_initial", "_into", "_is",
  "_is_are", "_key", "_left_or_right", "_line_or_lines", "_limits",
  "_lines", "_mode", "_number", "_numbers", "_of", "_on", "_onoff_status",
  "_other", "_procedure", "_program", "_record", "_right", "_sign",
  "_signed", "_sign_is", "_size", "_standard", "_status", "_tape", "_then",
  "_times", "_to", "_to_using", "_when", "_when_set_to", "_with",
  "coll_sequence", "column_or_col", "columns_or_cols", "comp_equal",
  "exception_or_error", "exception_or_overflow", "in_of", "label_option",
  "line_or_lines", "lock_records", "object_char_or_word", "records",
  "reel_or_unit", "scroll_line_or_lines", "size_or_length", "with_dups",
  "prog_coll_sequence", "detail_keyword", "ch_keyword", "cf_keyword",
  "ph_keyword", "pf_keyword", "rh_keyword", "rf_keyword",
  "control_keyword", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   512,   514,   513,   515,   515,   516,   516,   517,   517,
     519,   518,   520,   521,   522,   523,   523,   523,   524,   524,
     525,   526,   526,   527,   529,   530,   531,   528,   533,   532,
     534,   535,   535,   536,   536,   537,   537,   538,   538,   538,
     538,   539,   539,   540,   540,   541,   541,   542,   542,   543,
     543,   543,   543,   543,   545,   544,   546,   546,   547,   547,
     549,   548,   550,   550,   550,   550,   551,   551,   552,   552,
     552,   552,   553,   554,   555,   556,   557,   557,   557,   557,
     558,   558,   560,   559,   561,   561,   561,   562,   562,   563,
     563,   563,   564,   564,   565,   565,   566,   566,   567,   568,
     568,   569,   569,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   572,   571,   573,   573,   573,
     573,   574,   574,   575,   575,   577,   576,   578,   578,   578,
     578,   578,   578,   579,   579,   580,   580,   581,   580,   582,
     582,   583,   583,   583,   583,   583,   583,   584,   585,   585,
     586,   587,   587,   588,   589,   589,   590,   590,   591,   592,
     592,   593,   593,   594,   595,   596,   596,   597,   598,   599,
     600,   601,   602,   603,   603,   604,   604,   605,   605,   606,
     606,   608,   607,   607,   609,   609,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   611,
     611,   611,   611,   611,   612,   612,   612,   612,   613,   613,
     614,   614,   614,   615,   615,   616,   616,   616,   617,   618,
     618,   618,   619,   620,   621,   622,   622,   622,   624,   623,
     625,   625,   625,   626,   626,   626,   626,   627,   627,   628,
     628,   628,   628,   629,   630,   631,   632,   632,   632,   633,
     634,   635,   635,   636,   637,   637,   637,   638,   638,   638,
     639,   639,   640,   640,   641,   642,   642,   642,   642,   644,
     643,   645,   645,   646,   647,   647,   648,   648,   649,   649,
     650,   650,   651,   653,   652,   652,   654,   654,   655,   655,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   657,   658,   658,   658,   659,   659,   659,   660,   660,
     661,   661,   662,   662,   663,   664,   664,   665,   665,   666,
     666,   667,   668,   669,   669,   670,   670,   670,   671,   672,
     673,   674,   675,   676,   677,   677,   678,   678,   679,   680,
     679,   681,   682,   681,   683,   683,   683,   684,   685,   684,
     684,   686,   687,   687,   687,   688,   689,   689,   690,   690,
     690,   690,   691,   691,   691,   691,   691,   691,   691,   691,
     691,   691,   691,   691,   691,   692,   692,   693,   693,   694,
     694,   694,   695,   695,   696,   697,   697,   698,   698,   699,
     699,   699,   699,   699,   699,   699,   699,   699,   699,   699,
     699,   699,   699,   700,   701,   702,   702,   703,   704,   705,
     705,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   707,   707,   708,
     708,   709,   709,   710,   711,   711,   712,   713,   713,   714,
     714,   715,   716,   716,   717,   717,   718,   718,   719,   719,
     720,   721,   722,   723,   724,   726,   725,   727,   727,   728,
     728,   729,   729,   730,   730,   731,   731,   732,   733,   732,
     734,   735,   734,   736,   737,   736,   738,   738,   740,   739,
     741,   741,   741,   742,   742,   742,   742,   743,   744,   744,
     744,   745,   746,   746,   747,   748,   749,   749,   749,   750,
     750,   751,   751,   752,   752,   752,   752,   752,   753,   754,
     755,   756,   757,   758,   758,   760,   759,   761,   761,   762,
     762,   762,   762,   762,   762,   762,   762,   762,   762,   762,
     762,   762,   762,   762,   762,   762,   763,   764,   764,   764,
     764,   764,   764,   764,   765,   765,   765,   766,   766,   766,
     767,   768,   768,   768,   768,   769,   769,   769,   769,   770,
     771,   771,   771,   772,   772,   773,   774,   775,   776,   777,
     777,   777,   778,   778,   778,   779,   780,   780,   781,   782,
     782,   783,   783,   784,   785,   786,   787,   788,   787,   789,
     789,   790,   790,   791,   792,   791,   791,   793,   793,   794,
     794,   794,   794,   794,   794,   794,   794,   794,   794,   794,
     794,   794,   794,   794,   794,   794,   794,   794,   794,   794,
     794,   794,   794,   794,   794,   794,   794,   794,   794,   794,
     794,   794,   794,   795,   795,   796,   796,   797,   797,   797,
     798,   798,   798,   799,   800,   801,   802,   803,   801,   804,
     801,   805,   806,   805,   807,   805,   808,   808,   809,   810,
     810,   810,   811,   811,   811,   811,   811,   811,   812,   812,
     813,   813,   814,   815,   814,   816,   816,   817,   817,   817,
     817,   817,   819,   818,   820,   820,   821,   822,   823,   823,
     825,   826,   824,   828,   827,   827,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   831,   830,   832,
     832,   832,   832,   832,   832,   832,   832,   832,   832,   832,
     832,   832,   832,   832,   832,   832,   832,   832,   833,   833,
     834,   834,   835,   835,   836,   836,   836,   836,   836,   837,
     838,   838,   839,   839,   840,   840,   841,   841,   842,   842,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   844,   844,   846,   845,   847,   847,
     847,   848,   848,   849,   849,   851,   850,   852,   852,   853,
     853,   855,   854,   856,   856,   857,   858,   858,   860,   859,
     861,   862,   862,   862,   862,   863,   864,   863,   865,   865,
     866,   866,   867,   867,   867,   867,   868,   868,   868,   868,
     869,   869,   870,   870,   871,   871,   872,   872,   873,   873,
     875,   874,   876,   876,   878,   877,   879,   879,   880,   880,
     880,   880,   880,   882,   881,   883,   884,   884,   885,   886,
     888,   887,   889,   889,   890,   890,   891,   891,   893,   892,
     894,   894,   894,   894,   894,   894,   894,   895,   896,   895,
     897,   898,   898,   898,   898,   898,   899,   899,   900,   900,
     901,   901,   902,   902,   903,   903,   904,   904,   904,   904,
     904,   904,   904,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   905,   905,   907,   906,   908,   908,   908,   908,
     908,   909,   909,   911,   910,   912,   914,   913,   915,   916,
     916,   917,   917,   917,   918,   918,   919,   919,   920,   921,
     922,   922,   923,   923,   924,   924,   924,   924,   925,   925,
     926,   926,   928,   927,   929,   929,   929,   929,   929,   929,
     929,   931,   930,   932,   934,   933,   935,   937,   936,   938,
     939,   939,   940,   942,   941,   943,   943,   943,   944,   944,
     946,   945,   947,   948,   948,   949,   949,   949,   950,   950,
     951,   951,   952,   953,   953,   953,   953,   953,   953,   953,
     954,   954,   956,   955,   957,   957,   959,   958,   960,   961,
     961,   961,   962,   962,   962,   962,   964,   963,   965,   966,
     967,   967,   968,   968,   968,   968,   968,   968,   969,   969,
     970,   970,   971,   971,   971,   971,   971,   972,   973,   973,
     974,   974,   976,   975,   978,   977,   979,   979,   981,   980,
     982,   982,   983,   983,   985,   984,   986,   986,   987,   987,
     987,   987,   988,   988,   989,   989,   989,   989,   991,   990,
     992,   993,   992,   992,   994,   994,   995,   995,   996,   996,
     997,   997,   997,   997,   997,   998,   998,   999,   999,  1000,
    1000,  1001,  1003,  1002,  1004,  1005,  1005,  1006,  1006,  1006,
    1006,  1006,  1006,  1006,  1007,  1007,  1008,  1008,  1009,  1009,
    1010,  1012,  1011,  1013,  1014,  1016,  1015,  1017,  1018,  1018,
    1020,  1019,  1021,  1022,  1022,  1022,  1023,  1023,  1024,  1026,
    1025,  1027,  1027,  1028,  1028,  1029,  1029,  1030,  1030,  1031,
    1032,  1032,  1034,  1033,  1035,  1035,  1035,  1035,  1035,  1035,
    1036,  1036,  1037,  1037,  1038,  1039,  1040,  1040,  1041,  1041,
    1041,  1041,  1041,  1041,  1041,  1041,  1042,  1042,  1043,  1044,
    1044,  1045,  1046,  1046,  1047,  1047,  1049,  1048,  1051,  1050,
    1052,  1052,  1053,  1053,  1054,  1054,  1055,  1055,  1056,  1056,
    1056,  1057,  1057,  1057,  1059,  1058,  1060,  1061,  1061,  1062,
    1062,  1062,  1062,  1063,  1063,  1063,  1063,  1063,  1063,  1064,
    1065,  1065,  1066,  1066,  1068,  1067,  1067,  1069,  1069,  1069,
    1069,  1069,  1070,  1070,  1071,  1071,  1071,  1071,  1073,  1072,
    1074,  1075,  1075,  1076,  1076,  1076,  1077,  1077,  1078,  1078,
    1080,  1079,  1081,  1081,  1081,  1082,  1082,  1083,  1084,  1084,
    1086,  1085,  1087,  1087,  1089,  1088,  1090,  1092,  1091,  1093,
    1094,  1094,  1094,  1096,  1095,  1097,  1098,  1098,  1099,  1099,
    1100,  1101,  1101,  1102,  1103,  1103,  1104,  1104,  1105,  1105,
    1106,  1106,  1108,  1107,  1109,  1109,  1109,  1109,  1110,  1111,
    1111,  1112,  1112,  1112,  1112,  1112,  1113,  1114,  1114,  1115,
    1115,  1115,  1116,  1116,  1116,  1116,  1117,  1118,  1119,  1119,
    1121,  1120,  1122,  1123,  1123,  1124,  1124,  1124,  1124,  1125,
    1125,  1126,  1126,  1127,  1127,  1128,  1129,  1129,  1130,  1130,
    1131,  1132,  1132,  1133,  1133,  1134,  1135,  1135,  1136,  1136,
    1137,  1138,  1138,  1139,  1139,  1140,  1140,  1141,  1141,  1141,
    1142,  1143,  1144,  1144,  1144,  1145,  1146,  1147,  1148,  1148,
    1149,  1149,  1150,  1150,  1151,  1152,  1154,  1153,  1155,  1155,
    1155,  1156,  1156,  1156,  1156,  1156,  1156,  1156,  1156,  1156,
    1156,  1156,  1156,  1156,  1156,  1156,  1156,  1156,  1156,  1156,
    1156,  1156,  1156,  1156,  1156,  1157,  1157,  1158,  1158,  1159,
    1159,  1160,  1161,  1162,  1162,  1163,  1163,  1163,  1164,  1164,
    1164,  1165,  1165,  1165,  1166,  1166,  1167,  1167,  1167,  1168,
    1168,  1169,  1169,  1169,  1169,  1169,  1169,  1170,  1170,  1171,
    1172,  1173,  1174,  1174,  1175,  1176,  1177,  1177,  1178,  1179,
    1179,  1180,  1181,  1181,  1181,  1182,  1183,  1183,  1184,  1185,
    1186,  1186,  1187,  1188,  1188,  1189,  1190,  1191,  1191,  1192,
    1192,  1192,  1193,  1193,  1194,  1194,  1194,  1194,  1194,  1194,
    1194,  1194,  1194,  1194,  1195,  1195,  1196,  1196,  1196,  1197,
    1197,  1197,  1197,  1197,  1197,  1197,  1198,  1198,  1199,  1199,
    1200,  1200,  1201,  1201,  1202,  1202,  1203,  1203,  1203,  1204,
    1204,  1204,  1205,  1205,  1206,  1206,  1207,  1207,  1207,  1208,
    1209,  1210,  1210,  1211,  1212,  1212,  1212,  1212,  1213,  1213,
    1214,  1214,  1214,  1214,  1215,  1215,  1216,  1217,  1217,  1218,
    1219,  1220,  1221,  1221,  1221,  1221,  1221,  1221,  1221,  1222,
    1222,  1223,  1223,  1224,  1224,  1224,  1224,  1224,  1224,  1224,
    1225,  1225,  1225,  1225,  1225,  1225,  1225,  1225,  1225,  1225,
    1226,  1226,  1227,  1227,  1227,  1228,  1228,  1228,  1229,  1229,
    1229,  1230,  1230,  1230,  1231,  1231,  1231,  1232,  1232,  1233,
    1233,  1234,  1235,  1235,  1236,  1236,  1237,  1237,  1238,  1238,
    1239,  1239,  1240,  1240,  1240,  1241,  1241,  1242,  1242,  1242,
    1243,  1243,  1244,  1244,  1245,  1245,  1245,  1245,  1245,  1245,
    1245,  1245,  1246,  1246,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1248,  1248,  1249,  1249,  1250,  1250,
    1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,  1255,
    1256,  1256,  1257,  1257,  1258,  1258,  1259,  1259,  1260,  1260,
    1261,  1261,  1262,  1262,  1263,  1263,  1264,  1264,  1264,  1265,
    1265,  1266,  1266,  1267,  1267,  1268,  1268,  1269,  1269,  1269,
    1270,  1270,  1271,  1271,  1271,  1272,  1272,  1272,  1273,  1273,
    1273,  1274,  1274,  1275,  1275,  1276,  1276,  1277,  1277,  1277,
    1278,  1278,  1279,  1279,  1280,  1280,  1280,  1280,  1281,  1281,
    1282,  1282,  1283,  1283,  1284,  1284,  1285,  1285,  1286,  1286,
    1287,  1287,  1288,  1288,  1288,  1289,  1289,  1290,  1290,  1291,
    1291,  1292,  1292,  1293,  1293,  1294,  1294,  1295,  1295,  1296,
    1296,  1296,  1297,  1297,  1298,  1298,  1299,  1299,  1300,  1300,
    1301,  1301,  1302,  1302,  1303,  1303,  1304,  1304,  1305,  1305,
    1306,  1306,  1307,  1307,  1308,  1308,  1309,  1309,  1310,  1310,
    1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,  1315,  1315,
    1316,  1316,  1316,  1317,  1317,  1318,  1318,  1319,  1319,  1320,
    1320,  1321,  1321,  1322,  1322,  1323,  1323,  1324,  1324
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     2,     1,     1,
       0,     2,     4,     4,     3,     0,     1,     2,     0,     1,
       3,     0,     1,     3,     0,     0,     0,    20,     0,     7,
       5,     1,     1,     0,     2,     0,     3,     1,     2,     1,
       1,     1,     1,     0,     3,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     0,     4,     0,     3,     0,     3,
       0,     4,     0,     2,     3,     2,     1,     2,     1,     1,
       1,     1,     5,     3,     3,     4,     1,     1,     1,     1,
       1,     2,     0,     4,     0,     2,     3,     1,     2,     3,
       3,     3,     1,     1,     0,     2,     1,     2,     2,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     2,     3,     3,
       1,     0,     1,     3,     4,     0,     5,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     0,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       3,     1,     2,     3,     1,     2,     1,     2,     4,     1,
       2,     1,     3,     4,     5,     0,     3,     3,     5,     3,
       4,     3,     3,     0,     3,     0,     2,     0,     2,     0,
       2,     0,     6,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     1,     1,     1,     1,     0,     3,
       0,     1,     1,     1,     1,     0,     1,     1,     4,     1,
       1,     1,     6,     3,     4,     0,     1,     1,     0,     5,
       2,     2,     1,     0,     4,     5,     2,     3,     1,     1,
       3,     1,     2,     4,     4,     4,     1,     3,     4,     4,
       3,     1,     1,     3,     2,     2,     2,     0,     2,     3,
       1,     2,     1,     1,     5,     0,     1,     1,     1,     0,
       6,     1,     2,     2,     0,     2,     0,     3,     0,     3,
       0,     2,     2,     0,     5,     3,     1,     1,     0,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     1,     1,     4,     6,     9,     0,     3,
       0,     2,     0,     2,     3,     5,     5,     1,     1,     1,
       1,     3,     5,     0,     2,     1,     1,     1,     4,     2,
       2,     4,     3,     2,     2,     2,     1,     2,     0,     0,
       5,     0,     0,     2,     2,     3,     2,     1,     0,     4,
       3,     2,     0,     1,     1,     1,     0,     2,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     0,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     6,     0,     2,     7,     0,     2,     0,
       3,     1,     0,     5,     1,     1,     0,     3,     1,     2,
       1,     2,     2,     3,     1,     0,     5,     1,     2,     1,
       3,     0,     4,     2,     4,     2,     2,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     2,     0,     6,
       0,     2,     2,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     2,     1,     4,     1,     2,     4,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     3,     4,
       4,     4,     3,     0,     2,     0,     5,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     1,     1,     0,     1,     1,     0,     1,     1,
       4,     1,     2,     2,     1,     2,     1,     1,     1,     4,
       0,     3,     2,     1,     1,     3,     6,     2,     2,     1,
       2,     2,     0,     2,     1,     1,     2,     3,     2,     3,
       2,     2,     1,     4,     2,     3,     0,     0,     5,     0,
       1,     2,     3,     1,     0,     4,     3,     0,     2,     2,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     5,     5,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     0,     1,     1,
       0,     1,     1,     3,     2,     0,     0,     0,     9,     0,
       4,     0,     0,     3,     0,     3,     1,     2,     4,     0,
       2,     2,     0,     3,     3,     4,     4,     3,     0,     1,
       0,     2,     0,     0,     7,     0,     2,     1,     1,     2,
       1,     1,     0,     6,     0,     2,     2,     1,     0,     1,
       0,     0,     3,     0,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     4,     6,
       3,     3,     4,     3,     4,     3,     3,     4,     4,     3,
       4,     3,     4,     5,     3,     4,     3,     3,     1,     1,
       1,     2,     0,     1,     3,     3,     2,     2,     2,     3,
       3,     3,     0,     1,     0,     3,     0,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     0,     1,     0,     4,     4,     5,
       6,     0,     2,     0,     1,     0,     3,     3,     4,     0,
       2,     0,     3,     1,     2,     4,     0,     2,     0,     4,
       6,     0,     1,     1,     1,     0,     0,     3,     1,     2,
       2,     3,     0,     2,     2,     2,     0,     3,     2,     4,
       1,     1,     1,     1,     0,     2,     0,     2,     0,     1,
       0,     3,     1,     2,     0,     3,     2,     3,     0,     1,
       3,     3,     2,     0,     4,     4,     0,     1,     1,     1,
       0,     4,     3,     2,     1,     2,     0,     1,     0,     4,
       3,     3,     3,     3,     4,     2,     4,     1,     0,     3,
       5,     0,     2,     2,     2,     2,     0,     2,     1,     1,
       0,     2,     0,     1,     1,     2,     1,     2,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     0,     1,     0,     4,     4,     6,     6,     8,
       8,     0,     1,     0,     3,     2,     0,     4,     2,     1,
       3,     1,     1,     1,     2,     1,     1,     2,     2,     3,
       2,     3,     1,     3,     2,     1,     1,     1,     0,     2,
       0,     1,     0,     3,     0,     1,     1,     2,     1,     1,
       1,     0,     3,     1,     0,     3,     1,     0,     3,     3,
       0,     3,     1,     0,     6,     3,     2,     1,     0,     1,
       0,     3,     5,     0,     2,     0,     3,     3,     0,     2,
       1,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     2,     0,     3,     2,     1,
       1,     1,     2,     1,     1,     1,     0,     3,     2,     5,
       1,     2,     2,     2,     1,     1,     1,     2,     1,     2,
       4,     2,     0,     1,     1,     1,     1,     4,     0,     2,
       3,     3,     0,     3,     0,     3,     3,     4,     0,     4,
       4,     6,     0,     1,     0,     3,     4,     5,     1,     1,
       1,     1,     0,     3,     0,     3,     2,     1,     0,     3,
       2,     0,     4,     2,     0,     1,     1,     1,     1,     3,
       0,     2,     1,     3,     3,     0,     3,     1,     1,     1,
       3,     7,     0,     4,     7,     0,     2,     0,     2,     2,
       3,     3,     3,     2,     0,     3,     1,     1,     0,     1,
       1,     0,     3,     2,     1,     0,     4,     4,     0,     1,
       0,     4,     4,     0,     2,     3,     0,     1,     1,     0,
       4,     4,     6,     0,     2,     0,     2,     1,     2,     3,
       0,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     3,     4,     1,
       2,     3,     1,     2,     3,     3,     0,     3,     0,     7,
       0,     5,     0,     2,     0,     2,     0,     3,     0,     2,
       4,     0,     2,     4,     0,     4,     4,     0,     3,     0,
       4,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     1,     0,     1,     0,     4,     2,     0,     2,     2,
       4,     4,     0,     1,     1,     1,     1,     1,     0,     4,
       5,     1,     2,     1,     3,     3,     0,     4,     0,     1,
       0,     4,     4,     6,     6,     0,     1,     2,     0,     1,
       0,     3,     1,     2,     0,     3,     5,     0,     3,     2,
       0,     1,     1,     0,     4,     6,     0,     3,     1,     3,
       2,     2,     2,     3,     0,     3,     0,     3,     0,     3,
       0,     1,     0,     3,     1,     1,     1,     1,     7,     0,
       1,     1,     1,     1,     1,     1,     4,     1,     2,     1,
       2,     3,     0,     1,     2,     1,     4,     1,     1,     1,
       0,     4,     5,     0,     2,     0,     4,     3,     3,     1,
       1,     1,     1,     0,     1,     2,     0,     2,     0,     2,
       2,     0,     2,     0,     2,     2,     0,     2,     0,     2,
       2,     0,     2,     0,     2,     2,     1,     2,     1,     1,
       2,     2,     2,     1,     1,     2,     2,     2,     0,     2,
       0,     2,     0,     2,     1,     1,     0,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     2,     2,     1,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     2,     2,
       1,     1,     1,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     3,     1,     1,     2,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     2,     2,
       2,     4,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     2,     1,     1,     1,
       3,     2,     2,     1,     1,     3,     3,     4,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     5,     5,     5,     4,     5,     5,     5,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       5,     0,     3,     2,     1,     3,     3,     1,     3,     1,
       3,     0,     0,     1,     0,     1,     0,     1,     0,     2,
       0,     2,     0,     1,     1,     0,     1,     0,     1,     2,
       0,     2,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     2,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       0,     1,     0,     1,     1,     0,     1,     1,     0,     2,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     1,
       0,     1,     0,     1,     0,     2,     1,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     2,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     1,     0,     1,     0,     3,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     2,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,    10,     1,     0,     0,     3,     5,     6,     4,
      43,     8,     9,    43,    43,     0,     0,     7,     0,    11,
      45,    15,    21,    32,    31,    33,    33,     0,     0,    47,
      16,    18,    43,     0,    14,    22,     0,     0,    28,    44,
       0,   173,     0,    17,    12,    19,    15,     0,    34,    30,
    1775,    46,     0,     0,     0,  1818,  1775,  1775,  1775,     0,
       0,     0,     0,     0,  1775,     0,     0,  1752,   115,    48,
      49,    50,    53,    51,    52,     0,   101,   103,   104,   105,
     148,   107,   106,   108,   109,   110,   111,   112,   113,   114,
     175,     0,     0,    23,  1776,     0,     0,  1505,   125,  1775,
    1775,  1819,  1775,     0,     0,     0,     0,  1775,  1775,    60,
      82,     0,    54,    98,  1753,     0,  1775,     0,    99,   102,
       0,   147,     0,   179,    20,    13,    29,    37,    40,    42,
      41,  1812,    39,  1775,     0,     0,     0,  1574,   169,  1498,
     167,   172,   174,     0,     0,    62,    84,   171,    56,  1506,
     150,   151,  1777,   154,  1579,  1201,  1200,   116,   120,  1804,
    1775,     0,   100,   149,   176,   177,    38,  1813,    36,     0,
    1586,  1582,  1587,  1585,  1583,  1588,  1584,   158,   159,   161,
     170,   165,  1860,  1861,     0,   163,     0,  1751,     0,     0,
       0,  1775,  1882,    80,    61,  1750,    66,    68,    69,    70,
      71,  1750,     0,  1775,     0,    83,     0,    87,    55,    58,
     152,  1779,  1778,   155,     0,  1804,  1807,  1806,     0,     0,
     117,   121,     0,     0,   257,   180,   131,   130,   145,   141,
     146,   127,   144,   142,   128,   129,   143,   126,   132,   133,
     135,   160,     0,  1847,   164,     0,  1575,   168,  1881,  1775,
       0,     0,    65,    67,    63,    81,  1750,  1775,     0,     0,
      92,    93,    94,     0,     0,    85,    88,     0,     0,  1580,
     153,   156,     0,  1805,   123,   118,   119,   122,   178,     0,
       0,  1648,     0,   269,   265,    24,     0,   260,   262,   263,
     134,   137,     0,   162,     0,     0,  1880,    74,    64,     0,
    1499,    73,    89,     0,    90,    91,    97,    86,    57,     0,
     157,   124,   183,  1649,   181,  1758,   266,   267,   268,  1740,
     276,     0,   258,   261,     0,   136,   166,     0,    77,    79,
      78,    75,    76,    95,    59,   184,  1759,  1831,  1741,  1760,
       0,   278,   259,   138,   139,  1868,  1869,    72,  1814,  1832,
    1754,  1761,     0,     0,     0,   280,     0,  1793,  1814,  1839,
       0,   239,     0,  1775,  1750,  1780,   241,     0,  1849,  1846,
     227,   182,   226,   185,   186,   187,   188,   189,   190,     0,
     191,     0,   192,   238,   193,   194,   195,   196,   197,   198,
    1746,  1775,  1755,     0,  1484,   264,  1482,   277,     0,    25,
     140,  1794,  1775,  1815,  1780,  1840,  1841,   210,  1848,   242,
    1814,  1775,  1775,  1781,  1775,  1775,   251,  1740,   252,     0,
    1775,  1793,  1747,     0,     0,   270,   271,   274,  1483,   279,
     286,   287,   338,   281,   341,     0,     0,  1775,   212,   211,
     208,   241,   237,     0,     0,     0,     0,   250,  1808,  1808,
       0,   253,     0,  1775,   240,   223,   272,     0,   273,     0,
     487,   282,  1631,     0,   283,   220,   221,   219,   218,     0,
     204,   205,   215,   215,     0,   215,   207,   206,   215,     0,
    1504,  1503,   243,   244,   245,   246,   249,  1809,   254,   255,
     256,   224,     0,   275,     0,     0,   490,   343,     0,     0,
     347,     0,   285,   288,  1634,   216,   201,   217,   202,  1758,
     203,   200,   213,   199,   214,  1775,     0,   233,   232,   233,
     229,   339,     0,     0,   493,   346,     0,   344,     0,   353,
     354,   348,     0,   351,  1775,  1879,     0,   222,  1635,   209,
       0,   247,  1496,     0,   231,   230,   341,   488,     0,     0,
     606,   345,   350,   387,   356,  1754,  1775,     0,     0,  1775,
    1754,  1793,  1775,  1738,   284,     0,   289,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     0,     0,  1878,   248,
    1497,     0,   236,   340,   341,   491,     0,     0,    26,  1775,
    1742,     0,     0,     0,  1775,  1738,     0,     0,     0,     0,
       0,  1775,   334,  1739,   335,     0,   333,   336,   290,   291,
       0,   489,   341,   494,     0,   669,     0,   474,   411,  1820,
    1820,  1820,  1820,  1820,  1842,   412,   447,   449,   415,   416,
     417,   418,   419,   420,   443,   441,   442,   444,   445,   450,
     448,   421,  1816,   446,     0,   422,   408,   423,   424,     0,
       0,  1823,   426,   427,   425,  1782,   429,   430,   428,  1775,
    1777,   388,   389,   390,   391,   392,   393,   409,   413,   414,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
       0,  1743,     0,   384,     0,   357,   312,   332,  1870,  1871,
    1502,   321,  1500,  1863,  1862,   314,  1791,  1752,  1764,     0,
    1775,   318,   317,  1775,   337,     0,  1866,  1867,   234,   492,
     496,   607,     0,    27,   713,   485,   486,  1821,   440,   439,
     432,   431,   438,   437,   436,   435,   434,   433,  1843,     0,
    1817,   471,   457,   403,  1567,   483,  1824,  1783,  1784,   472,
       0,     0,   405,   407,  1662,  1662,   386,     0,  1800,  1597,
       0,     0,  1593,  1598,  1596,  1594,  1599,  1595,   385,   358,
    1589,  1591,     0,   302,  1501,  1792,   323,     0,   305,  1765,
    1825,   331,     0,     0,   235,   495,   609,   671,     0,     0,
     473,     0,  1835,     0,  1565,  1566,     0,   410,   475,   477,
     479,     0,   404,  1750,   451,   452,  1590,  1801,     0,     0,
     367,   363,   366,   365,   364,   379,   375,   377,   378,   380,
     376,   381,   382,   383,   360,   371,   372,   373,   368,   369,
     370,   362,   359,     0,   313,   304,   303,   301,   322,  1752,
    1826,   310,   319,   316,   320,   315,     0,   497,     0,   613,
     608,   610,     0,   674,   672,   690,     0,   767,   836,   845,
     851,   858,   890,   894,   908,   903,   909,   910,   918,   964,
     973,   976,  1002,  1011,  1014,  1017,  1022,  1023,  1030,  1052,
    1056,  1092,  1094,  1098,     0,  1104,  1118,  1142,  1160,  1161,
    1164,  1165,  1170,  1178,  1179,  1192,  1226,  1244,     0,  1278,
    1290,  1298,  1300,   695,  1304,  1307,  1313,  1360,   715,   716,
     717,   718,   719,   720,   721,   722,   724,   723,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   714,   458,
    1836,   459,  1615,  1610,  1621,     0,  1471,  1473,     0,     0,
       0,  1613,     0,  1475,  1614,  1616,  1617,     0,     0,     0,
       0,  1612,  1621,  1611,  1455,  1453,  1460,  1463,  1465,  1468,
    1532,  1470,  1529,  1563,  1530,  1531,  1618,     0,     0,     0,
    1564,   484,   481,   478,     0,   406,  1663,   361,   374,  1592,
       0,     0,   324,   325,   326,   327,     0,   306,  1763,   312,
       0,  1485,   498,     0,   614,     0,   611,   679,   679,     0,
       0,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1714,  1715,  1716,  1717,  1718,
    1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,
    1729,  1730,  1731,  1732,  1733,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,
    1704,  1705,  1706,  1707,  1708,  1709,  1664,  1710,  1711,  1712,
    1713,   766,     0,     0,     0,     0,   861,     0,     0,     0,
       0,     0,     0,     0,  1416,  1004,     0,     0,  1837,  1416,
       0,     0,     0,     0,     0,     0,   765,     0,  1130,     0,
       0,     0,     0,     0,     0,     0,     0,  1274,  1277,  1264,
    1275,  1276,  1266,     0,     0,  1299,  1297,     0,   713,     0,
       0,     0,     0,  1802,   462,     0,  1608,  1533,  1534,  1535,
       0,     0,     0,     0,     0,     0,     0,  1467,     0,  1466,
       0,  1609,  1456,  1457,  1576,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,     0,     0,   476,     0,
     480,   330,   329,  1744,  1752,   311,     0,   616,   617,   612,
    1749,   679,   676,   682,     0,   679,   691,   666,   789,   834,
     792,   788,  1800,     0,     0,  1523,   843,  1517,   841,  1512,
    1514,  1515,  1516,   846,     0,  1636,  1495,   852,   853,     0,
    1491,  1493,  1492,   864,   862,   863,   888,     0,  1545,   891,
     892,  1544,   895,   898,  1800,   906,  1569,     0,  1477,  1650,
    1509,  1568,  1573,  1510,     0,   916,  1814,  1593,   962,  1381,
     927,   931,  1512,     0,  1514,   971,     0,   865,   974,   983,
     982,  1000,     0,   979,   981,  1415,     0,  1006,  1010,  1008,
    1005,  1009,  1003,  1012,  1013,  1507,  1015,  1016,  1838,  1018,
    1489,  1833,  1414,  1031,  1033,  1053,  1054,  1057,     0,  1059,
    1060,  1061,  1093,  1230,  1560,  1561,     0,  1095,     0,  1102,
       0,  1111,  1108,  1110,  1109,  1105,  1112,  1132,  1495,  1119,
    1130,  1121,     0,  1128,     0,  1546,  1492,  1548,     0,  1158,
    1642,  1162,  1363,  1480,  1168,  1814,  1176,  1363,     0,  1190,
    1183,  1481,     0,  1488,  1193,  1194,  1195,  1196,  1197,  1198,
    1219,  1199,  1222,     0,  1486,     0,     0,  1559,  1573,  1227,
    1262,  1249,  1267,  1748,  1288,     0,  1281,  1283,     0,  1295,
       0,  1301,  1302,   701,   707,   696,   697,   698,   700,     0,
    1305,     0,  1308,  1310,  1330,  1316,  1373,  1363,  1803,     0,
     466,   461,  1623,  1455,  1453,  1472,  1474,  1455,     0,     0,
       0,  1455,  1526,  1527,  1528,     0,  1476,  1469,  1455,     0,
    1454,  1577,     0,  1459,  1458,  1462,  1461,  1464,     0,     0,
    1455,     0,  1775,  1745,     0,   308,     0,  1775,  1822,   677,
    1775,     0,   688,   680,   681,   692,   835,   768,  1745,   802,
     793,     0,     0,     0,     0,  1518,  1519,  1520,   844,   837,
       0,     0,  1513,  1638,  1637,   849,   854,   856,     0,   889,
     859,  1547,   865,   893,   898,  1872,  1873,   896,     0,   899,
       0,   907,   904,  1855,  1854,  1478,     0,  1652,  1479,  1571,
    1572,   913,   914,   917,   911,  1408,   963,   919,   710,     0,
     925,  1383,     0,   942,     0,   936,  1381,  1381,  1381,  1381,
     972,   965,     0,     0,   866,   975,  1001,   977,  1416,  1416,
     978,   985,   986,   710,  1440,  1441,  1442,  1436,  1837,  1428,
    1448,  1451,  1450,  1452,  1444,  1435,  1434,  1439,  1438,  1437,
    1443,  1423,  1427,  1445,  1447,  1449,  1425,  1426,  1422,  1424,
    1417,  1418,  1429,  1430,  1431,  1432,  1433,  1421,  1007,  1508,
    1020,  1834,   710,  1035,     0,  1055,     0,  1082,  1066,  1058,
    1063,  1064,  1065,  1234,     0,  1562,     0,     0,  1103,  1099,
       0,  1112,  1846,     0,  1120,  1126,  1127,   710,  1123,  1416,
       0,     0,  1131,     0,  1159,  1143,  1643,  1644,  1814,     0,
    1163,  1169,  1166,  1145,  1177,  1171,  1173,  1185,  1191,  1180,
       0,  1185,     0,  1540,  1541,  1220,  1223,     0,     0,  1487,
    1203,     0,  1202,     0,     0,  1571,  1263,  1245,  1251,  1775,
    1252,  1247,     0,     0,  1265,     0,     0,  1289,  1279,     0,
    1282,     0,  1296,  1291,     0,  1303,   708,   706,   699,     0,
    1311,  1312,  1309,  1331,  1314,  1748,     0,  1374,  1361,  1365,
     460,  1748,   456,   464,   465,  1780,  1622,     0,  1618,  1618,
    1618,     0,  1604,     0,  1618,  1578,     0,  1618,  1618,  1845,
       0,   328,  1802,   307,   502,  1775,  1775,  1738,  1788,   533,
     501,   505,   506,     0,     0,   631,  1775,   621,  1842,   622,
    1851,  1850,     0,  1775,     0,   634,   625,   630,  1795,   626,
       0,   629,   636,   633,   627,   632,     0,   637,   628,     0,
     648,   642,   646,   645,   643,   647,   618,   649,   644,     0,
    1795,     0,  1775,   689,     0,     0,   667,   798,   803,   804,
    1795,  1795,   796,   797,  1795,   784,  1376,  1853,  1852,   781,
     773,   775,   776,     0,  1376,     0,     0,     0,   790,   779,
       0,   787,   770,   786,   771,  1537,  1536,     0,  1522,     0,
    1800,  1569,  1386,   842,  1573,  1510,     0,  1640,   849,     0,
     847,     0,     0,  1494,   876,   897,   902,     0,     0,  1511,
    1386,  1775,  1651,  1570,   915,   710,   912,  1410,  1382,   711,
     929,  1744,   710,  1380,   935,   934,   933,   932,   943,  1381,
    1775,   946,     0,   949,   950,     0,  1775,   953,   954,   955,
     956,     0,   957,  1381,   944,     0,   804,   922,   923,   920,
     921,     0,  1386,     0,   872,   980,   995,   997,   996,   990,
     992,   998,  1416,   987,   984,  1416,   988,  1446,  1419,  1420,
    1802,  1019,  1490,   710,  1027,  1028,  1837,  1043,  1044,  1046,
    1048,  1049,  1045,  1047,  1038,  1837,  1034,     0,  1083,     0,
    1085,  1084,  1086,  1068,  1078,     0,     0,  1062,  1236,     0,
    1766,     0,  1096,  1386,     0,     0,     0,  1114,  1124,  1137,
    1133,  1138,  1134,  1139,     0,  1129,  1370,  1369,  1136,  1145,
    1364,  1556,  1557,  1558,     0,     0,  1408,     0,   710,     0,
    1184,     0,     0,     0,  1221,     0,  1225,  1224,  1217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1205,  1206,
    1645,  1408,     0,  1269,  1268,  1829,  1829,  1284,  1285,  1286,
       0,  1386,     0,     0,   709,     0,  1632,     0,  1286,  1173,
    1734,     0,  1775,  1630,  1605,  1606,  1607,  1628,  1625,  1626,
    1603,  1619,     0,  1601,  1602,   482,     0,     0,  1897,  1898,
    1775,  1738,     0,   499,   503,   511,   507,   509,   510,   512,
     514,     0,   619,   620,   623,   624,     0,   651,  1796,  1775,
    1835,  1775,   652,   650,   664,  1775,   683,   684,   687,     0,
     678,   693,   695,  1775,   806,     0,     0,   794,   795,     0,
     710,   785,  1378,   772,   774,  1376,   782,   777,   778,   791,
     780,  1539,  1521,  1538,  1650,     0,   710,   838,  1388,  1571,
    1572,  1386,     0,  1639,   848,   850,   857,   855,   881,   880,
     884,  1773,   901,   900,   905,     0,  1409,   710,  1407,   713,
    1384,   924,     0,   947,   948,   951,   952,     0,  1412,  1412,
     945,   926,   938,   939,   937,   940,     0,   966,     0,   867,
     868,   682,     0,  1416,  1416,   994,   710,   991,     0,  1026,
     710,  1029,  1024,     0,     0,  1050,     0,     0,     0,  1079,
    1081,     0,  1074,  1088,  1075,  1076,  1067,  1070,  1088,  1228,
    1775,  1780,     0,  1767,  1235,  1097,  1100,     0,  1114,  1113,
    1117,  1106,     0,  1125,  1122,     0,     0,  1147,  1146,   710,
    1167,  1396,  1172,  1174,     0,  1186,  1416,  1416,  1181,  1187,
    1204,  1216,  1218,  1208,  1209,  1210,  1214,  1211,  1215,  1212,
    1213,  1207,  1646,  1261,     0,  1258,  1259,  1253,     0,  1246,
    1877,  1876,     0,  1830,  1272,  1272,  1391,     0,  1650,  1292,
       0,   702,     0,  1633,  1317,  1318,     0,  1321,  1324,  1328,
    1322,  1408,  1735,     0,   470,   467,   468,     0,  1620,   309,
     504,  1789,  1790,  1581,   521,   516,   520,   519,   352,   534,
     508,   513,  1551,   641,  1549,  1550,   640,   657,   663,     0,
     660,   685,   686,   695,   713,     0,     0,  1376,   799,   801,
     800,  1377,   710,  1375,   783,  1386,  1511,  1387,   710,  1385,
    1570,   839,  1641,  1542,  1543,  1858,  1859,   886,   710,  1800,
    1774,   883,   882,   878,     0,  1654,  1655,  1656,  1657,  1658,
    1659,  1660,  1661,  1653,  1411,     0,   959,   958,   961,     0,
    1554,  1555,   960,     0,   930,  1386,  1477,  1386,  1477,   869,
     870,     0,   874,   873,   875,   993,   999,   989,  1021,  1025,
    1036,  1039,  1040,  1756,  1032,  1837,  1037,  1088,  1088,     0,
    1073,  1071,  1072,  1077,  1238,     0,  1232,  1768,  1386,  1107,
    1116,     0,  1140,     0,     0,  1154,     0,  1400,   710,  1395,
    1175,   710,   710,  1188,  1260,  1250,  1254,  1255,  1256,  1257,
    1248,  1270,  1273,  1271,   710,  1280,  1393,  1775,  1386,  1386,
     704,  1306,  1632,  1320,  1764,  1326,  1764,  1391,   710,   710,
    1362,  1372,  1403,  1404,  1371,  1368,  1367,  1785,   469,   463,
     515,  1864,  1865,   517,   354,   535,   655,   653,   656,   654,
     658,   659,     0,   635,   661,   662,     0,   713,   805,   810,
    1775,   811,   812,   813,  1775,   814,   815,   816,   817,   818,
     819,   820,   822,   823,   824,     0,   825,  1736,   826,   827,
     828,   807,   808,   769,  1379,   840,  1389,   710,   860,   885,
       0,   877,  1874,  1875,  1413,   941,   968,     0,   967,     0,
     871,  1041,  1757,     0,     0,  1069,  1080,  1088,  1771,  1771,
    1089,     0,     0,  1241,  1237,  1231,  1101,  1115,     0,  1148,
    1775,  1408,     0,     0,  1149,     0,  1153,  1401,  1182,  1189,
    1392,   710,  1390,     0,  1294,  1293,  1332,   703,     0,  1319,
       0,  1764,  1323,     0,  1315,  1405,  1406,  1402,  1786,  1787,
    1366,     0,  1775,  1775,     0,   522,   523,   524,   525,   526,
     527,     0,   537,   638,   639,     0,     0,     0,  1775,  1412,
    1412,  1737,     0,   809,   887,   879,  1386,  1386,     0,  1051,
    1087,  1772,     0,     0,  1775,  1239,     0,     0,  1229,  1233,
       0,     0,  1144,  1157,  1398,  1399,  1156,  1152,  1150,  1151,
    1394,  1287,  1339,   705,  1325,     0,  1329,  1884,  1883,  1775,
       0,     0,  1886,     0,  1775,  1775,   518,  1822,     0,   830,
     829,     0,   832,   831,   833,  1552,  1553,   970,   969,  1042,
    1091,  1090,     0,  1242,  1775,  1416,  1155,  1397,  1359,  1358,
    1340,  1333,  1334,  1736,  1335,  1336,  1337,  1357,     0,  1327,
       0,   532,   528,  1885,     0,     0,  1769,   592,     0,     0,
       0,     0,  1775,  1800,   536,  1775,  1775,     0,   543,   545,
     554,   546,   548,   551,   538,   539,   540,   550,   552,   555,
     541,     0,   542,   547,     0,   549,   553,   544,  1797,  1738,
     694,   821,  1240,     0,  1141,     0,  1827,  1802,   529,   531,
     530,  1770,   604,   594,   588,  1775,   596,   457,     0,  1416,
       0,     0,     0,     0,     0,     0,     0,   587,   589,   595,
       0,   598,   602,  1798,  1799,  1777,   600,  1243,     0,  1828,
       0,     0,   593,     0,  1835,   597,   585,  1650,   580,  1524,
    1888,     0,     0,  1890,  1892,     0,  1896,  1894,   556,   561,
     564,   567,   558,   562,   557,   563,   605,     0,   590,   591,
     601,   599,  1356,  1857,  1856,  1810,  1352,  1346,  1347,  1349,
     578,   576,   577,     0,     0,   570,   574,   571,   459,   603,
    1802,     0,   579,  1525,  1887,  1891,  1889,  1895,  1893,   566,
     559,   565,   569,   560,   568,     0,  1811,  1802,  1355,  1350,
    1353,     0,  1348,   575,   572,   573,   454,     0,   582,     0,
       0,  1354,  1351,     0,   453,   584,   581,   583,   586,  1345,
    1342,  1344,  1343,  1338,  1341,   455
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    11,    30,
      12,    31,    44,    45,    34,    35,    19,   320,   432,   615,
      32,    50,    14,    25,    37,    95,   131,   132,    20,    29,
      41,    69,    70,   148,   208,   267,    71,   145,   194,   195,
     196,   197,   198,   199,   200,   331,   201,    72,   146,   205,
     206,   207,   262,   304,   263,    73,    74,    75,    76,    77,
     116,   157,   276,   158,    78,   133,   237,   238,   239,   324,
     343,   240,    79,   121,    80,   150,   151,   152,   270,    81,
     177,   178,    82,    83,   244,    84,    85,    86,    87,    88,
      89,    90,   123,   224,   165,   225,   335,   348,   373,   374,
     478,   479,   440,   513,   506,   375,   468,   376,   377,   378,
     379,   380,   381,   520,   544,   382,   383,   384,   385,   386,
     484,   387,   388,   417,   389,   451,   285,   286,   287,   288,
     319,   289,   315,   425,   426,   458,   341,   355,   399,   433,
     434,   503,   435,   534,   566,   567,   827,   568,  1663,  1009,
     763,   569,   570,   703,   833,   571,   572,   828,  1002,  1003,
    1004,  1005,   573,   574,   575,   576,   606,   460,   546,   461,
     462,   497,   498,   553,   499,   531,   532,   590,   758,   814,
     815,   816,   817,   818,   500,   683,   589,   661,   662,   663,
     792,   664,   665,   666,   667,   668,   669,   670,  2550,  2694,
     671,   782,  1144,  1380,  1381,  1645,  1642,  2155,  2156,   672,
     673,   674,   675,   676,   992,   788,   789,  1178,   677,   678,
     496,   584,   524,   612,   550,   710,   775,   837,  1186,  1417,
    1670,  1671,  1956,  1957,  1958,  1959,  1672,  2164,  2165,  2320,
    2435,  2436,  2437,  2438,  2439,  2440,  1953,  2169,  2442,  2497,
    2554,  2555,  2628,  2670,  2673,  2556,  2655,  2656,  2557,  2662,
    2696,  2558,  2559,  2560,  2561,  2597,  2584,  2598,  2562,  2563,
    2564,  2601,  2565,  2566,  2567,   588,   776,   840,   841,   842,
    1188,  1418,  1706,  2330,  2331,  2332,  2336,  1707,  1708,   713,
    1425,  1982,   714,   845,  1018,  1017,  1191,  1192,  1193,  1422,
    1714,  1020,  1716,  2183,  1138,  1365,  1366,  2300,  2417,  1367,
    1368,  1923,  1778,  1779,  2029,  1369,   779,   898,   899,  1092,
    1199,  1200,  1742,  1429,  1485,  1722,  1723,  1719,  1984,  2187,
    2361,  2362,  1427,   900,  1093,  1206,  1441,  1439,   901,  1094,
    1213,  1760,   902,  1095,  1217,  1218,  1762,   903,  1096,  1226,
    1227,  1495,  1814,  2049,  2050,  2051,  2020,  2021,  2213,  2207,
    2368,  1450,   904,  1097,  1229,   905,  1098,  1232,  1457,   906,
    1099,  1235,  1462,   907,   908,   909,  1100,  1245,  1471,  1474,
     910,  1101,  1248,  1249,  1479,  1250,  1483,  1806,  2044,  2234,
    1789,  1803,  1804,  1477,   911,  1102,  1255,  1491,   912,  1103,
    1258,   913,  1104,  1261,  1262,  1263,  1500,  1501,  1502,  1824,
    1503,  1819,  1820,  2055,  1497,   914,  1105,  1272,   915,  1106,
    1273,   916,  1107,  1276,   917,  1108,  1279,  1831,   918,   919,
    1109,  1835,  2062,   920,  1110,  1283,  1543,  1844,  2065,  2251,
    2252,  2253,  2254,   921,  1111,  1285,   922,  1112,  1287,  1288,
    1549,  1550,  1856,  1551,  1552,  2076,  2077,  1853,  1854,  1855,
    2070,  2260,  2390,   923,  1113,   924,  1114,  1297,   925,  1115,
    1299,  1559,   926,  1117,  1305,  1306,  1563,  2091,   927,  1118,
    1309,  1567,  2094,  1568,  1310,  1311,  1312,  1870,  1872,  1873,
     928,  1119,  1319,  1885,  2275,  2401,  2472,  1575,   929,   930,
    1120,  1321,   931,   932,  1121,  1324,  1582,   933,  1122,  1326,
    1886,  1585,   934,   935,  1123,  1329,  1591,  1889,  2108,  2109,
    1589,   936,  1124,  1334,   159,  1603,  1335,  1336,  1908,  1909,
    1337,  1338,  1339,  1340,  1341,  1342,   937,  1125,  1292,  2264,
    1553,  2395,  1858,  2079,  2393,  2468,   938,  1126,  1350,  1911,
    1611,  2124,  2125,  2126,  1607,   939,  1352,  1614,  2291,  1132,
     940,  1133,  1354,  1355,  1356,  2136,  1618,   941,  1134,  1359,
    1623,   942,  1136,   943,  1137,  1361,   944,  1139,  1370,   945,
    1140,  1372,  1632,   946,  1141,  1374,  1636,  2144,  2145,  1928,
    2147,  2305,  2422,  2307,  1634,  2418,  2482,  2521,  2522,  2523,
    2703,  2524,  2647,  2648,  2681,  2525,  2526,  2527,   947,  1142,
    1376,  1580,  1929,  1878,  2310,  1638,  1991,  1992,  2193,  1480,
    1481,  1783,  2007,  2008,  2199,  2295,  2296,  2412,  2100,  2473,
    2101,  2279,  2311,  2312,  2313,  1776,  1777,  2028,  2228,  1281,
    1282,  1265,  1266,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
     974,  1165,  1384,   976,   977,   978,   979,  1236,  1237,  1465,
    1322,  1330,   395,   396,  1012,  1343,  1344,  1540,  1313,  1220,
    1221,   541,   481,   301,   691,   692,   482,    98,   153,  1274,
    1239,  1208,  1442,  2618,  1391,   981,  1747,  2002,  2078,  2202,
    1230,  1314,  2173,  2504,  2229,  1880,  2174,  1293,  1347,  1210,
     983,  1240,  1241,   734,   784,   785,  2175,   271,  2167,   179,
    1211,   760,   761,  1212,   986,   987,   988,  1173,  1146,  1399,
    1395,  1388,   501,  2146,   537,  1445,  1758,  2013,  1578,  2128,
     282,  1468,  1772,  2223,   794,  1091,  2153,  2452,   604,   339,
     684,  1431,   423,  1194,   202,   115,   393,  2383,   337,   352,
    1010,   770,  2084,  2582,  2462,  2214,    96,   214,   414,   739,
    2430,  1952,   766,   402,  1969,  2605,   798,  1379,   218,   488,
    2677,   168,   390,   731,   102,   719,   680,   831,  2610,  2134,
     350,  1542,   951,  1280,   407,   729,  1179,  1318,   391,  1724,
    1744,  1466,  2645,  2208,   184,   695,  2323,   708,   347,   596,
    1459,  2374,  2132,   538,   203,  2489,  2495,  2631,  2632,  2633,
    2634,  2635,  1674
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2362
static const yytype_int16 yypact[] =
{
   -2362,   239,    12, -2362,   329,   332, -2362,    12, -2362, -2362,
      99, -2362, -2362,    99,    99,   -50,   -50, -2362,   712, -2362,
     763,   686,   896, -2362, -2362,  1025,  1025,   613,   676, -2362,
   -2362,    39,    99,   -50, -2362, -2362,   827,   662, -2362, -2362,
     684,  1573,   -50, -2362, -2362, -2362,   686,   719, -2362, -2362,
     439, -2362,   743,   743,   769,   899,  1032,  1032,  1032,   926,
     743,   918,   875,   917,  1032,   927,   934,  1293, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,  1120, -2362, -2362, -2362, -2362,
    1147, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1218,   947,    39, -2362, -2362,   991,   125, -2362, -2362,  1032,
    1032, -2362,  1032,   948,  1392,   948,  1013,  1032,  1032, -2362,
   -2362,   948, -2362, -2362, -2362,   963,  1073,  1020, -2362, -2362,
     985, -2362,  1051, -2362, -2362, -2362, -2362,   660, -2362, -2362,
   -2362,  1163, -2362,  1032,   672,   948,  1251,   699, -2362, -2362,
   -2362, -2362, -2362,  1268,  1066,   358,  1336, -2362,  1041, -2362,
     963, -2362,    65, -2362, -2362, -2362, -2362, -2362,   -49,   447,
    1032,   -18, -2362, -2362, -2362,   -52, -2362, -2362, -2362,  1324,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,   672, -2362,  1112,
   -2362,  -198, -2362, -2362,   948, -2362,  1158, -2362,  1191,  1178,
    1550,  1032, -2362, -2362, -2362,   597, -2362, -2362, -2362, -2362,
   -2362,   412,  1563,  1032,    97, -2362,   119, -2362, -2362,   120,
   -2362, -2362, -2362, -2362,  1370,   447, -2362,  1397,   743,   743,
   -2362,   -49,  1179,    49,   -88, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   679, -2362,
      83, -2362,   672, -2362, -2362,  1304, -2362, -2362, -2362,  1032,
    1234,  1385, -2362, -2362, -2362, -2362,   688,  1032,  1142,  1413,
     -41, -2362,  1622,   607,  1199, -2362, -2362,  1200,  1547, -2362,
    1370, -2362,   743, -2362, -2362, -2362, -2362,   -49, -2362,  1204,
    1348, -2362,   743, -2362,   749, -2362,   100, -2362, -2362, -2362,
   -2362, -2362,   679, -2362,  1418,  1385, -2362, -2362, -2362,   733,
   -2362, -2362, -2362,  1420, -2362, -2362, -2362, -2362, -2362,  1391,
   -2362, -2362, -2362, -2362, -2362,  1224, -2362, -2362, -2362,  1657,
    1588,  1241, -2362, -2362,   679, -2362, -2362,    70, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1256, -2362,  1506,
    1576,  1245, -2362,  1678, -2362, -2362, -2362, -2362,  2467, -2362,
    1615, -2362,  1198,  1252,  1310, -2362,   679,  1433,  1355,  -224,
    1309, -2362,  1311,  1032,  1655,   634,   -73,   787, -2362,  1209,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1291,
   -2362,  1453, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1677,  1032, -2362,  1198, -2362,  1198, -2362, -2362,  1267,   485,
   -2362, -2362,  1032, -2362,  1482, -2362, -2362,  1039, -2362, -2362,
     892,  1032,  1032, -2362,  1032,  1032, -2362,  1657, -2362,   416,
    1032,  1433, -2362,  1318,  1217,  1198, -2362,  1394, -2362, -2362,
   -2362, -2362,  1216, -2362,  1219,    61,   284,  1032, -2362, -2362,
     914, -2362, -2362,  -110,  1307,   948,   948, -2362,  1414,  1414,
    1419, -2362,   948,  1032, -2362, -2362, -2362,  1385, -2362,  1337,
    1472, -2362, -2362,  1283, -2362, -2362, -2362, -2362, -2362,   948,
   -2362, -2362,   -84,   -84,  1728,   -84, -2362, -2362,   -84,   201,
   -2362, -2362, -2362, -2362, -2362,   755, -2362, -2362, -2362, -2362,
   -2362, -2362,   117, -2362,  1285,  1347,  1483,  -203,  1294,  6141,
   -2362,  1238, -2362, -2362,   -19, -2362, -2362, -2362, -2362,  1224,
   -2362, -2362, -2362, -2362, -2362,  1032,   948,  1243, -2362,  1243,
   -2362, -2362,  1296,  1354,  1383, -2362,  1299, -2362,  1300, -2362,
    1670, -2362,  1671, -2362,  1581, -2362,  1633, -2362, -2362, -2362,
     948,   948, -2362,   586, -2362, -2362,  1219, -2362,  1313,  1372,
    1390, -2362, -2362, -2362,  1070,  1615,  1032,   987,   987,  1032,
      38,  1433,  1032,  1759, -2362,  1477, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362,   743,  1008, -2362,   948,
   -2362,  1478, -2362, -2362,  1219, -2362,  1334,  1400, -2362,  6449,
     136,  1584,  1385,  1287,  1032,  1759,  1289,  -108,  -110,  1385,
    1290,  1032, -2362, -2362, -2362,   -53,   743, -2362, -2362, -2362,
     567, -2362,  1219, -2362,  1345,   801,   571, -2362, -2362,  -183,
     431,   573,   620,   674,  1297, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  1411, -2362,  1385, -2362, -2362, -2362, -2362,   948,
     948,  1565, -2362, -2362, -2362,   557, -2362, -2362, -2362,  1032,
     653, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1031,
     123, -2362,  1298, -2362,   859, -2362,  1357, -2362, -2362, -2362,
   -2362,  1289, -2362, -2362, -2362, -2362,  1546,    51,  1583,  1301,
    1032, -2362, -2362,  1032, -2362,  1082, -2362, -2362, -2362, -2362,
   -2362, -2362,  1682, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1302,
   -2362, -2362,  1360, -2362,  1346,  1365, -2362, -2362, -2362, -2362,
    6616,   465,  1784, -2362,  1415,  1415, -2362,  1001,  1505, -2362,
    2207,  2207, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1367, -2362,  1385,    52, -2362, -2362, -2362,  1385, -2362, -2362,
    1406, -2362,   400,   400, -2362,  1469,  1319,    16,  2601,  3520,
   -2362,  1385,  1374,  7131,  1362, -2362,   948, -2362,   465, -2362,
    1384,  1571, -2362,  1655, -2362, -2362, -2362, -2362,  2207,  1377,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362,  1001, -2362, -2362, -2362, -2362,    68,  1293,
   -2362,   816, -2362, -2362, -2362, -2362,  1325, -2362,  5959, -2362,
   -2362,  1319,  1382, -2362, -2362,  1460,  3958, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1438, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   665, -2362,
   -2362,  1502, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,  1725, -2362, -2362,  1378,  2424,   699,   699,  1379,  1380,
    1387, -2362,  1388,   699, -2362, -2362, -2362,  3719,  7131,  3719,
    1389, -2362,  1378, -2362,    67,  1068,   750, -2362,  1675, -2362,
   -2362, -2362, -2362, -2362,  1367, -2362,  1393,  1398,  1403,  7131,
   -2362, -2362,   703, -2362,   465, -2362, -2362, -2362, -2362, -2362,
    -110,  -110, -2362, -2362, -2362, -2362,  1658, -2362, -2362,  1357,
    1385, -2362, -2362,  1396, -2362,  1401, -2362,    98,    98,  1349,
    1405, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,   410,  3872,  7131,   411,   527,   463,  1198,  1079,
     633,  5396,  5485,  1598,   903,  1047,  1079,   948,  1421, -2362,
    1079,  1325,  2339,   948,  4677,  5485, -2362,   886,  4096,  1198,
     948,  1198,   948,    57,   707,   948,  1198, -2362, -2362, -2362,
   -2362, -2362, -2362,  4785,  4890, -2362, -2362,  1325,    88,   948,
    1198,   948,   948,  1548, -2362,  6754, -2362, -2362,  1367, -2362,
    1364,  1366,  7131,  7131,  7131,  2424,  1368, -2362,   976, -2362,
    2424, -2362, -2362, -2362, -2362,  7131,  6876,  7131,  7131,  7131,
    7131,  7131,  7131, -2362,  2424,  7131,  1068,  1456, -2362,  1408,
   -2362, -2362, -2362,  1839,  1293, -2362,   131, -2362, -2362, -2362,
   -2362,    21, -2362,   353,   502,    43, -2362, -2362, -2362,  1741,
     823,  1680,  1505,   948,  2424, -2362,  1747, -2362,  1187, -2362,
   -2362, -2362, -2362, -2362,   181,   526, -2362,   411, -2362,  1435,
   -2362,   699, -2362, -2362, -2362, -2362,  1752,  2965, -2362,   463,
   -2362, -2362,  1198,   780,  1505,  1754, -2362,   691, -2362,  1499,
   -2362, -2362,  1346,  1367,  1198,  1755,  1355,  1121,  1753,  4998,
   -2362,  5110,   147,  1152,  1180,  1757,   645,  1402, -2362, -2362,
   -2362,  1758,    56, -2362, -2362, -2362,  4457, -2362, -2362,  1789,
   -2362, -2362, -2362, -2362,  1079, -2362, -2362, -2362, -2362, -2362,
   -2362,  1450, -2362, -2362,  1002,  1325, -2362, -2362,    27, -2362,
   -2362, -2362, -2362, -2362, -2362,  1432,  5485, -2362,  1452,  1763,
    1855, -2362, -2362, -2362, -2362,   886,  1501, -2362,  1461, -2362,
    6184,     3,   727,  1465,  1464, -2362,  -199, -2362,  1471,  1768,
     760, -2362,  1716, -2362,  1769,  1355,  1770,  1716,   948,  1771,
    1423, -2362,  1272, -2362, -2362, -2362, -2362, -2362, -2362,  1643,
   -2362,  1079, -2362,  -105, -2362,   520,  1889, -2362,    82, -2362,
    1776,   951,   -30,  1875,  1777,  4599, -2362, -2362,   948,  1778,
    5265,  1325, -2362, -2362,   603, -2362, -2362, -2362, -2362,  3331,
   -2362,  1730, -2362,  1169,  1781,  1825,  1787,  1716, -2362,   948,
    1721,   773, -2362,    72,   822, -2362, -2362,   253,  1496,  1500,
    1507,   210, -2362,  1367, -2362,  1508, -2362, -2362,   264,  1509,
     822, -2362,  1007,   750,   750, -2362, -2362, -2362,  1074,  1510,
     295,  1514,  1032, -2362,  -110,  1840,  1513,   678,  6666, -2362,
    1032,  1556,  1656, -2362, -2362,  1860, -2362, -2362,  1272,  1773,
   -2362,   623,  1797,   -42,  1526, -2362,  1367, -2362, -2362, -2362,
    5593,  1772, -2362,  1750, -2362,  1600, -2362,  1635,  1724, -2362,
   -2362, -2362,  1402, -2362,   780, -2362, -2362, -2362,   953,   514,
     948, -2362, -2362, -2362, -2362, -2362,  7131,  1709, -2362,  1362,
   -2362,  1198, -2362, -2362, -2362,  1756, -2362, -2362, -2362,  5485,
   -2362,  1689,     1,  1687,  1138,  1512,  1824,  1824,  1824,  1824,
   -2362, -2362,  5485,  5593, -2362, -2362, -2362, -2362,   903,    59,
   -2362,  1490, -2362,  1492, -2362, -2362, -2362, -2362,  1421, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    4190, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     -12, -2362,  1866,  1476,  1823, -2362,  1272,    54, -2362, -2362,
    1636, -2362, -2362,   113,  7131, -2362,  1557,  1079, -2362, -2362,
    5593,  1501,  1209,  1198, -2362, -2362, -2362, -2362, -2362,  1834,
     948,   411, -2362,   932, -2362, -2362, -2362, -2362,  1355,  2339,
   -2362, -2362, -2362,  1779, -2362, -2362,   -97,  1876, -2362, -2362,
     948,  1876,  1558, -2362,  1367, -2362, -2362,  1154,   -49, -2362,
   -2362,  1910, -2362,  1959,   461,   104, -2362, -2362, -2362,  1032,
   -2362,   -91,  5485,  5485, -2362,    28,  5373, -2362, -2362,   948,
   -2362,  1814, -2362, -2362,  5593, -2362,  1385, -2362, -2362,  1272,
   -2362, -2362, -2362, -2362, -2362,  1875,  1785, -2362, -2362,   932,
   -2362,  1875, -2362, -2362, -2362,  1482, -2362,   948,  1393,  1393,
    1393,  2424, -2362,   126,  1393, -2362,  7027,  1393,  1393, -2362,
     465, -2362,  1548, -2362, -2362,  1032,  1032,  1759,  1029, -2362,
   -2362, -2362, -2362,  1808,   -35, -2362,  1032, -2362,   -77, -2362,
   -2362, -2362,  1399,  1032,  2965, -2362, -2362, -2362,  1715, -2362,
    1385, -2362,  1960, -2362, -2362, -2362,   948, -2362, -2362,   948,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1811,
    1715,   172,  1032, -2362,  1515,  1567, -2362, -2362, -2362,  1748,
    1715,  1715,   243,  1782,  1715, -2362,  1856, -2362, -2362, -2362,
    1520,  1522, -2362,  1272,  1856,  1786,  1599,  1734, -2362, -2362,
    1765, -2362, -2362, -2362, -2362, -2362, -2362,   468, -2362,   948,
    1505,  1832,   968, -2362,   -81,   -54,  1079,  1596,  1600,  1079,
   -2362,  1597,   411, -2362,   488, -2362, -2362,  1664,  1683, -2362,
     834,  1032, -2362, -2362, -2362, -2362, -2362,  1751, -2362, -2362,
   -2362,  2017, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1824,
    1032, -2362,   413, -2362, -2362,  1407,  1032, -2362, -2362, -2362,
   -2362,   -24, -2362,  1993, -2362,  1315,  1748, -2362, -2362, -2362,
   -2362,  1845,   968,  1850,   114, -2362, -2362, -2362, -2362,  2038,
   -2362,  1618,   174, -2362, -2362,    59, -2362, -2362, -2362, -2362,
    1548, -2362, -2362, -2362,  1933,  1925,  1421, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1700,  1421, -2362,  1620, -2362,  2018,
   -2362, -2362, -2362,   268, -2362,  1272,   265, -2362,    60,   773,
     535,  1079,  1079,   968,  1867,  1198,   416,   637,  1928, -2362,
   -2362, -2362,  2064, -2362,  1878, -2362, -2362, -2362, -2362,  1779,
   -2362, -2362, -2362, -2362,   948,  1946,  1756,  1034, -2362,  1577,
   -2362,  1579,  1272,   928, -2362,   468, -2362, -2362, -2362,  5485,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   461, -2362,
     500,  1756,   470, -2362, -2362,  1659,  1659, -2362, -2362,   426,
     948,   968,  1880,  1634, -2362,  1640,  2078,   948,   479,   -97,
    2081,  1585,  1032, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  1035, -2362, -2362, -2362,   948,   463, -2362, -2362,
    1032,  1759,   536,  1319, -2362, -2362, -2362,   948,   948, -2362,
   -2362,   582, -2362, -2362, -2362, -2362,   582, -2362, -2362,  1032,
    1374,  1032, -2362, -2362, -2362,  1032, -2362, -2362, -2362,   178,
   -2362, -2362, -2362,  1032,  1587,   582,   582, -2362, -2362,   582,
   -2362, -2362,  1798, -2362, -2362,  1856, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1499,   -42, -2362, -2362,  1796,   -67,
    1891,   968,   306, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     149,    78, -2362, -2362, -2362,   611, -2362, -2362, -2362, -2362,
   -2362, -2362,   582, -2362, -2362, -2362, -2362,   582,   569,   569,
   -2362, -2362, -2362, -2362, -2362,  1592,  1079, -2362,  1079,  4572,
   -2362,   -72,   -13,    59, -2362, -2362, -2362,  2038,   948, -2362,
   -2362, -2362, -2362,  1601,  1343,   189,  1604,   306,  1272, -2362,
   -2362,  2047, -2362, -2362, -2362, -2362,   265, -2362,  1916, -2362,
    1032,  1482,  1791, -2362, -2362,  1079, -2362,  1079,   637, -2362,
   -2362, -2362,  1038, -2362, -2362,   948,  5485,   541, -2362, -2362,
   -2362,  1807, -2362, -2362,  1846, -2362, -2362, -2362, -2362,  1579,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,   -26, -2362,   948, -2362, -2362, -2362,   852, -2362,
   -2362, -2362,  7131, -2362,  5485,  5485,  1646,  1780,  1499, -2362,
    1079, -2362,   306, -2362,  1799, -2362,  1272, -2362,  1996,  1679,
   -2362,    58, -2362,   587, -2362,  1585, -2362,   948, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,  1333, -2362, -2362,    -8, -2362,
     948, -2362, -2362, -2362, -2362, -2362, -2362,   736, -2362,   463,
     736, -2362, -2362, -2362,    91,  2067,  3375,  1856, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,  1705,  1914, -2362, -2362, -2362,
    1915, -2362, -2362, -2362, -2362, -2362, -2362,  1826, -2362,  1505,
   -2362, -2362, -2362, -2362,   948, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,  3011, -2362, -2362, -2362,  1341,
   -2362, -2362, -2362,  1138, -2362,   968,  1764,   968,  1774, -2362,
   -2362,  5485, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,  1343, -2362,  2022, -2362,  1421, -2362, -2362, -2362,   306,
    1137, -2362, -2362,  1137,   -70,   948, -2362, -2362,   968, -2362,
   -2362,  1739, -2362,  2077,  1868,  1892,   430, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     822, -2362, -2362, -2362, -2362, -2362,  1835,  1032,  1705,   968,
    1641, -2362,  2078, -2362,  1583,  2041,  1583,  1646, -2362, -2362,
   -2362, -2362,  1847, -2362, -2362, -2362, -2362,  1344, -2362,   948,
    1196, -2362, -2362,   536, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,   582, -2362, -2362, -2362,   582,   -15, -2362, -2362,
    1032, -2362, -2362, -2362,  1032, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  2082, -2362, -2362,     5, -2362,  2129, -2362, -2362,
   -2362,  3375, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     948, -2362, -2362, -2362, -2362,  1138, -2362,  1079, -2362,  1079,
   -2362, -2362, -2362,  2092,  2032,  1137,  1137, -2362,  1688,  1688,
   -2362,  1806,  1198,    -9, -2362,   948, -2362, -2362,  5485, -2362,
    1032,   655,  1883,  1884, -2362,  1885, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362,   948, -2362, -2362, -2362, -2362,  1697, -2362,
     948,  1583, -2362,   948, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,  1212,  1032,  1032,   165, -2362, -2362, -2362, -2362, -2362,
   -2362,  1552, -2362, -2362, -2362,  2040,   582,   582,  1032,   569,
     569, -2362,   536, -2362, -2362, -2362,  1705,  1705,  5485, -2362,
    1137, -2362,  5485,  5485,  1032,  1198,  1198,  1813, -2362, -2362,
    1673,   948, -2362, -2362,  1807, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  1352, -2362, -2362,   948, -2362, -2362, -2362,  1032,
     536,   536, -2362,  1941,  1032,  1032, -2362,  3412,  1701, -2362,
   -2362,   463, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,   411,  1198,  1032, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362,  1258, -2362, -2362, -2362, -2362,  2050, -2362,
     536, -2362, -2362, -2362,   536,   536,  1938,  1861,   546,  1385,
    1879,  1672,  1032,  1505, -2362,  1032,  1032,   948, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,   459, -2362, -2362,   -51, -2362, -2362, -2362,  1130,  1759,
   -2362, -2362, -2362,   411, -2362,  1804,  1760,  1548, -2362, -2362,
   -2362, -2362, -2362,  1940, -2362,  1032, -2362,  1360,  1854, -2362,
    7169,  7169,  1674,  2058,  1983,  1924,  1924, -2362, -2362, -2362,
    1385, -2362, -2362, -2362, -2362,   653, -2362, -2362,   948, -2362,
     800,    55, -2362,   901,  1374, -2362, -2362,  1499,  7147, -2362,
   -2362,   943,   962, -2362, -2362,  1072, -2362, -2362, -2362, -2362,
      -6,    -2, -2362, -2362, -2362, -2362, -2362,  7169, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,  1848,   -82,    55, -2362, -2362,
    1862, -2362, -2362,  1385,  1385, -2362, -2362, -2362,  1725, -2362,
    1548,   948, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,  2135, -2362,  1548, -2362, -2362,
    1881,   948, -2362, -2362, -2362, -2362,  1766,     0, -2362,  7169,
      10, -2362, -2362,  1385, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1198, -2362
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2362, -2362, -2362, -2362, -2362,  2181, -2362, -2362, -2362,   211,
   -2362,  2143, -2362,  2098, -2362, -2362,  1340, -2362, -2362, -2362,
    1395, -2362, -2362,  1273,  2166, -2362, -2362,  2066, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1994,
     579, -2362, -2362, -2362, -2362, -2362,  2046, -2362, -2362, -2362,
   -2362,  1991, -2362, -2362, -2362, -2362, -2362, -2362,  2123, -2362,
   -2362, -2362, -2362,  1978, -2362, -2362, -2362, -2362,  1962, -2362,
   -2362,   458, -2362, -2362, -2362, -2362,  2051, -2362, -2362, -2362,
   -2362,  2025, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1124, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,  1684, -2362,  1795, -2362, -2362, -2362,
    1737, -2362, -2362, -2362, -2362,   341, -2362, -2362,  1923, -2362,
   -2362, -2362, -2362, -2362,  1790, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
    1201, -2362, -2362, -2362,  1439, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  -299,
   -2362, -2362,  1714, -2362,  -756,  -826, -2362, -2362, -2362,  -533,
   -2362, -2362, -2362, -2362,   -56, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -1396,   796,  1479,   512,   543, -1395, -2362, -2362,
   -2362,  -370,  -440, -2362, -2362,   361, -2362, -2362,    69, -1391,
   -2362, -1389, -2362, -1388, -2362, -2362,  1434, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362,   266, -1779, -2362, -2362, -1218, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -1147, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,  1386,
   -2362, -2362, -2362,    45,    46, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362,  1210,   236, -2362,   180,
   -2362, -2362, -2362, -2362, -1828, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362,  -181, -2362, -2362,  -695, -2362,  1455, -2362, -2362,
   -2362, -2362, -2362, -2362,  1036,   515,   513, -2362,   433, -2362,
   -2362,  -124, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,   483, -2362, -2362, -2362,  1027, -2362, -2362, -2362, -2362,
   -2362,   793, -2362, -2362,   203, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   799, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,   775, -2362, -2362, -2362, -2362,
   -2362,    24, -1746, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,   757, -2362, -2362,   758, -2362,
   -2362,   435,   208, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
      13,   722, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362,   716, -2362, -2362,   191, -2362,   415, -2362,
   -2362, -1625, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362,   964,   710,   184, -2362, -2362,
   -2362, -2362, -2362, -2362, -1451,   965, -2362, -2362, -2362,   182,
   -2362, -2362, -2362,   394, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
     349, -2362, -2362, -2362, -2362, -2362, -2362,   689,   170, -2362,
   -2362, -2362, -2362, -2362,  -132, -2362, -2362, -2362, -2362,   373,
   -2362, -2362, -2362,   945, -2362,   944, -2362, -2362,  1161, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,   153, -2362,
   -2362, -2362, -2362, -2362,   939,   367, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,    -5, -2362,
     368, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -2362, -2362,  -349, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362,  -179, -2362,   661, -2362, -2362, -1644, -2362, -2362,  -656,
   -2362, -2362, -1561, -2362, -2362,    -3, -2362, -2362, -2362, -2362,
     -96, -2187, -2362, -2362,   -10, -1825, -2362, -2362, -1832, -1534,
   -1068, -1440, -2362, -2362,   776, -1678,   175,   179,   185,   186,
    -911,     2,  -706,   313,   344, -2362,   656,  -566, -1399, -1078,
    -361,   980, -1535,  -392,  -402, -2362, -1298, -2362, -1039, -2361,
     861,  -530,   -98,  2011, -2362,  1624,  -560,    22,  2164, -1066,
   -1017,   122,  -976, -2362, -1091, -1358, -2362,   422, -1277, -1876,
   -1086, -1155, -1084, -2362, -2362, -2362, -1106, -2362,  -864,   407,
    -582, -2362, -2362,  -103, -1177,  -759,   -99,  2048, -1325,  2079,
    -673,  1463,  -544,  -348, -2362, -2362, -2362,  -107,  1350, -2362,
   -2362,   343, -2362, -2362, -2362, -2362, -2362, -2362, -2362, -2362,
   -2362, -1953, -2362, -2362,  1574, -2362, -2362,  -200,  -591,  1903,
   -2362,  1141, -2362, -1304,  -285,  -621,   849, -2362,  1816, -1425,
   -2362, -1180, -2362, -2362,   -61, -2362,    -4,  -654,  -357, -2362,
   -2362, -2362, -2362,  -228,  -247, -2362, -1186, -1514,  2114,  1882,
   -2362, -2362,  -334, -2362, -2362,  1064, -2362, -2362, -2362,   414,
   -2362,   267, -1924, -1468, -2362, -2362, -2362,  -167,   475, -1387,
   -1701, -2362, -2362, -2362,  -567, -2362, -2362,  1632, -2362,  1794,
   -2362, -2362, -2362,   789, -2362, -2236,  -239, -2362, -2362, -2362,
   -2362, -2362, -2362
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1847
static const yytype_int16 yytable[] =
{
     139,   427,   139,   428,   689,   138,   741,   141,   139,   415,
     579,   759,  1014,   147,   245,  1253,  1433,   160,  1346,   778,
     838,  1238,  1700,  1702,   404,   990,   215,  1703,  1867,  1704,
    1705,  1710,   139,   427,  1768,  1871,  1264,   180,   696,  1859,
    1827,  1752,   268,   464,  1284,  1599,  2178,   437,  1460,  1616,
     279,  2195,   103,   104,   105,  1592,  1219,  2040,  1345,  1821,
     111,  2102,   463,  1848,  2646,  1469,  1328,   733,   790,  1398,
    1190,   843,  1452,  1498,  2242,    99,   768,   975,   220,   411,
    1816,   246,   107,  1409,  2209,   838,  2129,   211,  -670,  1275,
    1996,  -668,  1190,  1275,  1812,   134,   135,  1784,   136,  2038,
     291,   321,  1830,   143,   144,   535,   259,  1275,   114,   825,
    1745,  1849,   161, -1561,  2445,   790,  1000,  1209,  1555,  1546,
     264,   700, -1567,   360,   392,  1252,  1256,   345,  2449,   169,
   -1846, -1846,  1416,  1508,  1743, -1562, -1565,  1162,  1298,  1300,
   -1802,  1955,  1162,  1453,  1565,   215,   480,  1190,  1946, -1589,
     517,  1717,   297, -1846,  2184,  2391,   219,  1357,  1209, -1780,
     701,  1863,   681,  1190,   413, -1846,  1333,   529,   821,   821,
    2669,  1605,   505,  1612,  2672,  1962,  2695,  1428,  1219,  2171,
    2699,    42,   222,   221,  1787,  2298,   283,   251,   -96,  1915,
   -1846,  2257,  -500,   453,  2466,  1816,   327,   127,  2494,   258,
     693, -1748,   419,   796,  1976,  2163,    23,  2232,  1007,  2024,
    2181, -1744,     4, -1744,  2475,  2308,   821,   980,   822,  2492,
    -500,  -500,   405,   717,  2678,  1921,  -670, -1846, -1802,  -668,
    -670,  1850,  2127,  -668,  1383,  2700,  2240,   535,  1443,     3,
     274,   275,    43,  2701,  1216,   295, -1567,   583,   525,  1294,
    2649,  2047,    18,   299,  2493, -1846,  2679,  1539,   155, -1846,
     156,  1294,  1158,   783,  1410,   997,  2301,  1539,   418,  1847,
      94,  2487,  1333,   406,  2072,  1597,  2680,  1848,  2600,   999,
    1162,  2488,  1977,  1176,   518,   611,  2649,  2517,  -670,  1775,
    1537,  -668,    24,   718,   311,  1851,   128,   212,  1746, -1833,
     284, -1631,  2086,    43,   314,   243,  2210,  1680,  2467,  1681,
     694,  1216,  1963,   709,  2205,   747,  2058,  1916,   204, -1846,
    1556,  1180,  2073,  1162,  1275,  1849,  2314,  2702,  1539,   -96,
    2088,  1926,   682,   601,  1162,  -500,  1785,  1931,  1420,   280,
     139,  1598,   139,   139,  2243,   223,  1613,   485,   486,   139,
    2309,  2194,  1925,     5,   491,  2337,  2629,  2011,   493,   410,
    2139,   281,  1238,  -500,   744,  1162,   139,  1938,  2063,   507,
     507,   485,   507,  1147,   283,   507,   514,  2066, -1748,  1357,
       5,   783,  1821,  2387,   519,  1821,  2211,   424,  1214,  1150,
    1151,  2171,  1547,   823,   137,   989,  1156,  -675,   436, -1744,
   -1748,   980,   980,   980,  1421,   826,   243,   443,   444,   465,
     445,   446,   243,   139,   187,  1238,   452, -1750,   542,  -673,
     137,   188,  1378,   980,   728,   448,  1523,  2392,   154,  -670,
    1264, -1780,  -668,   469,   154,   985,  1363,   139,   139,  1290,
    1181,  1182,   542,   580,  2284,  1850,  1387,  1387,  1387,   492,
    2201,   702,  -500,  2263,  1566, -1748,  1995,   512,  2039,  1400,
    1402,   368,   137,  1548,  1753,  1163,  1408,   260,   187,   137,
    1163, -1748,  -675,   243,   747,   188,   139,   749, -1744,   129,
   -1082,   580,  1238,  1470,   536,  2244,    97,  2450,   284,  1364,
    2056,  1862,   137,   686,  -673,   139,  2324,   767,   137,  1900,
     697,  1832,   137,  1781,   137,  1786,  2074,  1901,   996,  1851,
    2052,   540,  1817,   844,   394,  1164,  1811,  1813,   749, -1748,
    1646,   752,  1852,  1818, -1082,   292,  1234,  1207,   980,  1967,
     577,   753,  1875,  1001, -1082,  1207,  1207, -1775,  2212,  1363,
    1275, -1748,  1363,  2363,   783,   732,  1238,   735,  1207,  1207,
     591,   322,   593, -1647,  1537,   598,   600,  1499,   602,   137,
    1937,   137,   752,  1415,  2005,   394,   989,  1207,  1207,   149,
     265,   243,   753,  2282,  1721,   346,  2476,  2009,  2071,   980,
    1539,   130,  -500, -1529,  1864,   679,   980,   980,   980,  1470,
     688,   745,  1364,   261,  1939,  1364, -1748,   699,   607,   980,
     980,   980,   980,   980,   980,   980,   980,  1149,  1163,   980,
    2206,   754, -1748,  1821, -1082,  2110,   536,  2502,  2503,   985,
     985,   985,  1435,   243,   255,  1898,   189,  1817,   704,  2040,
    1541,   466,  2385,  2386,  2365, -1833,  1913,  1914,  1818,  1167,
    1918,   985,  1207,  1600,  1168,  2215,  2402,  2235,  1922,  2237,
    1484,  1163,   754,   187,  1448,   740,   832,   430, -1627,  1508,
     188,  1006,  1163,   824,  2659,  2033,  2403,  1216,   829,   834,
     834,    94,  1902, -1815,  2376,   211,  2378,   749,  1238,   216,
     189,   755,   949,   991, -1082,  1207,   467,  1680,  2268,  1681,
    2658,  2018,  2404,  1163,  1492, -1529,   772,  1234,   190,   773,
    1207, -1629,   351,   449,  1903,   137,  1233,  2396,  1246,  1286,
    1773,  1167, -1624,  1234,  2130,  2163,  1168,  2405,  1198,  1228,
     839,   752,   755,  2017,  2001,   756,  1904,  1320, -1082,  1325,
    1207,   753,   749,  2075,  1351,  1362,  1852,  2414,  2415,  1665,
    2496,  2299,  2015,  1658,   187,  2052,   985,   412,  1373,  1444,
     325,   188,   190,  2082,   191,  2585, -1846, -1846,  2274,   192,
    1770,  1327,  2460,  1420,  1291,   450,   756,  1666,  1667,   137,
    1317,   956, -1082,   957,   253,   757,   752, -1846, -1082,  1905,
      15,  1377,   344,    16,  2099,   839,   753,  2384,  2595,  1207,
    2122,  2258,  2163,  2123,  1207,  2085,  2569,   985,  1223,   737,
    1643,  -665,  2034, -1846,   985,   985,   985,  1394,   191, -1846,
     137,   754,  1394,   192,   400,   715,   757,   985,   985,   985,
     985,   985,   985,   985,   985,   154,  1394,   985, -1846,  1421,
    1807,  1808,  1809,  1810,    27,   253,   305,   717,   154,  1906,
    1454,   705,   963,   154,  1275,  1539,  1773,    28,   581,  2083,
    1463,  1748,  1472,  1428,  1661,  2316,  1437,  2465,  1333,  1423,
    1332,  2160,   193,   254,  2019,   189,   754,  2586,   747,  2303,
     217,   413,   716,  1493,  1751,  1720, -1760,   431,  1769,  1317,
    2131,   755,  2176,  1545,   170,   212,  1775, -1744,  1644, -1744,
     -35,   228,  2216,  2217,  2218,  2507,  2508,   139,   139, -1846,
     980,  2188,  2189,   749,   137,  2190,  1882,   720,  2315,   748,
      94,  1185,  1475,  1207,   137,   137,   255,   182,   706,   749,
     707,  1127,  2596,  2112, -1846,   756,  1207,  1751,   171,   243,
    2406,  2513,  2230,  2230,  1907,   229,   755,   190,   172,  -665,
    1876,   738,   956,  -665,   957,   230,  2278,   752,  2226,  1224,
    1942,  1225,  1523,  2227,  1721,  2219,   189,   753,   956,  1625,
     957,  2643,  1317,   752,  1207,  2644,  1601,   137,  2236,  1877,
    2238,   582,   137,   753,  1234,   757, -1529,   306,  1333,   717,
     756,  2574,   243,   137, -1529, -1529,  2246,  1945,   980, -1529,
     328,  1583,  1222,   191,  1751,  2010,  1242,  1626,   192,  1668,
    1424,  -665,  1602,  1242,  1277,   183,  2326,  1242,  1234,  1238,
    1295,  1128,  1008,   963,   129,  1316,  2090,  1323,   173,  1323,
    1331,  1348,  1295,  2370,   137,   232,   717,     5,   190,   963,
     757,   470,   471,   472,    33,  1207, -1815,   754,  2281,  1323,
     137, -1846, -1846,   154,   243,  1576,  1207,  1207,   252,   722,
    1207,    36,  1129,   754,  1627,  2616,  1301,  2528,  1751,  1510,
    1511,  2572,  1238,  2611,    39,  2327,  1458, -1846,  1539,  2317,
      40,   749, -1762,   137,   416, -1744,  1949,  2220,  2221,  1774,
     717,  1130,  2222,    48,   191,  1234,   137,  1244,   174,   192,
     980,   137,  2172,  2333,  1577,   233,   724,  2172,  1512,  1513,
     316,  2548,  2549,   750,   751,  2441,  2551,   755,  2552,  2553,
    2568,  1302,   361,    49,  1222,   752,   130,  1544,   985,  1303,
    2273,   117,  2607,   755,  2420,   753,  2423,  2506,  1608,  1669,
    2664,    52,   175,  2031,  1242,    51,  1455,   394,   712,   298,
     243,   394,  -665,  1464,   362,  2388,  2687,  2041,  1586,  2665,
     726,   756,   473,  2533, -1744,  2704, -1844,   154,  2292,  2292,
    1234,   317,   318,  2690,   438,  2003,   474,   756,   329,   515,
      93,  1242,  2666,  1790,  2389,  1131,  1791, -1846,    53,   608,
     749,  1242,   176,  1792,  1793,  1615,  2650,  2651,  1609,   236,
     982,  1610,   100,  1202,  2328,   137,   747,  2168,  1639,  2329,
    1169,   757,   742,  1304,  1177,   754,   985,   516,  1569,  1170,
     439,   137,   609,   749,   749,  1766,    54,   757,    55,   956,
      56,   957,  2652,  1251,   752,  1331,  1570,   330,    57,  1794,
    2653,  1883,  2617,  2619,   753,   743,  2599,   300,  1242,  2602,
    1767,  2485,  1242,   403,  1879,  2006,  1267,    97,  2443,   475,
    2200,   441,  2444,   956,  1456,   957,  1360,   752,   752,  2667,
    2663,   476,   819,   819,    94,  2380,  2451,   753,   753,   952,
    2599,  2599,  2531,  2532, -1775,   755,   139,  1950,  1951,  2675,
    1167,  1640,  2668,   243,    58,  1168,   953,  1458,  1932,    26,
     963,   749,  1167,   820,   820,  2575,  2103,  1168,  1795,  2456,
    2270,  2457,    94,  1394,   101,    94,    47,  1524,   985,  1525,
     819,   139,  2578,  2003,   754,    91,  2579,  2580,  2487,   756,
     106,  2104,  1826,   108,   963,  2271,   109,  1796,  2488,   154,
     956,  2698,   957,  1207,  2225,   752,  1317,  1754,   594,  2204,
     595,   820,  2325,  2230,  2230,   753,  2505,   754,   754,  1797,
     114,   477,   226,    21,    22,  1837,  1259,  2591,  1838,  1839,
    2162,  1834,  2499,  2500,  2654,   120,   749,  1260,   110,   757,
    1268,  1269,    46,  2431,   982,   982,   982,    60,   112,  2006,
     155,  1896,   156,  2432,   755,   113,  1868,  1270,   954,  1647,
    1754,   122,  1897,  1651,  2204,  1866,   982,    13,   124,   749,
    1653,   963,    13,  1798,   592,   956,  2433,   957,  1660,   599,
     752,  2042,  2043,  1673,  1709,  2571,  1711,   755,   755,  1887,
     753,    61,  2470,  2196,  1397,   754,  2290,  1419,   756,  2603,
    2604,  1419,  1204,   706,  1167,   707,  2434,  1222,   956,  1168,
     957,  1271,   126,   752,  1912,   958,   959,   960,  2638,  2639,
     227,   961,   137,   753,  1242,  1655,  1799,  1754,  1205, -1760,
     140,   756,   756,  1975,   142,  1167,  1894,   149,  1222,  2204,
    1168,   162,   137,  1985,  1986,   428,   963,  1989,   757,  2518,
    1403,  1404,  2509,  2158,   749,  1836,  2510,  2511,  1837,   163,
     962,  1838,  1839,  1167,  1242,   755,  1389,  1390,  1168,  1201,
     754,  1215,   164,   167,  1231,   243,   137,   181,  1254,   963,
      64,   757,   757,  1405,  1406,  1407,  1800,  1166,  2519,  1289,
    1630,  1754,  1631,  1656,   185,  1315,  1167,  1924,   752,  1801,
    1207,  1168,  1167,   754,   186,   204,   228,  1168,   753,   756,
     351,  1934,  1935,  1936,   139,   193,  1371,  1940,  1375,  1933,
    1943,  1944,   982,    67,   242,  1964,  2520,  1965,   247,   982,
     982,   982,  1392,  2035,   964,  2036,   980,  1392,  1207,  1207,
     755,   118,   982,   982,   982,   982,   982,   982,   982,   982,
     229,  1392,   982,   137,    52,  2321,  2204,  2322,   249,   757,
     230,  1970,   248,  2372,  2026,  2373,  2428,   508,  2429,   510,
    1893,  2030,   511,   755,   231,  1910, -1545, -1545, -1545, -1545,
    1434,  1802,  1978,   250,   756,   965,   966,  1727,   754,  1728,
    1840,  1841,   257,  1157,    68,  1159,   269,  2319,   555,   273,
     278,    53,   294,  1440,  1315,   296,  1231,  1486,  1487,  1488,
    1489,   154,   302,   556,  1842,  1843,   300,   756,   303,  1242,
     307,   308,  2059,  1242,   309,   312,  1242,   970,   137,  1222,
     313,  1947,  1948,   334,   757, -1544, -1544, -1544, -1544,    54,
     232,    55,  1961,    56,   326,  1207,   333,   971,   336,  1966,
     338,    57,   972,   557,   721,   723,   725,   727,   755,   973,
     340,   137,   342,   349,   351,   356,   428,   757,   353,   354,
    2092,   392,   394,   397,   398,   401,   403,  2105,  1979,  1242,
     408,   187,   243,   409,   420,   421,   422,  1315,   429,   413,
     454,   455,   459,  -342,  2266,   457,   483,  2620,  2492,   490,
     487,   494,   756,   495,   502,   509,   521,    58,   523,  1593,
     233,   522,   533,   234,   235,   527,   543,   547,   548,   549,
     551,   552,  2137,  1840,  1841,  -355,   554,   578,  1242,  1242,
    1242,  2137,  1887,  2621,   585,  1621,   586,  2025,  2113,  2114,
    2115,  2116,  2117,  2118,  2119,  2120,   137,  1842,  1843,   587,
    2487,   603,   757,   605,   985,   613,  2032,   610,   685,   698,
    2488,   687,  2037,   690,   614,   730,   711,   736,   728,    59,
     765,   769,   746,   762,   777,   771,   781,   786,   783,  2191,
     791,   797,   780,    94,   823,   793,   830,   836,  1242,   950,
     558,  1725,  1726, -1631,   989,  2197,   994,   995,   998,  1011,
      60,   559,  1207,  1016,   236,  1593,  1019,  1116,  1135,  1143,
    1145,  1152,  1153,   139,  1171,  1183,  2224,  1187,  2159,  1154,
    1155,  1160,  1189,  1196,  1257,  1172,  1197,  1378,  1295,  1411,
    1174,  1412,  1727,  1295,  1728,  1175,  1729,  1278,  1385,  1413,
    1386,  1426,  1396,   982,    61,  2247,  1432,    62,  1438,  2249,
    2182,  1447,  1295,  1295,  1449,  1467,  1295,  1461,  1476,  1473,
    1538,  1541,  1207,  1490,  1554,  1496,  1207,  1207,  1557,  1494,
    1730,  1731,  1732,  1558,  1560,  1562, -1547,  1571,  1242,  1572,
    1573,  1574,  1579,  1581,  1333,  1584,  1202,  1588,  2277,   747,
    1604,  2092,  1590,  1606,  1190,  1617,  1629,  1622,  2157,  1295,
    2276,  1633,   560,   561,  1295,  1295,  1295,  1635,  1637,  2231,
    2231,  1641,    63,  1242,  1648,  1242,  2161,   562,  1649,   563,
    1733,  2641,  1734,  1593,  1662,  1650,  1652,  1654,  1657,  1735,
    1659,   982,  1736,    64,  1664,  2177,  1712,  2179,  1713,  1715,
    1718,  2180,  1749,  1757,  1761,  1756,  1759,  1874,  2606,  2185,
    1216,  1771,  1242,  1782,  1242,  1788,  1881,  1775,    65,  1478,
      66,  1822,   952,  1825,  1833,  2622,  1805,  1890,  1846,  2623,
    2624,  1547,  1869,  1861,  1892,  1888,    67,  1884,  1899,   953,
    1920,  2364,  1954,  1927,  1968,  1974,  1971,  2366,  1981,  1980,
    1983,  1990,  1998,  1997,   980,   980,  1919,  2369,  1790,  1993,
    1994,  1791,   564,  1999,  1720, -1517,  1593,  1242,  1792,  1793,
    2625,  2000,  2012,  2016,  2022,  2023,  2027,  1428,  2046,  1737,
    1295,  1738,   980,  2048,   139,  2053,  2626,  2627,  1392,   542,
    2054,  2060,  1895,   982,  2061,  2064,  2067,  2068,  1333,  2093,
    2087,   980,  2095,   428,  2096,  2099,  2265,    68,  2106,   565,
    2107,  1960,  2133,  2140,  1794,  2141,  2142,  2143,  2152,  2154,
    2186,  1315,  2192,  2198, -1566,  2233,  2259,  2407,  2278,  2250,
    2408,  2409,  2256,  1972,  2262,  2267,  1973,  2294,  2280,  2304,
    2297,   954,  2302,  2410,  2338,  2306,  2006, -1522, -1564,  2397,
    2367,   428,   749,   980,  2382,  2377,  2398,  2425,  2426,  2400,
    2399,  2411,  1242,  2416,  1242,  2379,  2421,  2451,  2448,  2309,
    1593,  2458,  2459,  2464,  2461,  2477,  2478,  2479,  2483,  2498,
    2514,  2533,  2570,  1795,  2515,  1204,  2004,  2577,  1478,  2581,
    2583,   956,   139,   957,  2588,  1242,   752,  2394,   958,   959,
     960,  2608,  2612,  2589,   961,  2615,   753,  2636,  2609,  2637,
    2163,  1205,  1796,  2683,  2689,  2676,  2454,  2691,    17,    92,
     125,  2693,    38,   166,   209,   256,  1242,   266,   119,   277,
     290,   210,   241,   545,  1797,   442,   504,  2089,   799,   323,
    1184,   526,   835,   962,  1701,   456,   139,  2614,  2686,   787,
    2081,   580,   993,  2170,  2318,  2334,  2335,  1015,  1195,  1295,
    2480,  2241,   963,  1295,   948,  1987,  1430,  2453,  1988,  2045,
    1739,  2014,   985,   985,  1446,  1764,   984,   800,   801,   802,
     803,   804,  2239,  1765,  1780,  1815,   754,  2375,  1798,  1823,
    2057,  2245,  1593,  1593,  2381,  1845,  1857,  2261,  2069,  1561,
     985,  1865,  2269,  2097,  1242,  1564,  1242,  2272,  2151,  2283,
    1891,  2121,   626,   627,  1595,  1596,  1349,   964,  2293,   985,
    1740,  2098,  2469,  2413,  1620,  2149,  2150,  2419,  2682,  1593,
    1930,  1741,  2427,  2286,  2424,  2474,  1829,  2287,  1587,  1763,
     332,  1799,   428,  2288,  2289,   764,   213,  2111,   310,   795,
     447,   293,  1161,  2576,  1414,   539,   755,  2138,  2463,   272,
    2135,   489,  2255,  2080,  2148,  2148,  2446,   774,   965,   966,
    2447,   985,  1860,  1295,  1295,     0,  1295,  1295,   747,  1295,
    2231,  2231,   597,  2630,  1231,     0,     0,     0,     0,  2166,
       0,     0,     0,  1896,  1960,  1960,     0,     0,     0,     0,
     756,  1800,     0,     0,  1897,     0,     0,     0,     0,     0,
     970,     0,     0,     0,  1801,   805,   806,   807,   808,   809,
     810,   811,   639,   640,     0,     0,  2471,     0,     0,     0,
     971,     0,     0,     0,     0,   972,     0,     0,     0,  1222,
       0,     0,   973,     0,   137,     0,     0,     0,  1148,  2203,
     757,   952,     0,     0,     0,     0,     0,     0,  2490,  2491,
     984,   984,   984,     0,     0,     0,     0,     0,   953,     0,
    2587,     0,     0,     0,  2501,     0,     0,     0,     0,     0,
       0,     0,   984,     0,     0,     0,     0,     0,     0,     0,
    2512,     0,     0,     0,     0,  2248,  1802,     0,     0,     0,
    1222,   357,     0,     0,  2203,  1593,     0,     0,     0,     0,
       0,     0,     0,  1593,     0,  2530,   358,     0,     0,     0,
    2534,  2535,     0,     0,     0,     0,   359,     0,     0,     0,
       0,  2640,  1874,     0,     0,     0,   952,     0,  1222,     0,
    2573,     0,     0,     0,  2657,     0,     0,     0,     0,     0,
       0,     0,     0,   953,     0,     0,     0,     0,     0,     0,
     360,  2285,     0,     0,     0,     0,     0,   812,  2590,   982,
     954,  2592,  2593,     0,  1222,     0,     0,     0,     0,  2203,
     813,   749,     0,  1593,  2684,  2685,     0,   984,     0,     0,
       0,     0,  1243,     0,     0,     0,     0,     0,     0,  1243,
       0,     0,     0,  1243,     0,     0,     0,  1960,  2692,     0,
       0,  2613,     0,     0,     0,     0,  1231,  1243,     0,     0,
       0,     0,     0,     0,  2705,   752,     0,   958,   959,   960,
       0,     0,   846,   961,   847,   753,   848,     0,   984,     0,
       0,   849,     0,     0,     0,   984,   984,   984,  1393,   850,
       0,  2371,     0,  1393,     0,   954,     0,     0,   984,   984,
     984,   984,   984,   984,   984,   984,   749,  1393,   984,     0,
       0,     0,   962,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   851,   852,     0,     0,     0,     0,     0,     0,
       0,   853,     0,     0,     0,     0,  2203,  1436,     0,     0,
       0,     0,   854,     0,     0,   855,     0,     0,     0,     0,
     752,     0,   958,   959,   960,   754,     0,   361,   961,   856,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   857,     0,     0,     0,   964,     0,     0,   362,
     858,     0,   859,     0,     0,     0,     0,   962,     0,  -228,
    2166,     0,     0,     0,     0,     0,     0,  1243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1243,     0,     0,
       0,     0,     0,   860,     0,   755,     0,     0,     0,     0,
       0,     0,     0,     0,   861,     0,     0,   965,   966,   862,
     754,     0,     0,     0,     0,     0,     0,  2455,     0,     0,
       0,     0,   363,     0,     0,     0,     0,   364,     0,     0,
       0,     0,     0,     0,     0,  1594,   863,     0,     0,   756,
       0,   964,     0,   864,  1243,     0,   865,   866,  1243,   970,
       0,     0,     0,     0,     0,     0,   867,     0,   365,     0,
    2481,     0,     0,   868,     0,   869,   366,  2484,   870,   971,
    2486,     0,     0,     0,   972,     0,     0,     0,     0,   367,
     755,   973,     0,   137,     0,     0,     0,     0,     0,   757,
       0,     0,   965,   966,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   368,     0,
     871,   369,     0,     0,   872,     0,   873,     0,  2516,   370,
       0,     0,     0,     0,   756,     0,   874,     0,     0,     0,
    -225,  1594,  2529,     0,   970,     0,     0,  2166,  2166,     0,
       0,     0,     0,  1755,     0,     0,     0,     0,  1231,     0,
       0,     0,   875,     0,   971,     0,     0,     0,   371,   972,
       0,   372,     0,     0,     0,   876,   973,     0,   137,   984,
       0,     0,     0,     0,   757,     0,     0,  2166,     0,     0,
       0,  2166,  2166,     0,     0,     0,     0,     0,     0,     0,
     877,   878,     0,     0,  2594,     0,  1755,     0,     0,     0,
       0,   879,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   880,   881,     0,     0,     0,
       0,     0,   882,     0,     0,     0,   883,     0,     0,     0,
       0,     0,     0,     0,   884,     0,     0,   982,   982,     0,
       0,     0,     0,     0,   885,     0,     0,     0,     0,  1594,
       0,     0,   846,   886,   847,  2642,   848,   984,     0,     0,
    1243,   849,   887,  1755,     0,   982,     0,   888,   889,   850,
       0,   890,     0,   891,     0,     0,     0,  2671,  2674,   892,
       0,     0,     0,     0,   982,     0,     0,   952,     0,     0,
       0,     0,   893,     0,     0,     0,     0,     0,     0,     0,
    1243,     0,   851,   852,   953,     0,     0,     0,  2688,     0,
     894,   853,     0,     0,     0,     0,   895,     0,     0,     0,
       0,   896,   854,     0,     0,   855,     0,  1755,     0,     0,
       0,     0,  1594,     0,  2697,     0,   982,     0,     0,   856,
       0,     0,     0,     0,     0,     0,     0,     0,   897,     0,
       0,     0,     0,     0,  1393,     0,     0,     0,     0,   984,
       0,     0,   857,     0,     0,     0,     0,     0,     0,     0,
     858,     0,   859,     0,     0,     0,     0,     0,     0,  -712,
       0,  -712,  -712,  -712,  -712,  -712,  -712,  -712,  -712,     0,
    -712,  -712,  -712,     0,  -712,  -712,  -712,  -712,  -712,  -712,
    -712,  -712,  -712,   860,     0,     0,   954,     0,     0,     0,
       0,     0,     0,     0,   861,     0,     0,     0,     0,   862,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   863,     0,     0,     0,
       0,     0,     0,   864,     0,  1243,   865,   866,     0,  1243,
       0,  1451,  1243,   958,   959,   960,   867,     0,     0,   961,
       0,     0,     0,   868,     0,   869,     0,     0,   870,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   962,     0,
       0,     0,     0,     0,     0,  1243,     0,     0,     0,     0,
     871,     0,     0,     0,   872,     0,   873,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   874,     0,     0,     0,
       0,     0,  -712,  -712,     0,  -712,  -712,  -712,  -712,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1594,  1594,
       0,     0,   875,     0,  1243,  1243,  1243,     0,     0,     0,
       0,     0,   846,     0,   847,   876,   848,     0,     0,     0,
       0,   849,   964,     0,     0,     0,     0,     0,     0,   850,
       0,     0,     0,     0,     0,  1594,     0,     0,     0,     0,
     877,   878,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   879,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   851,   852,  1243,   880,   881,     0,     0,     0,
       0,   853,   882,   965,   966,     0,   883,     0,     0,     0,
       0,     0,   854,     0,   884,   855,     0,  2339,     0,     0,
    2340,     0,     0,  2341,   885,     0,     0,     0,     0,   856,
       0,  2342,     0,   886,     0,     0,     0,     0,     0,     0,
       0,     0,   887,     0,     0,   970,     0,   888,   889,     0,
       0,   890,   857,   891,     0,     0,     0,     0,     0,   892,
     858,     0,   859,     0,     0,   971,     0,   624,     0,     0,
     972,     0,  -712,     0,     0,     0,  2343,   973,     0,   137,
       0,     0,     0,     0,  1243,     0,  1680,  1727,  1681,  1728,
     894,     0,     0,   860,     0,     0,   895,     0,     0,     0,
       0,   896,     0,     0,   861,     0,     0,     0,     0,   862,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1243,
       0,  1243,  -712,     0,     0,     0,     0,     0,   897,     0,
       0,   846,     0,   847,     0,   848,   863,     0,     0,     0,
     849,  1594,     0,   864,     0,     0,   865,   866,   850,  1594,
       0,     0,     0,     0,     0,     0,   867,     0,  1243,     0,
    1243,     0,     0,   868,     0,   869,     0,     0,   870,     0,
       0,     0,     0,     0,  2344,     0,     0,     0,     0,     0,
       0,   851,   852,  2345,     0,     0,     0,     0,     0,     0,
     853,     0,     0,     0,     0,     0,  2346,     0,     0,     0,
       0,   854,     0,     0,   855,   984,     0,     0,     0,     0,
     871,     0,     0,  1243,   872,     0,   873,     0,   856,  1594,
       0,     0,     0,     0,     0,     0,   874,     0,  2347,     0,
       0,  2536,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   857,     0,     0,     0,     0,     0,     0,  2348,   858,
    2349,   859,   875,     0,     0,     0,     0,   642,     0,     0,
       0,     0,     0,     0,     0,   876,     0,     0,     0,     0,
       0,     0,     0,  2350,  2537,     0,     0,     0,     0,     0,
       0,     0,   860,     0,     0,     0,     0,     0,     0,     0,
     877,   878,     0,   861,     0,     0,     0,     0,   862,     0,
       0,   879,     0,  2351,     0,     0,     0,  2538,  1243,     0,
    1243,     0,     0,     0,     0,   880,   881,     0,     0,     0,
       0,     0,   882,     0,     0,   863,   883,  2539,     0,     0,
    2352,  2540,   864,     0,   884,   865,   866,     0,     0,     0,
       0,  1243,     0,     0,   885,   867,     0,     0,     0,   646,
       0,     0,   868,   886,   869,  2541,  2353,   870,     0,     0,
       0,     0,   887,  2354,     0,     0,     0,   888,   889,     0,
       0,   890,  1243,   891,     0,     0,  2355,     0,     0,   892,
    2356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1628,     0,     0,     0,     0,     0,     0,   871,
       0,     0,     0,   872,     0,   873,     0,     0,     0,     0,
     894,   952,     0,     0,     0,   874,   895,     0,     0,     0,
       0,   896,     0,     0,     0,     0,     0,   651,   953,  2357,
       0,     0,     0,     0,     0,     0,  2542,     0,     0,     0,
       0,   875,     0,     0,     0,     0,     0,     0,   897,     0,
    1243,     0,  1243,  2543,   876,     0,     0,     0,  2358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2359,     0,
       0,     0,     0,  2544,  2360,     0,     0,     0,     0,   877,
     878,     0,     0,     0,     0,     0,     0,     0,  1202,     0,
     879,   747,     0,     0,  2545,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   880,   881,     0,     0,     0,     0,
       0,   882,     0,  2546,     0,   883,     0,     0,     0,     0,
     660,  2547,     0,   884,     0,     0,     0,     0,     0,     0,
     954,     0,     0,   885,     0,     0,     0,     0,     0,     0,
       0,   749,   886,     0,     0,     0,     0,     0,     0,     0,
       0,   887,     0,     0,     0,     0,   888,   889,     0,     0,
     890,     0,   891,     0,   952,     0,     0,     0,   892,     0,
       0,  1021,     0,  1022,   955,     0,  1203,     0,  1023,     0,
     956,   953,   957,     0,     0,   752,  1024,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,     0,     0,   894,
       0,     0,     0,     0,     0,   895,     0,     0,     0,     0,
     896,     0,     0,     0,     0,     0,     0,     0,     0,  1025,
    1026,     0,     0,     0,     0,     0,     0,     0,  1027,     0,
       0,     0,   962,     0,     0,     0,     0,   897,     0,  1028,
       0,     0,  1029,     0,     0,     0,     0,     0,     0,     0,
       0,   963,     0,     0,     0,     0,  1030,     0,     0,     0,
       0,     0,     0,   984,   984,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   754,     0,     0,     0,  1031,
       0,     0,     0,   954,     0,     0,     0,  1032,     0,  1033,
       0,   984,     0,     0,   749,     0,  1034,     0,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,   964,  1043,  1044,  1045,
     984,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,     0,     0,     0,     0,     0,     0,  1204,     0,     0,
       0,  1056,     0,   956,     0,   957,  1057,     0,   752,     0,
     958,   959,   960,     0,     0,   755,   961,     0,   753,     0,
       0,     0,     0,  1205,     0,     0,     0,   965,   966,     0,
       0,     0,   984,  1058,     0,     0,     0,     0,     0,     0,
    1059,     0,     0,  1060,  1061,     0,     0,     0,     0,     0,
       0,     0,     0,  1062,     0,   962,     0,     0,   952,   756,
    1063,   968,  1064,     0,     0,  1065,     0,     0,     0,   970,
       0,     0,     0,     0,   963,   953,  1202,     0,     0,   747,
       0,     0,  1504,  1505,  1506,     0,     0,     0,     0,   971,
    1507,     0,     0,     0,   972,     0,     0,     0,   754,     0,
       0,   973,     0,   137,     0,     0,     0,  1066,     0,   757,
       0,  1067,     0,  1068,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1069,     0,     0,     0,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1070,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1071,     0,     0,     0,  1307,     0,   755,   953,
       0,     0,     0,     0,     0,     0,     0,   954,     0,     0,
     965,   966,     0,     0,     0,     0,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1073,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   756,  1074,     0,     0,     0,     0,     0,  1075,
       0,     0,   970,  1076,     0,     0,     0,     0,     0,  1508,
       0,  1077,  1308,     0,   958,   959,   960,     0,     0,  1509,
     961,  1078,   971,     0,     0,     0,     0,   972,     0,     0,
    1079,     0,     0,     0,   973,     0,   137,     0,     0,  1080,
       0,     0,   757,     0,  1081,  1082,     0,     0,  1083,     0,
    1084,   954,     0,     0,     0,     0,  1085,  1510,  1511,   962,
       0,     0,   749,     0,     0,     0,     0,     0,     0,  1086,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1828,     0,     0,     0,     0,  1087,     0,     0,
       0,     0,     0,  1088,     0,  1204,  1512,  1513,  1089,     0,
       0,   956,     0,   957,     0,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1205,     0,  1202,     0,  1090,   747,     0,     0,  1504,
    1505,  1506,     0,   964,  1514,     0,     0,  1507,     0,     0,
    1515,     0,     0,  1516,     0,     0,     0,     0,     0,     0,
       0,  1517,     0,   962,     0,     0,     0,     0,  1518,     0,
       0,     0,     0,  1519,     0,     0,     0,     0,     0,     0,
       0,     0,   963,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1520,     0,   965,   966,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1846,   754,     0,     0,   952,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   953,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   970,   964,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1135,  -872,     0,
       0,  -872,     0,     0,     0,     0,   971,     0,     0,     0,
       0,   972,     0,     0,     0, -1135,     0,     0,   973,   243,
     137,     0,     0,     0,     0,  1202,   755,     0,   747,     0,
       0,     0,     0,     0,     0,     0,  1508,     0,   965,   966,
       0,  1190,     0,     0,     0,     0,  1509,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1521,     0,
    1522,     0,  1523,     0,     0,  1524,     0,  1525,  1526,  1527,
     756,     0,  1528,  1529,  -872,     0,     0,     0,   954, -1748,
     970,     0,     0,     0,  1510,  1511,     0,     0,     0,   749,
       0,  -872,     0,     0,     0,     0,     0,     0,     0,     0,
     971,   952,     0,  1202,     0,   972,   747,     0,     0,     0,
       0,     0,   973,     0,   137,     0,     0,     0,   953,     0,
     757,     0,  1204,  1512,  1513,     0,     0,     0,   956,     0,
     957,  1353,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,     0,     0,     0,  1205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1514,     0,     0,     0,     0,     0,  1515,     0,     0,
    1516,     0,     0,     0,     0,     0,     0,     0,  1517,   952,
     962,     0,     0,     0,     0,  1518,     0,     0,     0,     0,
    1519,  1296,     0,  -872,     0,     0,   953,     0,     0,   963,
       0,     0,     0,     0,  -872,     0,     0,     0,     0,  1520,
       0,  1202,     0,     0,   747,     0,     0,     0,     0,     0,
     954,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,   749,     0,     0,     0,     0,     0,  -872,     0,     0,
       0,     0,     0,  -872,     0,  -872,     0,  1619,  -872,     0,
    -872,  -872,  -872,     0,   964,     0,  -872,     0,  -872,     0,
       0,     0,     0,  -872,  1204,     0,     0,     0,     0,     0,
     956,     0,   957,     0,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,     0,   753,     0,   952,     0,     0,
    1205,     0,     0,   755,     0,  -872,     0,     0,   954,     0,
    -872,     0,     0,     0,   953,   965,   966,     0,     0,   749,
       0,     0,     0,     0,  -872,     0,  1202,  1353,     0,   747,
       0,     0,   962,     0,     0,  1521,     0,  1522,     0,  1523,
       0,     0,  1524,     0,  1525,  1526,  1527,   756,  -872,  1528,
    1529,   963,  1204,     0,     0,     0,     0,   970,   956, -1748,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,     0,   753,     0,   754,     0,   971,  1205,  -872,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,   952,     0,     0,     0,   964,     0,     0,     0,
     962,     0,  -872,     0,  1358,     0,   954,     0,  -872,   953,
       0,     0,     0,     0,     0,     0,     0,   749,     0,   963,
    -872,  -872,     0,     0,  -928,     0,     0,  -928,     0,     0,
       0,     0,     0,     0,     0,   755,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,   965,   966,     0,
    1204,     0,  -872,     0,     0,     0,   956,     0,   957,     0,
       0,   752,  -872,   958,   959,   960,     0,     0,  -872,   961,
       0,   753,     0,     0,   964,     0,  1205,     0,     0,   756,
       0,     0,  -872,     0,     0,     0,     0,  -872,     0,   970,
   -1748,     0,     0,     0,  -872,     0,  -872,     0,     0,     0,
    -928,     0,  -872,     0,     0,     0,     0,     0,   962,   971,
       0,   954,     0,   755,   972,     0,     0,  -928,     0,     0,
       0,   973,   749,   137,     0,   965,   966,   963,     0,   757,
       0,     0,     0,     0,     0,     0,  1202,     0,     0,   747,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,  1204,     0,   756,     0,     0,
       0,   956,     0,   957,     0,     0,   752,   970,   958,   959,
     960,     0,     0,     0,   961,     0,   753,     0,     0,     0,
       0,  1205,   964,  1478,     0,     0,     0,   971,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,   952,   962,     0,     0,     0,     0,     0,  -928,
       0,   755,     0,     0,     0,     0,     0,     0,     0,   953,
    -928,     0,   963,   965,   966,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,     0,     0,     0,
       0,     0,     0,  -928,     0,   756,     0,     0,     0,  -928,
       0,  -928,     0,     0,  -928,   970,  -928,  -928,  -928,     0,
       0,     0,  -928,     0,  -928,     0,     0,   964,     0,  -928,
       0,  1202,     0,     0,   747,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,     0,     0,     0,     0,   757,     0,     0,     0,     0,
       0,  -928,     0,     0,     0,     0,   755,     0,     0,     0,
       0,   954,     0,     0,     0,     0,     0,     0,   965,   966,
    -928,     0,   749,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -928,     0,     0,   952,     0,     0,
     756,     0,     0,     0,     0,  1204,     0,     0,     0,     0,
     970,   956,     0,   957,   953,     0,   752,     0,   958,   959,
     960,     0,     0,     0,   961,  -928,   753,     0,     0,  1202,
     971,  1205,   747,     0,     0,   972,     0,     0,     0,     0,
       0,     0,   973,     0,   137,     0,     0,     0,     0,     0,
     757,     0,  1202,     0,     0,   747,     0,     0,     0,     0,
       0,     0,     0,   962,  -928,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -928,  -928,     0,     0,
       0,     0,   963,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   952,   754,     0,  -928,     0,
       0,  1624,     0,     0,     0,     0,   954,     0,  -928,     0,
       0,     0,   953,     0,     0,     0,     0,   749,   952,     0,
       0,     0,     0,     0,     0,     0,     0,   964,  -928,     0,
       0,  1202,     0,  -928,   747,   953,     0,     0,     0,     0,
    -928,     0,  -928,     0,     0,     0,     0,     0,  -928,     0,
    1204,     0,     0,     0,     0,     0,   956,     0,   957,     0,
       0,   752,     0,   958,   959,   960,   755,     0,     0,   961,
       0,   753,     0,     0,     0,     0,  1205,     0,   965,   966,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   952,   962,     0,
     756,     0,     0,     0,   954,     0,     0,     0,     0,     0,
     970,     0,     0,     0,   953,   749,     0,   963,     0,     0,
       0,     0,     0,     0,  1482,     0,     0,   954,     0,  1750,
     971,     0,   747,     0,     0,   972,     0,     0,   749,     0,
       0,   754,   973,     0,   137,     0,     0,     0,  1204,     0,
     757,     0,     0,     0,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,     0,     0,     0,   961,     0,   753,
       0,  1204,   964,     0,  1205,     0,     0,   956,     0,   957,
       0,     0,  1247,     0,   958,   959,   960,     0,     0,     0,
     961,     0,   753,     0,     0,     0,     0,  1205,     0,     0,
       0,     0,     0,     0,     0,   952,   962,     0,     0,     0,
       0,   755,     0,     0,     0,     0,   954,     0,     0,     0,
       0,     0,   953,   965,   966,   963,     0,   749,     0,   962,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   963,   754,
       0,     0,     0,     0,     0,   756,     0,     0,     0,     0,
    1204,     0,     0,     0,     0,   970,   956,     0,   957,     0,
       0,   752,   754,   958,   959,   960,     0,     0,     0,   961,
     964,   753,     0,     0,     0,   971,  1205,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,     0,     0,   964,     0,   757,     0,     0,     0,     0,
       0,     0,     0,  1917,     0,     0,     0,     0,   962,   755,
       0,     0,     0,     0,   954,     0,     0,     0,     0,     0,
       0,   965,   966,     0,     0,   749,     0,   963,     0,     0,
       0,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   965,   966,     0,     0,     0,     0,
       0,   754,     0,   756,     0,     0,     0,     0,  1204,     0,
       0,     0,     0,   970,   956,     0,   957,     0,     0,   752,
       0,   958,   959,   960,     0,     0,   756,   961,     0,   753,
       0,     0,   964,   971,  1205,     0,   970,     0,   972,     0,
       0,     0,     0,     0,     0,   973,     0,   137,     0,     0,
       0,     0,     0,   757,     0,     0,   971,     0,     0,     0,
       0,   972,     0,     0,     0,     0,   962,     0,   973,     0,
     137,   755,     0,     0,     0,     0,   757,     0,     0,     0,
       0,     0,     0,   965,   966,   963,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
       0,     0,     0,     0,     0,   756,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,     0,     0,     0,
    1013,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     964,     0,     0,     0,     0,   971,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,   973,     0,   137,
       0,  -352,     0,     0,  -352,   757,     0,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,   755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   965,   966,  -352,     0,  -352,     0,     0,     0,     0,
       0,     0,  -352,     0,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   756,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   970,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -352,     0,
       0,     0,     0,   971,     0,     0,     0,     0,   972,     0,
       0,     0,     0,     0,     0,   973,     0,   137,     0,     0,
       0,     0,     0,   757,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   529,     0,     0,  -352,  -352,  -352,
    -352,  -352,   528,     0,  -352,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,  -352,     0,  -352,     0,     0,
       0,     0,  -352,  -352,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,  -352,  -352,     0,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,     0,     0,     0,
       0,  -352,     0,     0,  -352,     0,     0,     0,     0,     0,
    -352,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,  -352,     0,     0,  -352,     0,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,  -352,     0,   952,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,  -352,     0,
       0,     0,     0,   953,     0,     0,  -352,     0,     0,  -352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,   529,     0,     0,  -352,
    -352,  -352,  -352,  -352,     0,     0,  -352,  -352,     0,     0,
    -352,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
    -352,     0,     0,     0,  -352,     0,  -352,  -352,  -352,     0,
       0,     0,     0,  -352,  1307,     0,  -352,     0,     0,     0,
       0,     0,  -352,     0,     0,   954,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
    -352,     0,     0,     0,     0,  -352,     0,     0,  -352,     0,
       0,     0,     0,     0,     0,     0,     0,  -352,     0,     0,
       0,     0,  -352,     0,     0,     0,  -352,  -352,  -352,     0,
    1451,     0,   958,   959,   960,     0,  -352,     0,   961,     0,
    -352,     0,     0,     0,     0,     0,  -352,  -352,     0,     0,
    -352,     0,     0,   530,     0,     0,     0,     0,  -352,     0,
     616,  -352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -352,   617,     0,   962,   618,   619,
     620,   621,   622,   623,   624,     0,  -352,     0,     0,     0,
       0,     0,     0,     0,  -352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   625,     0,   626,   627,   628,   629,   630,   631,
     632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -352,     0,  -352,  -352,
    -352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   964,     0,     0,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352,
       0,     0,   965,   966,     0,     0,     0,     0,  -352,  -352,
    -352,     0,     0, -1846,     0,     0,     0,   634,   635,   636,
     637,   638,  -352,     0,   639,   640,     0,     0,     0,  -352,
       0,     0,     0,     0,     0,   530,     0,     0,     0,     0,
       0,     0,     0,     0,   970,   618,   619,   620,   621,   622,
     623,     0,     0,     0,     0, -1135,     0,     0,   641,     0,
       0,     0,     0,     0,   971,     0,     0,     0,     0,   972,
       0,    94,     0, -1135,   642,     0,   973,   243,   137,   625,
   -1822,   626,   627,   628,   629,   630,   631,   632,  1675,     0,
       0,  1676,     0,     0,  1677,   618,   619,   620,   621,   622,
     623,  1678,  1679,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   643,     0,     0,     0,
    1680,     0,  1681,     0,     0,   633,     0,     0,     0,   625,
       0,   626,   627,   628,   629,   630,   631,   632,     0,     0,
       0,     0,     0,     0,   644,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645,     0,
       0,     0,     0,     0,     0,     0,   646,     0,     0,   647,
       0,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,     0,   648,     0,   634,   635,   636,   637,   638,     0,
       0,   639,   640,     0,   649,     0,     0,     0,     0,     0,
       0,     0,   650,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1682,     0,     0,     0,
       0,     0,     0,     0,     0,   641,   952,     0,     0,     0,
       0,     0,     0,     0,   634,   635,   636,   637,   638,     0,
       0,   639,   640,   953,   651,  1683,   652,   653,   654,     0,
       0,     0,  1684,     0,  1685,     0,     0,     0,     0,     0,
   -1775,     0,     0,     0,     0,     0,     0,  1686,     0,     0,
       0,     0,     0,   655,     0,   641,     0,     0,     0,     0,
       0,     0,     0,   643,     0,     0,     0,     0,    94,     0,
    -349,   642,     0,     0,     0,     0,     0,     0,     0,  1687,
       0,     0,     0,     0,     0,     0,     0, -1822,  1688,     0,
       0,     0,     0,     0,     0,     0,   656,   657,   658,     0,
       0,  1689,     0,     0,     0,   645,     0,     0,     0,     0,
     659,     0,     0,   643,     0,     0,   647,   660,     0,     0,
       0,     0,     0,     0,     0,   954,     0,     0,   952,   648,
       0,     0,     0,     0,     0,     0,   749,     0,     0,     0,
       0,  1690,     0,     0,     0,   953,     0,     0,     0,     0,
       0,     0,     0,     0,  1691,   645,     0,     0,     0,     0,
       0,     0,     0,   646,     0,     0,   647,     0,     0,   955,
       0,     0,     0,     0,     0,   956,     0,   957,     0,   648,
     752,  1692,   958,   959,   960,     0,     0,     0,   961,     0,
     753,     0,     0,   652,   653,   654,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1693,     0,     0,
       0,     0,     0,     0,  1694,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   962,     0,     0,
       0,  1695,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,     0,   652,   653,   654,   963,   954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   749,     0,
       0,     0,     0,   656,   657,   658,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,     0,     0,     0,   952,
       0,     0,  1696,     0,     0,     0,     0,  -615,     0,     0,
       0,   955,  1697,     0,     0,     0,   953,   956,     0,   957,
       0,   964,   752,     0,   958,   959,   960,     0,     0,  1698,
     961,     0,   753,   656,   657,   658,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   659,     0,     0,
       0,     0,     0,  1699,   660,     0,     0,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,   962,
       0,     0,   965,   966,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   963,     0,
       0,     0,  1382,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   967,   952,   756,     0,   968,   969,     0,     0,
       0,     0,   754,     0,   970,     0,     0,     0,   954,   952,
     953,     0,     0,     0,     0,     0,     0,     0,     0,   749,
       0,     0,     0,     0,   971,     0,   953,     0,     0,   972,
       0,   952,     0,   964,     0,     0,   973,     0,   137,     0,
       0,     0,     0,     0,   757,     0,     0,     0,   953,     0,
       0,     0,   955,     0,     0,     0,     0,     0,   956,     0,
     957,     0,     0,   752,     0,   958,   959,   960,     0,     0,
       0,   961,   755,   753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   965,   966,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1401,     0,     0,     0,     0,     0,
     962,     0,   954,     0,   967,     0,   756,     0,   968,   969,
       0,     0,     0,   749,     0,     0,   970,     0,   954,   963,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   749,
       0,     0,     0,     0,     0,     0,   971,     0,     0,     0,
     954,   972,     0,   754,     0,     0,   955,     0,   973,     0,
     137,   749,   956,     0,   957,     0,   757,   752,     0,   958,
     959,   960,   955,     0,     0,   961,     0,   753,   956,     0,
     957,     0,     0,   752,   964,   958,   959,   960,     0,     0,
       0,   961,     0,   753,   955,     0,     0,     0,     0,     0,
     956,     0,   957,     0,     0,   752,     0,   958,   959,   960,
       0,     0,     0,   961,   962,   753,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,     0,     0,     0,
     962,     0,     0,   963,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   963,
       0,     0,   962,     0,     0,  1941,     0,   754,     0,     0,
       0,     0,     0,     0,     0,   967,     0,   756,     0,   968,
     969,   963,     0,   754,     0,     0,     0,   970,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   964,     0,
       0,     0,     0,     0,     0,   754,     0,   971,     0,     0,
    2660,     0,   972,     0,   964,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,     0,   964,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
     966,     0,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   965,   966,     0,     0,     0,
       0,     0,     0,     0,     0,   755,     0,     0,     0,   967,
       0,   756,     0,   968,   969,     0,     0,   965,   966,     0,
       0,   970,     0,     0,     0,     0,     0,   756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,   971,     0,     0,     0,     0,   972,     0,     0,   756,
       0,  2661,     0,   973,     0,   137,     0,   971,     0,   970,
       0,   757,   972,     0,     0,     0,     0,     0,     0,   973,
       0,   137,     0,     0,     0,     0,     0,   757,     0,   971,
       0,     0,     0,     0,   972,     0,     0,     0,     0,     0,
       0,   973,     0,   137,     0,     0,     0,     0,     0,   757
};

static const yytype_int16 yycheck[] =
{
     103,   393,   105,   395,   595,   103,   660,   105,   111,   366,
     540,   684,   838,   111,   181,  1101,  1202,   116,  1124,   714,
     776,  1099,  1418,  1418,   358,   784,   158,  1418,  1563,  1418,
    1418,  1418,   135,   425,  1459,  1569,  1104,   135,   598,  1553,
    1508,  1440,   209,   435,  1110,  1343,  1970,   404,  1234,  1353,
       1,  2004,    56,    57,    58,  1332,  1095,  1803,  1124,  1499,
      64,  1886,     1,     9,     9,  1242,     9,   649,   741,  1160,
      49,    55,  1227,    17,    87,    53,   697,   783,    96,   364,
      21,   184,    60,  1174,     6,   841,  1911,    22,     0,  1106,
    1734,     0,    49,  1110,  1493,    99,   100,    96,   102,   123,
      17,     1,   114,   107,   108,   124,     9,  1124,    57,    57,
     152,    57,   116,    31,   129,   788,    48,  1093,  1295,    92,
       1,   174,   203,    63,    86,  1101,  1102,    57,   123,   133,
     328,   161,     1,   159,  1432,    31,   203,    70,  1114,  1115,
      27,   176,    70,  1229,   141,   277,   256,    49,  1662,   203,
      33,  1428,   251,   244,  1982,   225,   160,  1133,  1134,   232,
     213,  1560,    26,    49,   237,   262,   271,   175,   750,   751,
     176,  1348,   256,   203,   176,   252,   176,    30,  1217,  1958,
     170,   142,   234,   161,  1482,  2138,   274,   191,   229,   161,
     287,  2067,    61,   421,   203,    21,   295,    72,  2434,   203,
     308,    87,   369,   747,    32,   256,   256,  2039,   829,  1770,
      32,    64,   200,    66,  2401,   157,   798,   783,   751,    54,
      89,    90,   446,   406,   306,  1624,   138,   107,   115,   138,
     142,   177,  1910,   142,  1145,   225,   308,   124,    57,     0,
     218,   219,    31,   233,   256,   249,   445,   546,   451,  1113,
    2611,  1812,   153,   257,    89,   187,   338,  1274,   307,   289,
     309,  1125,   968,   462,  1175,   798,  2142,  1284,   367,  1546,
     232,   106,   271,   497,     9,  1341,   358,     9,   329,   823,
      70,   116,   110,   989,   167,   584,  2647,  2474,   200,   231,
    1266,   200,   342,   476,   272,   241,   171,   232,   340,   110,
     388,   504,  1863,    92,   282,   503,   228,    64,   317,    66,
     418,   256,   389,   612,   165,     9,  1830,   289,   199,   410,
    1296,   994,    57,    70,  1341,    57,  2151,   317,  1345,   370,
    1865,  1635,   196,   561,    70,   204,   335,  1641,   410,   290,
     443,   446,   445,   446,   357,   397,   376,   445,   446,   452,
     292,  1995,  1629,   341,   452,  2183,  2592,  1756,   457,   363,
    1921,   312,  1440,   232,   241,    70,   469,   241,  1836,   472,
     473,   469,   475,   955,   274,   478,   479,  1845,   357,  1355,
     341,   462,  1822,  2259,   267,  1825,   308,   391,  1094,   956,
     957,  2170,   365,   447,   504,   462,   963,   376,   402,   252,
     357,   967,   968,   969,   476,   353,   503,   411,   412,   125,
     414,   415,   503,   516,    56,  1493,   420,    59,   516,   376,
     504,    63,   309,   989,   501,     9,   452,   497,   256,   341,
    1498,   504,   341,   437,   256,   783,   451,   540,   541,  1112,
    1000,  1001,   540,   541,  2122,   177,  1152,  1153,  1154,   453,
    2011,   504,   321,  2078,   451,   357,  1733,   256,   482,  1165,
    1166,   401,   504,   436,  1440,   398,  1172,   370,    56,   504,
     398,   357,   451,   503,     9,    63,   579,   212,   331,   354,
     212,   579,  1560,  1242,   503,   498,   504,   482,   388,   504,
     316,  1557,   504,   592,   451,   598,   504,   446,   504,    38,
     599,  1540,   504,  1479,   504,   504,   241,    46,   793,   241,
    1814,   515,   453,   497,   504,   448,  1492,  1493,   212,   498,
     448,   256,   468,   464,   256,   442,     6,  1093,  1094,  1684,
     534,   266,  1571,   465,   266,  1101,  1102,   499,   460,   451,
    1557,   498,   451,  2187,   462,   644,  1624,   650,  1114,  1115,
     554,   451,   556,   504,  1530,   559,   560,   501,   562,   504,
    1651,   504,   256,  1184,  1750,   504,   462,  1133,  1134,   504,
     451,   503,   266,  2107,   331,   505,  2401,  1754,  1855,  1145,
    1597,   456,   451,    57,  1560,   589,  1152,  1153,  1154,  1348,
     594,   468,   504,   496,   468,   504,   498,   601,   576,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,   955,   398,  1175,
     461,   346,   498,  2053,   346,  1892,   503,  2449,  2450,   967,
     968,   969,  1204,   503,   504,  1601,   268,   453,   606,  2375,
     441,   347,  2257,  2258,  2195,   446,  1612,  1613,   464,   458,
    1616,   989,  1208,   123,   463,    34,   216,  2046,  1624,  2048,
     503,   398,   346,    56,  1221,   659,   256,   172,   448,   159,
      63,   828,   398,   762,  2617,   252,   236,   256,   767,   772,
     773,   232,   211,    39,  2235,    22,  2237,   212,  1756,   232,
     268,   416,   781,   786,   416,  1251,   402,    64,  2087,    66,
    2614,   203,   262,   398,    49,   169,   700,     6,   340,   703,
    1266,   448,   188,   287,   243,   504,  1098,  2268,  1100,  1111,
    1469,   458,   448,     6,   244,   256,   463,   287,   308,   256,
     776,   256,   416,  1762,   256,   460,   265,  1119,   460,  1121,
    1296,   266,   212,   468,  1126,  1137,   468,  2298,  2299,    61,
    2441,  2140,  1759,   448,    56,  2049,  1094,   113,  1140,   223,
     292,    63,   340,   218,   396,   209,   330,   216,   217,   401,
    1466,  1122,  2387,   410,  1112,   349,   460,    89,    90,   504,
    1118,   251,   504,   253,   195,   510,   256,   236,   510,   318,
     451,  1142,   324,   451,   129,   841,   266,  2255,   329,  1355,
     290,  2068,   256,   293,  1360,  1861,  2497,  1145,   271,   242,
      27,     0,   389,   262,  1152,  1153,  1154,  1155,   396,   330,
     504,   346,  1160,   401,   356,   244,   510,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,   256,  1174,  1175,   287,   476,
    1486,  1487,  1488,  1489,   122,   256,   229,   406,   256,   378,
    1232,   274,   322,   256,  1861,  1862,  1605,    84,   262,   314,
     159,  1433,  1244,    30,  1414,  2153,  1204,  2392,   271,   357,
     153,  1947,   504,   451,   376,   268,   346,   321,     9,  2146,
     423,   237,   301,   228,  1440,   252,   362,   392,  1460,  1227,
     410,   416,  1966,  1285,   212,   232,   231,    64,   115,    66,
     451,   212,   281,   282,   283,  2456,  2457,  1000,  1001,   262,
    1466,  1985,  1986,   212,   504,  1989,  1579,   476,   321,    50,
     232,  1010,  1246,  1479,   504,   504,   504,   218,   351,   212,
     353,   256,   463,  1899,   287,   460,  1492,  1493,   256,   503,
     500,  2466,  2038,  2039,   473,   256,   416,   340,   266,   138,
       8,   384,   251,   142,   253,   266,   291,   256,  2032,   422,
    1656,   424,   452,  2037,   331,   344,   268,   266,   251,  1361,
     253,   161,  1310,   256,  1530,   165,   446,   504,  2046,    37,
    2048,   385,   504,   266,     6,   510,   450,   370,   271,   406,
     460,  2515,   503,   504,   458,   459,  2054,  1660,  1554,   463,
     257,  1325,  1095,   396,  1560,  1754,  1099,   394,   401,   321,
     498,   200,   482,  1106,  1107,   306,   270,  1110,     6,  2087,
    1113,   346,   196,   322,   354,  1118,   379,  1120,   346,  1122,
    1123,  1124,  1125,  2209,   504,   346,   406,   341,   340,   322,
     510,   117,   118,   119,   138,  1601,   402,   346,  2106,  1142,
     504,   500,   262,   256,   503,   285,  1612,  1613,   451,   476,
    1616,    26,   387,   346,   451,  2589,   170,  2482,  1624,   207,
     208,  2512,  2140,  2577,   451,   329,  1233,   287,  2085,  2153,
     394,   212,   256,   504,   287,   252,  1667,   466,   467,  1471,
     406,   416,   471,   256,   396,     6,   504,   454,   416,   401,
    1656,   504,   510,  2179,   334,   416,   476,   510,   246,   247,
     351,  2497,  2497,   244,   245,  2323,  2497,   416,  2497,  2497,
    2497,   225,   220,   451,  1217,   256,   456,  1284,  1466,   233,
    2096,     1,  2573,   416,  2304,   266,  2306,  2452,   177,   451,
     187,    11,   460,  1789,  1237,   451,   356,   504,   337,   451,
     503,   504,   341,   452,   252,     8,  2660,  1803,  1327,   187,
     476,   460,   238,   210,   331,  2690,   453,   256,  2134,  2135,
       6,   412,   413,  2677,   125,  1747,   252,   460,   435,   414,
     451,  1274,   210,    35,    37,   510,    38,   175,    58,   171,
     212,  1284,   510,    45,    46,  1352,   285,   286,   237,   510,
     783,   240,   423,     6,   458,   504,     9,  1953,  1377,   463,
     450,   510,   171,   317,   501,   346,  1554,   452,   481,   459,
     171,   504,   204,   212,   212,   262,    96,   510,    98,   251,
     100,   253,   321,  1101,   256,  1328,   499,   494,   108,    91,
     329,  1579,  2590,  2591,   266,   204,  2561,   504,  1341,  2564,
     287,  2421,  1345,   351,  1578,   411,   199,   504,  2332,   335,
    2009,   359,  2336,   251,   474,   253,  1134,   256,   256,   187,
    2618,   347,   750,   751,   232,  2241,     8,   266,   266,    82,
    2595,  2596,  2490,  2491,   204,   416,  1379,   248,   249,  2637,
     458,  1379,   210,   503,   164,   463,    99,  1454,  1645,    16,
     322,   212,   458,   750,   751,    37,   262,   463,   160,  2377,
     262,  2379,   232,  1651,   405,   232,    33,   455,  1656,   457,
     798,  1414,  2530,  1895,   346,    42,  2534,  2535,   106,   460,
     394,   287,  1503,   405,   322,   287,   451,   189,   116,   256,
     251,  2689,   253,  1899,  2029,   256,  1684,  1440,   351,  2012,
     353,   798,  2168,  2449,  2450,   266,  2452,   346,   346,   211,
      57,   437,    28,    13,    14,    12,   453,  2543,    15,    16,
    1951,  1542,  2446,  2447,   463,   218,   212,   464,   451,   510,
     323,   324,    32,   177,   967,   968,   969,   257,   451,   411,
     307,   453,   309,   187,   416,   451,  1567,   340,   201,  1387,
    1493,   173,   464,  1391,  2067,  1562,   989,     2,   451,   212,
    1398,   322,     7,   265,   555,   251,   210,   253,  1412,   560,
     256,    96,    97,  1417,  1418,  2501,  1420,   416,   416,  1586,
     266,   301,  2398,  2005,   448,   346,  2132,  1191,   460,   299,
     300,  1195,   245,   351,   458,   353,   240,  1540,   251,   463,
     253,   394,   451,   256,  1611,   258,   259,   260,  2595,  2596,
     126,   264,   504,   266,  1557,   448,   318,  1560,   271,   107,
      68,   460,   460,  1710,   451,   458,  1598,   504,  1571,  2142,
     463,   451,   504,  1720,  1721,  1867,   322,  1724,   510,   127,
    1167,  1168,  2458,   448,   212,     9,  2462,  2463,    12,   504,
     303,    15,    16,   458,  1597,   416,  1153,  1154,   463,  1092,
     346,  1094,   451,   340,  1097,   503,   504,   256,  1101,   322,
     390,   510,   510,  1169,  1170,  1171,   378,   449,   166,  1112,
     351,  1624,   353,   449,   256,  1118,   458,  1626,   256,   391,
    2096,   463,   458,   346,   468,   199,   212,   463,   266,   460,
     188,  1648,  1649,  1650,  1647,   504,  1139,  1654,  1141,  1647,
    1657,  1658,  1145,   433,   442,   156,   204,   158,   400,  1152,
    1153,  1154,  1155,   156,   377,   158,  2132,  1160,  2134,  2135,
     416,   451,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
     256,  1174,  1175,   504,    11,   252,  2259,   254,   410,   510,
     266,  1690,   401,   252,  1775,   254,   252,   473,   254,   475,
     446,  1782,   478,   416,   280,  1609,   485,   486,   487,   488,
    1203,   473,  1711,    63,   460,   428,   429,    65,   346,    67,
     277,   278,    59,   967,   504,   969,   256,  2157,    47,   232,
     451,    58,   328,   446,  1227,   401,  1229,   485,   486,   487,
     488,   256,   229,    62,   301,   302,   504,   460,    26,  1752,
     451,   451,  1833,  1756,   107,   451,  1759,   470,   504,  1762,
     312,  1665,  1666,   272,   510,   485,   486,   487,   488,    96,
     346,    98,  1676,   100,   256,  2241,   256,   490,   454,  1683,
      23,   108,   495,   102,   620,   621,   622,   623,   416,   502,
     102,   504,   451,   437,   188,    17,  2088,   510,   122,   454,
    1867,    86,   504,   451,   394,   272,   351,  1888,  1712,  1812,
     401,    56,   503,   402,   423,   262,    39,  1310,   451,   237,
     402,   504,   506,   504,  2081,   331,   419,    53,    54,   310,
     316,   394,   460,   261,   451,     7,   451,   164,   255,  1332,
     416,   394,   504,   419,   420,   451,   503,   451,   394,   366,
     451,   451,  1919,   277,   278,    85,    85,   124,  1861,  1862,
    1863,  1928,  1929,    89,   451,  1358,   394,  1771,  1900,  1901,
    1902,  1903,  1904,  1905,  1906,  1907,   504,   301,   302,   389,
     106,    22,   510,   306,  2132,   451,  1790,   309,   204,   499,
     116,   504,  1796,   504,   394,   384,   451,   232,   501,   226,
     254,   218,   504,   446,   122,   504,   446,   442,   462,  1990,
      26,   306,   510,   232,   447,   400,   410,   348,  1921,   445,
     239,    24,    25,   504,   462,  2006,   442,   256,   451,   504,
     257,   250,  2398,   451,   510,  1428,   376,   399,   336,   114,
     462,   462,   462,  1946,   169,   187,  2027,   451,  1946,   462,
     462,   462,   451,   504,   256,   462,   451,   309,  1961,   403,
     462,   453,    65,  1966,    67,   462,    69,   446,   504,    30,
     504,   130,   504,  1466,   301,  2056,   196,   304,   131,  2060,
    1979,   446,  1985,  1986,   132,   386,  1989,   133,   135,   134,
     101,   441,  2458,   136,   462,   137,  2462,  2463,   446,   497,
     103,   104,   105,   140,    49,   404,   445,   442,  2011,   445,
     439,   143,   196,   144,   271,   145,     6,   146,  2099,     9,
      31,  2088,   499,   147,    49,   148,   196,   149,  1932,  2032,
    2097,   150,   351,   352,  2037,  2038,  2039,   112,   151,  2038,
    2039,   220,   369,  2046,   448,  2048,  1950,   366,   448,   368,
     153,  2605,   155,  1546,   114,   448,   448,   448,   448,   162,
     446,  1554,   165,   390,   451,  1969,   410,  1971,   312,   109,
     197,  1975,   446,   223,   339,   203,   376,  1570,  2569,  1983,
     256,   272,  2085,   294,  2087,   298,  1579,   231,   415,   165,
     417,   501,    82,   501,   128,   321,   484,  1590,   175,   325,
     326,   365,   168,   446,   446,   129,   433,   228,    49,    99,
     196,  2192,   204,   228,   299,   204,    56,  2198,   451,   504,
     272,   165,   423,   237,  2590,  2591,  1619,  2208,    35,   509,
     508,    38,   451,   299,   252,   203,  1629,  2140,    45,    46,
     366,   276,   446,   446,   380,   362,   295,    30,   203,   252,
    2153,   254,  2618,   203,  2157,    17,   382,   383,  1651,  2157,
     442,   128,   152,  1656,   139,   365,   446,    49,   271,   141,
     203,  2637,     8,  2465,   196,   129,  2080,   504,   501,   498,
     501,  1674,   423,   203,    91,   451,   446,     9,     7,   504,
     503,  1684,   294,   297,   203,   503,    49,  2278,   291,   498,
    2281,  2282,   498,  1696,   188,   314,  1699,   461,   262,   113,
     330,   201,   313,  2294,    47,   436,   411,   203,   203,   380,
     294,  2513,   212,  2689,   102,   361,    49,  2308,  2309,   237,
     262,   296,  2235,   492,  2237,   361,    95,     8,    56,   292,
    1733,    49,   110,   337,   456,   262,   262,   262,   451,   109,
     337,   210,   451,   160,   481,   245,  1749,   107,   165,   221,
     299,   251,  2265,   253,   285,  2268,   256,  2265,   258,   259,
     260,   367,   232,   501,   264,   321,   266,   119,   418,   196,
     256,   271,   189,   321,    49,   337,  2367,   306,     7,    46,
      92,   425,    26,   127,   148,   201,  2299,   206,    75,   221,
     238,   150,   177,   519,   211,   410,   469,  1866,     1,   286,
    1009,   497,   773,   303,  1418,   425,  2319,  2587,  2658,   740,
    1859,  2319,   788,  1957,  2155,  2180,  2180,   841,  1018,  2332,
    2411,  2051,   322,  2336,   779,  1722,  1200,  2361,  1723,  1806,
     443,  1758,  2590,  2591,  1217,  1452,   783,    40,    41,    42,
      43,    44,  2049,  1454,  1479,  1498,   346,  2233,   265,  1501,
    1825,  2053,  1855,  1856,  2251,  1543,  1550,  2076,  1853,  1305,
    2618,  1561,  2088,  1879,  2377,  1310,  2379,  2095,  1929,  2109,
    1591,  1908,    75,    76,  1339,  1341,  1125,   377,  2135,  2637,
     493,  1884,  2395,  2297,  1355,  1928,  1928,  2302,  2647,  1892,
    1639,   504,  2312,  2128,  2307,  2401,  1530,  2128,  1328,  1448,
     299,   318,  2704,  2128,  2128,   691,   152,  1895,   270,   745,
     417,   242,   972,  2523,  1183,   509,   416,  1920,  2389,   215,
    1916,   449,  2065,  1858,  1927,  1928,  2340,   705,   428,   429,
    2344,  2689,  1553,  2446,  2447,    -1,  2449,  2450,     9,  2452,
    2449,  2450,   558,  2592,  1947,    -1,    -1,    -1,    -1,  1952,
      -1,    -1,    -1,   453,  1957,  1958,    -1,    -1,    -1,    -1,
     460,   378,    -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,   391,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,  2400,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,  2512,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,   955,  2012,
     510,    82,    -1,    -1,    -1,    -1,    -1,    -1,  2432,  2433,
     967,   968,   969,    -1,    -1,    -1,    -1,    -1,    99,    -1,
    2539,    -1,    -1,    -1,  2448,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2464,    -1,    -1,    -1,    -1,  2058,   473,    -1,    -1,    -1,
    2573,     4,    -1,    -1,  2067,  2068,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2076,    -1,  2489,    19,    -1,    -1,    -1,
    2494,  2495,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,  2600,  2095,    -1,    -1,    -1,    82,    -1,  2611,    -1,
    2514,    -1,    -1,    -1,  2613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      63,  2124,    -1,    -1,    -1,    -1,    -1,   330,  2542,  2132,
     201,  2545,  2546,    -1,  2647,    -1,    -1,    -1,    -1,  2142,
     343,   212,    -1,  2146,  2653,  2654,    -1,  1094,    -1,    -1,
      -1,    -1,  1099,    -1,    -1,    -1,    -1,    -1,    -1,  1106,
      -1,    -1,    -1,  1110,    -1,    -1,    -1,  2170,  2681,    -1,
      -1,  2585,    -1,    -1,    -1,    -1,  2179,  1124,    -1,    -1,
      -1,    -1,    -1,    -1,  2693,   256,    -1,   258,   259,   260,
      -1,    -1,     1,   264,     3,   266,     5,    -1,  1145,    -1,
      -1,    10,    -1,    -1,    -1,  1152,  1153,  1154,  1155,    18,
      -1,  2214,    -1,  1160,    -1,   201,    -1,    -1,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,   212,  1174,  1175,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,  2259,  1204,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,
     256,    -1,   258,   259,   260,   346,    -1,   220,   264,    88,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   504,   111,    -1,    -1,    -1,   377,    -1,    -1,   252,
     119,    -1,   121,    -1,    -1,    -1,    -1,   303,    -1,   262,
    2323,    -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1284,    -1,    -1,
      -1,    -1,    -1,   152,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,   428,   429,   168,
     346,    -1,    -1,    -1,    -1,    -1,    -1,  2370,    -1,    -1,
      -1,    -1,   315,    -1,    -1,    -1,    -1,   320,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1332,   195,    -1,    -1,   460,
      -1,   377,    -1,   202,  1341,    -1,   205,   206,  1345,   470,
      -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,   351,    -1,
    2413,    -1,    -1,   222,    -1,   224,   359,  2420,   227,   490,
    2423,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,   372,
     416,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,
     269,   404,    -1,    -1,   273,    -1,   275,    -1,  2471,   412,
      -1,    -1,    -1,    -1,   460,    -1,   285,    -1,    -1,    -1,
     423,  1428,  2485,    -1,   470,    -1,    -1,  2490,  2491,    -1,
      -1,    -1,    -1,  1440,    -1,    -1,    -1,    -1,  2501,    -1,
      -1,    -1,   311,    -1,   490,    -1,    -1,    -1,   451,   495,
      -1,   454,    -1,    -1,    -1,   324,   502,    -1,   504,  1466,
      -1,    -1,    -1,    -1,   510,    -1,    -1,  2530,    -1,    -1,
      -1,  2534,  2535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,   350,    -1,    -1,  2547,    -1,  1493,    -1,    -1,    -1,
      -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,    -1,
      -1,    -1,   381,    -1,    -1,    -1,   385,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   393,    -1,    -1,  2590,  2591,    -1,
      -1,    -1,    -1,    -1,   403,    -1,    -1,    -1,    -1,  1546,
      -1,    -1,     1,   412,     3,  2608,     5,  1554,    -1,    -1,
    1557,    10,   421,  1560,    -1,  2618,    -1,   426,   427,    18,
      -1,   430,    -1,   432,    -1,    -1,    -1,  2630,  2631,   438,
      -1,    -1,    -1,    -1,  2637,    -1,    -1,    82,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1597,    -1,    51,    52,    99,    -1,    -1,    -1,  2661,    -1,
     469,    60,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,
      -1,   480,    71,    -1,    -1,    74,    -1,  1624,    -1,    -1,
      -1,    -1,  1629,    -1,  2687,    -1,  2689,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,
      -1,    -1,    -1,    -1,  1651,    -1,    -1,    -1,    -1,  1656,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,    -1,
     139,   140,   141,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1733,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,  1752,   205,   206,    -1,  1756,
      -1,   256,  1759,   258,   259,   260,   215,    -1,    -1,   264,
      -1,    -1,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,  1812,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,
      -1,    -1,   291,   292,    -1,   294,   295,   296,   297,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1855,  1856,
      -1,    -1,   311,    -1,  1861,  1862,  1863,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,   324,     5,    -1,    -1,    -1,
      -1,    10,   377,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,  1892,    -1,    -1,    -1,    -1,
     349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,  1921,   374,   375,    -1,    -1,    -1,
      -1,    60,   381,   428,   429,    -1,   385,    -1,    -1,    -1,
      -1,    -1,    71,    -1,   393,    74,    -1,    32,    -1,    -1,
      35,    -1,    -1,    38,   403,    -1,    -1,    -1,    -1,    88,
      -1,    46,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,   470,    -1,   426,   427,    -1,
      -1,   430,   111,   432,    -1,    -1,    -1,    -1,    -1,   438,
     119,    -1,   121,    -1,    -1,   490,    -1,    45,    -1,    -1,
     495,    -1,   451,    -1,    -1,    -1,    91,   502,    -1,   504,
      -1,    -1,    -1,    -1,  2011,    -1,    64,    65,    66,    67,
     469,    -1,    -1,   152,    -1,    -1,   475,    -1,    -1,    -1,
      -1,   480,    -1,    -1,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2046,
      -1,  2048,   501,    -1,    -1,    -1,    -1,    -1,   507,    -1,
      -1,     1,    -1,     3,    -1,     5,   195,    -1,    -1,    -1,
      10,  2068,    -1,   202,    -1,    -1,   205,   206,    18,  2076,
      -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,  2085,    -1,
    2087,    -1,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,  2132,    -1,    -1,    -1,    -1,
     269,    -1,    -1,  2140,   273,    -1,   275,    -1,    88,  2146,
      -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,   243,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   263,   119,
     265,   121,   311,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   288,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,   350,    -1,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,   360,    -1,   318,    -1,    -1,    -1,   285,  2235,    -1,
    2237,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,    -1,
      -1,    -1,   381,    -1,    -1,   195,   385,   305,    -1,    -1,
     345,   309,   202,    -1,   393,   205,   206,    -1,    -1,    -1,
      -1,  2268,    -1,    -1,   403,   215,    -1,    -1,    -1,   327,
      -1,    -1,   222,   412,   224,   333,   371,   227,    -1,    -1,
      -1,    -1,   421,   378,    -1,    -1,    -1,   426,   427,    -1,
      -1,   430,  2299,   432,    -1,    -1,   391,    -1,    -1,   438,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,
     469,    82,    -1,    -1,    -1,   285,   475,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,   405,    99,   444,
      -1,    -1,    -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,
      -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,
    2377,    -1,  2379,   431,   324,    -1,    -1,    -1,   473,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,    -1,    -1,   451,   489,    -1,    -1,    -1,    -1,   349,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
     360,     9,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   374,   375,    -1,    -1,    -1,    -1,
      -1,   381,    -1,   491,    -1,   385,    -1,    -1,    -1,    -1,
     498,   499,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,   403,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,   426,   427,    -1,    -1,
     430,    -1,   432,    -1,    82,    -1,    -1,    -1,   438,    -1,
      -1,     3,    -1,     5,   245,    -1,    94,    -1,    10,    -1,
     251,    99,   253,    -1,    -1,   256,    18,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,   469,
      -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,   507,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,  2590,  2591,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,   111,
      -1,    -1,    -1,   201,    -1,    -1,    -1,   119,    -1,   121,
      -1,  2618,    -1,    -1,   212,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   377,   139,   140,   141,
    2637,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,   163,    -1,   251,    -1,   253,   168,    -1,   256,    -1,
     258,   259,   260,    -1,    -1,   416,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,   428,   429,    -1,
      -1,    -1,  2689,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,   303,    -1,    -1,    82,   460,
     222,   462,   224,    -1,    -1,   227,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,   322,    99,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,   490,
      20,    -1,    -1,    -1,   495,    -1,    -1,    -1,   346,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,   269,    -1,   510,
      -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,    -1,   190,    -1,   416,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   460,   375,    -1,    -1,    -1,    -1,    -1,   381,
      -1,    -1,   470,   385,    -1,    -1,    -1,    -1,    -1,   159,
      -1,   393,   256,    -1,   258,   259,   260,    -1,    -1,   169,
     264,   403,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
     412,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,   421,
      -1,    -1,   510,    -1,   426,   427,    -1,    -1,   430,    -1,
     432,   201,    -1,    -1,    -1,    -1,   438,   207,   208,   303,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,   469,    -1,    -1,
      -1,    -1,    -1,   475,    -1,   245,   246,   247,   480,    -1,
      -1,   251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,    -1,     6,    -1,   507,     9,    -1,    -1,    12,
      13,    14,    -1,   377,   284,    -1,    -1,    20,    -1,    -1,
     290,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,   303,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   332,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   439,   346,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,   377,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,     6,    -1,
      -1,     9,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,   499,    -1,    -1,   502,   503,
     504,    -1,    -1,    -1,    -1,     6,   416,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,   428,   429,
      -1,    49,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,
     450,    -1,   452,    -1,    -1,   455,    -1,   457,   458,   459,
     460,    -1,   462,   463,    82,    -1,    -1,    -1,   201,    87,
     470,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,   212,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    82,    -1,     6,    -1,   495,     9,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    99,    -1,
     510,    -1,   245,   246,   247,    -1,    -1,    -1,   251,    -1,
     253,   112,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   284,    -1,    -1,    -1,    -1,    -1,   290,    -1,    -1,
     293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    82,
     303,    -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,
     313,    94,    -1,   201,    -1,    -1,    99,    -1,    -1,   322,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,   332,
      -1,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,   253,    -1,   228,   256,    -1,
     258,   259,   260,    -1,   377,    -1,   264,    -1,   266,    -1,
      -1,    -1,    -1,   271,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,    -1,   266,    -1,    82,    -1,    -1,
     271,    -1,    -1,   416,    -1,   303,    -1,    -1,   201,    -1,
     308,    -1,    -1,    -1,    99,   428,   429,    -1,    -1,   212,
      -1,    -1,    -1,    -1,   322,    -1,     6,   112,    -1,     9,
      -1,    -1,   303,    -1,    -1,   448,    -1,   450,    -1,   452,
      -1,    -1,   455,    -1,   457,   458,   459,   460,   346,   462,
     463,   322,   245,    -1,    -1,    -1,    -1,   470,   251,   357,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,    -1,   346,    -1,   490,   271,   377,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,   377,    -1,    -1,    -1,
     303,    -1,   410,    -1,    94,    -1,   201,    -1,   416,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,   322,
     428,   429,    -1,    -1,     6,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   346,    -1,    -1,    -1,   428,   429,    -1,
     245,    -1,   460,    -1,    -1,    -1,   251,    -1,   253,    -1,
      -1,   256,   470,   258,   259,   260,    -1,    -1,   476,   264,
      -1,   266,    -1,    -1,   377,    -1,   271,    -1,    -1,   460,
      -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,   470,
     498,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,    -1,
      82,    -1,   510,    -1,    -1,    -1,    -1,    -1,   303,   490,
      -1,   201,    -1,   416,   495,    -1,    -1,    99,    -1,    -1,
      -1,   502,   212,   504,    -1,   428,   429,   322,    -1,   510,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   346,    -1,    -1,    -1,   245,    -1,   460,    -1,    -1,
      -1,   251,    -1,   253,    -1,    -1,   256,   470,   258,   259,
     260,    -1,    -1,    -1,   264,    -1,   266,    -1,    -1,    -1,
      -1,   271,   377,   165,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    82,   303,    -1,    -1,    -1,    -1,    -1,   201,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     212,    -1,   322,   428,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,   460,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,   256,   470,   258,   259,   260,    -1,
      -1,    -1,   264,    -1,   266,    -1,    -1,   377,    -1,   271,
      -1,     6,    -1,    -1,     9,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,
     322,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   346,    -1,    -1,    82,    -1,    -1,
     460,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
     470,   251,    -1,   253,    99,    -1,   256,    -1,   258,   259,
     260,    -1,    -1,    -1,   264,   377,   266,    -1,    -1,     6,
     490,   271,     9,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,
     510,    -1,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   416,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,   346,    -1,   460,    -1,
      -1,   196,    -1,    -1,    -1,    -1,   201,    -1,   470,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   212,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,   490,    -1,
      -1,     6,    -1,   495,     9,    99,    -1,    -1,    -1,    -1,
     502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,
     245,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   258,   259,   260,   416,    -1,    -1,   264,
      -1,   266,    -1,    -1,    -1,    -1,   271,    -1,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,   303,    -1,
     460,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,    99,   212,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,   484,    -1,    -1,   201,    -1,     6,
     490,    -1,     9,    -1,    -1,   495,    -1,    -1,   212,    -1,
      -1,   346,   502,    -1,   504,    -1,    -1,    -1,   245,    -1,
     510,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,    -1,    -1,   264,    -1,   266,
      -1,   245,   377,    -1,   271,    -1,    -1,   251,    -1,   253,
      -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,    -1,
     264,    -1,   266,    -1,    -1,    -1,    -1,   271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,   303,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    99,   428,   429,   322,    -1,   212,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   346,
      -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,   470,   251,    -1,   253,    -1,
      -1,   256,   346,   258,   259,   260,    -1,    -1,    -1,   264,
     377,   266,    -1,    -1,    -1,   490,   271,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,    -1,    -1,   377,    -1,   510,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,   303,   416,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    -1,    -1,   212,    -1,   322,    -1,    -1,
      -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,   346,    -1,   460,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,   470,   251,    -1,   253,    -1,    -1,   256,
      -1,   258,   259,   260,    -1,    -1,   460,   264,    -1,   266,
      -1,    -1,   377,   490,   271,    -1,   470,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,   490,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    -1,   303,    -1,   502,    -1,
     504,   416,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
      -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,   502,    -1,   504,
      -1,    32,    -1,    -1,    35,   510,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,   429,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   502,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,    -1,   178,   179,   180,
     181,   182,     1,    -1,   185,   186,    -1,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,
      -1,    -1,    21,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    36,   219,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,   305,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    -1,
      -1,    -1,    -1,    99,    -1,    -1,   327,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,   345,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,   175,    -1,    -1,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,
     371,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,
     219,    -1,    -1,    -1,   405,    -1,   407,   408,   409,    -1,
      -1,    -1,    -1,   232,   190,    -1,   235,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   446,    -1,    -1,    -1,    -1,
     451,    -1,    -1,    -1,    -1,   456,    -1,    -1,   277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,
      -1,    -1,   473,    -1,    -1,    -1,   477,   478,   479,    -1,
     256,    -1,   258,   259,   260,    -1,   305,    -1,   264,    -1,
     491,    -1,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,
     319,    -1,    -1,   504,    -1,    -1,    -1,    -1,   327,    -1,
      21,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    36,    -1,   303,    39,    40,
      41,    42,    43,    44,    45,    -1,   355,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,   407,   408,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,   477,   478,
     479,    -1,    -1,   439,    -1,    -1,    -1,   178,   179,   180,
     181,   182,   491,    -1,   185,   186,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,   481,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,   495,
      -1,   232,    -1,   499,   235,    -1,   502,   503,   504,    73,
     241,    75,    76,    77,    78,    79,    80,    81,    32,    -1,
      -1,    35,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,
      64,    -1,    66,    -1,    -1,   119,    -1,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    -1,   355,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    99,   405,   189,   407,   408,   409,    -1,
      -1,    -1,   196,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,
      -1,    -1,    -1,   434,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,   232,    -1,
     451,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,    -1,
      -1,   265,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,
     491,    -1,    -1,   277,    -1,    -1,   330,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    82,   343,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,   305,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   318,   319,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,   330,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,   343,
     256,   345,   258,   259,   260,    -1,    -1,    -1,   264,    -1,
     266,    -1,    -1,   407,   408,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,
      -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,    -1,   407,   408,   409,   322,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,   477,   478,   479,    -1,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,   446,    -1,    -1,    -1,    -1,   451,    -1,    -1,
      -1,   245,   456,    -1,    -1,    -1,    99,   251,    -1,   253,
      -1,   377,   256,    -1,   258,   259,   260,    -1,    -1,   473,
     264,    -1,   266,   477,   478,   479,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,
      -1,    -1,    -1,   497,   498,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   458,    82,   460,    -1,   462,   463,    -1,    -1,
      -1,    -1,   346,    -1,   470,    -1,    -1,    -1,   201,    82,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,   490,    -1,    99,    -1,    -1,   495,
      -1,    82,    -1,   377,    -1,    -1,   502,    -1,   504,    -1,
      -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    99,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,   260,    -1,    -1,
      -1,   264,   416,   266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,
     303,    -1,   201,    -1,   458,    -1,   460,    -1,   462,   463,
      -1,    -1,    -1,   212,    -1,    -1,   470,    -1,   201,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,
     201,   495,    -1,   346,    -1,    -1,   245,    -1,   502,    -1,
     504,   212,   251,    -1,   253,    -1,   510,   256,    -1,   258,
     259,   260,   245,    -1,    -1,   264,    -1,   266,   251,    -1,
     253,    -1,    -1,   256,   377,   258,   259,   260,    -1,    -1,
      -1,   264,    -1,   266,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,   256,    -1,   258,   259,   260,
      -1,    -1,    -1,   264,   303,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,   322,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,   303,    -1,    -1,   448,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   458,    -1,   460,    -1,   462,
     463,   322,    -1,   346,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,    -1,    -1,    -1,   346,    -1,   490,    -1,    -1,
     373,    -1,   495,    -1,   377,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,   458,
      -1,   460,    -1,   462,   463,    -1,    -1,   428,   429,    -1,
      -1,   470,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
      -1,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,   460,
      -1,   484,    -1,   502,    -1,   504,    -1,   490,    -1,   470,
      -1,   510,   495,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,   490,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   513,   514,     0,   200,   341,   515,   516,   517,   518,
     519,   520,   522,   532,   534,   451,   451,   517,   153,   528,
     540,   528,   528,   256,   342,   535,   535,   122,    84,   541,
     521,   523,   532,   138,   526,   527,    26,   536,   536,   451,
     394,   542,   142,   521,   524,   525,   528,   535,   256,   451,
     533,   451,    11,    58,    96,    98,   100,   108,   164,   226,
     257,   301,   304,   369,   390,   415,   417,   433,   504,   543,
     544,   548,   559,   567,   568,   569,   570,   571,   576,   584,
     586,   591,   594,   595,   597,   598,   599,   600,   601,   602,
     603,   535,   523,   451,   232,   537,  1268,   504,  1189,  1189,
     423,   405,  1286,  1268,  1268,  1268,   394,  1189,   405,   451,
     451,  1268,   451,   451,    57,  1257,   572,     1,   451,   570,
     218,   585,   173,   604,   451,   525,   451,    72,   171,   354,
     456,   538,   539,   577,  1268,  1268,  1268,   504,  1184,  1215,
      68,  1184,   451,  1268,  1268,   549,   560,  1184,   545,   504,
     587,   588,   589,  1190,   256,   307,   309,   573,   575,  1036,
    1218,  1268,   451,   504,   451,   606,   539,   340,  1283,  1268,
     212,   256,   266,   346,   416,   460,   510,   592,   593,  1221,
    1184,   256,   218,   306,  1306,   256,   468,    56,    63,   268,
     340,   396,   401,   504,   550,   551,   552,   553,   554,   555,
     556,   558,  1256,  1316,   199,   561,   562,   563,   546,   558,
     588,    22,   232,  1190,  1269,  1036,   232,   423,  1280,  1268,
      96,  1189,   234,   397,   605,   607,    28,   126,   212,   256,
     266,   280,   346,   416,   419,   420,   510,   578,   579,   580,
     583,   593,   442,   503,   596,  1299,  1215,   400,   401,   410,
      63,  1268,   451,   552,   451,   504,   551,    59,  1268,     9,
     370,   496,   564,   566,     1,   451,   563,   547,  1299,   256,
     590,  1219,  1280,   232,  1189,  1189,   574,   575,   451,     1,
     290,   312,  1242,   274,   388,   638,   639,   640,   641,   643,
     580,    17,   442,  1221,   328,  1268,   401,  1218,   451,  1268,
     504,  1185,   229,    26,   565,   229,   370,   451,   451,   107,
    1219,  1189,   451,   312,  1189,   644,   351,   412,   413,   642,
     529,     1,   451,   640,   581,   583,   256,  1218,   257,   435,
     494,   557,  1185,   256,   272,   608,   454,  1260,    23,  1251,
     102,   648,   451,   582,   583,    57,   505,  1310,   609,   437,
    1292,   188,  1261,   122,   454,   649,    17,     4,    19,    29,
      63,   220,   252,   315,   320,   351,   359,   372,   401,   404,
     412,   451,   454,   610,   611,   617,   619,   620,   621,   622,
     623,   624,   627,   628,   629,   630,   631,   633,   634,   636,
    1284,  1300,    86,  1258,   504,  1174,  1175,   451,   394,   650,
     583,   272,  1275,   351,  1284,   446,   497,  1296,   401,   402,
    1268,  1256,   113,   237,  1270,  1270,   287,   635,  1218,  1299,
     423,   262,    39,  1254,  1268,   645,   646,  1175,  1175,   451,
     172,   392,   530,   651,   652,   654,  1268,  1270,   125,   171,
     614,   359,   628,  1268,  1268,  1268,  1268,  1251,     9,   287,
     349,   637,  1268,  1275,   402,   504,   646,   331,   647,   506,
     679,   681,   682,     1,  1175,   125,   347,   402,   618,  1268,
     117,   118,   119,   238,   252,   335,   347,   437,   612,   613,
     256,  1184,  1188,   419,   632,  1184,  1184,   316,  1281,  1281,
     310,  1184,  1268,  1218,   394,   261,   732,   683,   684,   686,
     696,  1234,   451,   653,   632,   256,   616,  1215,   616,     7,
     616,   616,   256,   615,  1215,   414,   452,    33,   167,   267,
     625,   451,   394,   255,   734,   451,   684,   451,     1,   175,
     504,   687,   688,   504,   655,   124,   503,  1236,  1315,  1260,
    1268,  1183,  1184,   503,   626,   626,   680,   451,   394,   366,
     736,   451,   451,   685,    85,    47,    62,   102,   239,   250,
     351,   352,   366,   368,   451,   498,   656,   657,   659,   663,
     664,   667,   668,   674,   675,   676,   677,  1268,   124,  1183,
    1184,   262,   385,   681,   733,   451,   394,   389,   787,   698,
     689,  1268,  1258,  1268,   351,   353,  1311,  1311,  1268,  1258,
    1268,  1275,  1268,    22,  1250,   306,   678,  1189,   171,   204,
     309,   681,   735,   451,   394,   531,    21,    36,    39,    40,
      41,    42,    43,    44,    45,    73,    75,    76,    77,    78,
      79,    80,    81,   119,   178,   179,   180,   181,   182,   185,
     186,   219,   235,   277,   305,   319,   327,   330,   343,   355,
     363,   405,   407,   408,   409,   434,   477,   478,   479,   491,
     498,   699,   700,   701,   703,   704,   705,   706,   707,   708,
     709,   712,   721,   722,   723,   724,   725,   730,   731,  1268,
    1288,    26,   196,   697,  1252,   204,  1218,   504,  1268,  1250,
     504,  1186,  1187,   308,   418,  1307,  1188,  1218,   499,  1268,
     174,   213,   504,   665,  1189,   274,   351,   353,  1309,   681,
     737,   451,   337,   801,   804,   244,   301,   406,   476,  1287,
     476,  1287,   476,  1287,   476,  1287,   476,  1287,   501,  1297,
     384,  1285,  1218,  1212,  1215,  1215,   232,   242,   384,  1271,
    1268,  1269,   171,   204,   241,   468,   504,     9,    50,   212,
     244,   245,   256,   266,   346,   416,   460,   510,   690,  1222,
    1223,  1224,   446,   662,  1187,   254,  1274,   446,  1257,   218,
    1263,   504,  1268,  1268,  1309,   738,   788,   122,   827,   828,
     510,   446,   713,   462,  1216,  1217,   442,   706,   727,   728,
    1222,    26,   702,   400,  1246,  1246,  1224,   306,  1278,     1,
      40,    41,    42,    43,    44,   178,   179,   180,   181,   182,
     183,   184,   330,   343,   691,   692,   693,   694,   695,   707,
     708,  1212,   691,   447,  1218,    57,   353,   658,   669,  1218,
     410,  1289,   256,   666,  1215,   666,   348,   739,   686,   696,
     789,   790,   791,    55,   497,   805,     1,     3,     5,    10,
      18,    51,    52,    60,    71,    74,    88,   111,   119,   121,
     152,   163,   168,   195,   202,   205,   206,   215,   222,   224,
     227,   269,   273,   275,   285,   311,   324,   349,   350,   360,
     374,   375,   381,   385,   393,   403,   412,   421,   426,   427,
     430,   432,   438,   451,   469,   475,   480,   507,   829,   830,
     845,   850,   854,   859,   874,   877,   881,   885,   886,   887,
     892,   906,   910,   913,   927,   930,   933,   936,   940,   941,
     945,   955,   958,   975,   977,   980,   984,   990,  1002,  1010,
    1011,  1014,  1015,  1019,  1024,  1025,  1033,  1048,  1058,  1067,
    1072,  1079,  1083,  1085,  1088,  1091,  1095,  1120,   829,  1218,
     445,  1294,    82,    99,   201,   245,   251,   253,   258,   259,
     260,   264,   303,   322,   377,   428,   429,   458,   462,   463,
     470,   490,   495,   502,  1162,  1164,  1165,  1166,  1167,  1168,
    1169,  1197,  1211,  1212,  1223,  1225,  1226,  1227,  1228,   462,
    1217,  1215,   726,   728,   442,   256,  1256,   691,   451,  1224,
      48,   465,   670,   671,   672,   673,  1299,  1257,   196,   661,
    1262,   504,  1176,     1,   687,   791,   451,   807,   806,   376,
     813,     3,     5,    10,    18,    51,    52,    60,    71,    74,
      88,   111,   119,   121,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   139,   140,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   163,   168,   195,   202,
     205,   206,   215,   222,   224,   227,   269,   273,   275,   285,
     311,   324,   349,   360,   375,   381,   385,   393,   403,   412,
     421,   426,   427,   430,   432,   438,   451,   469,   475,   480,
     507,  1247,   831,   846,   851,   855,   860,   875,   878,   882,
     888,   893,   907,   911,   914,   928,   931,   934,   937,   942,
     946,   956,   959,   976,   978,   981,   399,   985,   991,  1003,
    1012,  1016,  1020,  1026,  1034,  1049,  1059,   256,   346,   387,
     416,   510,  1071,  1073,  1080,   336,  1084,  1086,   816,  1089,
    1092,  1096,  1121,   114,   714,   462,  1230,  1212,  1223,  1225,
    1306,  1306,   462,   462,   462,   462,  1306,  1168,  1164,  1168,
     462,  1230,    70,   398,   448,  1163,   449,   458,   463,   450,
     459,   169,   462,  1229,   462,   462,  1164,   501,   729,  1298,
    1222,  1188,  1188,   187,   662,  1218,   740,   451,   792,   451,
      49,   808,   809,   810,  1255,   808,   504,   451,   308,   832,
     833,  1211,     6,    94,   245,   271,   847,  1169,  1193,  1194,
    1211,  1222,  1225,   852,  1164,  1211,   256,   856,   857,  1180,
    1181,  1182,  1215,   271,   422,   424,   861,   862,   256,   876,
    1202,  1211,   879,  1175,     6,   883,  1169,  1170,  1171,  1192,
    1213,  1214,  1215,  1223,   454,   889,  1175,   256,   894,   895,
     897,  1193,  1194,  1202,  1211,   908,  1194,   256,   912,   453,
     464,   915,   916,   917,  1152,  1153,  1154,   199,   323,   324,
     340,   394,   929,   932,  1191,  1192,   935,  1215,   446,   938,
    1295,  1151,  1152,   947,  1191,   957,  1176,   960,   961,  1211,
    1222,  1225,  1050,  1209,  1210,  1215,    94,   979,  1194,   982,
    1194,   170,   225,   233,   317,   986,   987,   190,   256,   992,
     996,   997,   998,  1180,  1203,  1211,  1215,  1225,  1299,  1004,
    1175,  1013,  1172,  1215,  1017,  1175,  1021,  1172,     9,  1027,
    1173,  1215,   153,   271,  1035,  1038,  1039,  1042,  1043,  1044,
    1045,  1046,  1047,  1177,  1178,  1191,  1208,  1210,  1215,  1050,
    1060,  1175,  1068,   112,  1074,  1075,  1076,  1194,    94,  1081,
    1193,  1087,  1176,   451,   504,   817,   818,   821,   822,   827,
    1090,  1211,  1093,  1175,  1097,  1211,  1122,  1172,   309,  1279,
     715,   716,   448,  1162,  1164,   504,   504,  1164,  1233,  1233,
    1233,  1196,  1211,  1223,  1225,  1232,   504,   448,  1196,  1231,
    1164,   448,  1164,  1165,  1165,  1166,  1166,  1166,  1164,  1196,
    1162,   403,   453,    30,  1253,  1257,     1,   741,   793,   809,
     410,   476,   811,   357,   498,   802,   130,   844,    30,   835,
     836,  1253,   196,  1278,  1211,  1212,  1223,  1225,   131,   849,
     446,   848,  1194,    57,   223,  1237,   857,   446,  1306,   132,
     873,   256,  1203,  1202,  1175,   356,   474,   880,  1299,  1312,
    1278,   133,   884,   159,   452,  1171,  1303,   386,  1243,  1216,
    1217,   890,  1175,   134,   891,  1284,   135,   905,   165,   896,
    1131,  1132,   484,   898,   503,   836,   485,   486,   487,   488,
     136,   909,    49,   228,   497,   863,   137,   926,    17,   501,
     918,   919,   920,   922,    12,    13,    14,    20,   159,   169,
     207,   208,   246,   247,   284,   290,   293,   301,   308,   313,
     332,   448,   450,   452,   455,   457,   458,   459,   462,   463,
    1155,  1156,  1157,  1158,  1159,  1160,  1161,  1194,   101,  1192,
    1179,   441,  1293,   948,  1299,  1176,    92,   365,   436,   962,
     963,   965,   966,  1052,   462,  1216,  1194,   446,   140,   983,
      49,   987,   404,   988,   997,   141,   451,   993,   995,   481,
     499,   442,   445,   439,   143,  1009,   285,   334,  1240,   196,
    1123,   144,  1018,  1284,   145,  1023,  1123,  1173,   146,  1032,
     499,  1028,  1200,  1211,  1223,  1045,  1047,  1191,   446,  1178,
     123,   446,   482,  1037,    31,  1216,   147,  1066,   177,   237,
     240,  1062,   203,   376,  1069,  1299,  1255,   148,  1078,   228,
    1076,  1211,   149,  1082,   196,  1176,   394,   451,   451,   196,
     351,   353,  1094,   150,  1106,   112,  1098,   151,  1127,  1123,
    1184,   220,   718,    27,   115,   717,   448,  1163,   448,   448,
     448,  1163,   448,  1163,   448,   448,   449,   448,   448,   446,
    1268,  1188,   114,   660,   451,    61,    89,    90,   321,   451,
     742,   743,   748,  1268,  1324,    32,    35,    38,    45,    46,
      64,    66,   160,   189,   196,   198,   211,   243,   252,   265,
     305,   318,   345,   371,   378,   395,   446,   456,   473,   497,
     704,   705,   709,   721,   723,   725,   794,   799,   800,  1268,
    1301,  1268,   410,   312,   812,   109,   814,  1200,   197,   839,
     252,   331,   837,   838,  1301,    24,    25,    65,    67,    69,
     103,   104,   105,   153,   155,   162,   165,   252,   254,   443,
     493,   504,   834,  1178,  1302,   152,   340,  1198,  1212,   446,
       6,  1169,  1170,  1194,  1215,  1223,   203,   223,  1238,   376,
     853,   339,   858,  1182,   863,   880,   262,   287,  1261,  1212,
    1164,   272,  1244,  1217,  1175,   231,  1147,  1148,   824,   825,
     897,  1194,   294,  1133,    96,   335,   504,  1178,   298,   902,
      35,    38,    45,    46,    91,   160,   189,   211,   265,   318,
     378,   391,   473,   903,   904,   484,   899,  1131,  1131,  1131,
    1131,  1194,  1170,  1194,   864,   917,    21,   453,   464,   923,
     924,  1153,   501,   920,   921,   501,   824,  1295,   232,  1156,
     114,   939,  1180,   128,   824,   943,     9,    12,    15,    16,
     277,   278,   301,   302,   949,   953,   175,  1200,     9,    57,
     177,   241,   468,   969,   970,   971,   964,   965,  1054,  1279,
    1315,   446,  1191,  1170,  1194,   988,  1299,  1174,   824,   168,
     999,  1151,  1000,  1001,  1211,  1180,     8,    37,  1125,  1284,
    1207,  1211,  1222,  1225,   228,  1005,  1022,  1299,   129,  1029,
    1211,  1029,   446,   446,  1036,   152,   453,   464,  1194,    49,
      38,    46,   211,   243,   265,   318,   378,   473,  1040,  1041,
    1268,  1061,  1299,  1194,  1194,   161,   289,   410,  1194,  1211,
     196,  1170,  1194,   823,  1218,  1200,  1255,   228,  1101,  1124,
    1125,  1255,  1270,  1184,  1229,  1229,  1229,  1196,   241,   468,
    1229,   448,  1164,  1229,  1229,  1222,  1279,  1268,  1268,  1250,
     248,   249,  1273,   758,   204,   176,   744,   745,   746,   747,
    1211,  1268,   252,   389,   156,   158,  1268,  1203,   299,  1276,
    1218,    56,  1211,  1211,   204,  1276,    32,   110,  1218,  1268,
     504,   451,   803,   272,   840,  1276,  1276,   838,   837,  1276,
     165,  1128,  1129,   509,   508,  1200,  1128,   237,   423,   299,
     276,   256,  1199,  1212,  1211,  1278,   411,  1134,  1135,  1216,
    1217,  1170,   446,  1239,   853,  1192,   446,  1180,   203,   376,
     868,   869,   380,   362,  1134,  1268,   824,   295,  1149,   826,
     824,  1131,  1268,   252,   389,   156,   158,  1268,   123,   482,
     904,  1131,    96,    97,   900,   840,   203,  1134,   203,   865,
     866,   867,  1255,    17,   442,   925,   316,   923,  1279,   824,
     128,   139,   944,  1295,   365,   950,  1295,   446,    49,   970,
     972,  1200,     9,    57,   241,   468,   967,   968,  1200,  1055,
    1300,   717,   218,   314,  1264,  1191,  1134,   203,  1174,   637,
     379,   989,  1299,   141,   994,     8,   196,  1005,  1211,   129,
    1140,  1142,  1147,   262,   287,   824,   501,   501,  1030,  1031,
    1200,  1199,  1194,  1036,  1036,  1036,  1036,  1036,  1036,  1036,
    1036,  1041,   290,   293,  1063,  1064,  1065,  1157,  1241,  1147,
     244,   410,  1314,   423,  1291,  1291,  1077,  1299,  1211,  1134,
     203,   451,   446,     9,  1099,  1100,  1235,  1102,  1211,  1077,
    1102,  1022,     7,  1248,   504,   719,   720,  1268,   448,  1184,
    1202,  1268,  1250,   256,   749,   750,  1211,  1220,   686,   759,
     746,   747,   510,  1204,  1208,  1218,  1204,  1268,  1294,  1268,
    1268,    32,  1218,   815,   816,  1268,   503,   841,  1204,  1204,
    1204,   824,   294,  1130,  1128,  1243,  1212,   824,   297,  1136,
    1217,  1134,  1201,  1211,  1222,   165,   461,   871,  1305,     6,
     228,   308,   460,   870,  1267,    34,   281,   282,   283,   344,
     466,   467,   471,  1245,   824,   827,  1204,  1204,  1150,  1206,
    1208,  1218,  1150,   503,   901,  1170,  1171,  1170,  1171,   866,
     308,   811,    87,   357,   498,   924,  1152,   824,  1211,   824,
     498,   951,   952,   953,   954,  1293,   498,  1201,  1200,    49,
     973,   968,   188,   973,  1051,  1268,  1270,   314,  1170,   989,
     262,   287,  1001,  1194,   217,  1006,  1299,   824,   291,  1143,
     262,  1152,  1151,  1030,  1157,  1211,  1158,  1159,  1160,  1161,
    1164,  1070,  1194,  1070,   461,  1137,  1138,   330,  1243,  1170,
     819,  1201,   313,  1200,   113,  1103,   436,  1105,   157,   292,
    1126,  1144,  1145,  1146,  1147,   321,  1178,  1204,   720,  1183,
     751,   252,   254,  1308,   504,   687,   270,   329,   458,   463,
     795,   796,   797,  1202,   795,   796,   798,   816,    47,    32,
      35,    38,    46,    91,   189,   198,   211,   243,   263,   265,
     288,   318,   345,   371,   378,   391,   395,   444,   473,   483,
     489,   842,   843,  1128,   824,  1134,   824,   294,   872,   824,
    1278,  1211,   252,   254,  1313,   903,  1134,   361,  1134,   361,
    1194,   952,   102,  1259,  1295,   973,   973,  1201,     8,    37,
     974,   225,   497,  1056,  1184,  1053,  1134,   380,    49,   262,
     237,  1007,   216,   236,   262,   287,   500,   824,   824,   824,
     824,   296,  1139,  1268,  1134,  1134,   492,   820,  1107,  1100,
    1263,    95,  1104,  1263,  1137,   824,   824,  1146,   252,   254,
    1272,   177,   187,   210,   240,   752,   753,   754,   755,   756,
     757,   750,   760,  1204,  1204,   129,  1268,  1268,    56,   123,
     482,     8,  1249,   843,   824,  1211,  1171,  1171,    49,   110,
     973,   456,  1266,  1266,   337,  1174,   203,   317,  1057,  1215,
    1194,  1268,  1008,  1141,  1142,  1143,  1147,   262,   262,   262,
     824,  1211,  1108,   451,  1211,  1263,  1211,   106,   116,  1317,
    1268,  1268,    54,    89,  1317,  1318,  1302,   761,   109,  1204,
    1204,  1268,  1150,  1150,  1205,  1208,  1220,  1134,  1134,  1194,
    1194,  1194,  1268,  1174,   337,   481,  1211,  1143,   127,   166,
     204,  1109,  1110,  1111,  1113,  1117,  1118,  1119,  1261,  1211,
    1268,   750,   750,   210,  1268,  1268,   209,   252,   285,   305,
     309,   333,   414,   431,   451,   472,   491,   499,   704,   709,
     710,   721,   723,   725,   762,   763,   767,   770,   773,   774,
     775,   776,   780,   781,   782,   784,   785,   786,  1301,  1302,
     451,  1202,   996,  1268,  1151,    37,  1249,   107,   750,   750,
     750,   221,  1265,   299,   778,   209,   321,  1218,   285,   501,
    1268,  1278,  1268,  1268,  1211,   329,   463,   777,   779,  1220,
     329,   783,  1220,   299,   300,  1277,  1250,   996,   367,   418,
    1290,  1279,   232,  1268,   713,   321,  1151,  1197,  1195,  1197,
      53,    89,   321,   325,   326,   366,   382,   383,   764,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,   119,   196,   779,   779,
    1218,  1269,  1211,   161,   165,  1304,     9,  1114,  1115,  1181,
     285,   286,   321,   329,   463,   768,   769,  1218,  1294,  1243,
     373,   484,   771,  1197,   187,   187,   210,   187,   210,   176,
     765,  1211,   176,   766,  1211,  1197,   337,  1282,   306,   338,
     358,  1116,  1115,   321,  1218,  1218,   714,  1279,  1211,    49,
    1279,   306,  1215,   425,   711,   176,   772,  1211,  1197,   170,
     225,   233,   317,  1112,  1174,  1218
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 1343 "parser.y"
    {
	clear_initial_values ();
	current_program = NULL;
	cobc_cs_check = 0;
	prog_end = 0;
	depth = 0;
	main_flag_set = 0;
	current_program = cb_build_program (NULL, 0);
	cb_build_registers ();
  ;}
    break;

  case 3:
#line 1354 "parser.y"
    {
	if (!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body (current_program);
	}
	if (depth > 1) {
		cb_error (_("Multiple PROGRAM-ID's without matching END PROGRAM"));
	}
	if (cobc_flag_main && !main_flag_set) {
		cb_error (_("Executable requested but no program found"));
	}
	if (errorcount > 0) {
		YYABORT;
	}
	if (!current_program->entry_list) {
		emit_entry (current_program->program_id, 0, NULL);
	}
  ;}
    break;

  case 10:
#line 1390 "parser.y"
    {
	cb_tree		l;

	current_section = NULL;
	current_paragraph = NULL;
	prog_end = 1;
	if (increment_depth ()) {
		YYABORT;
	}
	l = cb_build_alphanumeric_literal (demangle_name,
					   strlen (demangle_name));
	current_program->program_id = cb_build_program_id (l, NULL, 0);
	current_program->prog_type = CB_PROGRAM_TYPE;
	if (!main_flag_set) {
		main_flag_set = 1;
		current_program->flag_main = cobc_flag_main;
	}
	check_relaxed_syntax (COBC_HD_PROGRAM_ID);
  ;}
    break;

  case 20:
#line 1445 "parser.y"
    {
	char	*s;

	if (CB_LITERAL_P ((yyvsp[(2) - (3)]))) {
		s = (char *)(CB_LITERAL ((yyvsp[(2) - (3)]))->data);
	} else {
		s = (char *)(CB_NAME ((yyvsp[(2) - (3)])));
	}
	if (depth) {
		depth--;
	}
	if (strcmp (stack_progid[depth], s)) {
		cb_error (_("END PROGRAM '%s' is different to PROGRAM-ID '%s'"),
			s, stack_progid[depth]);
	}
	if (!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body (current_program);
	}
  ;}
    break;

  case 23:
#line 1474 "parser.y"
    {
	char	*s;

	if (CB_LITERAL_P ((yyvsp[(2) - (3)]))) {
		s = (char *)(CB_LITERAL ((yyvsp[(2) - (3)]))->data);
	} else {
		s = (char *)(CB_NAME ((yyvsp[(2) - (3)])));
	}
	if (depth) {
		depth--;
	}
	if (strcmp (stack_progid[depth], s)) {
		cb_error (_("END FUNCTION '%s' is different to FUNCTION-ID '%s'"),
			s, stack_progid[depth]);
	}
	if (!current_program->flag_validated) {
		current_program->flag_validated = 1;
		cb_validate_program_body (current_program);
	}
  ;}
    break;

  case 24:
#line 1507 "parser.y"
    {
	cb_validate_program_environment (current_program);
  ;}
    break;

  case 25:
#line 1513 "parser.y"
    {
	current_storage = CB_STORAGE_WORKING;
  ;}
    break;

  case 26:
#line 1525 "parser.y"
    {
	cb_validate_program_data (current_program);
  ;}
    break;

  case 28:
#line 1535 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	if (CB_LITERAL_P ((yyvsp[(3) - (4)]))) {
		stack_progid[depth] = (char *)(CB_LITERAL ((yyvsp[(3) - (4)]))->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME ((yyvsp[(3) - (4)])));
	}
	if (prog_end) {
		if (!current_program->flag_validated) {
			current_program->flag_validated = 1;
			cb_validate_program_body (current_program);
		}
		clear_initial_values ();
		current_program = cb_build_program (current_program, depth);
		build_nested_special (depth);
		cb_build_registers ();
	} else {
		prog_end = 1;
	}
	if (increment_depth ()) {
		YYABORT;
	}
	current_program->program_id = cb_build_program_id ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]), 0);
	current_program->prog_type = CB_PROGRAM_TYPE;
	if (!main_flag_set) {
		main_flag_set = 1;
		current_program->flag_main = !!cobc_flag_main;
	}
  ;}
    break;

  case 29:
#line 1566 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 30:
#line 1573 "parser.y"
    {
#if	0	/* RXWRXW - FUNCTION-ID */
	cb_error (_("FUNCTION-ID is not yet implemented"));
#endif
	current_section = NULL;
	current_paragraph = NULL;
	if (CB_LITERAL_P ((yyvsp[(3) - (5)]))) {
		stack_progid[depth] = (char *)(CB_LITERAL ((yyvsp[(3) - (5)]))->data);
	} else {
		stack_progid[depth] = (char *)(CB_NAME ((yyvsp[(3) - (5)])));
	}
	if (prog_end) {
		if (!current_program->flag_validated) {
			current_program->flag_validated = 1;
			cb_validate_program_body (current_program);
		}
		clear_initial_values ();
		current_program = cb_build_program (current_program, depth);
		build_nested_special (depth);
		cb_build_registers ();
	} else {
		prog_end = 1;
	}
	if (increment_depth ()) {
		YYABORT;
	}
	current_program->program_id = cb_build_program_id ((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), 1);
	current_program->prog_type = CB_FUNCTION_TYPE;
	current_program->flag_recursive = 1;
	cobc_cs_check = 0;
  ;}
    break;

  case 33:
#line 1612 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 34:
#line 1613 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 37:
#line 1622 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  ;}
    break;

  case 38:
#line 1631 "parser.y"
    {
	if (!current_program->nested_level) {
		cb_error (_("COMMON may only be used in a contained program"));
	} else {
		current_program->flag_common = 1;
		cb_add_common_prog (current_program);
	}
  ;}
    break;

  case 41:
#line 1645 "parser.y"
    {
	current_program->flag_initial = 1;
  ;}
    break;

  case 42:
#line 1649 "parser.y"
    {
	current_program->flag_recursive = 1;
  ;}
    break;

  case 44:
#line 1659 "parser.y"
    {
	header_check |= COBC_HD_ENVIRONMENT_DIVISION;
  ;}
    break;

  case 46:
#line 1668 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_CONFIGURATION_SECTION;
	if (current_program->nested_level) {
		cb_error (_("CONFIGURATION SECTION not allowed in nested programs"));
	}
  ;}
    break;

  case 54:
#line 1693 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("SOURCE-COMPUTER", SYN_CLAUSE_1);
	if (warningopt && (check_comp_duplicate & SYN_CLAUSE_2)) {
		cb_warning (_("Phrases in non-standard order"));
	}
  ;}
    break;

  case 59:
#line 1711 "parser.y"
    {
	cb_verify (cb_debugging_line, "DEBUGGING MODE");
	current_program->flag_debugging = 1;
	needs_debug_item = 1;
	cobc_cs_check = 0;
	cb_build_debug_item ();
  ;}
    break;

  case 60:
#line 1724 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	check_comp_repeated ("OBJECT-COMPUTER", SYN_CLAUSE_2);
  ;}
    break;

  case 72:
#line 1753 "parser.y"
    {
	cb_verify (cb_memory_size_clause, "MEMORY SIZE");
  ;}
    break;

  case 73:
#line 1760 "parser.y"
    {
	current_program->collating_sequence = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 74:
#line 1767 "parser.y"
    {
	/* Ignore */
  ;}
    break;

  case 75:
#line 1774 "parser.y"
    {
	if (current_program->classification) {
		cb_error (_("Duplicate CLASSIFICATION clause"));
	} else {
		current_program->classification = (yyvsp[(4) - (4)]);
	}
  ;}
    break;

  case 76:
#line 1785 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 77:
#line 1789 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 78:
#line 1793 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 79:
#line 1797 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 82:
#line 1811 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
  ;}
    break;

  case 83:
#line 1816 "parser.y"
    {
	cobc_in_repository = 0;
  ;}
    break;

  case 86:
#line 1824 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 89:
#line 1836 "parser.y"
    {
	functions_are_all = 1;
  ;}
    break;

  case 90:
#line 1840 "parser.y"
    {
	cb_tree		x;

	if ((yyvsp[(3) - (3)])) {
		x = (yyvsp[(3) - (3)]);
	} else {
		x = (yyvsp[(2) - (3)]);
	}
	current_program->user_spec_list =
		cb_list_add (current_program->user_spec_list, x);
  ;}
    break;

  case 94:
#line 1861 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 95:
#line 1865 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 96:
#line 1872 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(1) - (1)]));
  ;}
    break;

  case 97:
#line 1877 "parser.y"
    {
	current_program->function_spec_list =
		cb_list_add (current_program->function_spec_list, (yyvsp[(2) - (2)]));
  ;}
    break;

  case 98:
#line 1888 "parser.y"
    {
	check_duplicate = 0;
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION, 0, 0);
	header_check |= COBC_HD_SPECIAL_NAMES;
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	}
  ;}
    break;

  case 100:
#line 1902 "parser.y"
    {
	cobc_cs_check = 0;
	yyerrok;
  ;}
    break;

  case 115:
#line 1933 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		save_tree = NULL;
	} else {
		save_tree = lookup_system_name (CB_NAME ((yyvsp[(1) - (1)])));
		if (!save_tree) {
			cb_error_x ((yyvsp[(1) - (1)]), _("Invalid system-name '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
		}
	}
  ;}
    break;

  case 117:
#line 1952 "parser.y"
    {
	if (save_tree) {
		if (CB_SYSTEM_NAME(save_tree)->token != CB_DEVICE_CONSOLE) {
			cb_error_x (save_tree, _("Invalid CRT clause"));
		} else {
			current_program->flag_console_is_crt = 1;
		}
	}
  ;}
    break;

  case 118:
#line 1962 "parser.y"
    {
	if (save_tree) {
		if (CB_SYSTEM_NAME(save_tree)->token != CB_FEATURE_CONVENTION) {
			cb_error_x (save_tree, _("Invalid special names clause"));
		} else if (CB_VALID_TREE ((yyvsp[(3) - (3)]))) {
			CB_SYSTEM_NAME(save_tree)->value = (yyvsp[(1) - (3)]);
			cb_define ((yyvsp[(3) - (3)]), save_tree);
			CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
					(yyvsp[(3) - (3)]), save_tree);
		}
	}
  ;}
    break;

  case 119:
#line 1975 "parser.y"
    {
	if (save_tree && CB_VALID_TREE ((yyvsp[(2) - (3)]))) {
		cb_define ((yyvsp[(2) - (3)]), save_tree);
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list,
				(yyvsp[(2) - (3)]), save_tree);
	}
  ;}
    break;

  case 123:
#line 1991 "parser.y"
    {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ((yyvsp[(3) - (3)]), save_tree, (yyvsp[(1) - (3)]) == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, (yyvsp[(3) - (3)]), x);
	}
  ;}
    break;

  case 124:
#line 2001 "parser.y"
    {
	cb_tree		x;

	/* cb_define_switch_name checks param validity */
	x = cb_define_switch_name ((yyvsp[(4) - (4)]), save_tree, (yyvsp[(2) - (4)]) == cb_int1);
	if (x) {
		CB_CHAIN_PAIR (current_program->mnemonic_spec_list, (yyvsp[(4) - (4)]), x);
	}
  ;}
    break;

  case 125:
#line 2016 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		(yyval) = NULL;
	} else {
		/* Returns null on error */
		(yyval) = cb_build_alphabet_name ((yyvsp[(2) - (2)]));
	}
  ;}
    break;

  case 126:
#line 2029 "parser.y"
    {
	if ((yyvsp[(3) - (5)])) {
		current_program->alphabet_name_list =
			cb_list_add (current_program->alphabet_name_list, (yyvsp[(3) - (5)]));
	}
	cobc_cs_check = 0;
  ;}
    break;

  case 127:
#line 2040 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_NATIVE;
	}
  ;}
    break;

  case 128:
#line 2046 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 129:
#line 2052 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 130:
#line 2058 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_EBCDIC;
	}
  ;}
    break;

  case 131:
#line 2064 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_ASCII;
	}
  ;}
    break;

  case 132:
#line 2070 "parser.y"
    {
	if ((yyvsp[(-1) - (1)])) {
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->alphabet_type = CB_ALPHABET_CUSTOM;
		CB_ALPHABET_NAME ((yyvsp[(-1) - (1)]))->custom_list = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 133:
#line 2080 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 134:
#line 2084 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 135:
#line 2091 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 136:
#line 2095 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 137:
#line 2099 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (2)]));
  ;}
    break;

  case 138:
#line 2103 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (4)]);
  ;}
    break;

  case 139:
#line 2110 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (1)]), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 140:
#line 2114 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 141:
#line 2120 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 142:
#line 2121 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 143:
#line 2122 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 144:
#line 2123 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 145:
#line 2124 "parser.y"
    { (yyval) = cb_norm_high; ;}
    break;

  case 146:
#line 2125 "parser.y"
    { (yyval) = cb_norm_low; ;}
    break;

  case 147:
#line 2133 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else if ((yyvsp[(1) - (2)])) {
		CB_CHAIN_PAIR (current_program->symbolic_char_list, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  ;}
    break;

  case 148:
#line 2147 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 149:
#line 2151 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 150:
#line 2159 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 151:
#line 2166 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 152:
#line 2170 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	} else {
		(yyval) = (yyvsp[(1) - (2)]);
	}
  ;}
    break;

  case 153:
#line 2181 "parser.y"
    {
	cb_tree		l1;
	cb_tree		l2;

	if (cb_list_length ((yyvsp[(1) - (3)])) != cb_list_length ((yyvsp[(3) - (3)]))) {
		cb_error (_("Invalid SYMBOLIC clause"));
		(yyval) = NULL;
	} else {
		l1 = (yyvsp[(1) - (3)]);
		l2 = (yyvsp[(3) - (3)]);
		for (; l1; l1 = CB_CHAIN (l1), l2 = CB_CHAIN (l2)) {
			CB_PURPOSE (l1) = CB_VALUE (l2);
		}
		(yyval) = (yyvsp[(1) - (3)]);
	}
  ;}
    break;

  case 154:
#line 2201 "parser.y"
    {
	if ((yyvsp[(1) - (1)]) == NULL) {
		(yyval) = NULL;
	} else {
		(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 155:
#line 2209 "parser.y"
    {
	if ((yyvsp[(2) - (2)]) == NULL) {
		(yyval) = (yyvsp[(1) - (2)]);
	} else {
		(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	}
  ;}
    break;

  case 156:
#line 2219 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 157:
#line 2220 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 158:
#line 2227 "parser.y"
    {
	cb_tree		x;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		x = cb_build_class_name ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
		if (x) {
			current_program->class_name_list =
				cb_list_add (current_program->class_name_list, x);
		}
	}
  ;}
    break;

  case 159:
#line 2247 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 160:
#line 2248 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 161:
#line 2253 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 162:
#line 2257 "parser.y"
    {
	if (CB_TREE_CLASS ((yyvsp[(1) - (3)])) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P ((yyvsp[(1) - (3)])) && CB_LITERAL ((yyvsp[(1) - (3)]))->size != 1) {
		cb_error (_("CLASS literal with THRU must have size 1"));
	}
	if (CB_TREE_CLASS ((yyvsp[(3) - (3)])) != CB_CLASS_NUMERIC &&
	    CB_LITERAL_P ((yyvsp[(3) - (3)])) && CB_LITERAL ((yyvsp[(3) - (3)]))->size != 1) {
		cb_error (_("CLASS literal with THRU must have size 1"));
	}
	if (literal_value ((yyvsp[(1) - (3)])) <= literal_value ((yyvsp[(3) - (3)]))) {
		(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	} else {
		(yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
	}
  ;}
    break;

  case 163:
#line 2278 "parser.y"
    {
	cb_tree	l;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		/* Returns null on error */
		l = cb_build_locale_name ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
		if (l) {
			current_program->locale_list =
				cb_list_add (current_program->locale_list, l);
		}
	}
  ;}
    break;

  case 164:
#line 2301 "parser.y"
    {
	unsigned char	*s = CB_LITERAL ((yyvsp[(4) - (5)]))->data;
	unsigned int	error_ind = 0;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
		error_ind = 1;
	}
	check_repeated ("CURRENCY", SYN_CLAUSE_1);
	if ((yyvsp[(5) - (5)])) {
		PENDING ("PICTURE SYMBOL");
	}
	if (CB_LITERAL ((yyvsp[(4) - (5)]))->size != 1) {
		cb_error_x ((yyvsp[(4) - (5)]), _("Invalid currency sign '%s'"), (char *)s);
		error_ind = 1;
	}
	switch (*s) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'N':
	case 'P':
	case 'R':
	case 'S':
	case 'V':
	case 'X':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'n':
	case 'p':
	case 'r':
	case 's':
	case 'v':
	case 'x':
	case 'z':
	case '+':
	case '-':
	case ',':
	case '.':
	case '*':
	case '/':
	case ';':
	case '(':
	case ')':
	case '=':
	case '\'':
	case '"':
	case ' ':
		cb_error_x ((yyvsp[(4) - (5)]), _("Invalid currency sign '%s'"), (char *)s);
		break;
	default:
		if (!error_ind) {
			current_program->currency_symbol = s[0];
		}
		break;
	}
  ;}
    break;

  case 165:
#line 2382 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 166:
#line 2386 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 167:
#line 2395 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("DECIMAL-POINT", SYN_CLAUSE_2);
		current_program->decimal_point = ',';
		current_program->numeric_separator = '.';
	}
  ;}
    break;

  case 168:
#line 2414 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		current_program->flag_trailing_separate = 1;
	}
  ;}
    break;

  case 169:
#line 2430 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("CURSOR", SYN_CLAUSE_3);
		current_program->cursor_pos = (yyvsp[(3) - (3)]);
	}
  ;}
    break;

  case 170:
#line 2448 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("CRT STATUS", SYN_CLAUSE_4);
		current_program->crt_status = (yyvsp[(4) - (4)]);
	}
  ;}
    break;

  case 171:
#line 2466 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("SCREEN CONTROL", SYN_CLAUSE_5);
		PENDING ("SCREEN CONTROL");
	}
  ;}
    break;

  case 172:
#line 2483 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_SPECIAL_NAMES, 0);
	if (current_program->nested_level) {
		cb_error (_("SPECIAL-NAMES not allowed in nested programs"));
	} else {
		check_repeated ("EVENT STATUS", SYN_CLAUSE_6);
		PENDING ("EVENT STATUS");
	}
  ;}
    break;

  case 174:
#line 2500 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_INPUT_OUTPUT_SECTION;
  ;}
    break;

  case 176:
#line 2508 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION,
			       0, 0);
	header_check |= COBC_HD_FILE_CONTROL;
  ;}
    break;

  case 178:
#line 2518 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION,
			       0, 0);
	header_check |= COBC_HD_I_O_CONTROL;
  ;}
    break;

  case 181:
#line 2534 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_INPUT_OUTPUT_SECTION,
			       COBC_HD_FILE_CONTROL, 0);
	check_duplicate = 0;
	if (CB_INVALID_TREE ((yyvsp[(3) - (3)]))) {
		YYERROR;
	}

	/* Build new file */
	current_file = build_file ((yyvsp[(3) - (3)]));
	current_file->optional = CB_INTEGER ((yyvsp[(2) - (3)]))->val;

	/* Add file to current program list */
	CB_ADD_TO_CHAIN (CB_TREE (current_file), current_program->file_list);
  ;}
    break;

  case 182:
#line 2551 "parser.y"
    {
	validate_file (current_file, (yyvsp[(3) - (6)]));
  ;}
    break;

  case 183:
#line 2555 "parser.y"
    {
	yyerrok;
	current_file = NULL;
	if (current_program->file_list) {
		current_program->file_list = CB_CHAIN (current_program->file_list);
	}
  ;}
    break;

  case 199:
#line 2589 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
  ;}
    break;

  case 200:
#line 2595 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_fileid = 1;
	}
  ;}
    break;

  case 201:
#line 2605 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("stdout", (size_t)6);
		current_file->special = COB_SELECT_STDOUT;
	}
  ;}
    break;

  case 202:
#line 2618 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("stdin", (size_t)5);
		current_file->special = COB_SELECT_STDIN;
	}
  ;}
    break;

  case 203:
#line 2631 "parser.y"
    {
	check_repeated ("ASSIGN", SYN_CLAUSE_1);
	cobc_cs_check = 0;
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
	if ((yyvsp[(5) - (5)])) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	} else {
		current_file->flag_ext_assign = 0;
		current_file->assign =
			cb_build_alphanumeric_literal ("LPT1", (size_t)4);
	}
  ;}
    break;

  case 209:
#line 2654 "parser.y"
    {
	current_file->flag_line_adv = 1;
  ;}
    break;

  case 211:
#line 2661 "parser.y"
    {
	current_file->flag_ext_assign = 1;
  ;}
    break;

  case 215:
#line 2674 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 218:
#line 2686 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("ACCESS", SYN_CLAUSE_2);
  ;}
    break;

  case 219:
#line 2693 "parser.y"
    { current_file->access_mode = COB_ACCESS_SEQUENTIAL; ;}
    break;

  case 220:
#line 2694 "parser.y"
    { current_file->access_mode = COB_ACCESS_DYNAMIC; ;}
    break;

  case 221:
#line 2695 "parser.y"
    { current_file->access_mode = COB_ACCESS_RANDOM; ;}
    break;

  case 222:
#line 2703 "parser.y"
    {
	struct cb_alt_key *p;
	struct cb_alt_key *l;

	p = cobc_parse_malloc (sizeof (struct cb_alt_key));
	p->key = (yyvsp[(5) - (6)]);
	p->duplicates = CB_INTEGER ((yyvsp[(6) - (6)]))->val;
	p->next = NULL;

	/* Add to the end of list */
	if (current_file->alt_key_list == NULL) {
		current_file->alt_key_list = p;
	} else {
		l = current_file->alt_key_list;
		for (; l->next; l = l->next) {
			;
		}
		l->next = p;
	}
  ;}
    break;

  case 223:
#line 2730 "parser.y"
    {
	check_repeated ("COLLATING", SYN_CLAUSE_3);
	PENDING ("COLLATING SEQUENCE");
  ;}
    break;

  case 224:
#line 2741 "parser.y"
    {
	check_repeated ("STATUS", SYN_CLAUSE_4);
	current_file->file_status = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 228:
#line 2756 "parser.y"
    {
	check_repeated ("LOCK", SYN_CLAUSE_5);
  ;}
    break;

  case 230:
#line 2764 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_MANUAL;
	cobc_cs_check = 0;
  ;}
    break;

  case 231:
#line 2769 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_AUTOMATIC;
	cobc_cs_check = 0;
  ;}
    break;

  case 232:
#line 2774 "parser.y"
    {
	current_file->lock_mode = COB_LOCK_EXCLUSIVE;
	cobc_cs_check = 0;
  ;}
    break;

  case 235:
#line 2783 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
  ;}
    break;

  case 236:
#line 2787 "parser.y"
    {
	current_file->lock_mode |= COB_LOCK_MULTIPLE;
	PENDING ("WITH ROLLBACK");
  ;}
    break;

  case 239:
#line 2803 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_INDEXED;
  ;}
    break;

  case 240:
#line 2808 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_SEQUENTIAL;
  ;}
    break;

  case 241:
#line 2813 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_RELATIVE;
  ;}
    break;

  case 242:
#line 2818 "parser.y"
    {
	check_repeated ("ORGANIZATION", SYN_CLAUSE_6);
	current_file->organization = COB_ORG_LINE_SEQUENTIAL;
  ;}
    break;

  case 243:
#line 2829 "parser.y"
    {
	check_repeated ("PADDING", SYN_CLAUSE_7);
	cb_verify (cb_padding_character_clause, "PADDING CHARACTER");
  ;}
    break;

  case 244:
#line 2840 "parser.y"
    {
	check_repeated ("RECORD DELIMITER", SYN_CLAUSE_8);
  ;}
    break;

  case 245:
#line 2850 "parser.y"
    {
	check_repeated ("RECORD KEY", SYN_CLAUSE_9);
	current_file->key = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 246:
#line 2857 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 247:
#line 2858 "parser.y"
    { PENDING ("SPLIT KEYS"); ;}
    break;

  case 248:
#line 2859 "parser.y"
    { PENDING ("SPLIT KEYS"); ;}
    break;

  case 249:
#line 2866 "parser.y"
    {
	check_repeated ("RELATIVE KEY", SYN_CLAUSE_10);
	current_file->key = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 250:
#line 2877 "parser.y"
    {
	check_repeated ("RESERVE", SYN_CLAUSE_11);
  ;}
    break;

  case 253:
#line 2891 "parser.y"
    {
	check_repeated ("SHARING", SYN_CLAUSE_12);
	current_file->sharing = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 254:
#line 2898 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 255:
#line 2899 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); ;}
    break;

  case 256:
#line 2900 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 259:
#line 2909 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 264:
#line 2928 "parser.y"
    {
	cb_tree l;

	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	switch (CB_INTEGER ((yyvsp[(2) - (5)]))->val) {
	case 0:
		/* SAME AREA */
		break;
	case 1:
		/* SAME RECORD */
		for (l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN (l)) {
			if (CB_VALID_TREE (CB_VALUE (l))) {
				CB_FILE (cb_ref (CB_VALUE (l)))->same_clause = samearea;
			}
		}
		samearea++;
		break;
	case 2:
		/* SAME SORT-MERGE */
		break;
	}
  ;}
    break;

  case 265:
#line 2955 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 266:
#line 2956 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 267:
#line 2957 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 268:
#line 2958 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 269:
#line 2965 "parser.y"
    {
	/* Fake for TAPE */
	cobc_cs_check = CB_CS_ASSIGN;
  ;}
    break;

  case 270:
#line 2970 "parser.y"
    {
	check_headers_present (COBC_HD_ENVIRONMENT_DIVISION,
			       COBC_HD_CONFIGURATION_SECTION,
			       COBC_HD_I_O_CONTROL, 0);
	cb_verify (cb_multiple_file_tape_clause, "MULTIPLE FILE TAPE");
	cobc_cs_check = 0;
  ;}
    break;

  case 277:
#line 2997 "parser.y"
    {
	header_check |= COBC_HD_DATA_DIVISION;
  ;}
    break;

  case 279:
#line 3006 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_FILE_SECTION;
  ;}
    break;

  case 282:
#line 3020 "parser.y"
    {
	if (CB_VALID_TREE (current_file)) {
		if (CB_VALID_TREE ((yyvsp[(2) - (2)]))) {
			if (current_file->reports) {
				cb_error (_("RECORD description invalid with REPORT"));
			} else {
				finalize_file (current_file, CB_FIELD ((yyvsp[(2) - (2)])));
			}
		} else if (!current_file->reports) {
			cb_error (_("RECORD description missing or invalid"));
		}
	}
  ;}
    break;

  case 283:
#line 3039 "parser.y"
    {
	current_storage = CB_STORAGE_FILE;
	check_headers_present (COBC_HD_DATA_DIVISION,
			       COBC_HD_FILE_SECTION, 0, 0);
	check_duplicate = 0;
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)])) || cb_ref ((yyvsp[(2) - (2)])) == cb_error_node) {
		YYERROR;
	}
	current_file = CB_FILE (cb_ref ((yyvsp[(2) - (2)])));
	if (CB_VALID_TREE (current_file)) {
		if ((yyvsp[(1) - (2)])) {
			current_file->organization = COB_ORG_SORT;
		}
	}
  ;}
    break;

  case 285:
#line 3056 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 286:
#line 3063 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 287:
#line 3067 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 290:
#line 3078 "parser.y"
    {
	check_repeated ("EXTERNAL", SYN_CLAUSE_1);
#if	0	/* RXWRXW - Global/External */
	if (current_file->flag_global) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	current_file->flag_external = 1;
  ;}
    break;

  case 291:
#line 3088 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_2);
#if	0	/* RXWRXW - Global/External */
	if (current_file->flag_external) {
		cb_error (_("File cannot have both EXTERNAL and GLOBAL clauses"));
	}
#endif
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		current_file->flag_global = 1;
		current_program->flag_file_global = 1;
	}
  ;}
    break;

  case 301:
#line 3118 "parser.y"
    {
	check_repeated ("BLOCK", SYN_CLAUSE_3);
	/* ignore */
  ;}
    break;

  case 305:
#line 3131 "parser.y"
    {
	check_repeated ("RECORD", SYN_CLAUSE_4);
	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if (warningopt) {
			cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_max = cb_get_int ((yyvsp[(3) - (4)]));
		if (current_file->record_max < 1)  {
			current_file->record_max = 1;
			cb_error (_("RECORD clause invalid"));
		}
		if (current_file->record_max > MAX_FD_RECORD)  {
			current_file->record_max = MAX_FD_RECORD;
			cb_error (_("RECORD size exceeds maximum allowed (%d)"),
				  MAX_FD_RECORD);
		}
	}
  ;}
    break;

  case 306:
#line 3151 "parser.y"
    {
	int	error_ind = 0;

	check_repeated ("RECORD", SYN_CLAUSE_4);
	if (current_file->organization == COB_ORG_LINE_SEQUENTIAL) {
		if (warningopt) {
			cb_warning (_("RECORD clause ignored for LINE SEQUENTIAL"));
		}
	} else {
		current_file->record_min = cb_get_int ((yyvsp[(3) - (6)]));
		current_file->record_max = cb_get_int ((yyvsp[(5) - (6)]));
		if (current_file->record_min < 0)  {
			current_file->record_min = 0;
			error_ind = 1;
		}
		if (current_file->record_max < 1)  {
			current_file->record_max = 1;
			error_ind = 1;
		}
		if (current_file->record_max > MAX_FD_RECORD)  {
			current_file->record_max = MAX_FD_RECORD;
			cb_error (_("RECORD size exceeds maximum allowed (%d)"),
				  MAX_FD_RECORD);
			error_ind = 1;
		}
		if (current_file->record_max <= current_file->record_min)  {
			error_ind = 1;
		}
		if (error_ind) {
			cb_error (_("RECORD clause invalid"));
		}
	}
  ;}
    break;

  case 307:
#line 3186 "parser.y"
    {
	int	error_ind = 0;

	check_repeated ("RECORD", SYN_CLAUSE_4);
	current_file->record_min = (yyvsp[(6) - (9)]) ? cb_get_int ((yyvsp[(6) - (9)])) : 0;
	current_file->record_max = (yyvsp[(7) - (9)]) ? cb_get_int ((yyvsp[(7) - (9)])) : 0;
	if ((yyvsp[(6) - (9)]) && current_file->record_min < 0)  {
		current_file->record_min = 0;
		error_ind = 1;
	}
	if ((yyvsp[(7) - (9)]) && current_file->record_max < 1)  {
		current_file->record_max = 1;
		error_ind = 1;
	}
	if ((yyvsp[(7) - (9)]) && current_file->record_max > MAX_FD_RECORD)  {
		current_file->record_max = MAX_FD_RECORD;
		cb_error (_("RECORD size exceeds maximum allowed (%d)"),
			  MAX_FD_RECORD);
		error_ind = 1;
	}
	if (((yyvsp[(6) - (9)]) || (yyvsp[(7) - (9)])) && current_file->record_max <= current_file->record_min)  {
		error_ind = 1;
	}
	if (error_ind) {
		cb_error (_("RECORD clause invalid"));
	}
  ;}
    break;

  case 309:
#line 3217 "parser.y"
    {
	current_file->record_depending = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 310:
#line 3223 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 311:
#line 3224 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 312:
#line 3228 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 313:
#line 3229 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 314:
#line 3237 "parser.y"
    {
	check_repeated ("LABEL", SYN_CLAUSE_5);
	cb_verify (cb_label_records_clause, "LABEL RECORDS");
  ;}
    break;

  case 315:
#line 3248 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
  ;}
    break;

  case 316:
#line 3253 "parser.y"
    {
	check_repeated ("VALUE OF", SYN_CLAUSE_6);
	cb_verify (cb_value_of_clause, "VALUE OF");
	if (!current_file->assign) {
		current_file->assign = cb_build_assignment_name (current_file, (yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 321:
#line 3276 "parser.y"
    {
	check_repeated ("DATA", SYN_CLAUSE_7);
	cb_verify (cb_data_records_clause, "DATA RECORDS");
  ;}
    break;

  case 322:
#line 3288 "parser.y"
    {
	check_repeated ("LINAGE", SYN_CLAUSE_8);
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("LINAGE clause with wrong file type"));
	} else {
		current_file->linage = (yyvsp[(3) - (5)]);
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
		if (current_linage == 0) {
			linage_file = current_file;
		}
		current_linage++;
	}
  ;}
    break;

  case 328:
#line 3316 "parser.y"
    {
	current_file->latfoot = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 329:
#line 3323 "parser.y"
    {
	current_file->lattop = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 330:
#line 3330 "parser.y"
    {
	current_file->latbot = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 331:
#line 3339 "parser.y"
    {
	cobc_cs_check = 0;
	check_repeated ("RECORDING", SYN_CLAUSE_9);
	/* ignore */
  ;}
    break;

  case 332:
#line 3351 "parser.y"
    {
	check_repeated ("CODE SET", SYN_CLAUSE_10);
	if (CB_VALID_TREE ((yyvsp[(3) - (3)]))) {
		cb_tree			x;
		struct cb_alphabet_name	*al;

		x = cb_ref ((yyvsp[(3) - (3)]));
		if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
		    current_file->organization != COB_ORG_SEQUENTIAL) {
			cb_error (_("CODE-SET clause invalid for file type"));
		}
		if (!CB_ALPHABET_NAME_P (x)) {
			cb_error_x ((yyvsp[(3) - (3)]), _("Alphabet-name is expected '%s'"), cb_name ((yyvsp[(3) - (3)])));
		} else {
			al = CB_ALPHABET_NAME (x);
			switch (al->alphabet_type) {
#ifdef	COB_EBCDIC_MACHINE
			case CB_ALPHABET_ASCII:
			case CB_ALPHABET_CUSTOM:
				current_file->code_set = al;
				break;
			default:
				if (warningopt) {
					cb_warning_x ((yyvsp[(3) - (3)]), _("Ignoring CODE-SET '%s'"),
						      cb_name ((yyvsp[(3) - (3)])));
				}
				break;
#else
			case CB_ALPHABET_EBCDIC:
			case CB_ALPHABET_CUSTOM:
				current_file->code_set = al;
				break;
			default:
				if (warningopt) {
					cb_warning_x ((yyvsp[(3) - (3)]), _("Ignoring CODE-SET '%s'"),
						      cb_name ((yyvsp[(3) - (3)])));
				}
				break;
#endif
			}
			if (warningopt) {
				PENDING ("CODE-SET");
			}
		}
	}
  ;}
    break;

  case 333:
#line 3403 "parser.y"
    {
	check_repeated ("REPORT", SYN_CLAUSE_11);
	if (current_file->organization != COB_ORG_LINE_SEQUENTIAL &&
	    current_file->organization != COB_ORG_SEQUENTIAL) {
		cb_error (_("REPORT clause with wrong file type"));
	} else {
		current_file->reports = (yyvsp[(2) - (2)]);
		current_file->organization = COB_ORG_LINE_SEQUENTIAL;
		current_file->flag_line_adv = 1;
	}
  ;}
    break;

  case 336:
#line 3423 "parser.y"
    {
	current_report = build_report ((yyvsp[(1) - (1)]));
	current_report->file = current_file;
	current_program->report_list =
				cb_list_add (current_program->report_list,
					     CB_TREE (current_report));
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  ;}
    break;

  case 337:
#line 3435 "parser.y"
    {
	current_report = build_report ((yyvsp[(2) - (2)]));
	current_report->file = current_file;
	current_program->report_list =
				cb_list_add (current_program->report_list,
					     CB_TREE (current_report));
	if (report_count == 0) {
		report_instance = current_report;
	}
	report_count++;
  ;}
    break;

  case 339:
#line 3478 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_WORKING_STORAGE_SECTION;
	current_storage = CB_STORAGE_WORKING;
  ;}
    break;

  case 340:
#line 3484 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		CB_FIELD_ADD (current_program->working_storage, CB_FIELD ((yyvsp[(5) - (5)])));
	}
  ;}
    break;

  case 341:
#line 3493 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 342:
#line 3496 "parser.y"
    {
	current_field = NULL;
	control_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  ;}
    break;

  case 343:
#line 3503 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	(yyval) = CB_TREE (description_field);
  ;}
    break;

  case 348:
#line 3523 "parser.y"
    {
	cb_tree x;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (2)]));
	if (CB_INVALID_TREE (x)) {
		YYERROR;
	} else {
		current_field = CB_FIELD (x);
		check_pic_duplicate = 0;
	}
  ;}
    break;

  case 349:
#line 3538 "parser.y"
    {
	if (!qualifier && (current_field->level == 88 ||
	    current_field->level == 66 || current_field->flag_item_78)) {
		cb_error (_("Item requires a data name"));
	}
	if (!qualifier) {
		current_field->flag_filler = 1;
	}
	if (current_field->level == 88) {
		cb_validate_88_item (current_field);
	}
	if (current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item (current_field, 0);
	}
	if (!description_field) {
		description_field = current_field;
	}
  ;}
    break;

  case 350:
#line 3558 "parser.y"
    {
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (3)]));
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  ;}
    break;

  case 351:
#line 3571 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 352:
#line 3578 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  ;}
    break;

  case 353:
#line 3584 "parser.y"
    {
	(yyval) = cb_build_filler ();
	qualifier = NULL;
	non_const_word = 0;
  ;}
    break;

  case 354:
#line 3590 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  ;}
    break;

  case 355:
#line 3599 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	qualifier = (yyvsp[(1) - (1)]);
	non_const_word = 0;
  ;}
    break;

  case 356:
#line 3608 "parser.y"
    {
	(yyval)= NULL;
  ;}
    break;

  case 357:
#line 3612 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
		(yyval)= NULL;
	} else {
		(yyval) = cb_null;
	}
  ;}
    break;

  case 358:
#line 3623 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 359:
#line 3624 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); ;}
    break;

  case 360:
#line 3625 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(2) - (2)])); ;}
    break;

  case 361:
#line 3626 "parser.y"
    { (yyval) = cb_build_const_length ((yyvsp[(3) - (3)])); ;}
    break;

  case 362:
#line 3631 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 363:
#line 3635 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 364:
#line 3639 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 365:
#line 3643 "parser.y"
    {
	(yyval) = cb_int4;
  ;}
    break;

  case 366:
#line 3647 "parser.y"
    {
	(yyval) = cb_int (8);
  ;}
    break;

  case 367:
#line 3651 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(long));
  ;}
    break;

  case 368:
#line 3655 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(void *));
  ;}
    break;

  case 369:
#line 3659 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(float));
  ;}
    break;

  case 370:
#line 3663 "parser.y"
    {
	(yyval) = cb_int ((int)sizeof(double));
  ;}
    break;

  case 371:
#line 3667 "parser.y"
    {
	(yyval) = cb_int (4);
  ;}
    break;

  case 372:
#line 3671 "parser.y"
    {
	(yyval) = cb_int (8);
  ;}
    break;

  case 373:
#line 3675 "parser.y"
    {
	(yyval) = cb_int (16);
  ;}
    break;

  case 374:
#line 3679 "parser.y"
    {
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
	current_field = cb_get_real_field ();
  ;}
    break;

  case 384:
#line 3711 "parser.y"
    {
	cb_tree x;
	int	level;

	cobc_cs_check = 0;
	level = cb_get_level ((yyvsp[(1) - (5)]));
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (5)]));
	if (level != 1) {
		cb_error (_("CONSTANT item not at 01 level"));
	} else if ((yyvsp[(5) - (5)])) {
		x = cb_build_constant ((yyvsp[(2) - (5)]), (yyvsp[(5) - (5)]));
		CB_FIELD (x)->flag_item_78 = 1;
		CB_FIELD (x)->level = 1;
		cb_needs_01 = 1;
		if ((yyvsp[(4) - (5)])) {
			CB_FIELD (x)->flag_is_global = 1;
		}
		/* Ignore return value */
		(void)cb_validate_78_item (CB_FIELD (x), 0);
	}
  ;}
    break;

  case 385:
#line 3737 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 386:
#line 3741 "parser.y"
    {
	PENDING ("CONSTANT FROM clause");
	(yyval) = NULL;
  ;}
    break;

  case 387:
#line 3749 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = NULL;
  ;}
    break;

  case 388:
#line 3755 "parser.y"
    {
	/* Required to check redefines */
	(yyval) = cb_true;
  ;}
    break;

  case 403:
#line 3783 "parser.y"
    {
	check_pic_repeated ("REDEFINES", SYN_CLAUSE_1);
	if ((yyvsp[(0) - (2)]) != NULL) {
		if (cb_relaxed_syntax_check) {
			cb_warning_x ((yyvsp[(2) - (2)]), _("REDEFINES clause should follow entry-name"));
		} else {
			cb_error_x ((yyvsp[(2) - (2)]), _("REDEFINES clause must follow entry-name"));
		}
	}

	current_field->redefines = cb_resolve_redefines (current_field, (yyvsp[(2) - (2)]));
	if (current_field->redefines == NULL) {
		current_field->flag_is_verified = 1;
		current_field->flag_invalid = 1;
		YYERROR;
	}
  ;}
    break;

  case 404:
#line 3807 "parser.y"
    {
	check_pic_repeated ("EXTERNAL", SYN_CLAUSE_2);
	if (current_storage != CB_STORAGE_WORKING) {
		cb_error (_("EXTERNAL not allowed here"));
	} else if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("EXTERNAL only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("EXTERNAL requires a data name"));
#if	0	/* RXWRXW - Global/External */
	} else if (current_field->flag_is_global) {
		cb_error (_("GLOBAL and EXTERNAL are mutually exclusive"));
#endif
	} else if (current_field->flag_item_based) {
		cb_error (_("BASED and EXTERNAL are mutually exclusive"));
	} else if (current_field->redefines) {
		cb_error (_("EXTERNAL and REDEFINES are mutually exclusive"));
	} else if (current_field->flag_occurs) {
		cb_error (_("EXTERNAL and OCCURS are mutually exclusive"));
	} else {
		current_field->flag_external = 1;
		current_program->flag_has_external = 1;
	}
  ;}
    break;

  case 405:
#line 3834 "parser.y"
    {
	current_field->ename = cb_to_cname (current_field->name);
  ;}
    break;

  case 406:
#line 3838 "parser.y"
    {
	current_field->ename = cb_to_cname ((const char *)CB_LITERAL ((yyvsp[(2) - (2)]))->data);
  ;}
    break;

  case 407:
#line 3847 "parser.y"
    {
	check_pic_repeated ("GLOBAL", SYN_CLAUSE_3);
	if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("GLOBAL only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("GLOBAL requires a data name"));
#if	0	/* RXWRXW - Global/External */
	} else if (current_field->flag_external) {
		cb_error (_("GLOBAL and EXTERNAL are mutually exclusive"));
#endif
	} else if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else if (current_storage == CB_STORAGE_LOCAL) {
		cb_error (_("GLOBAL not allowed here"));
	} else {
		current_field->flag_is_global = 1;
	}
  ;}
    break;

  case 408:
#line 3872 "parser.y"
    {
	check_pic_repeated ("PICTURE", SYN_CLAUSE_4);
	current_field->pic = CB_PICTURE ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 411:
#line 3888 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 412:
#line 3892 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 413:
#line 3896 "parser.y"
    {
	check_set_usage (CB_USAGE_FLOAT);
  ;}
    break;

  case 414:
#line 3900 "parser.y"
    {
	check_set_usage (CB_USAGE_DOUBLE);
  ;}
    break;

  case 415:
#line 3904 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  ;}
    break;

  case 416:
#line 3908 "parser.y"
    {
	check_set_usage (CB_USAGE_BINARY);
  ;}
    break;

  case 417:
#line 3912 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_5);
  ;}
    break;

  case 418:
#line 3916 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_6);
  ;}
    break;

  case 419:
#line 3920 "parser.y"
    {
	check_set_usage (CB_USAGE_COMP_X);
  ;}
    break;

  case 420:
#line 3924 "parser.y"
    {
	check_set_usage (CB_USAGE_DISPLAY);
  ;}
    break;

  case 421:
#line 3928 "parser.y"
    {
	check_set_usage (CB_USAGE_INDEX);
  ;}
    break;

  case 422:
#line 3932 "parser.y"
    {
	check_set_usage (CB_USAGE_PACKED);
  ;}
    break;

  case 423:
#line 3936 "parser.y"
    {
	check_set_usage (CB_USAGE_POINTER);
	current_field->flag_is_pointer = 1;
  ;}
    break;

  case 424:
#line 3941 "parser.y"
    {
	check_set_usage (CB_USAGE_PROGRAM_POINTER);
	current_field->flag_is_pointer = 1;
  ;}
    break;

  case 425:
#line 3946 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  ;}
    break;

  case 426:
#line 3950 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  ;}
    break;

  case 427:
#line 3954 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  ;}
    break;

  case 428:
#line 3962 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  ;}
    break;

  case 429:
#line 3966 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  ;}
    break;

  case 430:
#line 3970 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  ;}
    break;

  case 431:
#line 3978 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_CHAR);
  ;}
    break;

  case 432:
#line 3982 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_CHAR);
  ;}
    break;

  case 433:
#line 3986 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_SHORT);
  ;}
    break;

  case 434:
#line 3990 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_SHORT);
  ;}
    break;

  case 435:
#line 3994 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_INT);
  ;}
    break;

  case 436:
#line 3998 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_INT);
  ;}
    break;

  case 437:
#line 4002 "parser.y"
    {
	check_set_usage (CB_USAGE_SIGNED_LONG);
  ;}
    break;

  case 438:
#line 4006 "parser.y"
    {
	check_set_usage (CB_USAGE_UNSIGNED_LONG);
  ;}
    break;

  case 439:
#line 4010 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_SIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_SIGNED_LONG);
	}
  ;}
    break;

  case 440:
#line 4018 "parser.y"
    {
	if (sizeof(long) == 4) {
		check_set_usage (CB_USAGE_UNSIGNED_INT);
	} else {
		check_set_usage (CB_USAGE_UNSIGNED_LONG);
	}
  ;}
    break;

  case 441:
#line 4026 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN32);
  ;}
    break;

  case 442:
#line 4030 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN64);
  ;}
    break;

  case 443:
#line 4034 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_BIN128);
  ;}
    break;

  case 444:
#line 4038 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC64);
  ;}
    break;

  case 445:
#line 4042 "parser.y"
    {
	check_set_usage (CB_USAGE_FP_DEC128);
  ;}
    break;

  case 446:
#line 4046 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_5);
	PENDING ("USAGE NATIONAL");
  ;}
    break;

  case 451:
#line 4066 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 1;
  ;}
    break;

  case 452:
#line 4072 "parser.y"
    {
	check_pic_repeated ("SIGN", SYN_CLAUSE_6);
	current_field->flag_sign_separate = ((yyvsp[(3) - (3)]) ? 1 : 0);
	current_field->flag_sign_leading  = 0;
  ;}
    break;

  case 453:
#line 4085 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_7);
	if (current_field->depending && !((yyvsp[(3) - (6)]))) {
		cb_verify (cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = (yyvsp[(3) - (6)]) ? cb_get_int ((yyvsp[(2) - (6)])) : 1;
	current_field->occurs_max = (yyvsp[(3) - (6)]) ? cb_get_int ((yyvsp[(3) - (6)])) : cb_get_int ((yyvsp[(2) - (6)]));
	current_field->indexes++;
	if (current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error (_("Maximum OCCURS depth exceeded (%d)"),
			  COB_MAX_SUBSCRIPTS);
	}
	current_field->flag_occurs = 1;
  ;}
    break;

  case 455:
#line 4103 "parser.y"
    {
	current_field->step_count = cb_get_int ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 456:
#line 4113 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_7);
	if (current_field->depending && !((yyvsp[(3) - (7)]))) {
		cb_verify (cb_odo_without_to, "ODO without TO clause");
	}
	current_field->occurs_min = (yyvsp[(3) - (7)]) ? cb_get_int ((yyvsp[(2) - (7)])) : 1;
	current_field->occurs_max = (yyvsp[(3) - (7)]) ? cb_get_int ((yyvsp[(3) - (7)])) : cb_get_int ((yyvsp[(2) - (7)]));
	current_field->indexes++;
	if (current_field->indexes > COB_MAX_SUBSCRIPTS) {
		cb_error (_("Maximum OCCURS depth exceeded (%d)"),
			  COB_MAX_SUBSCRIPTS);
	}
	if (current_field->flag_item_based) {
		cb_error (_("BASED and OCCURS are mutually exclusive"));
	} else if (current_field->flag_external) {
		cb_error (_("EXTERNAL and OCCURS are mutually exclusive"));
	}
	current_field->flag_occurs = 1;
  ;}
    break;

  case 457:
#line 4135 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 458:
#line 4136 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 460:
#line 4141 "parser.y"
    {
	current_field->depending = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 461:
#line 4148 "parser.y"
    {
	if ((yyvsp[(1) - (1)])) {
		cb_tree		l;
		struct cb_key	*keys;
		int		i;
		int		nkeys;

		l = (yyvsp[(1) - (1)]);
		nkeys = cb_list_length ((yyvsp[(1) - (1)]));
		keys = cobc_parse_malloc (sizeof (struct cb_key) * nkeys);

		for (i = 0; i < nkeys; i++) {
			keys[i].dir = CB_PURPOSE_INT (l);
			keys[i].key = CB_VALUE (l);
			l = CB_CHAIN (l);
		}
		current_field->keys = keys;
		current_field->nkeys = nkeys;
	}
  ;}
    break;

  case 462:
#line 4171 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 463:
#line 4174 "parser.y"
    {
	cb_tree l;

	for (l = (yyvsp[(5) - (5)]); l; l = CB_CHAIN (l)) {
		CB_PURPOSE (l) = (yyvsp[(2) - (5)]);
		if (qualifier && !CB_REFERENCE(CB_VALUE(l))->chain &&
		    strcasecmp (CB_NAME(CB_VALUE(l)), CB_NAME(qualifier))) {
			CB_REFERENCE(CB_VALUE(l))->chain = qualifier;
		}
	}
	(yyval) = cb_list_append ((yyvsp[(1) - (5)]), (yyvsp[(5) - (5)]));
  ;}
    break;

  case 464:
#line 4189 "parser.y"
    { (yyval) = cb_int (COB_ASCENDING); ;}
    break;

  case 465:
#line 4190 "parser.y"
    { (yyval) = cb_int (COB_DESCENDING); ;}
    break;

  case 467:
#line 4195 "parser.y"
    {
	current_field->index_list = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 468:
#line 4201 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 469:
#line 4203 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 470:
#line 4208 "parser.y"
    {
	(yyval) = cb_build_index ((yyvsp[(1) - (1)]), cb_int1, 1U, current_field);
	CB_FIELD_PTR ((yyval))->special_index = 1;
  ;}
    break;

  case 471:
#line 4219 "parser.y"
    {
	check_pic_repeated ("JUSTIFIED", SYN_CLAUSE_8);
	current_field->flag_justified = 1;
  ;}
    break;

  case 472:
#line 4230 "parser.y"
    {
	check_pic_repeated ("SYNCHRONIZED", SYN_CLAUSE_9);
	current_field->flag_synchronized = 1;
  ;}
    break;

  case 473:
#line 4241 "parser.y"
    {
	check_pic_repeated ("BLANK", SYN_CLAUSE_10);
	current_field->flag_blank_zero = 1;
  ;}
    break;

  case 474:
#line 4252 "parser.y"
    {
	check_pic_repeated ("BASED", SYN_CLAUSE_11);
	if (current_storage != CB_STORAGE_WORKING &&
	    current_storage != CB_STORAGE_LINKAGE &&
	    current_storage != CB_STORAGE_LOCAL) {
		cb_error (_("BASED not allowed here"));
	} else if (current_field->level != 1 && current_field->level != 77) {
		cb_error (_("BASED only allowed at 01/77 level"));
	} else if (!qualifier) {
		cb_error (_("BASED requires a data name"));
	} else if (current_field->flag_external) {
		cb_error (_("BASED and EXTERNAL are mutually exclusive"));
	} else if (current_field->redefines) {
		cb_error (_("BASED and REDEFINES are mutually exclusive"));
	} else if (current_field->flag_any_length) {
		cb_error (_("BASED and ANY LENGTH are mutually exclusive"));
	} else if (current_field->flag_occurs) {
		cb_error (_("BASED and OCCURS are mutually exclusive"));
	} else {
		current_field->flag_item_based = 1;
	}
  ;}
    break;

  case 475:
#line 4280 "parser.y"
    {
	check_pic_repeated ("VALUE", SYN_CLAUSE_12);
	current_field->values = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 477:
#line 4288 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 478:
#line 4289 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 479:
#line 4293 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 480:
#line 4294 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 482:
#line 4299 "parser.y"
    {
	if (current_field->level != 88) {
		cb_error (_("FALSE clause only allowed for 88 level"));
	}
	current_field->false_88 = CB_LIST_INIT ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 483:
#line 4312 "parser.y"
    {
	check_pic_repeated ("RENAMES", SYN_CLAUSE_13);
	if (cb_ref ((yyvsp[(2) - (2)])) != cb_error_node) {
		if (CB_FIELD (cb_ref ((yyvsp[(2) - (2)])))->level == 01 ||
		    CB_FIELD (cb_ref ((yyvsp[(2) - (2)])))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD (cb_ref ((yyvsp[(2) - (2)])));
			current_field->pic = current_field->redefines->pic;
		}
	}
  ;}
    break;

  case 484:
#line 4325 "parser.y"
    {
	check_pic_repeated ("RENAMES", SYN_CLAUSE_13);
	if (cb_ref ((yyvsp[(2) - (4)])) != cb_error_node && cb_ref ((yyvsp[(4) - (4)])) != cb_error_node) {
		if (CB_FIELD (cb_ref ((yyvsp[(2) - (4)])))->level == 01 ||
		    CB_FIELD (cb_ref ((yyvsp[(2) - (4)])))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else if (CB_FIELD (cb_ref ((yyvsp[(4) - (4)])))->level == 01 ||
		    CB_FIELD (cb_ref ((yyvsp[(4) - (4)])))->level > 50) {
			cb_error (_("RENAMES may not reference a level 01 or > 50"));
		} else {
			current_field->redefines = CB_FIELD (cb_ref ((yyvsp[(2) - (4)])));
			current_field->rename_thru = CB_FIELD (cb_ref ((yyvsp[(4) - (4)])));
		}
	}
  ;}
    break;

  case 485:
#line 4346 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
	}
  ;}
    break;

  case 486:
#line 4355 "parser.y"
    {
	check_pic_repeated ("ANY", SYN_CLAUSE_14);
	if (current_field->flag_item_based) {
		cb_error (_("BASED and ANY clause are mutually exclusive"));
	} else {
		current_field->flag_any_length = 1;
		current_field->flag_any_numeric = 1;
	}
  ;}
    break;

  case 488:
#line 4370 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LOCAL_STORAGE_SECTION;
	current_storage = CB_STORAGE_LOCAL;
	if (current_program->nested_level) {
		cb_error (_("LOCAL-STORAGE not allowed in nested programs"));
	}
  ;}
    break;

  case 489:
#line 4379 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->local_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 491:
#line 4391 "parser.y"
    {
	check_headers_present (COBC_HD_DATA_DIVISION, 0, 0, 0);
	header_check |= COBC_HD_LINKAGE_SECTION;
	current_storage = CB_STORAGE_LINKAGE;
  ;}
    break;

  case 492:
#line 4397 "parser.y"
    {
	if ((yyvsp[(5) - (5)])) {
		current_program->linkage_storage = CB_FIELD ((yyvsp[(5) - (5)]));
	}
  ;}
    break;

  case 494:
#line 4408 "parser.y"
    {
	header_check |= COBC_HD_REPORT_SECTION;
	current_storage = CB_STORAGE_REPORT;
	description_field = NULL;
	current_program->flag_report = 1;
	cb_clear_real_field ();
  ;}
    break;

  case 498:
#line 4426 "parser.y"
    {
	if (CB_INVALID_TREE ((yyvsp[(2) - (2)]))) {
		YYERROR;
	} else {
		current_field = NULL;
		control_field = NULL;
		description_field = NULL;
		current_report = CB_REPORT (cb_ref ((yyvsp[(2) - (2)])));
	}
	check_duplicate = 0;
  ;}
    break;

  case 499:
#line 4439 "parser.y"
    {
	struct cb_field *p;

	for (p = description_field; p; p = p->sister) {
		cb_validate_field (p);
	}
	current_program->report_storage = description_field;
	current_program->flag_report = 1;
	if(current_report->records == NULL)
		current_report->records = description_field;
	finalize_report (current_report, description_field);
	(yyval) = CB_TREE (description_field);
  ;}
    break;

  case 502:
#line 4457 "parser.y"
    {
	yyerrok;
  ;}
    break;

  case 503:
#line 4464 "parser.y"
    {
	check_repeated ("GLOBAL", SYN_CLAUSE_1);
	current_report->global = 1;
	cb_error (_("GLOBAL is not allowed with RD"));
  ;}
    break;

  case 504:
#line 4470 "parser.y"
    {
	check_repeated ("CODE", SYN_CLAUSE_2);
  ;}
    break;

  case 507:
#line 4481 "parser.y"
    {
	check_repeated ("CONTROL", SYN_CLAUSE_3);
  ;}
    break;

  case 511:
#line 4494 "parser.y"
    {
      current_report->control_final = 1;
  ;}
    break;

  case 514:
#line 4506 "parser.y"
    {
	/* Add field to current control list */
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), current_report->controls);
  ;}
    break;

  case 515:
#line 4517 "parser.y"
    {
	check_repeated ("PAGE", SYN_CLAUSE_4);
	if (!current_report->heading) {
		current_report->heading = 1;
	}
	if (!current_report->first_detail) {
		current_report->first_detail = current_report->heading;
	}
	if (!current_report->last_control) {
		if (current_report->last_detail) {
			current_report->last_control = current_report->last_detail;
		} else if (current_report->footing) {
			current_report->last_control = current_report->footing;
		} else {
			current_report->last_control = current_report->lines;
		}
		if (current_report->t_last_detail) {
			current_report->t_last_control = current_report->t_last_detail;
		} else if (current_report->t_footing) {
			current_report->t_last_control = current_report->t_footing;
		} else if(current_report->t_lines) {
			current_report->t_last_control = current_report->t_lines;
		}

	}
	if (!current_report->last_detail && !current_report->footing) {
		current_report->last_detail = current_report->lines;
		current_report->footing = current_report->lines;
	} else if (!current_report->last_detail) {
		current_report->last_detail = current_report->footing;
	} else if (!current_report->footing) {
		current_report->footing = current_report->last_detail;
	}
	if(current_report->heading > 0
	&& current_report->first_detail > 0
	&& current_report->last_control > 0
	&& current_report->last_detail > 0
	&& current_report->footing > 0) {
		if (current_report->heading > current_report->first_detail ||
		    current_report->first_detail > current_report->last_control ||
		    current_report->last_control > current_report->last_detail ||
		    current_report->last_detail > current_report->footing) {
			cb_error (_("Invalid PAGE clause"));
		}
	}
  ;}
    break;

  case 516:
#line 4567 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(1) - (1)]))) {
		current_report->lines = cb_get_int ((yyvsp[(1) - (1)]));
	} else {
		current_report->t_lines = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 517:
#line 4575 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(1) - (2)]))) {
		current_report->lines = cb_get_int ((yyvsp[(1) - (2)]));
	} else {
		current_report->t_lines = (yyvsp[(1) - (2)]);
	}
  ;}
    break;

  case 518:
#line 4583 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(1) - (4)]))) {
		current_report->lines = cb_get_int ((yyvsp[(1) - (4)]));
	} else {
		current_report->t_lines = (yyvsp[(1) - (4)]);
	}
	if (CB_LITERAL_P ((yyvsp[(3) - (4)]))) {
		current_report->columns = cb_get_int ((yyvsp[(3) - (4)]));
	} else {
		current_report->t_columns = (yyvsp[(3) - (4)]);
	}
  ;}
    break;

  case 528:
#line 4617 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(3) - (3)]))) {
		current_report->heading = cb_get_int ((yyvsp[(3) - (3)]));
	} else {
		current_report->t_heading = (yyvsp[(3) - (3)]);
	}
  ;}
    break;

  case 529:
#line 4628 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(4) - (4)]))) {
		current_report->first_detail = cb_get_int ((yyvsp[(4) - (4)]));
	} else {
		current_report->t_first_detail = (yyvsp[(4) - (4)]);
	}
  ;}
    break;

  case 530:
#line 4639 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(4) - (4)]))) {
		current_report->last_control = cb_get_int ((yyvsp[(4) - (4)]));
	} else {
		current_report->t_last_control = (yyvsp[(4) - (4)]);
	}
  ;}
    break;

  case 531:
#line 4650 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(4) - (4)]))) {
		current_report->last_detail = cb_get_int ((yyvsp[(4) - (4)]));
	} else {
		current_report->t_last_detail = (yyvsp[(4) - (4)]);
	}
  ;}
    break;

  case 532:
#line 4661 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(3) - (3)]))) {
		current_report->footing = cb_get_int ((yyvsp[(3) - (3)]));
	} else {
		current_report->t_footing = (yyvsp[(3) - (3)]);
	}
  ;}
    break;

  case 535:
#line 4676 "parser.y"
    {
	cb_tree	x;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (2)]));
	check_pic_duplicate = 0;
	if (CB_INVALID_TREE (x)) {
		YYERROR;
	}

	current_field = CB_FIELD (x);
	if (!description_field) {
		description_field = current_field;
	}
  ;}
    break;

  case 556:
#line 4722 "parser.y"
    {
	check_pic_repeated ("TYPE", SYN_CLAUSE_16);
  ;}
    break;

  case 557:
#line 4729 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_HEADING;
  ;}
    break;

  case 558:
#line 4733 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_PAGE_HEADING;
  ;}
    break;

  case 561:
#line 4739 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_DETAIL;
  ;}
    break;

  case 562:
#line 4743 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_PAGE_FOOTING;
  ;}
    break;

  case 563:
#line 4747 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_FOOTING;
  ;}
    break;

  case 564:
#line 4753 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING;
  ;}
    break;

  case 565:
#line 4757 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING;
      current_field->report_control = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 566:
#line 4762 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_HEADING_FINAL;
  ;}
    break;

  case 567:
#line 4768 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING;
  ;}
    break;

  case 568:
#line 4772 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING;
      current_field->report_control = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 569:
#line 4777 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_CONTROL_FOOTING_FINAL;
  ;}
    break;

  case 570:
#line 4784 "parser.y"
    {
	check_pic_repeated ("NEXT GROUP", SYN_CLAUSE_17);
  ;}
    break;

  case 571:
#line 4791 "parser.y"
    {
	if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign > 0) {
		current_field->report_flag |= COB_REPORT_NEXT_GROUP_PLUS;
	} else {
		current_field->report_flag |= COB_REPORT_NEXT_GROUP_LINE;
	}
	current_field->next_group_line = cb_get_int((yyvsp[(1) - (1)]));
  ;}
    break;

  case 572:
#line 4800 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PLUS;
      current_field->next_group_line = cb_get_int((yyvsp[(2) - (2)]));
  ;}
    break;

  case 573:
#line 4805 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PLUS;
      current_field->next_group_line = cb_get_int((yyvsp[(2) - (2)]));
  ;}
    break;

  case 574:
#line 4810 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_NEXT_GROUP_PAGE;
  ;}
    break;

  case 579:
#line 4824 "parser.y"
    {
	check_pic_repeated ("SUM", SYN_CLAUSE_19);
	current_field->report_sum_list = (yyvsp[(3) - (4)]);
	build_sum_counter( current_report, current_field);
  ;}
    break;

  case 582:
#line 4834 "parser.y"
    {
      current_field->report_sum_upon = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 583:
#line 4841 "parser.y"
    {
      current_field->report_reset = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 584:
#line 4845 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_RESET_FINAL;
  ;}
    break;

  case 585:
#line 4852 "parser.y"
    {
	check_pic_repeated ("PRESENT", SYN_CLAUSE_20);
	current_field->report_when = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 587:
#line 4864 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_21);
	current_field->report_flag |= COB_REPORT_LINE;
  ;}
    break;

  case 590:
#line 4877 "parser.y"
    {
	current_field->report_flag |= COB_REPORT_LINE_PLUS;
  ;}
    break;

  case 591:
#line 4881 "parser.y"
    {
	current_field->report_flag |= COB_REPORT_LINE_PLUS;
  ;}
    break;

  case 595:
#line 4893 "parser.y"
    {
	current_field->report_line = cb_get_int((yyvsp[(1) - (1)]));
	if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign > 0) {
		current_field->report_flag |= COB_REPORT_LINE_PLUS;
	}
  ;}
    break;

  case 596:
#line 4903 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_LINE_NEXT_PAGE;
  ;}
    break;

  case 597:
#line 4907 "parser.y"
    {
      current_field->report_flag |= COB_REPORT_LINE_NEXT_PAGE;
  ;}
    break;

  case 598:
#line 4914 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_18);
  ;}
    break;

  case 601:
#line 4926 "parser.y"
    {
	current_field->report_column = cb_get_int ((yyvsp[(2) - (2)]));
	current_field->report_flag |= COB_REPORT_COLUMN_PLUS;
  ;}
    break;

  case 602:
#line 4931 "parser.y"
    {
	current_field->report_column = cb_get_int ((yyvsp[(1) - (1)]));
	if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign > 0) {
		current_field->report_flag |= COB_REPORT_COLUMN_PLUS;
	}
  ;}
    break;

  case 603:
#line 4941 "parser.y"
    {
	check_pic_repeated ("SOURCE", SYN_CLAUSE_22);
	current_field->report_source = (yyvsp[(3) - (4)]);
  ;}
    break;

  case 604:
#line 4949 "parser.y"
    {
	check_pic_repeated ("GROUP", SYN_CLAUSE_23);
	current_field->report_flag |= COB_REPORT_GROUP_INDICATE;
  ;}
    break;

  case 605:
#line 4957 "parser.y"
    {
	check_pic_repeated ("USAGE", SYN_CLAUSE_24);
  ;}
    break;

  case 607:
#line 4966 "parser.y"
    {
	current_storage = CB_STORAGE_SCREEN;
	current_field = NULL;
	description_field = NULL;
	cb_clear_real_field ();
  ;}
    break;

  case 608:
#line 4973 "parser.y"
    {
	struct cb_field *p;

	if (description_field) {
		for (p = description_field; p; p = p->sister) {
			cb_validate_field (p);
		}
		current_program->screen_storage = description_field;
		current_program->flag_screen = 1;
	}
  ;}
    break;

  case 614:
#line 4998 "parser.y"
    {
	cb_tree	x;
	int	flags;

	x = cb_build_field_tree ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), current_field, current_storage,
				 current_file, 0);
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (2)]));
	check_pic_duplicate = 0;
	if (CB_INVALID_TREE (x)) {
		YYERROR;
	}

	current_field = CB_FIELD (x);
	if (current_field->parent) {
		flags = current_field->parent->screen_flag;
		flags &= ~COB_SCREEN_BLANK_LINE;
		flags &= ~COB_SCREEN_BLANK_SCREEN;
		flags &= ~COB_SCREEN_ERASE_EOL;
		flags &= ~COB_SCREEN_ERASE_EOS;
		flags &= ~COB_SCREEN_LINE_PLUS;
		flags &= ~COB_SCREEN_LINE_MINUS;
		flags &= ~COB_SCREEN_COLUMN_PLUS;
		flags &= ~COB_SCREEN_COLUMN_MINUS;
		current_field->screen_flag |= flags;
		current_field->screen_foreg = current_field->parent->screen_foreg;
		current_field->screen_backg = current_field->parent->screen_backg;
		current_field->screen_prompt = current_field->parent->screen_prompt;
	}
  ;}
    break;

  case 615:
#line 5029 "parser.y"
    {
	if (!qualifier && (current_field->level == 88 ||
	    current_field->level == 66 ||
	    current_field->flag_item_78)) {
		cb_error (_("Item requires a data name"));
	}
	if (current_field->screen_flag & COB_SCREEN_INITIAL) {
		if (!(current_field->screen_flag & COB_SCREEN_INPUT)) {
			cb_error (_("INITIAL specified on non-input field"));
		}
	}
	if (!qualifier) {
		current_field->flag_filler = 1;
	}
	if (current_field->level == 88) {
		cb_validate_88_item (current_field);
	}
	if (current_field->flag_item_78) {
		/* Reset to last non-78 item */
		current_field = cb_validate_78_item (current_field, 0);
	}
	if (!description_field) {
		description_field = current_field;
	}
  ;}
    break;

  case 616:
#line 5055 "parser.y"
    {
	/* Free tree assocated with level number */
	cobc_parse_free ((yyvsp[(1) - (3)]));
	yyerrok;
	cb_unput_dot ();
	check_pic_duplicate = 0;
	check_duplicate = 0;
#if	1	/* RXWRXW Screen field */
	if (current_field) {
		current_field->flag_is_verified = 1;
		current_field->flag_invalid = 1;
	}
#endif
	current_field = cb_get_real_field ();
  ;}
    break;

  case 619:
#line 5078 "parser.y"
    {
	check_screen_attr ("BLANK LINE", COB_SCREEN_BLANK_LINE);
  ;}
    break;

  case 620:
#line 5082 "parser.y"
    {
	check_screen_attr ("BLANK SCREEN", COB_SCREEN_BLANK_SCREEN);
  ;}
    break;

  case 621:
#line 5086 "parser.y"
    {
	check_screen_attr ("BELL", COB_SCREEN_BELL);
  ;}
    break;

  case 622:
#line 5090 "parser.y"
    {
	check_screen_attr ("BLINK", COB_SCREEN_BLINK);
  ;}
    break;

  case 623:
#line 5094 "parser.y"
    {
	check_screen_attr ("ERASE EOL", COB_SCREEN_ERASE_EOL);
  ;}
    break;

  case 624:
#line 5098 "parser.y"
    {
	check_screen_attr ("ERASE EOS", COB_SCREEN_ERASE_EOS);
  ;}
    break;

  case 625:
#line 5102 "parser.y"
    {
	check_screen_attr ("HIGHLIGHT", COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 626:
#line 5106 "parser.y"
    {
	check_screen_attr ("LOWLIGHT", COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 627:
#line 5110 "parser.y"
    {
	check_screen_attr ("REVERSE-VIDEO", COB_SCREEN_REVERSE);
  ;}
    break;

  case 628:
#line 5114 "parser.y"
    {
	check_screen_attr ("UNDERLINE", COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 629:
#line 5118 "parser.y"
    {
	check_screen_attr ("OVERLINE", COB_SCREEN_OVERLINE);
  ;}
    break;

  case 630:
#line 5122 "parser.y"
    {
	check_screen_attr ("LEFTLINE", COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 631:
#line 5126 "parser.y"
    {
	check_screen_attr ("AUTO", COB_SCREEN_AUTO);
  ;}
    break;

  case 632:
#line 5130 "parser.y"
    {
	check_screen_attr ("SECURE", COB_SCREEN_SECURE);
  ;}
    break;

  case 633:
#line 5134 "parser.y"
    {
	check_screen_attr ("REQUIRED", COB_SCREEN_REQUIRED);
  ;}
    break;

  case 634:
#line 5138 "parser.y"
    {
	check_screen_attr ("FULL", COB_SCREEN_FULL);
  ;}
    break;

  case 635:
#line 5142 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
	current_field->screen_prompt = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 636:
#line 5147 "parser.y"
    {
	check_screen_attr ("PROMPT", COB_SCREEN_PROMPT);
  ;}
    break;

  case 637:
#line 5151 "parser.y"
    {
	check_screen_attr ("INITIAL", COB_SCREEN_INITIAL);
  ;}
    break;

  case 638:
#line 5155 "parser.y"
    {
	check_pic_repeated ("LINE", SYN_CLAUSE_16);
	current_field->screen_line = (yyvsp[(5) - (5)]);
  ;}
    break;

  case 639:
#line 5160 "parser.y"
    {
	check_pic_repeated ("COLUMN", SYN_CLAUSE_17);
	current_field->screen_column = (yyvsp[(5) - (5)]);
  ;}
    break;

  case 640:
#line 5165 "parser.y"
    {
	check_pic_repeated ("FOREGROUND-COLOR", SYN_CLAUSE_18);
	current_field->screen_foreg = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 641:
#line 5170 "parser.y"
    {
	check_pic_repeated ("BACKGROUND-COLOR", SYN_CLAUSE_19);
	current_field->screen_backg = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 650:
#line 5183 "parser.y"
    {
	check_pic_repeated ("USING", SYN_CLAUSE_20);
	current_field->screen_from = (yyvsp[(2) - (2)]);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  ;}
    break;

  case 651:
#line 5190 "parser.y"
    {
	check_pic_repeated ("FROM", SYN_CLAUSE_21);
	current_field->screen_from = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 652:
#line 5195 "parser.y"
    {
	check_pic_repeated ("TO", SYN_CLAUSE_22);
	current_field->screen_to = (yyvsp[(2) - (2)]);
	current_field->screen_flag |= COB_SCREEN_INPUT;
  ;}
    break;

  case 657:
#line 5214 "parser.y"
    {
	/* Nothing */
  ;}
    break;

  case 658:
#line 5218 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_PLUS;
  ;}
    break;

  case 659:
#line 5222 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_LINE_MINUS;
  ;}
    break;

  case 660:
#line 5229 "parser.y"
    {
	/* Nothing */
  ;}
    break;

  case 661:
#line 5233 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_PLUS;
  ;}
    break;

  case 662:
#line 5237 "parser.y"
    {
	current_field->screen_flag |= COB_SCREEN_COLUMN_MINUS;
  ;}
    break;

  case 663:
#line 5245 "parser.y"
    {
	check_pic_repeated ("OCCURS", SYN_CLAUSE_23);
	current_field->occurs_max = cb_get_int ((yyvsp[(2) - (3)]));
	current_field->occurs_min = current_field->occurs_max;
	current_field->indexes++;
	current_field->flag_occurs = 1;
  ;}
    break;

  case 664:
#line 5256 "parser.y"
    {
	cb_error (_("GLOBAL is not allowed with screen items"));
  ;}
    break;

  case 666:
#line 5265 "parser.y"
    {
	current_section = NULL;
	current_paragraph = NULL;
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	cb_set_system_names ();
	header_check |= COBC_HD_PROCEDURE_DIVISION;
  ;}
    break;

  case 667:
#line 5275 "parser.y"
    {
	if (current_program->flag_main && !current_program->flag_chained && (yyvsp[(3) - (7)])) {
		cb_error (_("Executable program requested but PROCEDURE/ENTRY has USING clause"));
	}
	/* Main entry point */
	emit_entry (current_program->program_id, 0, (yyvsp[(3) - (7)]));
	current_program->num_proc_params = cb_list_length ((yyvsp[(3) - (7)]));
	if (current_program->source_name) {
		emit_entry (current_program->source_name, 1, (yyvsp[(3) - (7)]));
	}
  ;}
    break;

  case 668:
#line 5287 "parser.y"
    {
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
	}
	if (current_section) {
		if (current_section->exit_label) {
			emit_statement (current_section->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_section));
	}
  ;}
    break;

  case 669:
#line 5302 "parser.y"
    {
	cb_tree label;

	/* No PROCEDURE DIVISION header ! */
	/* Only a statement is allowed as first element */
	/* Thereafter, sections/paragraphs may be used */
	check_pic_duplicate = 0;
	check_duplicate = 0;
	cobc_in_procedure = 1U;
	label = cb_build_reference ("MAIN SECTION");
	current_section = CB_LABEL (cb_build_label (label, NULL));
	current_section->flag_section = 1;
	current_section->flag_dummy_section = 1;
	current_section->flag_skip_label = !!skip_statements;
	current_section->flag_declaratives = !!in_declaratives;
	CB_TREE (current_section)->source_file = cb_source_file;
	CB_TREE (current_section)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_section));
	label = cb_build_reference ("MAIN PARAGRAPH");
	current_paragraph = CB_LABEL (cb_build_label (label, NULL));
	current_paragraph->flag_declaratives = !!in_declaratives;
	current_paragraph->flag_skip_label = !!skip_statements;
	current_paragraph->flag_dummy_paragraph = 1;
	CB_TREE (current_paragraph)->source_file = cb_source_file;
	CB_TREE (current_paragraph)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_paragraph));
	cb_set_system_names ();
  ;}
    break;

  case 671:
#line 5335 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 672:
#line 5339 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  ;}
    break;

  case 673:
#line 5344 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 674:
#line 5352 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("CHAINING invalid in user FUNCTION"));
	} else {
		current_program->flag_chained = 1;
	}
  ;}
    break;

  case 675:
#line 5361 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error (_("Number of parameters exceeds maximum %d"),
			  COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 676:
#line 5371 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 677:
#line 5373 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 678:
#line 5378 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_build_identifier ((yyvsp[(4) - (4)]), 0));
	CB_SIZES ((yyval)) = size_mode;
  ;}
    break;

  case 680:
#line 5387 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  ;}
    break;

  case 681:
#line 5391 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error (_("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  ;}
    break;

  case 683:
#line 5403 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO;
	}
  ;}
    break;

  case 684:
#line 5411 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_4;
	}
  ;}
    break;

  case 685:
#line 5419 "parser.y"
    {
	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else {
		size_mode = CB_SIZE_AUTO | CB_SIZE_UNSIGNED;
	}
  ;}
    break;

  case 686:
#line 5427 "parser.y"
    {
	unsigned char *s = CB_LITERAL ((yyvsp[(4) - (4)]))->data;

	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else if (CB_LITERAL ((yyvsp[(4) - (4)]))->size != 1) {
		cb_error_x ((yyvsp[(4) - (4)]), _("Invalid value for SIZE"));
	} else {
		size_mode = CB_SIZE_UNSIGNED;
		switch (*s) {
		case '1':
			size_mode |= CB_SIZE_1;
			break;
		case '2':
			size_mode |= CB_SIZE_2;
			break;
		case '4':
			size_mode |= CB_SIZE_4;
			break;
		case '8':
			size_mode |= CB_SIZE_8;
			break;
		default:
			cb_error_x ((yyvsp[(4) - (4)]), _("Invalid value for SIZE"));
			break;
		}
	}
  ;}
    break;

  case 687:
#line 5456 "parser.y"
    {
	unsigned char *s = CB_LITERAL ((yyvsp[(3) - (3)]))->data;

	if (call_mode != CB_CALL_BY_VALUE) {
		cb_error (_("SIZE only allowed for BY VALUE items"));
	} else if (CB_LITERAL ((yyvsp[(3) - (3)]))->size != 1) {
		cb_error_x ((yyvsp[(3) - (3)]), _("Invalid value for SIZE"));
	} else {
		size_mode = 0;
		switch (*s) {
		case '1':
			size_mode = CB_SIZE_1;
			break;
		case '2':
			size_mode = CB_SIZE_2;
			break;
		case '4':
			size_mode = CB_SIZE_4;
			break;
		case '8':
			size_mode = CB_SIZE_8;
			break;
		default:
			cb_error_x ((yyvsp[(3) - (3)]), _("Invalid value for SIZE"));
			break;
		}
	}
  ;}
    break;

  case 689:
#line 5489 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error (_("OPTIONAL only allowed for BY REFERENCE items"));
	}
  ;}
    break;

  case 690:
#line 5498 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("RETURNING clause is required for a FUNCTION"));
	}
  ;}
    break;

  case 691:
#line 5504 "parser.y"
    {
	struct cb_field	*f;

	if (cb_ref ((yyvsp[(2) - (2)])) != cb_error_node) {
		f = CB_FIELD_PTR ((yyvsp[(2) - (2)]));
/* RXWRXW
		if (f->storage != CB_STORAGE_LINKAGE) {
			cb_error (_("RETURNING item is not defined in LINKAGE SECTION"));
		} else if (f->level != 1 && f->level != 77) {
*/
		if (f->level != 1 && f->level != 77) {
			cb_error (_("RETURNING item must have level 01"));
		} else {
			if (current_program->prog_type == CB_FUNCTION_TYPE) {
				f->flag_is_returning = 1;
			}
			current_program->returning = (yyvsp[(2) - (2)]);
		}
	}
  ;}
    break;

  case 693:
#line 5528 "parser.y"
    {
	in_declaratives = 1;
	emit_statement (cb_build_comment ("DECLARATIVES"));
  ;}
    break;

  case 694:
#line 5534 "parser.y"
    {
	if (needs_field_debug) {
		start_debug = 1;
	}
	in_declaratives = 0;
	in_debugging = 0;
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
		current_paragraph = NULL;
	}
	if (current_section) {
		if (current_section->exit_label) {
			emit_statement (current_section->exit_label);
		}
		current_section->flag_fatal_check = 1;
		emit_statement (cb_build_perform_exit (current_section));
		current_section = NULL;
	}
	skip_statements = 0;
	emit_statement (cb_build_comment ("END DECLARATIVES"));
  ;}
    break;

  case 699:
#line 5571 "parser.y"
    {
	if (next_label_list) {
		cb_tree	plabel;
		char	name[32];

		snprintf (name, sizeof(name), "L$%d", next_label_id);
		plabel = cb_build_label (cb_build_reference (name), NULL);
		CB_LABEL (plabel)->flag_next_sentence = 1;
		emit_statement (plabel);
		current_program->label_list =
			cb_list_append (current_program->label_list, next_label_list);
		next_label_list = NULL;
		next_label_id++;
	}
	/* check_unreached = 0; */
  ;}
    break;

  case 701:
#line 5589 "parser.y"
    {
	/* check_unreached = 0; */
  ;}
    break;

  case 702:
#line 5599 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (4)]), 0) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last paragraph/section */
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
	}
	if (current_section) {
		if (current_section->exit_label) {
			emit_statement (current_section->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_section));
	}
	if (current_program->flag_debugging && !in_debugging) {
		if (current_paragraph || current_section) {
			emit_statement (cb_build_comment (
					"DEBUGGING - Fall through"));
			emit_statement (cb_build_debug (cb_debug_contents,
					"FALL THROUGH", NULL));
		}
	}

	/* Begin a new section */
	current_section = CB_LABEL (cb_build_label ((yyvsp[(1) - (4)]), NULL));
	if ((yyvsp[(3) - (4)])) {
		current_section->segment = cb_get_int ((yyvsp[(3) - (4)]));
	}
	current_section->flag_section = 1;
	/* Careful here, one negation */
	current_section->flag_real_label = !in_debugging;
	current_section->flag_declaratives = !!in_declaratives;
	current_section->flag_skip_label = !!skip_statements;
	CB_TREE (current_section)->source_file = cb_source_file;
	CB_TREE (current_section)->source_line = cb_source_line;
	current_paragraph = NULL;
  ;}
    break;

  case 703:
#line 5643 "parser.y"
    {
	emit_statement (CB_TREE (current_section));
  ;}
    break;

  case 706:
#line 5654 "parser.y"
    {
	cb_tree label;

	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (2)]), 1) == cb_error_node) {
		YYERROR;
	}

	/* Exit the last paragraph */
	if (current_paragraph) {
		if (current_paragraph->exit_label) {
			emit_statement (current_paragraph->exit_label);
		}
		emit_statement (cb_build_perform_exit (current_paragraph));
		if (current_program->flag_debugging && !in_debugging) {
			emit_statement (cb_build_comment (
					"DEBUGGING - Fall through"));
			emit_statement (cb_build_debug (cb_debug_contents,
					"FALL THROUGH", NULL));
		}
	}

	/* Begin a new paragraph */
	if (!current_section) {
		label = cb_build_reference ("MAIN SECTION");
		current_section = CB_LABEL (cb_build_label (label, NULL));
		current_section->flag_section = 1;
		current_section->flag_dummy_section = 1;
		current_section->flag_declaratives = !!in_declaratives;
		current_section->flag_skip_label = !!skip_statements;
		CB_TREE (current_section)->source_file = cb_source_file;
		CB_TREE (current_section)->source_line = cb_source_line;
		emit_statement (CB_TREE (current_section));
	}
	current_paragraph = CB_LABEL (cb_build_label ((yyvsp[(1) - (2)]), current_section));
	current_paragraph->flag_declaratives =!! in_declaratives;
	current_paragraph->flag_skip_label = !!skip_statements;
	current_paragraph->flag_real_label = !in_debugging;
	current_paragraph->segment = current_section->segment;
	CB_TREE (current_paragraph)->source_file = cb_source_file;
	CB_TREE (current_paragraph)->source_line = cb_source_line;
	emit_statement (CB_TREE (current_paragraph));
  ;}
    break;

  case 707:
#line 5702 "parser.y"
    {
	non_const_word = 0;
	check_unreached = 0;
	if (cb_build_section_name ((yyvsp[(1) - (1)]), 0) != cb_error_node) {
		cb_error_x ((yyvsp[(1) - (1)]), _("Unknown statement '%s'"), CB_NAME ((yyvsp[(1) - (1)])));
	}
	YYERROR;
  ;}
    break;

  case 708:
#line 5714 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 709:
#line 5718 "parser.y"
    {
	if (in_declaratives) {
		cb_error (_("SECTION segment invalid within DECLARATIVE"));
	}
	if (cb_verify (cb_section_segments, "SECTION segment")) {
		current_program->flag_segments = 1;
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		(yyval) = NULL;
	}
  ;}
    break;

  case 710:
#line 5736 "parser.y"
    {
	(yyval) = current_program->exec_list;
	current_program->exec_list = NULL;
	check_unreached = 0;
  ;}
    break;

  case 711:
#line 5741 "parser.y"
    {
	(yyval) = CB_TREE (current_statement);
	current_statement = NULL;
  ;}
    break;

  case 712:
#line 5746 "parser.y"
    {
	(yyval) = cb_list_reverse (current_program->exec_list);
	current_program->exec_list = (yyvsp[(1) - (3)]);
	current_statement = CB_STATEMENT ((yyvsp[(2) - (3)]));
  ;}
    break;

  case 713:
#line 5754 "parser.y"
    {
	cb_tree label;

	if (!current_section) {
		label = cb_build_reference ("MAIN SECTION");
		current_section = CB_LABEL (cb_build_label (label, NULL));
		current_section->flag_section = 1;
		current_section->flag_dummy_section = 1;
		current_section->flag_skip_label = !!skip_statements;
		current_section->flag_declaratives = !!in_declaratives;
		CB_TREE (current_section)->source_file = cb_source_file;
		CB_TREE (current_section)->source_line = cb_source_line;
		emit_statement (CB_TREE (current_section));
	}
	if (!current_paragraph) {
		label = cb_build_reference ("MAIN PARAGRAPH");
		current_paragraph = CB_LABEL (cb_build_label (label, NULL));
		current_paragraph->flag_declaratives = !!in_declaratives;
		current_paragraph->flag_skip_label = !!skip_statements;
		current_paragraph->flag_dummy_paragraph = 1;
		CB_TREE (current_paragraph)->source_file = cb_source_file;
		CB_TREE (current_paragraph)->source_line = cb_source_line;
		emit_statement (CB_TREE (current_paragraph));
	}
	check_headers_present (COBC_HD_PROCEDURE_DIVISION, 0, 0, 0);
  ;}
    break;

  case 714:
#line 5781 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 715:
#line 5785 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 765:
#line 5841 "parser.y"
    {
	if (cb_verify (cb_next_sentence_phrase, "NEXT SENTENCE")) {
		cb_tree label;
		char	name[32];

		begin_statement ("NEXT SENTENCE", 0);
		sprintf (name, "L$%d", next_label_id);
		label = cb_build_reference (name);
		next_label_list = cb_list_add (next_label_list, label);
		emit_statement (cb_build_goto (label, NULL));
	}
	check_unreached = 0;
  ;}
    break;

  case 766:
#line 5855 "parser.y"
    {
	yyerrok;
	cobc_cs_check = 0;
  ;}
    break;

  case 767:
#line 5866 "parser.y"
    {
	begin_statement ("ACCEPT", TERM_ACCEPT);
  ;}
    break;

  case 769:
#line 5876 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), current_statement->attr_ptr);
  ;}
    break;

  case 770:
#line 5881 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 0);
  ;}
    break;

  case 771:
#line 5885 "parser.y"
    {
	cb_emit_accept_line_or_col ((yyvsp[(1) - (3)]), 1);
  ;}
    break;

  case 772:
#line 5889 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date_yyyymmdd ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 773:
#line 5894 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_date ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 774:
#line 5899 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day_yyyyddd ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 775:
#line 5904 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_day ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 776:
#line 5909 "parser.y"
    {
	cb_emit_accept_day_of_week ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 777:
#line 5913 "parser.y"
    {
	cb_emit_accept_escape_key ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 778:
#line 5917 "parser.y"
    {
	cb_emit_accept_exception_status ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 779:
#line 5921 "parser.y"
    {
	cb_emit_accept_time ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 780:
#line 5925 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_accept_user_name ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 781:
#line 5930 "parser.y"
    {
	cb_emit_accept_command_line ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 782:
#line 5934 "parser.y"
    {
	cb_emit_accept_environment ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 783:
#line 5938 "parser.y"
    {
	cb_emit_get_environment ((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
  ;}
    break;

  case 784:
#line 5942 "parser.y"
    {
	cb_emit_accept_arg_number ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 785:
#line 5946 "parser.y"
    {
	cb_emit_accept_arg_value ((yyvsp[(1) - (4)]));
  ;}
    break;

  case 786:
#line 5950 "parser.y"
    {
	cb_emit_accept_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 787:
#line 5954 "parser.y"
    {
	cb_emit_accept_name ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 789:
#line 5962 "parser.y"
    {
	(yyval) = cb_null;
  ;}
    break;

  case 792:
#line 5973 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 793:
#line 5974 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 794:
#line 5978 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 795:
#line 5979 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 796:
#line 5980 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), cb_int0); ;}
    break;

  case 797:
#line 5981 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, (yyvsp[(2) - (2)])); ;}
    break;

  case 798:
#line 5982 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 799:
#line 5986 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 800:
#line 5990 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 801:
#line 5991 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 805:
#line 6000 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 810:
#line 6016 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_AUTO);
  ;}
    break;

  case 811:
#line 6020 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  ;}
    break;

  case 812:
#line 6024 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  ;}
    break;

  case 813:
#line 6028 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  ;}
    break;

  case 814:
#line 6032 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_FULL);
  ;}
    break;

  case 815:
#line 6036 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 816:
#line 6040 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 817:
#line 6044 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWER);
  ;}
    break;

  case 818:
#line 6048 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 819:
#line 6052 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_NO_ECHO);
  ;}
    break;

  case 820:
#line 6056 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  ;}
    break;

  case 821:
#line 6060 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, (yyvsp[(4) - (4)]), COB_SCREEN_PROMPT);
  ;}
    break;

  case 822:
#line 6064 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_PROMPT);
  ;}
    break;

  case 823:
#line 6068 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REQUIRED);
  ;}
    break;

  case 824:
#line 6072 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  ;}
    break;

  case 825:
#line 6076 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_SECURE);
  ;}
    break;

  case 826:
#line 6080 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 827:
#line 6084 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPDATE);
  ;}
    break;

  case 828:
#line 6088 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UPPER);
  ;}
    break;

  case 829:
#line 6092 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  ;}
    break;

  case 830:
#line 6096 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  ;}
    break;

  case 831:
#line 6100 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  ;}
    break;

  case 832:
#line 6104 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  ;}
    break;

  case 833:
#line 6108 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, (yyvsp[(3) - (3)]), NULL, 0);
  ;}
    break;

  case 834:
#line 6115 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ACCEPT);
  ;}
    break;

  case 835:
#line 6119 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ACCEPT);
  ;}
    break;

  case 836:
#line 6129 "parser.y"
    {
	begin_statement ("ADD", TERM_ADD);
  ;}
    break;

  case 838:
#line 6138 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '+', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  ;}
    break;

  case 839:
#line 6142 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(4) - (5)]), 0, cb_build_binary_list ((yyvsp[(1) - (5)]), '+'));
  ;}
    break;

  case 840:
#line 6146 "parser.y"
    {
	cb_emit_corresponding (cb_build_add, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 842:
#line 6153 "parser.y"
    {
	cb_list_add ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 843:
#line 6160 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), ADD);
  ;}
    break;

  case 844:
#line 6164 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), ADD);
  ;}
    break;

  case 845:
#line 6174 "parser.y"
    {
	begin_statement ("ALLOCATE", 0);
	current_statement->flag_no_based = 1;
  ;}
    break;

  case 847:
#line 6183 "parser.y"
    {
	cb_emit_allocate ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), NULL, (yyvsp[(2) - (3)]));
  ;}
    break;

  case 848:
#line 6187 "parser.y"
    {
	if ((yyvsp[(4) - (4)]) == NULL) {
		cb_error_x (CB_TREE (current_statement),
			    _("ALLOCATE CHARACTERS requires RETURNING clause"));
	} else {
		cb_emit_allocate (NULL, (yyvsp[(4) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
	}
  ;}
    break;

  case 849:
#line 6198 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 850:
#line 6199 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 851:
#line 6207 "parser.y"
    {
	begin_statement ("ALTER", 0);
	cb_verify (cb_alter_statement, "ALTER statement");
  ;}
    break;

  case 855:
#line 6221 "parser.y"
    {
	cb_emit_alter ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 858:
#line 6233 "parser.y"
    {
	begin_statement ("CALL", TERM_CALL);
	cobc_cs_check = CB_CS_CALL;
  ;}
    break;

  case 860:
#line 6248 "parser.y"
    {
	if (CB_LITERAL_P ((yyvsp[(2) - (6)])) &&
	    current_program->prog_type == CB_PROGRAM_TYPE &&
	    !current_program->flag_recursive &&
	    !strcmp ((const char *)(CB_LITERAL((yyvsp[(2) - (6)]))->data), current_program->orig_program_id)) {
		cb_warning_x ((yyvsp[(2) - (6)]), _("Recursive program call - assuming RECURSIVE attribute"));
		current_program->flag_recursive = 1;
	}
	cb_emit_call ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]), (yyvsp[(1) - (6)]));
  ;}
    break;

  case 861:
#line 6262 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  ;}
    break;

  case 862:
#line 6267 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STATIC_LINK);
	cobc_cs_check = 0;
  ;}
    break;

  case 863:
#line 6272 "parser.y"
    {
	(yyval) = cb_int (CB_CONV_STDCALL);
	cobc_cs_check = 0;
  ;}
    break;

  case 864:
#line 6277 "parser.y"
    {
	cb_tree		x;

	x = cb_ref ((yyvsp[(1) - (1)]));
	if (CB_VALID_TREE (x)) {
		if (CB_SYSTEM_NAME(x)->token != CB_FEATURE_CONVENTION) {
			cb_error_x ((yyvsp[(1) - (1)]), _("Invalid mnemonic name"));
			(yyval) = NULL;
		} else {
			(yyval) = CB_SYSTEM_NAME(x)->value;
		}
	} else {
		(yyval) = NULL;
	}
	cobc_cs_check = 0;
  ;}
    break;

  case 865:
#line 6297 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 866:
#line 6301 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
	size_mode = CB_SIZE_4;
  ;}
    break;

  case 867:
#line 6306 "parser.y"
    {
	if (cb_list_length ((yyvsp[(3) - (3)])) > COB_MAX_FIELD_PARAMS) {
		cb_error_x (CB_TREE (current_statement),
			    _("Number of parameters exceeds maximum %d"),
			    COB_MAX_FIELD_PARAMS);
	}
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 868:
#line 6317 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 869:
#line 6319 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 870:
#line 6324 "parser.y"
    {
	if (call_mode != CB_CALL_BY_REFERENCE) {
		cb_error_x (CB_TREE (current_statement),
			    _("OMITTED only allowed with BY REFERENCE"));
	}
	(yyval) = CB_BUILD_PAIR (cb_int (call_mode), cb_null);
  ;}
    break;

  case 871:
#line 6332 "parser.y"
    {
	int	save_mode;

	save_mode = call_mode;
	if (call_mode != CB_CALL_BY_REFERENCE) {
		if (CB_FILE_P ((yyvsp[(3) - (3)])) || (CB_REFERENCE_P ((yyvsp[(3) - (3)])) &&
		    CB_FILE_P (CB_REFERENCE ((yyvsp[(3) - (3)]))->value))) {
			cb_error_x (CB_TREE (current_statement),
				    _("Invalid file name reference"));
		} else if (call_mode == CB_CALL_BY_VALUE) {
			if (cb_category_is_alpha ((yyvsp[(3) - (3)]))) {
				cb_warning_x ((yyvsp[(3) - (3)]),
					      _("BY CONTENT assumed for alphanumeric item"));
				save_mode = CB_CALL_BY_CONTENT;
			}
		}
	}
	(yyval) = CB_BUILD_PAIR (cb_int (save_mode), (yyvsp[(3) - (3)]));
	CB_SIZES ((yyval)) = size_mode;
	call_mode = save_mode;
  ;}
    break;

  case 873:
#line 6358 "parser.y"
    {
	call_mode = CB_CALL_BY_REFERENCE;
  ;}
    break;

  case 874:
#line 6362 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY CONTENT not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_CONTENT;
	}
  ;}
    break;

  case 875:
#line 6371 "parser.y"
    {
	if (current_program->flag_chained) {
		cb_error_x (CB_TREE (current_statement),
			    _("BY VALUE not allowed in CHAINED program"));
	} else {
		call_mode = CB_CALL_BY_VALUE;
	}
  ;}
    break;

  case 876:
#line 6383 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 877:
#line 6387 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 878:
#line 6391 "parser.y"
    {
	(yyval) = cb_null;
  ;}
    break;

  case 879:
#line 6395 "parser.y"
    {
	struct cb_field	*f;

	if (cb_ref ((yyvsp[(4) - (4)])) != cb_error_node) {
		f = CB_FIELD_PTR ((yyvsp[(4) - (4)]));
		if (f->level != 1 && f->level != 77) {
			cb_error (_("RETURNING item must have level 01 or 77"));
			(yyval) = NULL;
		} else if (f->storage != CB_STORAGE_LINKAGE &&
			   !f->flag_item_based) {
			cb_error (_("RETURNING item is neither in LINKAGE SECTION nor is it BASED"));
			(yyval) = NULL;
		} else {
			(yyval) = cb_build_address ((yyvsp[(4) - (4)]));
		}
	} else {
		(yyval) = NULL;
	}
  ;}
    break;

  case 884:
#line 6428 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 885:
#line 6433 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 886:
#line 6440 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 887:
#line 6445 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 888:
#line 6452 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), CALL);
  ;}
    break;

  case 889:
#line 6456 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), CALL);
  ;}
    break;

  case 890:
#line 6466 "parser.y"
    {
	begin_statement ("CANCEL", 0);
  ;}
    break;

  case 892:
#line 6474 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 893:
#line 6478 "parser.y"
    {
	cb_emit_cancel ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 894:
#line 6488 "parser.y"
    {
	begin_statement ("CLOSE", 0);
  ;}
    break;

  case 896:
#line 6496 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 897:
#line 6501 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_close ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 898:
#line 6508 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NORMAL); ;}
    break;

  case 899:
#line 6509 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT); ;}
    break;

  case 900:
#line 6510 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_UNIT_REMOVAL); ;}
    break;

  case 901:
#line 6511 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_NO_REWIND); ;}
    break;

  case 902:
#line 6512 "parser.y"
    { (yyval) = cb_int (COB_CLOSE_LOCK); ;}
    break;

  case 903:
#line 6520 "parser.y"
    {
	begin_statement ("COMPUTE", TERM_COMPUTE);
  ;}
    break;

  case 905:
#line 6529 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(1) - (4)]), 0, (yyvsp[(3) - (4)]));
  ;}
    break;

  case 906:
#line 6536 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), COMPUTE);
  ;}
    break;

  case 907:
#line 6540 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), COMPUTE);
  ;}
    break;

  case 908:
#line 6550 "parser.y"
    {
	begin_statement ("COMMIT", 0);
	cb_emit_commit ();
  ;}
    break;

  case 909:
#line 6561 "parser.y"
    {
	size_t	save_unreached;

	/* Do not check unreached for CONTINUE */
	save_unreached = check_unreached;
	check_unreached = 0;
	begin_statement ("CONTINUE", 0);
	cb_emit_continue ();
	check_unreached = save_unreached;
  ;}
    break;

  case 910:
#line 6578 "parser.y"
    {
	begin_statement ("DELETE", TERM_DELETE);
  ;}
    break;

  case 912:
#line 6587 "parser.y"
    {
	cb_emit_delete ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 914:
#line 6595 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 915:
#line 6600 "parser.y"
    {
	begin_implicit_statement ();
	cb_emit_delete_file ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 916:
#line 6608 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DELETE);
  ;}
    break;

  case 917:
#line 6612 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DELETE);
  ;}
    break;

  case 918:
#line 6622 "parser.y"
    {
	begin_statement ("DISPLAY", TERM_DISPLAY);
	cobc_cs_check = CB_CS_DISPLAY;
  ;}
    break;

  case 920:
#line 6632 "parser.y"
    {
	cb_emit_env_name ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 921:
#line 6636 "parser.y"
    {
	cb_emit_env_value ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 922:
#line 6640 "parser.y"
    {
	cb_emit_arg_number ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 923:
#line 6644 "parser.y"
    {
	cb_emit_command_line ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 924:
#line 6648 "parser.y"
    {
	cb_emit_display ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL);
  ;}
    break;

  case 926:
#line 6653 "parser.y"
    {
	cobc_cs_check = 0;
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (4)])), cb_null, cb_int1,
			 NULL, current_statement->attr_ptr);
  ;}
    break;

  case 928:
#line 6663 "parser.y"
    {
	begin_implicit_statement ();
  ;}
    break;

  case 930:
#line 6671 "parser.y"
    {
	cb_emit_display (CB_LIST_INIT ((yyvsp[(1) - (5)])), cb_null, cb_int1,
			 (yyvsp[(2) - (5)]), current_statement->attr_ptr);
  ;}
    break;

  case 931:
#line 6679 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 932:
#line 6687 "parser.y"
    {
	(yyval) = cb_build_display_mnemonic ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 933:
#line 6691 "parser.y"
    {
	(yyval) = cb_build_display_name ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 934:
#line 6695 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 935:
#line 6699 "parser.y"
    {
	if (current_program->flag_console_is_crt) {
		(yyval) = cb_null;
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 941:
#line 6721 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 942:
#line 6727 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 943:
#line 6728 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 946:
#line 6739 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BELL);
  ;}
    break;

  case 947:
#line 6743 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_LINE);
  ;}
    break;

  case 948:
#line 6747 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLANK_SCREEN);
  ;}
    break;

  case 949:
#line 6751 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_BLINK);
  ;}
    break;

  case 950:
#line 6755 "parser.y"
    {
	cb_warning (_("Ignoring CONVERSION"));
  ;}
    break;

  case 951:
#line 6759 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOL);
  ;}
    break;

  case 952:
#line 6763 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_ERASE_EOS);
  ;}
    break;

  case 953:
#line 6767 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 954:
#line 6771 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 955:
#line 6775 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_OVERLINE);
  ;}
    break;

  case 956:
#line 6779 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_REVERSE);
  ;}
    break;

  case 957:
#line 6783 "parser.y"
    {
	check_attribs (NULL, NULL, NULL, NULL, NULL, COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 958:
#line 6787 "parser.y"
    {
	check_attribs ((yyvsp[(3) - (3)]), NULL, NULL, NULL, NULL, 0);
  ;}
    break;

  case 959:
#line 6791 "parser.y"
    {
	check_attribs (NULL, (yyvsp[(3) - (3)]), NULL, NULL, NULL, 0);
  ;}
    break;

  case 960:
#line 6795 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, 0);
  ;}
    break;

  case 961:
#line 6799 "parser.y"
    {
	check_attribs (NULL, NULL, (yyvsp[(3) - (3)]), NULL, NULL, COB_SCREEN_SCROLL_DOWN);
  ;}
    break;

  case 962:
#line 6806 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DISPLAY);
  ;}
    break;

  case 963:
#line 6810 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DISPLAY);
  ;}
    break;

  case 964:
#line 6820 "parser.y"
    {
	begin_statement ("DIVIDE", TERM_DIVIDE);
  ;}
    break;

  case 966:
#line 6829 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '/', (yyvsp[(1) - (4)]));
  ;}
    break;

  case 967:
#line 6833 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(3) - (6)]), '/', (yyvsp[(1) - (6)])));
  ;}
    break;

  case 968:
#line 6837 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '/', (yyvsp[(3) - (6)])));
  ;}
    break;

  case 969:
#line 6841 "parser.y"
    {
	cb_emit_divide ((yyvsp[(3) - (8)]), (yyvsp[(1) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  ;}
    break;

  case 970:
#line 6845 "parser.y"
    {
	cb_emit_divide ((yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
  ;}
    break;

  case 971:
#line 6852 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), DIVIDE);
  ;}
    break;

  case 972:
#line 6856 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), DIVIDE);
  ;}
    break;

  case 973:
#line 6866 "parser.y"
    {
	begin_statement ("ENTRY", 0);
  ;}
    break;

  case 975:
#line 6874 "parser.y"
    {
	if (current_program->nested_level) {
		cb_error (_("ENTRY is invalid in nested program"));
	} else if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("ENTRY is invalid in a user FUNCTION"));
	} else if (cb_verify (cb_entry_statement, "ENTRY")) {
		if (!cobc_check_valid_name ((char *)(CB_LITERAL ((yyvsp[(1) - (2)]))->data), 1U)) {
			emit_entry ((char *)(CB_LITERAL ((yyvsp[(1) - (2)]))->data), 1, (yyvsp[(2) - (2)]));
		}
	}
	check_unreached = 0;
  ;}
    break;

  case 976:
#line 6893 "parser.y"
    {
	begin_statement ("EVALUATE", TERM_EVALUATE);
	eval_level++;
	if (eval_level >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_level = 0;
		eval_inc = 0;
		eval_inc2 = 0;
		YYERROR;
	} else {
		for (eval_inc = 0; eval_inc < EVAL_DEPTH; ++eval_inc) {
			eval_check[eval_level][eval_inc] = NULL;
		}
		eval_inc = 0;
		eval_inc2 = 0;
	}
  ;}
    break;

  case 978:
#line 6917 "parser.y"
    {
	cb_emit_evaluate ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	eval_level--;
  ;}
    break;

  case 979:
#line 6924 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 980:
#line 6926 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 981:
#line 6931 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	eval_check[eval_level][eval_inc++] = (yyvsp[(1) - (1)]);
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  ;}
    break;

  case 982:
#line 6942 "parser.y"
    {
	(yyval) = cb_true;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  ;}
    break;

  case 983:
#line 6953 "parser.y"
    {
	(yyval) = cb_false;
	eval_check[eval_level][eval_inc++] = NULL;
	if (eval_inc >= EVAL_DEPTH) {
		cb_error (_("Maximum evaluate depth exceeded (%d)"),
			  EVAL_DEPTH);
		eval_inc = 0;
		YYERROR;
	}
  ;}
    break;

  case 984:
#line 6967 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 985:
#line 6971 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 986:
#line 6977 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 987:
#line 6979 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 988:
#line 6985 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	eval_inc2 = 0;
  ;}
    break;

  case 989:
#line 6994 "parser.y"
    {
	(yyval) = CB_BUILD_CHAIN ((yyvsp[(3) - (3)]), NULL);
	eval_inc2 = 0;
  ;}
    break;

  case 990:
#line 7002 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)]));
	eval_inc2 = 0;
  ;}
    break;

  case 991:
#line 7008 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
	eval_inc2 = 0;
  ;}
    break;

  case 992:
#line 7015 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 993:
#line 7017 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 994:
#line 7022 "parser.y"
    {
	cb_tree	not;
	cb_tree	e1;
	cb_tree	e2;
	cb_tree	x;
	cb_tree	parm1;

	not = cb_int0;
	e2 = (yyvsp[(2) - (2)]);
	x = NULL;
	parm1 = (yyvsp[(1) - (2)]);
	if (eval_check[eval_level][eval_inc2]) {
		/* Check if the first token is NOT */
		/* It may belong to the EVALUATE, however see */
		/* below when it may be part of a partial expression */
		if (CB_PURPOSE_INT (parm1) == '!') {
			/* Pop stack if subject not TRUE / FALSE */
			not = cb_int1;
			x = parm1;
			parm1 = CB_CHAIN (parm1);
		}
		/* Partial expression handling */
		switch (CB_PURPOSE_INT (parm1)) {
		/* Relational conditions */
		case '<':
		case '>':
		case '[':
		case ']':
		case '~':
		case '=':
		/* Class conditions */
		case '9':
		case 'A':
		case 'L':
		case 'U':
		case 'P':
		case 'N':
		case 'O':
		case 'C':
			if (e2) {
				cb_error_x (e2, _("Invalid THROUGH usage"));
				e2 = NULL;
			}
			not = CB_PURPOSE (parm1);
			if (x) {
				/* Rebind the NOT to the partial expression */
				parm1 = cb_build_list (cb_int ('!'), NULL, parm1);
			}
			/* Insert subject at head of list */
			parm1 = cb_build_list (cb_int ('x'),
					    eval_check[eval_level][eval_inc2], parm1);
			break;
		}
	}

	/* Build expr now */
	e1 = cb_build_expr (parm1);

	eval_inc2++;
	(yyval) = CB_BUILD_PAIR (not, CB_BUILD_PAIR (e1, e2));
  ;}
    break;

  case 995:
#line 7083 "parser.y"
    { (yyval) = cb_any; eval_inc2++; ;}
    break;

  case 996:
#line 7084 "parser.y"
    { (yyval) = cb_true; eval_inc2++; ;}
    break;

  case 997:
#line 7085 "parser.y"
    { (yyval) = cb_false; eval_inc2++; ;}
    break;

  case 998:
#line 7089 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 999:
#line 7090 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1000:
#line 7095 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), EVALUATE);
  ;}
    break;

  case 1001:
#line 7099 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), EVALUATE);
  ;}
    break;

  case 1002:
#line 7109 "parser.y"
    {
	begin_statement ("EXIT", 0);
	cobc_cs_check = CB_CS_EXIT;
  ;}
    break;

  case 1003:
#line 7114 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 1005:
#line 7122 "parser.y"
    {
	if (in_declaratives && use_global_ind) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PROGRAM is not allowed within a USE GLOBAL procedure"));
	}
	if (current_program->prog_type != CB_PROGRAM_TYPE) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PROGRAM only allowed within a PROGRAM type"));
	}
	if (current_program->flag_main) {
		check_unreached = 0;
	} else {
		check_unreached = 1;
	}
	current_statement->name = (const char *)"EXIT PROGRAM";
	cb_emit_exit (0);
  ;}
    break;

  case 1006:
#line 7140 "parser.y"
    {
	if (in_declaratives && use_global_ind) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT FUNCTION is not allowed within a USE GLOBAL procedure"));
	}
	if (current_program->prog_type != CB_FUNCTION_TYPE) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT FUNCTION only allowed within a FUNCTION type"));
	}
	check_unreached = 1;
	current_statement->name = (const char *)"EXIT FUNCTION";
	cb_emit_exit (0);
  ;}
    break;

  case 1007:
#line 7154 "parser.y"
    {
	struct cb_perform	*p;
	cb_tree			plabel;
	char			name[64];

	if (!perform_stack) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PERFORM is only valid with inline PERFORM"));
	} else if (CB_VALUE (perform_stack) != cb_error_node) {
		p = CB_PERFORM (CB_VALUE (perform_stack));
		if (!p->cycle_label) {
			sprintf (name, "EXIT PERFORM CYCLE %d", cb_id);
			p->cycle_label = cb_build_reference (name);
			plabel = cb_build_label (p->cycle_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PERFORM CYCLE";
		cb_emit_goto (CB_LIST_INIT (p->cycle_label), NULL);
	}
  ;}
    break;

  case 1008:
#line 7176 "parser.y"
    {
	struct cb_perform	*p;
	cb_tree			plabel;
	char			name[64];

	if (!perform_stack) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PERFORM is only valid with inline PERFORM"));
	} else if (CB_VALUE (perform_stack) != cb_error_node) {
		p = CB_PERFORM (CB_VALUE (perform_stack));
		if (!p->exit_label) {
			sprintf (name, "EXIT PERFORM %d", cb_id);
			p->exit_label = cb_build_reference (name);
			plabel = cb_build_label (p->exit_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PERFORM";
		cb_emit_goto (CB_LIST_INIT (p->exit_label), NULL);
	}
  ;}
    break;

  case 1009:
#line 7198 "parser.y"
    {
	cb_tree	plabel;
	char	name[64];

	if (!current_section) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT SECTION is only valid with an active SECTION"));
	} else {
		if (!current_section->exit_label) {
			sprintf (name, "EXIT SECTION %d", cb_id);
			current_section->exit_label = cb_build_reference (name);
			plabel = cb_build_label (current_section->exit_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT SECTION";
		cb_emit_goto (CB_LIST_INIT (current_section->exit_label), NULL);
	}
  ;}
    break;

  case 1010:
#line 7218 "parser.y"
    {
	cb_tree	plabel;
	char	name[64];

	if (!current_paragraph) {
		cb_error_x (CB_TREE (current_statement),
			    _("EXIT PARAGRAPH is only valid with an active PARAGRAPH"));
	} else {
		if (!current_paragraph->exit_label) {
			sprintf (name, "EXIT PARAGRAPH %d", cb_id);
			current_paragraph->exit_label = cb_build_reference (name);
			plabel = cb_build_label (current_paragraph->exit_label, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
		}
		current_statement->name = (const char *)"EXIT PARAGRAPH";
		cb_emit_goto (CB_LIST_INIT (current_paragraph->exit_label), NULL);
	}
  ;}
    break;

  case 1011:
#line 7243 "parser.y"
    {
	begin_statement ("FREE", 0);
  ;}
    break;

  case 1013:
#line 7251 "parser.y"
    {
	cb_emit_free ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1014:
#line 7261 "parser.y"
    {
	begin_statement ("GENERATE", 0);
  ;}
    break;

  case 1016:
#line 7270 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
		cb_emit_generate((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1017:
#line 7282 "parser.y"
    {
	if (!current_paragraph->flag_statement) {
		current_paragraph->flag_first_is_goto = 1;
	}
	begin_statement ("GO TO", 0);
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1019:
#line 7295 "parser.y"
    {
	cb_emit_goto ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
	start_debug = save_debug;
  ;}
    break;

  case 1020:
#line 7303 "parser.y"
    {
	check_unreached = 1;
	(yyval) = NULL;
  ;}
    break;

  case 1021:
#line 7308 "parser.y"
    {
	check_unreached = 0;
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1022:
#line 7319 "parser.y"
    {
	begin_statement ("GOBACK", 0);
	check_unreached = 1;
	cb_emit_exit (1U);
  ;}
    break;

  case 1023:
#line 7331 "parser.y"
    {
	begin_statement ("IF", TERM_IF);
  ;}
    break;

  case 1025:
#line 7340 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1026:
#line 7344 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (2)]), NULL, (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1027:
#line 7348 "parser.y"
    {
	cb_emit_if ((yyvsp[(-1) - (1)]), (yyvsp[(1) - (1)]), NULL);
  ;}
    break;

  case 1028:
#line 7355 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), IF);
  ;}
    break;

  case 1029:
#line 7359 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), IF);
  ;}
    break;

  case 1030:
#line 7369 "parser.y"
    {
	begin_statement ("INITIALIZE", 0);
  ;}
    break;

  case 1032:
#line 7378 "parser.y"
    {
	cb_emit_initialize ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  ;}
    break;

  case 1033:
#line 7384 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1034:
#line 7385 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1035:
#line 7389 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1036:
#line 7390 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1037:
#line 7391 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 1038:
#line 7396 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1039:
#line 7400 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1040:
#line 7407 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1041:
#line 7412 "parser.y"
    {
	(yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1042:
#line 7419 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1043:
#line 7425 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHABETIC); ;}
    break;

  case 1044:
#line 7426 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC); ;}
    break;

  case 1045:
#line 7427 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC); ;}
    break;

  case 1046:
#line 7428 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_ALPHANUMERIC_EDITED); ;}
    break;

  case 1047:
#line 7429 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NUMERIC_EDITED); ;}
    break;

  case 1048:
#line 7430 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL); ;}
    break;

  case 1049:
#line 7431 "parser.y"
    { (yyval) = cb_int (CB_CATEGORY_NATIONAL_EDITED); ;}
    break;

  case 1050:
#line 7436 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1051:
#line 7440 "parser.y"
    {
	(yyval) = cb_true;
  ;}
    break;

  case 1052:
#line 7449 "parser.y"
    {
	begin_statement ("INITIATE", 0);
  ;}
    break;

  case 1054:
#line 7457 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	    cb_emit_initiate((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1055:
#line 7464 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	    cb_emit_initiate((yyvsp[(2) - (2)]));
	}
  ;}
    break;

  case 1056:
#line 7476 "parser.y"
    {
	begin_statement ("INSPECT", 0);
	inspect_keyword = 0;
  ;}
    break;

  case 1059:
#line 7489 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1060:
#line 7493 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1061:
#line 7497 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1066:
#line 7513 "parser.y"
    {
	cb_init_tallying ();
  ;}
    break;

  case 1067:
#line 7517 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (3)]), (yyvsp[(3) - (3)]), cb_int0, 0);
	(yyval) = (yyvsp[(0) - (3)]);
  ;}
    break;

  case 1068:
#line 7527 "parser.y"
    {
	cb_emit_inspect ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]), cb_int1, 1);
	inspect_keyword = 0;
  ;}
    break;

  case 1069:
#line 7537 "parser.y"
    {
	cb_tree		x;
	x = cb_build_converting ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
	cb_emit_inspect ((yyvsp[(0) - (5)]), x, cb_int0, 2);
  ;}
    break;

  case 1070:
#line 7545 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1071:
#line 7546 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1072:
#line 7550 "parser.y"
    { (yyval) = cb_build_tallying_data ((yyvsp[(1) - (2)])); ;}
    break;

  case 1073:
#line 7551 "parser.y"
    { (yyval) = cb_build_tallying_characters ((yyvsp[(2) - (2)])); ;}
    break;

  case 1074:
#line 7552 "parser.y"
    { (yyval) = cb_build_tallying_all (); ;}
    break;

  case 1075:
#line 7553 "parser.y"
    { (yyval) = cb_build_tallying_leading (); ;}
    break;

  case 1076:
#line 7554 "parser.y"
    { (yyval) = cb_build_tallying_trailing (); ;}
    break;

  case 1077:
#line 7555 "parser.y"
    { (yyval) = cb_build_tallying_value ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1078:
#line 7559 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1079:
#line 7560 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1080:
#line 7565 "parser.y"
    {
	(yyval) = cb_build_replacing_characters ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
	inspect_keyword = 0;
  ;}
    break;

  case 1081:
#line 7570 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1082:
#line 7576 "parser.y"
    { /* Nothing */ ;}
    break;

  case 1083:
#line 7577 "parser.y"
    { inspect_keyword = 1; ;}
    break;

  case 1084:
#line 7578 "parser.y"
    { inspect_keyword = 2; ;}
    break;

  case 1085:
#line 7579 "parser.y"
    { inspect_keyword = 3; ;}
    break;

  case 1086:
#line 7580 "parser.y"
    { inspect_keyword = 4; ;}
    break;

  case 1087:
#line 7585 "parser.y"
    {
	switch (inspect_keyword) {
		case 1:
			(yyval) = cb_build_replacing_all ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 2:
			(yyval) = cb_build_replacing_leading ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 3:
			(yyval) = cb_build_replacing_first ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		case 4:
			(yyval) = cb_build_replacing_trailing ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
		default:
			cb_error_x (CB_TREE (current_statement),
				    _("INSPECT missing a keyword"));
			(yyval) = cb_build_replacing_all ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
			break;
	}
  ;}
    break;

  case 1088:
#line 7612 "parser.y"
    {
	(yyval) = cb_build_inspect_region_start ();
  ;}
    break;

  case 1089:
#line 7616 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1090:
#line 7623 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_before", (yyvsp[(3) - (3)])));
  ;}
    break;

  case 1091:
#line 7627 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(0) - (3)]), CB_BUILD_FUNCALL_1 ("cob_inspect_after", (yyvsp[(3) - (3)])));
  ;}
    break;

  case 1092:
#line 7636 "parser.y"
    {
	begin_statement ("MERGE", 0);
	current_statement->flag_merge = 1;
  ;}
    break;

  case 1094:
#line 7648 "parser.y"
    {
	begin_statement ("MOVE", 0);
  ;}
    break;

  case 1096:
#line 7656 "parser.y"
    {
	cb_emit_move ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1097:
#line 7660 "parser.y"
    {
	cb_emit_move_corresponding ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1098:
#line 7670 "parser.y"
    {
	begin_statement ("MULTIPLY", TERM_MULTIPLY);
  ;}
    break;

  case 1100:
#line 7679 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '*', (yyvsp[(1) - (4)]));
  ;}
    break;

  case 1101:
#line 7683 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_op ((yyvsp[(1) - (6)]), '*', (yyvsp[(3) - (6)])));
  ;}
    break;

  case 1102:
#line 7690 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), MULTIPLY);
  ;}
    break;

  case 1103:
#line 7694 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), MULTIPLY);
  ;}
    break;

  case 1104:
#line 7704 "parser.y"
    {
	begin_statement ("OPEN", 0);
  ;}
    break;

  case 1106:
#line 7712 "parser.y"
    {
	cb_tree l;
	cb_tree x;

	if ((yyvsp[(2) - (4)]) && (yyvsp[(4) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	if ((yyvsp[(4) - (4)])) {
		x = (yyvsp[(4) - (4)]);
	} else {
		x = (yyvsp[(2) - (4)]);
	}
	for (l = (yyvsp[(3) - (4)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), (yyvsp[(1) - (4)]), x);
		}
	}
  ;}
    break;

  case 1107:
#line 7733 "parser.y"
    {
	cb_tree l;
	cb_tree x;

	if ((yyvsp[(3) - (5)]) && (yyvsp[(5) - (5)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SHARING and LOCK clauses are mutually exclusive"));
	}
	if ((yyvsp[(5) - (5)])) {
		x = (yyvsp[(5) - (5)]);
	} else {
		x = (yyvsp[(3) - (5)]);
	}
	for (l = (yyvsp[(4) - (5)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			begin_implicit_statement ();
			cb_emit_open (CB_VALUE (l), (yyvsp[(2) - (5)]), x);
		}
	}
  ;}
    break;

  case 1108:
#line 7756 "parser.y"
    { (yyval) = cb_int (COB_OPEN_INPUT); ;}
    break;

  case 1109:
#line 7757 "parser.y"
    { (yyval) = cb_int (COB_OPEN_OUTPUT); ;}
    break;

  case 1110:
#line 7758 "parser.y"
    { (yyval) = cb_int (COB_OPEN_I_O); ;}
    break;

  case 1111:
#line 7759 "parser.y"
    { (yyval) = cb_int (COB_OPEN_EXTEND); ;}
    break;

  case 1112:
#line 7763 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1113:
#line 7764 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1114:
#line 7768 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1115:
#line 7769 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1116:
#line 7770 "parser.y"
    { (yyval) = cb_int (COB_LOCK_OPEN_EXCLUSIVE); ;}
    break;

  case 1117:
#line 7772 "parser.y"
    {
	(void)cb_verify (CB_OBSOLETE, "REVERSED");
	(yyval) = NULL;
  ;}
    break;

  case 1118:
#line 7783 "parser.y"
    {
	begin_statement ("PERFORM", TERM_PERFORM);
	/* Turn off field debug - PERFORM is special */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1120:
#line 7794 "parser.y"
    {
	cb_emit_perform ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
	start_debug = save_debug;
  ;}
    break;

  case 1121:
#line 7799 "parser.y"
    {
	CB_ADD_TO_CHAIN ((yyvsp[(1) - (1)]), perform_stack);
	/* Restore field debug before inline statements */
	start_debug = save_debug;
  ;}
    break;

  case 1122:
#line 7805 "parser.y"
    {
	perform_stack = CB_CHAIN (perform_stack);
	cb_emit_perform ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1123:
#line 7810 "parser.y"
    {
	cb_emit_perform ((yyvsp[(1) - (2)]), NULL);
	start_debug = save_debug;
  ;}
    break;

  case 1124:
#line 7818 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-4) - (0)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-4) - (0)]), PERFORM);
	}
  ;}
    break;

  case 1125:
#line 7826 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-4) - (1)]), PERFORM);
  ;}
    break;

  case 1126:
#line 7833 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), PERFORM);
  ;}
    break;

  case 1127:
#line 7837 "parser.y"
    {
	if (cb_relaxed_syntax_check) {
		TERMINATOR_WARNING ((yyvsp[(-2) - (1)]), PERFORM);
	} else {
		TERMINATOR_ERROR ((yyvsp[(-2) - (1)]), PERFORM);
	}
	/* Put the dot token back into the stack for reparse */
	cb_unput_dot ();
  ;}
    break;

  case 1128:
#line 7850 "parser.y"
    {
	/* Return from $1 */
	CB_REFERENCE ((yyvsp[(1) - (1)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (1)]), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 1129:
#line 7857 "parser.y"
    {
	/* Return from $3 */
	CB_REFERENCE ((yyvsp[(3) - (3)]))->length = cb_true;
	CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_decl_ok = 1;
	CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_decl_ok = 1;
	(yyval) = CB_BUILD_PAIR ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1130:
#line 7868 "parser.y"
    {
	(yyval) = cb_build_perform_once (NULL);
  ;}
    break;

  case 1131:
#line 7872 "parser.y"
    {
	(yyval) = cb_build_perform_times ((yyvsp[(1) - (2)]));
	current_program->loop_counter++;
  ;}
    break;

  case 1132:
#line 7877 "parser.y"
    {
	(yyval) = cb_build_perform_forever (NULL);
  ;}
    break;

  case 1133:
#line 7881 "parser.y"
    {
	cb_tree varying;

	if (!(yyvsp[(3) - (3)])) {
		(yyval) = cb_build_perform_forever (NULL);
	} else {
		varying = CB_LIST_INIT (cb_build_perform_varying (NULL, NULL, NULL, (yyvsp[(3) - (3)])));
		(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), varying);
	}
  ;}
    break;

  case 1134:
#line 7892 "parser.y"
    {
	(yyval) = cb_build_perform_until ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1135:
#line 7898 "parser.y"
    { (yyval) = CB_BEFORE; ;}
    break;

  case 1136:
#line 7899 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1137:
#line 7903 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1138:
#line 7904 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1139:
#line 7907 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1140:
#line 7909 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 1141:
#line 7914 "parser.y"
    {
	(yyval) = cb_build_perform_varying ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
  ;}
    break;

  case 1142:
#line 7924 "parser.y"
    {
	begin_statement ("READ", TERM_READ);
  ;}
    break;

  case 1144:
#line 7933 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		struct cb_file	*cf;

		cf = CB_FILE(cb_ref ((yyvsp[(1) - (7)])));
		if ((yyvsp[(5) - (7)]) && (cf->lock_mode & COB_LOCK_AUTOMATIC)) {
			cb_error_x (CB_TREE (current_statement),
				    _("LOCK clause invalid with file LOCK AUTOMATIC"));
		} else if ((yyvsp[(6) - (7)]) &&
		      (cf->organization != COB_ORG_RELATIVE &&
		       cf->organization != COB_ORG_INDEXED)) {
			cb_error_x (CB_TREE (current_statement),
				    _("KEY clause invalid with this file type"));
		} else if (current_statement->handler_id == COB_EC_I_O_INVALID_KEY &&
			   (cf->organization != COB_ORG_RELATIVE &&
			    cf->organization != COB_ORG_INDEXED)) {
			cb_error_x (CB_TREE (current_statement),
				    _("INVALID KEY clause invalid with this file type"));
		} else {
			cb_emit_read ((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(5) - (7)]));
		}
	}
  ;}
    break;

  case 1145:
#line 7959 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1146:
#line 7960 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1147:
#line 7965 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1148:
#line 7969 "parser.y"
    {
	(yyval) = cb_int3;
  ;}
    break;

  case 1149:
#line 7973 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1150:
#line 7977 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1151:
#line 7981 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 1152:
#line 7985 "parser.y"
    {
	(yyval) = cb_int3;
  ;}
    break;

  case 1153:
#line 7989 "parser.y"
    {
	(yyval) = cb_int4;
  ;}
    break;

  case 1154:
#line 7995 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1155:
#line 7996 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1158:
#line 8006 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), READ);
  ;}
    break;

  case 1159:
#line 8010 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), READ);
  ;}
    break;

  case 1160:
#line 8020 "parser.y"
    {
	begin_statement ("READY TRACE", 0);
	cb_emit_ready_trace ();
  ;}
    break;

  case 1161:
#line 8030 "parser.y"
    {
	begin_statement ("RELEASE", 0);
  ;}
    break;

  case 1163:
#line 8038 "parser.y"
    {
	cb_emit_release ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1164:
#line 8048 "parser.y"
    {
	begin_statement ("RESET TRACE", 0);
	cb_emit_reset_trace ();
  ;}
    break;

  case 1165:
#line 8058 "parser.y"
    {
	begin_statement ("RETURN", TERM_RETURN);
  ;}
    break;

  case 1167:
#line 8067 "parser.y"
    {
	cb_emit_return ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1168:
#line 8074 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), RETURN);
  ;}
    break;

  case 1169:
#line 8078 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), RETURN);
  ;}
    break;

  case 1170:
#line 8088 "parser.y"
    {
	begin_statement ("REWRITE", TERM_REWRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1172:
#line 8100 "parser.y"
    {
	cb_emit_rewrite ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	start_debug = save_debug;
  ;}
    break;

  case 1173:
#line 8108 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1174:
#line 8112 "parser.y"
    {
	(yyval) = cb_int1;
  ;}
    break;

  case 1175:
#line 8116 "parser.y"
    {
	(yyval) = cb_int2;
  ;}
    break;

  case 1176:
#line 8123 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), REWRITE);
  ;}
    break;

  case 1177:
#line 8127 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), REWRITE);
  ;}
    break;

  case 1178:
#line 8137 "parser.y"
    {
	begin_statement ("ROLLBACK", 0);
	cb_emit_rollback ();
  ;}
    break;

  case 1179:
#line 8148 "parser.y"
    {
	begin_statement ("SEARCH", TERM_SEARCH);
  ;}
    break;

  case 1181:
#line 8157 "parser.y"
    {
	cb_emit_search ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1182:
#line 8162 "parser.y"
    {
	current_statement->name = (const char *)"SEARCH ALL";
	cb_emit_search_all ((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)]));
  ;}
    break;

  case 1183:
#line 8169 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1184:
#line 8170 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1185:
#line 8175 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1186:
#line 8180 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1187:
#line 8187 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1188:
#line 8191 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 1189:
#line 8199 "parser.y"
    {
	(yyval) = cb_build_if_check_break ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1190:
#line 8206 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SEARCH);
  ;}
    break;

  case 1191:
#line 8210 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SEARCH);
  ;}
    break;

  case 1192:
#line 8220 "parser.y"
    {
	begin_statement ("SET", 0);
	setattr_val_on = 0;
	setattr_val_off = 0;
	cobc_cs_check = CB_CS_SET;
  ;}
    break;

  case 1193:
#line 8227 "parser.y"
    {
	cobc_cs_check = 0;
  ;}
    break;

  case 1200:
#line 8242 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1201:
#line 8243 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1202:
#line 8247 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1203:
#line 8248 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1204:
#line 8255 "parser.y"
    {
	cb_emit_setenv ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1205:
#line 8264 "parser.y"
    {
	cb_emit_set_attribute ((yyvsp[(1) - (3)]), setattr_val_on, setattr_val_off);
  ;}
    break;

  case 1208:
#line 8276 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BELL);
  ;}
    break;

  case 1209:
#line 8280 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_BLINK);
  ;}
    break;

  case 1210:
#line 8284 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_HIGHLIGHT);
  ;}
    break;

  case 1211:
#line 8288 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LOWLIGHT);
  ;}
    break;

  case 1212:
#line 8292 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_REVERSE);
  ;}
    break;

  case 1213:
#line 8296 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_UNDERLINE);
  ;}
    break;

  case 1214:
#line 8300 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_LEFTLINE);
  ;}
    break;

  case 1215:
#line 8304 "parser.y"
    {
	bit_set_attr ((yyvsp[(2) - (2)]), COB_SCREEN_OVERLINE);
  ;}
    break;

  case 1216:
#line 8313 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (4)]), cb_build_ppointer ((yyvsp[(4) - (4)])));
  ;}
    break;

  case 1217:
#line 8317 "parser.y"
    {
	cb_emit_set_to ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1218:
#line 8326 "parser.y"
    {
	cb_emit_set_up_down ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 1221:
#line 8340 "parser.y"
    {
	cb_emit_set_on_off ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1224:
#line 8354 "parser.y"
    {
	cb_emit_set_true ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1225:
#line 8358 "parser.y"
    {
	cb_emit_set_false ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1226:
#line 8368 "parser.y"
    {
	begin_statement ("SORT", 0);
  ;}
    break;

  case 1228:
#line 8376 "parser.y"
    {
	cb_tree		x;

	x = cb_ref ((yyvsp[(1) - (4)]));
	if (CB_VALID_TREE (x)) {
		if (CB_INVALID_TREE ((yyvsp[(2) - (4)]))) {
			if (CB_FILE_P (x)) {
				cb_error (_("File sort requires KEY phrase"));
			} else {
				cb_error (_("Table sort without keys not implemented yet"));
			}
			(yyval) = NULL;
		} else {
			cb_emit_sort_init ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
			(yyval)= (yyvsp[(1) - (4)]);
		}
	} else {
		(yyval) = NULL;
	}
  ;}
    break;

  case 1229:
#line 8397 "parser.y"
    {
	if ((yyvsp[(5) - (7)]) && CB_VALID_TREE ((yyvsp[(1) - (7)]))) {
		cb_emit_sort_finish ((yyvsp[(1) - (7)]));
	}
  ;}
    break;

  case 1230:
#line 8406 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1231:
#line 8411 "parser.y"
    {
	cb_tree l;
	cb_tree lparm;

	if ((yyvsp[(5) - (5)]) == NULL) {
		l = CB_LIST_INIT (NULL);
	} else {
		l = (yyvsp[(5) - (5)]);
	}
	lparm = l;
	for (; l; l = CB_CHAIN (l)) {
		CB_PURPOSE (l) = (yyvsp[(3) - (5)]);
	}
	(yyval) = cb_list_append ((yyvsp[(1) - (5)]), lparm);
  ;}
    break;

  case 1232:
#line 8429 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1233:
#line 8430 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1235:
#line 8435 "parser.y"
    {
	/* The OC sort is a stable sort. ie. Dups are per default in order */
	/* Therefore nothing to do here */
  ;}
    break;

  case 1236:
#line 8442 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1237:
#line 8443 "parser.y"
    { (yyval) = cb_ref ((yyvsp[(3) - (3)])); ;}
    break;

  case 1238:
#line 8448 "parser.y"
    {
	if ((yyvsp[(0) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(0) - (0)])))) {
		cb_error (_("File sort requires USING or INPUT PROCEDURE"));
	}
  ;}
    break;

  case 1239:
#line 8454 "parser.y"
    {
	if ((yyvsp[(0) - (2)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(0) - (2)])))) {
			cb_error (_("USING invalid with table SORT"));
		} else {
			cb_emit_sort_using ((yyvsp[(0) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  ;}
    break;

  case 1240:
#line 8464 "parser.y"
    {
	if ((yyvsp[(0) - (4)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(0) - (4)])))) {
			cb_error (_("INPUT PROCEDURE invalid with table SORT"));
		} else if (current_statement->flag_merge) {
			cb_error (_("INPUT PROCEDURE invalid with MERGE"));
		} else {
			cb_emit_sort_input ((yyvsp[(4) - (4)]));
		}
	}
  ;}
    break;

  case 1241:
#line 8479 "parser.y"
    {
	if ((yyvsp[(-1) - (0)]) && CB_FILE_P (cb_ref ((yyvsp[(-1) - (0)])))) {
		cb_error (_("File sort requires GIVING or OUTPUT PROCEDURE"));
	}
  ;}
    break;

  case 1242:
#line 8485 "parser.y"
    {
	if ((yyvsp[(-1) - (2)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(-1) - (2)])))) {
			cb_error (_("GIVING invalid with table SORT"));
		} else {
			cb_emit_sort_giving ((yyvsp[(-1) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  ;}
    break;

  case 1243:
#line 8495 "parser.y"
    {
	if ((yyvsp[(-1) - (4)])) {
		if (!CB_FILE_P (cb_ref ((yyvsp[(-1) - (4)])))) {
			cb_error (_("OUTPUT PROCEDURE invalid with table SORT"));
		} else {
			cb_emit_sort_output ((yyvsp[(4) - (4)]));
		}
	}
  ;}
    break;

  case 1244:
#line 8511 "parser.y"
    {
	begin_statement ("START", TERM_START);
	start_tree = cb_int (COB_EQ);
  ;}
    break;

  case 1246:
#line 8521 "parser.y"
    {
	if ((yyvsp[(3) - (4)]) && !(yyvsp[(2) - (4)])) {
		cb_error_x (CB_TREE (current_statement),
			    _("SIZE/LENGTH invalid here"));
	} else {
		cb_emit_start ((yyvsp[(1) - (4)]), start_tree, (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
	}
  ;}
    break;

  case 1247:
#line 8533 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1248:
#line 8537 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1249:
#line 8544 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1250:
#line 8548 "parser.y"
    {
	start_tree = (yyvsp[(3) - (4)]);
	(yyval) = (yyvsp[(4) - (4)]);
  ;}
    break;

  case 1251:
#line 8553 "parser.y"
    {
	start_tree = cb_int (COB_FI);
	(yyval) = NULL;
  ;}
    break;

  case 1252:
#line 8558 "parser.y"
    {
	start_tree = cb_int (COB_LA);
	(yyval) = NULL;
  ;}
    break;

  case 1253:
#line 8565 "parser.y"
    { (yyval) = cb_int (COB_EQ); ;}
    break;

  case 1254:
#line 8566 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LE : COB_GT); ;}
    break;

  case 1255:
#line 8567 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GE : COB_LT); ;}
    break;

  case 1256:
#line 8568 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_LT : COB_GE); ;}
    break;

  case 1257:
#line 8569 "parser.y"
    { (yyval) = cb_int ((yyvsp[(1) - (2)]) ? COB_GT : COB_LE); ;}
    break;

  case 1258:
#line 8570 "parser.y"
    { (yyval) = cb_int (COB_NE); ;}
    break;

  case 1259:
#line 8575 "parser.y"
    {
	cb_error_x (CB_TREE (current_statement),
		    _("NOT EQUAL condition disallowed on START statement"));
  ;}
    break;

  case 1262:
#line 8588 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), START);
  ;}
    break;

  case 1263:
#line 8592 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), START);
  ;}
    break;

  case 1264:
#line 8602 "parser.y"
    {
	begin_statement ("STOP RUN", 0);
  ;}
    break;

  case 1265:
#line 8606 "parser.y"
    {
	cb_emit_stop_run ((yyvsp[(4) - (4)]));
	check_unreached = 1;
	cobc_cs_check = 0;
  ;}
    break;

  case 1266:
#line 8612 "parser.y"
    {
	begin_statement ("STOP", 0);
	cb_verify (cb_stop_literal_statement, "STOP literal");
	cb_emit_display (CB_LIST_INIT ((yyvsp[(2) - (2)])), cb_int0, cb_int1, NULL,
			 NULL);
	cb_emit_accept (NULL, NULL, NULL);
	cobc_cs_check = 0;
  ;}
    break;

  case 1267:
#line 8624 "parser.y"
    {
	(yyval) = current_program->cb_return_code;
  ;}
    break;

  case 1268:
#line 8628 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1269:
#line 8632 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1270:
#line 8636 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int1;
	}
  ;}
    break;

  case 1271:
#line 8644 "parser.y"
    {
	if ((yyvsp[(4) - (4)])) {
		(yyval) = (yyvsp[(4) - (4)]);
	} else {
		(yyval) = cb_int0;
	}
  ;}
    break;

  case 1272:
#line 8655 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1273:
#line 8659 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1274:
#line 8665 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1275:
#line 8666 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1276:
#line 8667 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1277:
#line 8668 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1278:
#line 8675 "parser.y"
    {
	begin_statement ("STRING", TERM_STRING);
  ;}
    break;

  case 1280:
#line 8684 "parser.y"
    {
	cb_emit_string ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
  ;}
    break;

  case 1281:
#line 8690 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1282:
#line 8691 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1283:
#line 8695 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1284:
#line 8696 "parser.y"
    { (yyval) = CB_BUILD_PAIR (cb_int0, NULL); ;}
    break;

  case 1285:
#line 8697 "parser.y"
    { (yyval) = CB_BUILD_PAIR ((yyvsp[(3) - (3)]), NULL); ;}
    break;

  case 1286:
#line 8701 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1287:
#line 8702 "parser.y"
    { (yyval) = (yyvsp[(4) - (4)]); ;}
    break;

  case 1288:
#line 8707 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), STRING);
  ;}
    break;

  case 1289:
#line 8711 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), STRING);
  ;}
    break;

  case 1290:
#line 8721 "parser.y"
    {
	begin_statement ("SUBTRACT", TERM_SUBTRACT);
  ;}
    break;

  case 1292:
#line 8730 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(3) - (4)]), '-', cb_build_binary_list ((yyvsp[(1) - (4)]), '+'));
  ;}
    break;

  case 1293:
#line 8734 "parser.y"
    {
	cb_emit_arithmetic ((yyvsp[(5) - (6)]), 0, cb_build_binary_list (CB_BUILD_CHAIN ((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)])), '-'));
  ;}
    break;

  case 1294:
#line 8738 "parser.y"
    {
	cb_emit_corresponding (cb_build_sub, (yyvsp[(4) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 1295:
#line 8745 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), SUBTRACT);
  ;}
    break;

  case 1296:
#line 8749 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), SUBTRACT);
  ;}
    break;

  case 1297:
#line 8759 "parser.y"
    {
	begin_statement ("SUPPRESS", 0);
	if (!in_declaratives) {
		cb_error_x (CB_TREE (current_statement),
			    _("SUPPRESS statement must be within DECLARATIVES"));
	}
	cb_emit_suppress(control_field);
  ;}
    break;

  case 1300:
#line 8777 "parser.y"
    {
	begin_statement ("TERMINATE", 0);
  ;}
    break;

  case 1302:
#line 8785 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(1) - (1)]) != cb_error_node) {
	    cb_emit_terminate((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1303:
#line 8792 "parser.y"
    {
	begin_implicit_statement ();
	if ((yyvsp[(2) - (2)]) != cb_error_node) {
	    cb_emit_terminate((yyvsp[(2) - (2)]));
	}
  ;}
    break;

  case 1304:
#line 8804 "parser.y"
    {
	begin_statement ("TRANSFORM", 0);
  ;}
    break;

  case 1306:
#line 8812 "parser.y"
    {
	cb_tree		x;

	x = cb_build_converting ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), cb_build_inspect_region_start ());
	cb_emit_inspect ((yyvsp[(1) - (5)]), x, cb_int0, 2);
  ;}
    break;

  case 1307:
#line 8825 "parser.y"
    {
	begin_statement ("UNLOCK", 0);
  ;}
    break;

  case 1309:
#line 8833 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (2)]))) {
		if (CB_FILE (cb_ref ((yyvsp[(1) - (2)])))->organization == COB_ORG_SORT) {
			cb_error_x (CB_TREE (current_statement),
				    _("UNLOCK invalid for SORT files"));
		} else {
			cb_emit_unlock ((yyvsp[(1) - (2)]));
		}
	}
  ;}
    break;

  case 1313:
#line 8856 "parser.y"
    {
	begin_statement ("UNSTRING", TERM_UNSTRING);
  ;}
    break;

  case 1315:
#line 8866 "parser.y"
    {
	cb_emit_unstring ((yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]));
  ;}
    break;

  case 1316:
#line 8872 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1317:
#line 8874 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1318:
#line 8878 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1319:
#line 8880 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 1320:
#line 8885 "parser.y"
    {
	(yyval) = cb_build_unstring_delimited ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1321:
#line 8891 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(2) - (2)])); ;}
    break;

  case 1322:
#line 8893 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1323:
#line 8898 "parser.y"
    {
	(yyval) = cb_build_unstring_into ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1324:
#line 8904 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1325:
#line 8905 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1326:
#line 8909 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1327:
#line 8910 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1328:
#line 8914 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1329:
#line 8915 "parser.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 1330:
#line 8920 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), UNSTRING);
  ;}
    break;

  case 1331:
#line 8924 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), UNSTRING);
  ;}
    break;

  case 1332:
#line 8934 "parser.y"
    {
	skip_statements = 0;
	in_debugging = 0;
  ;}
    break;

  case 1338:
#line 8951 "parser.y"
    {
	if (!in_declaratives) {
		cb_error (_("USE statement must be within DECLARATIVES"));
	} else if (!current_section) {
		cb_error (_("SECTION header missing before USE statement"));
	} else {
		current_section->flag_begin = 1;
		current_section->flag_return = 1;
		current_section->flag_declarative_exit = 1;
		current_section->flag_real_label = 1;
		current_section->flag_skip_label = 0;
		CB_EXCEPTION_ENABLE (COB_EC_I_O) = 1;
		if (use_global_ind) {
			current_section->flag_global = 1;
			current_program->global_list =
				cb_list_add (current_program->global_list,
					     CB_TREE (current_section));
		}
		emit_statement (cb_build_comment ("USE AFTER ERROR"));
	}
  ;}
    break;

  case 1339:
#line 8976 "parser.y"
    {
	use_global_ind = 0;
  ;}
    break;

  case 1340:
#line 8980 "parser.y"
    {
	if (current_program->prog_type == CB_FUNCTION_TYPE) {
		cb_error (_("GLOBAL is invalid in a user FUNCTION"));
	} else {
		use_global_ind = 1;
		current_program->flag_global_use = 1;
	}
  ;}
    break;

  case 1341:
#line 8992 "parser.y"
    {
	cb_tree		l;

	for (l = (yyvsp[(1) - (1)]); l; l = CB_CHAIN (l)) {
		if (CB_VALID_TREE (CB_VALUE (l))) {
			setup_use_file (CB_FILE (cb_ref (CB_VALUE (l))));
		}
	}
  ;}
    break;

  case 1342:
#line 9002 "parser.y"
    {
	current_program->global_handler[COB_OPEN_INPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_INPUT].handler_prog = current_program;
  ;}
    break;

  case 1343:
#line 9007 "parser.y"
    {
	current_program->global_handler[COB_OPEN_OUTPUT].handler_label = current_section;
	current_program->global_handler[COB_OPEN_OUTPUT].handler_prog = current_program;
  ;}
    break;

  case 1344:
#line 9012 "parser.y"
    {
	current_program->global_handler[COB_OPEN_I_O].handler_label = current_section;
	current_program->global_handler[COB_OPEN_I_O].handler_prog = current_program;
  ;}
    break;

  case 1345:
#line 9017 "parser.y"
    {
	current_program->global_handler[COB_OPEN_EXTEND].handler_label = current_section;
	current_program->global_handler[COB_OPEN_EXTEND].handler_prog = current_program;
  ;}
    break;

  case 1346:
#line 9025 "parser.y"
    {
	cb_tree		plabel;
	char		name[64];

	if (!in_declaratives) {
		cb_error (_("USE statement must be within DECLARATIVES"));
	} else if (current_program->nested_level) {
		cb_error (_("USE DEBUGGING not supported in contained program"));
	} else {
		in_debugging = 1;
		current_section->flag_begin = 1;
		current_section->flag_return = 1;
		current_section->flag_declarative_exit = 1;
		current_section->flag_real_label = 0;
		current_section->flag_is_debug_sect = 1;
		if (!needs_debug_item) {
			needs_debug_item = 1;
			cb_build_debug_item ();
		}
		if (!current_program->flag_debugging) {
			skip_statements = 1;
			current_section->flag_skip_label = 1;
		} else {
			current_program->flag_gen_debug = 1;
			sprintf (name, "EXIT SECTION %d", cb_id);
			plabel = cb_build_reference (name);
			plabel = cb_build_label (plabel, NULL);
			CB_LABEL (plabel)->flag_begin = 1;
			CB_LABEL (plabel)->flag_dummy_exit = 1;
			current_section->exit_label = plabel;
			emit_statement (cb_build_comment ("USE FOR DEBUGGING"));
		}
	}
  ;}
    break;

  case 1349:
#line 9068 "parser.y"
    {
	cb_tree		l;
	cb_tree		x;
	cb_tree		z;

	if (current_program->flag_debugging) {
		CB_REFERENCE ((yyvsp[(1) - (1)]))->debug_section = current_section;
		CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_debug_code = 1;
		CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_all_debug = 0;
		z = CB_LIST_INIT ((yyvsp[(1) - (1)]));
		current_program->debug_list =
			cb_list_append (current_program->debug_list, z);
		/* Check backward refs to file/data names */
		/* Label refs will be checked later (forward/backward ref) */
		if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
			l = CB_VALUE(CB_WORD_ITEMS ((yyvsp[(1) - (1)])));
			switch (CB_TREE_TAG (l)) {
			case CB_TAG_FILE:
				CB_FILE (l)->debug_section = current_section;
				CB_FILE (l)->flag_fl_debug = 1;
				break;
			case CB_TAG_FIELD:
				x = cb_ref ((yyvsp[(1) - (1)]));
				if (CB_INVALID_TREE (x)) {
					break;
				}
				needs_field_debug = 1;
				CB_FIELD (x)->debug_section = current_section;
				CB_FIELD (x)->flag_field_debug = 1;
				CB_PURPOSE (z) = x;
				break;
			default:
				break;
			}
		}
	}
  ;}
    break;

  case 1350:
#line 9106 "parser.y"
    {
	if (current_program->flag_debugging) {
		if (current_program->all_procedure) {
			cb_error (_("Duplicate USE DEBUGGING ON ALL PROCEDURES"));
		} else {
			current_program->all_procedure = current_section;
		}
	}
  ;}
    break;

  case 1351:
#line 9116 "parser.y"
    {
	cb_tree		x;

	if (current_program->flag_debugging) {
		/* Reference must be a data item */
		x = cb_ref ((yyvsp[(3) - (3)]));
		if (CB_INVALID_TREE (x) || !CB_FIELD_P (x)) {
			cb_error (_("Invalid target for DEBUGGING ALL"));
		} else {
			needs_field_debug = 1;
			CB_FIELD (x)->debug_section = current_section;
			CB_FIELD (x)->flag_field_debug = 1;
			CB_FIELD (x)->flag_all_debug = 1;
			CB_REFERENCE ((yyvsp[(3) - (3)]))->debug_section = current_section;
			CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_debug_code = 1;
			CB_REFERENCE ((yyvsp[(3) - (3)]))->flag_all_debug = 1;
			CB_CHAIN_PAIR (current_program->debug_list, x, (yyvsp[(3) - (3)]));
		}
	}
  ;}
    break;

  case 1356:
#line 9146 "parser.y"
    {
	char wrk[80];
	cb_tree x;
	struct cb_field		*f;
	struct cb_report	*r;

	x = cb_ref ((yyvsp[(4) - (4)]));
	if (!CB_FIELD_P (x)) {
		cb_error_x ((yyvsp[(4) - (4)]), _("'%s' is not a report group"), CB_NAME ((yyvsp[(4) - (4)])));
		(yyval) = cb_error_node;
	} else {
		control_field = f = CB_FIELD (x);
		f->report_decl_id = current_section->id;
		if((r = f->report) != NULL) {
			r->has_declarative = 1;
		}
	}
	sprintf(wrk,"USE BEFORE REPORTING %s is l_%d",cb_name((yyvsp[(4) - (4)])),current_section->id);
	current_section->flag_real_label = 1;
	current_section->flag_declaratives = 1;
	current_section->flag_begin = 1;
	current_section->flag_return = 1;
	current_section->flag_declarative_exit = 1;
	current_section->flag_real_label = 1;
	current_section->flag_skip_label = 0;
	emit_statement (cb_build_comment (strdup(wrk)));
  ;}
    break;

  case 1357:
#line 9177 "parser.y"
    {
	current_section->flag_real_label = 1;
	emit_statement (cb_build_comment ("USE AFTER EXCEPTION CONDITION"));
	PENDING ("USE AFTER EXCEPTION CONDITION");
  ;}
    break;

  case 1360:
#line 9193 "parser.y"
    {
	begin_statement ("WRITE", TERM_WRITE);
	/* Special in debugging mode */
	save_debug = start_debug;
	start_debug = 0;
  ;}
    break;

  case 1362:
#line 9205 "parser.y"
    {
	if (CB_VALID_TREE ((yyvsp[(1) - (5)]))) {
		cb_emit_write ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
	}
	start_debug = save_debug;
  ;}
    break;

  case 1363:
#line 9214 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1364:
#line 9215 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1365:
#line 9220 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 1366:
#line 9224 "parser.y"
    {
	(yyval) = cb_build_write_advancing_lines ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
  ;}
    break;

  case 1367:
#line 9228 "parser.y"
    {
	(yyval) = cb_build_write_advancing_mnemonic ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1368:
#line 9232 "parser.y"
    {
	(yyval) = cb_build_write_advancing_page ((yyvsp[(1) - (3)]));
  ;}
    break;

  case 1369:
#line 9238 "parser.y"
    { (yyval) = CB_BEFORE; ;}
    break;

  case 1370:
#line 9239 "parser.y"
    { (yyval) = CB_AFTER; ;}
    break;

  case 1373:
#line 9249 "parser.y"
    {
	TERMINATOR_WARNING ((yyvsp[(-2) - (0)]), WRITE);
  ;}
    break;

  case 1374:
#line 9253 "parser.y"
    {
	TERMINATOR_CLEAR ((yyvsp[(-2) - (1)]), WRITE);
  ;}
    break;

  case 1377:
#line 9270 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1379:
#line 9280 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_ACCEPT;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1382:
#line 9293 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1384:
#line 9303 "parser.y"
    {
	current_statement->handler_id = COB_EC_IMP_DISPLAY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1387:
#line 9318 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1389:
#line 9328 "parser.y"
    {
	current_statement->handler_id = COB_EC_SIZE;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1392:
#line 9345 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1394:
#line 9356 "parser.y"
    {
	current_statement->handler_id = COB_EC_OVERFLOW;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1400:
#line 9379 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1401:
#line 9388 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_AT_END;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1405:
#line 9405 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1406:
#line 9414 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_EOP;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1409:
#line 9431 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler1 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1411:
#line 9441 "parser.y"
    {
	current_statement->handler_id = COB_EC_I_O_INVALID_KEY;
	current_statement->handler2 = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1412:
#line 9451 "parser.y"
    {
	(yyval) = cb_one;
  ;}
    break;

  case 1413:
#line 9455 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 1414:
#line 9465 "parser.y"
    {
	(yyval) = cb_build_cond ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1415:
#line 9472 "parser.y"
    {
	(yyval) = cb_build_expr ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1416:
#line 9478 "parser.y"
    {
	current_expr = NULL;
  ;}
    break;

  case 1417:
#line 9482 "parser.y"
    {
	(yyval) = cb_list_reverse (current_expr);
  ;}
    break;

  case 1421:
#line 9495 "parser.y"
    {
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)])) && CB_CLASS_NAME_P (cb_ref ((yyvsp[(1) - (1)])))) {
		push_expr ('C', (yyvsp[(1) - (1)]));
	} else {
		push_expr ('x', (yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1422:
#line 9503 "parser.y"
    { push_expr ('(', NULL); ;}
    break;

  case 1423:
#line 9504 "parser.y"
    { push_expr (')', NULL); ;}
    break;

  case 1424:
#line 9506 "parser.y"
    { push_expr ('+', NULL); ;}
    break;

  case 1425:
#line 9507 "parser.y"
    { push_expr ('-', NULL); ;}
    break;

  case 1426:
#line 9508 "parser.y"
    { push_expr ('*', NULL); ;}
    break;

  case 1427:
#line 9509 "parser.y"
    { push_expr ('/', NULL); ;}
    break;

  case 1428:
#line 9510 "parser.y"
    { push_expr ('^', NULL); ;}
    break;

  case 1429:
#line 9512 "parser.y"
    { push_expr ('=', NULL); ;}
    break;

  case 1430:
#line 9513 "parser.y"
    { push_expr ('>', NULL); ;}
    break;

  case 1431:
#line 9514 "parser.y"
    { push_expr ('<', NULL); ;}
    break;

  case 1432:
#line 9515 "parser.y"
    { push_expr (']', NULL); ;}
    break;

  case 1433:
#line 9516 "parser.y"
    { push_expr ('[', NULL); ;}
    break;

  case 1434:
#line 9517 "parser.y"
    { push_expr ('~', NULL); ;}
    break;

  case 1435:
#line 9519 "parser.y"
    { push_expr ('!', NULL); ;}
    break;

  case 1436:
#line 9520 "parser.y"
    { push_expr ('&', NULL); ;}
    break;

  case 1437:
#line 9521 "parser.y"
    { push_expr ('|', NULL); ;}
    break;

  case 1438:
#line 9523 "parser.y"
    { push_expr ('O', NULL); ;}
    break;

  case 1439:
#line 9524 "parser.y"
    { push_expr ('9', NULL); ;}
    break;

  case 1440:
#line 9525 "parser.y"
    { push_expr ('A', NULL); ;}
    break;

  case 1441:
#line 9526 "parser.y"
    { push_expr ('L', NULL); ;}
    break;

  case 1442:
#line 9527 "parser.y"
    { push_expr ('U', NULL); ;}
    break;

  case 1443:
#line 9530 "parser.y"
    { push_expr ('P', NULL); ;}
    break;

  case 1444:
#line 9531 "parser.y"
    { push_expr ('N', NULL); ;}
    break;

  case 1453:
#line 9561 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1454:
#line 9565 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1458:
#line 9576 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '+', (yyvsp[(3) - (3)])); ;}
    break;

  case 1459:
#line 9577 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '-', (yyvsp[(3) - (3)])); ;}
    break;

  case 1460:
#line 9578 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1461:
#line 9582 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '*', (yyvsp[(3) - (3)])); ;}
    break;

  case 1462:
#line 9583 "parser.y"
    { (yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '/', (yyvsp[(3) - (3)])); ;}
    break;

  case 1463:
#line 9584 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1464:
#line 9589 "parser.y"
    {
	(yyval) = cb_build_binary_op ((yyvsp[(1) - (3)]), '^', (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1465:
#line 9592 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1466:
#line 9596 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 1467:
#line 9597 "parser.y"
    { (yyval) = cb_build_binary_op (cb_zero, '-', (yyvsp[(2) - (2)])); ;}
    break;

  case 1468:
#line 9598 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1469:
#line 9601 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 1470:
#line 9602 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1471:
#line 9613 "parser.y"
    {
	if (current_linage > 1) {
		cb_error (_("LINAGE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if (current_linage == 0) {
		cb_error (_("Invalid LINAGE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = linage_file->linage_ctr;
	}
  ;}
    break;

  case 1472:
#line 9625 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_FILE (cb_ref ((yyvsp[(3) - (3)])))->linage_ctr;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1473:
#line 9634 "parser.y"
    {
	  if (report_count > 1
	  && current_report != NULL) {
		(yyval) = current_report->line_counter;
	  } else
	if (report_count > 1) {
		cb_error (_("LINE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if (report_count == 0) {
		cb_error (_("Invalid LINE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = report_instance->line_counter;
	}
  ;}
    break;

  case 1474:
#line 9650 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->line_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1475:
#line 9659 "parser.y"
    {
	  if (report_count > 1
	  && current_report != NULL) {
		(yyval) = current_report->page_counter;
	  } else
	if (report_count > 1) {
		cb_error (_("PAGE-COUNTER must be qualified here"));
		(yyval) = cb_error_node;
	} else if (report_count == 0) {
		cb_error (_("Invalid PAGE-COUNTER usage"));
		(yyval) = cb_error_node;
	} else {
		(yyval) = report_instance->page_counter;
	}
  ;}
    break;

  case 1476:
#line 9675 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(3) - (3)])))) {
		(yyval) = CB_REPORT (cb_ref ((yyvsp[(3) - (3)])))->page_counter;
	} else {
		cb_error_x ((yyvsp[(3) - (3)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(3) - (3)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1477:
#line 9689 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1478:
#line 9691 "parser.y"
    { (yyval) = cb_list_append ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1479:
#line 9696 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 1480:
#line 9704 "parser.y"
    { cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1481:
#line 9711 "parser.y"
    {
	cb_tree x;

	x = cb_ref ((yyvsp[(1) - (1)]));
	if (!CB_FIELD_P (x)) {
		(yyval) = cb_error_node;
	} else if (!CB_FIELD (x)->index_list) {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' not indexed"), cb_name ((yyvsp[(1) - (1)])));
		cb_error_x (x, _("'%s' defined here"), cb_name (x));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 1482:
#line 9731 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1483:
#line 9735 "parser.y"
    {
	cb_tree		l;

	if (CB_VALID_TREE ((yyvsp[(2) - (2)]))) {
		for (l = (yyvsp[(1) - (2)]); l; l = CB_CHAIN (l)) {
			if (CB_VALID_TREE (CB_VALUE (l)) &&
			    !strcasecmp (CB_NAME ((yyvsp[(2) - (2)])), CB_NAME (CB_VALUE (l)))) {
				cb_error_x ((yyvsp[(2) - (2)]), _("Multiple reference to '%s' "),
					    CB_NAME ((yyvsp[(2) - (2)])));
				break;
			}
		}
		if (!l) {
			(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
		}
	}
  ;}
    break;

  case 1484:
#line 9756 "parser.y"
    {
	if (CB_FILE_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a file name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1485:
#line 9797 "parser.y"
    {
	if (CB_REPORT_P (cb_ref ((yyvsp[(1) - (1)])))) {
		(yyval) = (yyvsp[(1) - (1)]);
	} else {
		cb_error_x ((yyvsp[(1) - (1)]), _("'%s' is not a report name"), CB_NAME ((yyvsp[(1) - (1)])));
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1486:
#line 9810 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1487:
#line 9812 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1488:
#line 9816 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1489:
#line 9822 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1490:
#line 9824 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1491:
#line 9829 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE ((yyval))->offset = CB_TREE (current_section);
	CB_REFERENCE ((yyval))->flag_in_decl = !!in_declaratives;
	CB_REFERENCE ((yyval))->section = current_section;
	CB_REFERENCE ((yyval))->paragraph = current_paragraph;
	CB_ADD_TO_CHAIN ((yyval), current_program->label_list);
  ;}
    break;

  case 1494:
#line 9843 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1495:
#line 9850 "parser.y"
    {
	(yyval) = cb_build_reference ((char *)(CB_LITERAL ((yyvsp[(1) - (1)]))->data));
	(yyval)->source_file = (yyvsp[(1) - (1)])->source_file;
	(yyval)->source_line = (yyvsp[(1) - (1)])->source_line;
  ;}
    break;

  case 1496:
#line 9860 "parser.y"
    { (yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)])); ;}
    break;

  case 1497:
#line 9861 "parser.y"
    { (yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 1498:
#line 9866 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1499:
#line 9874 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1500:
#line 9882 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1501:
#line 9886 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1502:
#line 9893 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	CB_REFERENCE((yyval))->flag_optional = 1;
	CB_ADD_TO_CHAIN ((yyval), current_program->reference_list);
  ;}
    break;

  case 1505:
#line 9909 "parser.y"
    {
	if (CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = cb_error_node;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 1506:
#line 9923 "parser.y"
    {
	if (CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_duped || CB_WORD_COUNT ((yyvsp[(1) - (1)])) > 0) {
		redefinition_error ((yyvsp[(1) - (1)]));
		(yyval) = NULL;
	} else {
		CB_WORD_COUNT ((yyvsp[(1) - (1)]))++;
		(yyval) = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 1507:
#line 9940 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1508:
#line 9944 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1511:
#line 9953 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 1512:
#line 9960 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1513:
#line 9964 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1518:
#line 9975 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1519:
#line 9979 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1520:
#line 9983 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1521:
#line 9987 "parser.y"
    {
	(yyval) = cb_build_ppointer ((yyvsp[(4) - (4)]));
  ;}
    break;

  case 1522:
#line 9991 "parser.y"
    {
	(yyval) = cb_build_address ((yyvsp[(3) - (3)]));
  ;}
    break;

  case 1523:
#line 9995 "parser.y"
    {
	cb_tree		x;
	cb_tree		switch_id;

	x = cb_ref ((yyvsp[(1) - (1)]));
	if (CB_VALID_TREE (x)) {
		if (CB_SYSTEM_NAME (x)->category != CB_SWITCH_NAME) {
			cb_error_x (x, _("Invalid mnemonic identifier"));
			(yyval) = cb_error_node;
		} else {
			switch_id = cb_int (CB_SYSTEM_NAME (x)->token);
			(yyval) = CB_BUILD_FUNCALL_1 ("cob_switch_value", switch_id);
		}
	} else {
		(yyval) = cb_error_node;
	}
  ;}
    break;

  case 1524:
#line 10016 "parser.y"
    {
	(yyval) = CB_LIST_INIT ((yyvsp[(1) - (1)]));
  ;}
    break;

  case 1525:
#line 10020 "parser.y"
    {
	(yyval) = cb_list_add ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 1533:
#line 10037 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1534:
#line 10041 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1535:
#line 10045 "parser.y"
    {
	(yyval) = cb_build_length ((yyvsp[(2) - (2)]));
  ;}
    break;

  case 1551:
#line 10092 "parser.y"
    {
	(yyval) = cb_zero;
  ;}
    break;

  case 1559:
#line 10116 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1560:
#line 10120 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 1); ;}
    break;

  case 1561:
#line 10124 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1562:
#line 10125 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 1563:
#line 10129 "parser.y"
    { (yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0); ;}
    break;

  case 1564:
#line 10134 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  ;}
    break;

  case 1565:
#line 10141 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1566:
#line 10148 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1567:
#line 10155 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1568:
#line 10165 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  ;}
    break;

  case 1569:
#line 10169 "parser.y"
    {
	(yyval) = cb_build_identifier ((yyvsp[(1) - (1)]), 0);
  ;}
    break;

  case 1570:
#line 10176 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (3)]))) {
		CB_REFERENCE ((yyvsp[(1) - (3)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (3)]));
	}
  ;}
    break;

  case 1571:
#line 10186 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (2)]))) {
		CB_REFERENCE ((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1572:
#line 10196 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (2)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (2)]))) {
		CB_REFERENCE ((yyvsp[(1) - (2)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (2)]));
	}
  ;}
    break;

  case 1573:
#line 10206 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
	if (CB_REFERENCE_P ((yyvsp[(1) - (1)]))) {
		CB_REFERENCE ((yyvsp[(1) - (1)]))->flag_target = 1;
	}
	if (start_debug) {
		cb_check_field_debug ((yyvsp[(1) - (1)]));
	}
  ;}
    break;

  case 1574:
#line 10219 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1575:
#line 10223 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (3)]);
	CB_REFERENCE ((yyvsp[(1) - (3)]))->chain = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 1576:
#line 10231 "parser.y"
    {
	(yyval) = (yyvsp[(0) - (3)]);
	CB_REFERENCE ((yyvsp[(0) - (3)]))->subs = cb_list_reverse ((yyvsp[(2) - (3)]));
  ;}
    break;

  case 1577:
#line 10239 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (4)]))->offset = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 1578:
#line 10243 "parser.y"
    {
	CB_REFERENCE ((yyvsp[(0) - (5)]))->offset = (yyvsp[(2) - (5)]);
	CB_REFERENCE ((yyvsp[(0) - (5)]))->length = (yyvsp[(4) - (5)]);
  ;}
    break;

  case 1579:
#line 10253 "parser.y"
    {
	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign < 0 || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		(yyval) = (yyvsp[(1) - (1)]);
	}
  ;}
    break;

  case 1580:
#line 10268 "parser.y"
    {
	int	n;

	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else {
		n = cb_get_int ((yyvsp[(1) - (1)]));
		if (n < 1 || n > 256) {
			cb_error (_("Invalid SYMBOLIC integer"));
			(yyval) = cb_int1;
		} else {
			(yyval) = (yyvsp[(1) - (1)]);
		}
	}
  ;}
    break;

  case 1581:
#line 10291 "parser.y"
    {
	int	n;

	if (cb_tree_category ((yyvsp[(1) - (1)])) != CB_CATEGORY_NUMERIC) {
		cb_error (_("Integer value expected"));
		(yyval) = cb_int1;
	} else if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign < 0 || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
		cb_error (_("Positive Integer value expected"));
		(yyval) = cb_int1;
	} else {
		n = cb_get_int ((yyvsp[(1) - (1)]));
		if (n < 1) {
			cb_error (_("Invalid integer"));
			(yyval) = cb_int1;
		} else {
			(yyval) = (yyvsp[(1) - (1)]);
		}
	}
  ;}
    break;

  case 1582:
#line 10314 "parser.y"
    {
	int	n;

	if (cb_tree_category ((yyvsp[(1) - (1)])) == CB_CATEGORY_NUMERIC) {
		if (CB_LITERAL ((yyvsp[(1) - (1)]))->sign || CB_LITERAL ((yyvsp[(1) - (1)]))->scale) {
			cb_error (_("Integer value expected"));
		} else {
			n = cb_get_int ((yyvsp[(1) - (1)]));
			if (n < 1 || n > 256) {
				cb_error (_("Invalid CLASS value"));
			}
		}
	}
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1583:
#line 10329 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1584:
#line 10330 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1585:
#line 10331 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1586:
#line 10332 "parser.y"
    { (yyval) = cb_high; ;}
    break;

  case 1587:
#line 10333 "parser.y"
    { (yyval) = cb_low; ;}
    break;

  case 1588:
#line 10334 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1589:
#line 10339 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1590:
#line 10343 "parser.y"
    {
	struct cb_literal	*l;

	if (CB_LITERAL_P ((yyvsp[(2) - (2)]))) {
		/* We must not alter the original definition */
		l = cobc_parse_malloc (sizeof(struct cb_literal));
		*l = *(CB_LITERAL((yyvsp[(2) - (2)])));
		l->all = 1;
		(yyval) = CB_TREE (l);
	} else {
		(yyval) = (yyvsp[(2) - (2)]);
	}
  ;}
    break;

  case 1591:
#line 10360 "parser.y"
    {
	(yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 1592:
#line 10364 "parser.y"
    {
	(yyval) = cb_concat_literals ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1593:
#line 10370 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 1594:
#line 10371 "parser.y"
    { (yyval) = cb_space; ;}
    break;

  case 1595:
#line 10372 "parser.y"
    { (yyval) = cb_zero; ;}
    break;

  case 1596:
#line 10373 "parser.y"
    { (yyval) = cb_quote; ;}
    break;

  case 1597:
#line 10374 "parser.y"
    { (yyval) = cb_high; ;}
    break;

  case 1598:
#line 10375 "parser.y"
    { (yyval) = cb_low; ;}
    break;

  case 1599:
#line 10376 "parser.y"
    { (yyval) = cb_null; ;}
    break;

  case 1600:
#line 10383 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), 0);
  ;}
    break;

  case 1601:
#line 10387 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), CB_LIST_INIT ((yyvsp[(3) - (5)])), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1602:
#line 10391 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1603:
#line 10395 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1604:
#line 10399 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, 0);
  ;}
    break;

  case 1605:
#line 10403 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1606:
#line 10407 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1607:
#line 10411 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]), 0);
  ;}
    break;

  case 1608:
#line 10415 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 0);
  ;}
    break;

  case 1609:
#line 10419 "parser.y"
    {
	(yyval) = cb_build_intrinsic ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NULL, 1);
  ;}
    break;

  case 1618:
#line 10443 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1619:
#line 10447 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (4)]), NULL);
  ;}
    break;

  case 1620:
#line 10451 "parser.y"
    {
	(yyval) = CB_BUILD_PAIR ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
  ;}
    break;

  case 1621:
#line 10458 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1622:
#line 10462 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 1623:
#line 10466 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1624:
#line 10473 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_int0);
  ;}
    break;

  case 1625:
#line 10480 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int1);
  ;}
    break;

  case 1626:
#line 10487 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_int2);
  ;}
    break;

  case 1627:
#line 10497 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  ;}
    break;

  case 1628:
#line 10504 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, (yyvsp[(3) - (3)]));
  ;}
    break;

  case 1629:
#line 10514 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (1)]));
	(yyval) = cb_list_add (x, cb_null);
  ;}
    break;

  case 1630:
#line 10521 "parser.y"
    {
	cb_tree	x;

	x = CB_LIST_INIT ((yyvsp[(1) - (3)]));
	(yyval) = cb_list_add (x, cb_ref ((yyvsp[(3) - (3)])));
  ;}
    break;

  case 1631:
#line 10532 "parser.y"
    {
	non_const_word = 1;
  ;}
    break;

  case 1632:
#line 10540 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1633:
#line 10541 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1634:
#line 10545 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1635:
#line 10546 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1636:
#line 10550 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1637:
#line 10551 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1638:
#line 10556 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1639:
#line 10560 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1640:
#line 10567 "parser.y"
    {
	(yyval) = NULL;
  ;}
    break;

  case 1641:
#line 10571 "parser.y"
    {
	(yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 1642:
#line 10578 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1643:
#line 10579 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1644:
#line 10580 "parser.y"
    { (yyval) = cb_int2; ;}
    break;

  case 1645:
#line 10584 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1646:
#line 10585 "parser.y"
    { (yyval) = cb_true; ;}
    break;

  case 1647:
#line 10589 "parser.y"
    { (yyval) = cb_int (cb_flag_optional_file); ;}
    break;

  case 1648:
#line 10590 "parser.y"
    { (yyval) = cb_int1; ;}
    break;

  case 1649:
#line 10591 "parser.y"
    { (yyval) = cb_int0; ;}
    break;

  case 1650:
#line 10596 "parser.y"
    {
	(yyval) = cb_int0;
  ;}
    break;

  case 1651:
#line 10600 "parser.y"
    {
	if ((yyvsp[(2) - (2)])) {
		(yyval) = (yyvsp[(2) - (2)]);
	} else {
		(yyval) = cb_int (COB_STORE_ROUND);
	}
	cobc_cs_check = 0;
  ;}
    break;

  case 1652:
#line 10612 "parser.y"
    {
	(yyval) = NULL;
	cobc_cs_check = 0;
  ;}
    break;

  case 1653:
#line 10617 "parser.y"
    {
	(yyval) = (yyvsp[(3) - (3)]);
	cobc_cs_check = 0;
  ;}
    break;

  case 1654:
#line 10625 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_AWAY_FROM_ZERO);
  ;}
    break;

  case 1655:
#line 10629 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_AWAY_FROM_ZERO);
  ;}
    break;

  case 1656:
#line 10633 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_EVEN);
  ;}
    break;

  case 1657:
#line 10637 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_NEAR_TOWARD_ZERO);
  ;}
    break;

  case 1658:
#line 10641 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_PROHIBITED);
  ;}
    break;

  case 1659:
#line 10645 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_GREATER);
  ;}
    break;

  case 1660:
#line 10649 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TOWARD_LESSER);
  ;}
    break;

  case 1661:
#line 10653 "parser.y"
    {
	(yyval) = cb_int (COB_STORE_ROUND | COB_STORE_TRUNCATION);
  ;}
    break;

  case 1662:
#line 10659 "parser.y"
    { (yyval) = NULL; ;}
    break;

  case 1663:
#line 10660 "parser.y"
    { (yyval) = cb_int1; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 17109 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 10830 "parser.y"


