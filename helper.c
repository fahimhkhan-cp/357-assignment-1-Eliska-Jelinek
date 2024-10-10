#include "helper.h"
#include <stdio.h>

FILE main(int argc, char* argv[]) {
	// Open input/source file for reading
  FILE *sourcefile = stdin;
  if (argc == 2) {
    sourcefile = fopen(argv[1], "r");
    // Error if it doesn't exist
    if (sourcefile == NULL) {
      perror("Source file does not exist");
      return sourcefile;
    }
  }


}