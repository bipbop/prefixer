#include "stdlib.h"
#include "stdio.h"

const int lineBreak = '\n';

int main(int argc, char** argv) {
  short int state = 1;
  int input;

  if (argc < 2) {
    fprintf(stderr, "you must add a prefix\n");
    return -1;
  }


  while (1) {
    input = fgetc(stdin);
    if (input == EOF) return 0; 
    if (state == 1) {
      state = 0;
      fprintf(stdout, "%s> ", argv[1]);
    }
    if (input == '\n') {
      state = 1;
    }
    fputc(input, stdout);
  }
  return -1;
}