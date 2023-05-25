#include<iostream>
#include<string>
using namespace std;

struct user {
    string name;
    double score;
};
int main ()
{
    int a;
    struct user ua0,ua1,ua2,ub0,ub1,ub2,a1,a2,a3;
   
    ua0.name="x1";
    ua0.score=0.8;
   
    ua1.name="x2";
    ua1.score=0.5;
   
    ua2.name="x3";
    ua2.score=0.4;
   
    ub0.name="x1";
    ub0.score=0.2;
   
    ub1.name="x2";
    ub1.score=0.8;
   
    ub2.name="x3";
    ub2.score=1.0;
   
    cout<<"Options \n Enter 1 for Union \n Enter 2 for for intersection \n Enter 3 for complement\n"<<endl;
    cin>>a;
   
    switch(a)
    {
        case 1:
            {
                if(ua0.name==ub0.name)
                {
                    a1.name=ua0.name;
                   
                    if(ua0.score>ub0.score)
                    {
                        a1.score=ua0.score;
                    }
                    else
                    {
                        a1.score=ub0.score;
                    }
                }
           
           
            if(ua1.name==ub1.name)
                {
                    a2.name=ua1.name;
                    if(ua1.score>ub1.score)
                    {
                        a2.score=ua1.score;
                    }
                    else
                    {
                        a2.score=ub1.score;
                    }
                }
           
            if(ua2.name==ub2.name)
           
                {
                    a3.name=ua2.name;
                    if(ua2.score>ub2.score)
                    {
                        a3.score=ua2.score;
                    }
                    else
                    {
                        a3.score=ub2.score;
                    }
                }
                cout<<"{"<<"("<<a1.name<<","<<a1.score<<")"<<"("<<a2.name<<","<<a2.score<<")"<<"("<<a3.name<<","<<a3.score<<")"<<"}"<<endl;
                    break;
                }
           
            break;
           
            case 2:
                {
           
                if(ua0.name==ub0.name)
                {
                    a1.name=ua0.name;
                   
                    if(ua0.score<ub0.score)
                    {
                        a1.score=ua0.score;
                    }
                    else
                    {
                        a1.score=ub0.score;
                    }
                }
           
           
            if(ua1.name==ub1.name)
                {
                    a2.name=ua1.name;
                    if(ua1.score<ub1.score)
                    {
                        a2.score=ua1.score;
                    }
                    else
                    {
                        a2.score=ub1.score;
                    }
                 }
           
            if(ua2.name==ub2.name)
           
                {
                    a3.name=ua2.name;
                    if(ua2.score<ub2.score)
                    {
                        a3.score=ua2.score;
                    }
                    else
                    {
                        a3.score=ub2.score;
                    }
                   
                }
                cout<<"{"<<"("<<a1.name<<","<<a1.score<<")"<<"("<<a2.name<<","<<a2.score<<")"<<"("<<a3.name<<","<<a3.score<<")"<<"}"<<endl;
                break;
            }
           
       
           
           
           
            case 3:
                {
                    a1.name=ua0.name;
                    a1.score=1-ua0.score;
                   
                    a2.name=ua1.name;
                    a2.score=1-ua1.score;
                   
                    a3.name=ua2.name;
                    a3.score=1-ua2.score;
                   
                    cout<<"{"<<"("<<a1.name<<","<<a1.score<<")"<<"("<<a2.name<<","<<a2.score<<")"<<"("<<a3.name<<","<<a3.score<<")"<<"}"<<endl;
                   
                    break;
                }
                default:
                    {
                        cout<<"Invalid Input"<< endl;
                    }
           
    }
   
   
}