#include "SensorData.hpp"
#include <iostream>

SensorData::SensorData(boost::asio::io_context& io_context)
    : gps_timer_(io_context, std::chrono::seconds(1)), imu_timer_(io_context, std::chrono::seconds(1)) {}

void SensorData::start() {
    gps_timer_.async_wait(std::bind(&SensorData::read_gps_data, this, std::placeholders::_1));
    imu_timer_.async_wait(std::bind(&SensorData::read_imu_data, this, std::placeholders::_1));
}

void SensorData::read_gps_data(const boost::system::error_code& ec) {
    if (!ec) {
        double latitude = 37.7749;
        double longitude = -122.4194;
        std::cout << "GPS Data - Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
        gps_timer_.expires_after(std::chrono::seconds(1));
        gps_timer_.async_wait(std::bind(&SensorData::read_gps_data, this, std::placeholders::_1));
    }
}

void SensorData::read_imu_data(const boost::system::error_code& ec) {
    if (!ec) {
        double roll = 1.0, pitch = 0.5, yaw = -0.2;
        std::cout << "IMU Data - Roll: " << roll << ", Pitch: " << pitch << ", Yaw: " << yaw << std::endl;
        imu_timer_.expires_after(std::chrono::seconds(1));
        imu_timer_.async_wait(std::bind(&SensorData::read_imu_data, this, std::placeholders::_1));
    }
}
