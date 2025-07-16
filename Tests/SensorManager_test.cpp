#include <gtest/gtest.h>
#include "SensorManager.hpp"
#include "MessageQueue.hpp"
#include "Observer.hpp"

class TestableSensorManager : public SensorManager {
public:
    using SensorManager::SensorManager;
    using SensorManager::readGPSData;
};

TEST(SensorManagerTest, ReadGPSDataCallable) {
    MessageQueue<SensorData> dummyQueue;
    Observer<SensorData> dummyObserver;
    TestableSensorManager manager(dummyQueue, dummyObserver);

    EXPECT_NO_THROW(manager.readGPSData());
}