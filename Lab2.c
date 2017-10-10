#include <stdio.h>
#include <stdlib.h>

int **CreateMatrix(int rows, int cols)
{
  int **matrix = malloc(sizeof(int*) * rows);
  int row;
  for (row = 0; row < rows; row++) {
    matrix[row] = malloc(sizeof(int) * cols);
  }
  return matrix;
}

void MatrixInput(int **matrix, int rows, int cols)
{
  int row, col;
  for (row = 0; row < rows; row++) {
    for (col = 0; col < cols; col++) {
      printf("enter the element at row %d and col %d\n", row+1, col+1 );
      scanf("%d", &matrix[row][col]);
    }
  }
}

void PrintMatrix(int **matrix, int rows, int cols)
{
  int row, col;
  for (row = 0; row< rows; row++) {
    for (col = 0; col < cols; col++) {
      printf("%d ", matrix[row][col]);
    }
    printf("\n");
  }
}

void multiplyMatrices(int **matrix1,int height1,int width1,int **matrix2,int height2,int width2,int **matrix3)
{
  int sum=0;
  for (int x = 0; x < width2; x++) {
      for (int y = 0; y < height1; y++) {
        for (int z = 0; z < height2; z++) {
          sum = sum + matrix1[x][z]*matrix2[z][y];
        }

        matrix3[x][y] = sum;
        sum = 0;
      }
    }
}

int main(int argc, char const *argv[])
{

  int width1=0,width2=0,height1=0,height2=0;

  while ((width1 == 0 )||(width1 != height2)) {
    printf("Welcome to matrix multiplier\n-remember you can only multiply matrices if the width of the first one is the same as the height of the second one" );
    printf("enter the height of the first matrix\n" );
    scanf("%d", &height1 );
    printf("enter the width of the first matrix\n" );
    scanf("%d", &width1 );
    printf("enter the height of the second matrix\n" );
    scanf("%d", &height2 );
    printf("enter the width of the second matrix\n" );
    scanf("%d", &width2 );
  }
  printf("Now, please enter the attributes of the first matrix\n" );
  int **matrix1,**matrix2,**matrix3;
  matrix1 = CreateMatrix(height1, width1);
  matrix2 = CreateMatrix(height2, width2);
  matrix3 = CreateMatrix(height1, width2);
  MatrixInput(matrix1, height1, width1);
  printf("Now, please enter the attributes of the second matrix\n" );
  MatrixInput(matrix2, height2, width2);
  printf("First matrix\n" );
  PrintMatrix(matrix1, height1, width1);
  printf("Second matrix\n" );
  PrintMatrix(matrix2, height2, width2);
  multiplyMatrices(matrix1, height1, width1, matrix2, height2, width2, matrix3);
  printf("resulting matrix is \n" );
  PrintMatrix(matrix3, height1, width2);



  return 0;
}
