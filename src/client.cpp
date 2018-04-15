#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>
#include <sstream>
#include "homework1/messaggio.h"

using namespace std;
static string comand;


void chatterCallbackS1(const std_msgs::String::ConstPtr& msg)
{
	comand = msg->data.c_str();	
}


void chatterCallbackS2(const homework1::messaggio& msg){
	if(comand.compare("a") == 0)
    		ROS_INFO("Message: [%s, %s, %s]", msg.nome.c_str(), msg.eta.c_str(), msg.corso.c_str());
	else if(comand.compare("c") == 0)
		ROS_INFO("Message: [%s]", msg.corso.c_str());
	else if(comand.compare("e") == 0)
    		ROS_INFO("Message: [%s]", msg.eta.c_str());
  	else if(comand.compare("n") == 0)
    		ROS_INFO("Message: [%s]", msg.nome.c_str());
  	else if(comand.compare("q") == 0){
		ros::shutdown();
		exit(0);
	}

}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "client");
	ros::NodeHandle nodoClient;
	ros::Subscriber subscriptionServer1 = nodoClient.subscribe("server1Topic", 1000, chatterCallbackS2);
	ros::Subscriber subscriptionServer2 = nodoClient.subscribe("server2Topic", 1000, chatterCallbackS1);
	ros::spin();

	return 0;
}

