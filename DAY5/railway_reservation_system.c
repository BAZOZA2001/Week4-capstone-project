#include <stdio.h>
#include <string.h>

// Structure to store train details
struct Train {
    int trainNumber;
    char destination[50];
    int availableSeats;
    float ticketPrice;
};

// Function to display the available trains
void viewAvailableTrains(struct Train trains[], int trainCount) {
    printf("\n===== Available Trains =====\n");
    for (int i = 0; i < trainCount; i++) {
        printf("Train Number: %d\n", trains[i].trainNumber);
        printf("Destination: %s\n", trains[i].destination);
        printf("Available Seats: %d\n", trains[i].availableSeats);
        printf("Ticket Price: $%.2f\n", trains[i].ticketPrice);
        printf("----------------------------\n");
    }
}

// Function to book tickets
void bookTickets(struct Train trains[], int trainCount) {
    int trainNumber, seatsToBook, trainFound = 0;
    printf("\nEnter the train number you want to book: ");
    scanf("%d", &trainNumber);
    
    // Search for the selected train
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            trainFound = 1;
            printf("Enter the number of seats to book: ");
            scanf("%d", &seatsToBook);
            
            if (seatsToBook <= trains[i].availableSeats) {
                // If enough seats are available, update the available seats
                trains[i].availableSeats -= seatsToBook;
                printf("\nBooking successful! %d seats have been booked on Train %d.\n", seatsToBook, trainNumber);
            } else {
                printf("\nSorry, not enough available seats! Only %d seats available.\n", trains[i].availableSeats);
            }
            break;
        }
    }
    
    if (!trainFound) {
        printf("\nTrain number %d not found.\n", trainNumber);
    }
}

// Function to cancel tickets
void cancelTickets(struct Train trains[], int trainCount) {
    int trainNumber, seatsToCancel, trainFound = 0;
    printf("\nEnter the train number you want to cancel tickets for: ");
    scanf("%d", &trainNumber);
    
    // Search for the selected train
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            trainFound = 1;
            printf("Enter the number of seats to cancel: ");
            scanf("%d", &seatsToCancel);
            
            if (seatsToCancel > 0) {
                // If the user wants to cancel seats, update the available seats
                trains[i].availableSeats += seatsToCancel;
                printf("\nCancellation successful! %d seats have been added back to Train %d.\n", seatsToCancel, trainNumber);
            } else {
                printf("\nInvalid number of seats to cancel. It must be positive.\n");
            }
            break;
        }
    }
    
    if (!trainFound) {
        printf("\nTrain number %d not found.\n", trainNumber);
    }
}

// Function to search trains by destination
void searchTrains(struct Train trains[], int trainCount) {
    char destination[50];
    int found = 0;
    
    printf("\nEnter the destination to search for: ");
    scanf("%s", destination);  // Read destination from user input
    
    printf("\n===== Trains to %s =====\n", destination);
    for (int i = 0; i < trainCount; i++) {
        if (strcmp(trains[i].destination, destination) == 0) {
            // If destination matches, display train details
            printf("Train Number: %d\n", trains[i].trainNumber);
            printf("Available Seats: %d\n", trains[i].availableSeats);
            printf("Ticket Price: $%.2f\n", trains[i].ticketPrice);
            printf("----------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No trains found for the destination %s.\n", destination);
    }
}

void showMenu() {
    printf("\n===== Railway Reservation System =====\n");
    printf("1. View available trains\n");
    printf("2. Book tickets\n");
    printf("3. Cancel tickets\n");
    printf("4. Search by destination\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    // Array of trains
    struct Train trains[] = {
        {101, "NewYork", 50, 75.50},
        {102, "LosAngeles", 30, 85.30},
        {103, "Chicago", 100, 60.20},
        {104, "SanFrancisco", 20, 95.75}
    };
    int trainCount = sizeof(trains) / sizeof(trains[0]);

    int choice;

    while (1) {  // Infinite loop to keep the menu running until the user exits
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewAvailableTrains(trains, trainCount);  // Display available trains
                break;
            case 2:
                bookTickets(trains, trainCount);  // Call the function to book tickets
                break;
            case 3:
                cancelTickets(trains, trainCount);  // Call the function to cancel tickets
                break;
            case 4:
                searchTrains(trains, trainCount);  // Call the function to search by destination
                break;
            case 5:
                printf("\nExiting... Thank you for using the system!\n");
                return 0;  // Exit the program
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
