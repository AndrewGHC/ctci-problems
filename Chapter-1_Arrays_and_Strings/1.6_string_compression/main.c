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
  char *compressed_str = (char *) malloc(strlen(str) * 2);

  char last_char[] = " ";
  strncpy(last_char, &str[0], 1);
  int nmbr_chars = 0;
  for (int i = 0; i < strlen(str); i++) {
    int  condition = strncmp(last_char, &str[i], 1);
    if (condition == 0) {
      nmbr_chars++;
    }

    if (condition != 0) {
      strncat(compressed_str, last_char, 1);
      char buf[sizeof(int)];
      sprintf(buf, "%d", nmbr_chars);
      strncat(compressed_str, buf, 1);
      nmbr_chars = 1;
    }

    if (i == strlen(str) - 1) {
      strncat(compressed_str, &str[i], 1);
      char buf[sizeof(int)];
      sprintf(buf, "%d", nmbr_chars);
      strncat(compressed_str, buf, 1);
    }

    strncpy(last_char, &str[i], 1);
  }

  printf("\nResult: %s \n\n", compressed_str);
  return 0;
}
