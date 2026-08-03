from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([
        Node(
            package='operational_state_engine',
            executable='operational_state_engine_node',
            output='screen'
        )
    ])
