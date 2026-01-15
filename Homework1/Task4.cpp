#include "Task4.h"
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    string color;
    string gearboxType;
    int horsepower;
    string fuelType;
    string engineType;
    int engineVolumeCC;
    double engineVolumeL;
    int weight;
    int kilometers;

public:
    void input() {
        cout << "Brand: ";
        getline(cin, brand);
        cout << "Model: ";
        getline(cin, model);
        cout << "Year of manufacture: ";
        cin >> year; cin.ignore();
        cout << "Color: ";
        getline(cin, color);
        cout << "Gearbox type (automatic/manual): ";
        getline(cin, gearboxType);
        cout << "Engine power (hp): ";
        cin >> horsepower; cin.ignore();
        cout << "Fuel type (petrol/diesel/gas/gas-petrol): ";
        getline(cin, fuelType);
        cout << "Engine type (V-shaped/inline/boxer): ";
        getline(cin, engineType);
        cout << "Engine volume (cc): ";
        cin >> engineVolumeCC;
        cout << "Engine volume (liters): ";
        cin >> engineVolumeL;
        cout << "Weight (kg): ";
        cin >> weight;
        cout << "Kilometers traveled: ";
        cin >> kilometers;
        cin.ignore();
    }

    void print() const {
        cout << "\nCar information:\n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year of manufacture: " << year << endl;
        cout << "Color: " << color << endl;
        cout << "Gearbox type: " << gearboxType << endl;
        cout << "Engine power: " << horsepower << " hp" << endl;
        cout << "Fuel type: " << fuelType << endl;
        cout << "Engine type: " << engineType << endl;
        cout << "Engine volume (cc): " << engineVolumeCC << endl;
        cout << "Engine volume (liters): " << engineVolumeL << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Kilometers traveled: " << kilometers << endl;
    }
};

void Task4() {
    Car car;
    car.input();
    car.print();
}
