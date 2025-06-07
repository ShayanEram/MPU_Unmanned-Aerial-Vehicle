/**
 * @file FlightController.hpp
 * @brief Header file for the FlightController class.
 * The brain of the aircraft, responsible for stabilization, navigation, and autonomous flight.
 */

#ifndef FLIGHTCONTROLLER_HPP
#define FLIGHTCONTROLLER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class FlightController {
public:
    explicit FlightController();
    ~FlightController();

    void start();
    void stop();

protected:
    // void update();
    // void setAltitude(float altitude);
    // float getAltitude() const;
    float altitude;

private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // FLIGHTCONTROLLER_HPP