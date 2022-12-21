#include<iostream>
using namespace std;

struct Distance{
	private:
	int meter;
	int centimeter;
	public:
	void inputDistance(){
		cout<<"Enter the distance in meters:";
		cin>>meter;
		cout<<"Enter the distance in centimeters:";
		cin>>centimeter;
	}

	void outputDistance(){
		cout<<"The total distance is "<<meter<<" m "<<centimeter<<" cm "<<endl;
	
	}
	Distance addDistance(Distance& d){
	Distance sum;
	sum.meter = d.meter + d.meter;
	sum.centimeter = d.centimeter + d.centimeter;
	
	if(sum.centimeter >= 100){
		sum.meter += 1;
		sum.centimeter %= 100;
	}
	return sum;
}
};


int main(){
	Distance d1,d2,sum;
	d1.inputDistance();
	d2.inputDistance();
	sum = d1.addDistance(d2);
	sum.outputDistance();
	return 0;
	
}

