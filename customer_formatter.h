#ifndef CUSTOMER_FORMATTER_H
#define CUSTOMER_FORMATTER_H

#include <iostream>
#include <string>
#include "customer.h"

using namespace std;

class CustomerFormatter {
public:
    // Formats customer data to a readable string
    static string formatCustomerData(const Customer& customer) {
        return "Name: " + customer.getFirstName() + " " + customer.getLastName() + ", " +
               "Address: " + customer.getZipCode() + " " + customer.getCity() + ", " +
               "Favorite Color: " + customer.getColorName();
    }

    // Prints formatted customer data in a string
    static void printCustomerData(const Customer& customer) {
        cout << formatCustomerData(customer) << endl;
    }
};

#endif // CUSTOMER_FORMATTER_H

