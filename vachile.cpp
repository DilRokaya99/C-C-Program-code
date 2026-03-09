#include <iostream>
#include <string>

class Vehicle {
public:
    double mileage;
    double price;

    Vehicle(double _mileage, double _price)
        : mileage(_mileage), price(_price) {}
};

class Car : public Vehicle {
public:
    double ownershipCost;
    int warrantyYears;
    int seatingCapacity;
    std::string fuelType;

    Car(double _mileage, double _price, double _ownershipCost, int _warrantyYears, int _seatingCapacity, const std::string& _fuelType)
        : Vehicle(_mileage, _price), ownershipCost(_ownershipCost), warrantyYears(_warrantyYears), seatingCapacity(_seatingCapacity), fuelType(_fuelType) {}
};

class Bike : public Vehicle {
public:
    int numCylinders;
    int numGears;
    std::string coolingType;
    std::string wheelType;
    double fuelTankSize;

    Bike(double _mileage, double _price, int _numCylinders, int _numGears, const std::string& _coolingType, const std::string& _wheelType, double _fuelTankSize)
        : Vehicle(_mileage, _price), numCylinders(_numCylinders), numGears(_numGears), coolingType(_coolingType), wheelType(_wheelType), fuelTankSize(_fuelTankSize) {}
};

class Audi : public Car {
public:
    std::string modelType;

    Audi(double _mileage, double _price, double _ownershipCost, int _warrantyYears, int _seatingCapacity, const std::string& _fuelType, const std::string& _modelType)
        : Car(_mileage, _price, _ownershipCost, _warrantyYears, _seatingCapacity, _fuelType), modelType(_modelType) {}
};

class Ford : public Car {
public:
    std::string modelType;

    Ford(double _mileage, double _price, double _ownershipCost, int _warrantyYears, int _seatingCapacity, const std::string& _fuelType, const std::string& _modelType)
        : Car(_mileage, _price, _ownershipCost, _warrantyYears, _seatingCapacity, _fuelType), modelType(_modelType) {}
};

class Bajaj : public Bike {
public:
    std::string makeType;

    Bajaj(double _mileage, double _price, int _numCylinders, int _numGears, const std::string& _coolingType, const std::string& _wheelType, double _fuelTankSize, const std::string& _makeType)
        : Bike(_mileage, _price, _numCylinders, _numGears, _coolingType, _wheelType, _fuelTankSize), makeType(_makeType) {}
};

class TVS : public Bike {
public:
    std::string makeType;

    TVS(double _mileage, double _price, int _numCylinders, int _numGears, const std::string& _coolingType, const std::string& _wheelType, double _fuelTankSize, const std::string& _makeType)
        : Bike(_mileage, _price, _numCylinders, _numGears, _coolingType, _wheelType, _fuelTankSize), makeType(_makeType) {}
};

int main() {
    // Create and print information for an Audi car
    Audi audi(25.5, 50000.0, 3000.0, 3, 5, "Petrol", "A4");
    std::cout << "Audi Car Information:" << std::endl;
    std::cout << "Model Type: " << audi.modelType << std::endl;
    std::cout << "Ownership Cost: " << audi.ownershipCost << std::endl;
    std::cout << "Warranty (Years): " << audi.warrantyYears << std::endl;
    std::cout << "Seating Capacity: " << audi.seatingCapacity << std::endl;
    std::cout << "Fuel Type: " << audi.fuelType << std::endl;
    std::cout << "Mileage: " << audi.mileage << std::endl;
    std::cout << "Price: " << audi.price << std::endl;
    std::cout << std::endl;

    // Create and print information for a Ford car
    Ford ford(22.0, 45000.0, 2800.0, 3, 5, "Petrol", "Fusion");
    std::cout << "Ford Car Information:" << std::endl;
    std::cout << "Model Type: " << ford.modelType << std::endl;
    std::cout << "Ownership Cost: " << ford.ownershipCost << std::endl;
    std::cout << "Warranty (Years): " << ford.warrantyYears << std::endl;
    std::cout << "Seating Capacity: " << ford.seatingCapacity << std::endl;
    std::cout << "Fuel Type: " << ford.fuelType << std::endl;
    std::cout << "Mileage: " << ford.mileage << std::endl;
    std::cout << "Price: " << ford.price << std::endl;
    std::cout << std::endl;

    // Create and print information for a Bajaj bike
    Bajaj bajaj(60.0, 3000.0, 2, 5, "Air", "Spokes", 3.5, "Pulsar");
    std::cout << "Bajaj Bike Information:" << std::endl;
    std::cout << "Make Type: " << bajaj.makeType << std::endl;
    std::cout << "Number of Cylinders: " << bajaj.numCylinders << std::endl;
    std::cout << "Number of Gears: " << bajaj.numGears << std::endl;
    std::cout << "Cooling Type: " << bajaj.coolingType << std::endl;
    std::cout << "Wheel Type: " << bajaj.wheelType << std::endl;
    std::cout << "Fuel Tank Size (inches): " << bajaj.fuelTankSize << std::endl;
    std::cout << "Mileage: " << bajaj.mileage << std::endl;
    std::cout << "Price: " << bajaj.price << std::endl;
    std::cout << std::endl;

    // Create and print information for a TVS bike
    TVS tvs(55.0, 2800.0, 1, 4, "Liquid", "Alloys", 3.2, "Apache");
    std::cout << "TVS Bike Information:" << std::endl;
 return 0;  
}