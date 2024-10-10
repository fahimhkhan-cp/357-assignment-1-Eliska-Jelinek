#define HELPER_H

#include <stdio.h>
#include <stdlib.h>

// // Opens a file or returns stdin if no filename is provided
// FILE* open_input(int argc, char* argv[]);

// // Closes a file if it is not stdin
// void close_file(FILE *file);


FILE* open_input(int argc, char* argv[]) {
    // Open input file for reading
    // Default to reading from stdin
    FILE *sourcefile = stdin;
    // Update sourcefile if one is provided
    if (argc == 2) {
        sourcefile = fopen(argv[1], "r");
        // Error if given file doesn't exist
        if (sourcefile == NULL) {
        perror("Source file does not exist");
        // End execution - failed
        exit(1);
        }
    }
    return sourcefile;
}

void close_file(FILE *sourcefile) {
    // Close file
    if (sourcefile != stdin) {
        fclose(sourcefile);
    }
}