#include<iostream>
#include<string>
using namespace std;

class myException{
	
	string expert;
	public:
		myException(string text){
			expert = text;
		}
		
		string what(){
			
			return expert;
		}
};

int main(){
	int a;
	cin >> a;
	try{
		if(a<0){
			throw myException("Negative");
		}
			cout << a <<endl;
		}

catch(myException e){
	cout << e.what() << endl;
}
return 0;
}