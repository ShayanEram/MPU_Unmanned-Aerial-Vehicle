#ifndef BATTERYMANAGER_HPP
#define BATTERYMANAGER_HPP

class BatteryManager {
public:
    BatteryManager();
    ~BatteryManager();

    void chargeBattery();
    void dischargeBattery();
    int getBatteryLevel() const;

private:
    int batteryLevel;
};

#endif // BATTERYMANAGER_HPP