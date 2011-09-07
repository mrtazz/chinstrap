#include "CUnit/Basic.h"
#include "chinstrap/scanner.h"
#include <string.h>


static scanner s;
static scanner s2;

int init_scanner_suite(void)
{
  s = scanner_init("foobar", 6);
  s2 = scanner_init("foobar", -1);
  return 0;
}

int clean_scanner_suite(void)
{
  return 0;
}

void test_scanner_init_with_length(void)
{
  CU_ASSERT(s.current_row == 0);
  CU_ASSERT(s.current_col == 0);
  CU_ASSERT(strcmp(s.thetemplate, "foobar"));
  CU_ASSERT(s.template_length == 6);
  CU_ASSERT(s.pos == 0);
}

void test_scanner_init_without_length(void)
{
  CU_ASSERT(s.current_row == 0);
  CU_ASSERT(s.current_col == 0);
  CU_ASSERT(strcmp(s.thetemplate, "foobar"));
  CU_ASSERT(s.template_length == 6);
  CU_ASSERT(s.pos == 0);
}
