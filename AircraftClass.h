#ifndef AIRCRAFTCLASS_H
#define AIRCRAFTCLASS_H

#include <iostream>
#include <string>

#include "Type.h"

class AircraftClass {
    //type( A,B, C)
private:
    Type type;
    std::string manufacturer;
    std::string model;
    int seats;
    double minRunwayLength;
    double fuelConsumptionPerKMPerSeat;
    double fuelTankCapacity;
    double averageSpeed;

public:
    AircraftClass();
    AircraftClass(std::string manufacturer, std::string model, int seats, double minRunwayLength,
                  double fuelConsumptionPerKMPerSeat, double fuelTankCapacity, double averageSpeed);

    Type getType() const;

    void setType(Type type);

    std::string getManufacturer() const;
    void setManufacturer(const std::string& manufacturer);

    std::string getModel() const;
    void setModel(const std::string& model);

    int getSeats() const;
    void setSeats(int seats);

    double getMinRunwayLength() const;
    void setMinRunwayLength(double minRunwayLength);

    double getFuelConsumptionPerKMPerSeat() const;
    void setFuelConsumptionPerKMPerSeat(double fuelConsumptionPerKMPerSeat);

    double getFuelTankCapacity() const;
    void setFuelTankCapacity(double fuelTankCapacity);

    double getAverageSpeed() const;
    void setAverageSpeed(double averageSpeed);

    double calculateMaxFlightDistance() const;

    void autoDetermineType();

    friend std::ostream& operator<<(std::ostream& os, const AircraftClass& aircraftClass);
};

#endif // AIRCRAFTCLASS_H
