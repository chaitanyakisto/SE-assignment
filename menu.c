#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "car.h"
#include "customer.h"
#include "rental.h"
#include "search.h"

void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);  // Discards leftover characters in input buffer
}

// Customers menu
void customers_menu(Customer customers[], int *customer_count, int *next_customer_id) {
    int choice, id;
    
    while (1) {
        printf("\nCustomers Management\n");
        printf("1. Register Customer\n");
        printf("2. Deregister Customer\n");
        printf("3. Update Customer\n");
        printf("4. Display Customers\n");
        printf("5. Return to Main Menu\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue;  // Restart the loop
        }

        switch (choice) {
            case 1:
                register_customer(customers, customer_count, next_customer_id);
                break;
            case 2:
                printf("Enter customer ID to deregister: ");
                scanf("%d", &id);
                deregister_customer(customers, customer_count, id);
                break;
            case 3:
                printf("Enter customer ID to update: ");
                scanf("%d", &id);
                update_customer(customers, *customer_count, id);
                break;
            case 4:
                display_customers(customers, *customer_count);
                break;
            case 5:
                return;  // Return to the main menu
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Cars menu
void cars_menu(Car cars[], int *car_count) {
    int choice, id;
    
    while (1) {
        printf("\nCars Management\n");
        printf("1. Add Car\n");
        printf("2. Remove Car\n");
        printf("3. Update Car\n");
        printf("4. Display Cars\n");
        printf("5. Return to Main Menu\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();  // Clears invalid input
            continue;  // Restart the loop
        }

        switch (choice) {
            case 1:
                add_car(cars, car_count);
                break;
            case 2:
                printf("Enter car ID to remove: ");
                scanf("%d", &id);
                remove_car(cars, car_count, id);
                break;
            case 3:
                printf("Enter car ID to update: ");
                scanf("%d", &id);
                update_car(cars, *car_count, id);
                break;
            case 4:
                display_cars(cars, *car_count);
                break;
            case 5:
                return;  // Return to the main menu
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Rental menu
void rental_menu(Rental rentals[], int *rental_count, Car cars[], int car_count, Customer customers[], int customer_count) {
    int choice, id;
    
    while (1) {
        printf("\nRental Management\n");
        printf("1. Book Car\n");
        printf("2. Return Car\n");
        printf("3. Display Rentals\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                book_car(rentals, rental_count, cars, car_count, customers, customer_count);
                break;
            case 2:
                printf("Enter rental ID to return: ");
                scanf("%d", &id);
                return_car(rentals, rental_count, cars, car_count, id);
                break;
            case 3:
                display_rentals(rentals, *rental_count);
                break;
            case 4:
                return;  // Return to the main menu
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Search menu
void search_menu(Car cars[], int car_count) {
    int choice;
    char search_term[50];
    
    while (1) {
        printf("\nSearch System\n");
        printf("1. Search Cars by Availability\n");
        printf("2. Search Cars by Type\n");
        printf("3. Return to Main Menu\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue;  // Restart the loop
        }

        switch (choice) {
            case 1:
                search_cars_by_availability(cars, car_count);
                break;
            case 2:
                printf("Enter search term (make/model): ");
                scanf("%s", search_term);
                search_cars_by_type(cars, car_count, search_term);
                break;
            case 3:
                return;  // Return to the main menu
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
