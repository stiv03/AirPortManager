#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include "AircraftClass.h"

class Aircraft {
private:
    std::string aircraftId;
    AircraftClass aircraftClass;
    double crewCost;

public:
    Aircraft();
    Aircraft(const std::string& aircraftId, const AircraftClass& aircraftClass, double crewCost);

    std::string getAircraftId() const;
    void setAircraftId(const std::string& aircraftId);

    AircraftClass getAircraftClass() const;
    void setAircraftClass(const AircraftClass& aircraftClass);

    double getCrewCost() const;
    void setCrewCost(double crewCost);

    double calculateFlightCost(double distance, int passengers) const;

    friend std::ostream& operator<<(std::ostream& os, const Aircraft& aircraft);
};

#endif // AIRCRAFT_H
