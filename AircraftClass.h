#ifndef AIRCRAFTCLASS_H
#define AIRCRAFTCLASS_H

#include <iostream>
#include <string>

class AircraftClass {
private:
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

    friend std::ostream& operator<<(std::ostream& os, const AircraftClass& aircraftClass);
};

#endif // AIRCRAFTCLASS_H
