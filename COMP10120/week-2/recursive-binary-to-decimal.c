#include <stdio.h>

int binaryToDecimal(int binaryInput);

int main(void) {

    return 0;
}

int binaryToDecimal(int binaryInput) {

    if (binaryInput == 0) {
        return 0
    } else (binaryInput == 1) {
        return 1
    }

    return binaryToDecimal(binaryInput) 
}