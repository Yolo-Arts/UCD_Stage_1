#include <stdio.h>
#include <stdlib.h>

int main() {

    // Step #1 - creating a pointer to a FILE type
    FILE *fp;

    // Step #2 - opening/access to a file
    // fp = fopen(<file_name>, <type_of_operation>);
    // Types of operation:
    //      - "w" - Writing
    //      - "r" - Reading
    //      - "a" - Appending. Adds to the end of the file.
    fp = fopen("myFirstFile.txt", "w");

    // Step #3 - Make sure opening is successful!
    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        // Step #4 - Do stuff with file.





        // Step #5 - Close file.
        fclose(fp);
    }


    return 0;
}