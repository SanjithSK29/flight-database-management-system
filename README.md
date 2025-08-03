Flight Reservation System in C
A comprehensive, console-based flight reservation system written in C. This application allows users to register, book flights, view flight details, manage their bookings, and more. It features data persistence by saving and loading flight and booking information to and from text files.
Table of Contents
Features
Data Structures
File Handling
How to Compile and Run
Core Functionalities
Features
This system is packed with a variety of features to manage flight and booking data effectively:
User Management: Simple user registration to associate bookings with a specific user.
Flight Administration:
Add new flights to the system with detailed attributes.
Load a set of default flights if no flight data is found.
Display a list of all available flights.
Sort flights based on their price.
Booking Management:
Book a seat on any available flight.
Meal preference and emergency contact are integrated into the booking process.
Generate a unique e-ticket for each booking.
View a complete travel history for the logged-in user.
Display a comprehensive list of all bookings made in the system.
Flight Information:
Track the real-time status of any flight (e.g., On-Time, Delayed).
Check the duration and distance of a specific flight route.
Calculate baggage allowance and any applicable fees for extra weight.
Data Persistence: All flight and booking records are saved to .txt files (flights.txt, bookings.txt), so your data is safe even after the program closes.
System Analytics:
Get a quick count of the total number of flights available.
Get a quick count of the total number of bookings made.
Data Structures
The system uses three primary structs to organize data:
struct User: Stores user-specific information.
char username[30]
char password[30]
int points (Note: Reward points are part of the structure but not yet functionally implemented for incrementing).
struct Flight: Holds all the essential details for a flight.
int flightNo
char departure[30]
char destination[30]
char status[20]
float price
float duration
float distance
int allowedWeight
float extraFarePerKg
struct Booking: Contains all information related to a single booking transaction.
int bookingID
char username[30]
int flightNo
int seatNo
char mealPref[20]
char emergencyContact[30]
File Handling
The application ensures data persistence through simple text file operations:
flights.txt: Stores the list of all available flights. The program reads from this file on startup and writes to it whenever a new flight is added or when the application exits.
bookings.txt: Stores the records of all bookings. This file is read on startup and updated every time a new booking is made or the application exits.
This approach ensures that all data is retained between sessions.
How to Compile and Run
To get this system running on your local machine, follow these simple steps.
Prerequisites
A C compiler, such as GCC (GNU Compiler Collection).
Compilation
Open your terminal or command prompt.
Navigate to the directory where you have saved the jack.c file.
Compile the code using the following command:
gcc jack.c -o flight_reservation

This command compiles the jack.c source file and creates an executable file named flight_reservation.
Execution
After a successful compilation, run the program with this command:
./flight_reservation


The program will start, load any existing data from .txt files, and prompt you to register a user before displaying the main menu.
Core Functionalities
The main menu provides access to all the system's features. Here is a breakdown of what each option does:
Option
Function
Description
1
Register User
Creates a new user profile by asking for a username and password. Bookings will be tied to this user.
2
Add Flight
Adds a new flight to the system. You will be prompted to enter all flight details.
3
View Flights
Displays a formatted list of all available flights with their key details.
4
Book Flight
Guides you through the process of booking a flight, including selecting a flight number, seat, meal preference, and emergency contact.
5
Select Meal
(Integrated into booking) Informs the user that meal selection is now part of the Book Flight process.
6
Add Emergency Contact
(Integrated into booking) Informs the user that this is now part of the Book Flight process.
7
View E-Ticket
Displays the full details of a specific booking when you provide its Booking ID.
8
View Travel History
Shows a list of all past and present bookings associated with the current user.
9
Sort Flights by Price
Sorts the global list of flights in ascending order of their price. The change is reflected when you View Flights.
10
Track Flight Status
Fetches and displays the current status (e.g., "On-Time", "Delayed") of a flight when you provide its flight number.
11
View Duration & Distance
Shows the flight's travel time (in hours) and total distance (in km).
12
Baggage Allowance
Calculates if your baggage is overweight and determines the extra fare based on the airline's policy.
13
View All Bookings
Displays a complete list of every booking made in the system, regardless of the user.
14
Count Bookings
Shows the total number of bookings currently stored in the system.
15
Count Flights
Shows the total number of flights available in the system.
16
Show Reward Points
Displays the number of reward points for the current user (currently defaults to 0).
17
Exit
Saves all current flight and booking data to their respective .txt files and terminates the program.


