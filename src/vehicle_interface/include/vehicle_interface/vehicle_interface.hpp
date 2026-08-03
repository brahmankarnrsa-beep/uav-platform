#ifndef VEHICLE_INTERFACE_HPP
#define VEHICLE_INTERFACE_HPP

#include <string>

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/float64.hpp"

#include "sensor_msgs/msg/battery_state.hpp"

#include "sensor_msgs/msg/nav_sat_fix.hpp"

#include "sensor_msgs/msg/imu.hpp"

#include "mavros_msgs/msg/state.hpp"

#include "mavros_msgs/srv/stream_rate.hpp"

#include "uav_interfaces/msg/vehicle_status.hpp"

class VehicleInterface : public rclcpp::Node
{
public:
    VehicleInterface();

private:

    void stateCallback(
        const mavros_msgs::msg::State::SharedPtr msg);

    void batteryCallback(
        const sensor_msgs::msg::BatteryState::SharedPtr msg);

    void gpsCallback(
        const sensor_msgs::msg::NavSatFix::SharedPtr msg);

    void imuCallback(
        const sensor_msgs::msg::Imu::SharedPtr msg);

    struct VehicleStateCache
    {
        bool connected = false;
        bool armed = false;
        std::string mode = "";

        float battery_voltage = 0.0f;

        double latitude = 0.0;
        double longitude = 0.0;
        float altitude = 0.0f;

        uint8_t gps_fix = 0;
        bool ekf_ok = false;

        float roll = 0.0f;
        float pitch = 0.0f;
        float yaw = 0.0f;

        float vx = 0.0f;
        float vy = 0.0f;
        float vz = 0.0f;
    };

    VehicleStateCache vehicle_state_;

    void publishVehicleStatus();

    rclcpp::TimerBase::SharedPtr publish_timer_;

    rclcpp::Publisher<uav_interfaces::msg::VehicleStatus>::SharedPtr
        vehicle_status_publisher_;

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr
        state_subscriber_;

    rclcpp::Subscription<sensor_msgs::msg::BatteryState>::SharedPtr
        battery_subscriber_;

    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr
        gps_subscriber_;

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr
        imu_subscriber_;

    rclcpp::Client<mavros_msgs::srv::StreamRate>::SharedPtr
        stream_rate_client_;

    rclcpp::TimerBase::SharedPtr stream_retry_timer_;

    void requestStreamRates();

};

#endif
