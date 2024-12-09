#include "Menu.h"

Menu::Menu(FlightManager& manager) : manager(manager) {}

void Menu::displayMenu() const {
    std::cout << "\n===== Система за управление на летище =====\n";
    std::cout << "1. Добавяне на самолет\n";
    std::cout << "2. Добавяне на полет\n";
    std::cout << "3. Преглед на всички самолети\n";
    std::cout << "4. Преглед на всички полети\n";
    std::cout << "5. Търсене на полети по дестинация\n";
    std::cout << "6. Изход\n";
    std::cout << "Въведете вашия избор: ";
}


void Menu::handleAddAircraft() {
    std::string aircraftId, manufacturer, model;
    int seats;
    double minRunwayLength, fuelConsumption, fuelTankCapacity, averageSpeed, crewCost;

    std::cout << "Въведете ID на самолета: ";
    std::cin >> aircraftId;

    std::cout << "Въведете производител: ";
    std::cin >> manufacturer;

    std::cout << "Въведете модел: ";
    std::cin >> model;

    std::cout << "Въведете брой места: ";
    std::cin >> seats;

    std::cout << "Въведете минимална дължина на пистата (м): ";
    std::cin >> minRunwayLength;

    std::cout << "Въведете разход на гориво на км на седалка (литри): ";
    std::cin >> fuelConsumption;

    std::cout << "Въведете капацитет на резервоара за гориво (литри): ";
    std::cin >> fuelTankCapacity;

    std::cout << "Въведете средна скорост (км/ч): ";
    std::cin >> averageSpeed;

    std::cout << "Въведете разход за екипаж ($): ";
    std::cin >> crewCost;


    AircraftClass aircraftClass(manufacturer, model, seats, minRunwayLength, fuelConsumption, fuelTankCapacity, averageSpeed);
    Aircraft newAircraft(aircraftId, aircraftClass, crewCost);
    manager.addAircraft(newAircraft);

    manager.saveToFile();

    std::cout << "Добавен успешно!\n";
}

void Menu::handleAddFlight() {
    std::string flightId, departure, destination, aircraftId;
    double distance;

    std::cout << "Въведете ID на полета: ";
    std::cin >> flightId;

    std::cout << "Въведете място на излитане: ";
    std::cin >> departure;

    std::cout << "Въведете дестинация: ";
    std::cin >> destination;

    std::cout << "Въведете разстояние (км): ";
    std::cin >> distance;

    std::cout << "Въведете ID на самолета, който да бъде назначен за този полет: ";

    std::cin >> aircraftId;

    Aircraft* selectedAircraft = nullptr;
    for (const auto& aircraft : manager.getAircrafts()) {
        if (aircraft.getAircraftId() == aircraftId) {
            selectedAircraft = new Aircraft(aircraft);
            break;
        }
    }

    if (selectedAircraft) {
        Flight newFlight(flightId, departure, destination, distance, *selectedAircraft);
        newFlight.checkAircraftCompatibility();
        manager.addFlight(newFlight);
        manager.saveToFile();
        std::cout << "Добавен успешно!\n";
    } else {
        std::cout << "Самолет с ID " << aircraftId << " не е намерен!\n";
    }
}

void Menu::handleViewAllAircrafts() const {
    std::cout << "\n--- Всички самолети ---\n";
    manager.displayAllAircrafts();
}

void Menu::handleViewAllFlights() const {
    std::cout << "\n--- Всички полети ---\n";
    manager.displayAllFlights();
}

void Menu::handleFindFlightsByDestination() const {
    std::string destination;
    std::cout << "Въведете дестинация за търсне на полет ";
    std::cin >> destination;

    std::vector<Flight> flights = manager.findFlightsByDestination(destination);
    if (flights.empty()) {
        std::cout << "Не са намерени полети за " << destination << std::endl;
    } else {
        std::cout << "\n--- Полети за " << destination << " ---\n";
        for (const auto& flight : flights) {
            std::cout << flight.getFlightId() << std::endl;
        }
    }
}
