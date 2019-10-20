#include <stdio.h>
#include <stdlib.h>
#ifndef TOKENIZER_H
#define TOKENIZER_H
//Counts the total amount of characters in the string
//By going through the total array and adding 1 to its position
int  string_length(char* c){
  //printf("in length method \n");
  int i = 0;
  int  size_of_string = 0;
  char* character = c;
  while(c[size_of_string] != '\0'){
    size_of_string = size_of_string + 1;
  }
  return size_of_string;
}
//Checks if current posiion is a valid character by checking its ascii value
//returning 1 if it is valid
char is_valid_character(char c){
  //printf("\nin is_valid_character method");
  if(c < 33 || c > 126){
    return 0;
  }
  return 1;
}
//Returns the fist letter of the first word if it is found
char* find_word_start(char* c){
  int i = 0;

  //checks if the character is a valid variable and then continues till it finds a character
  //if it is not a letter, returns the letter value itself
  while((is_valid_character(*(c+i))==0)|| ((((int) *(c+i)) > 47) && (((int) *(c+i)) < 58))){
    //printf("\ncurrent yes");
    if(*(c+i)== '\0'){
      //printf("\ncurrent string");
      return *(c+i);
    }
    i= i+1;
    //printf("yes");
  }
  return &*(c+i);
}
//Returns the ending of the first word after it has gone through the word
char* find_word_end(char* c){
  int i = 0;
  //checks if the first character is invalid and finds the start of the word
  while((is_valid_character(*(c+i)) == 0)|| ((((int) *(c+i)) > 47)&& (((int) *(c+i)) < 58))){
    if(*(c+i) == '\0'){
      return *(c+i);
    }
    i = i+1;
  }
  //Continues till the end of the word and returns the character at that position
  while(is_valid_character(*(c+i))== 1){
    if(*(c+i)=='\0'){
      return *(c+1);
    }
    i= i+1;
  }
  return &*(c+i);
}

//Returns the number of words in the list
int count_words(char* c){
  int i = 0;
  int words = 0;
  
  //Finds the first word and continues till the ending before incrementing the word count
  while(*(c+i) != '\0'){
    while((is_valid_character(*(c+i)) == 0)|| ((((int) *(c+i)) > 47) && (((int) *(c+i))<58))){
      //printf("\n1");
      if(*(c+i) == '\0'){
	return words;
      }
      //printf("\nvalue of i in 1: %d", i);
      i = i+1; 
    }
    //printf("\n3");
    while(is_valid_character(*(c+i))==1){
	if(*(c+i) =='\0'){
	  return words;
	}
	i = i+1;
    }
    i = i+1;
    words = words+1;
    //printf("\n words: %d", words);
  }
  return words;
}

//Copies the next word in the array string
char* copy_word(char *myStr){
  //Gets the start of the word and end
  char* newstring = find_word_start(myStr);
  char* endofnewstring = find_word_end(myStr);
  int size = 0;
  size = sizeof(myStr)/sizeof(myStr[0]);
  char *word = malloc(sizeof(char)*(size+1));
  int i = 0;
  
  //Copies the values of the word into a new pointer to return
  //copies from the start string till it reaches the first value
  //of the end string
  while(newstring[i] != endofnewstring[0]){
    *(word+i) = newstring[i];//or word[i] = newstring[i]
    //printf("\nletter of word : %c", word[i]);
    i = i+1;
  }
  word[i] = '\0';
  return &*word;
  
}

//Prints all the words in the final double pointer array
void print_tokens(char** c){
  for(int i = 0;c[i] != '\0'; i = i+1){
    printf("\nword in tokenizer is: %s",c[i]);
  }
  printf("\n");
}

//Free's the pointer memory location in the arrays and sets the pointer
//to null to avoid dangling pointers
void free_tokens(char** c){
  for(int i = 0; c[i] != '\0'; i = i+1){
    free(c[i]);
    c[i] = '\0';
  }
  free(c);
  c = '\0';
}

//Sets up the double pointer array and transfers the words from
//the original array to the double pointer
char** tokenize(char* c){
  //would get value from c using copy word
  int size = count_words(c);
  char** new_array = malloc((size+1)*sizeof(char*));
  int i = 0;
  //Finds the start of the word, copies the next word into a
  //temporary character array and transfers it into the double pointer
  //array, then continues through the next word in the starting array
  while((c[i])!= '\0'){
    c = find_word_start(c);
    char* word = copy_word(c);
    c = find_word_end(c);
    int size2 = string_length(word);
    new_array[i] = malloc((size2+1)*sizeof(char*));
    new_array[i] = word;
    i = i+1;
  }
  
  return new_array;
}
#endif
