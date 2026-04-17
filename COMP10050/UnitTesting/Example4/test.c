#include <stdio.h>
#include "rectangle.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void area_test_case() {
    CU_ASSERT_EQUAL(getArea(5, 4), 20);
}

void is_square_test_case() {
    CU_ASSERT_EQUAL(isSquare(5, 5), 1);
    CU_ASSERT_EQUAL(isSquare(2, 5), 0);
}

void runAllTests(){
	CU_initialize_registry();
	CU_pSuite suiteArea = CU_add_suite("area_suite", 0, 0);

	CU_add_test(suiteArea, "area_test", area_test_case);


	CU_pSuite suiteIsSquare = CU_add_suite("is_square_suite", 0, 0);
	CU_add_test(suiteIsSquare, "is_square_test", is_square_test_case);


	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}

int main(void) {
    runAllTests();
    return 0;
}