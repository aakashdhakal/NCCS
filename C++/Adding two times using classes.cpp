#include<iostream>
using namespace std;

class Time{
	private:
		int hour;
		int minute;
		int second;
	public:
		void readData(){
			cout<<"Enter the time in hour : minute : second = ";
			cin>>hour>>minute>>second;
		}
		void showData(){
			cout<<"The given time is "<<hour<<":"<<minute<<":"<<second<<endl;
		}
		friend void addTime(Time t1, Time t2);
};

void addTime (Time t1, Time t2){
	Time t3;
	t3.hour = t1.hour + t2.hour;
	t3.minute = t1.minute + t2.minute;
	t3.second = t1.second + t2.second;
	
	if(t3.second >= 60){
		t3.minute += t3.second/60;
		t3.second %= 60;
	}
	if(t3.minute >=60){
		t3.hour += t3.minute/60;
		t3.minute %= 60;
	}
	
	cout<<"The sum of two times is "<<t3.hour<<":"<<t3.minute<<":"<<t3.second<<endl;
}

int main(){
	
	//passing by value
	Time t1,t2;
	cout<<"Passing by value"<<endl;
	cout<<"----------------"<<endl;
	t1.readData();
	t2.readData();
	t1.showData();
	t2.showData();
	addTime(t1,t2);
	
	//passing by address
	Time *t3 = new Time,*t4 = new Time;
	cout<<"Passing by address"<<endl;
	cout<<"----------------------"<<endl;	
	t3 -> readData();
	t4 -> readData();
	t3 -> showData();
	t4 -> showData();
	addTime(*t3,*t4);
	
	//passing by reference
	Time &t5 = *t3;
	Time &t6 = *t4;
	cout<<"Passing by reference"<<endl;
	cout<<"----------------------"<<endl;
	t5.readData();
	t6.readData();
	t5.showData();
	t6.showData();
	addTime(t5,t6);
	return 0;
}
