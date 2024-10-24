#include "my_memory.h"
#include "stdbool.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void init() { memset(MY_HEAP, 0, 64000); }

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
  int global_index = 0;
  while (!found_block) {
    if (is_block_free(current_block)) {
      found_block = true;
    } else {
      uint8_t block_size = (*current_block) - 1;
      global_index += block_size;
      current_block = &MY_HEAP[global_index];
    }
  }

  *current_block = size_with_alignment + 1;
  MY_HEAP[global_index + size_with_alignment - 1] = size_with_alignment + 1;

  return current_block + 1;
}

void print_state(int max) {
  for (int i = 0; (i < max); i++) {
    if (i >= 64000)
      break;
    printf("%d, ", MY_HEAP[i]);
  }
  printf("\n");
}

void my_free(void *ptr) {
  uint8_t block_size = *((uint8_t *)ptr - 1) - 1;

  // Mark first metadata as free
  *((uint8_t *)ptr - 1) ^= 1;

  // Mark second metadata as free
  MY_HEAP[block_size - 1] ^= 1;
}

bool is_block_free(void *ptr) {
  int metadata = *(uint8_t *)ptr;

  int least_sign = metadata & 1;

  return !least_sign;
}
