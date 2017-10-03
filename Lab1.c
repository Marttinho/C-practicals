#include <stdio.h>      /* Standard Library of Input and Output */



void addition(double real1,double real2,double imag1,double imag2)
{
  printf("in addition function\n");
  double rsum = real1 + real2;
  double isum = imag1 + imag2;
  printf("The sum: %.2f%.2fi + %.2f%.2fi = %.2f %+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}//this one works

void substraction(double real1,double real2,double imag1,double imag2)
{
  printf("in substraction function\n");
  double rsum = real1 - real2;
  double isum = imag1 - imag2;
  printf("The sum: %.2f%.2fi - %.2f%.2fi = %.2f %+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}//working

void multiplication(double real1,double real2,double imag1,double imag2)
{
  printf("in multiplication function\n");
  double rsum = real1 * real2 - imag1 * imag2;
  double isum = imag1 * real2 + real1 * imag2;
  printf("The sum: %.2f%.2fi * %.2f%.2fi = %.2f %+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}

void division(double real1,double real2,double imag1,double imag2)
{
  printf("in division function\n");
  double rsum = real1 / real2;
  double isum = imag1 / imag2;
  printf("The sum: %.2f%.2fi / %.2f%.2fi = %.2f %+.2fi\n",real1,imag1,real2,imag2,rsum,isum);
}

int main(int argc, char const *argv[])
{

    double real1,real2,imag1,imag2;
    int choice;
    char sign1[1],sign2[1];

    printf("what would you like to do? \n + - * / \n");

    scanf("%d", &choice);

    printf("Now enter the complex numbers\nenter the real part\n" );
    scanf("%lf", &real1);
    /*printf("now enter the + or - for your first complex number\n" );
    scanf("%c", &sign1);*/
    printf("now enter the imaginary part of the first number\n" );
    scanf("%lf", &imag1);
    printf("Now enter the 2nd complex number\nenter the real part\n" );
    scanf("%lf", &real2);
    /*printf("now enter the + or - for your second complex number\n" );
    scanf("%c", &sign2);*/
    printf("now enter the imaginary part of the second number\n" );
    scanf("%lf", &imag2);


    //_Complex double z1 = real1 sign1 imag1 * I;
    //_Complex double z2 = real2 sign2 imag2 * I;
    printf("choice is %d\n", choice);
    switch (choice)
    {
      case 1:
        printf("here\n");
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

    return 0;
}
