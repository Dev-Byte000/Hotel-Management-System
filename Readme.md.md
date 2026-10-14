# 🏨 Hotel Management System in C++

## 📌 Project Overview

The **Hotel Management System** is a console-based application developed using C++. It helps manage basic hotel operations, including room availability, guest check-in, check-out, food ordering, billing, and revenue calculation.

The project uses fundamental C++ concepts such as structures, classes, objects, arrays, functions, loops, conditional statements, and encapsulation.

## ✨ Features

- **Display Rooms:** View room numbers, types, rates, and availability status.
- **Guest Check-In:** Register guests, assign available rooms, and generate unique guest IDs.
- **Guest Check-Out:** Calculate the final bill, update revenue, and make the room available again.
- **View Guests:** Display information about currently registered guests.
- **Food Ordering:** Allow guests to order food and add the charges to their accounts.
- **Bill Generation:** Calculate room charges, food charges, and the total bill.
- **Revenue Tracking:** Display the total revenue collected from completed check-outs.
- **Menu-Driven Interface:** Navigate hotel operations using a simple console menu.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Libraries:** `iostream`, `iomanip`, `string`, `limits`
- **Concepts:** Object-Oriented Programming (OOP), structures, arrays, functions, loops, and conditional statements.

## 🏨 Room Details

| Room Number | Room Type | Rate |
|---|---|---:|
| 101 | Single | ₹1,000 |
| 102 | Double | ₹1,500 |
| 103 | Double | ₹1,500 |
| 201 | Single | ₹1,000 |
| 202 | Suite | ₹3,000 |

*Room rates are per night in the intended design, but the current program calculates room charges using a fixed three-night duration.*

## 🍔 Food Menu

| Item | Price |
|---|---:|
| Burger | ₹450 |
| Fries | ₹200 |
| Soda | ₹150 |
| Pizza | ₹800 |

Guests can order multiple items and quantities. Food charges are added to the guest's account and included in the final bill.

## 💻 Requirements

Before running the project, make sure you have:

- A C++ compiler such as GCC or MinGW.
- An IDE or code editor such as Visual Studio Code, Code::Blocks, or Dev-C++.
- A terminal or command prompt to run the application.

## 🚀 How to Run the Project

### Step 1: Clone the repository

```bash
git clone <your-repository-url>
```

### Step 2: Open the project folder

```bash
cd Hotel-Management-System
```

### Step 3: Compile the program

Save the source code as `main.cpp`, then run:

```bash
g++ -std=c++11 main.cpp -o hotel
```

### Step 4: Execute the program

On Windows:

```bash
hotel.exe
```

On Linux or macOS:

```bash
./hotel
```

## 📋 Main Menu

When the program starts, the following menu appears:

```text
===== HOTEL MANAGEMENT =====
1. Display Rooms
2. Check In
3. Check Out and Bill
4. View Guests
5. Order Food
6. View Revenue
7. Exit
Enter choice:
```

Enter the corresponding number to perform an operation.

## 🧠 OOP Concepts Used

### 1. Class

The `HotelManager` class manages the hotel's operations, data, and functionality.

### 2. Encapsulation

Room details, guest records, food prices, and revenue are stored as private members of the `HotelManager` class. Public member functions provide access to the required operations.

### 3. Objects

The statement `HotelManager hotel;` creates an object that is used to access the hotel's functions.

### 4. Structures

The `Room` and `Guest` structures group related data into a single unit.

### 5. Member Functions

Functions such as `checkIn()`, `checkOut()`, `orderFood()`, and `displayRooms()` perform specific tasks.

## 📂 Project Structure

```text
Hotel-Management-System/
│
├── main.cpp
└── README.md
```

## ⚙️ How the System Works

1. The program displays the main menu.
2. The user selects an operation.
3. For check-in, the program verifies room availability and registers the guest.
4. Guests can order food using their unique guest IDs.
5. During check-out, the program calculates the room and food charges.
6. The total bill is added to the revenue, and the room becomes available.
7. The user can view active guests and total collected revenue.
8. The program exits when the user selects option 7.

## ⚠️ Limitations

- The program supports only five predefined rooms.
- It stores a maximum of 50 active guest records.
- Room charges are calculated for a fixed three-night stay.
- Guest and revenue data are stored in memory and are lost when the program terminates.
- The application does not include user authentication or database integration.
- Input validation for non-numeric menu entries can be improved.

## 🔮 Future Enhancements

- Add check-in and check-out dates to calculate room charges dynamically.
- Integrate a database such as MySQL to store guest records.
- Add guest details such as phone number and address.
- Generate printable bills and booking receipts.
- Add employee management and room-service features.
- Implement stronger input validation and error handling.

## 🎯 Project Objectives

- To understand the practical application of C++ programming.
- To implement basic Object-Oriented Programming concepts.
- To simplify hotel room and guest management.
- To automate food billing and revenue calculation.
- To develop problem-solving and programming skills through a real-world project.

## 👨‍💻 Author

**Name:** Your Name

**Project:** Hotel Management System

**Language:** C++

## 📄 License

This project is intended for educational and learning purposes. You may modify and extend it for academic projects.
