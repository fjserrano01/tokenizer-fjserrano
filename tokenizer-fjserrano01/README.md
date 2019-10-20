Lab Project 1: Building a Tokenizer
===================================
The Tokenizer created in this project is to be run by first compiling the
Makefile with the command "gcc Makefile" after which the system will create
the file to be ran called Tokenizer. This file when ran using the command
"./Tokenizer" will be using the files listed bellow to demonstrate the
program.

tokenizerInterface.c
tokenizer.c
tokenizer.h
history.c
history.h

--Commands--
These files will be compiled together and ran, the tokenizerInterface will
display the appropriate intro line for the user input.
$:
This line will indicate that the user may write their string into the
program. One may also run a command
"!n"
"n"- meaning any number within range of the words that have been inserted, if
there are only 3 words then the number accepted in this input will be from
1-3.

The user interface will then display the tokenized version of the word and
will ask the user if they wish to see the full list of all words that have
been inputed into the history List. This will be asked of input
"y" or "n"
and will only accept these lower case letters. With the press of "y" it will
display all the words that have been inserted into the program and the id of
which they have been stored under.

--Description of Files--
The history file initializes the list with an empty Item of value "0" in id
and NULL in next, in order to ensure a check of empty list is possible at the
beggining of the program. Using this if the is_empty method detects an id of 0
it will return 1 or true, in order to see a non empty list, the first Item in
the list will be of ID: 1.

The tokenizer file allows the user input to be tokenized by first verifying
the word is valid, then seperating the words in the string. This is done by
using the copy word function that first traverses the string finding the
appropriate beggining and finds the ending of the current word. This is then
copied into a new word. This same logic allows the tokenizer to seperate the
words and add them into the tokenized double pointer array as individual
strings.
