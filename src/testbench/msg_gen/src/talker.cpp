// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "msg_gen/Num.h"
int main(int argc, char **argv) {
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	ros::Publisher chatter_pub2 =
	    n.advertise<msg_gen::Num>("robot/random1", 1000);
	ros::Publisher chatter_pub3 =
	    n.advertise<msg_gen::Num>("robot/random2", 1000);
	ros::Publisher chatter_pub4 =
	    n.advertise<msg_gen::Num>("robot/random3", 1000);
	int chatter_count = 0;
	double dur = 0.001;
	ros::Timer timer2 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
                msg_gen::Num msg2;
		    //    std::stringstream ss2;
		    msg2.num = (int)((rand() % 1000)==0);
            msg2.header.stamp=ros::Time::now();
		    //    ss2 <<"V1:"<<msg2.data;
		    //    ROS_INFO("%d", msg2.data);
		    chatter_pub2.publish(msg2);
	    });
	ros::Timer timer3 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg3;
		    //   std::stringstream ss3;
		    msg3.num = (int)((rand() % 10000)==0);;
            msg3.header.stamp=ros::Time::now();
		    //    ss3 <<"V2:"<<msg3.data;
		    //    ROS_INFO("%d", msg3.data);
		    chatter_pub3.publish(msg3);
	    });
	ros::Timer timer4 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg4;
		    //   std::stringstream ss3;
		    msg4.num = (int)((rand() % 100000)==0);
            msg4.header.stamp=ros::Time::now();
		    //    ss3 <<"V2:"<<msg3.data;
		    //    ROS_INFO("%d", msg3.data);
		    chatter_pub4.publish(msg4);
	    });

	ros::spin();
	return 0;
}


