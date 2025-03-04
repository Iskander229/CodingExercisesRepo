//In this project I'm using Classes, Inheritance, Abstraction and template methods.

#include <iostream>
#include <string>
using namespace std;

//base Class for vehicles
class Vehicle {
protected:
    string vehicleName;

public:
    //constructor
    Vehicle(const string& name) 
        : vehicleName(name){}

    //abstract method
    virtual void showInfo() const = 0;

    //cleanup
    virtual ~Vehicle() {}
};


//DERIVING CAR AND MOTO

class Car : public Vehicle {
private:
    int numDoors;

public:
    //constructor
    Car(const string& name, int doors) 
        : Vehicle(name), numDoors(doors) {}

    //overriding info
    void showInfo() const override {
        cout << "Car Name: " << vehicleName << endl;
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    //constructor
    Motorcycle(const string& name, bool sidecar) 
        : Vehicle(name), hasSidecar(sidecar) {}

    //overriding info
    void showInfo() const override {
        cout << "Motorcycle Name: " << vehicleName << endl;
        cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

// template - garage
template <typename T>
class Garage {
private:
    T* vehicle; //pointer to store any type of vehicle

public:
    //constructor
    Garage() : vehicle(nullptr) {}

    //cleanup
    ~Garage() {
        delete vehicle; 
    }

    //storing a vehicle 
    void storeVehicle(T* v) {
        vehicle = v;
    }

    //display stored info
    void showStoredInfo() const {
        if (vehicle) {
            vehicle->showInfo();
        }
        else {
            cout << "No vehicles in the garage." << endl;
        }
    }
};


int main() {
    string carName;
    string motoName;
    int numDoors;
    bool hasSidecar;

    //Car input
    cout << "Enter Car Name: ";
    getline(cin, carName);
    cout << "Enter Number of Doors: ";
    cin >> numDoors;

    //Moto input
    cin.ignore(); //clean buffer after the car input
    cout << "Enter Motorcycle Name: ";
    getline(cin, motoName);
    cout << "Does the Motorcycle have a sidecar? (1 for Yes, 0 for No): ";
    cin >> hasSidecar;

    //User objects
    Car* newCar = new Car(carName, numDoors);
    Motorcycle* newMoto = new Motorcycle(motoName, hasSidecar);

    //Garagee objects
    Garage<Vehicle> carGarage;
    Garage<Vehicle> motoGarage;

    //Storing vehicles in garage
    carGarage.storeVehicle(newCar);
    motoGarage.storeVehicle(newMoto);

    //display vehicle details from garage
    cout << "\nCar Garage Details:" << endl;
    carGarage.showStoredInfo();
    cout << "\nMotorcycle Garage Details:" << endl;
    motoGarage.showStoredInfo();

    //avoiding memory leaks from pointers
    delete newCar;
    delete newMoto;

    return 0; //cleanups
}
