#ifndef _H_DEPTHQUERY_H_
#define _H_DEPTHQUERY_H_

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/Image.h>
#include <depth_query/DepthQueryService.h>

class DepthQuery
{
public:
    DepthQuery(ros::NodeHandle & nh);
protected:
    bool depthQueryCallback(depth_query::DepthQueryService::Request & req,
                    depth_query::DepthQueryService::Response & res);

    void imageCallback(const sensor_msgs::ImageConstPtr & msg);
private:
    ros::NodeHandle & nh_;
    ros::ServiceServer depthQuerySrv_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber img_sub_;
    sensor_msgs::ImageConstPtr img_;
}; 

#endif
