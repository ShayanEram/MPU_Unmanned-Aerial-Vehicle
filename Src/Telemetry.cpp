#include "Telemetry.hpp"
#include <iostream>

Telemetry::Telemetry(boost::asio::io_context& io_context)
    : telemetry_timer_(io_context, std::chrono::seconds(1)) {}

void Telemetry::start() {
    telemetry_timer_.async_wait(std::bind(&Telemetry::receive_telemetry, this, std::placeholders::_1));
}

void Telemetry::receive_telemetry(const boost::system::error_code& ec) {
    if (!ec) {
        double battery_level = 85.0;
        std::cout << "Telemetry Data - Battery Level: " << battery_level << "%" << std::endl;
        telemetry_timer_.expires_after(std::chrono::seconds(1));
        telemetry_timer_.async_wait(std::bind(&Telemetry::receive_telemetry, this, std::placeholders::_1));
    }
}
