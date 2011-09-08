#include <check.h>
#include <string.h>
#include "chinstrap/scanner.h"

START_TEST (test_scanner_init_with_length)
{
  scanner s = scanner_init("foobar", 6);
  fail_unless(s.current_row == 0);
  fail_unless(s.current_col == 0);
  fail_unless(strcmp(s.thetemplate, "foobar"));
  fail_unless(s.template_length == 6);
  fail_unless(s.pos == 0);
}
END_TEST


START_TEST (test_scanner_init_without_length)
{
  scanner s = scanner_init("foobar", -1);
  fail_unless(s.current_row == 0);
  fail_unless(s.current_col == 0);
  fail_unless(strcmp(s.thetemplate, "foobar"));
  fail_unless(s.template_length == 6);
  fail_unless(s.pos == 0);
}
END_TEST

Suite *
scanner_suite (void)
{
  Suite *s = suite_create ("Scanner");

  /* Core test case */
  TCase *tc_core = tcase_create ("Core");
  tcase_add_test (tc_core, test_scanner_init_with_length);
  tcase_add_test (tc_core, test_scanner_init_without_length);
  suite_add_tcase (s, tc_core);

  return s;
}
