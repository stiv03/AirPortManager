#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "FlightManager.h"

class Menu {
private:
    FlightManager& manager;
public:
    Menu(FlightManager& manager);

    void displayMenu() const;
    void handleAddAircraft();
    void handleAddFlight();
    void handleViewAllAircrafts() const;
    void handleViewAllFlights() const;
    void handleFindFlightsByDestination() const;
};

#endif // MENU_H
