
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
private:
    int CustomerID;
    string FirstName;
    string LastName;
    string ContactNumber;
    string Email;
    string Address;

public:
    Customer();
    Customer(int customerID, const string& firstName, const string& lastName, const string& contactNumber, const string& email, const string& address);


    ~Customer();


    int getCustomerID() const;
    string getFirstName() const;
    string getLastName() const;
    string getContactNumber() const;
    string getEmail() const;
    string getAddress() const;

    void setCustomerID(int id);
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setContactNumber(const string& contactNumber);
    void setEmail(const string& email);
    void setAddress(const string& address);
    string toCSVString() const;
    
    friend istream& operator>>(istream& is, Customer& customer);
    friend ostream& operator<<(ostream& os, const Customer& customer);


};

#endif
