#include"ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"
#include <sstream>
#include <sensor_msgs/JointState.h>
#include <stdlib.h>
#include<cmath>
class Controller
 {
 public:
 	Controller(){
 		sub = n.subscribe<sensor_msgs::JointState>("/owi535/joint_states",1000,&Controller::callback,this);
 		pub_m = n.advertise<std_msgs::Float64>("/owi535/Model_Rotation_Position_Controller/command", 1000);
/* 		pub_r = n.advertise<std_msgs::Float64>("/owi535/Rotation_Base_Position_Controller/command", 1000);
 		pub_b = n.advertise<std_msgs::Float64>("/owi535/Base_Elbow_Position_Controller/command", 1000);
 		pub_e = n.advertise<std_msgs::Float64>("/owi535/Elbow_Wrist_Position_Controller/command", 1000);*/
 	}
 	void callback(sensor_msgs::JointState cmd_arm){
 			std_msgs::Float64 m,r,b,e,sin_m;
 			std_msgs::String p;
 			std::stringstream ss;

 			ss<<"position heard: "<<cmd_arm.position[2];
 			ss<<"effort heard: "<<cmd_arm.position[2];
 			p.data = ss.str();
 			std::cout<<p.data.c_str()<<std::endl;
 			m.data = 1.1;
 			r.data = 3.4;
 			b.data = 15;
 			r.data = 2.5;
 			pub_m.publish(m);
 			int i=0;
 			while(ros::ok())
 			{
 				ss<<"position heard: "<<cmd_arm.position[2];
 			ss<<"effort heard: "<<cmd_arm.position[2];
 			p.data = ss.str();
 			//std::cout<<p.data.c_str()<<std::endl;
 				double s = sin(i/100);
 				sin_m.data = s;
 				pub_m.publish(m);
 				i++;
 			}
 		/*	pub_r.publish(r);
 			pub_b.publish(b);
 			pub_e.publish(e);*/

 			ros::spinOnce();
 		}

 private:
 	ros::NodeHandle n;
 	ros::Subscriber sub;
 	ros::Publisher pub_m;
/* 	ros::Publisher pub_r;
 	ros::Publisher pub_b;
 	ros::Publisher pub_e;*/
 	


 	
 };
int main(int argc,char **argv)
{

	ros::init(argc,argv,"Controller");
	Controller cn;
	ros::Rate loop_rate(10);
	ros::spin();
	return 0;
}
