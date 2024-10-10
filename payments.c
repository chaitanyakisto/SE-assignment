// billing_management.c

#include <stdio.h>
#include "payment.h"
#include "rental.h"
#include "car.h"

// Function to calculate rental fee (with manual input for rental rate)
void calculate_rental_fee(int rental_days, float rental_rate) {
    // Calculate the total rental fee
    float total_fee = rental_days * rental_rate;
    printf("Total rental fee for %d days: $%.2f\n", rental_days, total_fee);
}

// Function to generate a bill
void generate_bill(int rental_days, int rental_id, Rental rentals[], int rental_count) {
    float rental_rate;

    // Prompt user to input rental rate
    printf("Generating bill for Rental ID: %d\n", rental_id);
    printf("Enter rental rate per day: $");
    if (scanf("%f", &rental_rate) != 1) {
        printf("Invalid input! Please enter a number.\n");
        return;  // Exit the function if the input is invalid
    }

    // Calculate the rental fee using the manually entered rental rate
    calculate_rental_fee(rental_days, rental_rate);
}
