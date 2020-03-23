#ifndef GEOMETRY_MSGS_DATA_BUFFER_POSE_STAMPED_BUFFER_H_INCLUDED
#define GEOMETRY_MSGS_DATA_BUFFER_POSE_STAMPED_BUFFER_H_INCLUDED

//headers in data buffer
#include <data_buffer/data_buffer_base.h>

//headers in ROS
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <quaternion_operation/quaternion_operation.h>

namespace data_buffer
{
    class PoseStampedDataBuffer : public DataBufferBase<geometry_msgs::msg::PoseStamped>
    {
    public:
        PoseStampedDataBuffer(rclcpp::Clock::SharedPtr clock,std::string key,double buffer_length);
        ~PoseStampedDataBuffer();
    private:
        geometry_msgs::msg::PoseStamped interpolate(geometry_msgs::msg::PoseStamped data0,geometry_msgs::msg::PoseStamped data1,rclcpp::Time stamp) override;
    };
}

#endif  //GEOMETRY_MSGS_DATA_BUFFER_POSE_STAMPED_BUFFER_H_INCLUDED