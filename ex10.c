#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 0;

  char *states[] = {
    "Cali", "Oregon",
    "Washington", "Texas"
  };

  states[1] = argv[1];

  for(i = 1; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }



  int num_states = 6;

  for(i = 0; i < num_states; i++) {
    printf("state %d: %s\n", i, states[i]);
  }

  return 0;
}