#ifndef SENSORDATA_HPP
#define SENSORDATA_HPP

#include <boost/asio.hpp>

class SensorData {
public:
    SensorData(boost::asio::io_context& io_context);
    void start();

private:
    void read_gps_data(const boost::system::error_code& ec);
    void read_imu_data(const boost::system::error_code& ec);

    boost::asio::steady_timer gps_timer_;
    boost::asio::steady_timer imu_timer_;
};

#endif // SENSORDATA_H
