#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Replace all spaces in a string with %20
int main(int argc, char *argv[])
{
  if (argc == 1) {
    printf("No string passed");
    return 1;
  } else if (argc >= 3) {
    printf("This program only accepts one argument");
    return 1;
  }

  char *str = argv[1];
  // Count how many spaces there are in the string
  int nmbr_spaces = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      nmbr_spaces = nmbr_spaces + 1;
    }
  }

  // If there are no spaces, return error
  if (nmbr_spaces == 0) {
    printf("This string contains no spaces");
    return 1;
  }

  // Allocate buffer for the new string (' ' will become '%20')
  int buf_size = strlen(str) + nmbr_spaces * 2;
  char *new_str = (char *) malloc(buf_size);

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      strcat(new_str, "%20");
    } else {
      strncat(new_str, &str[i], 1);
    }
  }

  printf("%s", new_str);
  return 0;
}
