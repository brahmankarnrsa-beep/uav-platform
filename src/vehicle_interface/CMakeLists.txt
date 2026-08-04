cmake_minimum_required(VERSION 3.8)
project(platform_core)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_library(platform_core SHARED
  src/base_manager.cpp
)

target_include_directories(platform_core PUBLIC
  include
)

ament_target_dependencies(platform_core
  rclcpp
)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS platform_core
  EXPORT export_platform_core
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_export_targets(export_platform_core HAS_LIBRARY_TARGET)
ament_export_include_directories(include)
ament_export_dependencies(rclcpp)

ament_package()
