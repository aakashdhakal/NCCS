#include<iostream>
using namespace std;
int count=0;

int partition(int A[],int l, int r)
{
    int x=l;
    int y=r;
    int pivot = A[l];
    
    count = count+3;
    
    while(x<y)
    {
        while(A[x]<=pivot)
        {
            x++;
            count =count+3;    
        }
    
        while(A[y]>pivot)
        {
             y--;
            count =count+3;        
        }
    
        if(x<y)
        {
            int t = A[x];
            A[x]=A[y];
            A[y] = t;
            count =count+4;    
            
        }
        
    }
     A[l] =A[y];
    A[y]= pivot;
    count = count+3;
    return y;
    
    
}

void QuickSort(int A[],int l ,int r)
{
    if(l<r)
    {
        count++;
    int p = partition(A,l,r);
    QuickSort(A,l,p-1);
    QuickSort(A,p+1,r);
        
    }    
}


int main()
{
    
//int a[9] = {100,22,12,45,809,130,170,10,200};
int a[9] = {1,200,3,4,5,60,7,8,9};


cout<<"Before sorting: \n";
   for(int i=0 ;i<9 ;i++)
        {
    cout<<a[i]<<"\t" ;
        }
        
    cout<<endl;
    
QuickSort(a,0,8);

cout<<"After sorting: \n";
 for(int i=0 ;i<9 ;i++)
        {
    cout<<a[i]<<"\t" ;
        }
cout<<endl;        
cout<<"No. of Steps required : "<<count;        
        
return 0;

}
