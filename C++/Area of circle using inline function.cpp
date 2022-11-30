#include<iostream>
using namespace std;

inline float area(float radius){
	float area;
	area = 3.1415*radius*radius;
	return area;
	
}
int main(){
	float radius;
	cout<<"Enter the radius of the circle: ";
	cin>>radius;
	cout<<"The area of the circle having radius "<<radius<<"cm is "<<area(radius)<<"cm^2";
	return 0;
}