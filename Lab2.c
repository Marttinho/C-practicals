#include <stdio.h>
#include <stdlib.h>

//function prototypes

int **CreateMatrix(int rows, int cols);
void MatrixInput(int **matrix, int rows, int cols);
void PrintMatrix(int **matrix, int rows, int cols);
void multiplyMatrices(int **matrix1,int height1,int width1,int **matrix2,int height2,int width2,int **matrix3);
void promptf(int* width1,int* width2,int* height1,int* height2);

int main(int argc, char const *argv[])
{
  int width1=0,width2=0,height1=0,height2=0;//initializing the values to 0
  printf("\033[31mWelcome to matrix multiplier\033[30m\n" );

  while ((width1 == 0 )||(width1 != height2))//while matrix multiplication condition not satisfied
  {                                          //keeps repeating the call for promptf function
    promptf(&width1,&width2,&height1,&height2);
  }
  printf("Now, please enter the attributes of the first matrix\n" );
  int **matrix1,**matrix2,**matrix3;
  matrix1 = CreateMatrix(height1, width1);//allocates memory for all three matrices, with dimensions based
  matrix2 = CreateMatrix(height2, width2);//on user input
  matrix3 = CreateMatrix(height1, width2);
  MatrixInput(matrix1, height1, width1);//call function to input values of 1st matrix
  printf("Now, please enter the attributes of the second matrix\n" );
  MatrixInput(matrix2, height2, width2);//call function to input values of 2nd matrix
  printf("First matrix\n" );
  PrintMatrix(matrix1, height1, width1);//prints off first matrix
  printf("Second matrix\n" );
  PrintMatrix(matrix2, height2, width2);//prints off second matrix
  multiplyMatrices(matrix1, height1, width1, matrix2, height2, width2, matrix3);//multiplies matrices
  printf("resulting matrix is \n" );
  PrintMatrix(matrix3, height1, width2);//prints off the 3rd matrix
  free(matrix1);//frees the memory for all 4 matrices
  free(matrix2);
  free(matrix3);



  return 0;
}


int **CreateMatrix(int rows, int cols)
{
  int **matrix = malloc(sizeof(int*) * rows);
  int row;
  for (row = 0; row < rows; row++) {
    matrix[row] = malloc(sizeof(int) * cols);
  }
  return matrix;
}//function to create a matrix, utilizing malloc, dynamic allocation of memory

void MatrixInput(int **matrix, int rows, int cols)
{
  int row, col;
  char term;
  for (row = 0; row < rows; row++)
  {
    for (col = 0; col < cols; col++)
    {
      printf("enter the element at row %d and col %d\n", row+1, col+1 );
      if(scanf("%d%c", &matrix[row][col], &term) != 2 || term != '\n')
      {
        printf("you have to enter numbers\n");
        fseek(stdin,0,SEEK_END);
        row=rows;col=cols;
        MatrixInput(matrix, rows, cols);break;
      }
    }
  }
}//function used to input values into matrices, using 2 loops

void PrintMatrix(int **matrix, int rows, int cols)
{
  int row, col;
  for (row = 0; row< rows; row++) {
    for (col = 0; col < cols; col++) {
      printf("%d ", matrix[row][col]);
    }
    printf("\n");
  }
}//function to print matrix, using again 2 loops, input to this function is
//matrix, the number of rows and number of collums

void multiplyMatrices(int **matrix1,int height1,int width1,int **matrix2,int height2,int width2,int **matrix3)
{
  int sum=0;
  for (int x = 0; x < height1; x++) {
      for (int y = 0; y < width2; y++) {
        for (int z = 0; z < height2; z++) {
          sum = sum + matrix1[x][z]*matrix2[z][y];
        }

        matrix3[x][y] = sum;
        sum = 0;
      }
    }
}//function to multiply matrices, input is the 2 matrices inputted by user
//and 3rd empty one which will be the one contatining multiplied values
void promptf(int* width1,int* width2,int* height1,int* height2)
{
  char term;
    printf("If you want to multiply matrices, the #collums in the first matrix has to be equal to #rows in the econd matrix\n");
    printf("enter the height of the first matrix\n" );
    if(scanf("%d%c", height1, &term ) != 2 || term != '\n')
    {
      printf("the dimensions of matrices have to be numbers\n");
      fseek(stdin,0,SEEK_END);
      promptf(width1,width2,height1,height2);

    }
    printf("enter the width of the first matrix\n" );
    if(scanf("%d%c", width1, &term ) != 2 || term != '\n')
    {
      printf("the dimensions of matrices have to be numbers\n");
      fseek(stdin,0,SEEK_END);
      promptf(width1,width2,height1,height2);

    }
    printf("enter the height of the second matrix\n" );
    if(scanf("%d%c", height2, &term ) != 2 || term != '\n')
    {
      printf("the dimensions of matrices have to be numbers\n");
      fseek(stdin,0,SEEK_END);
      promptf(width1,width2,height1,height2);

    }
    printf("enter the width of the second matrix\n" );
    if(scanf("%d%c", width2, &term ) != 2 || term != '\n')
    {
      printf("the dimensions of matrices have to be numbers\n");
      fseek(stdin,0,SEEK_END);
      promptf(width1,width2,height1,height2);

    }

}//function used to promt user to input the dimensions of the matrices, and checks them
//against the condtion for matrix multiplication in the main function
