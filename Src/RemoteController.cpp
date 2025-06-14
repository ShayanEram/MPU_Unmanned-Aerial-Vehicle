#include "RemoteController.hpp"
#include <string>

RemoteController::RemoteController() : running(false) {
    _isConnected = false;
}
RemoteController::~RemoteController() {
    stop();
}
//------------------------------------------------------------------------------------
void RemoteController::start() {
    if (!running.load()) {
        running.store(true);
        moduleThread = std::thread(&RemoteController::runLoop, this);
    }
}
void RemoteController::stop() {
    if (running.load()) {
        running.store(false);
        if (moduleThread.joinable()) {
            moduleThread.join();
        }
    }
}
//------------------------------------------------------------------------------------
void RemoteController::runLoop() {
    Command command = {0.0f, 0.0f, 0.0f, 0.0f, false};
    
    while (running.load()) 
    {
        // SOCKET client_fd = accept(server_fd, nullptr, nullptr);
        // if (client_fd < 0) {
        //     perror("Client connection failed");
        //     continue;
        // }

        // char buffer[256] = {0};
        // int bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        // if (bytes_read > 0) {
        //     buffer[bytes_read] = '\0';
        //     std::cout << "Received command: " << buffer << std::endl;

        //     // Process commands
        //     command = processCommand(buffer);
            
        //     if(_statusToSend)
        //     {
        //         std::string response = "Drone status: Operational\n";
        //         send(client_fd, response.c_str(), static_cast<int>(response.length()), 0);
        //     }
        // }
        std::this_thread::sleep_for(std::chrono::milliseconds(REMOTE_INTERVAL_CHECK_MS));
        std::cout << "RemoteController running..." << std::endl;
    }
    stopConnection();
}
//------------------------------------------------------------------------------------
void RemoteController::startConnection()
{   
    // WSADATA wsa_data;
    // if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
    //     std::cerr << "WSAStartup failed!" << std::endl;
    //     return;
    // }

    // // Create Unix domain socket
    // server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    // if (server_fd == INVALID_SOCKET) {
    //     perror("Socket creation failed");
    //     return;
    // }

    // SOCKADDR_UN server_addr{};
    // server_addr.sun_family = AF_UNIX;
    // strncpy_s(server_addr.sun_path, sizeof(server_addr.sun_path), SOCKET_PATH, _TRUNCATE);

    // // Bind the socket
    // remove(SOCKET_PATH);  // Ensure no previous socket file exists
    // if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
    //     std::cerr << "Socket bind failed: " << WSAGetLastError() << std::endl;
    //     return;
    // }

    // // Start listening
    // if (listen(server_fd, SOMAXCONN) == SOCKET_ERROR) {
    //     std::cerr << "Socket listen failed: " << WSAGetLastError() << std::endl;
    //     return;
    // }

    std::cout << "Drone server started, waiting for commands..." << std::endl;
}
void RemoteController::stopConnection()
{
    // if (server_fd != INVALID_SOCKET) {
    //     closesocket(server_fd);
    //     DeleteFileA(SOCKET_PATH);  // Cleanup socket file
    //     WSACleanup();
    //     std::cout << "Drone server stopped." << std::endl;
    // }
}
RemoteController::Command RemoteController::processCommand(const std::string& command)
{
    Command cmd = {0.0f, 0.0f, 0.0f, 0.0f, false};

    // Parse the command string
    if (command.find("throttle") != std::string::npos) {
        cmd.throttle = std::stof(command.substr(command.find("=") + 1));
    }
    if (command.find("yaw") != std::string::npos) {
        cmd.yaw = std::stof(command.substr(command.find("=") + 1));
    }
    if (command.find("pitch") != std::string::npos) {
        cmd.pitch = std::stof(command.substr(command.find("=") + 1));
    }
    if (command.find("roll") != std::string::npos) {
        cmd.roll = std::stof(command.substr(command.find("=") + 1));
    }
    if (command.find("releasePayload") != std::string::npos) {
        cmd.releasePayload = command.find("true") != std::string::npos;
    }
    return cmd;
}