#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "FlightManager.h"

class Menu {
private:
    FlightManager& manager; // Референция към обекта на FlightManager
public:
    Menu(FlightManager& manager); // Конструктор

    void displayMenu() const;
    void handleAddAircraft();
    void handleAddFlight();
    void handleViewAllAircrafts() const;
    void handleViewAllFlights() const;
    void handleFindFlightsByDestination() const;
};

#endif // MENU_H
