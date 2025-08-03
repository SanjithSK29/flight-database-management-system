#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =================== STRUCT DEFINITIONS ===================

struct User {
    char username[30];
    char password[30];
    int points;
};

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

struct Booking {
    int bookingID;
    char username[30];
    int flightNo;
    int seatNo;
    char mealPref[20];
    char emergencyContact[30];
};

// =================== GLOBAL VARIABLES ===================

struct Flight flights[100];
struct Booking bookings[100];
struct User currentUser;
int bookingCount = 0, flightCount = 0;

// =================== FILE HANDLING FUNCTIONS ===================

void saveFlights() {
    FILE *fp = fopen("flights.txt", "w");
    if (!fp) {
        printf("Error opening flights file for writing.\n");
        return;
    }
    for (int i = 0; i < flightCount; i++) {
        fprintf(fp, "%d %s %s %s %.2f %.2f %.2f %d %.2f\n",
                flights[i].flightNo, flights[i].departure, flights[i].destination,
                flights[i].status, flights[i].price, flights[i].duration,
                flights[i].distance, flights[i].allowedWeight, flights[i].extraFarePerKg);
    }
    fclose(fp);
}

void loadFlights() {
    FILE *fp = fopen("flights.txt", "r");
    if (!fp) {
        // No file found, no flights loaded
        return;
    }
    flightCount = 0;
    while (fscanf(fp, "%d %s %s %s %f %f %f %d %f",
                  &flights[flightCount].flightNo, flights[flightCount].departure,
                  flights[flightCount].destination, flights[flightCount].status,
                  &flights[flightCount].price, &flights[flightCount].duration,
                  &flights[flightCount].distance, &flights[flightCount].allowedWeight,
                  &flights[flightCount].extraFarePerKg) == 9) {
        flightCount++;
        if (flightCount >= 100) break; // prevent overflow
    }
    fclose(fp);
}

void saveBookings() {
    FILE *fp = fopen("bookings.txt", "w");
    if (!fp) {
        printf("Error opening bookings file for writing.\n");
        return;
    }
    for (int i = 0; i < bookingCount; i++) {
        fprintf(fp, "%d %s %d %d %s %s\n",
                bookings[i].bookingID, bookings[i].username,
                bookings[i].flightNo, bookings[i].seatNo,
                bookings[i].mealPref, bookings[i].emergencyContact);
    }
    fclose(fp);
}

void loadBookings() {
    FILE *fp = fopen("bookings.txt", "r");
    if (!fp) {
        // No bookings file found
        return;
    }
    bookingCount = 0;
    while (fscanf(fp, "%d %s %d %d %s %s",
                  &bookings[bookingCount].bookingID, bookings[bookingCount].username,
                  &bookings[bookingCount].flightNo, &bookings[bookingCount].seatNo,
                  bookings[bookingCount].mealPref, bookings[bookingCount].emergencyContact) == 6) {
        bookingCount++;
        if (bookingCount >= 100) break;
    }
    fclose(fp);
}

// =================== DEFAULT FLIGHTS ===================

void loadDefaultFlights() {
    struct Flight f1 = {101, "Delhi", "Mumbai", "On-Time", 3500, 2.5, 1150, 20, 300};
    struct Flight f2 = {102, "Bangalore", "Chennai", "Delayed", 2200, 1.0, 350, 15, 250};
    flights[flightCount++] = f1;
    flights[flightCount++] = f2;
    printf("Default flights loaded.\n");
}

// =================== FUNCTION DEFINITIONS ===================

void problem1_registerUser() {
    printf("Enter Username: ");
    scanf("%29s", currentUser.username);
    printf("Enter Password: ");
    scanf("%29s", currentUser.password);
    currentUser.points = 0;
    printf("User registered successfully!\n");
}

void problem2_addFlight() {
    struct Flight f;
    printf("Enter Flight No, Departure, Destination, Status, Price, Duration (hrs), Distance (km), Allowed Weight (kg), Extra Fare per kg:\n");
    scanf("%d %29s %29s %19s %f %f %f %d %f", &f.flightNo, f.departure, f.destination, f.status, &f.price, &f.duration, &f.distance, &f.allowedWeight, &f.extraFarePerKg);
    flights[flightCount++] = f;
    saveFlights();
    printf("Flight added!\n");
}

void problem3_displayFlights() {
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }
    for (int i = 0; i < flightCount; i++) {
        printf("Flight %d: %s -> %s | Status: %s | Rs. %.2f | %.1f hrs | %.1f km\n",
               flights[i].flightNo, flights[i].departure, flights[i].destination, flights[i].status,
               flights[i].price, flights[i].duration, flights[i].distance);
    }
}

void problem4_bookFlight() {
    if (flightCount == 0) {
        printf("No flights available to book.\n");
        return;
    }
    struct Booking b;
    b.bookingID = bookingCount + 1;
    strcpy(b.username, currentUser.username);

    printf("Enter Flight No to book: ");
    scanf("%d", &b.flightNo);
    
    // Check if flight exists
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNo == b.flightNo) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Flight number not found.\n");
        return;
    }

    printf("Select seat number (1-100): ");
    scanf("%d", &b.seatNo);
    if (b.seatNo < 1 || b.seatNo > 100) {
        printf("Invalid seat number.\n");
        return;
    }

    printf("Enter meal preference (Veg/Non-Veg/Special): ");
    scanf("%19s", b.mealPref);

    printf("Enter emergency contact name: ");
    scanf("%29s", b.emergencyContact);

    bookings[bookingCount++] = b;
    saveBookings();

    printf("Booking successful! Your booking ID is %d\n", b.bookingID);
}

void problem5_selectMeal() {
    // This function integrated into booking now
    printf("Meal preference is selected during booking.\n");
}

void problem6_addEmergencyContact() {
    // This function integrated into booking now
    printf("Emergency contact is added during booking.\n");
}

void problem7_displayEticket() {
    int bookingID;
    printf("Enter Booking ID: ");
    scanf("%d", &bookingID);
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingID == bookingID) {
            printf("--- E-Ticket ---\nBooking ID: %d\nUsername: %s\nFlight No: %d\nSeat No: %d\nMeal: %s\nEmergency Contact: %s\n",
                   bookings[i].bookingID, bookings[i].username, bookings[i].flightNo,
                   bookings[i].seatNo, bookings[i].mealPref, bookings[i].emergencyContact);
            return;
        }
    }
    printf("Booking not found!\n");
}

void problem8_viewTravelHistory() {
    printf("--- Travel History for %s ---\n", currentUser.username);
    int found = 0;
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].username, currentUser.username) == 0) {
            printf("Booking ID: %d, Flight No: %d, Seat: %d, Meal: %s\n",
                   bookings[i].bookingID, bookings[i].flightNo, bookings[i].seatNo, bookings[i].mealPref);
            found = 1;
        }
    }
    if (!found) {
        printf("No travel history found.\n");
    }
}

void problem9_sortFlightsByPrice() {
    for (int i = 0; i < flightCount - 1; i++) {
        for (int j = i + 1; j < flightCount; j++) {
            if (flights[i].price > flights[j].price) {
                struct Flight temp = flights[i];
                flights[i] = flights[j];
                flights[j] = temp;
            }
        }
    }
    printf("Flights sorted by price.\n");
}

void problem10_trackFlightStatus() {
    int flightNo;
    printf("Enter Flight No: ");
    scanf("%d", &flightNo);
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNo == flightNo) {
            printf("Status for Flight %d: %s\n", flightNo, flights[i].status);
            return;
        }
    }
    printf("Flight not found.\n");
}

void problem11_displayFlightDurationAndDistance() {
    int flightNo;
    printf("Enter Flight No: ");
    scanf("%d", &flightNo);
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNo == flightNo) {
            printf("Flight Duration: %.2f hours\nDistance: %.2f km\n", flights[i].duration, flights[i].distance);
            return;
        }
    }
    printf("Flight not found.\n");
}

void problem12_baggageAllowance() {
    int flightNo, weightCarried;
    printf("Enter Flight No and Weight Carried: ");
    scanf("%d %d", &flightNo, &weightCarried);
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNo == flightNo) {
            printf("Allowed Weight: %d kg\n", flights[i].allowedWeight);
            if (weightCarried > flights[i].allowedWeight) {
                float extra = (weightCarried - flights[i].allowedWeight) * flights[i].extraFarePerKg;
                printf("Extra Fare: Rs. %.2f\n", extra);
            } else {
                printf("No extra charge.\n");
            }
            return;
        }
    }
    printf("Flight not found.\n");
}

void problem13_displayAllBookings() {
    if (bookingCount == 0) {
        printf("No bookings found.\n");
        return;
    }
    for (int i = 0; i < bookingCount; i++) {
        printf("Booking ID: %d | User: %s | Flight: %d | Seat: %d | Meal: %s | Emergency Contact: %s\n",
               bookings[i].bookingID, bookings[i].username, bookings[i].flightNo, bookings[i].seatNo,
               bookings[i].mealPref, bookings[i].emergencyContact);
    }
}

void problem14_countTotalBookings() {
    printf("Total bookings made: %d\n", bookingCount);
}

void problem15_countTotalFlights() {
    printf("Total flights available: %d\n", flightCount);
}

void problem16_showUserPoints() {
    printf("%s has %d reward points.\n", currentUser.username, currentUser.points);
}

// =================== MAIN MENU ===================

int main() {
    int choice;

    printf("\n--- Flight Reservation System ---\n");

    // Load existing flights and bookings from file
    loadFlights();
    loadBookings();

    if (flightCount == 0) {
        loadDefaultFlights();
        saveFlights();
    }

    problem1_registerUser();

    do {
        printf("\n1. Register User\n2. Add Flight\n3. View Flights\n4. Book Flight\n5. Select Meal\n6. Add Emergency Contact\n7. View E-Ticket\n8. View Travel History\n9. Sort Flights by Price\n10. Track Flight Status\n11. View Duration and Distance\n12. Baggage Allowance\n13. View All Bookings\n14. Count Bookings\n15. Count Flights\n16. Show Reward Points\n17. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: problem1_registerUser(); break;
            case 2: problem2_addFlight(); break;
            case 3: problem3_displayFlights(); break;
            case 4: problem4_bookFlight(); break;
            case 5: problem5_selectMeal(); break;
            case 6: problem6_addEmergencyContact(); break;
            case 7: problem7_displayEticket(); break;
            case 8: problem8_viewTravelHistory(); break;
            case 9: problem9_sortFlightsByPrice(); break;
            case 10: problem10_trackFlightStatus(); break;
            case 11: problem11_displayFlightDurationAndDistance(); break;
            case 12: problem12_baggageAllowance(); break;
            case 13: problem13_displayAllBookings(); break;
            case 14: problem14_countTotalBookings(); break;
            case 15: problem15_countTotalFlights(); break;
            case 16: problem16_showUserPoints(); break;
            case 17: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 17);

    // Save flights and bookings on exit
    saveFlights();
    saveBookings();

    return 0;
}
