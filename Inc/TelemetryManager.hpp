/**
 * @file TelemetryManager.hpp
 * @brief Header file for the TelemetryManager class.
 * Provides real-time data on altitude, speed, battery status, and environmental conditions.
 */

#ifndef TELEMETRY_MANAGER_HPP
#define TELEMETRY_MANAGER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class TelemetryManager {
public:
    explicit TelemetryManager();
    ~TelemetryManager();

    void start();
    void stop();

protected:
    void updateTelemetryData();
    void sendTelemetryData();

    static constexpr int TELEMETRY_UPDATE_INTERVAL_MS = 1000;

    std::string _telemetryPacket;
    
private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // TELEMETRY_MANAGER_HPP