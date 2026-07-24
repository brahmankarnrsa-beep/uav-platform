#include <memory>

#include "rclcpp/rclcpp.hpp"

class VehicleInterfaceNode : public rclcpp::Node
{
public:
    VehicleInterfaceNode()
    : Node("vehicle_interface")
    {
        RCLCPP_INFO(this->get_logger(),
                    "Vehicle Interface Node Started");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<VehicleInterfaceNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
