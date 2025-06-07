/**
 * @file PayloadManager.hpp
 * @brief Header file for the PayloadManager class.
 * This module ensures proper handling and deployment of payloads.
 */

#ifndef PAYLOADMANAGER_HPP
#define PAYLOADMANAGER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class PayloadManager {
public:
    explicit PayloadManager();
    ~PayloadManager();

    void start();
    void stop();

protected:
    // void loadPayload();
    // void unloadPayload();
    // void getPayloadStatus() const;

private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // PAYLOADMANAGER_HPP