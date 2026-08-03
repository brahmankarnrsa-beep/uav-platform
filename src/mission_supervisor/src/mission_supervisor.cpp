#include "mission_supervisor/mission_supervisor.hpp"

MissionSupervisor::MissionSupervisor()
: Node("mission_supervisor")
{
    state_sub_ =
        this->create_subscription<
            uav_interfaces::msg::VehicleState>(
                "vehicle/state",
                10,
                std::bind(
                    &MissionSupervisor::stateCallback,
                    this,
                    std::placeholders::_1));

    status_sub_ =
        this->create_subscription<
            uav_interfaces::msg::VehicleStatus>(
                "vehicle/status",
                10,
                std::bind(
                    &MissionSupervisor::statusCallback,
                    this,
                    std::placeholders::_1));
}

void MissionSupervisor::stateCallback(
    const uav_interfaces::msg::VehicleState::SharedPtr msg)
{
    RCLCPP_INFO(
        this->get_logger(),
        "State: %s",
        msg->state.c_str());
}

void MissionSupervisor::statusCallback(
    const uav_interfaces::msg::VehicleStatus::SharedPtr msg)
{
    RCLCPP_INFO(
        this->get_logger(),
        "Battery %.2f V | GPS %d | Mode %s",
        msg->battery_voltage,
        msg->gps_fix,
        msg->mode.c_str());
}
