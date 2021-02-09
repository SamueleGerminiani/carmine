# CARMINE: ContAinerized Ros MonItors geNEration
This tool can be used to automatically generate a ROS-based verification environment for LTL properties.

## Usage
1. Create a XML specification file (see specification.xml for an example)
2. `chmod +x generate_env.sh`
2. Launch `./generate_env.sh <specification_file.xml>`
3. Copy the **verification_env** directory inside the src directory of a valid catkin workspace 
4. To compile the package launch `catkin_make --pkg verification_env`
5. `source devel/setup.bash`
6. To run the node use `rosrun verification_env verification_env_node`
