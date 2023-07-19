#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 10

int main()
{
		 float a[SIZE][SIZE], x[SIZE], ratio;
		 int i,j,k,n;
		 printf("Enter number of variables: ");
		 scanf("%d", &n);
		 /* 2. Reading Augmented Matrix */
		 printf("Enter coefficients of Augmented Matrix:\n");
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n+1;j++)
			  {
				   printf("a[%d][%d] = ",i,j);
				   scanf("%f", &a[i][j]);
			  }
		 }
		 /* Applying Gauss Jordan Elimination */
		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("Mathematical Error!");
			  }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=n+1;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 /* Obtaining Solution */
		 for(i=1;i<=n;i++)
		 {
		  	x[i] = a[i][n+1]/a[i][i];
		 }
		 /* Displaying Solution */
		 printf("\nSolution:\n");
		 for(i=1;i<=n;i++)
		 {
		  	printf("x[%d] = %0.3f\n",i, x[i]);
		 }
		 getch();
		 return(0);
}
