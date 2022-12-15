#include<iostream>
using namespace std;

class Distance{
	private:
	int feet,inch;
	public:

		Distance(){
		}
		void inputData(){
			cout<<"Enter the length in feet: ";
			cin>>feet;
			cout<<"Enter the length in inch: ";
			cin>>inch;
		}
		
		void outputData(){
			cout<<"The lengtn entered is "<<feet<<" feet "<<inch<<" inches"<<endl;
		}
		
		void addData(Distance d1,Distance d2){
			Distance sum;
			sum.feet = d1.feet + d2.feet;
			sum.inch = d1.inch + d2.inch;
			
			if(sum.inch >= 12){
				sum.feet += 1;
				sum.inch %= 12;
			}
			cout<<"The sum is "<<sum.feet<<" feet "<<sum.inch<<" inch"<<endl;
		}
};

void addData(Distance,Distance);

int main(){
	Distance d1,d2,sum;
	d1.inputData();
	d2.inputData();
	d1.outputData();
	d2.outputData();
	sum.addData(d1,d2);
	return 0;
}