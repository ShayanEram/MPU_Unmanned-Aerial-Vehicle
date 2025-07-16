#include <gtest/gtest.h>
#include "TelemetryManager.hpp"
#include "Observer.hpp"

class TestableTelemetryManager : public TelemetryManager {
public:
    using TelemetryManager::TelemetryManager;
    using TelemetryManager::updateTelemetryData;
    using TelemetryManager::_telemetryPacket;
};

TEST(TelemetryManagerTest, UpdateTelemetryDataSetsPacket) {
    Observer<SensorData> dummyObserver;
    TestableTelemetryManager manager(dummyObserver);

    manager.updateTelemetryData();
    EXPECT_FALSE(manager._telemetryPacket.empty());
}