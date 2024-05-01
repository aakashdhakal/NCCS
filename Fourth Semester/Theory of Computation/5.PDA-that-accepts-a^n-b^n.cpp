#include<iostream>

using namespace std;

struct stack{
    char A[10];
    int top=-1;
}S;

void push(char a){
    S.A[++S.top]=a;
}
void pop(){
    S.top--;
}

int main(){
    string str;
    int len,state=0;
    cout<<"Enter a string :";
    cin>>str;
    len=str.length();
    for(int i=0;i<len;i++){
        if(state==0 && str[i]=='a' &&S.A[S.top]=='a'){
            push('a');
            state=0;}
        else if(state==0 && str[i]=='a' &&S.top==-1){
            push('a');
            state=0;}
        else if(state==0 && str[i]=='b' &&S.A[S.top]=='a'){
            pop();
            state=1;}
        else if(state==1 && str[i]=='b' && S.A[S.top]=='a'){
            pop();
            state=1;}
        else{
            cout<<"String rejected";
            return 0;
        }
        }
    
    if(S.top==-1)
        cout<<"String accepted";
    else
        cout<<"String rejected";
}
