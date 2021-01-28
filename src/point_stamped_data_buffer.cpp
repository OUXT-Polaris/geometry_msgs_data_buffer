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

#include <geometry_msgs_data_buffer/point_stamped_data_buffer.hpp>

#include <string>

namespace data_buffer
{
PointStampedDataBuffer::PointStampedDataBuffer(
  rclcpp::Clock::SharedPtr clock, std::string key,
  double buffer_length)
: DataBufferBase<geometry_msgs::msg::PointStamped>(clock, key, buffer_length) {}

PointStampedDataBuffer::~PointStampedDataBuffer() {}

geometry_msgs::msg::PointStamped PointStampedDataBuffer::interpolate(
  geometry_msgs::msg::PointStamped data0, geometry_msgs::msg::PointStamped data1,
  rclcpp::Time stamp)
{
  geometry_msgs::msg::PointStamped ret;
  assert(data0.header.frame_id == data1.header.frame_id);
  ret.header.frame_id = data0.header.frame_id;
  ret.header.stamp = stamp;
  rclcpp::Time data0_stamp = data0.header.stamp;
  rclcpp::Time data1_stamp = data1.header.stamp;
  ret.point.x = ((data0.point.x * toSec(data1_stamp - stamp)) +
    (data1.point.x * toSec(stamp - data0_stamp))) /
    toSec(data1_stamp - data0_stamp);
  ret.point.y = ((data0.point.y * toSec(data1_stamp - stamp)) +
    (data1.point.y * toSec(stamp - data0_stamp))) /
    toSec(data1_stamp - data0_stamp);
  ret.point.z = ((data0.point.z * toSec(data1_stamp - stamp)) +
    (data1.point.z * toSec(stamp - data0_stamp))) /
    toSec(data1_stamp - data0_stamp);
  return ret;
}
}  // namespace data_buffer
