#include<iostream>

using namespace std;


int main()
{
    bool p[4]={true ,true ,false,false};
    bool q[4]={true,false,true,false};
    
    cout<<"P\t Q \t (not P) \t (P and Q) \t (P or Q) \t (p Xor Q)\n";
    cout<<"............................................................................\n";
    
    for(int i=0;i<4;i++)
    {
        cout<<p[i]<<"\t"<<q[i]<<"\t\t"<<(1-p[i])<<"\t\t"<<(p[i]&q[i])<<"\t\t"<<(p[i]|q[i])<<"\t\t"<<(p[i]^q[i])<<"\n\n";
    }
    
}