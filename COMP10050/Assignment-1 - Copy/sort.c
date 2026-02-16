#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void sortSongs(char artists[][MAX_LENGHT], char songs[][MAX_LENGHT], int numOfSongs) {
    char tempArtist[MAX_LENGHT];
    char tempSong[MAX_LENGHT];

    for (int i = 0; i < numOfSongs - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < numOfSongs; j++) {
            // Compare artists
            int artistCmp = strcmp(artists[j], artists[minIdx]);

            if (artistCmp < 0) {
                minIdx = j;
            }
            // Compare song titles if the artist names are equal:
            else if (artistCmp == 0) {
                if (strcmp(songs[j], songs[minIdx]) < 0) {
                    minIdx = j;
                }
            }
        }

        if (minIdx != i) {
            // Swap Artist
            strcpy(tempArtist, artists[i]);
            strcpy(artists[i], artists[minIdx]);
            strcpy(artists[minIdx], tempArtist);

            // Swap Song
            strcpy(tempSong, songs[i]);
            strcpy(songs[i], songs[minIdx]);
            strcpy(songs[minIdx], tempSong);
        }
    }
}