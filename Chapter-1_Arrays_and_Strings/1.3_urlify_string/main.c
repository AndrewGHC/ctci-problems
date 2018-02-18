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
  int numberOfSpaces = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      numberOfSpaces = numberOfSpaces + 1;
    }
  }

  // If there are no spaces, return error
  if (numberOfSpaces == 0) {
    printf("This string contains no spaces");
    return 1;
  }

  // Allocate buffer for the new string (' ' will become '%20')
  int bufferSize = strlen(str) + numberOfSpaces * 2;
  char *newStr = (char *) malloc(bufferSize);

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ') {
      strcat(newStr, "%20");
    } else {
      strncat(newStr, &str[i], 1);
    }
  }

  printf("%s", newStr);
  return 0;
}
