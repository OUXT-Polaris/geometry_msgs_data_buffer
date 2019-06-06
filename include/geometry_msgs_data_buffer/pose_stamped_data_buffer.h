#ifndef GEOMETRY_MSGS_DATA_BUFFER_POSE_STAMPED_BUFFER_H_INCLUDED
#define GEOMETRY_MSGS_DATA_BUFFER_POSE_STAMPED_BUFFER_H_INCLUDED

#include <data_buffer/data_buffer_base.h>

//headers in ROS
#include <geometry_msgs/PoseStamped.h>
#include <quaternion_operation/quaternion_operation.h>

namespace data_buffer
{
    class PoseStampedDataBuffer : public DataBufferBase<geometry_msgs::PoseStamped>
    {
    public:
        PoseStampedDataBuffer(std::string key,double buffer_length);
        ~PoseStampedDataBuffer();
    private:
        geometry_msgs::PoseStamped interpolate(geometry_msgs::PoseStamped data0,geometry_msgs::PoseStamped data1,ros::Time stamp) override;
    };
}

#endif  //GEOMETRY_MSGS_DATA_BUFFER_POSE_STAMPED_BUFFER_H_INCLUDED