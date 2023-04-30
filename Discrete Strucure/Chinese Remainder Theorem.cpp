

#include<iostream>
using namespace std;
int CRT(int a1,int a2,int a3,int a4,int m1,int m2,int m3, int m4)
{
    int M = m1*m2*m3*m4;
    int M1 = M/m1;
    int M2 = M/m2;
    int M3 = M/m3;
    int M4 = M/m4;
    int i=1,j=1,k=1,l=1;
    
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
     while(((M4*l)%m4)!=1)
    {
        l++;    
    }
    
    int M1i=i;
     int M2i=j;
    int M3i=k;
    int M4i = l;

int X = (a1*M1*M1i + a2*M2*M2i + a3*M3*M3i+ a4*M4*M4i)%M;


return X;    
} 

int main()
{
int a1,a2,a3,m1,m2,m3,a4,m4;

cout<<"Enter the values of a1 ,a2,a3,a4 :";
cin>>a1>>a2>>a3>>a4;

cout<<"Enter the values of m1 ,m2,m3 ,m4:";
cin>>m1>>m2>>m3>>m4;

int x = CRT(a1,a2,a3,a4,m1,m2,m3,m4);
cout<<"X :" << x;

return 0;    
}