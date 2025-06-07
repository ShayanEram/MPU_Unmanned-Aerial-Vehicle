/**
 * @file RemoteController.hpp
 * @brief Header file for the RemoteController class.
 * Remote control via radio signals, Wi-Fi, or satellite links.
 */

#ifndef REMOTE_CONTROLLER_HPP
#define REMOTE_CONTROLLER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class RemoteController {
public:
    explicit RemoteController();
    ~RemoteController();

    void start();
    void stop();

protected:
    // void connect();
    // void disconnect();
    // void sendCommand();
    bool isConnected;

private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // REMOTE_CONTROLLER_HPP