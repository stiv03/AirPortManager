#include "Aircraft.h"

Aircraft::Aircraft()
    : aircraftId("Невалиден"), aircraftClass(), crewCost(0) {}

Aircraft::Aircraft(const std::string& aircraftId, const AircraftClass& aircraftClass, double crewCost)
    : aircraftId(aircraftId), aircraftClass(aircraftClass), crewCost(crewCost) {}

std::string Aircraft::getAircraftId() const {
    return aircraftId;
}

void Aircraft::setAircraftId(const std::string& aircraftId) {
    if (aircraftId.empty()) {
        throw std::invalid_argument("ID на самолета не може да е празно.");
    }
    this->aircraftId = aircraftId;
}

AircraftClass Aircraft::getAircraftClass() const {
    return aircraftClass;
}

void Aircraft::setAircraftClass(const AircraftClass& aircraftClass) {
    this->aircraftClass = aircraftClass;
}

double Aircraft::getCrewCost() const {
    return crewCost;
}

void Aircraft::setCrewCost(double crewCost) {
    if (crewCost < 0) {
        throw std::invalid_argument("Разходите трябва да са позитивно число.");
    }
    this->crewCost = crewCost;
}

double Aircraft::calculateFlightCost(double distance, int passengers) const {
    if (distance <= 0) {
        throw std::invalid_argument("Дистанцията трбява да е позотивна");
    }
    if (passengers <= 0 || passengers > aircraftClass.getSeats()) {
        throw std::invalid_argument("Броя на пътниците трябва да позитивен и в рамките на броя на седалките.");
    }
    double fuelCost = distance * passengers * aircraftClass.getFuelConsumptionPerKMPerSeat();
    double totalCost = fuelCost + crewCost;
    return totalCost;
}

std::ostream& operator<<(std::ostream& os, const Aircraft& aircraft) {
    os << "Информация за самолета:\n"
       << "ID на самолета: " << aircraft.aircraftId << "\n"
       << "Производител: " << aircraft.getAircraftClass().getManufacturer() << "\n"
       << "Модел: " << aircraft.getAircraftClass().getModel() << "\n"
       << "Брой места: " << aircraft.getAircraftClass().getSeats() << "\n"
       << "Минимална дължина на пистата (м): " << aircraft.getAircraftClass().getMinRunwayLength() << "\n"
       << "Разход на гориво на км на седалка (литри): " << aircraft.getAircraftClass().getFuelConsumptionPerKMPerSeat() << "\n"
       << "Максимално разстояние което може да измине: " << aircraft.getAircraftClass().calculateMaxFlightDistance() << " км \n"
       << "Капацитет на резервоара за гориво (литри): " << aircraft.getAircraftClass().getFuelTankCapacity() << "\n"
       << "Средна скорост (км/ч): " << aircraft.getAircraftClass().getAverageSpeed() << "\n"
       << "Разход за екипаж ($): " << aircraft.crewCost << "\n";
    return os;
}
