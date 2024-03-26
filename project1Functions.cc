#include <iostream>
using namespace std;

#include "constants.h"
#include "Dictionary.h"
#include "MyLetter.h"
#include "LetterArray.h"
#include "project1Functions.h"

//PRE:  A LetterArray object with LETTER_ARRAY_SIZE default MyLetter objects.
//POST:  A LetterArray object where the value of letter for each MyLetter object is
//index + ASCI_CONVERT (works for UNICODE too) where index is LetterArray[index].

LetterArray fillAlphabet (LetterArray alphArray){
  for (int index = 0; index < LETTER_ARRAY_SIZE; index++){
    alphArray.changeMyLetterLetter(index, (index + ASCII_CONVERT));
  }
    return(alphArray);
}


//PRE:  word is a string with a length WORD_LENGTH + 1.
//POST: word = a random word from the Dictionary object with EOS at location WORD_LENGTH.

void getARandomWord (char word[]){
  Dictionary book;
  book.getRandomWord(word);
  word[WORD_LENGTH] = EOS;
}

//PRE: IS contains feedback on letters contained in the secret word.
//POST:  RV is an array of WORD_LENGTH + 1 containing a character indicating response for each letter.
//EOS is at array position WORD_LENGTH.

void getUserFeedback (char feedback[]){
  for (int index = 0; index < WORD_LENGTH; index++){
    feedback[index] = cin.get();
  }
  cin.get();
  feedback[WORD_LENGTH] = EOS;
}

//PRE: destArr is defined.  sourceStr is WORD_LENGTH lowecase letters followed by EOS.
//POST:  destArr contains the ASCII or UNICODE codes for the letters in sourceStr.

void convertLetToASCII (char sourceStr[], int destArr[]){

  for (int index = 0; index < WORD_LENGTH; index++){
    destArr[index] = int (sourceStr[index]);
  }
  
}

//PRE: destStr is defined and of length WORD_LENGTH + 1.  sourceArr is WORD_LENGTH ASCII or UNICODE codes for
//lowercase letters.
//POST:  destStr contains the letters corresponding to the ASCII or UNICODE codes in sourceArr followed by EOS.

void convertASCIIToLet (int sourceArr[], char destStr[]){

  for (int index = 0; index < WORD_LENGTH; index++){
    destStr[index] = char (sourceArr[index]); 
  }
  destStr[WORD_LENGTH] = EOS;
}


//PRE:  thee int arrays of size WORD_LENGTH and one string of size WORD_LENGTH + 1:
//int guessWord[] (holds the ASCII values of the letter of the last word attempt)
//char feedback[] (hold the character feedback from IS on the last word) 
//int perfectMatches[] (holds the ASCII values for letters at positions where matches have occured.  At postions where matches
//have not occured, this array hold NO_MATCH)
//int lettersToGuess [] (holds the ASCII values for letters in the word where the correct location has not yet been found.

//POST:  appropriate ASCII or UNICODE values have been added to perfectMatches if any were indicated in feedback from IS

int updatePerfectMatches (int guessWord[], char feedback[], int perfectMatches[], int lettersToGuess[]){
  int counter = 0;
  for (int index = 0; index < WORD_LENGTH; index++){
    if (feedback[index] == BANG){
      //ASSERT:  This is a new perfect match.
      counter++;
      perfectMatches[index] = guessWord[index];
 
    
    }
  }
  return(counter);
}


//PRE:  two int arrays of size WORD_LENGTH and one string of size WORD_LENGTH + 1
//int guessWord[] (holds the ASCII values of the letter of the last word attempt)
//char feedback[] (hold the character feedback from IS on the last word) 
//int lettersToGuess [] is defined and initialized with NO_MATCH


//POST appropriate ASCII or UNICODE values have been added to lettersToGuess as indicated by feedback from IS.



int updateLettersToGuess (int guessWord[], char feedback[], int lettersToGuess[], LetterArray & alphabet){
  int counter = 0; //declare counter for how many "letters" added to lettersToGuess
  for (int index = 0; index < WORD_LENGTH; index++){
    if (feedback[index] == CLOSER){

      int aLetter = (guessWord[index] - ASCII_CONVERT);//store this letter's position in LetterArray
      // cout << "the value of aLetter is: " << aLetter << endl;
      alphabet.changeMyLetterAttPos(aLetter, index); 
      lettersToGuess[counter] = guessWord[index];
      counter++;
    }
  }
  return(counter);
}
  
//PRE: an int array containing the ASCII values of the last word attempt and a string with the IS feedback from that attempt
//and a LetterArray object
//POST:  MyLetter obejcts corresponding to letters in the word attempt that are not in the secret word have had the MyLetter
//object notInWord set to true. Positions these letters were guessed have been set to true in MyLetter.attPos.
void updateMyLetterNotInWord (int guessWord[], char feedback[], LetterArray & alphabet){
  int asciiValue;
  for (int index = 0; index < WORD_LENGTH; index++){
    if (feedback[index] == MISS){
      asciiValue = guessWord[index];
      alphabet.changeMyLetterNotInWord((asciiValue - ASCII_CONVERT));
      //ASSERT:  This letter has been marked as not being in the word.  It may still be a perfect match or close match
      //but additional copies of this letter should not be guessed.
      alphabet.changeMyLetterAttPos((asciiValue - ASCII_CONVERT), index);
      //ASSERT:  Letter has been marked as having been tried at this position.  Important when it is in guessWord
      //twice and the target word once.
    }
  }
}

//PRE: two int arrays, sourceArr and destArr with a size WORD_LENGTH. 
//POST:  destArr is a deep copy of sourceArr.

int copyArr (int sourceArr[], int destArr[]){
  for (int index = 0; index < WORD_LENGTH; index++){
    destArr[index] = sourceArr[index];
 }
}


//PRE:  four defined int arrays of WORD_LENGTH: lettersToGuess[], perfectMatches[], newWord[], indexArray[]
//three defined int variables: letToGuessCounter, perMatchCounter, index
//one defined bool wordFound set to false, passed by reference
//LetterArray object alphabet is defined and Dictionary object book is defined
//POST: newWord will contain the ASCII or UNICODE codes for the new word to guess, wordFound will be set to true


//LETTERARRAY & ALPHABET SHOULDN'T NEED TO BE PASSED BY REFERENCE HERE, BUT TROBULESHOOTING
void getNewWord (int lettersToGuess[], int perfectMatches[], int newWord[], int letToGuessCounter, int perMatchCounter, int index, bool & wordFound, LetterArray & alphabet, int indexArray[], Dictionary book){
  int newLettersNeeded = (WORD_LENGTH - letToGuessCounter - perMatchCounter);
  MyLetter tempMyLetter;
    bool letFound = false;
    int letIndex = 0;
    //This loop will assemble an array (lettersToGuess) that is non-perfect matches to later try in various positions for the new guessWord (newWord here)
    while ((letIndex < LETTER_ARRAY_SIZE) && (!wordFound)){
      letFound = false;
      tempMyLetter = alphabet.getMyLetter(letIndex);
      if (!tempMyLetter.getNotInWord()){
	lettersToGuess[letToGuessCounter + index] = tempMyLetter.getLetter();
	//ASSERT: a letter that has not previous had an x in feedback has been found
	letFound = true;
      }
      letIndex++;
      if (letFound){
		//if there are open positions for letters to guess, recurse to search the for letters for the next position
      if (((index+1) < newLettersNeeded) && (!wordFound)){
	getNewWord (lettersToGuess, perfectMatches, newWord, letToGuessCounter, perMatchCounter, (index + 1), wordFound, alphabet, indexArray, book);
       
      }
      else{
	//lettersToGuess[] has desired number of letters (WORD_LENGTH - perfectMatches).  Call function to put contents of perfectMatches[] and lettersToGuess[] in newWord.
	assembleWord1 (lettersToGuess, perfectMatches, newWord, perMatchCounter, 0, wordFound, alphabet, indexArray, book);
      }
      }
    }

  
}

//PRE: four defined int arrays: lettersToGuess[], perfectMatches[], newWord[], and indexArray[]
//two int variables:  perMatchCounter and index
//one bool wordFound passed by reference
//LetterArray object alphabet and Dictionary object book, both defined.
//POST: newWord contains the ASCII or UNICODE codes for the letter to guess.

void assembleWord1 (int lettersToGuess[], int perfectMatches[], int newWord[], int perMatchCounter, int index, bool & wordFound, LetterArray alphabet, int indexArray[], Dictionary book){
  int lettersToPlace = (WORD_LENGTH - perMatchCounter);
  int whileIndex = 0;
  //This set of recursive loops fills an array with a set of indices to be used to place the codes from lettersToGuess in the non-perfectMatch positions in newWord
  //indicies are used instead of letters to easily check for (and reject) the same letter (ie.  the same 'a' of two 'a''s) being placed more than once.
  while ((whileIndex < lettersToPlace) && (!wordFound)){ 
    indexArray[index] = whileIndex;
    if ((index + 1) < lettersToPlace){
      //if more indices need to be placed, recursively call this function at the next index position
      assembleWord1 (lettersToGuess, perfectMatches, newWord, perMatchCounter, (index + 1), wordFound, alphabet, indexArray, book);
    }
    else{
      //if all indices are placed, call the function to check the word.
      checkWord(lettersToGuess, perfectMatches, newWord, indexArray, perMatchCounter, wordFound, alphabet, book);
    }
    whileIndex++;
  }
   
}


//PRE:  four defined int arrays lettersToGuess[], perfectMatches[], newWord[], and indexArray[]
//one int variable perfectMatchCounter
//one bool wordFound passed by reference and set to false
//one LetterArray object alphabet and one Dictionary object book, both defined
//POST: iff an appropriate word is found for the next guess, newWord contains the ASCII or UNICODE codes for that word AND wordFound is set to true.
//otherwise wordFound set to false.
void checkWord (int lettersToGuess[], int perfectMatches[], int newWord[], int indexArray[], int perMatchCounter, bool & wordFound, LetterArray alphabet, Dictionary book){

  if (!checkDuplicates(indexArray, (WORD_LENGTH - perMatchCounter))){
    makeNewWord (lettersToGuess, perfectMatches, newWord, indexArray,(WORD_LENGTH - perMatchCounter));
    char newWordWithLetters[WORD_LENGTH + 1];//new char array to check assembled word against Dictionary object book
    convertASCIIToLet(newWord, newWordWithLetters);
    if (book.isInDictionary(newWordWithLetters)){
      //ASSERT:  newWord is in Dictionary object book
      if (checkLetterPositions(newWord, alphabet)){
	//ASSERT:  no letters are being placed in previously tried (and failed (CLOSER or MISS) positions
    wordFound = true;
      }
    }
  }
  
}
//PRE: four defined int arrays lettersToGuess[], perfectMatches[], newWord[], and indexArray[]
//one int variable lettersToAdd
//POST:  newWord will contain the ASCII or UNICODE codes for from lettersToGuess in locations not already perfect matches.
void makeNewWord (int lettersToGuess[], int perfectMatches[], int newWord[], int indexArray[], int lettersToAdd){
  for (int index = 0; index < WORD_LENGTH; index++){
    newWord[index] = perfectMatches[index];
  }
  int whileIndex = 0;
  int whileIndex2 = 0;
  bool letterAdded = false;
  while (whileIndex < lettersToAdd){
    letterAdded = false;
    while ((whileIndex2 < WORD_LENGTH) && (!letterAdded)){
	if (newWord[whileIndex2] == NO_MATCH){
	  newWord[whileIndex2] = lettersToGuess[indexArray[whileIndex]];
	  //a non-perfectMatch position has been found and the ASCII or UNICODE code for a letter has been added to that position
	  letterAdded = true;
	}
	whileIndex2++;
      }
    whileIndex++;
  }
}

//PRE:  a defined int array containing size values.
//POST:  RV is true iff any values in the array are duplicates.

  bool checkDuplicates(int dupCheckArray[], int size){
    bool dupe = false;
    int index = 0;
    int index2 = 0;
    while ((index < size) && (!dupe)){
      index2 = (index + 1);
	while ((index2 < size) && (!dupe)){
	  if (dupCheckArray[index2] == dupCheckArray[index]){
	    //ASSERT:  The same index is being used in more than one position
	    dupe = true;
	  }
	  index2++;
	}
	index++;
      }
    return(dupe);
  }

//PRE: a defined int array containing ASCII or UNICODE codes for letters for a proepective new guess word
//LetterArray object alphabet is defined
//POST:  RV is true iff no letters have previously been assigned a '-' (in word, but not perfect match)
//at their current positions in the prospective guess word.

bool checkLetterPositions(int newWord[], LetterArray alphabet){
  MyLetter tempLetter;
  bool allowed = true;
  int index = 0;
  int letterIndex;
  while((index < WORD_LENGTH) && (allowed)){
    letterIndex = (newWord[index] - ASCII_CONVERT);
    tempLetter = alphabet.getMyLetter(letterIndex);
    if (tempLetter.getAttPos(index)){
      //ASSERT: this letter has already been attempted at this position and it was not a perfect match.
      allowed = false;
    }
    index++;
  }
    return (allowed);
}

//PRE:  a defined int array of size WORD_LENGTH
//POST:  each position of the array has the value NO_MATCH

void initializeArray (int theArray[]){
  for (int index = 0; index < WORD_LENGTH; index++){
    theArray[index] = NO_MATCH;
  }
}

//PRE:  char feedback is defined, of size WORD_LENGTH + 1, and ends in EOS.
//POST:  RV is true iff all elements of feedback (except EOS at end) are BANG.

bool checkBangs(char feedback[]){
  bool allBangs = true;
for (int index = 0; index < WORD_LENGTH; index++){
  if (feedback[index] != BANG){
    //ASSERT:  A non-bang has been found.  The program hasn't won yet.
    allBangs = false;
  }
 }
return (allBangs);
}
