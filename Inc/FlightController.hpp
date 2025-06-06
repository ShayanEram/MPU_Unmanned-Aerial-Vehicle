#ifndef FLIGHTCONTROLLER_HPP
#define FLIGHTCONTROLLER_HPP

class FlightController {
public:
    FlightController();
    ~FlightController();

    void initialize();
    void update();
    void setAltitude(float altitude);
    float getAltitude() const;

private:
    float altitude;
};

#endif // FLIGHTCONTROLLER_HPP