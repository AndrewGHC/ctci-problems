#include <stdio.h>
#include <string.h>

// Determine if a string of max length 64 chars has unique characters
int str_is_unique(char *str)
{
   int ascii[255];
   for (int i = 0; i < strlen(str); i++) {
     if (ascii[(int)str[i]] == 0) {
       ascii[(int)str[i]] = 1;
     } else {
       printf("%s\n", "Not unique");
       return 1;
     }
   }
   printf("%s\n", "Unique");
   return 0;
}

int main()
{
  char str[64];
  scanf("%s", str);
  return str_is_unique(str);
}
