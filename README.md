# Flight Reservation System

A comprehensive C-based flight reservation system that allows users to register, book flights, manage bookings, and track flight information. This project demonstrates advanced C programming concepts including file I/O, structures, arrays, and user interaction.

## Features

### User Management
- **User Registration**: Create new user accounts with username and password
- **Reward Points System**: Track user reward points
- **Travel History**: View complete booking history for registered users

### Flight Management
- **Add Flights**: Add new flights with complete details
- **View Flights**: Display all available flights with status
- **Sort Flights**: Sort flights by price (ascending order)
- **Flight Tracking**: Check real-time flight status
- **Flight Details**: View duration and distance for specific flights

### Booking System
- **Book Flights**: Reserve seats on available flights
- **Seat Selection**: Choose specific seat numbers (1-100)
- **Meal Preferences**: Select meal options (Veg/Non-Veg/Special)
- **Emergency Contacts**: Add emergency contact information
- **E-Ticket Generation**: Generate and view electronic tickets

### Baggage Management
- **Weight Allowance**: Check allowed baggage weight per flight
- **Extra Fare Calculation**: Calculate additional charges for excess baggage
- **Baggage Tracking**: Monitor baggage weight limits

### Administrative Features
- **Booking Statistics**: Count total bookings and flights
- **Complete Booking View**: Display all system bookings
- **Data Persistence**: Save and load data from files

## File Structure

```
jackfruit/
├── jack.c          # Main source code file
├── flights.txt     # Flight data storage
├── bookings.txt    # Booking data storage (created at runtime)
├── a.out          # Compiled executable
└── README.md      # This file
```

## Installation & Compilation

### Prerequisites
- GCC compiler
- Linux/Unix environment (tested on Linux 6.8.0-60-generic)

### Compilation
```bash
gcc -o jack jack.c
```

### Running the Application
```bash
./jack
```

## Usage

1. **Start the Application**: Run the compiled executable
2. **Register**: Create a new user account (required first step)
3. **Navigate Menu**: Use the numbered menu system to access features
4. **Book Flights**: Select option 4 to book available flights
5. **Manage Bookings**: View tickets, travel history, and booking details

### Menu Options

| Option | Function |
|--------|----------|
| 1 | Register User |
| 2 | Add Flight |
| 3 | View Flights |
| 4 | Book Flight |
| 5 | Select Meal |
| 6 | Add Emergency Contact |
| 7 | View E-Ticket |
| 8 | View Travel History |
| 9 | Sort Flights by Price |
| 10 | Track Flight Status |
| 11 | View Duration and Distance |
| 12 | Baggage Allowance |
| 13 | View All Bookings |
| 14 | Count Bookings |
| 15 | Count Flights |
| 16 | Show Reward Points |
| 17 | Exit |

## Data Structures

### User Structure
```c
struct User {
    char username[30];
    char password[30];
    int points;
};
```

### Flight Structure
```c
struct Flight {
    int flightNo;
    char departure[30];
    char destination[30];
    char status[20];
    float price;
    float duration;
    float distance;
    int allowedWeight;
    float extraFarePerKg;
};
```

### Booking Structure
```c
struct Booking {
    int bookingID;
    char username[30];
    int flightNo;
    int seatNo;
    char mealPref[20];
    char emergencyContact[30];
};
```

## File I/O Operations

The system uses text files for data persistence:

- **flights.txt**: Stores flight information
- **bookings.txt**: Stores booking records (created automatically)

Data is automatically saved when:
- New flights are added
- New bookings are made
- The application exits

## Default Data

The system comes with two default flights:
- Flight 101: Delhi → Mumbai (On-Time, ₹3500)
- Flight 102: Bangalore → Chennai (Delayed, ₹2200)

## Technical Details

- **Language**: C
- **Data Storage**: Text files
- **Memory Management**: Static arrays (100 flights, 100 bookings)
- **Input Validation**: Seat numbers, flight existence checks
- **Error Handling**: File I/O error checking

## Contributing

This is a learning project demonstrating C programming concepts. Feel free to:
- Add new features
- Improve error handling
- Enhance the user interface
- Add database integration
- Implement user authentication

## License

This project is open source and available under the MIT License.

---

**Note**: This system is designed for educational purposes and demonstrates fundamental programming concepts in C. For production use, consider implementing additional security measures, database integration, and more robust error handling. 