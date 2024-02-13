//not completed
#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int top;
    char arr[100];

public:
    Stack()
    {
        top = -1;
    }
    void push(char x)
    {
        arr[++top] = x;
    }
    char pop()
    {
        return arr[top--];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    char peek(){
        return arr[top];
    }
    void printStack()
    {
    	    for(i=0;i<=arr.length;i++){
    	cout <<arr[i]<<endl;
	}
	}
};

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    Stack s;
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == 'a'){
            s.push(str[i]);
        }
        else if(str[i] == 'b'  && count < 3 ){
        	s.push(str[i]);
        	count++;
		}
        else if(str[i] == 'c'){
        	if(s.peek() == 'a'){
        		s.pop();
			}else{
				cout<<"Not Accepted"<<endl;
				return 0 ;
			}
		}
        i++;
    }
s.printStack();
 if (s.isEmpty())
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Not accepted" << endl;
    }
    return 0;
}
