#include <iostream>
using namespace std;
#include "constants.h"
#include "MyLetter.h"
#include "LetterArray.h"

//Default contructor
//PRE:
//POST:  A LetterArray object where arrayOfMyLetter[] contains LETTER_ARRAY_SIZE MyLetter objects

LetterArray::LetterArray(){
}

  //PRE:  Implicit parameter is defined with a size LETTER_ARRAY_SIZE and an index I < LETTER_ARRAY_SIZE
  //POST:  The MyLetter object at index I is returned.

MyLetter LetterArray::getMyLetter(int index){
  MyLetter myLetObject = arrayOfMyLetter[index];
  return (myLetObject);

}


  //PRE:  Implicit parameter is defined with size LETTER_ARRAY_SIZE, an index I < LETTER_ARRAY_SIZE, and
//asc, the ASCII, UNICODE, or other code for a letter.
  //POST:  The value for the letter (int letter in MyLetter class) is changed to the value of asc.

void LetterArray::changeMyLetterLetter(int index, int asc){
  arrayOfMyLetter[index].changeLetter(asc);
}


//PRE:  Implicit parameter is defined with a size LETTER_ARRAY_SIZE and index I < LETTER_ARRAY_SIZE.
//POST:  The value of notInWord in the MyLetter at the position I is changed to true.

void LetterArray::changeMyLetterNotInWord(int index){
  arrayOfMyLetter[index].changeNotInWord();
}
 


  //PRE:  Implicit parameter is defined with a size LETTER_ARRAY_SIZE, an index I < LETTER_ARRAY_SIZE, and a an
  //index pos < WORD_LENGTH in the MyLetter object.
  //POST:  The value at attPos[pos] in the MyLetter object at arrayOfMyLetter[index] is set to true.

void LetterArray::changeMyLetterAttPos(int index, int pos){
  arrayOfMyLetter[index].changeAttPos(pos);
}
