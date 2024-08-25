#include "./float_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



/**************** PRIVATE INTERFACE IMPLEMENTATION ****************/
struct float_array {
  int capacity; // maximum numbers of elements
  int size; // amount of elements stored
  float *data; // float array
};

bool ena_isFull(const floatArray *array) {
  return array->size == array->capacity;
}

void ena_verifyIndex(const floatArray *array, int index) {
  if (index < 0 || index >= array->size) {
    fprintf(stderr, "ERROR check the functions 'ena_at' 'ena_set' 'ena_remove'\n");
    fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, array->size - 1);
    exit(EXIT_FAILURE);
  }
}

/**************** PUBLIC INTERFACE IMPLEMENTATION ****************/
floatArray *ena_create(int capacity) {
  floatArray *array = (floatArray *) calloc(1, sizeof(floatArray));
  array->capacity = capacity;
  array->size = 0;
  array->data = (float *) calloc(array->capacity, sizeof(float));
  return array;
}

void ena_destroy(floatArray **arrayReference) {
  floatArray *aux = *arrayReference;
  free(aux->data);
  free(aux);
  *arrayReference = NULL;
}

int ena_size(const floatArray *array) {
  return array->size;
}

int ena_capacity(const floatArray *array) {
  return array->capacity; 
}

float ena_at(const floatArray *array, int index) {
  ena_verifyIndex(array, index);
  return array->data[index];
}

float ena_get(const floatArray *array, int index) {
  return array->data[index];
}

void ena_append(floatArray *array, float value) {
  if(ena_isFull(array)) {
    fprintf(stderr, "ERROR in 'ena_append'\n");
    fprintf(stderr, "Array is full\n");
    exit(EXIT_FAILURE);
  } else {
    array->data[array->size++] = value;
  }
}

void ena_set(floatArray *array, int index, float value) {
  ena_verifyIndex(array, index);
  array->data[index] = value;
}

void ena_print(const floatArray *array) {
  printf("capacity of array: %d\n", array->capacity);
  printf("size of array: %d\n", array->size);
  puts("elements of array:\n");
  for (int i = 0; i < array->size; ++i) {
    printf("array->data[%d] = %f\n", i, array->data[i]);
  }
  puts("");
}

void ena_remove(floatArray *array, int index) {
  ena_verifyIndex(array, index);
  for (int i = index; i < array->size - 1; ++i) {
    array->data[i] = array->data[i+1];
  }
  array->size = array->size - 1;
}

void ena_erase(floatArray *array) {
  array->size = 0;
}

floatArray *ena_clone(const floatArray *array) {
  floatArray *newArray = (floatArray *) calloc(1, sizeof(floatArray));
  newArray->capacity = array->capacity;
  newArray->size = array->size;
  newArray->data = (float *) calloc(newArray->capacity, sizeof(float));
  for (int i = 0; i < newArray->size; ++i) {
    newArray->data[i] = array->data[i];
  }
  return newArray;
}
