cmake_minimum_required(VERSION 3.8)
project(operational_state_engine)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(uav_interfaces REQUIRED)

include_directories(include)

add_executable(operational_state_engine_node
    src/operational_state_engine.cpp
    src/operational_state_engine_node.cpp
)

ament_target_dependencies(
    operational_state_engine_node
    rclcpp
    std_msgs
    uav_interfaces
)

install(TARGETS
    operational_state_engine_node
    DESTINATION lib/${PROJECT_NAME}
)

install(
    DIRECTORY launch
    DESTINATION share/${PROJECT_NAME}
)

install(
    DIRECTORY include/
    DESTINATION include
)

ament_package()
