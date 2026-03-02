/*

You work in an insurance company, you have installed trackers into several of your customers’ cars to monitor their driving and offer a discount bonus if they are ‘good’ drivers.  The data collected show the average acceleration per trip for the last ten trips for five sample drivers.

The rules state that if the total average acceleration for the past ten trips is more than 5 metres per second per second OR any trip has an average of 6 metres per second per second or more, then no discount should be applied to the customer. 

The collected data are shown below and captured in a two-dimensional array called acceleration.

There is a C function called bonusCheck that takes the 2D array and the driver number (eg. Driver 1 = {3, 1, 3, 4, 6, 7, 3, 2, 5, 3}) as parameters and returns 1 to apply bonus and 0 for no bonus. However, it is not working. Debug the code to make it work properly.  See the test cases for expected output.

For example:

Test    Result
int acceleration [5][10] = {{3, 1, 3, 4, 6, 7, 3, 2, 5, 3},{2, 2, 2, 3, 4, 4, 3, 3, 3, 2},{5, 6, 7, 6, 5, 3, 3, 3, 3, 3},{3, 3, 3, 3, 4, 4, 3, 2, 1, 3},{2, 3, 4, 6, 6, 2, 5, 1, 3, 3}};
printf("%d", bonusCheck(acceleration,1));
0
int acceleration [5][10] = {{3, 1, 3, 4, 6, 7, 3, 2, 5, 3},{2, 2, 2, 3, 4, 4, 3, 3, 3, 2},{5, 6, 7, 6, 5, 3, 3, 3, 3, 3},{3, 3, 3, 3, 4, 4, 3, 2, 1, 3},{2, 3, 4, 6, 6, 2, 5, 1, 3, 3}};
printf("%d", bonusCheck(acceleration,3));
0
int acceleration [5][10] = {{3, 1, 3, 4, 6, 7, 3, 2, 5, 3},{2, 2, 2, 3, 4, 4, 3, 3, 3, 2},{5, 6, 7, 6, 5, 3, 3, 3, 3, 3},{3, 3, 3, 3, 4, 4, 3, 2, 1, 3},{2, 3, 4, 6, 6, 2, 5, 1, 3, 3}};
printf("%d", bonusCheck(acceleration,4));

*/

#include <stdio.h>

int bonusCheck(int acceleration[][10], int driver);

int main(){
    int acceleration [5][10] = {{3, 1, 3, 4, 6, 7, 3, 2, 5, 3},{2, 2, 2, 3, 4, 4, 3, 3, 3, 2},{5, 6, 7, 6, 5, 3, 3, 3, 3, 3},{3, 3, 3, 3, 4, 4, 3, 2, 1, 3},{2, 3, 4, 6, 6, 2, 5, 1, 3, 3}};
    printf("%d", bonusCheck(acceleration,3));
}

int bonusCheck(int acceleration[][10], int driver)
{
int total;
int average;
for (size_t i = 0; i <=10; i++) {
    if(acceleration[driver][i]>=6) {
        return 1;
    } else {
        total += acceleration[driver][i];
    }
}
average = total/10;
    if (average>5){
    return 0;
    }
    else{

    return 0;
    }
}