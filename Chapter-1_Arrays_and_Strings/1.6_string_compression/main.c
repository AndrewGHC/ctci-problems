#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compress a string, so that e.g. 'aaabbcccd' becomes 'a3b2c3d1'
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

  // Max possible result requires a buffer of str * 2, as 'abc' becomes 'a1b1c1'
  char *compressedStr = (char *) malloc(strlen(str) * 2);

  char lastChar[] = " ";
  strncpy(lastChar, &str[0], 1);
  int numberOfChars = 0;
  for (int i = 0; i < strlen(str); i++) {
    int  condition = strncmp(lastChar, &str[i], 1);
    if (condition == 0) {
      numberOfChars++;
    }

    if (condition != 0) {
      strncat(compressedStr, lastChar, 1);
      char buf[sizeof(int)];
      sprintf(buf, "%d", numberOfChars);
      strncat(compressedStr, buf, 1);
      numberOfChars = 1;
    }

    if (i == strlen(str) - 1) {
      strncat(compressedStr, &str[i], 1);
      char buf[sizeof(int)];
      sprintf(buf, "%d", numberOfChars);
      strncat(compressedStr, buf, 1);
    }

    strncpy(lastChar, &str[i], 1);
  }

  printf("\nResult: %s \n\n", compressedStr);
  return 0;
}
