#ifndef BATTERYMANAGER_HPP
#define BATTERYMANAGER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class BatteryManager {
public:
    BatteryManager();
    ~BatteryManager();

    void start();
    void stop();

protected:
    // void chargeBattery();
    // void dischargeBattery();
    // int getBatteryLevel() const;
    // int batteryLevel;
    
private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // BATTERYMANAGER_HPP