#include <iostream>
#include <vector>
#include <optional>
#include <string>
#include <stdexcept>
#include <cstring>
#include "customer.h"
#include "base_archive.h"
#include "customer_formatter.h"
#include "customer_archive.h"

using namespace std;

extern "C" {
    struct MockCustomerStruct {
        int id;
        char first_name[50];
        char last_name[50];
        char zip_code[10];
        char city[50];
        int favorite_color;
    };
}

// Mock class for CustomerArchive
class MockCustomerArchive : public CustomerArchive {
private:
    vector<Customer> mockedCustomers;

public:
    MockCustomerArchive() {
        mockedCustomers.emplace_back(1, "Hans", "Müller", "677742", "Lauterecken", COLOR_RED);
    }
    // get customer data
    optional<Customer> getCustomerData(int customerId) const override {
        auto customerIter = find_if(mockedCustomers.begin(), mockedCustomers.end(),
                               [customerId](const Customer& customer) {
                                   return customer.getId() == customerId;
                               });
        return customerIter != mockedCustomers.end() ? make_optional(*customerIter) : nullopt;
    }
};

// check if toStruct convert sucsessfull
void checkCustomerStruct(const CUSTOMER& cStruct, const Customer& customer, const string& testName) {
    if (cStruct.id != customer.getId()) {
        throw runtime_error("Error in " + testName + ": Expected ID: " + to_string(customer.getId()) + ", Got: " + to_string(cStruct.id));
    }
    if (strcmp(cStruct.first_name, customer.getFirstName().c_str()) != 0) {
        throw runtime_error("Error in " + testName + ": Expected First Name: " + customer.getFirstName() + ", Got: " + cStruct.first_name);
    }
    if (strcmp(cStruct.last_name, customer.getLastName().c_str()) != 0) {
        throw runtime_error("Error in " + testName + ": Expected Last Name: " + customer.getLastName() + ", Got: " + cStruct.last_name);
    }
    if (strcmp(cStruct.zip_code, customer.getZipCode().c_str()) != 0) {
        throw runtime_error("Error in " + testName + ": Expected ZIP Code: " + customer.getZipCode() + ", Got: " + cStruct.zip_code);
    }
    if (strcmp(cStruct.city, customer.getCity().c_str()) != 0) {
        throw runtime_error("Error in " + testName + ": Expected City: " + customer.getCity() + ", Got: " + cStruct.city);
    }
    if (cStruct.favorite_color != customer.getFavoriteColor()) {
        throw runtime_error("Error in " + testName + ": Expected Favorite Color: " + to_string(customer.getFavoriteColor()) + ", Got: " + to_string(cStruct.favorite_color));
    }
    cout << testName << " passed!" << endl;
}

// Testfunktion für toCStruct
void testConvertToStruct() {
    Customer classCustomer(1, "Hans", "Müller", "677742", "Lauterecken", COLOR_RED);
    CUSTOMER structCustomer;
    classCustomer.toStruct(&structCustomer);
    // check field of the struct
    checkCustomerStruct(structCustomer, classCustomer, "testToStruct");
}

// Testfunktion für Getter
void testGetter(const string& expected, const string& got, const string& testName) {
    if (expected != got)
        throw runtime_error("Error in " + testName + ": Expected: " + expected + ", Got: " + got);
    else
        cout << testName << " passed!" << endl;
}

// Überprüfen, ob ein Optional einen Wert enthält und eine Ausnahme werfen, wenn nicht
void testOptionalHasValue(const optional<Customer>& opt, const string& testName) {
    if (!opt.has_value())
        throw runtime_error("Error in " + testName + ": Expected customer not found!");
}

// Unit-Tests ausführen
void unitTest() {
    try {
        MockCustomerArchive mockArchive;

        // Test: Customer is found
        auto customerHans = mockArchive.getCustomerData(1);
        testOptionalHasValue(customerHans, "getCustomerData(1)");

        // Test getter methods
        testGetter(to_string(1), to_string(customerHans->getId()), "getId()");
        testGetter("Hans", customerHans->getFirstName(), "getFirstName()");
        testGetter("Müller", customerHans->getLastName(), "getLastName()");
        testGetter("677742", customerHans->getZipCode(), "getZipCode()");
        testGetter("Lauterecken", customerHans->getCity(), "getCity()");
        testGetter("Red", customerHans->getColorName(), "getColor()");

        // Test formatter
        string formatted = CustomerFormatter::formatCustomerData(customerHans.value());
        testGetter("Name: Hans Müller, Address: 677742 Lauterecken, Favorite Color: Red", formatted, "formatCustomerData()");

        // Test: Customer not found
        customerHans = mockArchive.getCustomerData(999);
        cout << "Check handling with invalid ID (print no customer): ";
        if (!customerHans.has_value()) {
            formatted = "(no customer)";
        }
        testGetter("(no customer)", formatted, "getCustomerData() ");

        // Test if convert data to c struct
        testConvertToStruct();
    }
    catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
    }
}

// Main function to run tests
int main() {
    unitTest();
    cout << "All tests completed!" << endl;
    return 0;
}
