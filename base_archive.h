#ifndef BASE_ARCHIV_H
#define BASE_ARCHIV_H

#include "customer.h"
#include <vector>
#include <optional>

using namespace std;

//Abstract class defining the interface for a customer archive.
class BaseArchiv {
public:
    virtual void addNewCustomer(const Customer& newCustomer) = 0;
    virtual vector<Customer> getAllCustomers() const = 0;
    virtual optional<Customer> getCustomerData(int customerId) const = 0;
    virtual ~BaseArchiv() = default;
};

#endif // BASE_ARCHIV_H

