//Basic header files required for different inbuilt function 
#include <iostream>
#include<string>
#include <time.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
using namespace std;

/*n keeps track of the bus at a time. Every time bus is added the value of n increases by one. 
So it is index to store a bus data in array.
Same thing applies to np that is used to store passenger data in array*/
int n = 0;
int np = 0;

//Here class bus is defined that makes easier to implement different methods
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
  ofstream outFile;
  ifstream inFile;

  public:
  void inputInfo();
  void showInfo();
  void removeInfo();
  void seatInfo();
  void passenger();
  void admin();
  void bookTicket();
  void showTicket();
}
b[10], p[1000]; /*Here array of objects b and p is declared to store info 
					about bus and passenger respectively*/

//This function is used to generate line for distinctive output
void vline(char ch) {
  for (int i = 75; i > 0; i--) {
    cout << ch;
  }
  cout << endl;
}

//This function will run if  there are no bus in the system and user try to access bus info
void emptyList() {
  vline('-');
  cout << "The list is empty" << endl;
  vline('-');
}

//This function shows the seats of the bus and shows whether they are booked or not
void Bus::seatInfo() {
  vline('-');
  int q = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      cout.width(10);
      if (seats[i][j] != 0) {
        cout << ++q << ". !RESERVED";
      } else {
        cout << ++q << ". Available";
      }
    }
    cout << endl;
  }
}

// This function reserves a seat for the passenger in the bus
void Bus::bookTicket() {
  vline('-');
  string dest;
  int bnum, temp = 0, i;
  cout << "Please enter the desired destination: ";
  cin >> dest;

  for (int i = 0; i < n; i++) {
    if (dest == b[i].destination) {
      b[i].showInfo();
    } else {
      temp++;
    }
  }
  if (temp == n) {
    cout << "ERROR! No buses are available for the given destination" << endl;
    passenger();
  }

  cout << "Enter bus number: ";
  cin >> bnum;

  for (i = 0; i < n; i++) {
    if (bnum == b[i].busNumber) {
      break;
    }
  }

  b[i].seatInfo();

  do {
    cout << "Enter seat number: ";
    cin >> p[np].seatNumber;

    if (p[np].seatNumber > 32) {
      cout << "ERROR! The seat limit is 32. So, please enter seat number upto 32" << endl;
    } else if (b[i].seats[p[np].seatNumber / 4][(p[np].seatNumber % 4) - 1] != 0) {
      cout << "ERROR! The seat is already reserved" << endl;
    } else {
      break;
    }

  }

  while (p[np].seatNumber > 32 || b[i].seats[p[np].seatNumber / 4][(p[np].seatNumber % 4) - 1] != 0);

  cout << "Enter passenger's name: ";
  cin >> p[np].name;
  p[np].ticketNumber = 1000 + (rand() % 1000);
  b[i].seats[p[np].seatNumber / 4][(p[np].seatNumber % 4) - 1] = p[np].ticketNumber;
  cout << "Your ticket number is: " << p[np].ticketNumber << endl;
  np++;
  cout << "(NOTE: Please note down your ticket number as it is required to get details about your seat)" << endl;
  cout << "Your seat is reserved successfully" << endl;
  system("pause");
}

//This function gives the details about the seat and ticket 
void Bus::showTicket() {
  vline('-');
  int tnum, i, j, temp = 0;
  cout << "Please enter your ticket number: ";
  cin >> tnum;

  for (i = 0; i < np; i++) {
    if (p[i].ticketNumber == tnum) {
      break;
    } else {
      temp++;
    }
  }

  if (temp == np) {
    cout << "ERROR! Ticket number not found" << endl;
    return showTicket();
  }

  for (j = 0; j <= n; j++) {
    if (b[j].seats[i][j] == p[i].ticketNumber)
    ;
    break;
  }
  b[j].showInfo();
  cout << "Ticket number: " << p[i].ticketNumber << endl;
  cout << "Passenger's Name: " << p[i].name << endl;
  cout << "Seat Number: " << p[i].seatNumber << endl;
  system("pause");

}

//This function removes a bus from the system
void Bus::removeInfo() {
  // prompt user to enter the bus number of the bus to be removed
  cout << "Enter the bus number of the bus to be removed: ";
  cin >> busNumber;

  // open file for reading
  inFile.open("bus_info.txt");
  // open temporary file for writing
  outFile.open("temp.txt");
  
  int temp; // define temp as a local variable
  // copy all the bus information except the one to be removed to the temporary file
  while (inFile >> destination >> origin >> driverName >> temp >> arrivalTime >> departureTime >> fare) {
    if (temp != busNumber) {
      outFile << destination << " " << origin << " " << driverName << " " << temp << " " << arrivalTime << " " << departureTime << " " << fare << endl;
    }
  }
  // close the input and output files
  inFile.close();
  outFile.close();

  // delete the original file
  remove("bus_info.txt");
  // rename the temporary file to the original file name
  rename("temp.txt", "bus_info.txt");
}


//This function inputs bus details into the system
void Bus::inputInfo() {
	outFile.open("bus_info.txt", ios::out|ios::app);
  vline('-');
  cout << "Enter the bus number: ";
  cin >> busNumber;

  for (int i = 0; i < n; i++) {
    if (b[i].busNumber == busNumber) {
      cout << "The bus number already exists\nPlease enter different bus number" << endl;
      return inputInfo();
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
  outFile << destination << " " << origin << " " << driverName << " " << busNumber << " " << arrivalTime << " " << departureTime << " " << fare << endl;
  outFile.close();
  n++;


}

//This function shows the details about the bus
void Bus::showInfo() {
  
  
  vline('-');
  cout << "Bus number: " << busNumber << endl;
  cout << "Driver's Name: " << driverName << endl;
  cout << "From: " << origin << endl;
  cout << "To: " << destination << endl;
  cout << "Arrival Time: " << arrivalTime << endl;
  cout << "Departure Time: " << departureTime << endl;
  cout << "Fare: Rs " << fare << endl;

}

//This function contains acions that can be performed by bus admin
void Bus::admin() {
  vline('-');
  cout << "Select an action\n 1. Add a bus\n 2. Delete bus\n 3. View Available Buses\n 4. Change to Passenger mode\n 5. Exit" << endl;
  vline('-');
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
  	inFile.open("bus_info.txt", ios::in);
  	 while (inFile >> destination >> origin >> driverName >> busNumber >> arrivalTime >> departureTime >> fare) {
      showInfo();
  }
inFile.close();
    break;

  case 4:
    passenger();
    break;

  case 5:
  	cout<<"Closing the program!!"<<endl<<"<Thank You :)>"<<endl<<"Created By Aakash Dhakal"<<endl;
    exit(0);
    break;

  default:
    cout << "Please enter numbers from 1 to 5" << endl;
    return admin();
  }

  admin();
}

//This function contains acions that can be performed by passenger
void Bus::passenger() {
  vline('-');
  cout << "Select an action\n 1. View Available Buses\n 2. Book a ticket\n 3. View your ticket\n 4. Change to Admin mode\n 5. Exit" << endl;

  vline('-');
  int option = 0;
  cin >> option;

  switch (option) {

  case 1:
    if (n <= 0) {
      emptyList();
    }
    for (int i = 0; i < n; i++) {
      b[i].showInfo();
    }
    break;

  case 2:
    p[np].bookTicket();
    break;

  case 3:
    showTicket();
    break;

  case 4:
    admin();
    break;

  case 5:
  	cout<<"Closing the program!!"<<endl<<"<Thank You :)>"<<endl<<"Created By Aakash Dhakal"<<endl;
    exit(0);
    break;

  default:
    cout << "Error! Please enter numbers from 1 to 6" << endl;
    passenger();
    break;
  }
  passenger();
  vline('-');
}

//This is the main function from where the program starts
int main() {
  Bus b1;
  vline('-');
  cout << "Please select program mode\n 1. Admin\n 2. Passenger\n 3. Exit" << endl;
  vline('-');
  int choice;
  cin >> choice;

  switch (choice) {

  case 1:
    b1.admin();
    break;

  case 2:
    b1.passenger();
    break;
    
  case 3:
	cout<<"Closing the program!!"<<endl<<"<Thank You :)>"<<endl<<"Created By Aakash Dhakal"<<endl;
    exit(0);

  default:
    cout << "Please enter numbers 1 or 2" << endl;
    main();
    break;
  }

  return 0;
}