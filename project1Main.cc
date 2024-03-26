#include <iostream>

#include "constants.h"
#include "Dictionary.h"
#include "MyLetter.h"
#include "LetterArray.h"
#include "project1Functions.h"

using namespace std;


int main(){
  cout << "Welcome!  I'd like to play some Wordle." << endl;
  cout << "You think of a word.  I'll make guesses, and you can tell me how close I am." << endl;
  cout << "When I guess a word, please respond with one of the following:" << endl;
  cout << BANG << " if the letter is in the word and in the correct position." << endl;
  cout << CLOSER << " if the letter is in the word, but not in the correct position." << endl;
  cout << MISS << " if the letter is not in the word." << endl;
  LetterArray alphabet; //Default LetterArray object to hold a MyLetter for each lowecase English letter
  Dictionary book; //Dictionary object to be passed to fucntions to check words
  alphabet = fillAlphabet(alphabet); //Replace default values in alphabet MyLetter object with ASCII or UNICODE codes for letters
  char guessWord[WORD_LENGTH + 1]; //Declare string for first guess
  book.getRandomWord(guessWord); //Get a random word from Dictionary object book
  cout << "Guess 1: " << guessWord << endl; 
  char feedback[WORD_LENGTH + 1]; // holds feedback from user
  getUserFeedback(feedback); //get feedback from user on 1st word
  int perfectMatches[WORD_LENGTH]; //holds ASCII or UNICODE values for perfect match letters in appropriate array positions
  initializeArray(perfectMatches); //place NO_MATCH in all positions in perfectMatches[]
  int lettersToGuess[WORD_LENGTH]; //holds non-perfect matches to guess
  initializeArray(lettersToGuess); //place NO_MATCH in each position of this array
  int newGuess [WORD_LENGTH]; //holds the ASCII or UNICODE codes for the word to guess
  convertLetToASCII (guessWord, newGuess); //fill newGuess with the ASCII or UNICODE codes for the letters from guessWord
  int perMatCounter = updatePerfectMatches (newGuess, feedback, perfectMatches, lettersToGuess); //holds the number of perfect matches
  //this function also updates the array perfectMatches[] using the char feedback[]
  int letToGueCounter = updateLettersToGuess (newGuess, feedback, lettersToGuess, alphabet); //holds the number of CLOSE matches
  //this function also updates lettersToGuess[] using the char feedback[], it adds CLOSE matches to lettersToGuess (starting at index = 0)
  updateMyLetterNotInWord (newGuess, feedback, alphabet);//updates MyLetter object notInWord for words that received a MISS.  It also sets
  //MyObject attPos at the MISS index to true (tried this letter there)
  int indexArray [WORD_LENGTH];//array to hold indices for letters in lettersToGuess.  Used to prevent placing a letter at the same index more than once.
  bool wordFound = false;//bool for if appropriate newWord has been found.  It is used to collapse the recursive loops used to vary indices and letters.
  //char perMatLet [WORD_LENGTH + 1]; USED TO TROUBLESHOOT RUNTIME ERRORS
  //MyLetter testLetter; ALSO USED TO TROUBLESHOOT RUNTIME ERRORS
  int guessCounter = 1;
  bool allBangs = false;
  int whileIndex = 0;
  allBangs = checkBangs (feedback); //checks to see if the program has won.  Unlikely on first word, but it might happen.
  while ((whileIndex < (ALLOWED_ATTEMPTS - 1)) && (!allBangs)){ //Loop to select and evaluate words for next ALLOWED_ATTEMPTS -1
    wordFound = false;//set wordFound to false before generating a new word.
    //This next function is the first in a series to generate a new valid newWord
    getNewWord (lettersToGuess, perfectMatches, newGuess, letToGueCounter, perMatCounter, 0, wordFound, alphabet, indexArray, book);
    convertASCIIToLet (newGuess, guessWord);//convert from ASCII/UNICODE to lowercase letters
    cout << "Guess " << (whileIndex + GUESS_OFFSET) << ": " << guessWord << endl;//output guess
    getUserFeedback(feedback);//get feedback on guess
    allBangs = checkBangs (feedback);//check if program has won
    initializeArray(perfectMatches);//here to next comment:  Intialize and update arrays and counters repeating the process for the first word
    //in preparation for generating the next word
    perMatCounter = updatePerfectMatches (newGuess, feedback, perfectMatches, lettersToGuess);
    initializeArray(lettersToGuess);
    letToGueCounter = updateLettersToGuess (newGuess, feedback, lettersToGuess, alphabet);
    updateMyLetterNotInWord (newGuess, feedback, alphabet);
    whileIndex++;//update counter for next guess
    guessCounter++;//update counter keeping track of guesses
  }
  if (allBangs){
    cout << "I got the word in " << guessCounter << " guesses." << endl;  //the program wins
  }
  else{
    cout << "Sorry, I could not guess the word in " << ALLOWED_ATTEMPTS << " tries." << endl; //the program didn't guess the word
    //I had to reduce the number of tries to get this to print out.  I don't think I saw the computer lose in less than 8 allowed tries.
  }
  return(0);
}
