#include "RemoteController.hpp"

RemoteController::RemoteController() : running(false) {
    isConnected = false;
}

RemoteController::~RemoteController() {
    stop();
}

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

void RemoteController::runLoop() {
    while (running.load()) {

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work

        std::cout << "RemoteController running..." << std::endl;

    }
}