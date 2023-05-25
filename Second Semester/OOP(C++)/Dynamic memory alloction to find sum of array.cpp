#include<iostream>
using namespace std;

int arraySum(int array[],int n){
	int i,sum = 0;
	for(i=0;i<n;i++){
		sum = sum + array[i];
	}
	return sum;
}
int main(){
	int n,i;
	int* array = new int[n];
	cout<<"Please enter the number of items to be placed in the array: ";
	cin>>n;
	cout<<"Please enter the elements of the array: ";
	for(i=0;i<n;i++){
		cin>>array[i];
	}

	cout<<"The sum of the array is: "<<arraySum(array,n)<<endl;
}