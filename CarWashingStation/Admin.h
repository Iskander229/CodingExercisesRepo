#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "CarWashStation.h" // Include CarWashStation header
#include "Service.h"        // Include Service header

class Admin {
private:
    std::string adminID;
    std::string name;
    static const std::string ADMIN_PASSWORD; // Fixed password

public:
    Admin(const std::string& id, const std::string& name);
    bool login(const std::string& password) const;
    void addService(CarWashStation<Service>& carWash); // Use CarWashStation<Service>
    void removeService(CarWashStation<Service>& carWash); // Use CarWashStation<Service>
    void viewSalesReport(const CarWashStation<Service>& carWash) const; // Use CarWashStation<Service>
};

#endif