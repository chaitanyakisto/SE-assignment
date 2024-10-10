#ifndef FILEDATA_H
#define FILEDATA_H

#include "car.h"
#include "customer.h"
#include "rental.h"
#include "payment.h"

void save_data(Car cars[], int car_count, Customer customers[], int customer_count, Rental rentals[], int rental_count);
void load_data(Car cars[], int *car_count, Customer customers[], int *customer_count, Rental rentals[], int *rental_count);

#endif