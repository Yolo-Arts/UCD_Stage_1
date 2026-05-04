#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 80
#define MAX_SONGS 12

void update_recently_played(char recentSongs[5][MAX_LENGTH], char *newSong) {
    for (int k = 4; k > 0; k--) {
        strcpy(recentSongs[k], recentSongs[k - 1]);
    }
    strcpy(recentSongs[0], newSong);
}

int is_recently_played(char recentSongs[5][MAX_LENGTH], char *songTitle) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(recentSongs[i], songTitle) == 0) {
            return 1;
        }
    }
    return 0;
}

void parallelSwap(char artists[][MAX_LENGTH], char songs[][MAX_LENGTH], int i, int j) {
    char tempArtist[MAX_LENGTH];
    char tempSong[MAX_LENGTH];

    strcpy(tempArtist, artists[i]);
    strcpy(tempSong, songs[i]);

    strcpy(artists[i], artists[j]);
    strcpy(songs[i], songs[j]);

    strcpy(artists[j], tempArtist);
    strcpy(songs[j], tempSong);
}

