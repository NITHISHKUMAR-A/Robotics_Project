TELEPHO BASED ROS2 BOT WITH MICROROS INTEGRATION ⚙️🤖

	This project demonstrates the integration of micro-ROS on ESP32 with ROS2 Humble to build a WiFi-enabled mobile robot. The system provides real-time velocity control and odometry feedback, forming a reliable base for future autonomous navigation work.

Project Summary

	The robot operates as a ROS2-compliant platform. An ESP32 board runs a micro-ROS client that communicates with the ROS2 environment over WiFi. Motion commands are transmitted via the /cmd_vel topic, and encoder feedback is published as /odom. This setup allows the robot to be controlled using standard ROS2 tools such as teleop_twist_keyboard.

System Architecture

	ESP32 (micro-ROS Client Layer) - Implements WiFi-based micro-ROS
	transport (UDP) - Subscribes to: /cmd_vel - Publishes: /odom -
	Handles: - Motor driver interface (BTS7960) - Encoder signal reading -
	Firmware written in C using PlatformIO

	ROS2 Host (Control Layer) - Runs the micro-ROS Agent - Uses: -
	teleop_twist_keyboard → manual control - rqt_graph, rqt_plot →
	diagnostics - No custom ROS2 nodes used in this version

	Communication Protocol: WiFi UDP Example agent command: ros2 run
	micro_ros_agent micro_ros_agent udp4 –port 8888

Hardware Overview

	Motors: 12V Johnson Encoder Motor (300 RPM) Motor Driver: BTS7960
	High-Power Driver Controller: ESP32 Development Board Power: 12V Battery
	Pack Others: Terminal splitter, wiring, chassis

Software Setup

	1.  ESP32 Firmware Developed using PlatformIO (VS Code), including:

	-   micro-ROS integration
	-   WiFi configuration
	-   Motor control logic
	-   Encoder feedback
	-   /cmd_vel subscriber + /odom publisher

	2.  ROS2 Humble Environment Install micro-ROS agent: sudo apt install
	    ros-humble-micro-ros-agent

	Start agent: ros2 run micro_ros_agent micro_ros_agent udp4 –port 8888

	Install teleop: sudo apt install ros-humble-teleop-twist-keyboard

	Start control: ros2 run teleop_twist_keyboard teleop_twist_keyboard

Topics

	/cmd_vel: ROS2 → ESP32 (Velocity commands) /odom: ESP32 → ROS2
	(Encoder-based odometry)

Repository Structure

	TELEPHO-ROS2-BOT/ │── firmware/ │── docs/ │── launch/ │── README.md │──
	LICENSE



Future Development - Add LiDAR for SLAM - Integrate Raspberry Pi for
onboard processing - Build a fully autonomous navigation stack (Nav2) -
Implement obstacle detection & mapping

		Author Nithish Kumar A Robotics Enthusiast
