#include<iostream>

using namespace std;

void sort(int numbers[], int n){
	int temp,i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n-1;j++)
		if(numbers[i]>numbers[j]){
			temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = numbers[i];
		}
	}
	cout<<"The integers are: ";
	for(i=0;i<5;i++)
	cout<<' '<<numbers[i];
}
void sort(float dotNumbers[], int n){
	int temp,i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n-1;j++)
		if(dotNumbers[i]>dotNumbers[j]){
			temp = dotNumbers[i];
			dotNumbers[i] = dotNumbers[j];
			dotNumbers[j] = dotNumbers[i];
		}
	}
	cout<<endl<<"The decimal numbers are: ";
	for(i=0;i<5;i++)
	cout<<' '<<dotNumbers[i];
}
void sort(char letters[], int n){
	int temp,i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n-1;j++)
		if(letters[i]>letters[j]){
			temp = letters[i];
			letters[i] = letters[j];
			letters[j] = letters[i];
		}
	}
	cout<<endl<<"The characters are: ";
	for(i=0;i<5;i++)
	cout<<' '<<letters[i];
}
int main(){
	int n = 5;
	int numbers[5] = {1,2,3,4,5};
	float dotNumbers[5] = {1.3,2.4,3.5,4.7,5.8};
	char letters[5] = {'a','b','c','d','e'};
	sort(numbers,n);
	sort(dotNumbers,n);
	sort(letters,n);
}