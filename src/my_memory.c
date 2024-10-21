#include "my_memory.h"
#include "stdbool.h"
#include <stdint.h>
#include <stdio.h>

void init() { MY_HEAP[0] = 1; }

void *my_malloc0(size_t size) {
  uint8_t size_with_meta = size + 2;
  uint8_t size_with_alignment = size_with_meta + size_with_meta % 4;

  MY_HEAP[0] = size_with_alignment;

  return (void *)MY_HEAP;
}

void *my_malloc(size_t size) {
  uint8_t size_with_meta = size + 2;
  uint8_t size_with_alignment = size_with_meta + size_with_meta % 4;

  bool found_block = false;
  uint8_t *current_block = MY_HEAP;
  while (!found_block) {
    if (is_block_free(current_block)) {
      found_block = true;
    }
  }

  *current_block = size_with_alignment;

  return current_block;
}

void print_state(int max) {
  for (int i = 0; (i < max); i++) {
    if (i >= 64000)
      break;
    printf("%d, ", MY_HEAP[i]);
  }
  printf("\n");
}

void my_free(void *ptr) { *(uint8_t *)ptr |= 1; }

bool is_block_free(void *ptr) { return *(uint8_t *)ptr & 1; }
