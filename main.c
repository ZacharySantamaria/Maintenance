#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // Checking number of arguments
    if(argc == 2) {
        FILE *fptr;
        char *token;
        const char *delimiter = " ";
        fptr = fopen(argv[1], "r");

        char line[1000];

        // Checking if the ptr was successful
        if(fptr != NULL) {
            while(fgets(line, sizeof(line), fptr)) {
                token = strtok(line, delimiter);
                while(token != NULL) {
                    printf("%s\n", token);
                    token = strtok(NULL, delimiter);
                }
            }
            // Closing the open file pointer
            fclose(fptr);
        } else {
            printf("Not able to open the file.\n");
        }

    } else {
        printf("Wrong number of arguments.\n");
        printf("Usage `maintance <filename>`\n");
    }

    return 0;
}
