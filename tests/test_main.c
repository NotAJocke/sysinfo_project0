#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <cmocka.h>

extern void test_malloc_basic(void **state);
extern void test_malloc_multiple(void **state);

int main() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_malloc_basic),
      cmocka_unit_test(test_malloc_multiple),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
