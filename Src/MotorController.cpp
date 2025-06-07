#include "MotorController.hpp"

MotorController::MotorController() : running(false) {
    currentSpeed = 0; // Initialize current speed
}

MotorController::~MotorController() {
    stop();
}

void MotorController::start() {
    if (!running.load()) {
        running.store(true);
        moduleThread = std::thread(&MotorController::runLoop, this);
    }
}

void MotorController::stop() {
    if (running.load()) {
        running.store(false);
        if (moduleThread.joinable()) {
            moduleThread.join();
        }
    }
}

void MotorController::runLoop() {
    while (running.load()) {
        // Simulate motor control logic
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Current Speed: " << currentSpeed << std::endl;

        std::cout << "MotorController running... Speed: " << currentSpeed << std::endl;
    }
}