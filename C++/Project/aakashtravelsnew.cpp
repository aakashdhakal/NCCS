// Basic header files required for different inbuilt function
#include <iostream>
#include <fstream>
#include <conio.h>
#include <random>
#include <iomanip>
using namespace std;

// Here class bus is defined that makes easier to implement different methods
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
  	long long phoneNumber;
  	ofstream busFileOut, passFileOut;
  	ifstream busFileIn, passFileIn;
  	bool bypass = false;

  // Public access functions for class Bus
  public:
	void inputInfo();
  	void removeInfo();
  	void seatInfo();
  	void passenger();
  	void admin();
  	void bookTicket();
  	void cancelReservation();
  	void showTicket();
  	bool fileHandling(int);
  	void adminCheck();
};

void headerDisplay() {
  cout << R"(	
                     _______       _                _        _______                      _       
                    (_______)     | |              | |      (_______)                    | |      
                     _______ _____| |  _ _____  ___| |__        _  ____ _____ _   _ _____| |  ___ 
                    |  ___  (____ | |_/ |____ |/___)  _ \      | |/ ___|____ | | | | ___ | | /___)
                    | |   | / ___ |  _ (/ ___ |___ | | | |     | | |   / ___ |\ V /| ____| ||___ |
                    |_|   |_\_____|_| \_)_____(___/|_| |_|     |_|_|   \_____| \_/ |_____)\_|___/       
					                                                                           
)";
}
// This function is used to generate line for distinctive output
void vline(char ch, int n) {
  for (int i = n; i > 0; i--) {
	cout << ch;
  }
  cout << endl;
}

// This function will run if  there are no bus in the system and user try to access bus info
void emptyList() {
  vline('-', 120);
  cout << "The list is empty" << endl;
}

// Function to input and check the password for admin access
void inputPassword() {
	string password, pass;
	fstream passFile;
  	passFile.open("password.bin", ios::app | ios::in);
  if (passFile.peek() == ifstream::traits_type::eof()) {
    	pass = "admin123";
    	passFile << pass;
  }
  	passFile >> pass;
  	passFile.close();

  do {
  	  vline('-',120);
    cout << "Enter password: ";
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
      vline('-', 120);
      password.clear();
    }
  } while (password != pass);
  cout << endl;
}

void changePassword() {
  fstream passFile;
  string password;
  inputPassword();
  cout << "Enter new password: ";
  cin >> password;

  passFile.open("password.bin", ios::trunc | ios::out);
  passFile << password;
  passFile.close();
  cout << "Password Changed" << endl;

}

// Function to check if the bus number entered exists in the system
bool Bus::fileHandling(int n) {
  int countVar = 0, table = 0, q = 0;
  Bus bus, pass;

  busFileIn.clear();
  busFileIn.seekg(0);
  if (n <= 5) {
    busFileIn.open("bus_info.bin");
    while (busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare) {
      bool showInfo = false;


      if (busNumber == bus.busNumber && n == 1) {
        countVar++;
      }

      if (destination == bus.destination && (n == 2 || n == 4)) {
        countVar++;

        if (n == 4) {
          showInfo = true;
        }
      }

      if (n == 5) {
        showInfo = true;
      }

      if (showInfo == true) {

	    if (busFileIn.peek() == ifstream::traits_type::eof()) {
      emptyList();
      return false;
    }

        if (table == 0) {
          cout << "\033c";
          headerDisplay();
          vline('-', 120);
          cout << setw(10) << "S.No" << setw(18) << "Bus Number" << setw(21) << "From - To" << setw(25) << "Arrival Time" << setw(20) << "Departure Time" << setw(17) << "Fare" << endl;
        	vline('=', 120);
          table++;
        }
        	        cout << setw(5);
        cout << setw(9) << ++q << setw(15) << bus.busNumber << setw(20) << bus.origin << " - " << bus.destination <<setw(23-bus.destination.length())<< bus.arrivalTime << setw(18) << bus.departureTime <<setw(20)<< "Rs " << bus.fare <<resetiosflags(ios::left)<< endl;
		vline('-',120);
      }

      if (n == 3 && destination == bus.destination && busNumber == bus.busNumber) {
        countVar++;
      }
    }

    busFileIn.close();
    if (countVar != 0) {
      return true;
    }
    return false;
  } else {
    passFileIn.open("passengerInfo.bin");

    passFileIn.clear();
    passFileIn.seekg(0);

    while (passFileIn >> pass.name >> pass.ticketNumber >> pass.seatNumber >> pass.phoneNumber >> pass.busNumber) {

      if (ticketNumber == pass.ticketNumber && n == 6) {
        countVar++;
      }

      if (seatNumber == pass.seatNumber && busNumber == pass.busNumber && n == 7) {
        countVar++;

      }

      if (busNumber == pass.busNumber && n == 8) {
        seats[(pass.seatNumber - 1) / 4][(pass.seatNumber - 1) % 4] = 1;
        countVar++;
      }
    }
    passFileIn.close();
    if (countVar != 0) {
      return true;
    }
    return false;
  }
}

void Bus::adminCheck() {
  Bus b;
  bool busNumberExists = false;

  do {
    cout << "Enter the bus number: ";
    cin >> b.busNumber;

    busNumberExists = b.fileHandling(1);

    if (busNumberExists == false) {
      cout << "ERROR! The bus of number " << b.busNumber << " doesnot exists" << endl;
    }
  }
  while (busNumberExists == false);
  b.fileHandling(8);
  b.seatInfo();

}

// This function shows the seats of the bus and shows whether they are booked or not
void Bus::seatInfo() {
  vline('-', 120);
  int q = 0;

  fileHandling(7);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      cout.width(10);
      if (j == 2) {
        cout.width(20);
      }

      if (seats[i][j] == 1) {
        cout << ++q << ".!RESERVED";
      } else {
        cout << ++q << ".!!Empty!!";
      }
    }

    cout << endl;
  }

}

// This function reserves a seat for the passenger in the bus
void Bus::bookTicket() {
  vline('-', 120);
  passFileOut.open("passengerInfo.bin", ios::app);
  int i, row, col;
  bool reserved = false;
  bool busNumberExists = false;
  bool destinationExists = false;
  Bus bus, pass;

  cout << "Please enter the desired destination: ";
  cin >> pass.destination;
  destinationExists = pass.fileHandling(4);

  if (destinationExists == false) {
    cout << "ERROR! No buses are available for given destination" << endl;
    return passenger();
  }

  do {
    vline('-', 120);
    cout << "Enter bus number: ";
    cin >> pass.busNumber;

    busNumberExists = pass.fileHandling(3);

    if (busNumberExists == false || destinationExists == false) {
      cout << "ERROR! Bus number " << pass.busNumber << " is not available for provided destination" << endl;
    }
  } while (busNumberExists == false || destinationExists == false);
  pass.fileHandling(8);
  pass.seatInfo();

  do {
    vline('-', 120);
    cout << "Enter seat number: ";
    cin >> pass.seatNumber;

    reserved = pass.fileHandling(7);

    if (reserved == true) {
      cout << "ERROR! The seat is already reserved" << endl;
    } else if (pass.seatNumber > 32) {
      cout << "ERROR! The seat limit is 32. So, please enter seat number upto 32" << endl;
    } else {
      break;
    }
  } while (reserved == true || pass.seatNumber > 32);

  row = (seatNumber - 1) / 4;
  col = (seatNumber - 1) % 4;
  cout << "Enter passenger's name: ";
  getline(cin >> ws, pass.name);
  cout << "Enter passenger's phone number: ";
  cin >> pass.phoneNumber;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution < > dis(1000, 10000);
  pass.ticketNumber = dis(gen);
  passFileOut << pass.name << " " << pass.ticketNumber << " " << pass.seatNumber << " " << pass.phoneNumber << " " << pass.busNumber << endl;
  passFileOut.close();
  cout << "Your seat is reserved successfully" << endl;
  system("pause");
  pass.showTicket();
    cout << "\033c";
}

void Bus::cancelReservation() {

  Bus pass1,pass2;

  cout << "Enter ticket number: ";
  cin >> pass1.ticketNumber;

  bool ticketNumberExists = pass1.fileHandling(6);

  if (ticketNumberExists == true) {
    passFileIn.open("passengerInfo.bin");
  passFileOut.open("tempPass.bin");
  passFileIn.clear();
  passFileIn.seekg(0);
  while (passFileIn >> pass2.name >> pass2.ticketNumber >> pass2.seatNumber >> pass2.phoneNumber >> pass2.busNumber) {
    if (pass1.ticketNumber != pass2.ticketNumber) {
      passFileOut << pass2.name << " " << pass2.ticketNumber << " " << pass2.seatNumber << " " << pass2.phoneNumber << " " << pass2.busNumber << endl;
    }
  }

  passFileIn.close();
  passFileOut.close();

  remove("passengerInfo.bin");

  rename("tempPass.bin", "passengerInfo.bin");
  
    cout << "SUCCESS! The ticket is successfully cancelled" << endl;
  } else {
    cout << "The ticket number " << pass1.ticketNumber << " is not found in the list" << endl;
    return passenger();
  }
}

// This function gives the details about the seat and ticket
void Bus::showTicket() {
  passFileIn.open("passengerInfo.bin");
  busFileIn.open("bus_info.bin");
  Bus pass1, bus, pass2;
  int n = 0;
  passFileIn.clear();
  passFileIn.seekg(0);

  while (passFileIn >> pass2.name >> pass2.ticketNumber >> pass2.seatNumber >> pass2.phoneNumber >> pass2.busNumber) {
    if (pass2.ticketNumber == ticketNumber) {
      n++;
      break;
    }
  }

  passFileIn.close();

  if (n == 0) {
    cout << "ERROR! Ticket number not found" << endl;
    return passenger();
  }

  while (busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare) {
    if (pass2.busNumber == bus.busNumber) {
      break;
    }
  }

  busFileIn.close();
  cout << "\033c";
  vline('=', 120);
  cout << setw(60) << "BUS TICKET" << endl;
  vline('-', 120);
  cout << setw(30) << "Passenger's Name: " << pass2.name << setw(60) << "Ticket Number: " << pass2.ticketNumber << endl;
  cout << setw(30) << "Contact Number: " << pass2.phoneNumber <<setw(56) << "Arrival Time: " << bus.arrivalTime<< endl;
  cout << setw(30) << "Bus Number: " << pass2.busNumber <<setw(63) << "Departure Time: " << bus.departureTime <<endl;
  cout << setw(30) << "Seat Number: " << pass2.seatNumber << setw(56) << endl;
  cout << setw(53) << "From: " << bus.origin << setw(5) << "To: " << bus.destination << endl;
  cout << setw(99) << "Total Amount: Rs " << bus.fare << endl;
  vline('-', 120);
  cout << "NOTE: 1) Please note down your ticket number as it is required for further use" << endl;
  cout << "      2)Please report to the respective counter before an hour of departure otherwise your ticket will be cancelled" << endl;
  vline('=', 120);
  system("pause");
}

// This function removes a bus from the system
void Bus::removeInfo() {
  bool busNumberExists = false;
  bool validChoice = false;
  Bus bus1, bus2, pass;
  string choice;
  cout << "Enter the bus number: ";
  cin >> bus1.busNumber;

  busNumberExists = bus1.fileHandling(1);

  if (busNumberExists == false) {
    cout << "ERROR! The bus number " << bus1.busNumber << " is not on the list" << endl;
    return admin();
  }

  busNumberExists = bus1.fileHandling(8);

  if (busNumberExists == true) {
    cout << "ERROR! The passengers have already reserved seats of this bus. So, it cannot be deleted" << endl;
    return admin();
  }

  busFileIn.open("bus_info.bin");
  busFileOut.open("tempBus.bin");

  while (busFileIn >> bus2.destination >> bus2.origin >> bus2.driverName >> bus2.busNumber >> bus2.arrivalTime >> bus2.departureTime >> bus2.fare) {
    if (bus1.busNumber != bus2.busNumber) {
      busFileOut << bus2.destination << " " << bus2.origin << " " << bus2.driverName << " " << bus2.busNumber << " " << bus2.arrivalTime << " " << bus2.departureTime << " " << bus2.fare << endl;
    }
  }

  busFileIn.close();
  busFileOut.close();
  remove("bus_info.bin");
  rename("tempBus.bin", "bus_info.bin");

  cout << "SUCCESS! The bus is deleted from the list successfully" << endl;
}

void Bus::inputInfo() {
  bool busNumberExists = false;
  Bus inBus;

  busFileOut.open("bus_info.bin", ios::app);
  vline('-', 120);
  do {
    cout << "Enter the bus number: ";
    cin >> inBus.busNumber;

    busNumberExists = inBus.fileHandling(1);

    if (busNumberExists == true) {
      cout << "ERROR! The bus number " << inBus.busNumber << " already exists" << endl;
    }
  } while (busNumberExists == true);

  cout << "Enter the driver's name: ";
  getline(cin >> ws, inBus.driverName);
  cout << "From: ";
  getline(cin, inBus.origin);
  cout << "To: ";
  getline(cin, inBus.destination);
  cout << "Enter the arrival time (hh:mm): ";
  getline(cin, inBus.arrivalTime);
  cout << "Enter the departure time (hh:mm): ";
  getline(cin, inBus.departureTime);
  cout << "Enter the fare: ";
  cin >> inBus.fare;
  busFileOut << inBus.destination << " " << inBus.origin << " " << inBus.driverName << " " << inBus.busNumber << " " << inBus.arrivalTime << " " << inBus.departureTime << " " << inBus.fare << endl;
  cout << "Bus added successfully" << endl;
  busFileOut.close();
}

// This function contains acions that can be performed by bus admin
void Bus::admin() {
  Bus b;
  if (bypass == false) {
    inputPassword();
    bypass = true;
  }

  vline('-', 120);
  cout << "Select an action\n 1. Add a bus\n 2. Delete bus\n 3. View Available Buses\n 4. Check seat status\n 5. Change to Passenger mode\n 6. Change admin password\n 7. Exit" << endl;
  vline('-', 120);
  int option = 0;
  do {
    cin >> option;
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
  } while (cin.fail() == true);

  switch (option) {
  case 1:
    b.inputInfo();
    break;

  case 2:
    b.removeInfo();
    break;

  case 3:
    b.fileHandling(5);
    break;

  case 4:
    b.adminCheck();
    break;

  case 5:
    b.passenger();
    break;

  case 6:
  	bypass = false;
    changePassword();
    break;

  case 7:
    cout << "Closing the program!!" << endl <<
      "<Thank You :)>" << endl <<
      "Created By Aakash Dhakal" << endl;
    exit(0);
    break;

  default:
    cout << "ERROR! Please enter numbers from 1 to 6" << endl;
    return admin();
  }

  admin();
}

// This function contains acions that can be performed by passenger
void Bus::passenger() {
  Bus b;
  vline('-', 120);
  cout << "Select an action\n 1. View Available Buses\n 2. Book a ticket\n 3. View your ticket\n 4. Cancel your Reservation\n 5. Change to Admin mode\n 6. Exit" << endl;

  vline('-', 120);
  int option = 0;
  do {
    cin >> option;
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
  } while (cin.fail() == true);

  switch (option) {
  case 1:
    b.fileHandling(5);

    break;

  case 2:
    b.bookTicket();
    break;

  case 3:

    cout << "Enter your ticket number: ";
    cin >> b.ticketNumber;
    b.showTicket();
    break;

  case 4:
    b.cancelReservation();
    break;

  case 5:
    b.admin();
    break;

  case 6:
    cout << "Closing the program!!" << endl <<
      "<Thank You :)>" << endl <<
      "Created By Aakash Dhakal" << endl;
    exit(0);
    break;

  default:
    cout << "Error! Please enter valid numbers from 1 to 6" << endl;
    return passenger();
    break;
  }

  passenger();
  vline('-', 120);
}

void programMode() {
  Bus b;
  vline('-', 120);
  cout << setw(30) << " 1. Admin" << setw(30) << " 2. Passenger " << setw(25) << "3. Exit" << endl;
  vline('-', 120);
  int choice;

  do {
    cout << "Selet program mode: ";
    cin >> choice;
    if (cin.fail() == true) {

      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
  } while (cin.fail() == true);

  switch (choice) {
  case 1:
    b.admin();
    break;

  case 2:
    b.passenger();
    break;

  case 3:
    cout << "Closing the program!!" << endl <<
      "<Thank You :)>" << endl <<
      "Created By Aakash Dhakal" << endl;
    exit(0);

  default:
    cout << "ERROR! Please enter valid numbers 1 or 2" << endl;
    programMode();
    break;
  }
}

// This is the main function from where the program starts
int main() {

  headerDisplay();
  programMode();

  return 0;
}
