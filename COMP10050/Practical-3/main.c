#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/*
 * This method writes a set of songs provided  from the command line
 * in an array provided as input.
 *
 * Inputs:
 * char songs[MAX_SONGS][]: The array of songs to be written
 *
 * Output: The number of songs provided as input
 */

int insertSongs(char songs [MAX_SONGS][MAX_LENGHT] ) {
    int i, length;
    // Insert the songs
    for(i=0; i < MAX_SONGS; i++){
        printf("Insert Song %d: ", i+1);
        fgets(songs[i], MAX_LENGHT, stdin);

        //If the return command is pressed it exits
        if(songs[i][0]=='\n')
            break;

        //Remove the carriage return from the song
        length = strlen(songs[i]);
        songs[i][length -1] = '\0';
    }
    if (i >0)
        return i;
    else return 0;

}


/*
 * This method prints the songs provided as input
 *
 * Inputs:
 * char songs[MAX_SONGS][MAX_LENGHT]: The array of songs to be printed
 * int numOfSongs: The number of songs to be printed
 *
 */

void printSongs(char songs [MAX_SONGS][MAX_LENGHT], int numOfSongs){
    int i ;
    for(i=0; i< numOfSongs; i++){
        printf("\nSong %d: %s\n", i+1, songs[i]);
    }

}

int main()
{
    //an array of songs
    char songs[MAX_SONGS][MAX_LENGHT];
    int numOfSongs;

    // Insert a set of songs from the command line
    numOfSongs = insertSongs(songs);

    printf ("The number of songs is %d \n", numOfSongs);

    //Sort songs alphabetically
    sortSongs(songs, numOfSongs);

    //Print the songs
    printSongs(songs, numOfSongs);

    return 0;

}