cmake_minimum_required(VERSION 3.5)
project(geometry_msgs_data_buffer)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()
find_package(Eigen3 REQUIRED)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
)

add_library(geometry_msgs_data_buffer SHARED
  src/point_stamped_data_buffer.cpp
  src/pose_stamped_data_buffer.cpp
  src/twist_stamped_data_buffer.cpp)
ament_target_dependencies(geometry_msgs_data_buffer rclcpp data_buffer geometry_msgs quaternion_operation tf2_ros)
ament_export_targets(export_geometry_msgs_data_buffer HAS_LIBRARY_TARGET)
ament_export_libraries(geometry_msgs_data_buffer)

# install executables/libs
install(TARGETS
  geometry_msgs_data_buffer
  EXPORT export_geometry_msgs_data_buffer
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# Install header files
install(
  DIRECTORY "include/"
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()