#include<stdio.h>
#define N 100
typedef struct
{
	int p,a,b,w;
	
}p;
int n;
p q[N],t;
float w,tw,tt;
int main()
{
	printf("Enter the no of processes:");
	scanf("%d",&n);
	printf("Enter arrival time and burst time for each proceeses:\n");
	for(int i=0;i<n;i++)
	{
		printf("Process %d:",i+1);
		scanf("%d%d",&q[i].a,&q[i].b);
		q[i].p=i+1;
		
	}
	for(int t=0,c=-1,i=0;i<n;)
	{
		if(q[i].a <=t && q[i].b<0)
		{
			if(c==-1||q[i].b<q[c].b|| q[i].b==q[c].b&& q[i].a<q[c].a)
			{
				c=i;
			}
			i++;
		}
		else
		t++;
		if(c!=-1)
		{
			q[c].b--;
			if(q[c].b == 0){
				tw+=t+1 - q[c].a - q[c].w;
				tt+=t+1-q[c].a;
				c = -1;
			}

			for(int j=0;j<n;j++){
				if(q[j].a<=t && q[j].b>0 && j!=c){
					q[i].w++;
				}
			}
		}
		q[c].w = t+1-q[c].a;
	}
	printf("\n Processes \t Arrival Time \t Burst time\t Waiting time");
	for(int i=0;i<n;i++)
	{
		printf("\n P[%d]\t \t %d\t\t %d\t\t\t %d\t",q[i].p,q[i].a,q[i].b,q[i].w);
		
	}
	printf("\nAVerage waiting time :%d",tw/n);
	printf("\nAverage turn around time:%d",tw/n);
	return 0;
	
}
