#include "operational_state_engine/operational_state_engine.hpp"

OperationalStateEngine::OperationalStateEngine()
: Node("operational_state_engine")
{
    vehicle_status_sub_ =
        this->create_subscription<uav_interfaces::msg::VehicleStatus>(
            "vehicle/status",
            10,
            std::bind(
                &OperationalStateEngine::vehicleStatusCallback,
                this,
                std::placeholders::_1));

    state_sub_ =
        this->create_subscription<uav_interfaces::msg::VehicleStatus>(
            "vehicle/status",
            10,
            std::bind(
                &OperationalStateEngine::vehicleStatusCallback,
                this,
                std::placeholders::_1));

    state_pub_ =
        this->create_publisher<uav_interfaces::msg::VehicleState>(
            "vehicle/state",
            10);
}

void OperationalStateEngine::vehicleStatusCallback(
    const uav_interfaces::msg::VehicleStatus::SharedPtr msg)
{
    auto state = uav_interfaces::msg::VehicleState();

    if (!msg->connected)
        state.state = "NO_FC";
    else if (!msg->gps_fix)
        state.state = "WAITING_GPS";
    else
        state.state = "READY";

    state_pub_->publish(state);
}
