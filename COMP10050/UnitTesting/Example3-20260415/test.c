/*
 * test.c


 *
 *  Created on: 19 Apr 2017
 *      Author: liliana
 */
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>


	void slopeZero_testcase() {
		CU_ASSERT_EQUAL(getSlope(0,5,90,5),0);
	}


	void slopeMiddle_testcase() {
		CU_ASSERT(getSlope(0,0,90,54) > 0);
		CU_ASSERT(getSlope(0,90,4,54) < 0);
	}

	void slopeError_testcase() {
		CU_ASSERT(getSlope(0,90,0,54) == -1);
	}



	void distance_testcase() {
		CU_ASSERT_EQUAL((roundf(getDistance(-2,2, 2,-2)*100)/100.00), 5.66);
		CU_ASSERT_EQUAL((roundf(getDistance(2,2, -2,-2)*100)/100.00), 5.66);
		CU_ASSERT_EQUAL(getDistance(-2,0, 2, 0), 4);
		CU_ASSERT_EQUAL(getDistance(0,2, 0, -2), 4);

		CU_ASSERT_EQUAL(getDistance(2,-2, 2, -2),0);
	}



void runAllTests(){

	printf("%f\n",roundf(getDistance(-2,2, 2,-2)*100)/100.00);
	CU_initialize_registry();
	CU_pSuite suiteSlope = CU_add_suite("slope_suite", 0, 0);

	CU_add_test(suiteSlope, "slopeZero_test", slopeZero_testcase);
	CU_add_test(suiteSlope, "slopeMiddle_test", slopeMiddle_testcase);
	CU_add_test(suiteSlope, "slopeError_test", slopeError_testcase);

	CU_pSuite suiteDistance = CU_add_suite("slope_distance", 0, 0);
	CU_add_test(suiteDistance, "distance_test", distance_testcase);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}

int main() {
    runAllTests();
    return 0;
}
