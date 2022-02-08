#include "llist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  struct node *head = NULL;
  for (int i = 1; i <argc; i++){
    char *input = argv[i];
    if (strcmp(input, "ih") == 0){
      int num = atoi(argv[i+1]);
      llist_insert_head(&head, node_alloc(num));
    } else if (strcmp(input, "p") == 0){
      llist_print(head);
    }
    else if (strcmp(input, "dh") == 0){
      llist_delete_head(&head);
    }
    if (strcmp(input, "it") == 0){
      int num = atoi(argv[i+1]);
      llist_insert_tail(&head, node_alloc(num));
    }
    if (strcmp(input, "f") == 0){
      llist_free(&head);
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
struct node *llist_delete_head(struct node **head){
  if(*head == NULL) return NULL;
  struct node *old = *head;
  struct node *next = (*head)->next;
  *head = next;
  return old;
}
void llist_insert_tail(struct node **head, struct node *n){
  if (*head == NULL) *head = n;
  else{
    struct node *ptr = *head;
    while (ptr->next != NULL) ptr = ptr ->next;
    ptr->next = n;
  }
}
void llist_free(struct node **head){
  if (*head == NULL) return;

  llist_free(&(*head)->next);
  node_free(*head);
  *head = NULL;

}
void node_free(struct node *n){
  free(n);
}
struct node *node_alloc(int value){
  struct node *head = malloc(sizeof(struct node));
  head ->value = value;
  head ->next = NULL;
  return head;
}
