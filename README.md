This C++ program plays Wordle.  The user thinks of a five letter word.  The program then guesses
words, and the user replies with an "x" in letter positions that are not present in the target word.  
The user replies with "-" if the letter is present, but not in the correct location.  The user replies 
with "!" if the letter is in the correct location.

Example:  
Target word = "lofts"
Program guess = "lotus"
User response = "!!-x!"


project1Main.cc is the main program file.
MyLetter.cc is a program file that defines and contains the functions for the MyLetter class.
LetterArray.cc is a program file that defines and contains the functions for the LetterArray class.
project1Functions.cc is a program file that contains functions specific to this program.

Dictionary.o is a compiled program that defines and contains the fuctions for the Dictionary class.

MyLetter.h is the header file for MyLetter.cc
LetterArray.h the header file for LetterArray.cc
project1Functions.h is the header file for project1Functions.cc
Dictionary.h is the header file for Dictionary.o
constants.h contains the constants used in this program

Textcases.txt explains how the program was tested.

There are no testcase files as the program starts with a random word.

To compile and link, run the Makefile using the command "make".

To run
   ./project1Main
   
