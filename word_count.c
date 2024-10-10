#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	// Open input file for reading
  // Default to reading from stdin
  FILE *sourcefile = stdin;
  // Update sourcefile if one is provided
  if (argc == 2) {
    sourcefile = fopen(argv[1], "r");
    // Error if given file doesn't exist
    if (sourcefile == NULL) {
      perror("Source file does not exist");
      // Return to end execution
      return 1;
    }
  }


	// Initialize counting variables
  int chr_count = 0;
  int word_count = 1; // Starts at 1 to include very first word
  int line_count = 1; // ^^

  // Initialize loop variables
	int ch;
  int prev_space = 0; // defaults to false
  // prev_space is to prevent consecutive whitespaces from counting as words

  // Loop through all characters in given input
	while ((ch = getc(sourcefile)) != EOF) {
    // Update character count
    chr_count ++;

    // Update line count if applicable
    if (ch == *"\n") {
      line_count += 1;
      prev_space = 1; // sets to true
    // Update if ch is a space (or other whitespace)
    } else if (isspace(ch) == 1) {
      // Add to count only if previous char was not whitespace
      if (prev_space == 0) {  
        word_count += 1;
        prev_space = 1;
      } else {
        // reset prev_space to false if it was true
        prev_space = 0;
      }
    } else {
      // reset prev_space to false
      prev_space = 0;
    } 

  }


  // Print results to terminal
  printf("\nCharacter count: %d\nWord count: %d\nLine count: %d\n", chr_count,word_count,line_count);

  // // Free all variables
  // free(chr_count);
  // free(word_count);
  // free(line_count);
  // free(prev_space);
  // free(ch);

  // Close file
  if (sourcefile != stdin) {
    fclose(sourcefile);
  }
  
  // Filler return statement
  return 0;
}
