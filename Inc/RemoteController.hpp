#ifndef REMOTE_CONTROLLER_HPP
#define REMOTE_CONTROLLER_HPP

class RemoteController {
public:
    RemoteController();
    ~RemoteController();

    void connect();
    void disconnect();
    void sendCommand();

private:
    bool isConnected;
};

#endif // REMOTE_CONTROLLER_HPP