#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include <iostream>
#include <vector>
#include "Flight.h"

class FlightManager {
private:
    std::vector<Flight> flights;
    std::vector<Aircraft> aircrafts;

public:
    void addFlight(const Flight& flight);
    void addAircraft(const Aircraft& aircraft);

    std::vector<Flight> findFlightsByDestination(const std::string& destination) const;
    const std::vector<Aircraft>& getAircrafts() const;
    void displayAllFlights() const;
    void displayAllAircrafts() const;

    void saveToFile() const;
    void loadFromFile();
};

#endif // FLIGHTMANAGER_H
