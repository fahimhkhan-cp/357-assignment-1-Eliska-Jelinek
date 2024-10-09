#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// char read_cli_input(){
//   return 'h';
// }


int main(int argc, char* argv[]) {
	// Open input/source file for reading
  FILE *sourcefile = stdin;
  if (argc == 2) {
    sourcefile = fopen(argv[1], "r");
    // Error if it doesn't exist
    if (sourcefile == NULL) {
      perror("Source file does not exist");
      return 1;
    }
  }


	// Reading and writing from file

  int chr_count = 0;
  int word_count = 1; // might need to start this at one
  int line_count = 1; // ^^

	int ch; // char ch
  int prev_space = 0; // false
	while ((ch = getc(sourcefile)) != EOF) {
    //putchar(ch);
    
    // Update character count
    chr_count ++;

    if (ch == *"\n") {
      line_count += 1;
      prev_space = 1;
    } else if (isspace(ch) == 1) {
      if (prev_space == 0) {  
        word_count += 1;
        prev_space = 1;
      } else {
        // reset prev_space
        prev_space = 0;
      }
    } else {
      prev_space = 0;
    } 

  }



  printf("\nCharacter count: %d\nWord count: %d\nLine count: %d\n", chr_count,word_count,line_count);

  // Close file
  if (sourcefile != stdin) {
    fclose(sourcefile);
  }
  
  return 0;
}
