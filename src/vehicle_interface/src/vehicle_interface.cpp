#include <chrono>
#include <functional>
#include "vehicle_interface/vehicle_interface.hpp"

using namespace std::chrono_literals;

VehicleInterface::VehicleInterface()
: Node("vehicle_interface")
{
    RCLCPP_INFO(
        this->get_logger(),
        "Vehicle Interface Node Started");

    vehicle_status_publisher_ =
        this->create_publisher<uav_interfaces::msg::VehicleStatus>(
            "vehicle/status",
            10);

    state_subscriber_ =
        this->create_subscription<mavros_msgs::msg::State>(
            "/mavros/state",
            10,
            std::bind(
                &VehicleInterface::stateCallback,
                this,
                std::placeholders::_1));

    battery_subscriber_ =
        this->create_subscription<sensor_msgs::msg::BatteryState>(
            "/mavros/battery",
            rclcpp::SensorDataQoS(),
            std::bind(
                &VehicleInterface::batteryCallback,
                this,
                std::placeholders::_1));

    gps_subscriber_ =
        this->create_subscription<sensor_msgs::msg::NavSatFix>(
            "/mavros/global_position/raw/fix",
            rclcpp::SensorDataQoS(),
            std::bind(
                &VehicleInterface::gpsCallback,
                this,
                std::placeholders::_1));

    imu_subscriber_ =
         this->create_subscription<sensor_msgs::msg::Imu>(
             "/mavros/imu/data",
             rclcpp::SensorDataQoS(),
             std::bind(
                 &VehicleInterface::imuCallback,
                 this,
                 std::placeholders::_1));

    publish_timer_ =
        this->create_wall_timer(
            50ms,
            std::bind(
                &VehicleInterface::publishVehicleStatus,
                this));

    mode_client_ =
        this->create_client<mavros_msgs::srv::SetMode>(
            "/mavros/set_mode");

    requestStreamRates();

    stream_retry_timer_ =
        this->create_wall_timer(
            std::chrono::seconds(5),
            std::bind(
                &VehicleInterface::requestStreamRates,
                this));
}

void VehicleInterface::publishVehicleStatus()
{
    uav_interfaces::msg::VehicleStatus msg;

    msg.connected = vehicle_state_.connected;

    msg.armed = vehicle_state_.armed;

    msg.mode = vehicle_state_.mode;

    msg.battery_voltage = vehicle_state_.battery_voltage;

    msg.latitude = vehicle_state_.latitude;

    msg.longitude = vehicle_state_.longitude;

    msg.altitude = vehicle_state_.altitude;

    msg.gps_fix = vehicle_state_.gps_fix;

    msg.ekf_ok = vehicle_state_.ekf_ok;

    vehicle_status_publisher_->publish(msg);
}

void VehicleInterface::stateCallback(
    const mavros_msgs::msg::State::SharedPtr msg)
{
    static bool was_connected = false;

    vehicle_state_.connected = msg->connected;
    vehicle_state_.armed = msg->armed;
    vehicle_state_.mode = msg->mode;

    if (!was_connected && msg->connected)
    {
        requestStreamRates();
    }

    was_connected = msg->connected;
}

void VehicleInterface::batteryCallback(
    const sensor_msgs::msg::BatteryState::SharedPtr msg)
{
    vehicle_state_.battery_voltage = msg->voltage;
}

void VehicleInterface::gpsCallback(
    const sensor_msgs::msg::NavSatFix::SharedPtr msg)
{
    vehicle_state_.latitude = msg->latitude;
    vehicle_state_.longitude = msg->longitude;
    vehicle_state_.altitude = msg->altitude;
    vehicle_state_.gps_fix = msg->status.status >= 0;
}

void VehicleInterface::imuCallback(
    const sensor_msgs::msg::Imu::SharedPtr)
{
    // IMU callback placeholder
}



void VehicleInterface::requestStreamRates()
{
    while (!stream_rate_client_->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_INFO(this->get_logger(),
                    "Waiting for MAVROS stream service...");
    }

    auto request =
        std::make_shared<mavros_msgs::srv::StreamRate::Request>();

    request->stream_id = 0;
    request->message_rate = 20;
    request->on_off = true;

    stream_rate_client_->async_send_request(request);

    RCLCPP_INFO(this->get_logger(),
                "Requested MAVLink stream rate.");
}
