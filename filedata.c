#include <stdio.h>
#include <string.h>
#include "car.h"
#include "customer.h"
#include "rental.h"

void save_data(Car cars[], int car_count, Customer customers[], int customer_count, Rental rentals[], int rental_count) {
    // Saving all data to a single data.txt file
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open data.txt for writing.\n");
        return;
    }

    // Saving Cars
    fprintf(file, "CARS\n");
    for (int i = 0; i < car_count; i++) {
        fprintf(file, "%d %s %s %d %f %d\n", cars[i].id, cars[i].make, cars[i].model, cars[i].year, cars[i].rental_rate, cars[i].is_available);
    }

    // Saving Customers
    fprintf(file, "CUSTOMERS\n");
    for (int i = 0; i < customer_count; i++) {
        fprintf(file, "%d %s %s\n", customers[i].id, customers[i].name, customers[i].phone);
    }

    // Saving Rentals
    fprintf(file, "RENTALS\n");
    for (int i = 0; i < rental_count; i++) {
        fprintf(file, "%d %d %d %d\n", rentals[i].rental_id, rentals[i].car_id, rentals[i].customer_id, rentals[i].rental_days);
    }

    fclose(file);
    printf("Data successfully saved to data.txt.\n");
}

void load_data(Car cars[], int *car_count, Customer customers[], int *customer_count, Rental rentals[], int *rental_count) {
    char line[256];
    
    // Loading all data from a single data.txt file
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open data.txt for reading.\n");
        return;
    }

    // Loading Cars
    fgets(line, sizeof(line), file); // Read "CARS"
    while (fgets(line, sizeof(line), file) && strncmp(line, "CUSTOMERS", 9) != 0) {
        sscanf(line, "%d %s %s %d %f %d", &cars[*car_count].id, cars[*car_count].make, cars[*car_count].model, 
               &cars[*car_count].year, &cars[*car_count].rental_rate, &cars[*car_count].is_available);
        (*car_count)++;
    }

    // Loading Customers
    while (fgets(line, sizeof(line), file) && strncmp(line, "RENTALS", 7) != 0) {
        sscanf(line, "%d %s %s", &customers[*customer_count].id, customers[*customer_count].name, customers[*customer_count].phone);
        (*customer_count)++;
    }

    // Loading Rentals
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %d %d %d", &rentals[*rental_count].rental_id, &rentals[*rental_count].car_id, &rentals[*rental_count].customer_id, &rentals[*rental_count].rental_days);
        (*rental_count)++;
    }

    fclose(file);
    printf("Data successfully loaded from data.txt.\n");
}
