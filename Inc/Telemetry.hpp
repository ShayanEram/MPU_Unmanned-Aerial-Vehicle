#ifndef TELEMETRY_HPP
#define TELEMETRY_HPP

#include <boost/asio.hpp>

class Telemetry {
public:
    Telemetry(boost::asio::io_context& io_context);
    void start();

private:
    void receive_telemetry(const boost::system::error_code& ec);

    boost::asio::steady_timer telemetry_timer_;
};

#endif // TELEMETRY_H
