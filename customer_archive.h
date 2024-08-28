#ifndef CUSTOMER_ARCHIVE_H
#define CUSTOMER_ARCHIVE_H

#include "customer.h"
#include "base_archive.h"
#include <vector>
#include <optional>

using namespace std;


class CustomerArchive : public BaseArchiv {
private:
    vector<Customer> customers;

public:
    void addNewCustomer(const Customer& newCustomer);
    vector<Customer> getAllCustomers() const;
    optional<Customer> getCustomerData(int customerId) const;
    void printCustomerData(int customerId) const;
    void printAllCustomers() const;
};

#endif // CUSTOMER_ARCHIVE_H

