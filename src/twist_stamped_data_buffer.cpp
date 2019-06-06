#include <geometry_msgs_data_buffer/twist_stamped_data_buffer.h>

namespace data_buffer
{
    TwistStampedDataBuffer::TwistStampedDataBuffer(std::string key,double buffer_length) : DataBufferBase<geometry_msgs::TwistStamped>(key,buffer_length)
    {

    }

    TwistStampedDataBuffer::~TwistStampedDataBuffer()
    {

    }

    geometry_msgs::TwistStamped TwistStampedDataBuffer::interpolate(geometry_msgs::TwistStamped data0,geometry_msgs::TwistStamped data1,ros::Time stamp)
    {
        geometry_msgs::TwistStamped ret;
        ROS_ASSERT(data0.header.frame_id == data1.header.frame_id);
        ret.header.frame_id = data0.header.frame_id;
        ret.header.stamp = stamp;
        ret.twist.linear.x = ((data0.twist.linear.x*(data1.header.stamp-stamp).toSec()) + 
            (data1.twist.linear.x*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.twist.linear.y = ((data0.twist.linear.y*(data1.header.stamp-stamp).toSec()) + 
            (data1.twist.linear.y*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.twist.linear.z = ((data0.twist.linear.z*(data1.header.stamp-stamp).toSec()) + 
            (data1.twist.linear.z*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.twist.angular.x = ((data0.twist.angular.x*(data1.header.stamp-stamp).toSec()) + 
            (data1.twist.angular.x*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.twist.angular.y = ((data0.twist.angular.y*(data1.header.stamp-stamp).toSec()) + 
            (data1.twist.angular.y*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.twist.angular.z = ((data0.twist.angular.z*(data1.header.stamp-stamp).toSec()) + 
            (data1.twist.angular.z*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        return ret;
    }
}