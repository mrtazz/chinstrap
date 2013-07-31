#include <stdlib.h>
#include <check.h>

Suite* scanner_suite (void);

int
main (void)
{
  int number_failed = 0;
  typedef Suite* (*SuiteFun) (void);
  SuiteFun suites[] = {
          scanner_suite,
  };
  for (size_t i = 0; i < sizeof(suites)/sizeof(suites[0]); ++i) {
      SRunner *sr = srunner_create (suites[i]());
      srunner_run_all (sr, CK_NORMAL);
      number_failed += srunner_ntests_failed (sr);
      srunner_free (sr);
  }
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
