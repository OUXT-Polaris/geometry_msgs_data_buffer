#include <geometry_msgs_data_buffer/twist_stamped_data_buffer.h>

namespace data_buffer
{
    TwistStampedDataBuffer::TwistStampedDataBuffer(rclcpp::Clock::SharedPtr clock,std::string key,double buffer_length) 
        : DataBufferBase<geometry_msgs::msg::TwistStamped>(clock,key,buffer_length)
    {

    }

    TwistStampedDataBuffer::~TwistStampedDataBuffer()
    {

    }

    geometry_msgs::msg::TwistStamped TwistStampedDataBuffer::interpolate(geometry_msgs::msg::TwistStamped data0,geometry_msgs::msg::TwistStamped data1,rclcpp::Time stamp)
    {
        geometry_msgs::msg::TwistStamped ret;
        assert(data0.header.frame_id == data1.header.frame_id);
        ret.header.frame_id = data0.header.frame_id;
        ret.header.stamp = stamp;
        rclcpp::Time data0_stamp = data0.header.stamp;
        rclcpp::Time data1_stamp = data1.header.stamp;
        ret.twist.linear.x = ((data0.twist.linear.x*toSec(data1_stamp-stamp)) + 
            (data1.twist.linear.x*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.twist.linear.y = ((data0.twist.linear.y*toSec(data1_stamp-stamp)) + 
            (data1.twist.linear.y*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.twist.linear.z = ((data0.twist.linear.z*toSec(data1_stamp-stamp)) + 
            (data1.twist.linear.z*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.twist.angular.x = ((data0.twist.angular.x*toSec(data1_stamp-stamp)) + 
            (data1.twist.angular.x*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.twist.angular.y = ((data0.twist.angular.y*toSec(data1_stamp-stamp)) + 
            (data1.twist.angular.y*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        ret.twist.angular.z = ((data0.twist.angular.z*toSec(data1_stamp-stamp)) + 
            (data1.twist.angular.z*toSec(stamp-data0_stamp)))
            /toSec(data1_stamp-data0_stamp);
        return ret;
    }
}