#ifndef WAYPOINTNAVIGATION_HPP
#define WAYPOINTNAVIGATION_HPP

#include <boost/asio.hpp>
#include <vector>

struct Waypoint {
    double latitude;
    double longitude;
};

class WaypointNavigation {
public:
    WaypointNavigation(boost::asio::io_context& io_context, const std::vector<Waypoint>& waypoints);
    void start();

private:
    void navigate_to_waypoints(const boost::system::error_code& ec);

    boost::asio::steady_timer waypoint_timer_;
    std::vector<Waypoint> waypoints_;
    std::vector<Waypoint>::iterator current_waypoint_;
};

#endif // WAYPOINTNAVIGATION_H
