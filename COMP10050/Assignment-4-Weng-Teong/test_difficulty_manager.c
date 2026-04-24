
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <math.h>
#include "difficulty_manager.h"

// Suite 1: Is Level Valid?

void test_all_levels_valid(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        CU_ASSERT_TRUE(is_level_valid(lvl));
    }
}

void test_invalid_level(void) {
    CU_ASSERT_FALSE(is_level_valid(0));
    CU_ASSERT_FALSE(is_level_valid(-5));
    CU_ASSERT_FALSE(is_level_valid(101));
}

// Suite 2: Fast Enemy

void test_fast_enemy_invalid_level_returns_zero(void) {
    FastEnemy e = calculate_fast_enemy(0);
    CU_ASSERT_EQUAL(e.health, 0);
    CU_ASSERT_EQUAL(e.speed, 0);
}

void test_fast_enemy_health_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        FastEnemy e = calculate_fast_enemy(lvl);
        double expected = 40.0 * pow(1.08, (double)lvl);
        CU_ASSERT_EQUAL((round(e.health * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_fast_enemy_speed_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        FastEnemy e = calculate_fast_enemy(lvl);
        double raw = 8.0 + ((double)lvl * 0.6);
        double expected = (raw > 18.0) ? 18.0 : raw;
        CU_ASSERT_EQUAL((round(e.speed * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_fast_enemy_speed_never_exceeds_cap(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        FastEnemy e = calculate_fast_enemy(lvl);
        CU_ASSERT_TRUE(e.speed <= 18.0);
    }
}

void test_fast_enemy_attack_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        FastEnemy e = calculate_fast_enemy(lvl);
        int expected = 5 + (lvl * 1);
        CU_ASSERT_EQUAL(e.attack_power, expected);
    }
}

void test_fast_enemy_knockback_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        FastEnemy e = calculate_fast_enemy(lvl);
        double expected = 1.2 + ((double)lvl * 0.02);
        CU_ASSERT_EQUAL((round(e.knockback * 100) / 100), (round(expected * 100) / 100));

    }
}

void test_fast_enemy_coin_drop_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        FastEnemy e = calculate_fast_enemy(lvl);
        int expected = 5 + (lvl * 2);
        CU_ASSERT_EQUAL(e.coin_drop, expected);
    }
}

// Suite 3: Normal Enemy

void test_normal_enemy_invalid_level_returns_zero(void) {
    NormalEnemy e = calculate_normal_enemy(0);
    CU_ASSERT_EQUAL(e.health, 0);
    CU_ASSERT_EQUAL(e.speed, 0);
}

void test_normal_enemy_health_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        NormalEnemy e = calculate_normal_enemy(lvl);
        double expected = 100.0 * pow(1.12, (double)lvl);
        CU_ASSERT_EQUAL((round(e.health * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_normal_enemy_speed_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        NormalEnemy e = calculate_normal_enemy(lvl);
        double raw = 5.0 + ((double)lvl * 0.3);
        double expected = (raw > 12.0) ? 12.0 : raw;
        CU_ASSERT_EQUAL((round(e.speed * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_normal_enemy_speed_never_exceeds_cap(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        NormalEnemy e = calculate_normal_enemy(lvl);
        CU_ASSERT_TRUE(e.speed <= 12.0);
    }
}

void test_normal_enemy_attack_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        NormalEnemy e = calculate_normal_enemy(lvl);
        int expected = 10 + (lvl * 3);
        CU_ASSERT_EQUAL(e.attack_power, expected);
    }
}

void test_normal_enemy_knockback_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        NormalEnemy e = calculate_normal_enemy(lvl);
        double expected = 2.5 + ((double)lvl * 0.05);
        CU_ASSERT_EQUAL((round(e.knockback * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_normal_enemy_coin_drop_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        NormalEnemy e = calculate_normal_enemy(lvl);
        int expected = 10 + (lvl * 4);
        CU_ASSERT_EQUAL(e.coin_drop, expected);
    }
}


// Suite 4: Tanky enemy

void test_tanky_enemy_invalid_level_returns_zero(void) {
    TankyEnemy e = calculate_tanky_enemy(0);
    CU_ASSERT_EQUAL(e.health, 0);
    CU_ASSERT_EQUAL(e.speed, 0);
}

void test_tanky_enemy_health_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        TankyEnemy e = calculate_tanky_enemy(lvl);
        double expected = 250.0 * pow(1.18, (double)lvl);
        CU_ASSERT_EQUAL((round(e.health * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_tanky_enemy_speed_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        TankyEnemy e = calculate_tanky_enemy(lvl);
        double raw = 2.0 + ((double)lvl * 0.1);
        double expected = (raw > 6.0) ? 6.0 : raw;
        CU_ASSERT_EQUAL((round(e.speed * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_tanky_enemy_speed_never_exceeds_cap(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        TankyEnemy e = calculate_tanky_enemy(lvl);
        CU_ASSERT_TRUE(e.speed <= 6.0);
    }
}

void test_tanky_enemy_attack_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        TankyEnemy e = calculate_tanky_enemy(lvl);
        int expected = 25 + (lvl * 8);
        CU_ASSERT_EQUAL(e.attack_power, expected);
    }
}

void test_tanky_enemy_knockback_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        TankyEnemy e = calculate_tanky_enemy(lvl);
        double expected = 5.0 + ((double)lvl * 0.2);
        CU_ASSERT_EQUAL((round(e.knockback * 100) / 100), (round(expected * 100) / 100));
    }
}

void test_tanky_enemy_coin_drop_all_levels(void) {
    for (int lvl = 1; lvl <= 100; lvl++) {
        TankyEnemy e = calculate_tanky_enemy(lvl);
        int expected = 30 + (lvl * 10);
        CU_ASSERT_EQUAL(e.coin_drop, expected);
    }
}


int main(void) {
    CU_initialize_registry();

    // Suite 1: is_level_valid
    CU_pSuite s_valid = CU_add_suite("Suite_isLevelValid", 0, 0);
    CU_add_test(s_valid, "all levels 1-100 are valid",    test_all_levels_valid);
    CU_add_test(s_valid, "invalid: level",           test_invalid_level);

    // Suite 2: FastEnemy
    CU_pSuite s_fast = CU_add_suite("Suite_FastEnemy", 0, 0);
    CU_add_test(s_fast, "invalid level returns zero struct",        test_fast_enemy_invalid_level_returns_zero);
    CU_add_test(s_fast, "health formula correct (levels 1-100)",    test_fast_enemy_health_all_levels);
    CU_add_test(s_fast, "speed formula correct (levels 1-100)",     test_fast_enemy_speed_all_levels);
    CU_add_test(s_fast, "speed never exceeds cap (levels 1-100)",   test_fast_enemy_speed_never_exceeds_cap);
    CU_add_test(s_fast, "attack power correct (levels 1-100)",      test_fast_enemy_attack_all_levels);
    CU_add_test(s_fast, "knockback correct (levels 1-100)",         test_fast_enemy_knockback_all_levels);
    CU_add_test(s_fast, "coin drop correct (levels 1-100)",         test_fast_enemy_coin_drop_all_levels);

    // Suite 3: NormalEnemy
    CU_pSuite s_normal = CU_add_suite("Suite_NormalEnemy", 0, 0);
    CU_add_test(s_normal, "invalid level returns zero struct",        test_normal_enemy_invalid_level_returns_zero);
    CU_add_test(s_normal, "health formula correct (levels 1-100)",    test_normal_enemy_health_all_levels);
    CU_add_test(s_normal, "speed formula correct (levels 1-100)",     test_normal_enemy_speed_all_levels);
    CU_add_test(s_normal, "speed never exceeds cap (levels 1-100)",   test_normal_enemy_speed_never_exceeds_cap);
    CU_add_test(s_normal, "attack power correct (levels 1-100)",      test_normal_enemy_attack_all_levels);
    CU_add_test(s_normal, "knockback correct (levels 1-100)",         test_normal_enemy_knockback_all_levels);
    CU_add_test(s_normal, "coin drop correct (levels 1-100)",         test_normal_enemy_coin_drop_all_levels);

    // Suite 4: TankyEnemy
    CU_pSuite s_tanky = CU_add_suite("Suite_TankyEnemy", 0, 0);
    CU_add_test(s_tanky, "invalid level returns zero struct",        test_tanky_enemy_invalid_level_returns_zero);
    CU_add_test(s_tanky, "health formula correct (levels 1-100)",    test_tanky_enemy_health_all_levels);

    CU_add_test(s_tanky, "speed formula correct (levels 1-100)",     test_tanky_enemy_speed_all_levels);
    CU_add_test(s_tanky, "speed never exceeds cap (levels 1-100)",   test_tanky_enemy_speed_never_exceeds_cap);
    CU_add_test(s_tanky, "attack power correct (levels 1-100)",      test_tanky_enemy_attack_all_levels);
    CU_add_test(s_tanky, "knockback correct (levels 1-100)",         test_tanky_enemy_knockback_all_levels);
    CU_add_test(s_tanky, "coin drop correct (levels 1-100)",         test_tanky_enemy_coin_drop_all_levels);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}
