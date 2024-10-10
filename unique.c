#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"


int main(int argc, char *argv[]) {
	// Open input file for reading
    FILE *sourcefile = open_input(argc, argv);


    // Initialize vars for loop
    char *line = NULL;
    unsigned int len = 0;
    int read;
    char *prev_line = NULL;

    // Loop through each line in input
    while ((read = getline(&line, (size_t *)&len, sourcefile)) != -1) {
        // Compare current line to previous line
        if (!(prev_line != NULL && strcmp(prev_line, line) == 0)) {
            // Print if it's a "unique" line (not the same as previous)
            printf("%s", line);
        }
        
        // Update previous line with copy of current line
        free(prev_line);
        prev_line = strdup(line);
    }

    // Free variables
    free(prev_line);
    free(line);

    // Close file
    close_file(sourcefile);

    // Filler return statement
    return 0;

}
