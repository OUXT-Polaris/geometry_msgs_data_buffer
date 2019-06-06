#include <geometry_msgs_data_buffer/point_stamped_data_buffer.h>

namespace data_buffer
{
    PointStampedDataBuffer::PointStampedDataBuffer(std::string key,double buffer_length) : DataBufferBase<geometry_msgs::PointStamped>(key,buffer_length)
    {

    }

    PointStampedDataBuffer::~PointStampedDataBuffer()
    {

    }

    geometry_msgs::PointStamped PointStampedDataBuffer::interpolate(geometry_msgs::PointStamped data0,geometry_msgs::PointStamped data1,ros::Time stamp)
    {
        geometry_msgs::PointStamped ret;
        ROS_ASSERT(data0.header.frame_id == data1.header.frame_id);
        ret.header.frame_id = data0.header.frame_id;
        ret.header.stamp = stamp;
        ret.point.x = ((data0.point.x*(data1.header.stamp-stamp).toSec()) + 
            (data1.point.x*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.point.y = ((data0.point.y*(data1.header.stamp-stamp).toSec()) + 
            (data1.point.y*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        ret.point.z = ((data0.point.z*(data1.header.stamp-stamp).toSec()) + 
            (data1.point.z*(stamp-data0.header.stamp).toSec()))
            /(data1.header.stamp-data0.header.stamp).toSec();
        return ret;
    }
}