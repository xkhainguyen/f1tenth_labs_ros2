import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    params = os.path.join(
        get_package_share_directory('lab1_pkg'),
        'config',
        'params.yaml'
        )

    talker_node = Node(
        package='lab1_pkg',
        executable='talker',  # no need .cpp
        # parameters=[
        #     {'v': 1.5},
        #     {'d': 9.1}
        # ],
        parameters=[params]  # import from .yaml
        # name='talker'  # will overide name
        # output='screen',
        # emulate_tty=True
    )
    
    relay_node = Node(
        package='lab1_pkg',  # if other packages then need <depend>
        executable='relay.py',  # need .py for /scripts
        # name='relay2'  # will overide name
    )
    
    ld.add_action(talker_node)
    ld.add_action(relay_node)

    return ld