project1Main: project1Main.o MyLetter.o LetterArray.o project1Functions.o Dictionary.o
	g++ project1Main.o MyLetter.o LetterArray.o project1Functions.o Dictionary.o -o project1Main

project1Functions.o: project1Functions.cc LetterArray.h MyLetter.h project1Functions.h Dictionary.h constants.h
	g++ -c project1Functions.cc

LetterArray.o: LetterArray.cc LetterArray.h MyLetter.h constants.h
	g++ -c LetterArray.cc

MyLetter.o: MyLetter.h MyLetter.cc constants.h
	g++ -c MyLetter.cc

project1Main.o: project1Main.cc MyLetter.h LetterArray.h project1Functions.h Dictionary.h constants.h
	g++ -c project1Main.cc
