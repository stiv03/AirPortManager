#include "AircraftClass.h"
#include <stdexcept>

AircraftClass::AircraftClass()
    : manufacturer("Неизвестен"), model("Неизвестен"), seats(0), minRunwayLength(0),
      fuelConsumptionPerKMPerSeat(0), fuelTankCapacity(0), averageSpeed(0) {}

AircraftClass::AircraftClass(std::string manufacturer, std::string model, int seats, double minRunwayLength,
                             double fuelConsumptionPerKMPerSeat, double fuelTankCapacity, double averageSpeed)
{
    setManufacturer(manufacturer);
    setModel(model);
    setSeats(seats);
    setMinRunwayLength(minRunwayLength);
    setFuelConsumptionPerKMPerSeat(fuelConsumptionPerKMPerSeat);
    setFuelTankCapacity(fuelTankCapacity);
    setAverageSpeed(averageSpeed);
    autoDetermineType();
}

void AircraftClass::autoDetermineType() {
    if (seats < 100 && minRunwayLength < 2000) {
        type = Type::A; // Малък самолет
    } else if (seats >= 100 && seats <= 200 &&
               minRunwayLength >= 2000 && minRunwayLength <= 3000) {
        type = Type::B; // Среден самолет
               } else {
                   type = Type::C; // Голям самолет
               }
}

Type AircraftClass::getType() const {
    return type;
}

std::string AircraftClass::getManufacturer() const {
    return manufacturer;
}

void AircraftClass::setManufacturer(const std::string& manufacturer) {
    if (manufacturer.empty()) {
        throw std::invalid_argument("Производителя не може да бъде празен.");
    }
    this->manufacturer = manufacturer;
}

std::string AircraftClass::getModel() const {
    return model;
}

void AircraftClass::setModel(const std::string& model) {
    if (model.empty()) {
        throw std::invalid_argument("Модела не може да бъде празен.");
    }
    this->model = model;
}

int AircraftClass::getSeats() const {
    return seats;
}

void AircraftClass::setSeats(int seats) {
    if (seats <= 0) {
        throw std::invalid_argument("Седалките трябва да са позитивно число");
    }
    this->seats = seats;
}

double AircraftClass::getMinRunwayLength() const {
    return minRunwayLength;
}

void AircraftClass::setMinRunwayLength(double minRunwayLength) {
    if (minRunwayLength <= 0) {
        throw std::invalid_argument("Пистата трябва да е положително число");
    }
    this->minRunwayLength = minRunwayLength;
}

double AircraftClass::getFuelConsumptionPerKMPerSeat() const {
    return fuelConsumptionPerKMPerSeat;
}

void AircraftClass::setFuelConsumptionPerKMPerSeat(double fuelConsumptionPerKMPerSeat) {
    if (fuelConsumptionPerKMPerSeat <= 0) {
        throw std::invalid_argument("Положително число");
    }
    this->fuelConsumptionPerKMPerSeat = fuelConsumptionPerKMPerSeat;
}

double AircraftClass::getFuelTankCapacity() const {
    return fuelTankCapacity;
}

void AircraftClass::setFuelTankCapacity(double fuelTankCapacity) {
    if (fuelTankCapacity <= 0) {
        throw std::invalid_argument("Капацитета на горивото трябва да е положително число");
    }
    this->fuelTankCapacity = fuelTankCapacity;
}

double AircraftClass::getAverageSpeed() const {
    return averageSpeed;
}

void AircraftClass::setAverageSpeed(double averageSpeed) {
    if (averageSpeed <= 0) {
        throw std::invalid_argument("Средната скорост трябва да е положително число");
    }
    this->averageSpeed = averageSpeed;
}

double AircraftClass::calculateMaxFlightDistance() const {
    return fuelTankCapacity / fuelConsumptionPerKMPerSeat;
}

std::ostream& operator<<(std::ostream& os, const Type& type) {
    switch (type) {
        case Type::A: os << "A"; break;
        case Type::B: os << "B"; break;
        case Type::C: os << "C"; break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const AircraftClass& aircraftClass) {
    os << "Клас на самолета\n"
       << "Клас: " << aircraftClass.type << "\n"
       << "Прозиводител: " << aircraftClass.manufacturer << "\n"
       << "Модел: " << aircraftClass.model << "\n"
       << "Седалки: " << aircraftClass.seats << "\n"
       << "Максимално разстояние: " << aircraftClass.calculateMaxFlightDistance() << " км \n"
       << "Минимална дължина на пистата: " << aircraftClass.minRunwayLength << " метра\n";
    return os;
}
