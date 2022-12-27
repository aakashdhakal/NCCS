#include<iostream>
using namespace std;

class Farenheit{
	float f;
	public:
		friend void operator >> (istream& fin, Farenheit& fobj);
		friend void operator << (ostream& fout, Farenheit& fobj);
		
		operator float(){
			return (f-32)*5/9;
		}
};

void operator >> (istream& fin, Farenheit& fobj){
	fin >> fobj.f;
}

void operator << (ostream& fout, Farenheit& fobj){
	fout << fobj.f;
}

class Celsius{
	float c;
	public:
		Celsius(){
		}
		friend void operator >> (istream& fin, Celsius& fobj);
		friend void operator << (ostream& fout, Celsius& fobj);
		
		Celsius(Farenheit& f){
			c = f;
		}
};

void operator >> (istream& fin, Celsius& fobj){
	fin >> fobj.c;
}

void operator << (ostream& fout, Celsius& fobj){
	fout << fobj.c;
}
int main(){
	Farenheit f1;
	Celsius c1;
	cout<<"Enter the temperature in Farenheit: ";
	cin>>f1;
	cout<<"The temperature in Farenheit is: ";
	cout<<f1;
	c1 = f1;
	cout<<"The temperature in celsius is: ";
	cout<<c1;
	return 0;

}