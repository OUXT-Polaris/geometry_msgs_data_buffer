#ifndef GEOMETRY_MSGS_DATA_BUFFER_POINT_STAMPED_DATA_BUFFER_H_INCLUDED
#define GEOMETRY_MSGS_DATA_BUFFER_POINT_STAMPED_DATA_BUFFER_H_INCLUDED

namespace data_buffer
{
    class PointStampedDataBuffer : public DataBufferBase<geometry_msgs::PointStamped>
    {
    public:
        PointStampedDataBuffer(std::string key,double buffer_length);
        ~PointStampedDataBuffer();
    private:
        geometry_msgs::PointStamped interpolate(geometry_msgs::PointStamped data0,geometry_msgs::PointStamped data1,ros::Time stamp) override;
    };
}

#endif  //GEOMETRY_MSGS_DATA_BUFFER_POINT_STAMPED_DATA_BUFFER_H_INCLUDED