#include <check.h>
#include <string.h>
#include "chinstrap/scanner.h"

START_TEST (test_scanner_init_with_length)
{
  scanner s = scanner_init("foobar", 6);
  fail_unless(s.current_row == 0);
  fail_unless(s.current_col == 0);
  fail_unless(!strcmp(s.thetemplate, "foobar"));
  fail_unless(s.template_length == 6);
  fail_unless(s.pos == 0);
}
END_TEST


START_TEST (test_scanner_init_without_length)
{
  scanner s = scanner_init("foobar", -1);
  fail_unless(s.current_row == 0);
  fail_unless(s.current_col == 0);
  fail_unless(!strcmp(s.thetemplate, "foobar"));
  fail_unless(s.template_length == 6);
  fail_unless(s.pos == 0);
}
END_TEST

START_TEST (test_scanner_get_char)
{
  scanner s = scanner_init("foobar", 6);
  scanner_token t = get_char(&s);
  fail_unless(s.current_row == 0);
  fail_unless(s.current_col == 1);
  fail_unless(!strcmp(s.thetemplate, "foobar"));
  fail_unless(s.template_length == 6);
  fail_unless(s.pos == 1);
  fail_unless(t.row == 0);
  fail_unless(t.col == 1);
  fail_unless(t.cargo == 'f');
}
END_TEST

START_TEST (test_scanner_get_char_with_newline)
{
  scanner s = scanner_init("foo\nbar", 7);
  get_char(&s);
  get_char(&s);
  get_char(&s);
  scanner_token t = get_char(&s);
  fail_unless(s.current_row == 1);
  fail_unless(s.current_col == 1);
  fail_unless(!strcmp(s.thetemplate, "foo\nbar"));
  fail_unless(s.template_length == 7);
  fail_unless(s.pos == 5);
  fail_unless(t.row == 1);
  fail_unless(t.col == 1);
  fail_unless(t.cargo == 'b');
}
END_TEST

#include<stdio.h>
START_TEST (test_scanner_reach_end_of_template)
{
  const char foo[6] = { 'f', 'o', 'o', '\0', 7, 7};
  scanner s = scanner_init(foo, 3);
  get_char(&s);
  get_char(&s);
  get_char(&s);
  get_char(&s);
  scanner_token t = get_char(&s);
  fail_unless(t.cargo == '\0');
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
  tcase_add_test (tc_core, test_scanner_get_char);
  tcase_add_test (tc_core, test_scanner_get_char_with_newline);
  tcase_add_test (tc_core, test_scanner_reach_end_of_template);
  suite_add_tcase (s, tc_core);

  return s;
}
