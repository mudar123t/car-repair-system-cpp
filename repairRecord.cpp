#include "RepairRecord.h"
#include <iostream>
using namespace std;

RepairRecord::RepairRecord(){}

RepairRecord::RepairRecord(int recordID, int carID, const string& date, const string& technician, const string& description, float cost, RepairStatus status) {

    RecordID = recordID;
    CarID = carID;
    Date = date;
    TechnicianName = technician;
    Description = description;
    Cost = cost;
    this->status = status;
}


RepairRecord::~RepairRecord() {
}

int RepairRecord::getRecordID() const {
    return RecordID;
}

int RepairRecord::getCarID() const {
    return CarID;
}

string RepairRecord::getDate() const {
    return Date;
}

string RepairRecord::getTechnician() const {
    return TechnicianName;
}

string RepairRecord::getDescription() const {
    return Description;
}

float RepairRecord::getCost() const {
    return Cost;
}

RepairStatus RepairRecord::getStatus() const {
    return status;
}


void RepairRecord::setRecordID(int recordID) {
    RecordID = recordID;
}

void RepairRecord::setCarID(int carID) {
    CarID = carID;
}

void RepairRecord::setDate(const string& date) {
    Date = date;
}

void RepairRecord::setTechnician(const string& technician) {
    TechnicianName = technician;
}

void RepairRecord::setDescription(const string& description) {
    Description = description;
}

void RepairRecord::setCost(float cost) {
    Cost = cost;
}

void RepairRecord::setStatus(RepairStatus status) {
    this->status = status;
}

string RepairRecord::toCSVString() const {
    string statusString;
    switch (getStatus()) {
        case PENDING:
            statusString = "PENDING";
            break;
        case IN_PROGRESS:
            statusString = "IN_PROGRESS";
            break;
        case COMPLETED:
            statusString = "COMPLETED";
            break;
        default:
            statusString = "UNKNOWN";
            break;
    }
    return to_string(getRecordID()) + "," + to_string(getCarID()) + "," + getDate() + ","
         + getTechnician() + "," + getDescription() + "," + to_string(getCost()) + ","
         + statusString;
}

istream& operator>>(istream& is, RepairStatus& status) {
    string statusStr;
    is >> statusStr;

    if (statusStr == "PENDING") {
        status = RepairStatus::PENDING;
    } else if (statusStr == "IN_PROGRESS") {
        status = RepairStatus::IN_PROGRESS;
    } else if (statusStr == "COMPLETED") {
        status = RepairStatus::COMPLETED;
    }

    return is;
}

string getStatusString(RepairStatus status) {
    switch (status) {
        case RepairStatus::PENDING:
            return "PENDING";
        case RepairStatus::IN_PROGRESS:
            return "IN_PROGRESS";
        case RepairStatus::COMPLETED:
            return "COMPLETED";
        default:
            return "UNKNOWN";
    }
}

istream& operator>>(istream& is, RepairRecord& record) {
    char comma;

    is >> record.RecordID >> comma >> record.CarID >> comma;
    getline(is, record.Date, ',');
    getline(is, record.TechnicianName, ',');
    getline(is, record.Description, ',');
    is >> record.Cost >> comma >> record.status;

    return is;
}

ostream& operator<<(ostream& os, const RepairRecord& record) {
    os << "RecordID: " << record.getRecordID() << ", CarID: " << record.getCarID() << ", Date: " << record.getDate()
       << ", Technician: " << record.getTechnician() << ", Description: " << record.getDescription()
       << ", Cost: " << record.getCost() << ", Status: " << getStatusString(record.getStatus());
    return os;
}