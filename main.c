#include <stdio.h>
#include "car.h"
#include "customer.h"
#include "rental.h"
#include "search.h"
#include "file_data.h"
#include "menu.h"

int main() {
    Car cars[MAX_CARS];
    Customer customers[MAX_CUSTOMERS];
    Rental rentals[MAX_RENTALS];

    int car_count = 0;
    int customer_count = 0;
    int next_customer_id = 1;
    int rental_count = 0;
    int id=0;

    // Load data from files (initial data load)
    load_data(cars, &car_count, customers, &customer_count, rentals, &rental_count, &next_customer_id);

    int choice;
    
    while (1) {
        printf("\nWelcome to Peaky Blinders Car Rental\n");
        printf("1. Cars Management\n");
        printf("2. Customers Management\n");
        printf("3. Rental Management\n");
        printf("4. Billing Management\n");
        printf("5. Search System\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();  // Clears invalid input
            continue;  // Restart the loop
        }

        switch (choice) {
            case 1:
                cars_menu(cars, &car_count);
                break;
            case 2:
                customers_menu(customers, &customer_count, &next_customer_id);
                break;
            case 3:
                rental_menu(rentals, &rental_count, cars, car_count, customers, customer_count);
                break;
            case 4:
                printf("Enter rental ID to generate bill: ");
                scanf("%d", &id);
                generate_bill(id, rentals, rental_count, cars, car_count);
                break;
            case 5:
                search_menu(cars, car_count);
                break;
            case 6:
                // Save data and exit
                printf("Saving data...\n");
                save_data(cars, car_count, customers, customer_count, rentals, rental_count);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
