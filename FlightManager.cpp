#include "FlightManager.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <exception>

void FlightManager::addFlight(const Flight& flight) {
    flights.push_back(flight);
}

void FlightManager::addAircraft(const Aircraft& aircraft) {
    aircrafts.push_back(aircraft);
}

std::vector<Flight> FlightManager::findFlightsByDestination(const std::string& destination) const {
    std::vector<Flight> result;
    for (const auto& flight : flights) {
        if (flight.getDestination() == destination) {
            result.push_back(flight);
        }
    }
    return result;
}

const std::vector<Aircraft>& FlightManager::getAircrafts() const {
    return aircrafts;
}

void FlightManager::displayAllFlights() const {
    for (const auto& flight : flights) {
        std::cout << flight << std::endl;
    }
}

void FlightManager::displayAllAircrafts() const {

    const_cast<FlightManager*>(this)->loadFromFile();

    if (aircrafts.empty()) {
        std::cout << "Няма добавени самолети\n";
    } else {
        for (const auto& aircraft : aircrafts) {
            std::cout << aircraft << std::endl;
        }
    }
}


void FlightManager::saveToFile() const {
    try {
        if (aircrafts.empty() && flights.empty()) {
            std::cerr << "Няма данни за записване." << std::endl;
            return;
        }

        std::ofstream aircraftFile("aircrafts.txt", std::ios::out | std::ios::app);
        if (!aircraftFile) {
            throw std::ios_base::failure("Неуспешно отваряне на файла aircrafts.txt");
        }

        std::ofstream flightFile("flights.txt", std::ios::out | std::ios::app);
        if (!flightFile) {
            throw std::ios_base::failure("Неуспешно отваряне на файла flights.txt");
        }

        for (const auto& aircraft : aircrafts) {
            aircraftFile << aircraft.getAircraftId() << " "
                         << aircraft.getAircraftClass().getManufacturer() << " "
                         << aircraft.getAircraftClass().getModel() << " "
                         << aircraft.getAircraftClass().getSeats() << " "
                         << aircraft.getAircraftClass().getMinRunwayLength() << " "
                         << aircraft.getAircraftClass().getFuelConsumptionPerKMPerSeat() << " "
                         << aircraft.getAircraftClass().getFuelTankCapacity() << " "
                         << aircraft.getAircraftClass().getAverageSpeed() << " "
                         << aircraft.getCrewCost() << "\n";
        }

        for (const auto& flight : flights) {
            flightFile << flight.getFlightId() << " "
                       << flight.getDeparture() << " "
                       << flight.getDestination() << " "
                       << flight.getDistance() << " "
                       << flight.getAircraft().getAircraftId() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Възникна грешка по време на запис на файлове: " << e.what() << std::endl;
    }
}

void FlightManager::loadFromFile() {
    std::ifstream aircraftFile("aircrafts.txt");
    std::ifstream flightFile("flights.txt");

    if (aircraftFile.is_open()) {
        std::string aircraftId, manufacturer, model;
        int seats;
        double minRunwayLength, fuelConsumption, fuelTankCapacity, averageSpeed, crewCost;

        while (aircraftFile >> aircraftId >> manufacturer >> model >> seats >> minRunwayLength
               >> fuelConsumption >> fuelTankCapacity >> averageSpeed >> crewCost) {

            bool exists = false;
            for (const auto& aircraft : aircrafts) {
                if (aircraft.getAircraftId() == aircraftId) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                AircraftClass aircraftClass(manufacturer, model, seats, minRunwayLength, fuelConsumption, fuelTankCapacity, averageSpeed);
                Aircraft newAircraft(aircraftId, aircraftClass, crewCost);
                aircrafts.push_back(newAircraft);
            }
               }
    }

    if (flightFile.is_open()) {
        std::string line;

        while (std::getline(flightFile, line)) {
            if (line.empty()) continue;

            std::istringstream iss(line);
            std::string flightId, departure, destination, aircraftId;
            double distance;

            if (iss >> flightId >> departure >> destination >> distance >> aircraftId) {
                for (const auto& aircraft : aircrafts) {
                    if (aircraft.getAircraftId() == aircraftId) {
                        Flight newFlight(flightId, departure, destination, distance, aircraft);
                        flights.push_back(newFlight);
                        break;
                    }
                }
            } else {
                std::cerr << "Невалиден ред във файла: " << line << std::endl;
            }
        }
    }

    aircraftFile.close();
    flightFile.close();
}

