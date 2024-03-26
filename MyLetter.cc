#include <iostream>
using namespace std;

#include "constants.h"
#include "MyLetter.h"






//Default constructor.
//PRE: 
//POST:  A MyLetter object where letter = 48, notInWord = false, and attPos[] = false at each location.

MyLetter::MyLetter(){
  letter = NO_MATCH;
  notInWord = false;
  int index = 0;
  while (index < WORD_LENGTH){
    attPos[index] = false;
    index++;
  }

}

//PRE: The implicit parameter is defined.
//POST:  RV is the ASCII value of the letter in the implicit parameter.

int MyLetter::getLetter() const {
  return(letter);
}

//PRE:  The implicit parameter is defined.
//POST:  RV is the bool of notInWord.

bool MyLetter::getNotInWord() const {
  return(notInWord);

}

//PRE:  The implicit parameter is defined.
//POST:  RV is the bool at the index position of attPos.

bool MyLetter::getAttPos(int index) const {
  return(attPos[index]);
}


//PRE:  The implicit parameter is defined.
//POST:  The value of notInWord is set to true.

void MyLetter::changeNotInWord(){
  notInWord = true;
}


//PRE:  The implicit parameter is defined.  An integer (I) for the position of attPos to be changed.
//POST:  The value of attPos[I] is set to true.

void MyLetter::changeAttPos(int index){
  attPos[index] = true;
}

 //PRE:  The implicit parameter is defined.  An integer 97 <= I <= 122 that is the ASCII code for a lowercase letter.
 //POST:  The value of letter is changed to I or 48 if I < 96 || I > 122.

void MyLetter::changeLetter(int ascCode){
  letter = ascCode;
}

