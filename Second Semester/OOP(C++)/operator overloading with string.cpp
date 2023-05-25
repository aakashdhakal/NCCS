#include<iostream>
#include<string>
using namespace std;

class Distance{
	int feet;
	int inch;
	public:
		Distance(){
		}
		Distance(int f, int i){
			f = feet;
			i = inch;
		}
		Distance operator +(Distance d2){
		Distance d3;
		d3.inch = inch + d2.inch;
		d3.feet = feet + d2.feet; + d3.inch/12;
		d3.inch %=12;
		return d3;
		}
			void inDis(){
			cout<<"Enter the distance in feet: ";
			cin>>feet;
			cout<<"Enter the distance in inch: ";
			cin>>inch;
		}
		
		void display(){
			cout<<"Added feet: "<<feet<<endl;
			cout<<"Added feet: "<<inch<<endl;
		}
};

class String{
	string text;
	
	public:
		String(){
		}
		String(string t){
			text = t;
		}
		String operator +(String s2){
			String s3;
			s3.text = text + s2.text;
			return s3;
		}
		
		void display(){
			cout <<"Added text: "<<text<<endl;
		}
		void inStr(){
			cout<<"Enter the string: ";
			cin>>text;
		}
		
};

int main(){
	Distance d1,d2;
	String s1,s2;
	d1.inDis();
	d2.inDis();
	s1.inStr();
	s2.inStr();
	Distance d3 = d1+ d2;
	String s3 = s1 + s2;
	d3.display();
	s3.display();
	return 0;
}