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

void inputf(int choice)//this function checks if the input are numbers, if not recursively calls the function again
{
  char term;
  double real1,real2,imag1,imag2;
  printf("Now enter the complex numbers\nenter the real part\n" );
  if(scanf("%lf%c", &real1, &term) != 2 || term != '\n')
  {
    printf("Wrong input, try again\n" );
    fseek(stdin,0,SEEK_END);
    inputf(choice);
  }
  printf("now enter the imaginary part of the first number\n" );
  if(scanf("%lf%c", &imag1, &term) != 2 || term != '\n')
  {
    printf("Wrong input, try again\n" );
    fseek(stdin,0,SEEK_END);
    inputf(choice);
  }
  printf("Now enter the 2nd complex number\nenter the real part\n" );
  if(scanf("%lf%c", &real2, &term) != 2 || term != '\n')
  {
    printf("Wrong input, try again\n" );
    fseek(stdin,0,SEEK_END);
    inputf(choice);
  }
  printf("now enter the imaginary part of the second number\n" );
  if(scanf("%lf%c", &imag2, &term) != 2 || term != '\n')
  {
    printf("Wrong input, try again\n" );
    fseek(stdin,0,SEEK_END);
    inputf(choice);
  }

  //at this point switch statement determines what to do based on the input 'choice' in main, and calls the appropriate function
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


int main(int argc, char const *argv[])
{
    int choice;

    printf("what would you like to do? \n-press 1 for addition\n-press 2 for substraction\n-press 3 for multiplication\n-press 4 for division\n");

    if (scanf("%d", &choice) != (1 || 2 || 3 || 4))
    {
      printf("you need to enter 1,2,3 or 4\n" );
      fseek(stdin,0,SEEK_END);
      main(argc, argv);

    }//If input is not 1,2,3 or 4 it recursively calls the function again
    else
    {
      inputf(choice);//If one of those 4 is pressed, then it calls the inputf function
    }

    return 0;
}
