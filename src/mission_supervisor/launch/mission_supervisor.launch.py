from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([
        Node(
            package='mission_supervisor',
            executable='mission_supervisor_node',
            name='mission_supervisor',
            output='screen'
        )
    ])
