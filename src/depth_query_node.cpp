#include <ros/ros.h>

#include "depth_query.h"

int main(int argc, char * argv[])
{
    ros::init(argc, argv, "DepthQueryService");
    ros::NodeHandle nh;

    DepthQuery dq(nh);

    ros::Rate rate(100);
    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
