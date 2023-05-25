#include<iostream>
#include<string>
using namespace std;

template<class T>
class stack{
	int top;
	T st[100];
	public:
		stack(){
			top = -1;
		}
		void push(T i){
			st[++top] = i;
		}
		
		T pop(){
			return st[top--];
		}
};

int main() {
	
	stack<int>int_stack;
	stack<string>str_stack;
	
	int_stack.push(77);
	str_stack.push("oop");
	str_stack.push("Stack");
	int_stack.push(99);
	cout<<int_stack.pop()<<endl;
	cout<<str_stack.pop()<<endl;
	cout<<str_stack.pop()<<endl;
	return 0;
}