// Copyright (c) 2019 OUXT Polaris
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GEOMETRY_MSGS_DATA_BUFFER__POINT_STAMPED_DATA_BUFFER_HPP_
#define GEOMETRY_MSGS_DATA_BUFFER__POINT_STAMPED_DATA_BUFFER_HPP_

// headers in data buffer
#include <data_buffer/data_buffer_base.hpp>

// headers in ROS
#include <geometry_msgs/msg/point_stamped.hpp>

#include <string>

namespace data_buffer
{
class PointStampedDataBuffer : public DataBufferBase<geometry_msgs::msg::PointStamped>
{
public:
  PointStampedDataBuffer(rclcpp::Clock::SharedPtr clock, std::string key, double buffer_length);
  ~PointStampedDataBuffer();

private:
  geometry_msgs::msg::PointStamped interpolate(
    geometry_msgs::msg::PointStamped data0,
    geometry_msgs::msg::PointStamped data1,
    rclcpp::Time stamp) override;
};
}  // namespace data_buffer

#endif  // GEOMETRY_MSGS_DATA_BUFFER__POINT_STAMPED_DATA_BUFFER_HPP_
