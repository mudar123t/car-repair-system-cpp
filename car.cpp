#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() {}

Car::Car(int carID, const string& model, const string& manufacturer, int year, const string& licensePlate, int currentMileage) {
    CarID = carID;
    Model = model;
    Manufacturer = manufacturer;
    Year = year;
    LicensePlate = licensePlate;
    CurrentMileage = currentMileage;
}

// Car::~Car() {}

int Car::getCarID() const {
    return CarID;
}

string Car::getModel() const {
    return Model;
}

string Car::getManufacturer() const {
    return Manufacturer;
}

int Car::getYear() const {
    return Year;
}

string Car::getLicensePlate() const {
    return LicensePlate;
}

int Car::getCurrentMileage() const {
    return CurrentMileage;
}
void Car::setCarID(int carID) {
    CarID = carID;
}
void Car::setModel(const string& model) {
    Model = model;
}

void Car::setManufacturer(const string& manufacturer) {
    Manufacturer = manufacturer;
}

void Car::setYear(int year) {
    Year = year;
}

void Car::setLicensePlate(const string& licensePlate) {
    LicensePlate = licensePlate;
}

void Car::setCurrentMileage(int currentMileage) {
    CurrentMileage = currentMileage;
}

string Car::toCSVString() const {
    return to_string(getCarID()) + "," + getModel() + "," + getManufacturer() + ","
         + to_string(getYear()) + "," + getLicensePlate() + "," + to_string(getCurrentMileage());
}

    istream& operator>>(std::istream& is, Car& car) {
    char comma;

    is >> car.CarID >> comma;
    getline(is, car.Model, ',');
    getline(is, car.Manufacturer, ',');
    is >> car.Year >> comma;
    getline(is, car.LicensePlate, ',');
    is >> car.CurrentMileage;

    return is;
}


    ostream& operator<<(ostream& os, const Car& car) {
        os << "CarID: " << car.getCarID() << ", Model: " << car.getModel() << ", Manufacturer: " << car.getManufacturer()
        << ", Year: " << car.getYear() << ", License Plate: " << car.getLicensePlate() << ", Mileage: " << car.getCurrentMileage();
        return os;
    }

