#ifndef GEOMETRY_MSGS_DATA_BUFFER_TWIST_STAMPED_DATA_BUFFER_H_INCLUDED
#define GEOMETRY_MSGS_DATA_BUFFER_TWIST_STAMPED_DATA_BUFFER_H_INCLUDED

//headers in data buffer
#include <data_buffer/data_buffer_base.h>

//headers in ROS
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <quaternion_operation/quaternion_operation.h>

namespace data_buffer
{
    class TwistStampedDataBuffer : public DataBufferBase<geometry_msgs::msg::TwistStamped>
    {
    public:
        TwistStampedDataBuffer(std::shared_ptr<rclcpp::Node> node_ptr,std::string key,double buffer_length);
        ~TwistStampedDataBuffer();
    private:
        geometry_msgs::msg::TwistStamped interpolate(geometry_msgs::msg::TwistStamped data0,geometry_msgs::msg::TwistStamped data1,rclcpp::Time stamp) override;
    };
}

#endif  //GEOMETRY_MSGS_DATA_BUFFER_TWIST_STAMPED_DATA_BUFFER_H_INCLUDED