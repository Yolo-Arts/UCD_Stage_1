/*
 * clear.c
 *
 *  Created on: 8 Mar 2026
 *      Author: annie
 */
#include <stdio.h> //need for fflush(stdout)
#include <stdlib.h> // need for system()

void clearDisplay() { //works in terminal but eclipse cant clear screen

     #ifdef _WIN32
        system("cls");    // Windows
    #else
        system("clear");  // Linux / Mac

     #endif //needs to know where conditional ends

}
