#ifndef TELEMETRY_MANAGER_HPP
#define TELEMETRY_MANAGER_HPP

class TelemetryManager {
public:
    TelemetryManager();
    ~TelemetryManager();

    void initialize();
    void update();
    void sendData();

private:
    // Add private member variables here
};

#endif // TELEMETRY_MANAGER_HPP