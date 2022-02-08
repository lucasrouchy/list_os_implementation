#include "llist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  struct node *head = NULL;
  for (int i = 1; i <argc; i++){
    char *input = argv[i];
    if (strcmp(input, "it") == 0){
      int num = atoi(argv[i+1]);
      llist_insert_head(&head, node_alloc(num));
    } else if (strcmp(input, "p") == 0){
      llist_print(head);
    }
  }
  return 0;
}

void llist_insert_head(struct node **head, struct node *n){
  struct node *old = *head;
  n->next = old;
  *head = n;
}

void llist_print(struct node *head){
  struct node *ptr = head;
  if(head == NULL) printf("[Empty]");
  while (ptr != NULL) {
    int current_value = ptr->value;
    printf("%d", current_value);
    if (ptr->next != NULL) printf(" -> ");
    ptr = ptr->next;
  }
  printf("\n");
}
struct node *node_alloc(int value){
  struct node *head = malloc(sizeof(struct node));
  head ->value = value;
  head ->next = NULL;
  return head;
}
