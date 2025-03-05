#ifndef MAVLINKCOMMUNICATION_HPP
#define MAVLINKCOMMUNICATION_HPP

#include <boost/asio.hpp>
#include <mavlink.h>

class MavlinkCommunication {
public:
    MavlinkCommunication(boost::asio::io_context& io_context, const std::string& port, unsigned int baud_rate);
    void start();

private:
    void receive_mavlink_message(const boost::system::error_code& ec, std::size_t bytes_transferred);

    boost::asio::serial_port serial_port_;
    uint8_t buffer_[MAVLINK_MAX_PACKET_LEN];
};

#endif // MAVLINKCOMMUNICATION_H
