#ifndef SENSORMANAGER_HPP
#define SENSORMANAGER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class SensorManager {
public:
    explicit SensorManager();
    ~SensorManager();

    void start();
    void stop();

protected:
    // void initializeSensors();
    // void readSensorData();
    // void processSensorData();

private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // SENSORMANAGER_HPP