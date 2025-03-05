#include "MavlinkCommunication.hpp"
#include <iostream>

MavlinkCommunication::MavlinkCommunication(boost::asio::io_context& io_context, const std::string& port, unsigned int baud_rate)
    : serial_port_(io_context) {
    serial_port_.open(port);
    serial_port_.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
}

void MavlinkCommunication::start() {
    serial_port_.async_read_some(boost::asio::buffer(buffer_, MAVLINK_MAX_PACKET_LEN),
                                 std::bind(&MavlinkCommunication::receive_mavlink_message, this,
                                           std::placeholders::_1, std::placeholders::_2));
}

void MavlinkCommunication::receive_mavlink_message(const boost::system::error_code& ec, std::size_t bytes_transferred) {
    if (!ec) {
        mavlink_message_t msg;
        mavlink_status_t status;
        if (mavlink_parse_char(MAVLINK_COMM_0, buffer_[0], &msg, &status)) {
            std::cout << "Received MAVLink message with ID: " << msg.msgid << std::endl;
        }
        serial_port_.async_read_some(boost::asio::buffer(buffer_, MAVLINK_MAX_PACKET_LEN),
                                     std::bind(&MavlinkCommunication::receive_mavlink_message, this,
                                               std::placeholders::_1, std::placeholders::_2));
    }
}
