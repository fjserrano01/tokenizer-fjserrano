#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main(){
  List* list = init_history();
  while(1){
    
    //if statement checks for value if user decides to access
    //single word in history
    char* word = malloc(100*sizeof(char));
    printf("\n$:");
    fgets(word, 100, stdin);
    if(word[0] == '!'){
      //int i = 1;
      int id = 0;
      //int temp = 0;
      char* tempword = malloc(sizeof(char));
      *tempword = word[1];
      if(string_length(word) == 3){
	id = atoi(tempword);
	printf("\nid: %d", id);
      }//else{
      //while(i < string_length(word)){
      //temp = temp + word[i];
      //id = temp/10;
      //}
      //}
      char* historyWord = malloc(100*sizeof(char));
      historyWord = get_history(list, id);
      printf("\nhistoryword: %s",historyWord);
    }

    //Else adds the word to tokenizer and to the history of the
    //words inputed by the user
    else{
    int size = count_words(word);
    char** tokenizedword = (char**)malloc((size+1)*sizeof(char*));
    tokenizedword = tokenize(word);
    print_tokens(tokenizedword);
    //printf("\nString: %s", word);
    add_history(list, word);
    printf("\nWould you like to check word in history, y n");
    char* option = malloc(sizeof(char));
    fgets(option, 100, stdin);
    if(option[0] == 121){
      print_history(list);
    }
    free_tokens(tokenizedword);
    }
  }
  return 0;
}
