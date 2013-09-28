            >> source format is free 
       Identification division. 
       Program-id.  boxdraw. 
      *> 
      *> boxdraw * Box drawing examples. 
      *> 
      *> Run this program to test your computer's use of box drawing characters. 
      *> It displays both MS DOS and UTF-8 formats to see which ones work. 
      *> 
      *> To compile and run on Linux: 
      *> cobc -x boxdraw.cob 
      *> ./boxdraw 
      *> 
      *> Published under GNU General Public License. 
      *> 
       Data division. 
       Working-storage section. 
      *>
      *> MS DOS box characters. 
       01  box-dos-line-horizontal        pic x(01) value x"cd". 
       01  box-dos-line-vertical          pic x(01) value x"ba". 
       01  box-dos-top-left               pic x(01) value x"c9". 
       01  box-dos-top-right              pic x(01) value x"bb". 
       01  box-dos-bottom-left            pic x(01) value x"c8". 
       01  box-dos-bottom-right           pic x(01) value x"bc". 
      *> 
      *> UTF-8 box characters. 
       01  box-utf8-line-horizontal       pic x(03) value x"e29590". 
       01  box-utf8-line-vertical         pic x(03) value x"e29591". 
       01  box-utf8-top-left              pic x(03) value x"e29594". 
       01  box-utf8-top-right             pic x(03) value x"e29597". 
       01  box-utf8-bottom-left           pic x(03) value x"e2959a". 
       01  box-utf8-bottom-right          pic x(03) value x"e2959d". 
      *>
       Procedure division. 
      *> MS DOS box characters. 
          Display " ". 
          Display "MS DOS box characters. ".
          Display "If these display correctly, this computer is MS DOS compatible. ". 
      *> 
          Display box-dos-line-horizontal. 
          Display box-dos-line-vertical.   
          Display box-dos-top-left.          
          Display box-dos-top-right.       
          Display box-dos-bottom-left.       
          Display box-dos-bottom-right.   
      *> 
      *> UTF-8 box characters. 
          Display " ". 
          Display "UTF-8 box characters. ".
          Display "If these display correctly, this computer is UTF-8 compatible. ". 
      *> 
          Display box-utf8-line-horizontal. 
          Display box-utf8-line-vertical.   
          Display box-utf8-top-left.          
          Display box-utf8-top-right.       
          Display box-utf8-bottom-left.       
          Display box-utf8-bottom-right.     
      *>
      *> Glyphs. 
          Display " ". 
          Display "Box character glyphs. ". 
      *> 
          Display "═". 
          Display "║". 
          Display "╔". 
          Display "╗". 
          Display "╚". 
          Display "╝". 
      *> 
          Display " ". 
          Goback. 
      *> 
