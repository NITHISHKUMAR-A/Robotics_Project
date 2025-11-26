
 <===================================== DOCUMENTS ======================================>
   
   <===/////////////////////////  INTRUCTION FOR SIMULATION /////////////////////////////===>
  
  
~> STEP 1 [Open Terminal ]
  
~> STEP2 [ Use the Below CMD in Terminal ]
 
  CMD = "cd scropy_ws/"  (avoid "" use only inside CMD)
  
  press Enter 
  
~> STEP 3 [Split the Terminal into Four screen ]

~> STEP 4 [use below Cmd on all four screen]

  CMD =  "source install/setup.bash " (avoid "" use only inside CMD)
 
  press enter

~> STEP 5  [ Below cmd for start simulation in ros2 ] and [Run the below comments as per order give below ]

 ## STEP 5.1
 
         <----------  RUN RVIZ  ----------->
 
  CMD = "ros2 launch scropy rsp.launch.py use_sim_time:=true"  (avoid "" use only inside CMD)
  
 ## STEP 5.2
         <---------  RUN GAZEBO  ------>

  CMD = "ros2 launch scropy launch_sim.launch.py  use_sim_time:=true"  (avoid "" use only inside CMD)
  
  press enter

 ## STEP 5.3 [ Use this CMD if need otherwise skip it ]

         <-------------  RUN TELPHO KEY FOR GAZEBO_CONTROLLER  ---------------->

  CMD = "ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args --remap /cmd_vel:=/diff_drive_controller/cmd_vel_unstamped"  (avoid "" use only inside CMD)
  
 ## STEP 5.4

         <-------------  RUN SLAMTOOL_BOX FOR LOCALIZATION(map spawn )  --------------------->

  CMD = "ros2 launch slam_toolbox online_async_launch.py slam_params_file:=./src/scropy/config/mapper_params_online_async.yaml  use_sim_time:=true"  (avoid "" use only inside CMD)
  
 ## STEP 5.5

         <----------  RUN NAV2 -----------> 

  CMD = "ros2 launch scropy navigation.launch.py use_sim_time:=true"  (avoid "" use only inside CMD)



 

 
 
