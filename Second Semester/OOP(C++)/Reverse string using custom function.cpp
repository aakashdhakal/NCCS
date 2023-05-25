#include<iostream>
#include<string.h>

using namespace std;

string strRev(string& str){
	int i,n=0,len=0;
	char tempStr;
	len = str.length();
	n = len-1;
	
	for(i=0 ; i<=(len/2)-1 ; i++){
		tempStr = str[i];
		str[i] = str[n];
		str[n] = tempStr;
		n--;
	}
	return str;
}

int main(){
	string str;
	cout<<"Enter the desired string: ";
	cin>>str;
	//getline (cin, str);
		cout<<"The given string is: "<<str<<endl;
	strRev(str);
	cout<<"The reverse of the given string is: "<<str<<endl;
	return 0;	                                               
}