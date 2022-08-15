## CARMINE

The official repo of CARMINE: ContAinerized Ros MonItors geNEration.

<img src="icon.png" alt="drawing" width="200"/>

## Table of contents

[Project info](#project-info)

[Quick start](#quick-start)
1. [Install dependencies](#dependencies)
2. [Build the project](#build-the-project)

[Optional arguments](#optional-arguments)

## Project info

This tool can be used to automatically generate a ROS-based verification environment from LTL properties.

# Quick start

For now, we support only Linux and Mac OS (both x86 and arm64) with gcc (c++17) and cmake 3.14+.

## Dependencies
* [spotLTL](https://spot.lrde.epita.fr/install.html)
* [antlr4-runtime](https://www.antlr.org)

* Install all the dependencies manually or simply run the commands below.


```
sudo apt-get install -y uuid-dev pkg-config
```

* Install all dependencies in the local repository (all the dependencies will be compiled from the source);

```
cd third_party
bash install_all.sh
```


## Build the project

```
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```


# How to use the tool  
Carmine has one main input, a configuration file containing the LTL properties.
The user can find several input examples in the 'input' directory

## Generating the verification environment

Run the following command in the root directory of carmine:

```
./generate_env.sh specifications.xml
```

This will create the 'ver_env' catkin project inside the output directory

## The specification file
We report hereafter an example of a specification file.

 ```xml
<handler>

    <monitor name="Monitor0" description="An example" LTLformula="G({(var1)[->1]:1}|=>{$timeout(var2==0,2000)})">
        <variable decl="bool var1">
            <rosTopic>joint_states</rosTopic>
            <msgType>sensor_msgs::JointState</msgType>
            <msgField>start</msgField>
        </variable>
        <variable decl="double var2">
            <rosTopic>joint_states</rosTopic>
            <msgType>sensor_msgs::JointState</msgType>
            <msgField>speed</msgField>
            <filter window="10">ma</filter>
        </variable>
    </monitor>

</handler>
```

* All specification files must start with a 'handler' tag
* The user can define many 'monitor' tags containing the specifications of a monitor 
   - 'name' will become the name of the monitor (WARNING: the tool will use this parameter to generate code, make sure to use legal characters)
   - 'description' is used only for debugging purposes
   - 'LTLformula' temporal assertion that will be synthesized (it uses the variables declared in the 'decl' tags, check the grammar at src/antlr4/PSLParser/grammar/temporal.g4)
* 'variable' contains a declaration of variables used in the 'LTLformula'
  - 'decl' is a c++ style variable declaration, this is just an alias for the real variable, which is the field of a ros topic (the alias is necessary to ensure the readability of the formula as topic names can be extremely long)
* 'rosTopic' is the name of the ros topic containing the required variables
* 'msgType' the c++ type of the ros message received from topic 'rosTopic' (this is necessary as in c++ types must be known at compile time)
* 'msgField' is the field of the message received from the topic (this is the actual variable, its type must be the same as the one declared in 'decl')
* 'filter' is an optional tag to filter the values of the variable defined in 'msgField' (usefull for floating point types), for now, only one type of filter is available: moving average (ma)
    - 'window' is the length of the moving average window



# How to use the generated verification environment

The generated verification environment contained in 'ver_env' is a simple catkin project that can be compiled
following the usual ros/catkin chain.
WARNING: when compiling, 'ver_env' must know where to find the code (headers and definition) of the topics used by the verification environment

##  How to run the verification environment
Simply run the executable:

```
./devel/lib/ver_env/ver_env_node --disableNotifications --milpUsageThreshold 0.9 --milpResponsivnessThreshold 0 --topicPrefix robot/ __name:="unique_name_of_the_handler"
```

Alternatively, you can use a Ros launch file.

##  Mandatory arguments

* \_\_name:="unique_name_of_the_handler"

##  Optional arguments

* \-\-milpUsageThreshold : a float value (percentage value between 0 and 1) specifying the maximum allowed cpu usage on this running machine
* \-\-milpResponsivnessThreshold : an interger value specifying the maximum allowed delay (in milliseconds) for receiving the values from the topics
* \-\-disableMigration: it disables the migration of monitors
* \-\-disableNotifications: it disables notifications, such as a monitor failure
* \-\-topicPrefix: adds a prefix to the name of used topics


