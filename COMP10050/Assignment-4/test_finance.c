#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "finance.h"

/* --- Suite A: Growth Logic --- */
void test_growth_zero_interest() {
    FinanceProfile p = {1000.0, 100.0, 0.0, 0.0, 0.0, 1}; // $1000 + $100/mo, 0% interest
    // Should be exactly $1000 + $1200 = $2200
    CU_ASSERT_DOUBLE_EQUAL(calculate_future_value(p), 2200.0, 0.01);
}

void test_growth_positive_interest() {
    FinanceProfile p = {1000.0, 0.0, 0.12, 0.0, 0.0, 1}; // $1000, 12% interest (1% per mo)
    // 1000 * (1.01)^12 = 1126.83
    CU_ASSERT_DOUBLE_EQUAL(calculate_future_value(p), 1126.83, 0.01);
}

void test_growth_negative_interest() {
    FinanceProfile p = {1000.0, 0.0, -0.10, 0.0, 0.0, 1}; // Market crash (-10%)
    CU_ASSERT(calculate_future_value(p) < 1000.0);
}

/* --- Suite B: Inflation and Taxes --- */
void test_tax_on_profit() {
    // $2000 total, $1000 cost = $1000 profit. 20% tax = $200
    CU_ASSERT_DOUBLE_EQUAL(calculate_tax_liability(2000.0, 1000.0, 0.20), 200.0, 0.01);
}

void test_tax_on_loss() {
    // $800 total, $1000 cost = -$200 loss. Tax should be $0
    CU_ASSERT_DOUBLE_EQUAL(calculate_tax_liability(800.0, 1000.0, 0.20), 0.0, 0.01);
}

void test_inflation_zero_rate() {
    // At 0% inflation, $100 is still worth $100
    CU_ASSERT_DOUBLE_EQUAL(adjust_for_inflation(100.0, 0.0, 5), 100.0, 0.01);
}

int main() {
    CU_initialize_registry();
    
    CU_pSuite suite1 = CU_add_suite("Investment_Growth_Suite", NULL, NULL);
    CU_add_test(suite1, "Zero_Interest_Test", test_growth_zero_interest);
    CU_add_test(suite1, "Positive_Interest_Test", test_growth_positive_interest);
    CU_add_test(suite1, "Market_Crash_Test", test_growth_negative_interest);

    CU_pSuite suite2 = CU_add_suite("Tax_and_Inflation_Suite", NULL, NULL);
    CU_add_test(suite2, "Standard_Tax_Test", test_tax_on_profit);
    CU_add_test(suite2, "Loss_Protection_Test", test_tax_on_loss);
    CU_add_test(suite2, "Zero_Inflation_Test", test_inflation_zero_rate);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}