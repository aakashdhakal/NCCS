// Basic header files required for different inbuilt function
#include <iostream>
#include <fstream>
#include <conio.h>
#include <random>
#include <iomanip>
using namespace std;

// Here class bus is defined that makes easier to implement different methods
class Bus{
	
	private:
		string destination;
		string origin;
		string driverName;
		string arrivalTime;
		string departureTime;
		int fare;
		ofstream busFileOut;
		ifstream busFileIn;
		
	protected:
		int busNumber;
		int seats[8][4] = {0};
		
	public:
		void inputInfo();
		void showInfo();
		void removeInfo();
		void admin();
		void adminCheck();
		bool checkDetails(int);
			
	
};

class Passenger: public Bus{
	
	private:
		string name;
		int seatNumber;
		int ticketNumber;
		int phoneNumber;
		ofstream passFileOut;
		ifstream passFileIn;
		bool bypass = false;
		
	public:
		void bookTicket();
		void cancelReservation();
		void showTicket(int);
		bool checkDetails(int);
		void seatInfo();

};

void vline(char ch,int n)
{
	for (int i = n; i > 0; i--)
	{
		cout << ch;
	}

	cout << endl;
}

	bool Bus::checkDetails(int n){
		
	busFileIn.open("bus_info.bin");
	Bus bus;
	
	busFileIn.clear();
	busFileIn.seekg(0);	
	while (busFileIn >> bus.destination >> bus.origin >> bus.driverName >> bus.busNumber >> bus.arrivalTime >> bus.departureTime >> bus.fare){
		
		if(busNumber == bus.busNumber && n == 1){
			busFileIn.close();
			return true;
		}
		
		
		if(destination == bus.destination && n == 2){
			busFileIn.close();
			return true;
		}
		
		
		if(destination == bus.destination && busNumber == bus.busNumber && n == 3){
			busFileIn.close();
			return true;
		}
		
		
	return false;
}


	bool Passenger::checkDetails(int n){
		
	passFileIn.open("bus_info.bin");
	Passenger pass;
	
	passFileIn.clear();
	passFileIn.seekg(0);	
	while (passFileIn >> pass.name >> pass.ticketNumber >> pass.seatNumber >> pass.phoneNumber >> pass.busNumber){
		
		if(ticketNumber == pass.ticketNumber && n == 1){
			passFileIn.close();
			return true;
		}
		
		if(seatNumber == pass.seatNumber && busNumber == pass.busNumber && n == 2){
			seats[(seatNumber - 1) / 4][(seatNumber - 1) % 4] = 1;
			passFileIn.close();
			return true;
		}
			if(seatNumber == pass.seatNumber && busNumber == pass.busNumber && n == 3){
			seats[(seatNumber - 1) / 4][(seatNumber - 1) % 4] = 1;
		}
		
	}
	passFileIn.close();
	return false;
}

void Bus::adminCheck(){
	Passenger pass;
	Bus bus;
	bool busNumberExists = false;
	
	do{
	cout<<"Enter the bus number: ";
	cin>>bus.busNumber;
	
	busNumberExists = bus.checkDetails(1);
	
	if(busNumberExists == false){
		cout<<"ERROR! The bus of number "<<bus.busNumber<<" doesnot exists"<<endl;
	}
}
	while(busNumberExists == false);
	pass.seatInfo();
}

void Passenger::seatInfo()
{
	vline('-',75);
	int q = 0;
	Passenger pass;
	pass.busNumber = busNumber;
	
	
	pass.checkDetails(3);
	
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

	passFileIn.close();
}

void Passenger::bookTicket()
{
	vline('-',75);
	passFileIn.open("passengerInfo.bin");
	passFileOut.open("passengerInfo.bin", ios::app);
	busFileIn.open("bus_info.bin", ios::in);
	int i, row, col;
	bool reserved = false;
	bool busNumberExists = false;
	bool destinationExists = false;
	Bus bus;
	Passenger pass;

	cout << "Please enter the desired destination: ";
	cin >> bus.destination;
	destinationExists = bus.checkDetails(2);

	if (destinationExists == false)
	{
		cout << "ERROR! No buses are available for given destination" << endl;
		return passenger();
	}

	while (busFileIn >> bus1.destination >> bus1.origin >> bus1.driverName >> bus1.busNumber >> bus1.arrivalTime >> bus1.departureTime >> bus1.fare)
	{
		if (bus.destination == bus1.destination)
		{
			bus.showInfo();
		}
	}

	do
	{
		vline('-',75);
		cout << "Enter bus number: ";
		cin >> pass.busNumber;

		busNumberExists = pass.checkBusNum();
		destinationExists = pass.checkDestinationWithBusNum();

		if (busNumberExists == false || destinationExists == false)
		{
			cout << "ERROR! Bus number " << pass.busNumber << " is not available for provided destination" << endl;
		}
	} while (busNumberExists == false || destinationExists == false);

	pass.seatInfo();

	do
	{
		vline('-',75);
		cout << "Enter seat number: ";
		cin >> pass.seatNumber;

		reserved = pass.checkSeatNum();

		if (reserved == true)
		{
			cout << "ERROR! The seat is already reserved" << endl;
		}
		else if (pass.seatNumber > 32)
		{
			cout << "ERROR! The seat limit is 32. So, please enter seat number upto 32" << endl;
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
	uniform_int_distribution<> dis(1000, 10000);
	pass.ticketNumber = dis(gen);
	passFileOut << pass.name << " " << pass.ticketNumber << " " << pass.seatNumber << " " << pass.phoneNumber << " " << pass.busNumber << endl;
	busFileIn.close();
	passFileIn.close();
	passFileOut.close();
	cout << "Your seat is reserved successfully" << endl;
	system("pause");
	showTicket(pass.ticketNumber);
}

void Bus::showInfo()
{
	vline('-',75);
	cout << "Bus number: " << busNumber << endl;
	cout << "Driver's Name: " << driverName << endl;
	cout << "From: " << origin << endl;
	cout << "To: " << destination << endl;
	cout << "Arrival Time: " << arrivalTime << endl;
	cout << "Departure Time: " << departureTime << endl;
	cout << "Fare: Rs " << fare << endl;
}


int main()
{

	return 0;
}
