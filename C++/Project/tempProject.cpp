//Basic header files required for different inbuilt function 
#include <iostream>

#include <string>

#include <ctime>

#include <stdlib.h>

#include <cstdlib>

#include <fstream>

#include <conio.h>

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
  int seats[8][4] = {0};
  string name;
  int seatNumber;
  int ticketNumber;
  int phoneNumber;
  ofstream busFileOut, passFileOut;
  ifstream busFileIn, passFileIn;
  bool bypass = false;

  public:
  void inputInfo();
  void showInfo();
  void removeInfo();
  void seatInfo();
  void passenger();
  void admin();
  void bookTicket();
  void showTicket();
  bool searchBus();
  void changePassword();
}
b, p;
/*Here array of objects b and p is declared to store info 
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
}


void Bus::changePassword() {

  string password, pass;
  busFileIn.open("password.bin", ios::binary);

  busFileIn >> pass;
  vline('-');
  do {
    cout << "Enter current password: ";
    char ch = _getch();
    while (ch != 13) {
      // 13 is the ASCII code for the Enter key
      if (ch == 8) {
        // 8 is the ASCII code for the backspace key
        if (!password.empty()) {
          cout << '\b' << ' ' << '\b';
          password.pop_back();
        }
      } else {
        password.push_back(ch);
        cout << '*';
      }

      ch = _getch();
    }

    if (password != pass) {
      cout << "\nIncorrect Password" << endl;
      password.clear();
      vline('-');
    }

  } while (password != pass);
  busFileIn.close();
  cout << "\nEnter new password: ";
  cin >> password;
  busFileOut.open("password.bin", ios::binary | ios::trunc);
  busFileOut << password;

  busFileOut.close();
  cout << "Password Changed" << endl;
  bypass = false;
}

//This function shows the seats of the bus and shows whether they are booked or not
void Bus::seatInfo() {
  vline('-');
  int q = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      cout.width(10);
      if (seats[i][j] == 1) {
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
  passFileIn.open("passengerInfo.bin", ios::binary);
  passFileOut.open("passengerInfo.bin",ios::app|ios::binary);
  busFileIn.open("bus_info.bin",ios::in|ios::binary);
  string dest;
  int bnum, temp = 0, i,row,col;
  Bus bus,pass;
  busFileIn.clear();
  busFileIn.seekg(0);
  
  cout << "Please enter the desired destination: ";
  cin >> dest;
while(busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare){
	
	if(dest == bus.destination){
		temp++;
		bus.showInfo();
	}
}
  if (temp == 0) {
    cout << "ERROR! No buses are available for the given destination" << endl;
    return passenger();
  }

vline('-');

do {
	busFileIn.clear();
    busFileIn.seekg(0);
  cout << "Enter bus number: ";
  cin >> bnum;
  
  while(busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare){
	
	if(bnum == bus.busNumber){
		break;
	}
}
if(bnum != bus.busNumber || dest != bus.destination){
	cout<<"ERROR! Bus number "<<bnum<<" is not available for provided destination"<<endl;
	vline('-');
}
  }while(bnum != bus.busNumber || dest != bus.destination);
  
  
  bus.seatInfo();
	vline('-');
	
	
  do {
  	passFileIn.clear();
    passFileIn.seekg(0);
    cout << "Enter seat number: ";
    cin >> seatNumber;
while(passFileIn >> pass.name >> pass.ticketNumber >> pass.seatNumber >> pass.phoneNumber >> pass.busNumber){

}
    if (seatNumber > 32) {
      cout << "ERROR! The seat limit is 32. So, please enter seat number upto 32" << endl;
    } 
	else if (pass.busNumber == bnum && pass.seatNumber == seatNumber) {
      cout << "ERROR! The seat is already reserved" << endl;
    }
	else {
      break;
    }

  }while (pass.busNumber == bnum || pass.seatNumber == seatNumber);
row = (seatNumber - 1) / 4;
col = (seatNumber - 1) % 4;
  cout << "Enter passenger's name: ";
  getline(cin>>ws,name);
  cout<< "Enter passenger's phone number: ";
  cin  >> phoneNumber;
  ticketNumber = 1000 + (rand() % 1000);
  bus.seats[row][col] = 1;
  cout << "Your ticket number is: " << ticketNumber << endl;
  passFileOut << name<< " " << ticketNumber << " " << seatNumber << " " << phoneNumber<< " "  << bus.busNumber <<endl;
  cout << "(NOTE: Please note down your ticket number as it is required to get details about your seat)" << endl;
  cout << "Your seat is reserved successfully" << endl;
  busFileIn.close();
  passFileIn.close();
  passFileOut.close();

}




//This function gives the details about the seat and ticket 
void Bus::showTicket() {
  
}

//This function removes a bus from the system
void Bus::removeInfo() {
  cout << "Enter the bus number of the bus to be removed: ";
  cin >> busNumber;

  busFileIn.open("bus_info.bin");

  busFileOut.open("temp.bin");

  int temp;

  while (busFileIn >> destination >> origin >> driverName >> temp >> arrivalTime >> departureTime >> fare) {
    if (temp != busNumber) {
      busFileOut << destination << " " << origin << " " << driverName << " " << temp << " " << arrivalTime << " " << departureTime << " " << fare << endl;
    }
  }

  busFileIn.close();
  busFileOut.close();

  remove("bus_info.bin");

  rename("temp.bin", "bus_info.bin");
}

void Bus::inputInfo() {
  int temp;
  bool busNumberExists = false;

  busFileIn.open("bus_info.bin");
  busFileOut.open("bus_info.bin", ios::app | ios::binary);
  vline('-');
  do {
    cout << "Enter the bus number: ";
    cin >> busNumber;
    // Check if the bus number already exists in the file
    while (busFileIn >> destination >> origin >> driverName >> temp >> arrivalTime >> departureTime >> fare) {
      if (temp == busNumber) {
        cout << "ERROR! Bus number " << busNumber << " already exists\nPlease enter bus number again" << endl;
        vline('-');
        busNumberExists = true;
        break;
      } else {
        busNumberExists = false;
      }
    }

    // Reset the file position to the beginning
    busFileIn.clear();
    busFileIn.seekg(0);
  } while (busNumberExists == true);

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
  // Write the bus data to the file
  busFileOut << destination << " " << origin << " " << driverName << " " << busNumber << " " << arrivalTime << " " << departureTime << " " << fare << endl;
  // Close the file
  busFileIn.close();
  busFileOut.close();
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

  string password, pass;
  busFileIn.open("password.bin", ios::binary);
  busFileOut.open("password.bin", ios::app | ios::binary);
  if (busFileIn.peek() == std::ifstream::traits_type::eof()) {
    busFileOut << "admin123";
  }
  busFileOut.close();

  busFileIn >> pass;
  busFileIn.close();
if(bypass == false){
  do {
    cout << "Enter password: ";
    bypass = true;
    char ch = _getch();
    while (ch != 13) {
      // 13 is the ASCII code for the Enter key
      if (ch == 8) {
        // 8 is the ASCII code for the backspace key
        if (!password.empty()) {
          cout << '\b' << ' ' << '\b';
          password.pop_back();
        }
      } else {
        password.push_back(ch);
        cout << '*';
      }

      ch = _getch();
    }
    if (password != pass) {
      cout << "\nIncorrect Password" << endl;
      vline('-');
      password.clear();
    }
  } while (password != pass);
  cout << endl;
}
  vline('-');
  cout << "Select an action\n 1. Add a bus\n 2. Delete bus\n 3. View Available Buses\n 4. Change to Passenger mode\n 5. Change admin password\n 6. Exit" << endl;
  vline('-');
  int option = 0;
  cin >> option;
  if(cin.fail() == true){
  	option = 100;
  }

  switch (option) {
  case 1:
    b.inputInfo();
    break;

  case 2:
    removeInfo();
    break;

  case 3:

    busFileIn.open("bus_info.bin", ios::in | ios::binary);
    if (busFileIn.peek() == std::ifstream::traits_type::eof()) {
      emptyList();
    } else {
      while (busFileIn >> destination >> origin >> driverName >> busNumber >> arrivalTime >> departureTime >> fare) {
        showInfo();
      }
    }

    busFileIn.close();

    break;

  case 4:
    passenger();
    break;

  case 5:
    changePassword();
    break;

  case 6:
    cout << "Closing the program!!" << endl << "<Thank You :)>" << endl << "Created By Aakash Dhakal" << endl;
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
    busFileIn.open("bus_info.bin", ios::in | ios::binary);
    if (busFileIn.peek() == std::ifstream::traits_type::eof()) {
      emptyList();
    } else {
      while (busFileIn >> destination >> origin >> driverName >> busNumber >> arrivalTime >> departureTime >> fare) {
        showInfo();
      }
    }

    busFileIn.close();

    break;

  case 2:
    p.bookTicket();
    break;

  case 3:
    showTicket();
    break;

  case 4:
    return admin();
    break;

  case 5:
    cout << "Closing the program!!" << endl << "<Thank You :)>" << endl << "Created By Aakash Dhakal" << endl;
    exit(0);
    break;

  default:
    cout << "Error! Please enter numbers from 1 to 6" << endl;
    return passenger();
    break;
  }

  passenger();
  vline('-');
}

//This is the main function from where the program starts
int main() {
  vline('-');
  cout << "Please select program mode\n 1. Admin\n 2. Passenger\n 3. Exit" << endl;
  vline('-');
  int choice;
  cin >> choice;
switch(choice){
	
    case 1:b.admin();
    break;

  case 2:
    b.passenger();
    break;

  case 3:
    cout << "Closing the program!!" << endl << "<Thank You :)>" << endl << "Created By Aakash Dhakal" << endl;
    exit(0);

  default:
    cout << "Please enter numbers 1 or 2" << endl;
    main();
    break;
  }

  return 0;
}
