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
// #include <afunix.h>
// #include <sys/types.h>
// #include <fcntl.h>
// #include <cstring>
// #include <winsock2.h>
// #include <windows.h>
// #include <ws2tcpip.h>

class RemoteController {
public:
    explicit RemoteController();
    ~RemoteController();
    void start();
    void stop();

protected:
    struct Command {
        float throttle;
        float yaw;
        float pitch;
        float roll;
        bool releasePayload;
    };

    void startConnection();
    void stopConnection();
    Command processCommand(const std::string& command);

    static constexpr int REMOTE_INTERVAL_CHECK_MS = 10;

    static constexpr const char* SOCKET_PATH = "/tmp/remote_controller_socket";
    bool _isConnected;
    //SOCKET  server_fd;
    bool _statusToSend;

private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // REMOTE_CONTROLLER_HPP