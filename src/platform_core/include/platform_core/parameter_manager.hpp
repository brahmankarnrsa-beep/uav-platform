#pragma once

#include <string>

#include <rclcpp/rclcpp.hpp>

class ParameterManager
{
public:
    explicit ParameterManager(rclcpp::Node* node);

    template<typename T>
    T get(const std::string& name)
    {
        T value{};
        node_->get_parameter(name, value);
        return value;
    }

    template<typename T>
    void declare(
        const std::string& name,
        const T& default_value)
    {
        node_->declare_parameter<T>(
            name,
            default_value);
    }

private:
    rclcpp::Node* node_;
};
