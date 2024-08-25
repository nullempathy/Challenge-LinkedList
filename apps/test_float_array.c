#include "./float_array.h"
#include <stdio.h>


int main() {
  floatArray *array = ena_create(5);
  ena_print(array);
  
  ena_append(array, 1.0);
  ena_append(array, 2.0);
  ena_append(array, 3.0);
  ena_append(array, 4.0);
  ena_append(array, 5.0);
  ena_print(array);

  ena_remove(array, 2);
  ena_print(array);
 
  floatArray *clonedArray = ena_clone(array);
  puts("");
  printf("======= array =======\n");
  ena_print(array);
  puts("");
  printf("======= clonedArray =======\n");
  ena_print(clonedArray);
  puts("");
  printf("======= array =======\n");
  ena_erase(array);
  ena_print(array);


  ena_destroy(&array);

  return 0;
}
