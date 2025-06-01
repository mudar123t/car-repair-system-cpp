#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {
public:
    int CarID;
    string Model;
    string Manufacturer;
    int Year;
    string LicensePlate;
    int CurrentMileage;

public:

    Car();

    Car(int carID, const string& model, const string& manufacturer, int year, const string& licensePlate, int currentMileage);

    // ~Car();

    int getCarID() const;
    string getModel() const;
    string getManufacturer() const;
    int getYear() const;
    string getLicensePlate() const;
    int getCurrentMileage() const;

    void setCarID(int carID);
    void setModel(const string& model);
    void setManufacturer(const string& manufacturer);
    void setYear(int year);
    void setLicensePlate(const string& licensePlate);
    void setCurrentMileage(int currentMileage);
    string toCSVString() const;
    
    friend istream& operator>>(istream& is, Car& car);
    friend ostream& operator<<(ostream& os, const Car& car);

};

#endif 
