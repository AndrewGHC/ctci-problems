#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if there is a 1 char difference between two strings
int main(int argc, char *argv[])
{
  if (argc == 1) {
    printf("No arguments passed");
    return 1;
  } else if (argc < 3) {
    printf("This program requires two arguments");
    return 1;
  }
  else if (argc >= 4) {
    printf("This program only accepts two arguments");
    return 1;
  }

  char *firstStr = argv[1];
  char *secondStr = argv[2];

  char *largerString = strlen(firstStr) > strlen(secondStr) ? firstStr : secondStr;
  char *smallerString = strlen(firstStr) > strlen(secondStr) ? secondStr : firstStr;
  // If one string is > 1 char larger or < 1 char smaller, return error
  if (strlen(largerString) % strlen(smallerString) > 1) {
    printf("Greater than 1 char difference");
    return 1;
  }

  printf("There is a one char difference between these strings");
  return 0;
}
