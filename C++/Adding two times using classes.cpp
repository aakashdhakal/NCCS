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
			cout<<"The added time is "<<hour<<":"<<minute<<":"<<second<<endl;
		}
		friend void addTimeV(Time,Time);
		friend void addTimeR(Time&,Time&);
		friend void addTime(Time*,Time*);
};

Time addTime (Time t1,Time t2){
	Time sum;
	sum.hour = t1.hour + t2.hour;
	sum.minute = t1.minute + t2.minute;
	sum.second = t1.second + t2.second;
	
	if(sum.second >= 60){
		sum.minute += sum.second/60;
		sum.second %= 60;
	}
	if(sum.minute >=60){
		sum.hour += sum.minute/60;
		sum.minute %= 60;
	}
	
	return sum;
}
Time& addTimeR (Time& t1,Time& t2){
	Time sum;
	sum.hour = t1.hour + t2.hour;
	sum.minute = t1.minute + t2.minute;
	sum.second = t1.second + t2.second;
	
	if(sum.second >= 60){
		sum.minute += sum.second/60;
		sum.second %= 60;
	}
	if(sum.minute >=60){
		sum.hour += sum.minute/60;
		sum.minute %= 60;
	}
	
	return sum;
}
Time* addTime (Time* t1 ,Time* t2 ){
	Time* sum;
	sum -> hour = t1 -> hour + t2 -> hour;
	sum -> minute = t1 -> minute + t2 -> minute;
	sum -> second = t1 -> second + t2 -> second;
	
	if(sum -> second >= 60){
		sum -> minute += sum -> second/60;
		sum -> second %= 60;
	}
	if(sum -> minute >=60){
		sum -> hour += sum -> minute/60;
		sum -> minute %= 60;
	}
	
	return sum;
}

int main(){
	
	Time t1,t2,sum;
	t1.readData();
	t2.readData();
	cout<<"Pass by Value"<<endl;
	Time sum = addTime(t1,t2);
	cout<<"Pass by Reference"<<endl;
	Time& sum = addTime(t1,t2);
	cout<<"Pass by Address"<<endl;
	
	Time* sum = addTime(&t1,&t2);
	
	return 0;
}
