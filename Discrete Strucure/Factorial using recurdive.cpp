#include<iostream>
using namespace std;
 long fact(int n)
{
    if(n==0)
    {
        return 1;
        
    }
    else
    {
        return n*fact(n-1);    
    }
}
int main()
{
 long n ,result;
cout<<"Enter any Number ";
cin>>n;
result = fact(n);
cout<<"Factorial of "<<n<<" is "<<result;
    
    return 0;
}