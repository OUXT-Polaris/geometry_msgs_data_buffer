#ifndef GEOMETRY_MSGS_DATA_BUFFER_POINT_STAMPED_DATA_BUFFER_H_INCLUDED
#define GEOMETRY_MSGS_DATA_BUFFER_POINT_STAMPED_DATA_BUFFER_H_INCLUDED

//headers in data buffer
#include <data_buffer/data_buffer_base.h>

//headers in ROS
#include <geometry_msgs/msg/point_stamped.hpp>

namespace data_buffer
{
    class PointStampedDataBuffer : public DataBufferBase<geometry_msgs::msg::PointStamped>
    {
    public:
        PointStampedDataBuffer(std::shared_ptr<rclcpp::Node> node_ptr,std::string key,double buffer_length);
        ~PointStampedDataBuffer();
    private:
        geometry_msgs::msg::PointStamped interpolate(geometry_msgs::msg::PointStamped data0,geometry_msgs::msg::PointStamped data1,rclcpp::Time stamp) override;
    };
}

#endif  //GEOMETRY_MSGS_DATA_BUFFER_POINT_STAMPED_DATA_BUFFER_H_INCLUDED