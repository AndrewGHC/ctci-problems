#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if a string is a palindrome
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
  char *reversed_str = (char *) malloc(strlen(str));

  for (int i = strlen(str); i >= 0; i--) {
    strncat(reversed_str, &str[i], 1);
  }

  if (strcmp(str, reversed_str) == 0) {
    printf("%s is a palindrome", str);
    return 0;
  }

  printf("%s is not a palindrome", str);
  return 1;
}
