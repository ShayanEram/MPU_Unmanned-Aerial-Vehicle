#include "FlightController.hpp"

FlightController::FlightController(
    MessageQueue<BatteryData>& batteryQueue,
    SharedResource<MotorData>& motorData,
    Observer<PayloadData>& payloadObserver,
    SharedResource<RemoteData>& remoteData,
    MessageQueue<SensorData>& sensorQueue)
    : _batteryQueue(batteryQueue), 
    _motorData(motorData),
    _payloadObserver(payloadObserver), 
    _remoteData(remoteData),
    _sensorQueue(sensorQueue), 
    running(false)
{
    altitude = 0.0f; // Initialize altitude
}

FlightController::~FlightController() {
    stop();
}

void FlightController::start() {
    if (!running.load()) {
        running.store(true);
        moduleThread = std::thread(&FlightController::runLoop, this);
    }
}

void FlightController::stop() {
    if (running.load()) {
        running.store(false);
        if (moduleThread.joinable()) {
            moduleThread.join();
        }
    }
}

void FlightController::runLoop() {
    
    while (running.load()) {

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate periodic updates

        std::cout << "FlightController running... Altitude: " << altitude << std::endl;
    }
}