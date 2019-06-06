#include <geometry_msgs_data_buffer/pose_stamped_data_buffer.h>

namespace data_buffer
{
    PoseStampedDataBuffer::PoseStampedDataBuffer(std::string key,double buffer_length) : DataBufferBase<geometry_msgs::PoseStamped>(key,buffer_length)
    {

    }

    PoseStampedDataBuffer::~PoseStampedDataBuffer()
    {

    }

    geometry_msgs::PoseStamped PoseStampedDataBuffer::interpolate(geometry_msgs::PoseStamped data0,geometry_msgs::PoseStamped data1,ros::Time stamp)
    {
        geometry_msgs::PoseStamped ret;
        ROS_ASSERT(data0.header.frame_id == data1.header.frame_id);
        ret.header.frame_id = data0.header.frame_id;
        ret.header.stamp = stamp;
        ret.pose.position.x = ((data0.pose.position.x*(data1.header.stamp-stamp).toSec()) + 
            (data1.pose.position.x*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.pose.position.y = ((data0.pose.position.y*(data1.header.stamp-stamp).toSec()) + 
            (data1.pose.position.y*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.pose.position.z = ((data0.pose.position.z*(data1.header.stamp-stamp).toSec()) + 
            (data1.pose.position.z*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        double ratio = (stamp-data0.header.stamp).toSec()/(data1.header.stamp-data0.header.stamp).toSec();
        ret.pose.orientation = quaternion_operation::slerp(data0.pose.orientation,data1.pose.orientation,ratio);
        return ret;
    }
}