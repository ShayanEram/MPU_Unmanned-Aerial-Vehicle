/**
 * @file SensorManager.hpp
 * @brief Header file for SensorManager class.
 * Includes GPS, IMU (gyroscope, accelerometer), barometer, and magnetometer for precise movement tracking.
 * 
 */

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