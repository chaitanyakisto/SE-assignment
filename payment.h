// billing_management.h

#ifndef BILLING_MANAGEMENT_H
#define BILLING_MANAGEMENT_H

#include "rental.h"
#include "car.h"

// Function declarations
void calculate_rental_fee(int rental_days, int rental_id, Rental rentals[], int rental_count, Car cars[], int car_count);
void generate_bill(int rental_days, int rental_id, Rental rentals[], int rental_count, Car cars[], int car_count);

#endif
