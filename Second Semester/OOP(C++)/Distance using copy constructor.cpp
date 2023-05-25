#include<iostream>
using namespace std;

class Distance{
	int feet;
	int inch;
	public:
		Distance(){}
		Distance(int f, int i){
		 	f = feet;
		 	i = inch;
		 }
		Distance(Distance& d){
		 	feet = d.feet;
		 	inch = d.inch;
		 }
		void inData(){
			cout<<"Enter the length in feet: ";
			cin>>feet;
			cout<<"Enter the length in inch: ";
			cin>>inch;
		}
		void outData(){
			cout<<"The sum of the two distances is: "<<feet<<" feet "<<inch<<" inch "<<endl;
		}
		Distance sumDistance(Distance& d){
			Distance sum;
			sum.feet = feet + d.feet;
			sum.inch = inch + d.inch;
			
		if(sum.inch >= 12) {
        sum.feet += 1;
        sum.inch %= 12;
    } 
    return sum;
		}
		
};

int main(){
	Distance d1,sum;
	d1.inData();
	Distance d2(d1);
	sum = d1.sumDistance(d2);
	sum.outData();
	return 0;
}