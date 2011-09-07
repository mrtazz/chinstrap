#include <CUnit/Basic.h>

extern int init_scanner_suite(void);
extern int clean_scanner_suite(void);
extern void test_scanner_init_with_length(void);
extern void test_scanner_init_without_length(void);

int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("scanner tests", init_scanner_suite,
                         clean_scanner_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "scanner init with length", test_scanner_init_with_length)) ||
       (NULL == CU_add_test(pSuite, "scanner init without length", test_scanner_init_without_length))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   //CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_automated_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
