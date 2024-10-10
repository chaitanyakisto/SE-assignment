#ifndef MENU_H
#define MENU_H

#include "car.h"
#include "customer.h"
#include "rental.h"
#include "search.h"

void clear_input_buffer();
void customers_menu(Customer customers[], int *customer_count, int *next_customer_id);
void cars_menu(Car cars[], int *car_count);
void rental_menu(Rental rentals[], int *rental_count, Car cars[], int car_count, Customer customers[], int customer_count);
void search_menu(Car cars[], int car_count);

#endif