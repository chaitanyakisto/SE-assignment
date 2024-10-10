// search_management.h

#ifndef SEARCH_MANAGEMENT_H
#define SEARCH_MANAGEMENT_H

#include "car.h"

// Function declarations
void search_cars_by_availability(Car cars[], int car_count);
void search_cars_by_type(Car cars[], int car_count, const char *search_term);

#endif
