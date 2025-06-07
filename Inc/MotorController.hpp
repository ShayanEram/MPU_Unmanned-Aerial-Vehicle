/**
 * @file MotorController.hpp
 * @brief Header file for the MotorController class.
 * Manages speed and direction of motors.
 */

#ifndef MOTORCONTROLLER_HPP
#define MOTORCONTROLLER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class MotorController {
public:
    explicit MotorController();
    ~MotorController();

    void start();
    void stop();

protected:
    // void setSpeed(int speed);
    // int getSpeed() const;
    int currentSpeed;

private:
    void runLoop();
    std::thread moduleThread;
    std::atomic<bool> running;
};

#endif // MOTORCONTROLLER_HPP