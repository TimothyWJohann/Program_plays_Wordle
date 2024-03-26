#ifndef INCLUDED_MyLetter
#define INCLUDED_MyLetter


class MyLetter {

  //CI:  letter is an integer corresponding to an ASCII or UNICODE code for a lowercase letter, or
  // the code for 'a' - 1 for initializing arrays.
  //notInWord is a bool set to false and switched to true when attempt to use the letter returns 'x'.
  //attPos is an bool array of locations that a letter has been tried in a word.  Each location is
  //test to false at the beginning of the program.

 private:
  bool notInWord;//true if an 'x' has been returned for in an attempt to use this letter. 
  int letter;//holds the ASCII value for the letter
  bool attPos[WORD_LENGTH];//holds positions in the word at which this letter has been attempted and feedback has
  //returned "in word but not exact match"
    


public:

//Default constructor.
//PRE: 
//POST:  A MyLetter object where letter = 48, notInWord = false, and attPos = false at each location.

MyLetter();


//PRE: The implicit parameter is defined.
//POST:  RV is the ASCII, UNICODE, or other value of the letter in the implicit parameter.
 
int getLetter() const;

 //PRE:  The implicit parameter is defined.
//POST:  RV is the bool of notInWord.

 bool getNotInWord() const;

//PRE:  The implicit parameter is defined.
//POST:  RV is the bool at the index position of attPos.

 bool getAttPos(int index) const;

//PRE:  The implicit parameter is defined.
//POST:  The value of notInWord is set to true.

 void changeNotInWord();
 
//PRE:  The implicit parameter is defined.  An integer (I) for the position of attPos to be changed.
//POST:  The value of attPos[I] is set to true.

 void changeAttPos(int index);

 //PRE:  The implicit parameter is defined.  An integer 97 <= I <= 122 that is the ASCII code for a lowercase letter.
 //POST:  The value of letter is changed to I or 48 if I < 96 || I > 122.

 void changeLetter(int ascCode);
 
};
#endif
