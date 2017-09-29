#include<stdio.h>
#include<math.h>


int factorial(int n)
{
  //printf("computing factorial for %d\n", n);
   int fact = 1;
   if (n==0)
   {
    // printf("the factorial is %d\n", fact);
     return fact;
   }
   else if(n==1)
   {
    //  printf("the factorial is %d\n", fact);
      return fact;
   }
   else
   {
      fact = n * factorial(n-1);
    //  printf("the factorial is %d\n", fact);
      return fact;
   }
}

double eexx(int n, int r)
{
  double tempn = factorial(n);
  double tempr = factorial(r);
  int temps = n-r;
  double tempa = factorial(temps);

  double partial = tempn/(tempr*tempa);
//printf("here %lf,%lf,%lf,%lf\n", tempn,tempr,tempa,partial);
  return partial;
}


int main(int argc, char const *argv[])
{
  printf("Enter your n\n" );
  //char n[1];
  int n,a,b;
  scanf("%d", &n);
  printf("Enter your a\n" );
  scanf("%d", &a);
  printf("Enter your b\n" );
  scanf("%d", &b);
  //int n=3, a=2,b=2;
  double partialans, axs, bxs, overall=0;
  double nx = n;
  for (int i = 0; i <= n; i++)
  {

    double ax = a;
    double bx = b;
    double y = n-i;
    double r = i;

    partialans = eexx(n,i);
    //printf("%lf\n", partialans);
    //printf("ax is %lf\n",ax );
    axs = pow(ax, y);
    bxs = pow(bx, r);
    //printf("ax is %lf\n",axs );

    //printf("partial answers are %lf,%lf,%lf,%lf\n", partialans, ax, y, bx);
    overall = overall + partialans * axs * bxs;
    printf("result so far %lf\n", overall);

  }

  //binomial expansion
  //(a+b)^n
  printf("%lf\n", overall);




  return 0;
}
