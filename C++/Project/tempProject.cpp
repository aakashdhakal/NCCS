//Basic header files required for different inbuilt function 
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <random>
#include <iomanip>
using namespace std;

//Here class bus is defined that makes easier to implement different methods
class Bus
{
	//Private variables for class Bus
	string destination;
	string origin;
	string driverName;
	int busNumber;
	string arrivalTime;
	string departureTime;
	int fare;
	int seats[8][4] = { 0 };

	string name;
	int seatNumber;
	int ticketNumber;
	int phoneNumber;
	ofstream busFileOut, passFileOut;
	ifstream busFileIn, passFileIn;
	bool bypass = false;

	//Public access functions for class Bus
	public:
		void inputInfo();
	void showInfo();
	void removeInfo();
	void seatInfo();
	void passenger();
	void admin();
	void bookTicket();
	void cancelReservation(int);
	void showTicket(int);
	bool searchBus();
	void changePassword();
	bool checkBusNum();
	bool checkDestination();
	bool checkSeatNum();
	bool checkTicketNum();
	bool checkDestinationWithBusNum();
};

//This function is used to generate line for distinctive output
void vline(char ch)
{
	for (int i = 75; i > 0; i--)
	{
		cout << ch;
	}

	cout << endl;
}

//This function will run if  there are no bus in the system and user try to access bus info
void emptyList()
{
	vline('-');
	cout << "\x1b[91mThe list is empty\033[0m" << endl;
}

//Function to input and check the password for admin access
void inputPassword()
{
	string password, pass;
	fstream passFile;
	passFile.open("password.bin", ios::app | ios:: in);
	if (passFile.peek() == ifstream::traits_type::eof())
	{
		passFile << "admin123";
	}

	passFile >> pass;
	passFile.close();

	do {
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
			cout << "\n\x1b[91mIncorrect Password\033[0m" << endl;
			vline('-');
			password.clear();
		}
	} while (password != pass);
	cout << endl;

}

//Function to check if the bus number entered exists in the system
bool Bus::checkBusNum()
{
	int n = 0;
	Bus tempBus;
	busFileIn.open("bus_info.bin", ios::binary);

	busFileIn.clear();
	busFileIn.seekg(0);

	while (busFileIn >> tempBus.destination >> tempBus.origin >> tempBus.driverName >> tempBus.busNumber >> tempBus.arrivalTime >> tempBus.departureTime >> tempBus.fare)
	{
		if (busNumber == tempBus.busNumber)
		{
			n++;
		}
	}

	busFileIn.close();

	if (n == 0)
	{
		return false;
	}

	return true;
}

bool Bus::checkDestination()
{
	int n = 0;
	Bus tempBus;
	busFileIn.open("bus_info.bin", ios::binary);

	busFileIn.clear();
	busFileIn.seekg(0);

	while (busFileIn >> tempBus.destination >> tempBus.origin >> tempBus.driverName >> tempBus.busNumber >> tempBus.arrivalTime >> tempBus.departureTime >> tempBus.fare)
	{
		if (destination == tempBus.destination)
		{
			n++;
		}
	}

	busFileIn.close();

	if (n == 0)
	{
		return false;
	}

	return true;
}

bool Bus::checkSeatNum()
{
	int n = 0;
	Bus tempBus;
	passFileIn.open("passengerInfo.bin", ios::binary);

	passFileIn.clear();
	passFileIn.seekg(0);

	while (passFileIn >> tempBus.name >> tempBus.ticketNumber >> tempBus.seatNumber >> tempBus.phoneNumber >> tempBus.busNumber)
	{
		if (seatNumber == tempBus.seatNumber && busNumber == tempBus.busNumber)
		{
			n++;
		}
	}

	passFileIn.close();

	if (n == 0)
	{
		return false;
	}

	return true;
}

bool Bus::checkTicketNum()
{
	int n = 0;
	Bus tempBus;
	passFileIn.open("passengerInfo.bin");

	passFileIn.clear();
	passFileIn.seekg(0);

	while (passFileIn >> tempBus.name >> tempBus.ticketNumber >> tempBus.seatNumber >> tempBus.phoneNumber >> tempBus.busNumber)
	{
		if (ticketNumber == tempBus.ticketNumber)
		{
			n++;
		}
	}

	passFileIn.close();

	if (n == 0)
	{
		return false;
	}

	return true;
}

bool Bus::checkDestinationWithBusNum()
{
	int n = 0;
	Bus tempBus;
	busFileIn.open("bus_info.bin");

	busFileIn.clear();
	busFileIn.seekg(0);

	while (busFileIn >> tempBus.destination >> tempBus.origin >> tempBus.driverName >> tempBus.busNumber >> tempBus.arrivalTime >> tempBus.departureTime >> tempBus.fare)
	{
		if (destination == tempBus.destination && busNumber == tempBus.busNumber)
		{
			n++;
		}
	}

	busFileIn.close();

	if (n == 0)
	{
		return false;
	}

	return true;
}

void Bus::changePassword()
{
	string password, pass;
	busFileIn.open("password.bin");

	busFileIn >> pass;
	vline('-');
	do {
		cout << "Enter current password: ";
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
			cout << "\n\x1b[91mIncorrect Password\033[0m" << endl;
			password.clear();
			vline('-');
		}
	} while (password != pass);
	busFileIn.close();
	cout << "\nEnter new password: ";
	cin >> password;
	busFileOut.open("password.bin", ios::trunc);
	busFileOut << password;

	busFileOut.close();
	cout << "Password Changed" << endl;
	bypass = false;
}

//This function shows the seats of the bus and shows whether they are booked or not
void Bus::seatInfo()
{
	vline('-');
	int q = 0;
	int snum, bnum;
	passFileIn.open("passengerInfo.bin");
	passFileIn.clear();
	passFileIn.seekg(0);
	while (passFileIn >> name >> ticketNumber >> snum >> phoneNumber >> bnum)
	{
		if (bnum == busNumber)
		{
			seats[(snum - 1) / 4][(snum - 1) % 4] = 1;
		}
	}

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
				cout << ++q << ".\x1b[91mX\033[0m";
			}
			else
			{
				cout << ++q << ".O";
			}
		}

		cout << endl;
	}

	passFileIn.close();
}

// This function reserves a seat for the passenger in the bus
void Bus::bookTicket()
{
	vline('-');
	passFileIn.open("passengerInfo.bin");
	passFileOut.open("passengerInfo.bin", ios::app);
	busFileIn.open("bus_info.bin", ios:: in);
	int i, row, col;
	bool reserved = false;
	bool busNumberExists = false;
	bool destinationExists = false;
	Bus bus, pass;

	cout << "Please enter the desired destination: ";
	cin >> pass.destination;
	destinationExists = pass.checkDestination();

	if (destinationExists == false)
	{
		cout << "\x1b[91mERROR! No buses are available for given destination\033[0m" << endl;
		return passenger();
	}

	while (busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare)
	{
		if (bus.destination == pass.destination)
		{
			bus.showInfo();
		}
	}

	do {
		vline('-');
		cout << "Enter bus number: ";
		cin >> pass.busNumber;

		busNumberExists = pass.checkBusNum();
		destinationExists = pass.checkDestinationWithBusNum();

		if (busNumberExists == false || destinationExists == false)
		{
			cout << "\x1b[91mERROR! Bus number " << pass.busNumber << " is not available for provided destination\033[0m" << endl;
		}
	} while (busNumberExists == false || destinationExists == false);

	pass.seatInfo();

	do {
		vline('-');
		cout << "Enter seat number: ";
		cin >> pass.seatNumber;

		reserved = pass.checkSeatNum();

		if (reserved == true)
		{
			cout << "\x1b[91mERROR! The seat is already reserved\033[0m" << endl;
		}
		else if (pass.seatNumber > 32)
		{
			cout << "\x1b[91mERROR! The seat limit is 32. So, please enter seat number upto 32\033[0m" << endl;
		}
		else
		{
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
	busFileIn.close();
	passFileIn.close();
	passFileOut.close();
	cout << "\u001b[32;1mYour seat is reserved successfully\033[0m" << endl;
	system("pause");
	showTicket(pass.ticketNumber);

}

void Bus::cancelReservation(int number)
{
	//Creating objects of the class Bus
	Bus pass1, pass2;
	bool ticketNumberExists = false;

	//Opening the passenger info file for reading and writing
	passFileIn.open("passengerInfo.bin");
	passFileOut.open("tempPass.bin");
	number = pass1.ticketNumber;

	//Checking if the entered ticket number exists
	ticketNumberExists = pass1.checkTicketNum();

	if (ticketNumberExists == false)
	{
		cout << "\x1b[91mERROR! Ticket number not found\033[0m" << endl;
		return passenger();
	}

	passFileIn.clear();
	passFileIn.seekg(0);
	while (passFileIn >> pass2.name >> pass2.ticketNumber >> pass2.seatNumber >> pass2.phoneNumber >> pass2.busNumber)
	{
		if (pass2.ticketNumber == pass1.ticketNumber)
		{
			continue;
		}

		passFileOut << pass2.name << " " << pass2.ticketNumber << " " << pass2.seatNumber << " " << pass2.phoneNumber << " " << pass2.busNumber << endl;
	}

	passFileIn.close();
	passFileOut.close();

	remove("passengerInfo.bin");

	rename("tempPass.bin", "passengerInfo.bin");
}

//This function gives the details about the seat and ticket 
void Bus::showTicket(int number)
{
	passFileIn.open("passengerInfo.bin", ios::binary);
	busFileIn.open("bus_info.bin", ios::binary);
	Bus pass1, bus, pass2;
	int n = 0;

	pass1.ticketNumber = number;
	passFileIn.clear();
	passFileIn.seekg(0);

	while (passFileIn >> pass2.name >> pass2.ticketNumber >> pass2.seatNumber >> pass2.phoneNumber >> pass2.busNumber)
	{
		if (pass2.ticketNumber == pass1.ticketNumber)
		{
			n++;
			break;
		}
	}

	passFileIn.close();

	if (n == 0)
	{
		cout << "\x1b[91mERROR! Ticket number not found\033[0m" << endl;
		return passenger();
	}

	while (busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare)
	{
		if (pass2.busNumber == bus.busNumber)
		{
			break;
		}
	}

	busFileIn.close();
	cout << "\033c";
	vline('=');
	cout << "||" << setw(38) << "BUS TICKET" << setw(35) << "||" << endl;
	vline('-');
	cout << "||" << setw(20) << "Passenger's Name: " << pass2.name << setw(37) << "Ticket Number: " << pass2.ticketNumber << setw(6) << "||" << endl;
	cout << "||" << setw(18) << "Contact Number: " << pass2.phoneNumber << setw(46) << "||" << endl;
	cout << "||" << setw(14) << "Bus Number: " << pass2.busNumber << setw(56) << "||" << endl;
	cout << "||" << setw(15) << "Seat Number: " << pass2.seatNumber << setw(56) << "||" << endl;
	cout << "||" << setw(33) << "From: " << bus.origin << setw(5) << "To: " << bus.destination << setw(29) << "||" << endl;
	cout << "||" << setw(63) << "Total Amount: Rs " << bus.fare << setw(6) << "||" << endl;
	vline('-');
	cout << "||" << "NOTE: Please note down your ticket number as it is required for further use" << "||" << endl;
	cout << "||" << "      Please report to the respective counter before an hour of departure otherwise your ticket will be cancelled" << "||" << endl;
	vline('=');
	system("pause");
}

//This function removes a bus from the system
void Bus::removeInfo()
{
	bool busNumberExists = false;
	bool validChoice = false;
	Bus bus1, bus2, pass;
	string choice;
	cout << "Enter the bus number: ";
	cin >> bus1.busNumber;

	busNumberExists = bus1.checkBusNum();

	if (busNumberExists == false)
	{
		cout << "\x1b[91mERROR! The bus number " << bus1.busNumber << " is not on the list\033[0m" << endl;
		return admin();
	}

	cout << "\x1b[91mWARNING! All the passengers' data of the bus with the number " << bus1.busNumber << " will be removed\033[0m\nDo you wish to continue? (Y/N)" << endl;
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
			cout << "\x1b[91mERROR! Please enter a valid option (y/Y) for yes or (n/N) for no!\033[0m" << endl;
		}
	}

	if (choice == "y" || choice == "Y")
	{
		busFileIn.open("bus_info.bin");
		busFileOut.open("tempBus.bin");
		passFileIn.open("passengerInfo.bin");

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

		while (passFileIn >> pass.name >> pass.ticketNumber >> pass.seatNumber >> pass.phoneNumber >> pass.busNumber)
		{
			if (bus1.busNumber == pass.busNumber)
			{
				cout << "loop" << endl;
				cancelReservation(pass.ticketNumber);
			}
		}

		passFileIn.close();

		cout << "\u001b[32;1mSUCCESS! The bus has been removed from the list\033[0m" << endl;
	}
	else
	{
		return admin();
	}
}

void Bus::inputInfo()
{
	bool busNumberExists = false;
	Bus inBus;

	busFileOut.open("bus_info.bin", ios::app);
	vline('-');
	do {
		cout << "Enter the bus number: ";
		cin >> inBus.busNumber;

		busNumberExists = inBus.checkBusNum();

		if (busNumberExists == true)
		{
			cout << "\x1b[91mERROR! The bus number " << inBus.busNumber << " already exists\033[0m" << endl;
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
	cout << "\u001b[32;1mBus added successfully\033[0m" << endl;
	busFileOut.close();
}

//This function shows the details about the bus
void Bus::showInfo()
{
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
void Bus::admin()
{
	Bus b;
	if (bypass == false)
	{
		inputPassword();
		bypass = true;
	}

	vline('-');
	cout << "Select an action\n 1. Add a bus\n 2. Delete bus\n 3. View Available Buses\n 4. Change to Passenger mode\n 5. Change admin password\n 6. Exit" << endl;
	vline('-');
	int option = 0;
	do {
		cin >> option;
		if (cin.fail() == true)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail() == true);

	switch (option)
	{
		case 1:
			inputInfo();
			break;

		case 2:
			removeInfo();
			break;

		case 3:

			busFileIn.open("bus_info.bin", ios:: in);
			if (busFileIn.peek() == ifstream::traits_type::eof())
			{
				emptyList();
			}
			else
			{
				while (busFileIn >> b.destination >> b.origin >> b.driverName >> b.busNumber >> b.arrivalTime >> b.departureTime >> b.fare)
				{
					b.showInfo();
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
			cout << "\x1b[91mERROR! Please enter numbers from 1 to 6\033[0m" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return admin();
	}

	admin();
}

//This function contains acions that can be performed by passenger
void Bus::passenger()
{
	Bus pass, b;
	vline('-');
	cout << "Select an action\n 1. View Available Buses\n 2. Book a ticket\n 3. View your ticket\n 4. Cancel your Reservation\n 5. Change to Admin mode\n 6. Exit" << endl;

	vline('-');
	int option = 0;
	do {
		cin >> option;
		if (cin.fail() == true)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail() == true);

	switch (option)
	{
		case 1:
			busFileIn.open("bus_info.bin", ios:: in);
			if (busFileIn.peek() == std::ifstream::traits_type::eof())
			{
				emptyList();
			}
			else
			{
				while (busFileIn >> b.destination >> b.origin >> b.driverName >> b.busNumber >> b.arrivalTime >> b.departureTime >> b.fare)
				{
					b.showInfo();
				}
			}

			busFileIn.close();

			break;

		case 2:
			bookTicket();
			break;

		case 3:

			cout << "Enter your ticket number: ";
			cin >> pass.ticketNumber;
			showTicket(pass.ticketNumber);
			break;

		case 4:
			cout << "Enter your ticket number: ";
			cin >> pass.ticketNumber;
			cancelReservation(pass.ticketNumber);
			break;

		case 5:
			admin();
			break;

		case 6:
			cout << "Closing the program!!" << endl << "<Thank You :)>" << endl << "Created By Aakash Dhakal" << endl;
			exit(0);
			break;

		default:
			cout << "\x1b[91mError! Please enter valid numbers from 1 to 6\033[0m" << endl;
			return passenger();
			break;
	}

	passenger();
	vline('-');
}

//This is the main function from where the program starts
int main()
{
	Bus b;
	vline('=');
	cout << "Please select program mode\n 1. Admin\n 2. Passenger\n 3. Exit" << endl;
	vline('=');
	int choice;

	do {
		cin >> choice;
		if (cin.fail() == true)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (cin.fail() == true);

	switch (choice)
	{
		case 1:
			b.admin();
			break;

		case 2:
			b.passenger();
			break;

		case 3:
			cout << "Closing the program!!" << endl << "<Thank You :)>" << endl << "Created By Aakash Dhakal" << endl;
			return 0;

		default:
			cout << "\x1b[91mERROR! Please enter valid numbers 1 or 2\033[0m" << endl;
			return main();
			break;
	}

	return 0;
}
