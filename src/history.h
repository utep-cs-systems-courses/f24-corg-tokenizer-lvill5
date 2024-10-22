#ifndef _HISTORY_
#define _HISTORY_
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
  List* history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item* new_item = malloc(sizeof(Item));
    new_item->id = (list->root == NULL) ? 1 : list->root->id + 1; // Assign ID
    new_item->str = strdup(str); // Duplicate the string
    new_item->next = NULL;

    if (list->root == NULL) {
        list->root = new_item; // First item
    } else {
        Item* current = list->root;
        while (current->next != NULL) {
            current = current->next; // Traverse to the end
        }
        current->next = new_item; // Add new item at the end
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *current = list->root;
    while (current != NULL) {
        if (current->id == id) {
            return current->str; // Return the string if ID matches
        }
        current = current->next; // Move to the next item
    }
    return NULL; // Return NULL if ID not found
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if (list->root == NULL) {
        printf("History is empty.\n"); // Message for empty list
        return;
    }
    
    Item *current = list->root;
    while (current != NULL) {
        printf("%d: %s\n", current->id, current->str); // Print ID and string
        current = current->next; // Move to the next item
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list) {
    Item *current = list->root;
    while (current != NULL) {
        Item *next = current->next; // Store the next item
        free(current->str);          // Free the string
        free(current);               // Free the current item
        current = next;              // Move to the next item
    }
    free(list); // Free the list structure itself
}

#endif
