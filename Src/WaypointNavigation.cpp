#include "WaypointNavigation.hpp"
#include <iostream>

WaypointNavigation::WaypointNavigation(boost::asio::io_context& io_context, const std::vector<Waypoint>& waypoints)
    : waypoint_timer_(io_context, std::chrono::seconds(1)), waypoints_(waypoints), current_waypoint_(waypoints_.begin()) {}

void WaypointNavigation::start() {
    waypoint_timer_.async_wait(std::bind(&WaypointNavigation::navigate_to_waypoints, this, std::placeholders::_1));
}

void WaypointNavigation::navigate_to_waypoints(const boost::system::error_code& ec) {
    if (!ec && current_waypoint_ != waypoints_.end()) {
        std::cout << "Navigating to waypoint - Latitude: " << current_waypoint_->latitude
                  << ", Longitude: " << current_waypoint_->longitude << std::endl;
        waypoint_timer_.expires_after(std::chrono::seconds(5));
        waypoint_timer_.async_wait(std::bind(&WaypointNavigation::navigate_to_waypoints, this, std::placeholders::_1));
        ++current_waypoint_;
    }
}
