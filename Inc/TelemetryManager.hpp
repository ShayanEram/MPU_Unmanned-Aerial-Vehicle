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
    // void initialize();
    // void update();
    // void sendData();

private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // TELEMETRY_MANAGER_HPP