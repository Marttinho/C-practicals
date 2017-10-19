#include<stdio.h>

double F(double x,double y); //function prototype to define f(x,y)
void inputf();//input function, checking that step-size h is bigger than 0

int main(int argc, char const *argv[])
{
  double y,x,y1,n,h,f,k1,k2,k3,k4;
  x = 0;
  y = 1;
  inputf(&h);
  while (h<0)
  {
    inputf(&h);//if step-size enter is smaller than 0 than keep asking
  }
  FILE *file = fopen("file.txt", "w");//opeining the file for write purposes
  if (file == NULL)
  {
      printf("Error opening file!\n");
      return 0;
  }

  printf("\033[31mWelcome to Runge Kutta 4th order method\033[30m\n" );
  long double i = 0;
  while (((double)i) <= 5.0)//casting long double to double, otherwise for some h it wont stop properly, because of floating point problem
    {
        f = F(x,y);//call the F function on x,y
        k1 = h * f;//computing K1
        f = F(x+h/2,y+k1/2);
        k2 = h * f;//computing K2
        f = F(x+h/2,y+k2/2);
        k3 = h * f;//computing K3
        f = F(x+h,y+k3);
        k4 = h * f;//computing K4
        y1 = y + (( k1 + 2*k2 + 2*k3 + k4)/6);
        printf("x is %.5lf, and y is %.5lf\n", x,y);//printing the intermediate result on screen
        fprintf(file, "%.3lf \t %.3lf\n",x,y);//printing the intermediate result into a file
        y=y1;//assigning the new y1 to y
        x+=h;//incrementing x by the step-size h
        i+=h;

    }
  fclose(file);//closing the file

    return 0;
}

double F(double x, double y)
{
  return -y;

}

void inputf(double *h)
{
  char term;
  printf("Enter the step step-size\n" );
  if(scanf("%lf%c", h, &term ) != 2 || term != '\n')
  {
    printf("it can only be a number 0< and <5\n");
    fseek(stdin,0,SEEK_END);
    inputf(h);return;
  }
}
