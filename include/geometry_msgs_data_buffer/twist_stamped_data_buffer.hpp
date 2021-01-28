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

#ifndef GEOMETRY_MSGS_DATA_BUFFER__TWIST_STAMPED_DATA_BUFFER_HPP_
#define GEOMETRY_MSGS_DATA_BUFFER__TWIST_STAMPED_DATA_BUFFER_HPP_

// headers in data buffer
#include <data_buffer/data_buffer_base.hpp>

// headers in ROS
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <quaternion_operation/quaternion_operation.h>

#include <string>

namespace data_buffer
{
class TwistStampedDataBuffer : public DataBufferBase<geometry_msgs::msg::TwistStamped>
{
public:
  TwistStampedDataBuffer(rclcpp::Clock::SharedPtr clock, std::string key, double buffer_length);
  ~TwistStampedDataBuffer();

private:
  geometry_msgs::msg::TwistStamped interpolate(
    geometry_msgs::msg::TwistStamped data0,
    geometry_msgs::msg::TwistStamped data1,
    rclcpp::Time stamp) override;
};
}  // namespace data_buffer

#endif  // GEOMETRY_MSGS_DATA_BUFFER__TWIST_STAMPED_DATA_BUFFER_HPP_
