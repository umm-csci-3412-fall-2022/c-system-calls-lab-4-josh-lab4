#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
  // Returns true if c is a vowel and false otherwise
  if (c == 'a' || c == 'A' ||c == 'e' || c == 'E' ||c == 'i' || c == 'I' ||c == 'o' || c == 'O' ||c == 'u' || c == 'U') {
    return true;
  }
  return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  // Copy non-vowel characters from in_buf to out_buf
  // Return amount of non-vowels transferred over
  int num_nonvowel = 0;

  // For each character in the in_buf character array, if it is not a vowel,
  // then add one to the non-vowel counter and add the non-vowel to the out_buf 
  // character array
  for (int i = 0; i < num_chars; i++) {
    if (!is_vowel(in_buf[i])) {
      out_buf[num_nonvowel] = in_buf[i];
      num_nonvowel++;
    }
  }
  return num_nonvowel;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  // Copy all non-vowels from inputFile to OutputFile
  char input[BUF_SIZE];
  char output[BUF_SIZE];
  while (!feof(inputFile)) {
    // While the bottom of the input file indicator has not been reached
    // Read data from input file to the block of memory `input`
    // Copy the non-vowels from the `input` block of memory to the `output` block of memory
    // Write data from `output` block of memory to the out file
    int num_chars = fread(input, sizeof(char), BUF_SIZE, inputFile);
    int num_nonvowel = copy_non_vowels(num_chars, input, output);
    fwrite(output, sizeof(char), num_nonvowel, outputFile);
  }
}


int main(int argc, char *argv[]){
  // `stdin` and `stdout` are the default names of the input and output respectively
  FILE *inputFile = stdin;
  FILE *outputFile = stdout;

  // Note: The first argument is always the name of the program, so:
  // 	Having 2 arguments means we only were given the input file
  // 	Having 3 arguments measn we were given the input and output files
  // 	Having more than 3 argument smeans we were given too many files
  if(argc == 2) {
    // If only given an input file, open it and make it readable
    inputFile = fopen(argv[1], "r");
  } else if(argc == 3){
    // If given input and output file:
    //   Open the input file and make it readable
    inputFile = fopen(argv[1], "r");
    //   Open the output file and make it writable
    outputFile = fopen(argv[2], "w");
  } else if(argc > 3){
    // If given too many arguments, output an error and stop the program
    fprintf(stderr, "Too many arguments were used");
    return 1;
  }

  disemvowel(inputFile, outputFile);

  return 0;
}

