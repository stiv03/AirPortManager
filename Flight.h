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
    int passengers;
    Aircraft aircraft;
    double flightDuration;

    //passengers

public:
    Flight();
    Flight(const std::string& flightId, const std::string& departure, const std::string& destination,
           double distance, const Aircraft& aircraft, int passengers);

    std::string getFlightId() const;
    void setFlightId(const std::string& flightId);

    std::string getDeparture() const;
    void setDeparture(const std::string& departure);

    std::string getDestination() const;
    void setDestination(const std::string& destination);

    double getDistance() const;
    void setDistance(double distance);

    int getPassengers() const;
    void setPassengers(int passengers);

    double calculateFlightDuration();

    double calculateFlightCost() const;

    Aircraft getAircraft() const;

    void setAircraft(const Aircraft &aircraft);

    void checkAircraftCompatibility() const;
    void checkPassengersCompatibility() const;


    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);

};

#endif // FLIGHT_H
