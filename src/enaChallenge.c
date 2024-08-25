#include "enaChallenge.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct product {
  int serialNumber;
  char name[50];
  float price;
  size_t accessCounter;
} product;


typedef struct doubly_node {
  product *product;
  node *next;
  node *previous;
} doublyNode, node;


typedef struct doubly_linked_list {
  node *begin;
  node *end;
  int size;
} doublyLinkedList, list;


int totalCost = 0;


list *enaList_create() {
  list *newList = (list *) calloc(1, sizeof(list));
  newList->begin = NULL;
  newList->end = NULL;
  newList->size = 0;
  return newList;
}


node *enaNode_create() {
  node *newNode = (node *) calloc(1, sizeof(node));
  newNode->next = NULL;
  newNode->previous = NULL;
  newNode->product = NULL;
  return newNode;
} 


product *enaList_create_product(const int serial, const char name[], const float price) {
  product *newProduct = (product *) calloc (1, sizeof(product));
  newProduct->serialNumber = serial;
  strcpy(newProduct->name, name);
  newProduct->price = price;
  newProduct->accessCounter = 0;
  return newProduct;
}


bool enaList_is_empty(const list *currentList) {
  return currentList->size == 0; 
}


void enaList_add_product(list *currentList, const int serial, const char name[], const float price) {
  node *auxNode = enaNode_create();
  product *auxProduct = enaList_create_product(serial, name, price);
  auxNode->product = auxProduct;
  if (!enaList_is_empty(currentList)) { 
    node *currentNode = currentList->end;
    currentNode->next = auxNode;
    auxNode->previous = currentNode;
  }
  else {
    currentList->begin = auxNode;
  }
  currentList->end = auxNode;
  currentList->size++;
}


void attTotalCost(int *totalCost, const int cost) {
  *totalCost += cost;
}


void enaList_print(list *currentList) {
  if (!enaList_is_empty(currentList)) {
    puts("print():");
    node *currentNode = currentList->begin;
    while (currentNode != NULL) {
      printf("%d, ", currentNode->product->serialNumber);
      currentNode = currentNode->next;
    }
  }
  puts("");
  puts("");
}


void enaList_print_reverse(list *currentList) {
  if (!enaList_is_empty(currentList)) {
    puts("print_reverse():");
    node *currentNode = currentList->end;
    while (currentNode != NULL) {
      printf("%d, ", currentNode->product->serialNumber);
      currentNode = currentNode->previous;
    }
  }
  puts("");
  puts("");
}


void enaUpdatesCurrentListBegin(list *currentList, node *currentNode) {
  product *currentProduct = NULL;
  product *previousProduct = NULL;
  while (currentNode->previous != NULL) {
    previousProduct = currentNode->previous->product;
    currentProduct = currentNode->product;
    if (currentProduct->accessCounter <= previousProduct->accessCounter) {
      currentNode = currentNode->previous;
    }
  }
  currentList->begin = currentNode;
}


void enaUpdatesCurrentListEnd(list *currentList, node *currentNode) {
  product *currentProduct = NULL;
  product *nextProduct = NULL;
  while (currentNode->next != NULL) {
    nextProduct = currentNode->next->product;
    currentProduct = currentNode->product;
    if (currentProduct->accessCounter >= nextProduct->accessCounter) {
      currentNode = currentNode->next;
    }
  }
  currentList->end = currentNode;
}


void enaUpdatesTheListAfterAccessingTheProduct(node *currentNode, node *previousNode, node *nextNode, product *currentProduct, product *previousProduct) {
  while (previousNode != NULL && currentProduct->accessCounter >= previousProduct->accessCounter) {
    previousNode->next = nextNode;
    if (previousNode->previous != NULL) {
      previousNode->previous->next = currentNode;
      currentNode->previous = previousNode->previous;
      previousNode->previous = currentNode;
    } else {
      previousNode->previous = currentNode;
      currentNode->previous = NULL; 
    }
    if (nextNode != NULL) {
      nextNode->previous = previousNode;
    }
    currentNode->next = previousNode;

    previousNode = currentNode->previous;
    nextNode = currentNode->next;
    previousProduct = previousNode->product;
  }
}


void enaList_access_product(list *currentList, const int serial) {
  if (!enaList_is_empty(currentList)) {
    node *currentNode = currentList->begin;
    node *previousNode = currentNode->previous;
    node *nextNode = currentNode->next;
    product *currentProduct = currentNode->product;
    int cost = 1;
    while (currentNode != NULL) {
      currentProduct = currentNode->product;
      if (currentProduct->serialNumber == serial) {
        currentProduct->accessCounter++;
        attTotalCost(&totalCost, cost);
        printf("%d, %s, %.2f\n", currentProduct->serialNumber, currentProduct->name, currentProduct->price);
        if (currentList->begin == currentNode) {
          return;
        }
        previousNode = currentNode->previous;
        nextNode = currentNode->next;
        product *previousProduct = previousNode->product;
        enaList_print(currentList);
        enaList_print_reverse(currentList);
        while (previousNode != NULL && currentProduct->accessCounter >= previousProduct->accessCounter) {
          previousNode->next = nextNode;
          if (previousNode->previous != NULL) {
            previousNode->previous->next = currentNode;
            currentNode->previous = previousNode->previous;
            previousNode->previous = currentNode;
          } else {
            previousNode->previous = currentNode;
            currentNode->previous = NULL; 
          }
          if (nextNode != NULL) {
            nextNode->previous = previousNode;
          }
          currentNode->next = previousNode;
          previousNode = currentNode->previous;
          nextNode = currentNode->next;
          if (previousNode != NULL) {
            previousProduct = previousNode->product;
          }
          else {
            previousProduct = NULL;
          }
          enaList_print(currentList);
          enaList_print_reverse(currentList);
        }
        printf("Antes de atualizar o Begin eo End:\n");
        enaList_print(currentList);
        enaList_print_reverse(currentList);
        enaUpdatesCurrentListBegin(currentList, currentNode);
        enaUpdatesCurrentListEnd(currentList, currentNode);
        printf("Depois de atualizar o Begin eo End:\n");
        enaList_print(currentList);
        enaList_print_reverse(currentList);
        return;
      }
      cost++;
      currentNode = currentNode->next;
    }
    printf("non-existent product %d\n", serial);
  }
}

/*
void enaList_access_product(list *currentList, const int serial) {
  if (!enaList_is_empty(currentList)) {
    node *currentNode = currentList->begin;
    node *previousNode = currentNode->previous;
    node *nextNode = currentNode->next;
    product *currentProduct = currentNode->product;
    int cost = 1;
    while (currentNode != NULL) {
      currentProduct = currentNode->product;
      if (currentProduct->serialNumber == serial) {
        currentProduct->accessCounter++;
        printf("%d, %s, %.2f\n", currentProduct->serialNumber, currentProduct->name, currentProduct->price);
        attTotalCost(&totalCost, cost);
        previousNode = currentNode->previous;
        nextNode = currentNode->next;
        product *previousProduct = previousNode->product;
        updatesTheListAfterAccessingTheProduct(currentNode, previousNode, nextNode, currentProduct, previousProduct);
        enaUpdatesCurrentListBegin(currentList, currentNode);
        enaUpdatesCurrentListEnd(currentList, currentNode);
        return;
      }
      cost++;
      currentNode = currentNode->next;
    }
    printf("non-existent product %d\n", serial);
  }
}
*/

void enaList_stop(const list *currentList) {
  if (!enaList_is_empty(currentList)) {
    node *currentNode = currentList->begin;
    printf("L = (");
    for (int i = 0; i < currentList->size; ++i) {
      printf("%d, ", currentNode->product->serialNumber);
      currentNode = currentNode->next;
    }
    printf(")\n");
    printf("totalCost = %d\n", totalCost);
  }
}
