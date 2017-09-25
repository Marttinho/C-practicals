#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Enter theta\n");
	char theta[5];
	scanf("%s", theta);

	double sinus,series;

	double ftemp = atof(theta);
	double temp= ftemp;
	sinus = sin(ftemp);
	printf("The sin of your Theta is %f\n", sinus);

	//mclaurin series
	double x=3;
	int counter=1;
	series = ftemp;
	double d = 0.00001;
	printf("Intermediate res is %lf \n", fabs(sinus - fabs(series)));

	while (fabs(sinus - fabs(series)) > d)
	{
		//double pow(double ftemp,double x);
		ftemp = pow(ftemp, x);
		int fact,i,n;
		fact = 1;  
		for(i = 1; i <= x; i++)
		   {
		       fact = fact*i;		
		   }
		double y = ftemp/fact;
		printf("%lf\n",ftemp );
		printf("%lf\n",y );
		if (counter % 2)
			{
				series = series - y;
				printf("here\n");
			}
		else
			{ 
				series = series + y;
				printf("in else\n");

			}
		ftemp = temp;
		x = x+2;
		counter = counter + 1;
		printf("The mclaurins series is %lf \n", series);
		printf("sinus is %lf\n", sinus);
		printf("Intermediate res is %lf \n", fabs(sinus - fabs(series)));

	}
	printf(" You need this many members of mclaurins series %d\n", counter);
	return 0;
}