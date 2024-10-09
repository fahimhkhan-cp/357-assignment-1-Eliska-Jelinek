#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    // Open file
    FILE *file = fopen(argv[1], "r");
    // TODO: HANDLE NO FILE INPUT AND INVALID FILE INPUT

    char *line = NULL;
    unsigned int len = 0;
    int read;
    char *prev_line = NULL;

    while ((read = getline(&line, (size_t *)&len, file)) != -1) {
        // check if lines are the same
        
        int same = 0;
        int ch1;
        int ch2;
        
        if (!(prev_line != NULL && strcmp(prev_line, line) == 0)) {
            printf("%s", line);
        }
        
        // Update previous line with copy of current line
        prev_line = strdup(line);
    }

    fclose(file);

}
