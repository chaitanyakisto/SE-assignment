#include <stdio.h>
#include "car.h"
#include "customer.h"
#include "rental.h"

int main() {
    Car cars[MAX_CARS];
    Customer customers[MAX_CUSTOMERS];
    Rental rentals[MAX_RENTALS];

    int car_count = 0;
    int customer_count = 0;
    int rental_count = 0;

    // Load data from file (initial data load)
    load_data(cars, &car_count, customers, &customer_count, rentals, &rental_count);

    int choice;
    
    while (1) {
        printf("\nCar Rental Management System\n");
        printf("1. Add Car\n");
        printf("2. Delete Car\n");
        printf("3. Update Car\n");
        printf("4. Add Customer\n");
        printf("5. Delete Customer\n");
        printf("6. Update Customer\n");
        printf("7. Add Rental\n");
        printf("8. Generate Bill\n");
        printf("9. Search by Type\n");
        printf("10. Save and Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');  // Clears invalid input
            continue;  // Restart the loop
        }

        switch (choice) {
            case 1:
                // Function to add a car
                add_car(cars, &car_count);
                break;
            case 2:
                // Function to delete a car
                delete_car(cars, &car_count);
                break;
            case 3:
                // Function to update a car
                update_car(cars, car_count);
                break;
            case 4:
                // Function to add a customer
                add_customer(customers, &customer_count);
                break;
            case 5:
                // Function to delete a customer
                delete_customer(customers, &customer_count);
                break;
            case 6:
                // Function to update a customer
                update_customer(customers, customer_count);
                break;
            case 7:
                // Function to add a rental
                add_rental(rentals, &rental_count, cars, car_count, customers, customer_count);
                break;
            case 8:
                // Function to generate a bill
                generate_bill(rentals, rental_count);
                break;
            case 9:
                // Function to search by type
                search_by_type(cars, car_count);
                break;
            case 10:
                // Save data and exit
                printf("Saving data...\n");
                save_data(cars, car_count, customers, customer_count, rentals, rental_count);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
