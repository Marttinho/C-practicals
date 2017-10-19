#include<stdio.h>
#include<math.h>

double F(double x,double y); //function prototype to define f(x,y)

int main(int argc, char const *argv[])
{
  double y,x,y1,n,h,f,k1,k2,k3,k4;
  x = 0;
  y = 1;
  n = 5;
  h = 0.01;
  FILE *file = fopen("file.txt", "w");//opeining the file for write purposes
  if (file == NULL)
  {
      printf("Error opening file!\n");
      return 0;
  }

  printf("\033[31mWelcome to Runge Kutta 4th order method\033[30m\n" );
  for (double i = 0.0; i <= 5.0; i+=h)
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
    }
  fclose(file);//closing the file

    return 0;
}

double F(double x, double y)
{
  return -y;


}
