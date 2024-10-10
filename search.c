// search_management.c

#include <stdio.h>
#include <string.h>
#include "search.h"
#include "car.h"

// Function to search for available cars
void search_cars_by_availability(Car cars[], int car_count) {
    int found = 0;
    printf("Available Cars:\n");
    for (int i = 0; i < car_count; i++) {
        if (cars[i].is_available) {
            printf("ID: %d, Model: %s, Make: %s, Year: %d\n", 
                cars[i].id, 
                cars[i].model, 
                cars[i].make, 
                cars[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No available cars.\n");
    }
}

// Function to search cars by make or model
void search_cars_by_type(Car cars[], int car_count, const char *search_term) {
    int found = 0;
    printf("Search Results for '%s':\n", search_term);
    for (int i = 0; i < car_count; i++) {
        if (strstr(cars[i].model, search_term) || strstr(cars[i].make, search_term)) {
            printf("ID: %d, Model: %s, Make: %s, Year: %d\n", 
                cars[i].id, 
                cars[i].model, 
                cars[i].make, 
                cars[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No cars found matching '%s'.\n", search_term);
    }
}
