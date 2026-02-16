#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "shuffle.h"

int insertSongs(char songs[MAX_TOTAL_SONGS][MAX_LENGHT], char artists[MAX_TOTAL_SONGS][MAX_LENGHT]);
void printSorted(char artists[][MAX_LENGHT], char songs[][MAX_LENGHT], int numOfSongs);

int main() {
    char songs[MAX_TOTAL_SONGS][MAX_LENGHT];
    char artists[MAX_TOTAL_SONGS][MAX_LENGHT];
    int numOfSongs;

    srand(time(NULL));

    numOfSongs = insertSongs(songs, artists);
    printf("\nThe number of songs is %d\n", numOfSongs);

    sortSongs(artists, songs, numOfSongs);

    printf("\nSorted list of songs:\n");
    printSorted(artists, songs, numOfSongs);

    shufflePlaylist(artists, songs, numOfSongs);

    // the ASCII art of a masterfully created stickman.
    printf("\nASCII Art!\n");
    printf("  O  \n");
    printf(" /|V  \n");
    printf(" /\\  \n");
    printf("\nleg is a lil off center...\n");

    return 0;
}


int insertSongs(char songs[MAX_TOTAL_SONGS][MAX_LENGHT], char artists[MAX_TOTAL_SONGS][MAX_LENGHT]) {
    char currentArtist[MAX_LENGHT];
    int totalSongCount = 0;

    for (int j = 0; j < MAX_ARTISTS; j++) {
        printf("\nInsert an artist/group name:\n");
        if (fgets(currentArtist, MAX_LENGHT, stdin) == NULL || currentArtist[0] == '\n') {
            break;
        }

        currentArtist[strcspn(currentArtist, "\n")] = 0;

        for (int i = 0; i < MAX_SONGS_PER_ARTIST; i++) {
            printf("Insert song %d for %s:\n", i + 1, currentArtist);
            if (fgets(songs[totalSongCount], MAX_LENGHT, stdin) == NULL || songs[totalSongCount][0] == '\n') {
                break;
            }

            songs[totalSongCount][strcspn(songs[totalSongCount], "\n")] = 0;
            strcpy(artists[totalSongCount], currentArtist);
            totalSongCount++;
        }
    }
    return totalSongCount;
}

void printSorted(char artists[][MAX_LENGHT], char songs[][MAX_LENGHT], int numOfSongs) {
    char lastArtist[MAX_LENGHT] = "";
    for (int i = 0; i < numOfSongs; i++) {
        // ensures that the artist name is only printed once:
        if (strcmp(artists[i], lastArtist) != 0) {
            printf("%s\n", artists[i]);
            strcpy(lastArtist, artists[i]);
        }
        printf("  -  %s\n", songs[i]);
    }
}