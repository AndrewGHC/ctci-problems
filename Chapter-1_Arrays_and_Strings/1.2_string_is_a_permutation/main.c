#include <stdio.h>
#include <string.h>

// Given two strings, determine if the first is a permutation of the second

int str_is_permutation(char *first_str, char *second_str)
{
   if (strlen(first_str) != strlen(second_str)) {
     printf("Not a permutation");
     return 1;
   };

   int ascii[255] = { 0 };

   // Set occurances of each char in first string
   for (int i = 0; i < strlen(first_str); i++) {
     int first_str_atoi = (int)first_str[i];
     ascii[first_str_atoi] = ascii[first_str_atoi] + 1;
   }

   // Do opposite for second string
   for (int i = 0; i < strlen(second_str); i++) {
     int second_str_atoi = (int)second_str[i];
     ascii[second_str_atoi] = ascii[second_str_atoi] - 1;
   }

   // Ensure net result is equal
   for (int i = 0; i < strlen(first_str); i++) {
     int first_str_atoi = (int)first_str[i];
     if (ascii[first_str_atoi] != 0) {
       printf("Not a permutation");
       return 1;
     }
   }

   printf("Permutation");
   return 0;
}

int main(int argc, char *argv[])
{
  return str_is_permutation(argv[1], argv[2]);
}
