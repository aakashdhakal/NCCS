#include <iostream>
#include<fstream>
using namespace std;


int main(){
	string text;
	fstream file;
	file.open("abc.txt", ios::in);
	
	while(!file.eof()){
		file >> text;
		
		cout<<text<<" ";
	}
}

