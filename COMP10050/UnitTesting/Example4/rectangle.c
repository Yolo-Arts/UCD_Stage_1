#include <stdio.h>
#include "rectangle.h"

int getArea(int length, int width) {
    return length * width;
}

int isSquare(int length, int width) {
    if (length == width) {
        return 1;
    } else {
        return 0;
    }
}