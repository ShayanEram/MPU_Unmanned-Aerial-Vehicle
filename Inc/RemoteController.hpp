#ifndef REMOTE_CONTROLLER_HPP
#define REMOTE_CONTROLLER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class RemoteController {
public:
    RemoteController();
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