#include <geometry_msgs_data_buffer/point_stamped_data_buffer.h>

namespace data_buffer
{
    PointStampedDataBuffer::PointStampedDataBuffer(rclcpp::Clock::SharedPtr clock,std::string key,double buffer_length) 
        : DataBufferBase<geometry_msgs::msg::PointStamped>(clock,key,buffer_length)
    {

    }

    PointStampedDataBuffer::~PointStampedDataBuffer()
    {

    }

    geometry_msgs::msg::PointStamped PointStampedDataBuffer::interpolate(geometry_msgs::msg::PointStamped data0,geometry_msgs::msg::PointStamped data1,rclcpp::Time stamp)
    {
        geometry_msgs::msg::PointStamped ret;
        assert(data0.header.frame_id == data1.header.frame_id);
        ret.header.frame_id = data0.header.frame_id;
        ret.header.stamp = stamp;
        rclcpp::Time data0_stamp = data0.header.stamp;
        rclcpp::Time data1_stamp = data1.header.stamp;
        ret.point.x = ((data0.point.x*toSec(data1_stamp-stamp)) + 
            (data1.point.x*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.point.y = ((data0.point.y*toSec(data1_stamp-stamp)) + 
            (data1.point.y*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.point.z = ((data0.point.z*toSec(data1_stamp-stamp)) + 
            (data1.point.z*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        return ret;
    }
}