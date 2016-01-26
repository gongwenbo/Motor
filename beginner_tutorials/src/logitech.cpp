 #include "ros/ros.h"
 #include <geometry_msgs/Twist.h>
 #include <logitech/logitech.h>
 
 logitech::logitech x;
 int tem;
 void chatterCallback(const geometry_msgs::Twist::ConstPtr& msg)
   {
     ROS_INFO("linear.x [%f]", msg->linear.x);
     ROS_INFO("linear.y [%f]", msg->linear.y);
     ROS_INFO("linear.z [%f]", msg->linear.z);
     ROS_INFO("------------------------------");
     ROS_INFO("angular.x [%f]", msg->angular.x);
     ROS_INFO("angular.y [%f]", msg->angular.y);
     ROS_INFO("angular.z [%f]", msg->angular.z);
     ROS_INFO("******************************");
     x.a=msg->linear.x;
     //x.a=1000*x.a;
     //tem=int(x.a);
     //ROS_INFO("%d",tem);
    // x.a=tem;
     ROS_INFO("x.a=%f",x.a);

     ROS_INFO("x.a=%.3f",x.a);
     

    


   }
   
 int main(int argc, char **argv)
   {
     
     ros::init(argc, argv, "logitech");
   
     ros::NodeHandle n;
   
     ros::Subscriber sub = n.subscribe("teleop_velocity_smoother/raw_cmd_vel", 1, chatterCallback);      //"teleop_velocity_smoother/raw_cmd_vel”为罗技手柄话题

     ros::Publisher chatter_pub = n.advertise<logitech::logitech>("logitech_msg", 1);
   
     ros::Rate loop_rate(10);

  while (ros::ok())

{

  chatter_pub.publish(x);
  ros::spinOnce();
  loop_rate.sleep();

}
    
     //ros::spin();
     
     return 0;
   }
