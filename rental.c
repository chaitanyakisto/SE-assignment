// rental_management.c

#include <stdio.h>
#include "rental.h"
#include "menu.h"

// Function to book a car
void book_car(Rental rentals[], int *rental_count, Car cars[], int car_count, Customer customers[], int customer_count) {
    if (*rental_count >= MAX_RENTALS) {
        printf("Rental list is full!\n");
        return;
    }

    int car_id, customer_id, rental_days;

    printf("Enter car ID to rent: ");
    scanf("%d", &car_id);
    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter number of rental days: ");
    scanf("%d", &rental_days);

    int car_index = -1, customer_index = -1;
    for (int i = 0; i < car_count; i++) {
        if (cars[i].id == car_id) {
            car_index = i;
            break;
        }
    }
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == customer_id) {
            customer_index = i;
            break;
        }
    }

    if (car_index == -1) {
        printf("Car ID %d not found.\n", car_id);
        return;
    }
    if (customer_index == -1) {
        printf("Customer ID %d not found.\n", customer_id);
        return;
    }
    if (cars[car_index].is_available == 0) {
        printf("Car ID %d is currently not available.\n", car_id);
        return;
    }

    Rental new_rental;
    new_rental.rental_id = *rental_count + 1;
    new_rental.car_id = car_id;
    new_rental.customer_id = customer_id;
    new_rental.rental_days = rental_days;

    rentals[*rental_count] = new_rental;
    (*rental_count)++;
    cars[car_index].is_available = 0;  // Mark car as rented

    printf("Car booked successfully! Rental ID: %d\n", new_rental.rental_id);
}

// Function to return a car
void return_car(Rental rentals[], int *rental_count, Car cars[], int car_count, int rental_id) {
    int found = 0;

    for (int i = 0; i < *rental_count; i++) {
        if (rentals[i].rental_id == rental_id) {
            found = 1;
            for (int j = i; j < *rental_count - 1; j++) {
                rentals[j] = rentals[j + 1];  // Shift rentals left to remove the rental
            }
            (*rental_count)--;

            // Find and mark the car as available
            for (int k = 0; k < car_count; k++) {
                if (cars[k].id == rentals[i].car_id) {
                    cars[k].is_available = 1;
                    break;
                }
            }
            printf("Car with Rental ID %d returned successfully.\n", rental_id);
            break;
        }
    }

    if (!found) {
        printf("Rental ID %d not found.\n", rental_id);
    }
}

// Function to display all rentals
void display_rentals(Rental rentals[], int rental_count) {
    if (rental_count == 0) {
        printf("No active rentals.\n");
        return;
    }

    printf("Rental List:\n");
    for (int i = 0; i < rental_count; i++) {
        printf("Rental ID: %d, Car ID: %d, Customer ID: %d, Rental Days: %d\n", 
            rentals[i].rental_id, 
            rentals[i].car_id, 
            rentals[i].customer_id, 
            rentals[i].rental_days);
    }
}

int search_days(Rental rentals[], int id, int rental_days, int rental_count){
    for (int i = 0; i < rental_count; i++) {
        if (rentals[i].rental_id == id) {
            return rentals[i].rental_days;  // Retrieve the rental days
        }
    }
}
