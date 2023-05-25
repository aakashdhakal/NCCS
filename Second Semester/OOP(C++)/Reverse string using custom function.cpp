#include<iostream>
#include<string>
using namespace std;

string revStr(string str){
int i, n = str.length();
string temp="";

for(i=n-1; i>=0; i--){
	temp = temp + str[i];
}
return temp;
}

int main(){
	string str;
	cout<<"Enter the required string value: ";
	//cin>>str;
	getline(cin,str);
	cout<<"You have entered: "<<str<<endl;
	cout<<"The reverse of your string will be: "<<revStr(str)<<endl;
	return 0;
}