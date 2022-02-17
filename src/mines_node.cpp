//Ryan Reschak
//Description:
//Draws Mines Logo in Turtle Sim to do so
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

int section = 0; //Starts at bottom of the M

void logo(const turtlesim::PoseConstPtr& pos){
 
	//ROS_INFO("Pose %.2f %.2f", pos->x, pos->y);
	switch(section) {
		case 0:

			if (pos->y > 5.75f) {
				ROS_INFO("Completed 0");
				section = 1;
			}
			break;
		case 1:

			if (pos->x > 6.0f) {
				ROS_INFO("Completed 1");
				section = 2;
			}
			break;
		case 2:
			if (pos->y > 7.5f) {
				ROS_INFO("Completed 2");
				section = 3;
			}
			break;
		case 3:
			if (pos->x < 5.5f) {
				ROS_INFO("Completed 3");
				section = 4;
			}
			break;
		case 4: //top of M left side complete
			if (pos->y > 8.0f) {
				ROS_INFO("Completed 4");
				section = 5;
			}
			break;

		case 5:
			if (pos->x > 6.5f) {
				ROS_INFO("Completed 5");
				section = 6;
			}
			break;
		case 6:
			if (pos->y < 7.25f && pos->x > 7.25f) {
				ROS_INFO("Completed 6");
				section = 7;
			}
			break;
		case 7:
			if (pos->y > 8.0f && pos->x > 8.0f) {
				ROS_INFO("Completed 7");
				section = 8;
			}
			break;
		case 8: //Complete Top Part
			if (pos->x > 10.0f) {
				ROS_INFO("Completed 8");
				section = 9;
			}
			break;
		case 9:
			if (pos->y < 7.75f) {
				ROS_INFO("Completed 9");
				section = 10;
			}
			break;
		case 10:
			if (pos->x < 9.5f) {
				ROS_INFO("Completed 10");
				section = 11;
			}
			break;
		case 11:
			if (pos->y < 6.0f) {
				ROS_INFO("Completed 11");
				section = 12;
			}
			break;
		case 12:
			if (pos->x > 10.0f) {
				ROS_INFO("Completed 12");
				section = 13;
			}
			break;
		case 13: //Complete Right Side
			if (pos->y < 5.5f) {
				ROS_INFO("Completed 13");
				section = 14;
			}
			break;
		case 14:
			if (pos->x < 8.5f) {
				ROS_INFO("Completed 14");
				section = 15;
			}
			break;
		case 15:
			if (pos->y > 5.75f) {
				ROS_INFO("Completed 15");
				section = 16;
			}
			break;
		
		case 16:
			if (pos->x > 8.75f) {
				ROS_INFO("Completed 16");
				section = 17;
			}
			break;
		case 17:
			if (pos->y > 7.0f) {
				ROS_INFO("Completed 17");
				section = 18;
			}
			break;
		case 18: //Starting Lower Arch
			if (/*pos->y < 7.5 &&*/ pos->x < 7.75f) {
				ROS_INFO("Completed 18");
				section = 19;
			}
			break;
		case 19: //Completed arch
			if (/*pos->y > 7.0f &&*/ pos->x < 6.75f) {
				ROS_INFO("Completed 19");
				section = 20;
			}
			break;
		
		case 20:
			if (pos->y < 6.0f) {
				ROS_INFO("Completed 20");
				section = 21;
			}
			break;
		case 21:
			if (pos->x > 7.0f) {
				ROS_INFO("Completed 21");
				section = 22;
			}
			break;
		case 22:
			if (pos->y < 5.5f) {
				ROS_INFO("Completed 22");
				section = 23;
			}
			break;
		case 23:
			if (pos->x < 5.5f) {
				ROS_INFO("Completed 23");
				section = 0;
			}
			break;
		default:
			ROS_INFO("Sub: Rats");
			break;
	}
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "mines_node");
	
	ros::NodeHandle node;

	ros::Subscriber sub = node.subscribe("turtle1/pose", 10, logo);
	ros::Publisher pub = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
	
	ros::Rate loop_rate(10);
	
	geometry_msgs::Twist msg;

	while(ros::ok()){

		//ROS_INFO("Section %d", section);
		switch(section) {
			case 0: 
				msg.linear.x = 0.0f;
				msg.linear.y = 1.0f;
				break;
			case 1: 
				msg.linear.x = 1.0f;
				msg.linear.y = 0.0f;
				break;
			case 2:
				msg.linear.x = 0.0f;
				msg.linear.y = 1.0f;
				break;
			case 3:
				msg.linear.x = -1.0f;
				msg.linear.y = 0.0f;
				break;
			case 4: //top of M left side complete
				msg.linear.x = 0.0f;
				msg.linear.y = 1.0f;
				break;
			case 5: 
				msg.linear.x = 1.0f;
				msg.linear.y = 0.0f;
				break;
			case 6:
				msg.linear.x = 1.0f;
				msg.linear.y = -1.0f;
				break;
			case 7:
				msg.linear.x = 1.0f;
				msg.linear.y = 1.0f;
				break;
			case 8: 
				msg.linear.x = 1.0f;
				msg.linear.y = 0.0f;
				break;
			case 9: 
				msg.linear.x = 0.0f;
				msg.linear.y = -1.0f;
				break;
			case 10:
				msg.linear.x = -1.0f;
				msg.linear.y = 0.0f;
				break;
			case 11:
				msg.linear.x = 0.0f;
				msg.linear.y = -1.0f;
				break;
			case 12: 
				msg.linear.x = 1.0f;
				msg.linear.y = 0.0f;
				break;
			case 13: //Complete Right Side
				msg.linear.x = 0.0f;
				msg.linear.y = -1.0f;
				break;
			case 14:
				msg.linear.x = -1.0f;
				msg.linear.y = 0.0f;
				break;
			case 15:
				msg.linear.x = 0.0f;
				msg.linear.y = 1.0f;
				break;
			case 16: 
				msg.linear.x = 1.0f;
				msg.linear.y = 0.0f;
				break;
			case 17: 
				msg.linear.x = 0.0f;
				msg.linear.y = 1.0f;
				break;
			case 18:
				msg.linear.x = -1.0f;
				msg.linear.y = -1.0f;
				break;
			case 19:
				msg.linear.x = -1.0f;
				msg.linear.y = 1.0f;//cum back
				break;
			case 20: 
				msg.linear.x = 0.0f;
				msg.linear.y = -1.0f;
				break;
			case 21: 
				msg.linear.x = 1.0f;
				msg.linear.y = 0.0f;
				break;
			case 22:
				msg.linear.x = 0.0f;
				msg.linear.y = -1.0f;
				break;
			case 23:
				msg.linear.x = -1.0f;
				msg.linear.y = 0.0f;
				break;
			default: //oh no
				ROS_INFO("Pub: Rats");
				break;
		}
		pub.publish(msg);
		ros::spinOnce();	
		loop_rate.sleep();
	}	
	return 0;
}
