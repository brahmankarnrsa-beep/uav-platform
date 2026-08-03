#pragma once

#include <rclcpp/rclcpp.hpp>

#include <uav_interfaces/msg/vehicle_status.hpp>
#include <uav_interfaces/msg/vehicle_state.hpp>

class OperationalStateEngine : public rclcpp::Node
{
public:
    OperationalStateEngine();

private:

    void vehicleStatusCallback(
        const uav_interfaces::msg::VehicleStatus::SharedPtr msg);

    rclcpp::Subscription<
        uav_interfaces::msg::VehicleStatus>::SharedPtr
            vehicle_status_sub_;

    rclcpp::Publisher<
        uav_interfaces::msg::VehicleState>::SharedPtr
            state_pub_;
};
