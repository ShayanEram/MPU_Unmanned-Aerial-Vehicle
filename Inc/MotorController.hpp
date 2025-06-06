#ifndef MOTORCONTROLLER_HPP
#define MOTORCONTROLLER_HPP

class MotorController {
public:
    MotorController();
    ~MotorController();

    void initialize();
    void setSpeed(int speed);
    int getSpeed() const;

private:
    int currentSpeed;
};

#endif // MOTORCONTROLLER_HPP