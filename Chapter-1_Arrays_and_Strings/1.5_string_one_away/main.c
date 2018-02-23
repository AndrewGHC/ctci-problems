#include <stdio.h>
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

  char *first_str = argv[1];
  char *second_str = argv[2];

  char *larger_string = strlen(first_str) > strlen(second_str) ? first_str : second_str;
  char *smaller_string = strlen(first_str) > strlen(second_str) ? second_str : first_str;
  // If one string is > 1 char larger or < 1 char smaller, return error
  if (strlen(larger_string) % strlen(smaller_string) > 1) {
    printf("Greater than 1 char difference");
    return 1;
  }

  printf("There is a one char difference between these strings");
  return 0;
}
