#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { 
  list_node *nd = (list_node*)malloc(sizeof(list_node));
  nd->value = value;
  nd->next = NULL;
  return nd; 
}

void insert_at_head(struct linked_list *list, size_t value) {
  
  list_node*ptr = new_node(value);
  ptr->next = list->head;
  list->count++;
}

void insert_at_tail(struct linked_list *list, size_t value) { // Use
  if (list->head == NULL){
    return new_node(value);
  }
  list_node*p = list->head;
  while ((p->next) != NULL){
    p=p->next;
  }
  p->next = new_node(value);
  list->count++;
}

size_t remove_from_head(struct linked_list *list) { // Use
  list_node*q = list->head;
  if (q == NULL){
    return NULL;
  }
  int value = q->value;
  list->head = list->head->next;
  free(q);
  list->count--;
  return value; 
}

size_t remove_from_tail(struct linked_list *list) { 
  if (list->head == NULL){
    return NULL;
  }
  list_node*q = list->head;
  list_node*p = list->head;
  while ((q->next->next) != NULL){
    q=q->next->next;
    p=p->next;
  }
  int value = q->value;
  p->next = NULL;
  free(q);
  list->count--;
  return value; 
}

void free_list(struct linked_list list) {
  while ((list.head) != NULL){
    list_node*p = list.head.next;
    free(list.head);
    list.head = p;
  }
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
