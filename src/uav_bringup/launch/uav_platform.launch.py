from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

import os


def generate_launch_description():

    mavros = Node(
        package="mavros",
        executable="mavros_node",
        namespace="mavros",
        output="screen",
        parameters=[
            {
                "fcu_url": "udp://0.0.0.0:14550@",
                "gcs_url": "",
                "tgt_system": 1,
                "tgt_component": 1,
                "fcu_protocol": "v2.0",
            },
            os.path.join(
                get_package_share_directory("mavros"),
                "launch",
                "apm_pluginlists.yaml"
            ),
            os.path.join(
                get_package_share_directory("mavros"),
                "launch",
                "apm_config.yaml"
            ),
        ]
    )

    vehicle_interface = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("vehicle_interface"),
                "launch",
                "vehicle_interface.launch.py"
            )
        )
    )

    operational_state_engine = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("operational_state_engine"),
                "launch",
                "operational_state_engine.launch.py"
            )
        )
    )

    mission_supervisor = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("mission_supervisor"),
                "launch",
                "mission_supervisor.launch.py"
            )
        )
    )

    return LaunchDescription([
        mavros,
        vehicle_interface,
        operational_state_engine,
        mission_supervisor
    ])
