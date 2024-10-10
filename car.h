// car_management.h

#ifndef CAR_MANAGEMENT_H
#define CAR_MANAGEMENT_H

#define MAX_CARS 100  // Maximum number of cars in the system

// Structure to represent a car
typedef struct {
    int id;             // Unique ID for each car
    char model[50];     // Car model name
    char make[50];      // Car manufacturer
    int year;           // Year of manufacture
    float rental_rate;  // Rate of the car per day
    int is_available;   // 1 if the car is available, 0 if it's rented
} Car;

// Function declarations
void add_car(Car cars[], int *car_count);
void remove_car(Car cars[], int *car_count, int id);
void update_car(Car cars[], int car_count, int id);
void display_cars(Car cars[], int car_count);

#endif
