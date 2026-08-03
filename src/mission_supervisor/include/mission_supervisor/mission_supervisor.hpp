#pragma once

#include <rclcpp/rclcpp.hpp>

#include <uav_interfaces/msg/vehicle_state.hpp>
#include <uav_interfaces/msg/vehicle_status.hpp>

class MissionSupervisor : public rclcpp::Node
{
public:
    MissionSupervisor();

private:
    void stateCallback(
        const uav_interfaces::msg::VehicleState::SharedPtr msg);

    void statusCallback(
        const uav_interfaces::msg::VehicleStatus::SharedPtr msg);

    rclcpp::Subscription<
        uav_interfaces::msg::VehicleState>::SharedPtr state_sub_;

    rclcpp::Subscription<
        uav_interfaces::msg::VehicleStatus>::SharedPtr status_sub_;
};
