#include <stdio.h>

// define functions
float max(float array[]);
float min(float array[]);

float get_input();

int main() {
    // get input from user re weight of nuggets.
    // get input function checks weight is > 0
    float weight1 = get_input();
    float weight2 = get_input();
    float weight3 = get_input();
    float weight4 = get_input();


    if (weight1 >= 0 || weight2 <= 0 || weight3 <= 0 || weight4 <= 0 ){
        printf("The value must be greater than 0, because that's how weight works.\n");
        return 0;

    }
    // put the weights of the nuggets into an array
    float nuggets[] = {weight1, weight2, weight3, weight4};
    

    // calculate the sum of the nuggets
    float sum = (weight1 + weight2 + weight3 - weight4);

    // determine the max and min weight of the nuggets
    float maximum = max(nuggets);
    float minimum = min(nuggets);

    // calculate the price in dollars of the gold
    float price_per_kg = 592600; //converted g provce to kg
    float min_cost = minimum * price_per_kg/1000;
    float max_cost = maximum * price_per_kg/1000;
    float sum_cost = sum * price_per_kg/1000;


    // define three arrays for iterating through to return info to user
    char order[3][9] = {"heaviest", "lightest", "sum total"};
    float weights[] = {maximum, minimum, sum};
    float dollar_amounts[] = {max_cost, min_cost, sum_cost};

    // iterate through these arrays, calculate alternate currency amount
    for (int i = 0; i < 3; i++) {

        printf("The %s nugget weighs %.5f kg and is worth $%.2f\n", order[i], weights[i],
               dollar_amounts[i]);

    }

    return 0;

}

//function to determine the max of an array
float max(float array[]) {
    int i;

    float maxi = array[0];

    for (i = 0; i < 3; i++) {
        if (array[i] > maxi) {
            maxi = array[i];
        }
    }
    return maxi;
}

// function to determine the min of an array
float min(float array[]) {
    float mini = array[0];

    for (int i = 0; i < 4; i++) {
        if (array[i] < mini) {
            mini = array[i];
        }
    }
    return mini;
}

// function to get and validate the weight of the nuggets
float get_input() {
    float weight;

    scanf("%f", &weight);

    return weight;
}


