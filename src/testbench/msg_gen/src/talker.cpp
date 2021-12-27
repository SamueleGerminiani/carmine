// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "msg_gen/Num.h"
int main(int argc, char **argv) {
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	double dur = 0.005;
	ros::Publisher chatter_pub1 =
	    n.advertise<msg_gen::Num>("robot/random1", 1000);
	ros::Publisher chatter_pub2 =
	    n.advertise<msg_gen::Num>("robot/random2", 1000);
	ros::Publisher chatter_pub3 =
	    n.advertise<msg_gen::Num>("robot/random3", 1000);
	ros::Publisher chatter_pub4 =
	    n.advertise<msg_gen::Num>("robot/random4", 1000);
	ros::Publisher chatter_pub5 =
	    n.advertise<msg_gen::Num>("robot/random5", 1000);
	ros::Publisher chatter_pub6 =
	    n.advertise<msg_gen::Num>("robot/random6", 1000);
	ros::Publisher chatter_pub7 =
	    n.advertise<msg_gen::Num>("robot/random7", 1000);
	ros::Publisher chatter_pub8 =
	    n.advertise<msg_gen::Num>("robot/random8", 1000);
	ros::Publisher chatter_pub9 =
	    n.advertise<msg_gen::Num>("robot/random9", 1000);
	int chatter_count = 0;
	ros::Timer timer1 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
                msg_gen::Num msg1;
		    //    std::stringstream ss1;
		    msg1.num = (int)((rand() % 1000)==0);
            msg1.header.stamp=ros::Time::now();
		    //    ss1 <<"V1:"<<msg1.data;
		    //    ROS_INFO("%d", msg1.data);
		    chatter_pub1.publish(msg1);
	    });
	ros::Timer timer2 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg2;
		    //   std::stringstream ss2;
		    msg2.num = (int)((rand() % 10000)==0);;
            msg2.header.stamp=ros::Time::now();
		    //    ss2 <<"V2:"<<msg2.data;
		    //    ROS_INFO("%d", msg2.data);
		    chatter_pub2.publish(msg2);
	    });
	ros::Timer timer3 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg3;
		    //   std::stringstream ss3;
		    msg3.num = (int)((rand() % 100000)==0);
            msg3.header.stamp=ros::Time::now();
		    //    ss3 <<"V2:"<<msg3.data;
		    //    ROS_INFO("%d", msg3.data);
		    chatter_pub3.publish(msg3);
	    });

	ros::Timer timer4 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
                msg_gen::Num msg4;
		    //    std::stringstream ss4;
		    msg4.num = (int)((rand() % 4000)==0);
            msg4.header.stamp=ros::Time::now();
		    //    ss4 <<"V4:"<<msg4.data;
		    //    ROS_INFO("%d", msg4.data);
		    chatter_pub4.publish(msg4);
	    });
	ros::Timer timer5 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg5;
		    //   std::stringstream ss5;
		    msg5.num = (int)((rand() % 10000)==0);;
            msg5.header.stamp=ros::Time::now();
		    //    ss5 <<"V5:"<<msg5.data;
		    //    ROS_INFO("%d", msg5.data);
		    chatter_pub5.publish(msg5);
	    });
	ros::Timer timer6 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg6;
		    //   std::stringstream ss6;
		    msg6.num = (int)((rand() % 100000)==0);
            msg6.header.stamp=ros::Time::now();
		    //    ss6 <<"V2:"<<msg6.data;
		    //    ROS_INFO("%d", msg6.data);
		    chatter_pub6.publish(msg6);
	    });
	ros::Timer timer7 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
                msg_gen::Num msg7;
		    //    std::stringstream ss7;
		    msg7.num = (int)((rand() % 7000)==0);
            msg7.header.stamp=ros::Time::now();
		    //    ss7 <<"V7:"<<msg7.data;
		    //    ROS_INFO("%d", msg7.data);
		    chatter_pub7.publish(msg7);
	    });
	ros::Timer timer8 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg8;
		    //   std::stringstream ss8;
		    msg8.num = (int)((rand() % 10000)==0);;
            msg8.header.stamp=ros::Time::now();
		    //    ss8 <<"V2:"<<msg2.data;
		    //    ROS_INFO("%d", msg8.data);
		    chatter_pub8.publish(msg8);
	    });
	ros::Timer timer9 =
	    n.createTimer(ros::Duration(dur), [&](const ros::TimerEvent &) {
		    msg_gen::Num msg9;
		    //   std::stringstream ss9;
		    msg9.num = (int)((rand() % 100000)==0);
            msg9.header.stamp=ros::Time::now();
		    //    ss9 <<"V2:"<<msg9.data;
		    //    ROS_INFO("%d", msg9.data);
		    chatter_pub9.publish(msg9);
	    });

	ros::spin();
	return 0;
}


