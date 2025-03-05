#include <boost/asio.hpp>
#include "SensorData.hpp"
#include "Telemetry.hpp"
#include "MavlinkCommunication.hpp"
#include "WaypointNavigation.hpp"
#include "Main.hpp"

int main() {
    boost::asio::io_context io_context;

    SensorData sensor_data(io_context);
    Telemetry telemetry(io_context);
    MavlinkCommunication mavlink(io_context, "COM3", 57600);

    std::vector<Waypoint> waypoints = {
        {37.7749, -122.4194},
        {37.7849, -122.4294},
        {37.7949, -122.4394}
    };
    WaypointNavigation navigation(io_context, waypoints);

    sensor_data.start();
    telemetry.start();
    mavlink.start();
    navigation.start();

    std::cout << "UAV control system is running..." << std::endl;

    io_context.run();
    return 0;
}
