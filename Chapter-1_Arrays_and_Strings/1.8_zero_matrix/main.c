#include <stdio.h>

void print_matrix(const int m, const int n, const int matrix[m][n])
{
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void zero_row(const int m, const int n, const int row, int matrix[m][n])
{
  for (int i = 0; i < m; i++) {
    matrix[row][i] = 0;
  }
}

void zero_column(const int m, const int n, const int column, int matrix[m][n])
{
  for (int i = 0; i < n; i++) {
    matrix[i][column] = 0;
  }
}

// If an element in a matrix is 0, elements all items in that column and row with 0
int main()
{
  const int m = 4;
  const int n = 4;
  int matrix[m][n] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {1, 2, 0, 4},
    {5, 6, 7, 8}
  };
  printf("Matrix to be zeroed:\n\n");
  print_matrix(m, n, matrix);

  // Clone matrix
  int zero_matrix[m][n] = { {0}, {0}, {0}, {0} };
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      zero_matrix[i][j] = matrix[i][j];
    }
  }

  // Set rows & columns to 0 if row element is 0
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        zero_row(m, n, i, zero_matrix);
        zero_column(m, n, j, zero_matrix);
      }
    }
  }

  printf("\nMatrix with zeros:\n\n");
  print_matrix(m, n, zero_matrix);
  printf("\n");

  return 0;
}
