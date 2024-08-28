#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>

#define COLOR_BLUE      1
#define COLOR_GREEN     2
#define COLOR_VIOLET    3
#define COLOR_RED       4
#define COLOR_YELLOW    5
#define COLOR_TURQUOISE 6
#define COLOR_WHITE     7

using namespace std;

// C Struct for customer

extern "C" {
    struct _CUSTOMER {
        int id;
        char first_name[24];
        char last_name[32];
        char zip_code[8];
        char city[32];
        int favorite_color;
    };
    typedef struct _CUSTOMER CUSTOMER;
}

// Class for Customer data
class Customer {
private:
    int id;
    string first_name;
    string last_name;
    string zip_code;
    string city;
    int favorite_color;

public:
    Customer(int id, const string& first_name, const string& last_name, 
             const string& zip_code, const string& city, int favorite_color);

    int getId() const;
    const string& getFirstName() const;
    const string& getLastName() const;
    const string& getZipCode() const;
    const string& getCity() const;
    int getFavoriteColor() const;

    // Convert customer data to C struct
    void toStruct(CUSTOMER* cStruct) const;
    
    // Validate customer data
    vector<string> validateCustomerData() const;
    
    // Get color name from color number
    string getColorName() const;
};

#endif // CUSTOMER_H

