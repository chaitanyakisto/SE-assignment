// car_management.c

#include <stdio.h>
#include <string.h>
#include "car.h"
#include "menu.h"

// Function to add a new car to the system
void add_car(Car cars[], int *car_count) {
    if (*car_count >= MAX_CARS) {
        printf("Car list is full!\n");
        return;
    }
    
    Car new_car;
    new_car.id = *car_count + 1;  // Assign a unique ID to the car

    printf("Enter car make: ");
    scanf("%s", new_car.make);

    printf("Enter car model: ");
    scanf("%s", new_car.model);

    printf("Enter car year of manufacture: ");
    scanf("%d", &new_car.year);

    printf("Enter rental rate per day: ");
    scanf("%f", &new_car.rental_rate);

    new_car.is_available = 1;  // Initially, the car is available
    
    cars[*car_count] = new_car;
    (*car_count)++;  // Increment the car count
    printf("Car added successfully! Car ID: %d\n", new_car.id);
}

// Function to remove a car by its ID
void remove_car(Car cars[], int *car_count, int id) {
    int found = 0;

    for (int i = 0; i < *car_count; i++) {
        if (cars[i].id == id) {
            found = 1;
            for (int j = i; j < *car_count - 1; j++) {
                cars[j] = cars[j + 1];  // Shift cars left to remove the car
            }
            (*car_count)--;
            printf("Car with ID %d removed successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Car with ID %d not found.\n", id);
    }
}

// Function to update a car's details
void update_car(Car cars[], int car_count, int id) {
    int found = 0;

    for (int i = 0; i < car_count; i++) {
        if (cars[i].id == id) {
            found = 1;
            printf("Updating car with ID %d\n", id);

            printf("Enter new car make: ");
            scanf("%s", cars[i].make);

            printf("Enter new car model: ");
            scanf("%s", cars[i].model);

            printf("Enter new car year of manufacture: ");
            scanf("%d", &cars[i].year);

            printf("Enter new car rental rate: ");
            scanf("%f", &cars[i].rental_rate);

            printf("Is the car available? (1 for yes, 0 for no): ");
            scanf("%d", &cars[i].is_available);

            printf("Car updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Car with ID %d not found.\n", id);
    }
}

// Function to display all cars in the system
void display_cars(Car cars[], int car_count) {
    if (car_count == 0) {
        printf("No cars available.\n");
        return;
    }

    printf("Car List:\n");
    for (int i = 0; i < car_count; i++) {
        printf("ID: %d, Make: %s, Model: %s, Year: %d, Available: %s\n", 
            cars[i].id, 
            cars[i].make, 
            cars[i].model, 
            cars[i].year, 
            cars[i].is_available ? "Yes" : "No");
    }
}
