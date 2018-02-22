#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(const int m, const int n, const int matrix[m][n])
{
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void transpose_array(const int m, const int n, int to[m][n], const int from[m][n])
{
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      to[j][i] = from[i][j];
      to[i][j] = from[j][i];
    }
  }
}

void reverse_array(const int m, const int n, int to[m][n], const int from[m][n])
{
  for (int i = 0; i < m; i++) {
    int first = 0;
    int second = n - 1;
    int tmp;
    while (first < second) {
      tmp = from[i][first];
      to[i][first] = from[i][second];
      to[i][second] = tmp;
      first++;
      second--;
    }
  }
}

// Rotate a matrix by 90 deg, where each pixel is 4 bytes
int main()
{
  const int m = 4;
  const int n = 4;
  // Int = 4 bytes when compiled by GCC on 32/64 bit architectures
  int matrix[m][n] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {1, 2, 3, 4},
    {5, 6, 7, 8}
  };
  printf("Matrix to be rotated:\n\n");
  print_matrix(m, n, matrix);

  int transposed_matrix[m][n] = { {0}, {0}, {0}, {0} };
  int reversed_matrix[m][n] = { {0}, {0}, {0}, {0} };

  transpose_array(m, n, transposed_matrix, matrix);
  reverse_array(m, n, reversed_matrix, transposed_matrix);

  printf("\nRotated array:\n\n");
  print_matrix(m, n, reversed_matrix);
  printf("\n");

  return 0;
}
