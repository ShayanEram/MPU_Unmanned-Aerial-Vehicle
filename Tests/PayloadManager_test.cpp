#include <gtest/gtest.h>
#include "PayloadManager.hpp"
#include "Observer.hpp"

class TestablePayloadManager : public PayloadManager {
public:
    using PayloadManager::PayloadManager;
    using PayloadManager::getPayloadStatus;
    using PayloadManager::PayloadState;
};

TEST(PayloadManagerTest, GetPayloadStatusReturnsErrorByDefault) {
    Observer<PayloadData> dummyObserver;
    TestablePayloadManager manager(dummyObserver);

    // By default, readGPIO will return -1 (as implemented in PayloadManager)
    auto status = manager.getPayloadStatus();
    EXPECT_EQ(status, TestablePayloadManager::PayloadState::ERROR);
}