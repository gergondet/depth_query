#include "depth_query.h"

DepthQuery::DepthQuery(ros::NodeHandle & nh)
: nh_(nh), it_(nh_)
{
    img_sub_ = it_.subscribe("/depth_query_image", 1, &DepthQuery::imageCallback, this);
    depthQuerySrv_ = nh.advertiseService("depth_query", &DepthQuery::depthQueryCallback, this);
}

bool DepthQuery::depthQueryCallback(depth_query::DepthQueryService::Request & req,
                    depth_query::DepthQueryService::Response & res)
{
    if(req.x >= 0 && req.x < img_->height && req.y >= 0 && req.y < img_->width)
    {
        res.z = img_->data[2*(req.x+req.y*img_->width)] + (img_->data[2*(req.x+req.y*img_->width)+1] << 8);
    }
    else
    {
        res.z = 0;
    }
    return true;
}

void DepthQuery::imageCallback(const sensor_msgs::ImageConstPtr & msg)
{
    img_ =  msg;
}
