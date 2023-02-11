// Basic header files required for different inbuilt function
#include <iostream>
#include <fstream>
#include <conio.h>
#include <random>
#include <iomanip>
using namespace std;

// Here class bus is defined that makes easier to implement different methods
class Bus
{
	private:
	string origin;
	string driverName;
	string arrivalTime;
	string departureTime;
	int fare;
	ofstream busFileOut;
	ifstream busFileIn;
	bool bypass = false;

	protected:
	int busNumber;
	string destination;

	public:
	void inputInfo();
	void showInfo();
	void removeInfo();
	void admin();
	void adminCheck();
	bool fileHandling(int);
	int checkDetails();
	void showDetails();

};

class Passenger: public Bus
{
	private: 
	string name;
	int seatNumber;
	int ticketNumber;
	int phoneNumber;
	ofstream passFileOut;
	ifstream passFileIn;
	int seats[8][4] = { 0 };

	public: 
	void bookTicket();
	void cancelReservation();
	void showTicket(int);
	bool fileHandling(int);
	void seatInfo();
	void passenger();

};

void vline(char ch,int n)
{
	for (int i = n; i > 0; i--)
	{
		cout << ch;
	}

	cout << endl;
}

// This function will run if  there are no bus in the system and user try to access bus info
void emptyList()
{
	vline('-',75);
	cout << "The list is empty" << endl;
}

// Function to input and check the password for admin access
void inputPassword()
{
	string password, pass;
	fstream passFile;
	passFile.open("password.bin", ios::app | ios::in);
	if (passFile.peek() == ifstream::traits_type::eof())
	{
		pass = "admin123";
		passFile << pass;
	}

	passFile >> pass;
	passFile.close();

	do
	{
		cout << "Enter password: ";
		char ch = _getch();
		while (ch != 13)
		{
			// 13 is the ASCII code for the Enter key
			if (ch == 8)
			{
				// 8 is the ASCII code for the backspace key
				if (!password.empty())
				{
					cout << '\b' << ' ' << '\b';
					password.pop_back();
				}
			}
			else
			{
				password.push_back(ch);
				cout << '*';
			}

			ch = _getch();
		}

		if (password != pass)
		{
			cout << "\nIncorrect Password" << endl;
			vline('-',75);
			password.clear();
		}
	} while (password != pass);
	cout << endl;
}

void changePassword()
{
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

void headerDisplay(){
		cout << R"(	
                     _______       _                _        _______                      _       
                    (_______)     | |              | |      (_______)                    | |      
                     _______ _____| |  _ _____  ___| |__        _  ____ _____ _   _ _____| |  ___ 
                    |  ___  (____ | |_/ |____ |/___)  _ \      | |/ ___|____ | | | | ___ | | /___)
                    | |   | / ___ |  _ (/ ___ |___ | | | |     | | |   / ___ |\ V /| ____| ||___ |
                    |_|   |_\_____|_| \_)_____(___/|_| |_|     |_|_|   \_____| \_/ |_____)\_|___/       
					                                                                           
)";
	
}

bool Bus::fileHandling(int n)
{
	Bus bus;
	int countVar = 0;
	busFileIn.open("bus_info.bin");

	if (busFileIn.peek() == ifstream::traits_type::eof()) {
		
		if(n == 4 || n == 5){
			emptyList();
		}
		
		return false;
	}
	
	else{

	while (busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare)
	{
		bool showInfo = false;

		if (busNumber == bus.busNumber && n == 1)
		{
			countVar++;
		}

		if (destination == bus.destination && n == 2 || n == 4)
		{
			cout<<destination<<endl;
			countVar++;
			if (n == 4)
			{
				showInfo = true;
			}
		}

		if (busNumber == bus.busNumber && destination == bus.destination && n == 3)
		{
			countVar++;
		}

		if (n == 5)
		{
			showInfo = true;
		}

		if (showInfo == true)
		{
			bus.showInfo();
		}
	}

	busFileIn.close();
	if (countVar != 0)
	{
		return true;;
	}

	return false;
}
}

bool Passenger::fileHandling(int n)
{
	Passenger pass;
	int countVar = 0;
	passFileIn.open("passengerInfo.bin");

	if (passFileIn.peek() == ifstream::traits_type::eof())
	{
		return false;
	}
	else{

	while (passFileIn >> pass.name >> pass.ticketNumber >> pass.seatNumber >> pass.phoneNumber >> pass.busNumber)
	{
		if (ticketNumber == pass.ticketNumber && n == 1)
		{
			countVar++;
		}

		if (seatNumber == pass.seatNumber && busNumber == pass.busNumber && n == 2)
		{
			seats[(seatNumber - 1) / 4][(seatNumber - 1) % 4] = 1;
			countVar++;
		}

		if (busNumber = pass.busNumber && n == 3)
		{
			countVar++;
		}
	}

	passFileIn.close();
	if (countVar != 0)
	{
		return true;;
	}

	return false;
}
}

void Bus::adminCheck()
{
	Bus bus;
	Passenger pass;
	bool busNumberExists = false;

	do {
		cout << "Enter the bus number: ";
		cin >> bus.busNumber;

		busNumberExists = bus.fileHandling(1);

		if (busNumberExists == false)
		{
			cout << "ERROR! The bus of number " << bus.busNumber << " doesnot exists" << endl;
		}
	}

	while (busNumberExists == false);
	pass.seatInfo();

}

void Passenger::seatInfo()
{
	//vline('-',120);
	int q = 0;
	bool busNumberExists = false;
	Bus bus;
	Passenger pass;
	pass.busNumber = busNumber;
	busNumberExists = pass.fileHandling(2);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout.width(10);
			if (j == 2)
			{
				cout.width(20);
			}

			if (seats[i][j] == 1)
			{
				cout << ++q << ".!RESERVED";
			}
			else
			{
				cout << ++q << ".!!Empty!!";
			}
		}

		cout << endl;
	}
}

int Bus::checkDetails()
{
	Bus bus;
	int n;
	bool destinationExists = false;
	bool busNumberExists = false;

	cout << "Enter the destination: ";
	cin >> bus.destination;

	destinationExists = bus.fileHandling(4);

	if (destinationExists = false)
	{
		cout << "ERROR! No buses are available for given destination" << endl;
		return n = 0;;
	}

	do {
		cout << "Enter the bus number: ";
		cin >> bus.busNumber;

		busNumberExists = bus.fileHandling(3);

		if (busNumberExists = false)
		{
			cout << "The bus with number " << bus.busNumber << " is not available for given destination" << endl;
		}
	} while (busNumberExists = false);

	return bus.busNumber;

}

void Passenger::bookTicket()
{
	vline('-',120);
	passFileOut.open("passengerInfo.bin", ios::app);
	bool reserved = false;
	bool busNumberExists = false;
	bool destinationExists = false;
	Bus bus;
	Passenger pass;

	pass.busNumber = bus.checkDetails();
	pass.seatInfo();

	do {
		vline('-',120);
		cout << "Enter seat number: ";
		cin >> pass.seatNumber;

		reserved = pass.fileHandling(2);

		if (reserved == true)
		{
			cout << "ERROR! The seat is already reserved" << endl;
		}
		else if (pass.seatNumber > 32)
		{
			cout << "ERROR! The seat limit is 32. So, please enter seat number upto 32" << endl;
		}
	} while (reserved == true || pass.seatNumber > 32);

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
	showTicket(pass.ticketNumber);
}

void Passenger::cancelReservation()
{
	// Creating objects of the class Bus
	Passenger pass1, pass2;
	bool ticketNumberExists = false;

	// Opening the passenger info file for reading and writing
	passFileIn.open("passengerInfo.bin");
	passFileOut.open("tempPass.bin");

	pass1.ticketNumber = ticketNumber;

	// Checking if the entered ticket number exists
	ticketNumberExists = pass1.fileHandling(1);

	if (ticketNumberExists == false)
	{
		cout << "ERROR! Ticket number not found" << endl;
		return passenger();
	}

	passFileIn.clear();
	passFileIn.seekg(0);
	while (passFileIn >> pass2.name >> pass2.ticketNumber >> pass2.seatNumber >> pass2.phoneNumber >> pass2.busNumber)
	{
		if (pass2.ticketNumber != pass1.ticketNumber)
		{
			passFileOut << pass2.name << " " << pass2.ticketNumber << " " << pass2.seatNumber << " " << pass2.phoneNumber << " " << pass2.busNumber << endl;
		}
	}

	passFileIn.close();
	passFileOut.close();

	remove("passengerInfo.bin");

	rename("tempPass.bin", "passengerInfo.bin");
}

void Passenger::showTicket(int ticketNumber){
	
	
}

void Bus::showDetails(){
	
	
}

void Bus::inputInfo()
{
	bool busNumberExists = false;
	Bus bus;

	busFileOut.open("bus_info.bin", ios::app);
	//vline('-',75);
	do {
		cout << "Enter the bus number: ";
		cin >> bus.busNumber;

		busNumberExists = bus.fileHandling(1);

		if (busNumberExists == true)
		{
			cout << "ERROR! The bus number " << bus.busNumber << " already exists" << endl;
		}
	} while (busNumberExists == true);

	cout << "Enter the driver's name: ";
	getline(cin >> ws, bus.driverName);
	cout << "From: ";
	getline(cin, bus.origin);
	cout << "To: ";
	getline(cin, bus.destination);
	cout << "Enter the arrival time (hh:mm): ";
	getline(cin, bus.arrivalTime);
	cout << "Enter the departure time (hh:mm): ";
	getline(cin, bus.departureTime);
	cout << "Enter the fare: ";
	cin >> bus.fare;
	busFileOut << bus.destination << " " << bus.origin << " " << bus.driverName << " " << bus.busNumber << " " << bus.arrivalTime << " " << bus.departureTime << " " << bus.fare << endl;
	cout << "Bus added successfully" << endl;
	busFileOut.close();
}

// This function shows the details about the bus
void Bus::showInfo()
{
	vline('-',120);
	cout << "Bus number: " << busNumber << endl;
	cout << "Driver's Name: " << driverName << endl;
	cout << "From: " << origin << endl;
	cout << "To: " << destination << endl;
	cout << "Arrival Time: " << arrivalTime << endl;
	cout << "Departure Time: " << departureTime << endl;
	cout << "Fare: Rs " << fare << endl;
}

void Bus::removeInfo()
{
	bool busNumberExists = false;
	bool validChoice = false;
	Bus bus1, bus2;
	Passenger pass;
	string choice;

	cout << "Enter the bus number: ";
	cin >> bus1.busNumber;

	busNumberExists = bus1.fileHandling(1);

	if (busNumberExists == false)
	{
		cout << "ERROR! The bus number " << bus1.busNumber << " is not on the list" << endl;
		return admin();
	}

	cout << "WARNING! All the passengers' data of the bus with the number " << bus1.busNumber << " will be removed\nDo you wish to continue? (Y/N)" << endl;
	while (!validChoice)
	{
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "n" || choice == "N")
		{
			validChoice = true;
		}
		else
		{
			cout << "ERROR! Please enter a valid option (y/Y) for yes or (n/N) for no" << endl;
		}
	}

	if (choice == "y" || choice == "Y")
	{
		busFileIn.open("bus_info.bin");
		busFileOut.open("tempBus.bin");

		while (busFileIn >> bus2.destination >> bus2.origin >> bus2.driverName >> bus2.busNumber >> bus2.arrivalTime >> bus2.departureTime >> bus2.fare)
		{
			if (bus1.busNumber != bus2.busNumber)
			{
				busFileOut << bus2.destination << " " << bus2.origin << " " << bus2.driverName << " " << bus2.busNumber << " " << bus2.arrivalTime << " " << bus2.departureTime << " " << bus2.fare << endl;
			}
		}

		busFileIn.close();
		busFileOut.close();
		remove("bus_info.bin");
		rename("tempBus.bin", "bus_info.bin");

		do { 	busNumberExists = pass.fileHandling(3);

			if (busNumberExists = true)
			{
				pass.cancelReservation();
			}
		}

		while (busNumberExists = true);

		cout << "SUCCESS! The bus has been removed from the list" << endl;
	}
	else
	{
		return admin();
	}
}

void Bus::admin()
{
	Bus bus;
	Passenger pass;
	bool validChoice = true;
	if (bypass == false)
	{
		inputPassword();
		bypass = true;
	}

	vline('-',120);
	cout << " 1. Add a bus\n 2. Delete bus\n 3. View Available Buses\n 4. Check seat status\n 5. Change to Passenger mode\n 6. Change admin password\n 7. Exit" << endl;
	vline('-',120); 
	int option = 0;
	do{	
		cout<<"Select an action: ";
		cin >> option;
		if (cin.fail() == true)
		{
			validChoice = false;
			cout<<"\aERROR! Please enter valid numbers from 1 to 7"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		}
		
	vline('-',120);
	} while (validChoice == false);

	switch (option)
	{
	case 1:
		bus.inputInfo();
		break;

	case 2:
		bus.removeInfo();
		break;

	case 3:
		bus.fileHandling(5);
		break;

	case 4:
		bus.adminCheck();
		break;
	
	case 5:
		pass.passenger();
		break;

	case 6:
		bypass = false;
		changePassword();
		break;

	case 7:
		cout << "Closing the program!!" << endl
			 << "<Thank You :)>" << endl
			 << "Created By Aakash Dhakal" << endl;
		exit(0);
		break;
		
	}
	admin();
}

// This function contains acions that can be performed by passenger
void Passenger::passenger()
{
	Passenger pass;
	Bus bus;
	bool validChoice = true;
	vline('-',120);
	cout << " 1. View Available Buses\n 2. Book a ticket\n 3. View your ticket\n 4. Cancel your Reservation\n 5. Change to Admin mode\n 6. Exit" << endl;

	vline('-',120);
	int option = 0;
		do{	
		cout<<"Select an action: ";
		cin >> option;
		if (cin.fail() == true)
		{
			validChoice = false;
			cout<<"\aERROR! Please enter valid numbers from 1 to 6"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		}
	vline('-',120);
	} while (validChoice == false);

	switch (option)
	{
	case 1:
		bus.fileHandling(5);
		break;

	case 2:
		pass.bookTicket();
		break;

	case 3:

		cout << "Enter your ticket number: ";
		cin >> pass.ticketNumber;
		showTicket(pass.ticketNumber);
		break;

	case 4:
		cout << "Enter your ticket number: ";
		cin >> pass.ticketNumber;
		pass.cancelReservation();
		cout << "SUCCESS! The reservation of ticket number " << pass.ticketNumber << " is successfully cancelled" << endl;
		break;

	case 5:
		bus.admin();
		break;

	case 6:
		cout << "Closing the program!!" << endl
			 << "<Thank You :)>" << endl
			 << "Created By Aakash Dhakal" << endl;
		exit(0);
		break;
	}

	passenger();
	vline('-',75);
}

void programMode(){
	
	Bus bus;
	Passenger pass;
	bool validChoice = true;
	vline('-',120);
	cout <<setw(30)<< " 1. Admin"<<setw(35)<<" 2. Passenger "<<setw(30)<<"3. Exit" << endl;
	vline('-',120);
	int choice;

	do
	{	
		cout<<"Select program mode: ";
		cin >> choice;
		if (cin.fail() == true)
		{
			validChoice = false;
			cout<<"\aERROR! Please enter valid numbers from 1 to 3"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		}
	vline('-',120);
	} while (validChoice == false);

	switch (choice)
	{
	case 1:
		bus.admin();
		break;

	case 2:
		pass.passenger();
		break;

	case 3:
		cout << "Closing the program!!" << endl
			 << "<Thank You :)>" << endl
			 << "Created By Aakash Dhakal" << endl;
				exit(0);
	}
}

// This is the main function from where the program starts
int main()
{

headerDisplay();
programMode();


	return 0;
}
