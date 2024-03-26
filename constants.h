#ifndef INCLUDED_constants
#define INCLUDED_constants

#define WORD_LENGTH 5 //Length of words used in the game
#define LETTER_ARRAY_SIZE 26 
#define ASCII_CONVERT (int) 'a'//referred to as an ASCII correction through program, but it would also work for UNICODE and possibly other systems.
#define EOS '\0'
#define BANG '!' //for use when the letter is in the secret word in the guessed position (perfect match)
#define CLOSER '-' //for use when the letter is in the secret word, but not in the guessed position
#define MISS 'x' //for use when the letter is not in the word
#define NO_MATCH ((int) 'a' - 1)//works for a filler element that is not a lowercase letter in ASCII, UNICODE, and possibly other systems.
#define ALLOWED_ATTEMPTS 10
#define GUESS_OFFSET 2 //needed to keep the correct count on guesses in project1Main.cc


#endif
