# C++ Developer Test

This project involves refactoring the `customer.h` header to modern C++ while maintaining backward compatibility with existing programs, and developing a library for managing customer data. Due to time constraints, task 3 (the console application) and the integration test were not completed. I would be happy to discuss these tasks further during the interview. The system is implemented in modern C++17. To compile the project, run the following command:
```bash
g++ -std=c++17 -Wall -Wextra -o unit_test customer.cpp customer_archive.cpp unit_test.cpp
```

## Available Files

To realize this project, the following files have been implemented:

## Files and Their Functions

### customer.h
- Contains a C data structure `CUSTOMER` that represents customer data, along with a modern C++ class that encapsulates, validates, and converts the data.

### customer.cpp
- Implements the methods of the `Customer` class.

### customer_formatter.h
- Defines the `CustomerFormatter` class, which provides methods to format and output customer data in the required text format.

### customer_archive.h
- Defines the `CustomerArchive` class, which serves as an archive and provides methods for managing the customer archive.

### customer_archive.cpp
- Implements the methods of the `CustomerArchive` class.

### base_archive.h
- Defines the abstract `BaseArchiv` class, which provides an interface for a customer archive and specifies the basic methods for managing a customer archive.

### test_main.cpp
- Implements unit tests to verify the entire project. It checks the functionality of the `Customer` and `CustomerArchive` classes as well as the formatting of customer data to ensure that all methods work as expected. Additionally, it tests the getter methods, handles invalid customer IDs, and verifies the correct conversion and output of customer data in C and C++ formats.

### unit_test.cpp
- Implements unit tests to verify the `Customer` and `CustomerArchive` classes, including the conversion of customer data to C structures, the functionality of getter methods, data formatting, and the handling of invalid customer IDs.

