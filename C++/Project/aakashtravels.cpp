#include <bits/stdc++.h>
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

 public:
  void inputInfo();
  void showInfo();
  void removeInfo();
  void seatInfo();
  friend class Passenger;

} b[10];

class Passenger {
  string name;
  int seatNumber;
  int ticketNumber;

 public:
  void bookTicket();
  void showTicket();
  friend class Bus;

} p[1000];

void vline(char ch) {
  for (int i = 75; i > 0; i--) {
    cout << ch;
  }
  cout << endl;
}
void Bus::seatInfo() {
  vline('-');
  int q = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      cout.width(10);
      if (seats[i][j] != 0) {
        cout << ++q << ". BOOKED";
      } else {
        cout << ++q << ". Empty";
      }
    }
    cout << endl;
  }
  vline('-');
}

void roleSelect();
void emptyList() {
  vline('-');
  cout << "The list is empty" << endl;
  vline('-');
}

void passenger() {
  vline('-');
  cout << "Select an action\n 1. See Available Buses\n 2. Book a ticket\n 3. "
          "View your ticket\n 4. Change User Role\n 5. Exit"
       << endl;
  int option;
  cin >> option;

  switch (option) {
    case 1:
      b[0].showInfo();
      break;

    case 2:
      p[0].bookTicket();
      break;

    case 3:
      p[0].showTicket();
      break;

    case 4:
      roleSelect();
      break;

    case 5:
      exit(0);
      break;
    default:
      cout << "Error! Please enter numbers 1 or 2 or 3" << endl;
      passenger();
      break;
  }
  vline('-');
  passenger();
}

void busAdmin() {
  vline('-');
  cout << "Select an action\n 1. Add a bus\n 2. Delete bus\n 3. View Available "
          "Buses\n 4. Change User Role\n 5. Exit"
       << endl;
  int option;
  cin >> option;

  switch (option) {
    case 1:
      b[n].inputInfo();
      break;

    case 2:
      b[0].removeInfo();
      break;

    case 3:
      b[0].showInfo();
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

  vline('-');
  busAdmin();
}

void roleSelect() {
  vline('-');
  cout << "Please mention your role:\n 1. Admin \n 2. Passenger" << endl;
  int option;
  cin >> option;

  switch (option) {
    case 1:
      busAdmin();
      break;

    case 2:
      passenger();
      break;

    default:
      cout << "Error! Please enter numbers 1 or 2" << endl;
      roleSelect();
      break;
  }
  vline('-');
}

void Passenger::bookTicket() {
  string dest;
  int bnum, temp = 0, i;
  cout << "Please enter the desired destination: ";
  cin >> dest;

  for (int i = 0; i < n; i++) {
    if (dest == b[i].destination) {
      vline('-');
      cout << "Bus number: " << b[i].busNumber << endl;
      cout << "Driver's Name: " << b[i].driverName << endl;
      cout << "From: " << b[i].origin << endl;
      cout << "To: " << b[i].destination << endl;
      cout << "Arrival Time: " << b[i].arrivalTime << endl;
      cout << "Departure Time: " << b[i].departureTime << endl;
      cout << "Fare: Rs " << b[i].fare << endl;
      vline('-');
    }

    else {
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
snum:
  cout << "Enter seat number: ";
  cin >> p[np].seatNumber;

  if (p[np].seatNumber > 32) {
    cout << "ERROR! The seat limit is 32. So, please enter seat number upto 32"
         << endl;
    goto snum;
  }
  if (b[i].seats[p[np].seatNumber / 4][(p[np].seatNumber % 4) - 1] != 0) {
    cout << "ERROR! The seat is already reserved" << endl;
    goto snum;
  }

  cout << "Enter passenger's name: ";
  cin >> p[np].name;
  p[np].ticketNumber = 1000 + (rand() % 1000);
  b[i].seats[p[np].seatNumber / 4][(p[np].seatNumber % 4) - 1] =
      p[np].ticketNumber;
  cout << "Your ticket number is: " << p[np].ticketNumber << endl;
  np++;
  cout << "(NOTE: Please note down your ticket number as it is required to get "
          "details about your seat)"
       << endl;
  cout << "Your seat is reserved successfully" << endl;
  system("pause");
}

void Passenger::showTicket() {
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
    showTicket();
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
  vline('-');
  system("pause");
}
void Bus::inputInfo() {
  cout << "Enter the bus number: ";
  cin >> b[n].busNumber;

  for (int i = 0; i < n; i++) {
    if (b[i].busNumber == busNumber) {
      cout << "The bus number already exists\nPlease enter different bus number"
           << endl;
      return inputInfo();
    }
  }
  cout << "Enter the driver's name: ";
  getline(cin >> ws, b[n].driverName);
  cout << "From: ";
  getline(cin, b[n].origin);
  cout << "To: ";
  getline(cin, b[n].destination);
  cout << "Enter the arrival time (hh:mm): ";
  getline(cin, b[n].arrivalTime);
  cout << "Enter the departure time (hh:mm): ";
  getline(cin, b[n].departureTime);
  cot << "Enter the fare: ";
  cin >> b[n].fare;
  cout << "Bus added successfully" << endl;
  n++;
  system("pause");
}

void Bus::showInfo() {
  if (n <= 0) {
    emptyList();
  } else {
    for (int i = 0; i < n; i++) {
      vline('-');
      cout << "Bus number: " << b[i].busNumber << endl;
      cout << "Driver's Name: " << b[i].driverName << endl;
      cout << "From: " << b[i].origin << endl;
      cout << "To: " << b[i].destination << endl;
      cout << "Arrival Time: " << b[i].arrivalTime << endl;
      cout << "Departure Time: " << b[i].departureTime << endl;
      cout << "Fare: Rs " << b[i].fare << endl;
      vline('-');
    }
  }
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
        busAdmin();
      }
    }
    cout << "Error! Bus not found in the list" << endl;
    vline('-');
    removeInfo();
  }
}

int main() {
  srand(time(0));
  cout << "E-Ticket" << endl;
  roleSelect();
  return 0;
}