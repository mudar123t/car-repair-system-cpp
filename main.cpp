// main.cpp
#include "car_repair_library.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    CarRepairLibrary carLibrary;
    carLibrary.displayMenu();
    return 0;
}














    //separate function testing



    // CarRepairLibrary carLibrary;

    // // Add a new car
    // carLibrary.addNewCar();

    // // find car by id
    // int targetCarID;
    // cout << "Enter the Car ID to find: ";
    // cin >> targetCarID;
    // Car foundCar = carLibrary.findCarByID(targetCarID);
    // // Check if the car was found
    // if (foundCar.getCarID() != 0) {
    //     cout << "Car Found:\n" << foundCar << endl;
    // } else {
    //     cout << "Car with ID " << targetCarID << " not found." << endl;
    // }

    //find car by license palate
    // string targetLicensePlate;
    // cout << "Enter the License Plate to find: ";
    // cin >> targetLicensePlate;

    // Car foundCarByLicensePlate = carLibrary.findCarByLicensePlate(targetLicensePlate);

    // // Check if the car was found
    // if (foundCarByLicensePlate.getCarID() != 0) {
    //     cout << "Car Found:\n" << foundCarByLicensePlate << endl;
    // } else {
    //     cout << "Car with License Plate " << targetLicensePlate << " not found." << endl;
    // }

    //update car info
    // int targetCarID;
    // cout << "Enter the Car ID to update: ";
    // cin >> targetCarID;

    // carLibrary.updateCarInformation(targetCarID);

    //delete car
    // int targetCarID;
    // cout << "Enter the Car ID to delete: ";
    // cin >> targetCarID;

    // carLibrary.deleteCar(targetCarID);

    // add New Repair-Record
    // int carID = 1;
    // carLibrary.addNewRepairRecord(1);

    // RepairRecord foundRepair;
    // foundRepair = carLibrary.findRepairRecordsForCar(carID);
    // cout << foundRepair << endl;

    // int targetRecordID;
    // cout << "Enter targetRecordID: ";
    // cin >> targetRecordID;

    // carLibrary.updateRepairRecordStatus(targetRecordID);
    // carLibrary.updateRepairRecordDescription(targetRecordID);
    // carLibrary.deleteRepairRecord(targetRecordID);

    // carLibrary.addNewCustomer();
    // cout<<carLibrary.findCustomerByContactNumber("05013530069")<<endl;
    // cout << carLibrary.findCustomerById(1) << endl;
    // carLibrary.updateCustomerInformation(1);
    // carLibrary.deleteCustomer(1);

    // carLibrary.loadDataFromFile();

    // carLibrary.loadDataFromFile();

    // float totalCost = carLibrary.getTotalCostOfCompletedRepairs();
    // cout << "Total Cost of Completed Repairs: $" << totalCost << endl;
