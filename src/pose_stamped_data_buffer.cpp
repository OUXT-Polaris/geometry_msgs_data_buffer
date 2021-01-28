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

#include <geometry_msgs_data_buffer/pose_stamped_data_buffer.hpp>

#include <string>

namespace data_buffer
{
PoseStampedDataBuffer::PoseStampedDataBuffer(
  rclcpp::Clock::SharedPtr clock, std::string key,
  double buffer_length)
: DataBufferBase<geometry_msgs::msg::PoseStamped>(clock, key, buffer_length) {}

PoseStampedDataBuffer::~PoseStampedDataBuffer() {}

geometry_msgs::msg::PoseStamped PoseStampedDataBuffer::interpolate(
  geometry_msgs::msg::PoseStamped data0, geometry_msgs::msg::PoseStamped data1,
  rclcpp::Time stamp)
{
  geometry_msgs::msg::PoseStamped ret;
  assert(data0.header.frame_id == data1.header.frame_id);
  rclcpp::Time data0_stamp = data0.header.stamp;
  rclcpp::Time data1_stamp = data1.header.stamp;
  ret.header.frame_id = data0.header.frame_id;
  ret.header.stamp = stamp;
  ret.pose.position.x = ((data0.pose.position.x * toSec(data1_stamp - stamp)) +
    (data1.pose.position.x * toSec(stamp - data0_stamp))) /
    toSec(data1_stamp - data0_stamp);
  ret.pose.position.y = ((data0.pose.position.y * toSec(data1_stamp - stamp)) +
    (data1.pose.position.y * toSec(stamp - data0_stamp))) /
    toSec(data1_stamp - data0_stamp);
  ret.pose.position.z = ((data0.pose.position.z * toSec(data1_stamp - stamp)) +
    (data1.pose.position.z * toSec(stamp - data0_stamp))) /
    toSec(data1_stamp - data0_stamp);
  double ratio = toSec(stamp - data0_stamp) / toSec(data1_stamp - data0_stamp);
  ret.pose.orientation = quaternion_operation::slerp(
    data0.pose.orientation, data1.pose.orientation,
    ratio);
  return ret;
}
}  // namespace data_buffer
