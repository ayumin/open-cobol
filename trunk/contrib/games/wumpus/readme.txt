
   The original BASIC wumpus game was written by Gregory Yob in 1973.  
This was a good game to study, because it showed how relational data 
(room numbers) could be used in multi-dimensioned tables. 

   He published it in People's Computer Company Journal, 
Vol. 2, No. 1, 1973.  It is one of the first games ever published, 
since the PCC Journal's first issue was October 1972. 

   The game was published again in Creative Computing, Vol. 1, No. 5, 
Sept/Oct 1975.  Another publication came in The Best of Creative 
Computing Volume 1 (1976) pp. 247 - 250. 

   Translated to COBOL for fun and educational purposes.

   This COBOL translation uses the earliest BASIC version that could 
be found in the Internet.  

   The term "user friendly" was not yet a part of the English language
when these games were created.  To end the game, the user was expected 
to turn off the computer, turn it back on, and reload the BASIC 
interpreter paper tape for the next game. 
Press ctrl-c to end the game. 

   Very little input validation is done.  If "X" is entered for a "Y/N" 
prompt, it may take it as either "Y" or "N" and give no warning. 

   Strategies for playing wumpus.

- See what a dodecahedron is at http://en.wikipedia.org/wiki/Dodecahedron 

- Print out the dodecahedron.jpg file.  It is a map of how the rooms are 
  connected.

- Move through the middle rooms 6 through 15 if possible. 
  This will quickly give hazard warnings for the outside and inside rooms.

- On the printed map, use pennies to mark possible bats, nickels to mark 
  possible pits, and dimes to mark possible wumpus locations. 
  Then back track and approach the rooms from the other side to determine 
  which of the possibles are actual hazards. 

- An arrow can go through 5 rooms if selected.  If trapped between bats and 
  pits it might be better to just start shooting arrows, than to take a 
  chance with a move. 

- With 5 arrows and up to 5 rooms each arrow, it is possible to hit all 
  but 2 of the 20 rooms.  However, the wumpus moves one room each time an 
  arrow is fired, so there's no guarantee that this will work. 
  But it does improve the odds.

   To compile and run under OpenCOBOL on Linux. 

cobc -xW wumpus.cob 
./wumpus  

   Wumpus does not use file I/O such as Berkeley DB, and does not 
use ncurses screen displays.
