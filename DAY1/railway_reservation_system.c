#include <stdio.h>

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
    int choice;

    while (1) {  // Infinite loop to keep the menu running until the user exits
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nView available trains feature coming soon!\n");
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

