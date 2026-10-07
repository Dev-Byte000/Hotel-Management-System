#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

struct Room {
    int roomNumber;
    bool isBooked;
    string type;
    double rate;
};


struct Guest {
    string guestId;
    string name;
    int checkInDate;
    int checkoutDate;
};


class HotelManager {
private:
map<int, Room> rooms;
map<string, Guest> guests;
int nextGuestId = 1001;

public:
HotelManager() {
    initializeRooms();
}


void initializeRooms() {
    rooms[101] = {101, false, "Single", 1000.0};
    rooms[102] = {102, false, "Double", 1500.0};
    rooms[103] = {103, true, "Double", 1500.0};
    rooms[201] = {201, false, "Single", 1000.0};
    rooms[202] = {202, false, "Suite", 3000.0};
}


void displayMenu() {
    cout << "\n===============================\n";
    cout << "  HOTEL MANAGEMENT SYSTEM\n";
    cout << "===============================\n";
    cout << "1. Display Room Status\n";
    cout << "2. Check-In Guest (Booking)\n";
    cout << "3. Check-Out Guest\n";
    cout << "4. View All Guests\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}


void displayRoomStatus() {
    cout << "\n--- Room Status Report ---\n";
    cout << left << setw(10) << "Room No" 
         << setw(12) << "Type" 
         << setw(15) << "Rate (Per Night)" 
         << setw(12) << "Status" << endl;
    cout << string(49, '-') << endl;


    for (const auto& pair : rooms) {
        const Room& r = pair.second;
        string status = r.isBooked ? "BOOKED" : "AVAILABLE";
        cout << left << setw(10) << r.roomNumber 
             << setw(12) << r.type 
             << "$" << fixed << setprecision(2) << right << setw(14) << r.rate
             << setw(12) << status << endl;
    }
}


int checkAvailableRoom() {
    cout << "\n--- Available Rooms ---\n";
    for (const auto& pair : rooms) {
        if (!pair.second.isBooked) {
            cout << "Room " << pair.first << " (" << pair.second.type << ") - ID: " << pair.first << endl;
        }
    }
    int roomNum = 0;
    do {
        cout << "Enter Room Number to book (or 0 to cancel): ";
        cin >> roomNum;
        if (roomNum == 0) return -1;
        if (rooms.find(roomNum) == rooms.end()) {
            cout << "Invalid Room Number." << endl;
        } else if (!rooms[roomNum].isBooked) {
            return roomNum;
        } else {
            cout << "This room is already occupied." << endl;
        }
    } while (true);
}


void checkInGuest() {
    int roomToBook = checkAvailableRoom();

    if (roomToBook < 0) return;

    string guestName;
    cout << "Enter Guest Name: ";
    cin >> guestName;

    string newId = "G" + to_string(nextGuestId++);
    int checkInDate;
    cout << "Enter Check-In Date (YYYY MM DD): ";
    cin >> checkInDate;

    int checkoutDate = checkInDate + 3; 


    Room& bookedRoom = rooms[roomToBook];
    bookedRoom.isBooked = true;


    Guest newGuest = {newId, guestName, checkInDate, checkoutDate};
    guests[newId] = newGuest;


    cout << "\n====================================\n";
    cout << "SUCCESS: Guest " << guestName << " checked into Room " << roomToBook << ".\n";
    cout << "Booking ID: " << newId << endl;
    cout << "------------------------------------\n";
}


void checkOutGuest() {
    string idToCheckOut;
    cout << "\nEnter Guest ID to check out: ";
    cin >> idToCheckOut;

    if (guests.find(idToCheckOut) == guests.end()) {
        cout << "Error: Guest ID not found.\n";
        return;
    }

    Guest& guest = guests[idToCheckOut];
    int roomNum = -1;


    for (const auto& pair : rooms) {
        if (pair.second.isBooked) {
            if (pair.second.rate == 1500.0 && pair.first >= 101 && pair.first <= 202) { 
                roomNum = pair.first;
                break;
            }
        }
    }


    if (roomNum == -1 || rooms[roomNum].isBooked == false) {
        cout << "Error: Cannot find or confirm the assigned room for this guest.\n";
        return;
    }


    rooms[roomNum].isBooked = false;
    guests.erase(idToCheckOut);


    cout << "\n====================================\n";
    cout << "SUCCESS: Guest " << guest.name << " checked out from Room " << roomNum << ".\n";
    cout << "Thank you for staying with us!\n";
    cout << "====================================\n";
}


void viewAllGuests() {
    if (guests.empty()) {
        cout << "\n--- No active bookings found ---\n";
        return;
    }
    
    cout << "\n--- Active Guest Records ---\n";
    cout << left << setw(12) << "Guest ID" 
         << setw(20) << "Name" 
         << setw(15) << "Check-In Date" 
         << setw(15) << "Checkout Date" << endl;
    cout << string(62, '-') << endl;


    for (const auto& pair : guests) {
        const Guest& g = pair.second;
        cout << left << setw(12) << g.guestId 
             << setw(20) << g.name 
             << setw(15) << g.checkInDate 
             << setw(15) << g.checkoutDate << endl;
    }
}

};


void runSystem() {
    HotelManager hms;
    int choice = -1;

    while (choice != 5) {
        hms.displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                hms.displayRoomStatus();
                break;
            case 2:
                hms.checkInGuest();
                break;
            case 3:
                hms.checkOutGuest();
                break;
            case 4:
                hms.viewAllGuests();
                break;
            case 5:
                cout << "\nExiting Hotel Management System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}


int main() {
    runSystem();
    return 0;
}
