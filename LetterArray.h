#ifndef INCLUDED_LetterArray
#define INCLUDED_LetterArray



class LetterArray {

  //CI:  contains an array of MyLetter objects of length LETTER_ARRAY_SIZE.
 private:
  MyLetter arrayOfMyLetter[LETTER_ARRAY_SIZE];//the array to hold MyLetter objects

 public:
  //Default contructor
//PRE:
//POST:  A LetterArray object where arrayOfMyLetter[] contains ALPHABET MyLetter objects

  LetterArray();

  //PRE:  Implicit parameter is defined with a size LETTER_ARRAY_SIZE and an index I < LETTER_ARRAY_SIZE
  //POST:  The MyLetter object at index I is returned.

  MyLetter getMyLetter(int index);

  //PRE:  Implicit parameter is defined with a size LETTER_ARRAY_SIZE, an index I < LETTER_ARRAY_SIZE, and int asc
  //the ASCII, UNICODE, or other code for a lowercase letter.
  //POST:  The value for the letter (int letter in MyLetter class) is changed to the value of asc.

  void changeMyLetterLetter(int index, int asc);
  
//PRE:  Implicit parameter is defined with a size LETTER_ARRAY_SIZE and index I < LETTER_ARRAY_SIZE.
//POST:  The value of notInWord in the MyLetter at the position I is changed to true.

  void changeMyLetterNotInWord(int index);

  //PRE:  Implicit parameter is defined with a size LETTER_ARRAY_SIZE, an index I < LETTER_ARRAY_SIZE, and a an
  //index pos < WORD_LENGTH in the MyLetter object.
  //POST:  The value at attPos[pos] in the MyLetter object at arrayOfMyLetter[index] is set to true.

  void changeMyLetterAttPos(int index, int pos);

  
};

#endif
