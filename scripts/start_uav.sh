#!/bin/bash

cd /uav_ws

source /opt/ros/humble/setup.bash
source /uav_ws/install/setup.bash

while true
do
    echo "======================================"
    echo "Starting UAV Platform..."
    echo "======================================"

    ros2 launch uav_bringup uav_platform.launch.py

    echo ""
    echo "Launch exited. Restarting in 3 seconds..."
    sleep 3
done
