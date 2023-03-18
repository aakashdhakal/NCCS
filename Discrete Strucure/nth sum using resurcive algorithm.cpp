#include<iostream>
using namespace std;
 long Sum(int n)
{
    if(n==1)
    {
        return 1;
        
    }
    else
    {
        return n+Sum(n-1);    
    }
}
int main()
{
 long n ,result;
cout<<"Enter any number ";
cin>>n;
result = Sum(n);
cout<<"Sum of first "<<n<<" natural numbers is "<<result;
    
    return 0;
}