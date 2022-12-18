#include<iostream>
using namespace std;
struct Distance{
	int meter;
	int centimeter;
};
void inputDistance(Distance &);
void outputDistance(Distance);
Distance addDistance(Distance, Distance);

int main(){
	Distance d1,d2;
	inputDistance(d1);
	inputDistance(d2);
	
	Distance sum = addDistance(d1,d2);
	outputDistance(sum);
	return 0;
	
}
void inputDistance( Distance &d){
	cout<<"Enter the distance in meters:";
	cin>>d.meter;
	cout<<"Enter the distance in centimeters:";
	cin>>d.centimeter;
}

void outputDistance(Distance d){
	cout<<"The total distance is "<<d.meter<<" m "<<d.centimeter<<" cm "<<endl;
	
}
Distance addDistance(Distance d1, Distance d2){
	Distance sum;
	sum.meter = d1.meter + d2.meter;
	sum.centimeter = d1.centimeter + d2.centimeter;
	
	if(sum.centimeter >= 100){
		sum.meter += 1;
		sum.centimeter %= 100;
	}
	return sum;
}