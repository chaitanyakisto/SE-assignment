// billing_management.c

#include <stdio.h>
#include "payment.h"
#include "rental.h"
#include "car.h"

// Function to calculate rental fee
void calculate_rental_fee(int rental_days, int rental_id, Rental rentals[], int rental_count, Car cars[], int car_count) {
    int car_id = -1;
    float rental_fee_per_day = 0;

    // Find the rental record by rental_id
    for (int i = 0; i < rental_count; i++) {
        if (rentals[i].rental_id == rental_id) {
            car_id = rentals[i].car_id;  // Get the associated car_id
            break;
        }
    }

    if (car_id == -1) {
        printf("Rental ID not found.\n");
        return;
    }

    // Find the car by car_id and get its rental fee
    for (int i = 0; i < car_count; i++) {
        if (cars[i].id == car_id) {
            rental_fee_per_day = cars[i].rental_rate;  // Get the rental fee for the car
            break;
        }
    }

    // Calculate the total rental fee
    float total_fee = rental_days * rental_fee_per_day;
    printf("Total rental fee for %d days: $%.2f\n", rental_days, total_fee);
}


// Function to generate a bill
void generate_bill(int rental_days, int rental_id, Rental rentals[], int rental_count, Car cars[], int car_count) {
    printf("Generating bill for Rental ID: %d\n", rental_id);
    calculate_rental_fee(rental_days, rental_id, rentals, rental_count, cars, car_count);
}