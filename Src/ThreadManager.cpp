#include "ThreadManager.hpp"

ThreadManager::ThreadManager()
    : batteryManager(), flightController(), 
      motorController(), remoteController(), payloadManager(),
      sensorManager(), telemetryManager() {}
      
void ThreadManager::startAll() 
{
    batteryManager.start();
    flightController.start();
    motorController.start();
    payloadManager.start();
    remoteController.start();
    sensorManager.start();
    telemetryManager.start();
}

void ThreadManager::stopAll() 
{
    batteryManager.stop();
    flightController.stop();
    motorController.stop();
    payloadManager.stop();
    remoteController.stop();
    sensorManager.stop();
    telemetryManager.stop();
}
