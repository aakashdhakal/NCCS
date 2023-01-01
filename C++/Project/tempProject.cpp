#include <iostream>
#include<string>
#include <time.h>
using namespace std;
int n = 0;
int np = 0;

class Bus {
  string destination;
  string origin;
  string driverName;
  int busNumber;
  string arrivalTime;
  string departureTime;
  int fare;
  int seats[8][4];
	string name;
  int seatNumber;
  int ticketNumber;

 public:
  void inputInfo();
  void showInfo();
  void removeInfo();
  void seatInfo();
  void busAdmin();
	void bookTicket();
  void showTicket();
  void passenger();
}b[10], p[1000]; 




void vline(char ch) {
  for (int i = 75; i > 0; i--) {
    cout << ch;
  }
  cout << endl;
}

void emptyList() {
  vline('-');
  cout << "The list is empty" << endl;
  vline('-');
}

int roleSelect(){
	
	int option;
 	do{
	 cout << "Please mention your role:\n 1. Admin \n 2. Passenger" << endl;

  cin >> option;

  switch (option) {
    case 1:
      break;

    case 2:
      break;

    default:
      cout << "Error! Please enter numbers 1 or 2" << endl;
      break;
  }
}
while(option>2);

return option;
}


void Bus::removeInfo() {
  int number;

  if (n <= 0) {
    emptyList();
  } else {
    vline('-');
    cout << "Enter the bus number: ";
    cin >> number;
    for (int i = 0; i < n; i++) {
      if (b[i].busNumber == number) {
        b[i] = b[i + 1];
        n--;
        cout << "The bus is removed from the list!" << endl;
      }
    }
    cout << "Error! Bus not found in the list" << endl;
    vline('-');
    removeInfo();
  }
}


void Bus::inputInfo() {
  cout << "Enter the bus number: ";
  cin >> busNumber;

  for (int i = 0; i < n; i++) {
    if (b[i].busNumber == busNumber) {
      cout << "The bus number already exists\nPlease enter different bus number"<< endl;
      inputInfo();
    }
}
  cout << "Enter the driver's name: ";
  getline(cin >> ws, driverName);
  cout << "From: ";
  getline(cin, origin);
  cout << "To: ";
  getline(cin, destination);
  cout << "Enter the arrival time (hh:mm): ";
  getline(cin, arrivalTime);
  cout << "Enter the departure time (hh:mm): ";
  getline(cin, departureTime);
  cout << "Enter the fare: ";
  cin >> fare;
  cout << "Bus added successfully" << endl;
  n++;
  system("pause");
}

void Bus::showInfo() {
  if (n <= 0) {
    emptyList();
  } else {
      vline('-');
      cout << "Bus number: " << busNumber << endl;
      cout << "Driver's Name: " <<driverName << endl;
      cout << "From: " <<origin << endl;
      cout << "To: " <<destination << endl;
      cout << "Arrival Time: " <<arrivalTime << endl;
      cout << "Departure Time: " <<departureTime << endl;
      cout << "Fare: Rs " <<fare << endl;
      vline('-');
    }
  }

void Bus::busAdmin() {
  vline('-');
  cout << "Select an action\n 1. Add a bus\n 2. Delete bus\n 3. View Available Buses\n 4. Change User Role\n 5. Exit"<< endl;
  int option = 0;
  cin >> option;

  switch (option) {
    case 1:
      b[n].inputInfo();
      break;

    case 2:
      removeInfo();
      break;

    case 3:
    	for(int i=0;i<n;i++)
		{
      b[i].showInfo();
  }
      break;

    case 4:
      roleSelect();
      break;

    case 5:
      exit(0);
      break;

    default:
      cout << "Error! Please enter numbers 1 or 2 or 3" << endl;
      busAdmin();
      break;
  }
busAdmin();
  vline('-');
}


void Bus::passenger() {
  vline('-');
  cout << "Select an action\n 1. See Available Buses\n 2. Book a ticket\n 3. View your ticket\n 4. Change User Role\n 5. Exit"<< endl;
  int option = 0;
  cin >> option;

  switch (option) {
    case 1:
      for(int i=0;i<n;i++)
		{
      b[i].showInfo();
  }
      break;

    case 2:
      //bookTicket();
      break;

    case 3:
      //showTicket();
      break;

    case 4:
      roleSelect();
      break;

    case 5:
      exit(0);
      break;
      
    default:
      cout << "Error! Please enter numbers from 1 to 5" << endl;
      break;
  }
  vline('-');
}



int main() {
	int option;
	 
	cout << "E-Ticket" << endl;
	option = roleSelect();
	
	if(option == 1){
		b[0].busAdmin();
	}
	else{
		p[0].passenger();
	}               
  	return 0;
}