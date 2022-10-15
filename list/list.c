#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "list.h"
 
list_t *list_alloc() {
 list_t* list = (list_t*) malloc(sizeof(list_t));
 list->head = NULL;
 return list;
 }
 
void list_free(list_t *l) {
   // free up all nodes from head to end of list
   // loop through and call node free for each node_free
   // then set head to null
 
   node_t *current_node, *next_node;
   current_node = l->head;
   if (current_node != NULL) {
     next_node = current_node->next;
     while (current_node != NULL) {
       node_free(current_node);
       current_node = next_node;
       if (next_node != NULL) {
         next_node = next_node->next;
       }
     }
   }
   l->head = NULL;
}
 
node_t *node_alloc(elem val) {
 node_t* node = (node_t*) malloc(sizeof(node_t));
 node->value = val;
 node->next = NULL;
 return node;
}
 
void node_free(node_t *n) {
 free(n);
}
 
void list_print(list_t *l) {
   node_t *current_node = l->head;
   if (current_node == NULL) {
     printf("List is empty!");
   }
 
   while (current_node != NULL){
     printf("%d ", current_node->value);
     current_node = current_node->next;
   }
   printf("\n");
}
 
int list_length(list_t *l) {
   node_t *current_node = l->head;
   int count = 0;
   if (current_node == NULL) {
     printf("List is empty!");
     return count;
   }
   else {
     while (current_node != NULL){
       count++;
       current_node = current_node->next;
     }
     return count;
 }
}
 
void list_add_to_back(list_t *l, elem value) {
 node_t *current_node = l->head;
 if (current_node == NULL) {
   list_add_to_front(l, value);
 }
 else {
   while (current_node->next != NULL){
     current_node = current_node->next;
   }
   node_t *new_node = node_alloc(value);
   current_node->next = new_node;
 }
}
 
void list_add_to_front(list_t *l, elem value) {
   node_t *add_node = node_alloc(value);
   if (l->head == NULL) {
     l->head = add_node;
     add_node->next = NULL;
   } else {
     add_node->next = l->head;
     l->head = add_node;
   }
}
 
void list_add_at_index(list_t *l, elem value, int index) {
 if (index < 0 || index > list_length(l)) {
   return;
 }
 if (index == list_length(l)) {
   list_add_to_back(l, value);
   return;
 }
 if (index == 0) {
   list_add_to_front(l, value);
   return;
 }
 int count = 0;
 node_t *add_node = node_alloc(value);
 node_t *current_node = l->head;
 add_node->value = value;
 while (count < (index - 1)) {
   current_node = current_node->next;
   count++;
 }
 add_node->next = current_node->next;
 current_node->next = add_node;
}
 
 
 

elem list_remove_from_back(list_t *l) {
 node_t *current_node = l->head;
 int val = 0;
 if (current_node == NULL) {
   return -1;
 }
 else if (l->head->next == NULL) {
     val = l->head->value;
     node_free(l->head);
     l->head = NULL;
     return val;
 }
 else {
   while (current_node->next->next != NULL){
     current_node = current_node->next;
   }
   val = current_node->value;
   node_free(current_node->next);
   current_node->next = NULL;
   return val;
 }
}

 

elem list_remove_from_front(list_t *l) {
  int val = 0;
  if (l -> head == NULL) {
     return -1;
   }
  if (l -> head -> next == NULL){
    val = l->head->value;
     node_free(l->head);
     l->head = NULL;
     return val;
  }
  node_t *temp = l->head;
  l -> head = l -> head -> next;

  free(temp);
  return l -> head -> value;
}
 
 

elem list_remove_at_index(list_t *l, int index) {
 if (index < 0 || index > list_length(l) || l->head == NULL) {
   return -1;
 }
 if (index == list_length(l)) {
   return list_remove_from_back(l);
 }
 if (index == 0) {
   return list_remove_from_front(l);
 }
 int i = -1;
 int val = 0;
 node_t *remove_node = l->head;
 node_t *current_node = l->head;
 while (i < (index - 1)) {
   current_node = remove_node;
   remove_node = remove_node->next;
   i++;
 }
 val = remove_node->value;
 current_node->next = remove_node->next;
 node_free(remove_node);
 remove_node->next = NULL;
 return val;
}
 

bool list_is_in(list_t *l, elem value) {
   node_t *current_node = l->head;
   if (current_node == NULL) {
     printf("No nodes, list is empty!\n");
     return false;
   } else {
     while (current_node != NULL) {
       if (current_node->value == value) {
         return true;
       } else {
         current_node = current_node->next;
       }
     }
   return false;
   }
}

 

elem list_get_elem_at(list_t *l, int index) {
 int val = 0;
 node_t *current_node = l->head;
 if (index < 0 || index > list_length(l) || l->head == NULL) {
   return -1;
 }
 if (index == list_length(l)) {
   while (current_node->next != NULL){
     current_node = current_node->next;
   }
   val = current_node->value;
   return val;
 }
 if (index == 0) {
   return l->head->value;
 }
 int i = 0;
 while (i < (index - 1)) {
   current_node = current_node->next;
   i++;
 }
 val = current_node->value;
 return val;
}

 
int list_get_index_of(list_t *l, elem value) {
 int val = 1;
 int length = list_length(l);
 if (l->head == NULL) {
   return -1;
 }
 if (value == l->head->value) {
   return 1;
 }
 
 if (list_is_in(l, value) == false) {
   return -1;
 } else {
     node_t *current_node = l->head;
     while (val < length && current_node->value != value) {
       current_node = current_node->next;
       val++;
     }
     return val;
 }
}
