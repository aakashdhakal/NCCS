#include<iostream>
using namespace std;
 int main(){
 	int length,breadth,height,volume;
 	cout<<"Enter the length of the cuboid (in cm): ";
 	cin>>length;
 	cout<<"Enter the breadth of the cuboid (in cm): ";
 	cin>>breadth;
 	cout<<"Enter the height of the cuboid (in cm): ";
 	cin>>height;
 	volume =length*breadth*height;
 	cout<<"The volume of the cuboid having length "<<length<<"cm, breadth "<<breadth<<"cm and height "<<height<<"cm is "<<volume<<"cm^3"<<endl;
 	return 0;
 } 