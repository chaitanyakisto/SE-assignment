// rental_management.h

#ifndef RENTALMANAGEMENT_H
#define RENTALMANAGEMENT_H

#include "car.h"
#include "customer.h"

#define MAX_RENTALS 100  // Maximum number of rentals in the system

// Structure to represent a rental
typedef struct {
    int rental_id;       // Unique rental ID
    int car_id;          // Car ID that is rented
    int customer_id;     // Customer ID who rented the car
    int rental_days;     // Number of days the car is rented
} Rental;

// Function declarations
void book_car(Rental rentals[], int *rental_count, Car cars[], int car_count, Customer customers[], int customer_count);
void return_car(Rental rentals[], int *rental_count, Car cars[], int car_count, int rental_id);
void display_rentals(Rental rentals[], int rental_count);
int search_days(Rental rentals[], int id, int rental_days, int rental_count);

#endif