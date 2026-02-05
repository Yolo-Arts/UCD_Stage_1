#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/*
 * This function sorts the songs provided as input alphabetically
 *
 * Inputs:
 *   char songs[MAX_SONGS][MAX_LENGHT]: The songs to be sorted
 *   int numOfSongd: the number of songs to be sorted
 *
 */

void sortSongs(char songs[][MAX_LENGHT], int numOfSongs){
    int i =0;
    int j=0;
    int minIndex = 0;
    int minIndexChanged = 0;

    char swap [MAX_LENGHT];

    printf("\nThe number of songs is %d\n", numOfSongs);


    for(i=0; i< (numOfSongs-1); i ++){
        minIndex = i;
        for(j=i+1; j<numOfSongs; j++){
            printf("i: %d, j: %d, minIndex: %d\n", i, j,minIndex);
            if(strcmp(songs[j], songs[minIndex]) < 0){
                minIndex = j;
                minIndexChanged =1;
            }
        }

            if(minIndexChanged == 1){
                memset(swap, '$', MAX_LENGHT-2);
                swap[MAX_LENGHT -1] = '\0';
                printf("%s\n", swap);
                strcpy(swap,songs[i]);
                strcpy(songs[i], songs[minIndex]);
                strcpy(songs[minIndex], swap);
                minIndexChanged =0;
            }

    }
}


