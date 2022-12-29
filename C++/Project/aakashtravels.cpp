#include<bits/stdc++.h>
using namespace std;
int n = 0;

class Bus{
	string destination;
	string origin;
	string driverName;
	int busNumber;
	string arrivalTime;
	string departureTime;
	public:
		
	void inputInfo();
	void showInfo();
	void removeInfo();


	
} b[10];

void busAdmin(){
		

		cout<<"Select an action\n 1. Add a bus\n 2. Delete bus\n 3. View Available Buses\n 4. Exit"<<endl;
		int option;
		cin>>option;
	
			switch(option){
		
				case 1: b[n].inputInfo();
						break;
		
				case 2: b[0].removeInfo();
						break;
				
				case 3: 
						b[0].showInfo();
						break;
						
				case 4: exit(0);
						break;
				
				default:  cout<<"Error! Please enter numbers 1 or 2 or 3"<<endl;
							busAdmin();
							break;
	}
}

	void roleSelect(){
		cout<<"Please mention your role:\n 1. Admin \n 2. Passenger"<<endl;
		int option;
		cin>>option;
	
			switch(option){
		
				case 1: busAdmin();
				break;
		
				case 2: cout<<"test"<<endl;
				break;
		
				default: cout<<"Error! Please enter numbers 1 or 2"<<endl;
						roleSelect();
						break;
	}
	
}

	void Bus::inputInfo(){

		cout<<"Enter the bus number: ";
		cin>>b[n].busNumber;
		
		for (int i=0;i<n;i++){
			if(b[i].busNumber == busNumber){
				cout<<"The bus number already exists\nPlease enter different bus number"<<endl;
				return inputInfo();
			}
		}
		cout<<"Enter the driver's name: ";
		getline(cin>>ws,b[n].driverName);
		cout<<"From: ";
		getline(cin,b[n].origin);
		cout<<"To: ";
		getline(cin,b[n].destination);
		cout<<"Enter the arrival time (hh:mm): ";
		getline(cin,b[n].arrivalTime);
		cout<<"Enter the departure time time (hh:mm): ";
		getline(cin,b[n].departureTime);
		cout<<"Bus added successfully"<<endl;
		n++;
		system("pause");
		busAdmin();
		
	}
	
	void Bus::showInfo(){
if(n<=0){
		cout<<"------------------------------------------------"<<endl;
	cout<<"The list is empty"<<endl;
		cout<<"------------------------------------------------"<<endl;
}
else{
for(int i=0;i<n;i++){
	cout<<"------------------------------------------------"<<endl;
	cout<<"Bus number: "<<b[i].busNumber<<endl;
	cout<<"Driver's Name: "<<b[i].driverName<<endl;
	cout<<"From: "<<b[i].origin<<endl;
	cout<<"To: "<<b[i].destination<<endl;
	cout<<"Arrival Time: "<<b[i].arrivalTime<<endl;
	cout<<"Departure Time: "<<b[i].departureTime<<endl;
	cout<<"------------------------------------------------"<<endl;
}
}
		busAdmin();
}

void Bus::removeInfo() {

	  int number;

	  
if(n<=0){
		cout<<"------------------------------------------------"<<endl;
	cout<<"The list is empty"<<endl;
		cout<<"------------------------------------------------"<<endl;
}
	  else{
	  		  cout<<"Enter the bus number: ";
	  cin >> number;
	  for (int i = 0; i < n; i++) {
	    if (b[i].busNumber == number) {
	     		 b[i] = b[i + 1];
	    	n--;
	    	cout<<"The bus is removed from the list!"<<endl;
	  }
	  
	  else{
	  	cout<<"Error! Bus not found in the list"<<endl;
	  	removeInfo();
	  }
}

	}
		  busAdmin();
}
	
class Passenger{
	string name;
	int seatNumber;
	int ticketNumber;
	public:
};

int main(){
  	cout<<"E-Ticket"<<endl;
  	roleSelect();
	return 0;
}