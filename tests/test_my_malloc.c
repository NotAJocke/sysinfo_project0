#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include "cmocka.h"
#include "my_memory.h"

/**
 * Really basic test that only malloc on the first block of
 * the heap
 */
void test_malloc_basic(void **state) {
  (void)state;

  // init the memory
  init();

  // asking for memory for an int (4 bytes on my syst.)
  int *number = my_malloc(sizeof(int));

  // Need to recast and get the previous case
  // to access metadata
  assert_false(is_block_free((uint8_t *)number - 1));

  // storing an int that is higher than a byte so it needs
  // to store it on multiple cells
  *number = 10000;

  // checking if I get back the same number
  assert_int_equal(10000, *number);

  // freeing the ptr
  my_free(number);
  assert_true(is_block_free((uint8_t *)number - 1));
}

void test_malloc_multiple(void **state) {
  (void)state;

  init();

  int *number = my_malloc(sizeof(int));

  *number = 10000;

  int *number2 = my_malloc(sizeof(int));
  *number2 = 300;

  assert_int_equal(10000, *number);
  assert_int_equal(300, *number2);

  my_free(number);
  number = NULL;

  int *number3 = my_malloc(sizeof(int));
  *number3 = 480;

  assert_int_equal(480, *number3);
  assert_int_equal(300, *number2);
}
