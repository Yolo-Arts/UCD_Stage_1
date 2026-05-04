#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 80
#define MAX_SONGS 12

void update_recent_songs(char recentSongs[5][MAX_LENGTH], char *newSong) {
    for (int k = 4; k > 0; k--) {
        strcpy(recentSongs[k], recentSongs[k - 1]);
    }
    strcpy(recentSongs[0], newSong);
}

int isSongRecentlyPlayed(char recentSongs[5][MAX_LENGTH], char *songTitle) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(recentSongs[i], songTitle) == 0) {
            return 1;
        }
    }
    return 0;
}

