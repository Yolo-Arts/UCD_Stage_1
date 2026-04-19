#ifndef FINANCE_H_
#define FINANCE_H_

typedef struct {
    double initial_investment;
    double monthly_contribution;
    double annual_growth_rate;
    double inflation_rate;
    double tax_rate;
    int years;
} FinanceProfile;

// Suite A: Growth Logic
double calculate_monthly_growth(double balance, double annual_rate, double contribution);
double calculate_future_value(FinanceProfile profile);
double calculate_total_contributions(FinanceProfile profile);

// Suite B: Real World Adjustments
double adjust_for_inflation(double nominal_value, double inflation_rate, int years);
double calculate_tax_liability(double total_value, double total_contributions, double tax_rate);

// Utility
void generate_detailed_report(FinanceProfile profile);

#endif