#include <stdio.h>
#include <string.h>

// Given two strings, determine if the first is a permutation of the second

int strIsPermutation(char *firstString, char *secondString)
{
   if (strlen(firstString) != strlen(secondString)) {
     printf("Not a permutation");
     return 1;
   };

   int ascii[255] = { 0 };

   // Set occurances of each char in first string
   for (int i = 0; i < strlen(firstString); i++) {
     int firstStringATOI = (int)firstString[i];
     ascii[firstStringATOI] = ascii[firstStringATOI] + 1;
   }

   // Do opposite for second string
   for (int i = 0; i < strlen(secondString); i++) {
     int secondStringATOI = (int)secondString[i];
     ascii[secondStringATOI] = ascii[secondStringATOI] - 1;
   }

   // Ensure net result is equal
   for (int i = 0; i < strlen(firstString); i++) {
     int firstStringATOI = (int)firstString[i];
     if (ascii[firstStringATOI] != 0) {
       printf("Not a permutation");
       return 1;
     }
   }

   printf("Permutation");
   return 0;
}

int main(int argc, char *argv[])
{
  return strIsPermutation(argv[1], argv[2]);
}
