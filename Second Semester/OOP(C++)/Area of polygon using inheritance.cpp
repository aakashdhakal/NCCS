#include<iostream>
using namespace std;

class Polygon{
	private:
	protected:
		float side1;
		float side2;
		float side3;
	
	public:
		virtual void getArea() = 0;
		virtual void setData() = 0;
};


class Rectangle:public Polygon{
	
	public:
		void setData(){
			cout<<"Enter the length of the rectangle: ";
			cin>> side1;
			cout<<"Enter the breadth of the rectangle: ";
			cin>> side2;
		}
		
		void getArea(){
			float area;
			area = side1*side2;
			cout<<"The area of rectangle having length "<<side1<<" cm and breadth "<<side2<<" cm is "<<area<<" cm^2"<<endl;
		}
};

class Square: public Polygon{
	
	public:
		void setData(){
			cout<<"Enter the length of the square: ";
			cin>> side1;
		}
		
		void getArea(){
			float area;
			area = side1*side1;
			cout<<"The area of square having length "<<side1<<" cm is "<<area<<" cm^2"<<endl;
		}
};

int main(){
	
	Rectangle r;
	Square s;
	Polygon* p1 = &r;
	Polygon* p2 = &s;
	
	p1 -> setData();
	p1 -> getArea();
	
	p2 -> setData();
	p2 -> getArea();
	
}