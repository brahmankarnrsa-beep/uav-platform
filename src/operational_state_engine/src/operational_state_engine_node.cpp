#include "operational_state_engine/operational_state_engine.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OperationalStateEngine>());
    rclcpp::shutdown();
    return 0;
}
