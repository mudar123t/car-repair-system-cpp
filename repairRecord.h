#ifndef REPAIRRECORD_H
#define REPAIRRECORD_H

#include <string>

using namespace std;

enum RepairStatus {
    PENDING,
    IN_PROGRESS,
    COMPLETED
};

class RepairRecord {
private:
    int RecordID;
    int CarID;
    string Date;
    string TechnicianName;
    string Description;
    float Cost;
    RepairStatus status;

public:
    RepairRecord();
    RepairRecord(int recordID, int carID, const string& date, const string& technician, const string& description, float cost, RepairStatus status);

    ~RepairRecord();

    int getRecordID() const;
    int getCarID() const;
    string getDate() const;
    string getTechnician() const;
    string getDescription() const;
    float getCost() const;
    RepairStatus getStatus() const;

    void setRecordID(int recordID);
    void setCarID(int carID);
    void setDate(const string& date);
    void setTechnician(const string& technician);
    void setDescription(const string& description);
    void setCost(float cost);
    void setStatus(RepairStatus status);
    string toCSVString() const;

    
    friend istream& operator>>(istream& is, RepairRecord& record);
    friend ostream& operator<<(ostream& os, const RepairRecord& record);
};

#endif
