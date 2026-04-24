#ifndef DIFFICULTY_MANAGER_H
#define DIFFICULTY_MANAGER_H

#include <stdio.h>
#include <stdbool.h>


// Fast Enemy Struct

typedef struct {
    double health;          // Double #1
    double speed;           // Double #2
    int attack_power;
    double knockback;
    int coin_drop;
} FastEnemy;


// Normal Enemy Struct

typedef struct {
    double health;
    double speed;
    int attack_power;
    double knockback;
    int coin_drop;
} NormalEnemy;


// Tanky Enemy Struct

typedef struct {
    double health;
    double speed;
    int attack_power;
    double knockback;
    int coin_drop;
} TankyEnemy;


// Function prototypes

FastEnemy calculate_fast_enemy(int level);

NormalEnemy calculate_normal_enemy(int level);

TankyEnemy calculate_tanky_enemy(int level);


// Helper functions

bool is_level_valid(int level);

void display_enemy_stats(int level);


#endif