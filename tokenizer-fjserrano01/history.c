#include <stdio.h>
#include <stdlib.h>
#ifndef TOKENIZER_H
#define TOKENIZER_H
#ifndef HISTORY_H
#define HISTORY_H

typedef struct s_Item{
  int id;
  char* str;
  struct s_Item* next;
}Item;

typedef struct s_List {
  struct s_Item* root;
}List;

//malloc list to point to the item
//Creates the list and initializes a temp item
// to be able to check initialization in add history
List* init_history(){
  List* list = malloc(sizeof(List));
  Item* temp = malloc(sizeof(Item));
  temp->id = 0;
  temp->str = "";
  temp->next = NULL;
  list->root = temp;
  return &*list;
}

//checks if the initial item exist by checking for default 0
// value initializes. if not it adds an item to the end of the list
void add_history(List* list, char* str){
  Item* temp = malloc(sizeof(Item));
  temp->str = str;
  if(is_empty(list)==1){
    temp->id = 1;
    list->root = temp;
  }else{
    int i = 0;
    List* tempList = malloc(sizeof(list));
    *tempList = *list;
    while(tempList->root->next != NULL){
      tempList->root = tempList->root->next;
      i = i+1;
     
    }
    temp->id = (tempList->root->id) +1;
    tempList->root->next = temp;
    tempList->root = tempList->root->next;
    tempList->root->next = NULL;
  }
}

//gets history by traversing the linked list till it finds the
//appropriate id of the item.
char* get_history(List* list, int id){
  char* str = malloc(100*sizeof(char));
  if(!is_empty(list)){
    List* tempList = malloc(sizeof(list));
    *tempList = *list;
    while(tempList->root != NULL){
      if(tempList->root->id == id){
	return &*tempList->root->str;
      }
      tempList->root = tempList->root->next;
    }
  }
  return NULL;
}

//Prints the full list of the history List
void print_history(List* list){
  List* tempList = malloc(sizeof(list));
  *tempList = *list;
  if(!is_empty(tempList)){
    while(tempList->root != NULL){
      printf("\nword at is %s", tempList->root->str);
      printf("\nword id is %d", tempList->root->id);
      tempList->root = tempList->root->next;
    }
  }
}

//Free's the history of the list
void free_history(List* list){
  List* temp = malloc(sizeof(list));
  while(!is_empty(list)){
    temp = list;
    list->root = list->root->next;
    free(temp);
  }
}

//checks if the list is empty, added to reduce redundancy in method checks
int is_empty(List* list){
  if(list->root->id == 0){
    return 1;
  }
  return 0;
}
#endif
#endif
