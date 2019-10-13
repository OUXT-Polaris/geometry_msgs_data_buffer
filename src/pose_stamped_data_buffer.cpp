#include <geometry_msgs_data_buffer/pose_stamped_data_buffer.h>

namespace data_buffer
{
    PoseStampedDataBuffer::PoseStampedDataBuffer(std::shared_ptr<rclcpp::Node> node_ptr,std::string key,double buffer_length) 
        : DataBufferBase<geometry_msgs::msg::PoseStamped>(node_ptr,key,buffer_length)
    {

    }

    PoseStampedDataBuffer::~PoseStampedDataBuffer()
    {

    }

    geometry_msgs::msg::PoseStamped PoseStampedDataBuffer::interpolate(geometry_msgs::msg::PoseStamped data0,geometry_msgs::msg::PoseStamped data1,rclcpp::Time stamp)
    {
        geometry_msgs::msg::PoseStamped ret;
        assert(data0.header.frame_id == data1.header.frame_id);
        rclcpp::Time data0_stamp = data0.header.stamp;
        rclcpp::Time data1_stamp = data1.header.stamp;
        ret.header.frame_id = data0.header.frame_id;
        ret.header.stamp = stamp;
        ret.pose.position.x = ((data0.pose.position.x*toSec(data1_stamp-stamp)) + 
            (data1.pose.position.x*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.pose.position.y = ((data0.pose.position.y*toSec(data1_stamp-stamp)) + 
            (data1.pose.position.y*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.pose.position.z = ((data0.pose.position.z*toSec(data1_stamp-stamp)) + 
            (data1.pose.position.z*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        double ratio = toSec(stamp-data0_stamp)/toSec(data1_stamp-data0_stamp);
        ret.pose.orientation = quaternion_operation::slerp(data0.pose.orientation,data1.pose.orientation,ratio);
        return ret;
    }
}