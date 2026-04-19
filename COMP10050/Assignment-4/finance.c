#include <stdio.h>
#include <math.h>
#include "finance.h"

// Logic for a single month's calculation
double calculate_monthly_growth(double balance, double annual_rate, double contribution) {
    double monthly_rate = annual_rate / 12.0;
    balance += contribution;
    balance *= (1.0 + monthly_rate);
    return balance;
}

double calculate_future_value(FinanceProfile profile) {
    double balance = profile.initial_investment;
    int total_months = profile.years * 12;

    for (int i = 1; i <= total_months; i++) {
        balance = calculate_monthly_growth(balance, profile.annual_growth_rate, profile.monthly_contribution);
    }
    return balance;
}

double calculate_total_contributions(FinanceProfile profile) {
    return profile.initial_investment + (profile.monthly_contribution * 12 * profile.years);
}

double adjust_for_inflation(double nominal_value, double inflation_rate, int years) {
    if (inflation_rate == 0) return nominal_value;
    return nominal_value / pow((1.0 + inflation_rate), years);
}

double calculate_tax_liability(double total_value, double total_contributions, double tax_rate) {
    double profit = total_value - total_contributions;
    if (profit <= 0) return 0.0; // No tax on losses or breaking even
    return profit * tax_rate;
}

void generate_detailed_report(FinanceProfile profile) {
    printf("\n============================================\n");
    printf("   INVESTMENT FORECAST: %d YEAR OUTLOOK\n", profile.years);
    printf("============================================\n");
    
    double current_balance = profile.initial_investment;
    for (int y = 1; y <= profile.years; y++) {
        for (int m = 1; m <= 12; m++) {
            current_balance = calculate_monthly_growth(current_balance, profile.annual_growth_rate, profile.monthly_contribution);
        }
        double real_val = adjust_for_inflation(current_balance, profile.inflation_rate, y);
        printf("Year %d: Nominal [$%.2f] | Inflation Adjusted [$%.2f]\n", y, current_balance, real_val);
    }
    printf("============================================\n");
}