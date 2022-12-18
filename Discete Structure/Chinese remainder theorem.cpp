#include<iostream>
using namespace std;
int CRT(int a1,int a2,int a3,int m1,int m2,int m3)
{
    int M = m1*m2*m3;
    int M1 = M/m1;
    int M2 = M/m2;
    int M3 = M/m3;
    int i=1,j=1,k=1;
    
    while(((M1*i)%m1)!=1)
    {
        i++;    
    }
    while(((M2*j)%m2)!=1)
    {
        j++;    
    }
    while(((M3*k)%m3)!=1)
    {
        k++;    
    }
    
    int M1i=i;
     int M2i=j;
    int M3i=k;

int X = (a1*M1*M1i + a2*M2*M2i + a3*M3*M3i )%M;


return X;    
} 

int main()
{
int a1,a2,a3,m1,m2,m3;

cout<<"Enter the values of a1 ,a2,a3 :";
cin>>a1>>a2>>a3;

cout<<"Enter the values of m1 ,m2,m3 :";
cin>>m1>>m2>>m3;

int x = CRT(a1,a2,a3,m1,m2,m3);
cout<<"X :" << x;

return 0;    
}
