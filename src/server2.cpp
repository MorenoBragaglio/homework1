#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream> 
#include <sstream>
#include <termios.h>

using namespace std;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "server2");
	ros::NodeHandle nodoServer2;
	ros::Publisher server2_pub = nodoServer2.advertise<std_msgs::String>("server2Topic", 1000);
	std_msgs::String msg;
	string ss;

	while (ros::ok())
	{
		string c;
		cout << "---------- MENU' ---------- \n a - Print all message \n c - Print course of study \n e - Print age\n n - Print name\n q - Exit" << endl;
		cin >> c;
	
		if(c == "a" || c == "e" || c == "n" || c == "c"){
			msg.data = c;
    			ROS_INFO("%s", msg.data.c_str());
			fflush(stdout);
    			server2_pub.publish(msg);
		}else if (c == "q"){
			msg.data = c;
			ROS_INFO("%s", msg.data.c_str());
			fflush(stdout);
        		server2_pub.publish(msg);
			ros::shutdown();
			exit(0);
		}	
	}

	return 0;
}

