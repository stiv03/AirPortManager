#include <iostream>
#include "FlightManager.h"
#include "Menu.h"

int main() {
    FlightManager manager;

    manager.loadFromFile();

    Menu menu(manager);
    int choice;

    do {
        menu.displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                menu.handleAddAircraft();
                 break;
            case 2:
                menu.handleAddFlight();
                break;
            case 3:
                menu.handleViewAllAircrafts();
                break;
            case 4:
                menu.handleViewAllFlights();
                break;
            case 5:
                menu.handleFindFlightsByDestination();
                break;
            case 6:
                std::cout << "Довиждане!" << std::endl;
                break;
            default:
                std::cout << "Невалиден избор. Моля опитайте отново." << std::endl;
        }

    } while (choice != 6);

    return 0;
}
