#include<stdio.h>
int main()
{
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	printf("Enter total no.of processes:");
	scanf("%d",&n);
	printf("\n Enter burst time of processes:\n");
	for(i=0;i<n;i++)
	{
		printf("\n P[%d]:",i+1);
		scanf("%d",&bt[i]);
		
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		wt[i]+=bt[j];
	}
	printf("\n Processes \t Burst time \t Waiting time\t Turn around time");
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		printf("\n P[%d]\t \t %d\t\t %d\t\t\t %d\t",i+1,bt[i],wt[i],tat[i]);
		
	}
	avwt/=i;
	avtat/=i;
	printf("\nAVerage waiting time :%d",avwt);
	printf("\nAverage turn around time:%d",avtat);
	return 0;
	
}
