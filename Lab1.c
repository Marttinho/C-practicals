#include <stdio.h>      /* Standard Library of Input and Output */
#include <complex.h>    /* Standard Library of Complex Numbers */


void addition(_Complex double z1,_Complex double z2)
{
  printf("in function\n");
  _Complex double sum = z1 + z2;
  printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));
}

void substraction(_Complex double z1, _Complex double z2)
{
  _Complex double sum = z1 - z2;
  printf("The sum: Z1 - Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));
}

void multiplication(_Complex double z1, _Complex double z2)
{
  _Complex double sum = z1 * z2;
  printf("The sum: Z1 * Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));
}

void division(_Complex double z1, _Complex double z2)
{
  _Complex double sum = z1 / z2;
  printf("The sum: Z1 / Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));
}

int main(int argc, char const *argv[])
{

    double real1=2,real2=2,imag1=2,imag2=2;
    int choice;

    printf("what would you like to do? \n + - / * \n");

    scanf("%d", &choice);

    /*printf("Now enter the complex numbers\nenter the real part\n" );
    scanf("%lf", &real1);
    printf("now enter the imaginary part of the first number\n" );
    scanf("%lf", &imag1);
    printf("Now enter the 2nd complex number\nenter the real part\n" );
    scanf("%lf", &real2);
    printf("now enter the imaginary part of the second number\n" );
    scanf("%lf", &imag2);*/


    _Complex double z1 = real1 + imag1 * I;
    _Complex double z2 = real2 - imag2 * I;
    printf("choice is %d\n", choice);
    switch (choice)
    {
      case 1:
        printf("here\n");
        addition(z1, z2);
        break;
      case 2:
        substraction(z1, z2);
        break;
      case 3:
        multiplication(z1, z2);
        break;
      case 4:
        division( z1, z2);
        break;
    }

    return 0;
}
