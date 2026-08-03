#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "vehicle_interface/vehicle_interface.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<VehicleInterface>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
