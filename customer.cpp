
#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() {CustomerID = 0;}

Customer::Customer(int customerID, const string& firstName, const string& lastName, const string& contactNumber, const string& email, const string& address) {

    CustomerID = customerID;
    FirstName = firstName;
    LastName = lastName;
    ContactNumber = contactNumber;
    Email = email;
    Address = address;
}


Customer::~Customer() {}


int Customer::getCustomerID() const {
    return CustomerID;
}

string Customer::getFirstName() const {
    return FirstName;
}

string Customer::getLastName() const {
    return LastName;
}

string Customer::getContactNumber() const {
    return ContactNumber;
}

string Customer::getEmail() const {
    return Email;
}

string Customer::getAddress() const {
    return Address;
}

void Customer::setCustomerID(int id) {
    CustomerID = id;
}

void Customer::setFirstName(const string& firstName) {
    FirstName = firstName;
}

void Customer::setLastName(const string& lastName) {
    LastName = lastName;
}

void Customer::setContactNumber(const string& contactNumber) {
    ContactNumber = contactNumber;
}

void Customer::setEmail(const string& email) {
    Email = email;
}

void Customer::setAddress(const string& address) {
    Address = address;
}

string Customer::toCSVString() const {
    return to_string(getCustomerID()) + "," + getFirstName() + "," + getLastName() + ","
         + getContactNumber() + "," + getEmail() + "," + getAddress();
}

istream& operator>>(std::istream& is, Customer& customer) {
    char comma;

    is >> customer.CustomerID >> comma;
    getline(is, customer.FirstName, ',');
    getline(is, customer.LastName, ',');
    getline(is, customer.ContactNumber, ',');
    getline(is, customer.Email, ',');
    getline(is, customer.Address);

    return is;
}

ostream& operator<<(ostream& os, const Customer& customer) {
    os << "CustomerID: " << customer.getCustomerID() << ", Name: " << customer.getFirstName() << " " << customer.getLastName()
       << ", Contact Number: " << customer.getContactNumber() << ", Email: " << customer.getEmail() << ", Address: " << customer.getAddress();
    return os;
}