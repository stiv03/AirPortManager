#include "Flight.h"
#include <cmath>
#include <iomanip>

Flight::Flight()
    : flightId("Неизвестен"), departure("Неизвестен"), destination("Неизвестен"), distance(0), flightDuration(0) {}

Flight::Flight(const std::string& flightId, const std::string& departure, const std::string& destination,
               double distance, const Aircraft& aircraft)
    : flightId(flightId), departure(departure), destination(destination), distance(distance), aircraft(aircraft)
{
    calculateFlightDuration();
}

std::string Flight::getFlightId() const {
    return flightId;
}

void Flight::setFlightId(const std::string& flightId) {
    if (flightId.empty()) {
        throw std::invalid_argument("ID на полета не може да бъде празен.");
    }
    this->flightId = flightId;
}

std::string Flight::getDeparture() const {
    return departure;
}

void Flight::setDeparture(const std::string& departure) {
    if (departure.empty()) {
        throw std::invalid_argument("Мястото на заминаване не може да бъде празно.");
    }
    this->departure = departure;
}

std::string Flight::getDestination() const {
    return destination;
}

void Flight::setDestination(const std::string& destination) {
    if (destination.empty()) {
        throw std::invalid_argument("Дестинацията не може да бъде празна.");
    }
    this->destination = destination;
}

double Flight::getDistance() const {
    return distance;
}

void Flight::setDistance(double distance) {
    if (distance <= 0) {
        throw std::invalid_argument("Разстоянието трябва да бъде положително.");
    }
    this->distance = distance;
}

double Flight::calculateFlightDuration() {
    flightDuration = distance / aircraft.getAircraftClass().getAverageSpeed();
    flightDuration = std::round(flightDuration * 100) / 100;
    return flightDuration;
}

double Flight::calculateFlightCost() const {
    return aircraft.calculateFlightCost(distance, aircraft.getAircraftClass().getSeats());
}
void Flight::setAircraft(const Aircraft& aircraft) {
    this->aircraft = aircraft;
}

Aircraft Flight::getAircraft() const {
    return aircraft;
}

void Flight::checkAircraftCompatibility() const {
    if (distance > aircraft.getAircraftClass().calculateMaxFlightDistance()) {
        throw std::invalid_argument("Разстоянието e прекалено голямо за този самолет, самолета не е съвместим");
    }
    std::cout << "Самолета е съвместим за тази дестинация " << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Flight& flight) {
    os << "Информация за полета:\n"
       << "ID на полета: " << flight.flightId << "\n"
       << "От: " << flight.departure << "\n"
       << "До: " << flight.destination << "\n"
       << "Разстояние: " << flight.distance << " км\n"
       << "Продължителност на полета: " << flight.flightDuration << " часа\n"
       << "Извъшва се с самолет : " << flight.getAircraft().getAircraftId()<< " \n"
    << "Цена на полета: " << std::fixed << std::setprecision(0) << flight.calculateFlightCost() << " $\n";
    return os;
}
