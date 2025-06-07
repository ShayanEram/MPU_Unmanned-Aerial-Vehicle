#ifndef MOTORCONTROLLER_HPP
#define MOTORCONTROLLER_HPP

#include <thread>
#include <atomic>
#include <iostream>

class MotorController {
public:
    MotorController();
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