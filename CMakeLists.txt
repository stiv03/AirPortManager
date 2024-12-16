cmake_minimum_required(VERSION 3.30)
project(AirPort)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF) # Disable GNU extensions

add_executable(AirPort main.cpp
        AircraftClass.cpp
        Aircraft.cpp
        AircraftClass.h
        Aircraft.h
        Flight.h
        Flight.cpp
        FlightManager.h
        FlightManager.cpp
        Menu.h
        Menu.cpp
        Type.h)
