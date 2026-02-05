/* * Calculates the average of a set of integers. It takes as input:
* - numbers: the numbers to be averaged
* - size: home many numbers should be averaged
* It returns the result of the average function */
double avg(int numbers[], int size);
/* * Allows to insert a set of integers form the standard input.
* It takes as input
* - numbers: the numbers to be inserted
* - maxSize: maximum amoount of numbers to be inserted */
void insertNumbers(int numbers[], int maxSize);

double avg(int numbers[], int size){
    int i =0;
    double result =0;
    for(i=0; i< size; i++)
    result += numbers[i];
    return result/size;
}
void insertNumbers(int numbers[], int maxSize){ int i =0;
    for(i =0; i<maxSize;i++){
    printf("insert an integer number: "); scanf ("%d", &numbers[i]); }
}