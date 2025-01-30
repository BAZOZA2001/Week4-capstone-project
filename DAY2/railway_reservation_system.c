#include <stdio.h>

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
        {101, "New York", 50, 75.50},
        {102, "Los Angeles", 30, 85.30},
        {103, "Chicago", 100, 60.20},
        {104, "San Francisco", 20, 95.75}
    };
    int trainCount = sizeof(trains) / sizeof(trains[0]);

    int choice;

    while (1) {  // Infinite loop to keep the menu running until the user exits
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewAvailableTrains(trains, trainCount);  // Call the function to display trains
                break;
            case 2:
                printf("\nBook tickets feature coming soon!\n");
                break;
            case 3:
                printf("\nCancel tickets feature coming soon!\n");
                break;
            case 4:
                printf("\nSearch by destination feature coming soon!\n");
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
