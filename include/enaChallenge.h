#ifndef ENA_CHALLENGE_H
#define ENA_CHALLENGE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct product product;
typedef struct doubly_node doublyNode, node;
typedef struct doubly_linked_list doublyLinkedList, list;

list *enaList_create();
bool enaList_is_empty(const list *currentList);
void enaList_add_product(list *currentList, const int serial, const char name[], const float price);
void enaList_access_product(list *currentList, const int serial);
void enaList_stop(const list *currentList);
void enaUpdatesCurrentListBegin(list *currentList, node *currentNode);
void enaUpdatesCurrentListEnd(list *currentList, node *currentNode);
void enaList_print(list *currentList);
void enaList_print_reverse(list *currentList);


#endif
