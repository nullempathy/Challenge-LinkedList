#include "enaChallenge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
  list *currentList = enaList_create();
  enaList_print(currentList);
  enaList_print_reverse(currentList);
  
  printf("enaList_add_product(currentList, 1, Playstation5, 4999.99)\n");
  enaList_add_product(currentList, 1, "Playstation5", 4999.99);
  enaList_print(currentList);
  enaList_print_reverse(currentList);

  puts("");
  puts("");

  printf("enaList_add_product(currentList, 2, Lapiseira, 5.00)\n");
  enaList_add_product(currentList, 2, "Lapiseira", 5.00);
  enaList_print(currentList);
  enaList_print_reverse(currentList);

  puts("");
  puts("");
  
  printf("enaList_add_product(currentList, 3, BolaDeFutebol, 89.90)\n");
  enaList_add_product(currentList, 3, "BolaDeFutebol", 89.90);
  enaList_print(currentList);
  enaList_print_reverse(currentList);


  puts("");
  puts("");
  puts("");
  puts("");


  printf("enaList_access_product(currentList, 99)\n");
  enaList_access_product(currentList, 99);
  enaList_print(currentList);
  enaList_print_reverse(currentList);

  puts("");
  puts("");
  
  printf("enaList_access_product(currentList, 6)\n");
  enaList_access_product(currentList, 6);
  enaList_print(currentList);
  enaList_print_reverse(currentList);


  puts("");
  puts("");
  puts("");
  puts("");


  printf("enaList_add_product(currentList, 4, MouseGamer, 120.00)\n");
  enaList_add_product(currentList, 4, "MouseGamer", 120.00);
  enaList_print(currentList);
  enaList_print_reverse(currentList);
  
  puts("");
  puts("");
  
  printf("enaList_add_product(currentList, 5, Chiclete, 0.99)\n");
  enaList_add_product(currentList, 5, "Chiclete", 0.99);
  enaList_print(currentList);
  enaList_print_reverse(currentList);
  

  puts("");
  puts("");
  puts("");
  puts("");


  printf("enaList_access_product(currentList, 4)\n");
  enaList_access_product(currentList, 4);
  enaList_print(currentList);
  enaList_print_reverse(currentList);

  puts("");
  puts("");
  
  printf("enaList_access_product(currentList, 2)\n");
  enaList_access_product(currentList, 2);
  enaList_print(currentList);
  enaList_print_reverse(currentList);


  puts("");
  puts("");
  puts("");
  puts("");


  printf("enaList_add_product(currentList, 6, Chupeta, 31.47)\n");
  enaList_add_product(currentList, 6, "Chiclete", 31.47);
  enaList_print(currentList);
  enaList_print_reverse(currentList);
  

  puts("");
  puts("");
  puts("");
  puts("");


  printf("enaList_access_product(currentList, 100)\n");
  enaList_access_product(currentList, 100);
  enaList_print(currentList);
  enaList_print_reverse(currentList);

  puts("");
  puts("");

  printf("enaList_access_product(currentList, 6)\n");
  enaList_access_product(currentList, 6);
  enaList_print(currentList);
  enaList_print_reverse(currentList);

  puts("");
  puts("");
  
  printf("enaList_access_product(currentList, 1)\n");
  enaList_access_product(currentList, 1);
  enaList_print(currentList);
  enaList_print_reverse(currentList);
  
  puts("");
  puts("");
  
  printf("enaList_access_product(currentList, 3)\n");
  enaList_access_product(currentList, 3);
  enaList_print(currentList);
  enaList_print_reverse(currentList);


  puts("");
  puts("");
  puts("");
  puts("");


  printf("enaList_add_product(currentList, 7, Game_Fifa_2021, 249.99)\n");
  enaList_add_product(currentList, 7, "Game_Fifa_2021", 249.99);
  enaList_print(currentList);
  enaList_print_reverse(currentList);


  puts("");
  puts("");
  puts("");
  puts("");


  printf("enaList_access_product(currentList, 1)\n");
  enaList_access_product(currentList, 1);
  enaList_print(currentList);
  enaList_print_reverse(currentList);
  
  puts("");
  puts("");
  
  printf("enaList_access_product(currentList, 7)\n");
  enaList_access_product(currentList, 7);
  enaList_print(currentList);
  enaList_print_reverse(currentList);
  
  enaList_stop(currentList);

  return 0;
}
