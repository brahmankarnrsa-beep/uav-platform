from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([
        Node(
            package='vehicle_interface',
            executable='vehicle_interface_node',
            name='vehicle_interface',
            output='screen',
            parameters=[
                {
                    'heartbeat_period': 1.0
                }
            ]
        )
    ])
