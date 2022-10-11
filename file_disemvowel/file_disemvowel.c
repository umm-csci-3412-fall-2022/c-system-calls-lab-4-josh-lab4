#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 1024;

bool is_vowel(char c) {
  // Returns true if c is a vowel and false otherwise
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  // Copy non-vowel characters 
  // Retrun amount of non-vowels transferred over
}

void disemvowel(File* inputFile, File* outputFile) {
  // Copy all non-vowels from inputFile to OutputFile
}

int main(int argc, char *argv[]) {
  // This sets `stdin` and `stdout` by default
  FILE *inputFile = stdin;
  FILE *outputFile = stdout;

  // Code that processes the command line arguments
  // And sets up input and output files
  
  disemvowel(inputFile, outputFile);

  return 0;
}
