// customer_management.h

#ifndef CUSTOMER_MANAGEMENT_H
#define CUSTOMER_MANAGEMENT_H

#define MAX_CUSTOMERS 100  // Maximum number of customers in the system

// Structure to represent a customer
typedef struct {
    int id;             // Unique ID for each customer
    char name[50];      // Customer name
    char phone[15];     // Customer phone number
} Customer;

// Function declarations
void register_customer(Customer customers[], int *customer_count, int *next_customer_id);
void deregister_customer(Customer customers[], int *customer_count, int id);
void update_customer(Customer customers[], int customer_count, int id);
void display_customers(Customer customers[], int customer_count);

#endif
