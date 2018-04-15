#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "homework1/messaggio.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "server1");
	ros::NodeHandle nodoServer1;
	ros::Publisher server1_pub = nodoServer1.advertise<homework1::messaggio>("server1Topic", 1000);
	ros::Rate loop_rate(1);

	while (ros::ok())
	{
		//METTERE QUASI TUTTO FUORI DA WHILE
		homework1::messaggio msg;
    		std::stringstream ss;
	    	ss << "Moreno";
	    	msg.nome = ss.str();
		std::stringstream ss1;
		ss1 << "22 anni";
		msg.eta = ss1.str();
	    	std::stringstream ss2;
	    	ss2 << "Ingegneria e Scienze Informatiche";
	    	msg.corso = ss2.str();
		ROS_INFO("nome: %s, eta: %s, corso: %s", msg.nome.c_str(), msg.eta.c_str(), msg.corso.c_str());
	    	server1_pub.publish(msg);
	    	ros::spinOnce();
	    	loop_rate.sleep();
	}

	return 0;
}

