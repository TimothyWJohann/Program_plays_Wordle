#ifndef INCLUDED_project1Functions
#define INCLUDED_project1Functions

//PRE:  A LetterArray object with LETTER_ARRAY_SIZE default MyLetter objects.
//POST:  A LetterArray object where the value of letter for each MyLetter object is
//index + ASCI_CONVERT (works for UNICODE too) where index is LetterArray[index].

LetterArray fillAlphabet (LetterArray alphArray);

//PRE:  word is a string with a length WORD_LENGTH + 1.
//POST: word = a random word from the Dictionary object with EOS at location WORD_LENGTH.

void getARandomWord (char word[]);

//PRE: IS contains feedback on letters contained in the secret word.
//POST:  RV is an array of WORD_LENGTH + 1 containing a character indicating response for each letter.
//EOS is at array position WORD_LENGTH.

void getUserFeedback (char feedback[]);

//PRE: destArr is defined.  sourceStr is WORD_LENGTH lowecase letters followed by EOS.
//POST:  destArr contains the ASCII or UNICODE codes for the letters in sourceStr.

void convertLetToASCII (char sourceStr[], int destArr[]);

//PRE: destStr is defined and of length WORD_LENGTH + 1.  sourceArr is WORD_LENGTH ASCII or UNICODE codes for
//lowercase letters.
//POST:  destStr contains the letters corresponding to the ASCII or UNICODE in sourceArr followed by EOS.

void convertASCIIToLet (int sourceArr[], char destStr[]);

//PRE:  three int arrays of size WORD_LENGTH and one string of size WORD_LENGTH + 1:
//int guessWord[] (holds the ASCII values of the letter of the last word attempt)
//char feedback[] (hold the character feedback from IS on the last word) 
//int perfectMatches[] (holds the ASCII values for letters at positions where matches have occured.  At postions where matches
//have not occured, this array hold NO_MATCH)
//int lettersToGuess [] (holds the ASCII values for letters in the word where the correct location has not yet been found.

//POST:  appropriate ASCII or UNICODE values have been added to perfectMatches if any were indicated in feedback from IS

int updatePerfectMatches (int guessWord[], char feedback[], int perfectMatches[], int lettersToGuess[]);

//PRE:  two int arrays of size WORD_LENGTH and one string of size WORD_LENGTH + 1
//int guessWord[] (holds the ASCII values of the letter of the last word attempt)
//char feedback[] (hold the character feedback from IS on the last word) 
//int lettersToGuess [] is defined and initialzed with NO_MATCH


//POST: appropriate ASCII or UNICODE values have been added to lettersToGuess as indicated by feedback from IS.
int updateLettersToGuess (int guessWord[], char feedback[], int lettersToGuess[], LetterArray & alphabet);

//PRE: an int array containing the ASCII values of the last word attempt and a string with the IS feedback from that attempt
//and a LetterArray object
//POST:  MyLetter obejcts corresponding to letters in the word attempt that are not in the secret word have had the MyLetter
//object notInWord set to true.  Positions these letters were guessed have been set to true in MyLetter.attPos.

void updateMyLetterNotInWord (int guessWord[], char feedback[], LetterArray & alphabet);

//PRE: two int arrays, sourceArr and destArr with a size WORD_LENGTH. 
//POST:  destArr is a deep copy of sourceArr.

int copyArr (int sourceArr[], int destArr[]);


//PRE:  four defined int arrays of WORD_LENGTH: lettersToGuess[], perfectMatches[], newWord[], indexArray[]
//three defined int variables: letToGuessCounter, perMatchCounter, index
//one defined bool wordFound set to false, passed by reference
//LetterArray object alphabet is defined and Dictionary object book is defined.
//POST: newWord will contain the ASCII or UNICODE codes for the new word to guess, wordFound will be set to true

void getNewWord (int lettersToGuess[], int perfectMatches[], int newWord[], int letToGuessCounter, int perMatchCounter, int index, bool & wordFound, LetterArray & alphabet, int indexArray[], Dictionary book);


//PRE: four defined int arrays: lettersToGuess[], perfectMatches[], newWord[], and indexArray[]
//two int variables:  perMatchCounter and index
//one bool wordFound passed by reference
//LetterArray object alphabet and Dictionary object book, both defined.
//POST: newWord contains the ASCII or UNICODE codes for the letter to guess.

void assembleWord1 (int lettersToGuess[], int perfectMatches[], int newWord[], int perMatchCounter, int index, bool & wordFound, LetterArray alphabet, int indexArray[], Dictionary book); 


//PRE:  four defined int arrays lettersToGuess[], perfectMatches[], newWord[], and indexArray[]
//one int variable perfectMatchCounter
//one bool wordFound passed by reference and set to false
//one LetterArray object alphabet and one Dictionary object book, both defined
//POST: iff an appropriate word is found for the next guess, newWord contains the ASCII or UNICODE codes for that word AND wordFound is set to true.
//otherwise wordFound set to false.
void checkWord (int lettersToGuess[], int perfectMatches[], int newWord[], int indexArray[], int perMatchCounter, bool & wordFound, LetterArray alphabet, Dictionary book);

//PRE: four defined int arrays lettersToGuess[], perfectMatches[], newWord[], and indexArray[]
//one int variable lettersToAdd
//POST:  newWord will contain the ASCII codes for from lettersToGuess in locations not already perfect matches.
void makeNewWord (int lettersToGuess[], int perfectMatches[], int newWord[], int indexArray[], int lettersToAdd);


//PRE:  a defined int array containing size values
//POST:  RV is true iff any values in the array are duplicates.

bool checkDuplicates(int dupCheckArray[], int size);

//PRE: a defined int array containing ASCII or UNICODE codes for letters for a proepective new guess word
//LetterArray object alphabet is defined
//POST:  RV is true iff no letters have previously been assigned a '-' (in word, but not perfect match)
//at their current positions in the prospective guess word.

bool checkLetterPositions(int newWord[], LetterArray alphabet);


//PRE:  a defined int array of size WORD_LENGTH
//POST:  each position of the array has the value NO_MATCH

void initializeArray (int theArray[]);


//PRE:  char feedback is defined, of size WORD_LENGTH + 1, and ends in EOS.
//POST:  RV is true iff all elements of feedback (except EOS at end) are BANG.

bool checkBangs(char feedback[]);

#endif
