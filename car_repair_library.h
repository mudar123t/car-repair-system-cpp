#ifndef CAR_REPAIR_LIBRARY_H
#define CAR_REPAIR_LIBRARY_H

#include "Car.h"
#include "RepairRecord.h"
#include "Customer.h"
#include <vector>

using namespace std;

class CarRepairLibrary
{
private:
    vector<Car> cars;                   // A vector to store the Cars
    vector<RepairRecord> repairRecords; // A vector to store the Repair Records
    vector<Customer> customers;         // A vector to store the Customers

public:
    CarRepairLibrary();

    // car funcs declaration
    void addNewCar();
    Car findCarByID(int carID) const;
    Car findCarByLicensePlate(const string &licensePlate) const;
    void updateCarInformation(int targetID);
    void deleteCar(int targetID);

    // repair records funcs declarations
    void addNewRepairRecord(int carID);
    RepairRecord findRepairRecordsForCar(int targetCarID) const;
    void updateRepairRecordStatus(int targetRecordID);
    void updateRepairRecordDescription(int targetRecordID);
    void deleteRepairRecord(int targetRecordID);

    // customer functions declarations
    void addNewCustomer();
    Customer findCustomerByContactNumber(const string &ContactNumber) const;
    Customer findCustomerById(int ID) const;
    void updateCustomerInformation(int targetID);
    void deleteCustomer(int targetID);

    //file operations
    void saveDataToFile() const;
    void loadDataFromFile();
    
    ////summarizing operations
    float getTotalCostOfCompletedRepairs() const;
    float getTotalCostOfAllRepairs() const;
    int getNumberOfCars(const vector<Car>& cars);
    float calculateAverageRepairCost(const vector<RepairRecord>& repairRecords);

    //interface
    void displayMenu();
    void carOperations();
    void repairRecordOperations();
    void customerOperations();
    void summarizingOperations();
    void fileOperations();
};
#endif
