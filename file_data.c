#include <stdio.h>
#include <string.h>
#include "car.h"
#include "customer.h"
#include "rental.h"
#include "payment.h"

void save_data(Car cars[], int car_count, Customer customers[], int customer_count, Rental rentals[], int rental_count) {
    // Saving Cars to cars.csv
    FILE *car_file = fopen("cars.csv", "w");
    if (car_file == NULL) {
        printf("Error: Unable to open cars.csv for writing.\n");
        return;
    }
    fprintf(car_file, "id,make,model,year,rental_rate,is_available\n");
    for (int i = 0; i < car_count; i++) {
        fprintf(car_file, "%d,%s,%s,%d,%f,%d\n", cars[i].id, cars[i].make, cars[i].model, cars[i].year, cars[i].rental_rate, cars[i].is_available);
    }
    fclose(car_file);
    
    // Saving Customers to customers.csv
    FILE *customer_file = fopen("customers.csv", "w");
    if (customer_file == NULL) {
        printf("Error: Unable to open customers.csv for writing.\n");
        return;
    }
    fprintf(customer_file, "id,name,phone\n");
    for (int i = 0; i < customer_count; i++) {
        fprintf(customer_file, "%d,%s,%s\n", customers[i].id, customers[i].name, customers[i].phone);
    }
    fclose(customer_file);
    
    // Saving Rentals to rentals.csv
    FILE *rental_file = fopen("rentals.csv", "w");
    if (rental_file == NULL) {
        printf("Error: Unable to open rentals.csv for writing.\n");
        return;
    }
    fprintf(rental_file, "rental_id,car_id,customer_id,rental_days\n");
    for (int i = 0; i < rental_count; i++) {
        fprintf(rental_file, "%d,%d,%d,%d\n", rentals[i].rental_id, rentals[i].car_id, rentals[i].customer_id, rentals[i].rental_days);
    }
    fclose(rental_file);
    
    printf("Data successfully saved to CSV files.\n");
}

void load_data(Car cars[], int *car_count, Customer customers[], int *customer_count, Rental rentals[], int *rental_count) {
    char line[256];
    
    // Loading Cars from cars.csv
    FILE *car_file = fopen("cars.csv", "r");
    if (car_file == NULL) {
        printf("Error: Unable to open cars.csv for reading.\n");
        return;
    }
    fgets(line, sizeof(line), car_file);  // Skip the header
    while (fgets(line, sizeof(line), car_file)) {
        sscanf(line, "%d,%[^,],%[^,],%d,%f,%d", &cars[*car_count].id, cars[*car_count].make, cars[*car_count].model, 
               &cars[*car_count].year, &cars[*car_count].rental_rate, &cars[*car_count].is_available);
        (*car_count)++;
    }
    fclose(car_file);
    
    // Loading Customers from customers.csv
    FILE *customer_file = fopen("customers.csv", "r");
    if (customer_file == NULL) {
        printf("Error: Unable to open customers.csv for reading.\n");
        return;
    }
    fgets(line, sizeof(line), customer_file);  // Skip the header
    while (fgets(line, sizeof(line), customer_file)) {
        sscanf(line, "%d,%[^,],%s", &customers[*customer_count].id, customers[*customer_count].name, customers[*customer_count].phone);
        (*customer_count)++;
    }
    fclose(customer_file);
    
    // Loading Rentals from rentals.csv
    FILE *rental_file = fopen("rentals.csv", "r");
    if (rental_file == NULL) {
        printf("Error: Unable to open rentals.csv for reading.\n");
        return;
    }
    fgets(line, sizeof(line), rental_file);  // Skip the header
    while (fgets(line, sizeof(line), rental_file)) {
        sscanf(line, "%d,%d,%d,%d", &rentals[*rental_count].rental_id, &rentals[*rental_count].car_id, &rentals[*rental_count].customer_id, &rentals[*rental_count].rental_days);
        (*rental_count)++;
    }
    fclose(rental_file);
    
    printf("Data successfully loaded from CSV files.\n");
}