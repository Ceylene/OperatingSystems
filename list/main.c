#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t *list1;
  list1 = list_alloc();
  list_print(list1);
  list_add_to_front(list1, 1);
  list_add_to_front(list1, 2);
  list_add_to_front(list1, 3);
  list_add_to_front(list1, 4);
  list_add_to_front(list1, 5);
  list_add_to_front(list1, 6);
  list_print(list1);

  printf("The length of this list is now %d. \n", list_length(list1));

  list_add_to_back(list1, 10);
  list_print(list1);
  list_add_to_front(list1, 20);
  list_add_to_back(list1, 30);
  list_add_to_front(list1, 40);
  list_add_to_back(list1, 50);
  list_add_to_front(list1, 60);
  list_print(list1);
  list_free(list1);
  list_print(list1);

  printf("The length of this list is now %d. \n", list_length(list1));

  list_add_at_index(list1, 100, 6);
  list_add_at_index(list1, 200, 4);
  list_add_at_index(list1, 300, 2);
  list_add_at_index(list1, 400, 8);
  list_print(list1);

  printf("The length of this list is now %d. \n", list_length(list1));

  list_remove_from_front(list1);
  list_print(list1);
  list_remove_from_back(list1);
  list_print(list1);
  list_remove_from_front(list1);
  list_print(list1);
  
  printf("The length of this list is now %d. \n", list_length(list1));

  list_remove_at_index(list1, -3);
  list_print(list1);
  list_remove_at_index(list1, 1);
  list_print(list1);
  list_remove_at_index(list1, 7);
  list_print(list1);
  list_add_to_front(list1, 67);
  list_print(list1);
  
  printf("The length of this list is now %d. \n", list_length(list1));

  list_free(list1);
  list_free(list1);

  list_print(list1);
  list_add_to_back(list1, 45);
  list_print(list1);

  printf("The length of this list is now %d. \n", list_length(list1));
  
  printf("Is %d in the list?: %d\n", 21, list_is_in(list1, 21));
  list_print(list1);
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(list1, 3));
  printf("Index of %d?: %d\n", 70, list_get_index_of(list1, 70));
  printf("Index of %d?: %d\n", 81, list_get_index_of(list1, 81)); 


 list_free(list1);
 list_add_at_index(list1, -1, -1);
 list_print(list1);
 list_add_at_index(list1, -1, -1);
 list_print(list1);
 list_add_at_index(list1, 10, 0);
 list_print(list1);
 list_add_at_index(list1, 20, 1);
 list_print(list1);
 list_free(list1);
 printf("The list length is %d\n", list_length(list1));
 list_print(list1);


 list_remove_from_back(list1);
 list_remove_from_front(list1);
 list_remove_at_index(list1, -3);
 list_remove_at_index(list1, 0);
 list_remove_at_index(list1, 2);
 list_add_to_front(list1, 10);
 list_add_to_front(list1, 20);
 list_add_to_front(list1, 30);
 list_add_to_front(list1, 40);
 list_add_to_front(list1, 60);
 list_add_at_index(list1, 50, 1);
 list_add_at_index(list1, 0, 6);
 list_add_at_index(list1, 70, 0);
 list_add_at_index(list1, 80, 12);
 list_print(list1);
  
 list_free(list1);
 list_free(list1);
 list_add_to_back(list1, 100);
 list_print(list1);
 list_remove_from_front(list1);
 list_print(list1);
 list_add_to_back(list1, 13); 
 list_print(list1);
 list_remove_from_back(list1);
 list_print(list1);


 list_add_to_front(list1, 10);
 list_add_to_front(list1, 20);
 list_add_to_front(list1, 30);
 list_add_to_front(list1, 40);
 list_add_to_front(list1, 60);
 list_print(list1);
 list_remove_at_index(list1, 0);
 list_print(list1);
 list_remove_at_index(list1, -2);
 list_print(list1);
 list_remove_at_index(list1, 7);
 list_print(list1);
 list_remove_at_index(list1, 4);
 list_print(list1);
 

 list_free(list1);
 list_print(list1);
 list_remove_at_index(list1, 0);
 list_print(list1);
 list_add_to_front(list1, 60);
 list_print(list1);
 list_remove_at_index(list1, 1);
 list_print(list1);
 list_add_to_front(list1, 80);
 list_print(list1);
 list_remove_at_index(list1, 0);
 list_print(list1);


  printf("Is %d in the list?: %d\n", 60, list_is_in(list1, 60));
 list_add_to_back(list1, 50);
 list_add_to_back(list1, 60);
 list_add_to_back(list1, 70);
 list_add_to_back(list1, 80);
 list_add_to_back(list1, 90);
 list_print(list1);
 printf("Is %d in the list?: %d\n", 30, list_is_in(list1, 30));
 printf("Is %d in the list?: %d\n", 60, list_is_in(list1, 60));
 printf("Is %d in the list?: %d\n", 80, list_is_in(list1, 80));
 list_add_to_back(list1, 70);
 list_print(list1);
 printf("Is %d in the list?: %d\n", 70, list_is_in(list1, 70));
  printf("The list length is %d\n", list_length(list1));
 list_print(list1);
 printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(list1, -4));
 printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(list1, 10));
 printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(list1, 6));
 printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(list1, 5));
 printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(list1, 0));
 list_free(list1);
 list_print(list1);
 printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(list1, 0));
 list_remove_at_index(list1, 0);
 printf("Is %d in the list?: %d\n", 21, list_is_in(list1, 21));
 printf("Index of %d?: %d\n", 21, list_get_index_of(list1, 21));
 list_add_to_front(list1, 10);
 list_add_to_front(list1, 20);
 list_add_to_front(list1, 30);
 list_add_to_front(list1, 40);
 list_add_to_front(list1, 50);
 list_print(list1);

  printf("Index of %d?: %d\n", 50, list_get_index_of(list1, 50));
 printf("Index of %d?: %d\n", 81, list_get_index_of(list1, 81));
 printf("Index of %d?: %d\n", 10, list_get_index_of(list1, 10));
 printf("Index of %d?: %d\n", 30, list_get_index_of(list1, 30));
 list_add_to_front(list1, 60);
 list_print(list1);
 printf("Index of %d?: %d\n", 50, list_get_index_of(list1, 50));
 printf("Index of %d?: %d\n", 60, list_get_index_of(list1, 60));
 list_add_to_front(list1, 10);
 list_print(list1);
 printf("Index of %d?: %d\n", 10, list_get_index_of(list1, 10));
 list_add_to_back(list1, 40);
 list_print(list1);
 printf("Index of %d?: %d\n", 40, list_get_index_of(list1, 40));

  return 0;
  
}