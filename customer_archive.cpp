#include "customer_archive.h"
#include "customer_formatter.h"
#include "customer.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Method to add a new customer
void CustomerArchive::addNewCustomer(const Customer& newCustomer) {
    auto errors = newCustomer.validateCustomerData();
    if (errors.empty()) {
        customers.emplace_back(newCustomer);
        cout << "Customer added successfully." << endl;
    } else {
        cerr <<  "(no customer)";
        for (const auto& error : errors) {
            cerr << error << " ";
        }
        cerr << endl;
    }
}

// Method to get all customers
vector<Customer> CustomerArchive::getAllCustomers() const {
    return customers;
}

// Method to get customer data by ID
optional<Customer> CustomerArchive::getCustomerData(int customerId) const {
    auto it = find_if(customers.begin(), customers.end(),
        [customerId](const Customer& customer) {
            return customer.getId() == customerId;
        });
    return it != customers.end() ? make_optional(*it) : nullopt;
}

// Method to print formatted customer data
void CustomerArchive::printCustomerData(int customerId) const {
    auto customerOpt = getCustomerData(customerId);
    if (customerOpt)
        CustomerFormatter::printCustomerData(*customerOpt);
    else
        cout << "(no customer)" << endl;
}

// Method to print all customers
void CustomerArchive::printAllCustomers() const {
    if (customers.empty()) {
        cout << "(no customer)" << endl; 
        return;
    }
    for (const auto& customer : customers) {
        CustomerFormatter::printCustomerData(customer);
    }
}

