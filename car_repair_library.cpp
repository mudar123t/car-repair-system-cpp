#include "car_repair_library.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

CarRepairLibrary::CarRepairLibrary()
{
    loadDataFromFile();
}

//car funcs implementation
void CarRepairLibrary::addNewCar() {
    if (cars.size() >= 100) {
        cout << "Error: Maximum number of cars reached." << endl;
        return;
    }
    Car newCar;
    cout << "Enter Car Details:" << endl;
    newCar.setCarID(cars.size() + 1);
    cout << "Car Model: ";
    cin >> newCar.Model;

    cout << "Manufacturer: ";
    cin >> newCar.Manufacturer;

    cout << "Year: ";
    int year;
    cin >> year;
    cin.ignore();
    newCar.setYear(year);
    while (true) {
        cout << "License Plate: ";
        string licensePlate;
        getline(cin, licensePlate);
        Car foundCar = findCarByLicensePlate(licensePlate);
        if (foundCar.getLicensePlate() == licensePlate) {
            cout << "License plate already exists. Please enter a different one." << endl;
        } else {
            newCar.setLicensePlate(licensePlate);
            break;
        }
    }
    cout << "Current Mileage: ";
    int currentMileage;
    cin >> currentMileage;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    newCar.setCurrentMileage(currentMileage);
    cars.push_back(newCar);
    saveDataToFile();
    cout << "Car added successfully!" << endl;
}

Car CarRepairLibrary::findCarByID(int carID) const {
    for (const Car& car : cars) {
        if (car.getCarID() == carID) {
            return car;
        }
    }

    return Car{};
}

Car CarRepairLibrary::findCarByLicensePlate(const string& licensePlate) const {
    for (const auto& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            return car;
        }
    }

    return Car{}; 
}

void CarRepairLibrary::updateCarInformation(int targetID) {
    for (auto& car : cars) {
        if (car.getCarID() == targetID) {
            cout << "Enter updated information for Car ID " << targetID << ":" << endl;

            cout << "Car Model: ";
            string model;
            cin.ignore();
            getline(cin, model);
            car.setModel(model);

            cout << "Manufacturer: ";
            string manufacturer;
            getline(cin, manufacturer);
            car.setManufacturer(manufacturer);

            cout << "Year: ";
            int year;
            cin >> year;
            car.setYear(year);

            cout << "License Plate: ";
            cin.ignore();
            string licensePlate;
            getline(cin, licensePlate);
            car.setLicensePlate(licensePlate);

            cout << "Current Mileage: ";
            int currentMileage;
            cin >> currentMileage;
            car.setCurrentMileage(currentMileage);

            saveDataToFile();
            cout << "Car information updated successfully!" << endl;
            return;
        }
    }

    cout << "Car with ID " << targetID << " not found." << endl;
}

void CarRepairLibrary::deleteCar(int targetID) {
    for (auto& car : cars) {
        if (car.getCarID() == targetID) {
            cars.pop_back();
        saveDataToFile();
        cout << "Car with ID " << targetID << " deleted successfully!" << endl;
        } else {
            cout << "Car with ID " << targetID << " not found." << endl;
        }
    }
}

//repair records funcs implementation
void CarRepairLibrary::addNewRepairRecord(int carID) {
    if (repairRecords.size() >= 100) {
        cout << "Error: Maximum number of repair records reached." << endl;
        return;
    }

    RepairRecord newRecord;
    newRecord.setRecordID(repairRecords.size() + 1);
    Car car2 = findCarByID(carID);
    newRecord.setCarID(carID);

    cout << "Enter Repair Record Details:" << endl;

    string date;
    cout << "Date: ";
    cin >> date;
    newRecord.setDate(date);

    string Technician;
    cout << "TechnicianName: ";
    cin >> Technician;
    newRecord.setTechnician(Technician);
    cin.ignore();

    string Description;
    cout << "Description: ";
    getline(cin, Description);
    newRecord.setDescription(Description);

    float cost;
    cout << "Cost: ";
    cin >> cost; newRecord.setCost(cost);
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int statusChoice;
    cout << "Choose Repair Status (0: PENDING, 1: IN_PROGRESS, 2: COMPLETED): ";
    cin >> statusChoice;
    cin.clear();

    if (statusChoice >= 0 && statusChoice <= 2) {
    newRecord.setStatus(static_cast<RepairStatus>(statusChoice));
        repairRecords.push_back(newRecord);
        cout << "Repair Record added successfully!" << endl;
        saveDataToFile();
    } else {
        cout << "Invalid status choice. Repair Record not added." << endl;
    }
}

RepairRecord CarRepairLibrary::findRepairRecordsForCar(int targetCarID) const {
    for (const auto& record : repairRecords) {
        if (record.getCarID() == targetCarID) {
                return record;
            }
    }

    return RepairRecord{};
}

void CarRepairLibrary::updateRepairRecordStatus(int targetRecordID) {
    for (auto& record : repairRecords) {
        if (record.getRecordID() == targetRecordID) {
            cout << "Enter updated status for Repair Record ID " << targetRecordID << ":\n";
            cout << "Choose Repair Status (0: PENDING, 1: IN_PROGRESS, 2: COMPLETED): ";

            int statusChoice;
            cin >> statusChoice;

            if (statusChoice >= 0 && statusChoice <= 2) {
                record.setStatus(static_cast<RepairStatus>(statusChoice));
                saveDataToFile(); // Save the updated data to file
                cout << "Repair Record status updated successfully!\n";
            } else {
                cout << "Invalid status choice. Repair Record status not updated.\n";
            }

            return;
        }
    }

    cout << "Repair Record with ID " << targetRecordID << " not found.\n";
}

void CarRepairLibrary::updateRepairRecordDescription(int targetRecordID) {
    for (auto& record : repairRecords) {
        if (record.getRecordID() == targetRecordID) {
            cout << "Enter the updated description for Repair Record ID " << targetRecordID << ": ";
            string newDescription;
            cin.ignore();
            getline(cin, newDescription);
            record.setDescription(newDescription);
            saveDataToFile(); 
            cout << "Repair Record description updated successfully!" << endl;
            return;
        }
    }

    cout << "Repair Record with ID " << targetRecordID << " not found.\n";
}

void CarRepairLibrary::deleteRepairRecord(int targetRecordID) {
    for (auto& record : repairRecords) {
        if (record.getCarID() == targetRecordID) {
            repairRecords.pop_back();
        saveDataToFile();
        cout << "record with ID " << targetRecordID << " deleted successfully!" << endl;
        } else {
            cout << "record with ID " << targetRecordID << " not found." << endl;
        }
    }
}

//customer functions implementation
void CarRepairLibrary::addNewCustomer() {
    if (customers.size() >= 100) {
        cout << "Error: Maximum number of customers reached." << endl;
        return;
    }

    Customer newCustomer;
    newCustomer.setCustomerID(customers.size() + 1);

    cout << "Enter Customer Details:" << endl;
    cout << "First Name:";
    string firstName;
    cin>> firstName;
    newCustomer.setFirstName(firstName);

    cout << "Last Name: ";
    string lastName;
    cin.ignore();
    getline(cin, lastName);
    newCustomer.setLastName(lastName);

    cout << "Phone Number: ";
    string phoneNumber;
    getline(cin, phoneNumber);
    newCustomer.setContactNumber(phoneNumber);

    cout << "Email: ";
    string email;
    getline(cin, email);
    newCustomer.setEmail(email);

    cout << "Address: ";
    string address;
    getline(cin, address);
    newCustomer.setAddress(address);

    customers.push_back(newCustomer);
    saveDataToFile(); 
    cout << "Customer added successfully!" << endl;
}

Customer CarRepairLibrary::findCustomerByContactNumber(const string& ContactNumber) const {
    for (const auto& customer : customers) {
        if (customer.getContactNumber() == ContactNumber) {
            return customer;
        }
    }

    return Customer{}; 
}

Customer CarRepairLibrary::findCustomerById(int ID) const {
    for (const Customer& customer : customers) {
        if (customer.getCustomerID() == ID) {
            return customer;
        }
    }

    return Customer{};
}

void CarRepairLibrary::updateCustomerInformation(int targetID) {
    for (auto& customer : customers) {
        if (customer.getCustomerID() == targetID) {
            cout << "Enter updated information for Customer ID " << targetID << ":\n";

            cout << "Enter Customer Details:" << endl;
            cout << "First Name: ";
            string firstName;
            cin >> firstName;
            customer.setFirstName(firstName);

            cout << "Last Name: ";
            string lastName;
            cin.ignore();
            getline(cin, lastName);
            customer.setLastName(lastName);

            cout << "Phone Number: ";
            string phoneNumber;
            getline(cin, phoneNumber);
            customer.setContactNumber(phoneNumber);

            cout << "Email: ";
            string email;
            getline(cin, email);
            customer.setEmail(email);

            cout << "Address: ";
            string address;
            getline(cin, address);
            customer.setAddress(address);
            cout << "Customer information updated successfully!\n";
            saveDataToFile();
            return;
        }
    }

    cout << "Customer with ID " << targetID << " not found.\n";
}

void CarRepairLibrary::deleteCustomer(int targetID) {
    for (auto& customer : customers) {
        if (customer.getCustomerID() == targetID) {
            customers.pop_back();
        saveDataToFile();
        cout << "customer with ID " << targetID << " deleted successfully!" << endl;
        } else {
            cout << "customer with ID " << targetID << " not found." << endl;
        }
    }
}


//file operations
void CarRepairLibrary::saveDataToFile() const {
    // Save Cars
    ofstream carFile("cars.txt");
    if (!carFile.is_open()) {
        cout << "Error opening file for writing: cars.txt" << endl;
        return;
    }

    for (const auto& car : cars) {
        carFile << car.toCSVString() << endl;
    }

    carFile.close();

    //, ios::app
    // Save Repair Records
    ofstream repairFile("repair_records.txt");
    if (!repairFile.is_open()) {
        cout << "Error opening file for writing: repair_records.txt" << endl;
        return;
    }

    for (const auto& record : repairRecords) {
        repairFile << record.toCSVString() << endl;
    }

    repairFile.close();

    // Save Customers
    ofstream customerFile("customers.txt");
    if (!customerFile.is_open()) {
        cout << "Error opening file for writing: customers.txt" << endl;
        return;
    }

    for (const auto& customer : customers) {
        customerFile << customer.toCSVString() << endl;
    }

    customerFile.close();

    cout << "Data saved to files successfully." << endl;
}

void CarRepairLibrary::loadDataFromFile() {
    // Load Cars
    ifstream carFile("cars.txt");
    if (!carFile.is_open()) {
        cout << "Error opening file for reading: cars.txt\n";
        return;
    }

    cars.clear();
    Car car;
    while (carFile >> car) {
        cars.push_back(car);
        // cout << "Loaded Car: " << car << endl;
    }

    carFile.close();

    // Load Repair Records
    ifstream repairFile("repair_records.txt");
    if (!repairFile.is_open()) {
        cout << "Error opening file for reading: repair_records.txt\n";
        return;
    }

    repairRecords.clear(); // Clear existing repair records
    RepairRecord record;
    while (repairFile >> record) {
        repairRecords.push_back(record);
        // cout << "Loaded Repair Record: " << record << endl;
    }

    repairFile.close();

    // Load Customers
    ifstream customerFile("customers.txt");
    if (!customerFile.is_open()) {
        cout << "Error opening file for reading: customers.txt\n";
        return;
    }

    customers.clear(); // Clear existing customers
    Customer customer;
    while (customerFile >> customer) {
        customers.push_back(customer);
        // cout << "Loaded Customer: " << customer << endl;
    }

    customerFile.close();
    cout << "Data loaded successfully and stored." << endl;
}


//summarizing operations
float CarRepairLibrary::getTotalCostOfCompletedRepairs() const {
    float totalCost = 0.0;

    for (const auto& record : repairRecords) {
        if (record.getStatus() == RepairStatus::COMPLETED) {
            totalCost += record.getCost();
        }
    }

    return totalCost;
}

float CarRepairLibrary::getTotalCostOfAllRepairs() const {
    float totalCost = 0.0;

    for (const auto& record : repairRecords) {
        totalCost += record.getCost();
    }

    return totalCost;
}

int CarRepairLibrary::getNumberOfCars(const vector<Car>& cars) {
    return cars.size();
}

float CarRepairLibrary::calculateAverageRepairCost(const vector<RepairRecord>& repairRecords) {
    if (repairRecords.empty()) {
        return 0.0f;
    }

    float totalCost = 0.0f;

    for (const auto& record : repairRecords) {
        totalCost += record.getCost();
    }

    return totalCost / repairRecords.size();
}

//interface
void CarRepairLibrary::displayMenu() {
    int choice;

    do {
        cout << "\n==== Main Menu ====\n";
        cout << "1. Car Operations\n";
        cout << "2. Repair Record Operations\n";
        cout << "3. Customer Operations\n";
        cout << "4. Summarizing Operations\n";
        cout << "5. File Operations\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                carOperations();
                break;
            case 2:
                repairRecordOperations();
                break;
            case 3:
                customerOperations();
                break;
            case 4:
                summarizingOperations();
                break;
            case 5:
                fileOperations();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 6);
}

void CarRepairLibrary::carOperations() {
    int carChoice;

    do {
        cout << "\n==== Car Operations ====\n";
        cout << "1. Add a new car\n";
        cout << "2. Find a car by ID\n";
        cout << "3. Find a car by License Plate\n";
        cout << "4. Update car information\n";
        cout << "5. Delete a car\n";
        cout << "6. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> carChoice;

        switch (carChoice) {
            case 1:
                addNewCar();  
                break;
            case 2: {
                int targetID;
                cout << "Enter Car ID to search: ";
                cin >> targetID;
                Car foundCar = findCarByID(targetID);
                if (foundCar.getCarID() != 0) {
                    cout << "Car Found:\n" << foundCar << endl;
                } else {
                    cout << "Car with ID " << targetID << " not found." << endl;
                }
                break;
            }
            case 3: {
                string targetLicensePlate;
                cout << "Enter License Plate to search: ";
                cin >> targetLicensePlate;
                Car foundCar = findCarByLicensePlate(targetLicensePlate);
                if (foundCar.getCarID() != 0) {
                    cout << "Car Found:\n" << foundCar << endl;
                } else {
                    cout << "Car with LicensePlate " << targetLicensePlate << " not found." << endl;
                }
                break;
            }
            case 4: {
                int targetID;
                cout << "Enter Car ID to update: ";
                cin >> targetID;
                updateCarInformation(targetID);
                break;
            }
            case 5: {
                int targetID;
                cout << "Enter Car ID to delete: ";
                cin >> targetID;
                deleteCar(targetID);
                break;
            }
            case 6:
                cout << "Returning to the main menu.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (carChoice != 6);
}

void CarRepairLibrary::repairRecordOperations() {
    int repairRecordChoice;

    do {
        cout << "\n==== Repair Record Operations ====\n";
        cout << "1. Add a new repair record\n";
        cout << "2. Find repair records for a car\n";
        cout << "3. Update repair record status\n";
        cout << "4. Update repair record description\n";
        cout << "5. Delete a repair record\n";
        cout << "6. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> repairRecordChoice;

        switch (repairRecordChoice) {
            case 1: {
                while (true) {
                    int carID;
                    cout << "Enter Car ID for the repair record: ";
                    cin >> carID;
                    Car car2 = findCarByID(carID);
                    if(car2.getCarID() != 0){
                        addNewRepairRecord(carID);  
                        break;
                    }else{
                        cout << "car id that you have Entered doesn't exist please add the car firs"<<endl;
                    }
                }break;
            }
            case 2: {
                int targetCarID;
                cout << "Enter Car ID to find repair records: ";
                cin >> targetCarID;
                RepairRecord foundRecord = findRepairRecordsForCar(targetCarID); 
                if (foundRecord.getRecordID() != 0){
                    cout << "Found Repair Record: " << foundRecord << endl;
                    break;
                }else {
                    cout << "Car with ID " << targetCarID << " has no repair record!" << endl;
                }
                break;
            }
            case 3: {
                int targetRecordID;
                cout << "Enter Repair Record ID to update status: ";
                cin >> targetRecordID;
                RepairRecord foundRecord = findRepairRecordsForCar(targetRecordID); 
                if (foundRecord.getRecordID() != 0){
                    updateRepairRecordStatus(targetRecordID);  
                    break;
                }else {
                    cout << "repair record with ID " << targetRecordID << " not found!" << endl;
                }
                break;
            }
            case 4: {
                int targetRecordID;
                cout << "Enter Repair Record ID to update status: ";
                cin >> targetRecordID;
                RepairRecord foundRecord = findRepairRecordsForCar(targetRecordID); 
                if (foundRecord.getRecordID() != 0){
                    updateRepairRecordDescription(targetRecordID);   
                    break;
                }else {
                    cout << "repair record with ID " << targetRecordID << " not found!" << endl;
                }
                break;
            }
            case 5: {
                int targetRecordID;
                cout << "Enter Repair Record ID to update status: ";
                cin >> targetRecordID;
                RepairRecord foundRecord = findRepairRecordsForCar(targetRecordID); 
                if (foundRecord.getRecordID() != 0){
                    deleteRepairRecord(targetRecordID);  
                    break;
                }else {
                    cout << "repair record with ID " << targetRecordID << " not found!" << endl;
                }
                break;
            }
            case 6:
                cout << "Returning to the main menu.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (repairRecordChoice != 6);
}

void CarRepairLibrary::customerOperations() {
    int customerChoice;

    do {
        cout << "\n==== Customer Operations ====\n";
        cout << "1. Add a new customer\n";
        cout << "2. Find a customer by contact number\n";
        cout << "3. Find a customer by ID\n";
        cout << "4. Update customer information\n";
        cout << "5. Delete a customer\n";
        cout << "6. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> customerChoice;

        switch (customerChoice) {
            case 1: {
                addNewCustomer();  
                break;
            }
            case 2: {
                string targetContactNumber;
                cout << "Enter Contact Number to search: ";
                cin >> targetContactNumber;
                Customer foundCustomer = findCustomerByContactNumber(targetContactNumber);  
                if (foundCustomer.getCustomerID() != 0){
                    cout << "Found Customer: " << foundCustomer << endl;
                    break;
                }else {
                    cout << "Customer with ContactNumber " << targetContactNumber << " not found!" << endl;
                }
                break;
            }
            case 3: {
                int targetID;
                cout << "Enter Customer ID to search: ";
                cin >> targetID;
                Customer foundCustomer = findCustomerById(targetID);
                if (foundCustomer.getCustomerID() != 0){
                    cout << "Found Customer: " << foundCustomer << endl;
                    break;
                }else {
                    cout << "Customer with ID " << targetID << " not found!" << endl;
                }
                break;
            }
            case 4: {
                int targetID;
                cout << "Enter Customer ID to search: ";
                cin >> targetID;
                Customer foundCustomer = findCustomerById(targetID);
                if (foundCustomer.getCustomerID() != 0){
                    updateCustomerInformation(targetID);  
                    break;
                }else {
                    cout << "Customer with ID " << targetID << " not found!" << endl;
                }
                break;
            }
            case 5: {
                int targetID;
                cout << "Enter Customer ID to search: ";
                cin >> targetID;
                Customer foundCustomer = findCustomerById(targetID);
                if (foundCustomer.getCustomerID() != 0){
                    deleteCustomer(targetID);  
                    break;
                }else {
                    cout << "Customer with ID " << targetID << " not found!" << endl;
                }
                break;
            }
            case 6:
                cout << "Returning to the main menu.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (customerChoice != 6);
}

void CarRepairLibrary::summarizingOperations() {
    int summarizingChoice;

    do {
        cout << "\n==== Summarizing Operations ====\n";
        cout << "1. Get total cost of completed repairs\n";
        cout << "2. Get total cost of all repairs\n";
        cout << "3. Get the number of cars in the system\n";
        cout << "4. Get the average of all repairs costs\n";
        cout << "5. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> summarizingChoice;

        switch (summarizingChoice) {
            case 1: {
                float totalCost = getTotalCostOfCompletedRepairs(); 
                cout << "Total Cost of Completed Repairs: $" << totalCost << endl;
                break;
            }
            case 2: {
                float totalCost = getTotalCostOfAllRepairs(); 
                cout << "Total Cost of All Repairs: $" << totalCost << endl;
                break;
            }
            case 3: {
                int numberOfCars  = getNumberOfCars(cars); 
                cout << "Number of Cars in the system: " << numberOfCars << endl;
                break;
            }
            case 4: {
                float averageCost = calculateAverageRepairCost(repairRecords); 
                cout << "Average Repair Cost: : " << averageCost << endl;
                break;
            }
            case 5:{
                cout << "Returning to the main menu.\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (summarizingChoice != 5);
}

void CarRepairLibrary::fileOperations() {
    int fileChoice;

    do {
        cout << "\n==== File Operations ====\n";
        cout << "1. Save data to file\n";
        cout << "2. Load data from file\n";
        cout << "3. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> fileChoice;

        switch (fileChoice) {
            case 1:
                saveDataToFile();
                break;
            case 2:
                loadDataFromFile();
                break;
            case 3:
                cout << "Returning to the main menu.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (fileChoice != 3);
}