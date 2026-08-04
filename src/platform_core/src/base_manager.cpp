#include "platform_core/base_manager.hpp"

using namespace std::chrono_literals;

BaseManager::BaseManager(const std::string& node_name)
: Node(node_name)
{
    parameters_ =
        std::make_shared<ParameterManager>(this);
}

void BaseManager::start()
{
    if (!initialize())
    {
        RCLCPP_FATAL(
            this->get_logger(),
            "Initialization failed.");

        rclcpp::shutdown();
        return;
    }

    update_timer_ =
        this->create_wall_timer(
            100ms,
            std::bind(
                &BaseManager::timerCallback,
                this));

    RCLCPP_INFO(
        this->get_logger(),
        "Manager started.");
}

void BaseManager::timerCallback()
{
    update();
}
