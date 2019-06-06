#ifndef GEOMETRY_MSGS_DATA_BUFFER_TWIST_STAMPED_DATA_BUFFER_H_INCLUDED
#define GEOMETRY_MSGS_DATA_BUFFER_TWIST_STAMPED_DATA_BUFFER_H_INCLUDED

//headers in data buffer
#include <data_buffer/data_buffer_base.h>

//headers in ROS
#include <geometry_msgs/TwistStamped.h>
#include <quaternion_operation/quaternion_operation.h>

namespace data_buffer
{
    class TwistStampedDataBuffer : public DataBufferBase<geometry_msgs::TwistStamped>
    {
    public:
        TwistStampedDataBuffer(std::string key,double buffer_length);
        ~TwistStampedDataBuffer();
    private:
        geometry_msgs::TwistStamped interpolate(geometry_msgs::TwistStamped data0,geometry_msgs::TwistStamped data1,ros::Time stamp) override;
    };
}

#endif  //GEOMETRY_MSGS_DATA_BUFFER_TWIST_STAMPED_DATA_BUFFER_H_INCLUDED