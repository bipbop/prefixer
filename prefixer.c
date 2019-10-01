#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

const int lineBreak = '\n';
char hostname[1024];

int main(int argc, char** argv) {
  short int state = 1;
  char *preffix;
  int input;

  if (argc < 2) {
    bzero(hostname, sizeof(char) * sizeof(hostname));
    if (gethostname(hostname, sizeof(hostname) - 1) == -1) {
      fprintf(stderr, "you must add a prefix\n");
      return -1;
    }
    preffix = hostname;
  } else {
    preffix = argv[1];
  }


  while (1) {
    input = fgetc(stdin);
    if (input == EOF) return 0; 
    if (state == 1) {
      state = 0;
      fprintf(stdout, "%s> ", preffix);
    }

    if (input == '\n') {
      state = 1;
    }
    fputc(input, stdout);
  }
  return -1;
}