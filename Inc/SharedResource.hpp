#ifndef SHARED_RESOURCE_HPP
#define SHARED_RESOURCE_HPP

#include <mutex>

class SharedResource {
public:
    struct DroneData {
        double latitude;
        double longitude;
        double altitude;
    };

    void setData(DroneData data) {
        std::lock_guard<std::mutex> lock(resourceMutex);
        droneData = data;
    }

    DroneData getData() {
        std::lock_guard<std::mutex> lock(resourceMutex);
        return droneData;
    }

private:
    DroneData droneData;
    std::mutex resourceMutex;
};

#endif // SHARED_RESOURCE_HPP