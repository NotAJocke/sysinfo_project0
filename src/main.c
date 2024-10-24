#include "my_memory.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

void printb(char *name, bool value) {
  printf("%s is %s\n", name, value ? "true" : "false");
}

int main() {
  // init();

  printf("Initial memory state:\n");
  print_state(50);
  printf("\n\n");

  int *n1 = my_malloc(sizeof(int));

  printf("After malloc:\n");

  print_state(50);
  printf("\n\n");

  *n1 = INT_MAX;

  printf("Adding INT_MAX:\n");
  print_state(50);
  printf("\n\n");

  int *n2 = my_malloc(sizeof(int));

  printf("After malloc 2:\n");
  print_state(50);
  printf("\n\n");

  *n2 = 2;

  printf("Adding 2:\n");
  print_state(50);
  printf("\n\n");

  my_free(n1);

  printf("After free n1:\n");
  print_state(50);
  printf("\n\n");

  int *n3 = my_malloc(sizeof(int));
  *n3 = 280;

  printf("After malloc 3 && insert 280 :\n");
  print_state(50);
  printf("\n\n");

  return 0;
}
