//gcd (Basic Euclidean Algorithm)

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a==0)
    return b;
    return gcd(b%a,a);
}

int main(){
    int a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    cout<<"The gcd of given numbers is "<<gcd(a,b)<<endl;
    return 0;
}