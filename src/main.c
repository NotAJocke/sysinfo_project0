#include "my_memory.h"
#include <stdint.h>
#include <stdio.h>

void printb(char *name, bool value) {
  printf("%s is %s\n", name, value ? "true" : "false");
}

int main() {
  init();

  printf("Initial memory state:\n");
  print_state(50);
  printf("\n\n");

  int *five = my_malloc(sizeof(int));

  printf("memory after malloc int:\n");
  print_state(50);
  printf("\n\n");

  *five = 5000;

  printf("memory after dereferencing and adding 5000:\n");
  print_state(50);
  printf("\n\n");

  printf("Value stored in memory:\n");
  printf("%d\n", *five);
  printf("\n\n");

  printf("After the free\n");
  my_free(five);
  print_state(50);
  printf("\n\n");

  five = my_malloc(sizeof(uint8_t));
  printf("memory after malloc uint8:\n");
  print_state(50);
  printf("\n\n");

  *five = 600;

  printf("memory after dereferencing and adding 600:\n");
  print_state(50);
  printf("\n\n");

  return 0;
}
