#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

struct Room {
    int number;
    string type;
    double rate;
    bool booked;
};

struct Guest {
    string id, name;
    int roomNumber;
    double foodCharges;
};

class HotelManager {
private:
    Room rooms[5] = {
        {101, "Single", 1000, false},
        {102, "Double", 1500, false},
        {103, "Double", 1500, false},
        {201, "Single", 1000, false},
        {202, "Suite", 3000, false}
    };

    Guest guests[50];
    int guestCount = 0;
    int nextId = 1001;
    double revenue = 0;

    string food[4] = {"Burger", "Fries", "Soda", "Pizza"};
    double price[4] = {450, 200, 150, 800};

    int findRoom(int number) {
        for (int i = 0; i < 5; i++)
            if (rooms[i].number == number)
                return i;

        return -1;
    }

    int findGuest(string id) {
        for (int i = 0; i < guestCount; i++)
            if (guests[i].id == id)
                return i;

        return -1;
    }

public:
    void showMenu() {
        cout << "\n===== HOTEL MANAGEMENT =====\n";
        cout << "1. Display Rooms\n";
        cout << "2. Check In\n";
        cout << "3. Check Out and Bill\n";
        cout << "4. View Guests\n";
        cout << "5. Order Food\n";
        cout << "6. View Revenue\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
    }

    void displayRooms() {
        cout << "\nRoom No\tType\tRate\tStatus\n";

        for (int i = 0; i < 5; i++) {
            cout << rooms[i].number << "\t"
                 << rooms[i].type << "\t"
                 << rooms[i].rate << "\t"
                 << (rooms[i].booked ? "Booked" : "Available")
                 << endl;
        }
    }

    void checkIn() {
        if (guestCount == 50) {
            cout << "Guest limit reached!\n";
            return;
        }

        displayRooms();

        int number;
        cout << "\nEnter room number: ";
        cin >> number;

        int index = findRoom(number);

        if (index == -1 || rooms[index].booked) {
            cout << "Invalid or unavailable room!\n";
            return;
        }

        string name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter guest name: ";
        getline(cin, name);

        guests[guestCount].id = "G" + to_string(nextId++);
        guests[guestCount].name = name;
        guests[guestCount].roomNumber = number;
        guests[guestCount].foodCharges = 0;

        rooms[index].booked = true;

        cout << "Check-in successful!\n";
        cout << "Guest ID: " << guests[guestCount].id << endl;

        guestCount++;
    }

    void orderFood() {
        string id;

        cout << "Enter guest ID: ";
        cin >> id;

        int index = findGuest(id);

        if (index == -1) {
            cout << "Guest not found!\n";
            return;
        }

        cout << "\n===== FOOD MENU =====\n";

        for (int i = 0; i < 4; i++)
            cout << i + 1 << ". " << food[i]
                 << " - Rs. " << price[i] << endl;

        int choice, quantity;

        while (true) {
            cout << "Enter item number (0 to finish): ";
            cin >> choice;

            if (choice == 0)
                break;

            if (choice < 1 || choice > 4) {
                cout << "Invalid item!\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity <= 0) {
                cout << "Invalid quantity!\n";
                continue;
            }

            double cost = price[choice - 1] * quantity;
            guests[index].foodCharges += cost;

            cout << "Item added! Cost: Rs. " << cost << endl;
        }
    }

    void checkOut() {
        string id;

        cout << "Enter guest ID: ";
        cin >> id;

        int index = findGuest(id);

        if (index == -1) {
            cout << "Guest not found!\n";
            return;
        }

        Guest g = guests[index];
        int roomIndex = findRoom(g.roomNumber);

        double roomBill = rooms[roomIndex].rate * 3;
        double totalBill = roomBill + g.foodCharges;

        cout << "\n===== FINAL BILL =====\n";
        cout << "Guest: " << g.name << endl;
        cout << "Room charges: Rs. " << roomBill << endl;
        cout << "Food charges: Rs. " << g.foodCharges << endl;
        cout << "Total bill: Rs. "
             << fixed << setprecision(2) << totalBill << endl;

        revenue += totalBill;
        rooms[roomIndex].booked = false;

        for (int i = index; i < guestCount - 1; i++)
            guests[i] = guests[i + 1];

        guestCount--;

        cout << "Check-out successful!\n";
    }

    void viewGuests() {
        if (guestCount == 0) {
            cout << "No active guests.\n";
            return;
        }

        for (int i = 0; i < guestCount; i++) {
            cout << "\nGuest ID: " << guests[i].id;
            cout << "\nName: " << guests[i].name;
            cout << "\nRoom: " << guests[i].roomNumber;
            cout << "\nFood charges: Rs. "
                 << guests[i].foodCharges << endl;
        }
    }

    void viewRevenue() {
        cout << "Total revenue collected: Rs. "
             << fixed << setprecision(2) << revenue << endl;
    }
};

int main() {
    HotelManager hotel;
    int choice;

    do {
        hotel.showMenu();
        cin >> choice;

        switch (choice) {
            case 1: hotel.displayRooms(); break;
            case 2: hotel.checkIn(); break;
            case 3: hotel.checkOut(); break;
            case 4: hotel.viewGuests(); break;
            case 5: hotel.orderFood(); break;
            case 6: hotel.viewRevenue(); break;
            case 7: cout << "Thank you for visiting!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}