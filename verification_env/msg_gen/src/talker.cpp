// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "msg_gen/Num.h"
int main(int argc, char **argv) {
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	ros::Publisher chatter_pub1 =
	    n.advertise<msg_gen::Num>("V0", 1000);
	ros::Publisher chatter_pub2 =
	    n.advertise<msg_gen::Num>("V1", 1000);
	ros::Publisher chatter_pub3 =
	    n.advertise<msg_gen::Num>("V2", 1000);
	int chatter_count = 0;
	double dur = 0.000001;
//	ros::Timer timer1 =
//	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
//		    std_msgs::Int32 msg1;
//		    //    std::stringstream ss1;
//		    msg1.data = 7;
//		    //   ss1 <<"V0:"<<msg1.data;
//		    //   ROS_INFO("%d", msg1.data);
//		    chatter_pub1.publish(msg1);
//		    //		    chatter_count++;
//	    });
	ros::Timer timer2 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
                msg_gen::Num msg2;
		    //    std::stringstream ss2;
		    msg2.num = 0;
            msg2.header.stamp=ros::Time::now();
		    //    ss2 <<"V1:"<<msg2.data;
		    //    ROS_INFO("%d", msg2.data);
		    chatter_pub2.publish(msg2);
	    });
	ros::Timer timer3 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg3;
		    //   std::stringstream ss3;
		    msg3.num = 1;
            msg3.header.stamp=ros::Time::now();
		    //    ss3 <<"V2:"<<msg3.data;
		    //    ROS_INFO("%d", msg3.data);
		    chatter_pub3.publish(msg3);
	    });

	ros::spin();
	return 0;
}


