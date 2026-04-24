/**
 * @file difficulty_manager.c
 * @brief Implementation of specialized enemy scaling.
 */

#include "difficulty_manager.h"
#include <stdio.h>
#include <math.h>

// Global scaling constants
static const double SPEED_CAP = 18.0;


/**
 * Validation helper
 */
bool is_level_valid(int level) {
    if (level < 1) {
        return false;
    }
    if (level > 100) {
        return false;
    }
    return true;
}


/**
 * Logic for the FastEnemy type.
 * Scales speed quickly, health slowly.
 */

FastEnemy calculate_fast_enemy(int level) {
    FastEnemy enemy;

    if (!is_level_valid(level)) {
        enemy.health = 0; enemy.speed = 0;
        return enemy;
    }

    // Health: Low base, slow exponential growth (8% per level)
    enemy.health = 40.0 * pow(1.08, (double)level);

    // Speed: High base, scales up to the cap
    double raw_speed = 8.0 + ((double)level * 0.6);
    
    if (raw_speed > SPEED_CAP) {
        enemy.speed = SPEED_CAP;
    } else {
        enemy.speed = raw_speed;
    }

    enemy.attack_power = 5 + (level * 1);
    enemy.knockback = 1.2 + (level * 0.02);
    enemy.coin_drop = 5 + (level * 2);

    return enemy;
}


/**
 * Logic for the NormalEnemy type.
 * Balanced progression.
 */

NormalEnemy calculate_normal_enemy(int level) {
    NormalEnemy enemy;

    if (!is_level_valid(level)) {
        enemy.health = 0; enemy.speed = 0;
        return enemy;
    }

    // Health: 12% growth per level
    enemy.health = 100.0 * pow(1.12, (double)level);

    double raw_speed = 5.0 + ((double)level * 0.3);

    if (raw_speed > 12.0) { // Normal enemies have a lower speed cap
        enemy.speed = 12.0;
    } else {
        enemy.speed = raw_speed;
    }

    enemy.attack_power = 10 + (level * 3);
    enemy.knockback = 2.5 + (level * 0.05);
    enemy.coin_drop = 10 + (level * 4);

    return enemy;
}


/**
 * Logic for the TankyEnemy type.
 * Massive HP and Knockback, but stays slow.
 */

TankyEnemy calculate_tanky_enemy(int level) {
    TankyEnemy enemy;

    if (!is_level_valid(level)) {
        enemy.health = 0; enemy.speed = 0;
        return enemy;
    }

    // Health: Massive base, aggressive growth (18% per level)
    enemy.health = 250.0 * pow(1.18, (double)level);

    // Speed: Very slow, barely increases
    double raw_speed = 2.0 + ((double)level * 0.1);

    if (raw_speed > 6.0) {
        enemy.speed = 6.0;
    } else {
        enemy.speed = raw_speed;
    }

    enemy.attack_power = 25 + (level * 8);
    enemy.knockback = 5.0 + (level * 0.2);
    enemy.coin_drop = 30 + (level * 10);

    return enemy;
}


/**
 * Logging function for debugging.
 * Useful for CUnit verification.
 */

void display_enemy_stats(int level) {
    FastEnemy f = calculate_fast_enemy(level);
    NormalEnemy n = calculate_normal_enemy(level);
    TankyEnemy t = calculate_tanky_enemy(level);

    printf("\n--- LEVEL %d ENEMY DATA ---\n", level);
    printf("[FAST]   HP: %7.1f | Spd: %4.1f | Atk: %d | KB: %.1f\n",
           f.health, f.speed, f.attack_power, f.knockback);
    printf("[NORMAL] HP: %7.1f | Spd: %4.1f | Atk: %d | KB: %.1f\n",
           n.health, n.speed, n.attack_power, n.knockback);
    printf("[TANK]   HP: %7.1f | Spd: %4.1f | Atk: %d | KB: %.1f\n",
           t.health, t.speed, t.attack_power, t.knockback);
}
