#include "customer.h"
#include <cstring>
#include <iostream>

using namespace std;

Customer::Customer(int id, const string& first_name, const string& last_name, 
                   const string& zip_code, const string& city, int favorite_color)
    : id(id), first_name(first_name), last_name(last_name),
      zip_code(zip_code), city(city), favorite_color(favorite_color) {}

// Methods to get customer data
int Customer::getId() const { return id; }
const string& Customer::getFirstName() const { return first_name; }
const string& Customer::getLastName() const { return last_name; }
const string& Customer::getZipCode() const { return zip_code; }
const string& Customer::getCity() const { return city; }
int Customer::getFavoriteColor() const { return favorite_color; }

// Method to convert customer data to C struct format
void Customer::toStruct(CUSTOMER* cStruct) const {
    cStruct->id = id;
    strncpy(cStruct->first_name, first_name.c_str(), sizeof(cStruct->first_name) - 1);
    cStruct->first_name[sizeof(cStruct->first_name) - 1] = '\0';
    strncpy(cStruct->last_name, last_name.c_str(), sizeof(cStruct->last_name) - 1);
    cStruct->last_name[sizeof(cStruct->last_name) - 1] = '\0';
    strncpy(cStruct->zip_code, zip_code.c_str(), sizeof(cStruct->zip_code) - 1);
    cStruct->zip_code[sizeof(cStruct->zip_code) - 1] = '\0';
    strncpy(cStruct->city, city.c_str(), sizeof(cStruct->city) - 1);
    cStruct->city[sizeof(cStruct->city) - 1] = '\0';
    cStruct->favorite_color = favorite_color;
}

// Method to validate customer data
vector<string> Customer::validateCustomerData() const {
    vector<string> errors;
    if (first_name.empty()) errors.emplace_back("Unknown first name.");
    if (last_name.empty()) errors.emplace_back("Unknown last name.");
    if (zip_code.empty()) errors.emplace_back("Unknown ZIP code.");
    if (city.empty()) errors.emplace_back("Unknown city.");
    if (favorite_color < COLOR_BLUE || favorite_color > COLOR_WHITE) 
        errors.emplace_back("Invalid favorite color.");
    return errors;
}

// Method to return color name by number
string Customer::getColorName() const {
    static const unordered_map<int, string> colorMap = {
        {COLOR_BLUE, "Blue"},
        {COLOR_GREEN, "Green"},
        {COLOR_VIOLET, "Violet"},
        {COLOR_RED, "Red"},
        {COLOR_YELLOW, "Yellow"},
        {COLOR_TURQUOISE, "Turquoise"},
        {COLOR_WHITE, "White"}
    };
    auto itColor = colorMap.find(favorite_color);
    return itColor != colorMap.end() ? itColor->second : "Unknown Color";
}
