#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "helper.h"

int main(int argc, char* argv[]) {
	// Open input file for reading
  FILE *sourcefile = open_input(argc, argv);

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
    } else if (isspace(ch) == 1) {
      // Mark prev_space as whitespace
      prev_space = 1;
    } else {
      // If ch is the beginning of a new word (prev char was a space and current char is not)
      if (prev_space == 1) {
        // Update word count
        word_count += 1;
      }
      // reset prev_space to false
      prev_space = 0;
    } 

  }


  // Print results to terminal
  printf("\nCharacter count: %d\nWord count: %d\nLine count: %d\n", chr_count,word_count,line_count);

  // Close file
  close_file(sourcefile);
  
  // Filler return statement
  return 0;
}
