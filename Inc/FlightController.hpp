#ifndef FLIGHTCONTROLLER_HPP
#define FLIGHTCONTROLLER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class FlightController {
public:
    FlightController();
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