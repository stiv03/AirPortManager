#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include "Aircraft.h"

class Flight {
private:
    std::string flightId;
    std::string departure;
    std::string destination;
    double distance;
    Aircraft aircraft;
    double flightDuration;

public:
    Flight();
    Flight(const std::string& flightId, const std::string& departure, const std::string& destination,
           double distance, const Aircraft& aircraft);

    std::string getFlightId() const;
    void setFlightId(const std::string& flightId);

    std::string getDeparture() const;
    void setDeparture(const std::string& departure);

    std::string getDestination() const;
    void setDestination(const std::string& destination);

    double getDistance() const;
    void setDistance(double distance);

    double calculateFlightDuration();

    double calculateFlightCost() const;

    double calculateFlightCost();

    Aircraft getAircraft() const;

    void checkAircraftCompatibility() const;

    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);

};

#endif // FLIGHT_H
