// customer_management.c

#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "menu.h"

// Function to register a new customer
void register_customer(Customer customers[], int *customer_count, int *next_customer_id) {
    if (*customer_count >= MAX_CUSTOMERS) {
        printf("Customer list is full!\n");
        return;
    }
    
    Customer new_customer;
    new_customer.id = *next_customer_id;  // Assign a unique ID to the customer

    printf("Enter customer name: ");
    getchar();  // Consume the leftover newline character from previous input
    fgets(new_customer.name, sizeof(new_customer.name), stdin);

     // Remove the newline character at the end of the name (if present)
    size_t len = strlen(new_customer.name);
    if (len > 0 && new_customer.name[len - 1] == '\n') {
        new_customer.name[len - 1] = '\0';
    }

    printf("Enter customer phone number: ");
    scanf("%s", new_customer.phone);
    
    customers[*customer_count] = new_customer;
    (*customer_count)++;
    (*next_customer_id)++;  // Increment the next available ID
    printf("Customer registered successfully! Customer ID: %d\n", new_customer.id);
}


// Function to deregister a customer by their ID
void deregister_customer(Customer customers[], int *customer_count, int id) {
    int found = 0;

    for (int i = 0; i < *customer_count; i++) {
        if (customers[i].id == id) {
            found = 1;
            for (int j = i; j < *customer_count - 1; j++) {
                customers[j] = customers[j + 1];  // Shift customers left to remove the customer
            }
            (*customer_count)--;
            printf("Customer with ID %d deregistered successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Customer with ID %d not found.\n", id);
    }
}

// Function to update a customer's details
void update_customer(Customer customers[], int customer_count, int id) {
    int found = 0;

    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == id) {
            found = 1;
            printf("Updating customer with ID %d\n", id);

            printf("Enter new customer name: ");
            scanf("%s", customers[i].name);

            printf("Enter new customer phone number: ");
            scanf("%s", customers[i].phone);

            printf("Customer updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Customer with ID %d not found.\n", id);
    }
}

// Function to display all customers
void display_customers(Customer customers[], int customer_count) {
    if (customer_count == 0) {
        printf("No customers registered.\n");
        return;
    }

    printf("Customer List:\n");
    for (int i = 0; i < customer_count; i++) {
        printf("ID: %d, Name: %s, Phone: %s\n", 
            customers[i].id, 
            customers[i].name, 
            customers[i].phone);
    }
}
