#include "SensorManager.hpp"

SensorManager::SensorManager() : running(false) {
    // Constructor implementation
}

SensorManager::~SensorManager() {
    stop();
}

void SensorManager::start() {
    if (!running.load()) {
        running.store(true);
        moduleThread = std::thread(&SensorManager::runLoop, this);
    }
}

void SensorManager::stop() {
    if (running.load()) {
        running.store(false);
        if (moduleThread.joinable()) {
            moduleThread.join();
        }
    }
}

void SensorManager::runLoop() {

    while (running.load()) {


        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate periodic sensor updates

        std::cout << "SensorManager running... Sensor data processed." << std::endl;
    }
}