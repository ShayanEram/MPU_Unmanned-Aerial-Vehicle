#ifndef THREAD_MANAGER_HPP
#define THREAD_MANAGER_HPP

#include "BatteryManager.hpp"
#include "FlightController.hpp"
#include "MotorController.hpp"
#include "PayloadManager.hpp"
#include "RemoteController.hpp"
#include "SensorManager.hpp"
#include "TelemetryManager.hpp"

class ThreadManager {
public:
    void startAll();
    void stopAll();

private:
    BatteryManager batteryManager;
    FlightController flightController;
    MotorController motorController;
    PayloadManager payloadManager;
    RemoteController remoteController;
    SensorManager sensorManager;
    TelemetryManager telemetryManager;
};

#endif
