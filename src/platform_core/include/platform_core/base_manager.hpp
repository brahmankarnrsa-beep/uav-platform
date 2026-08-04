#pragma once

#include <chrono>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include "platform_core/parameter_manager.hpp"

class BaseManager : public rclcpp::Node
{
public:
    explicit BaseManager(const std::string& node_name);

    virtual ~BaseManager() = default;

protected:

    virtual bool initialize() = 0;

    virtual void update() = 0;

    virtual void shutdown() = 0;

    void start();

    rclcpp::TimerBase::SharedPtr update_timer_;

    std::shared_ptr<ParameterManager> parameters_;

private:

    void timerCallback();
};
