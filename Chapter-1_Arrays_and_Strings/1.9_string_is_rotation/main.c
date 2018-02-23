#include <stdio.h>
#include <string.h>

// Given two strings, check if the second is a rotation of the first
// E.g., "tca" is a rotation of "cat"
int main(int argc, char *argv[])
{
  if (argc == 1) {
    printf("No arguments passed");
    return 1;
  } else if (argc < 3) {
    printf("This program requires two arguments");
    return 1;
  } else if (argc >= 4) {
    printf("This program only accepts two arguments");
    return 1;
  }

  char *first_str = argv[1];
  char *second_str = argv[2];

  if (strlen(first_str) != strlen(second_str)) {
    printf("Both arguments must be of the same length");
    return 1;
  }

  int len = strlen(first_str);
  char permutations[len][len];

  int current_char;
  for (int i = 0; i < len; i++) {
    current_char = i;
    for (int j = 0; j < len; j++) {
      if (current_char > len -1) current_char = 0;
      permutations[i][j] = first_str[current_char];
      current_char++;
    }
  }

  int is_rotation;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (second_str[j] == permutations[i][j]) {
        is_rotation = 1;
      } else {
        is_rotation = 0;
        break;
      }
    }
    if (is_rotation) {
      printf("%s is a rotation of %s", second_str, first_str);
      return 0;
    }
  }

  printf("%s is not a rotation of %s", second_str, first_str);
  return 1;
}
