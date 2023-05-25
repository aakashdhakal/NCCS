#include<iostream>
using namespace std;

class Time{
	int hour;
	int min;
	int sec;
	public:
		Time(){
		}
                                                                                                               
		Time operator ++(){
			sec++;
			min += sec/60;
			hour += min/60;
			sec %= 60;
			min %= 60;
			return *this;
		}
		Time operator ++(int){
			sec++;
			min += sec/60;
			hour += min/60;
			sec %= 60;
			min %= 60;
			return *this;
		}
		void inTime(){
			cout<<"Please enter time in hour:minute:second: ";
			cin>>hour>>min>>sec;
		}	
		
		void outTime(){
			cout<<"The time is "<<hour<<" : "<<min<<" : "<<sec<<endl;
		}
};

int main(){
	Time t1;
	t1.inTime();
	cout<<"Pre-Increment"<<endl;
	cout<<"During increment"<<endl;
	(++t1).outTime();
	cout<<"After increment"<<endl;
	t1.outTime();
	
	cout<<"Post-Increment"<<endl;
	cout<<"During increment"<<endl;
	(t1++).outTime();
	cout<<"After increment"<<endl;
	t1.outTime();
	return 0;
}