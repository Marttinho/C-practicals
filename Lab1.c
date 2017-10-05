//By Martin Nahalka, 51444972
#include <stdio.h>      
#include <stdlib.h>



void addition(double real1,double real2,double imag1,double imag2)
{
  printf("in addition function\n");
  double rsum = real1 + real2;
  double isum = imag1 + imag2;
  printf("The sum: %.2f%+.2fi + %.2f%+.2fi = %.2f%+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}//function handling addition of complex numbers

void substraction(double real1,double real2,double imag1,double imag2)
{
  printf("in substraction function\n");
  double rsum = real1 - real2;
  double isum = imag1 - imag2;
  printf("The sum: %.2f%+.2fi - %.2f%+.2fi = %.2f%+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}//function handling substraction of complex numbers

void multiplication(double real1,double real2,double imag1,double imag2)
{
  printf("in multiplication function\n");
  double rsum = real1 * real2 - imag1 * imag2;
  double isum = imag1 * real2 + real1 * imag2;
  printf("The sum: %.2f%+.2fi * %.2f%+.2fi = %.2f%+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}//function handling multiplication of complex numbers

void division(double real1,double real2,double imag1,double imag2)
{
  printf("in division function\n");
  double rsum = (real1*real2 + imag1*imag2)/(real2*real2+imag2*imag2);
  double isum = (imag1*real2 - real1*imag2)/(real2*real2+imag2*imag2);
  printf("The sum: %.2f%+.2fi / %.2f%+.2fi = %.2f%+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}//function handling division of complex numbers

int main(int argc, char const *argv[])
{
    double real1,real2,imag1,imag2;
    int choice;

    printf("what would you like to do? \n-press 1 for addition\n-press 2 for substraction\n-press 3 for multiplication\n-press 4 for division\n");

    if (scanf("%d", &choice) != (1 || 2 || 3 || 4))
    {
      printf("you need to enter 1,2,3 or 4\nexiting\n" );
    }
    else
    {
    printf("Now enter the complex numbers\nenter the real part\n" );
    scanf("%lf", &real1);
    printf("now enter the imaginary part of the first number\n" );
    scanf("%lf", &imag1);
    printf("Now enter the 2nd complex number\nenter the real part\n" );
    scanf("%lf", &real2);
    printf("now enter the imaginary part of the second number\n" );
    scanf("%lf", &imag2);
    //switch statement for determining what the user wants to do
    switch (choice)
      {
      case 1:
        addition(real1, real2, imag1, imag2);
        break;
      case 2:
        substraction(real1, real2, imag1, imag2);
        break;
      case 3:
        multiplication(real1, real2, imag1, imag2);
        break;
      case 4:
        division(real1, real2, imag1, imag2);
        break;
      }
    }

    return 0;
}
