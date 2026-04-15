/*
 * test.c
 *
 *  Created on: 17 Apr 2017
 *      Author: liliana
 */

#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>

void triangle_testcase1(void){
	CU_ASSERT(strcmp("Equilateral", checkTriangle(60,60,60)) == 0);
	CU_ASSERT_STRING_EQUAL("Right", checkTriangle(40,90,50));
	CU_ASSERT_STRING_NOT_EQUAL("Right", checkTriangle(80,80,50));

}

void runAllTests(){
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("triangle_suite", 0, 0);

	CU_add_test(suite, "triangle_test", triangle_testcase1);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}

int main() {
    runAllTests();

    return 0;
}

