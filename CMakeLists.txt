cmake_minimum_required(VERSION 2.8.3)
project(geometry_msgs_data_buffer)

add_compile_options(-std=c++11)

find_package(Eigen3 REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  data_buffer
  geometry_msgs
  roscpp
  quaternion_operation
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES geometry_msgs_data_buffer
  CATKIN_DEPENDS data_buffer geometry_msgs roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

add_library(geometry_msgs_data_buffer
  src/point_stamped_data_buffer.cpp
  src/pose_stamped_data_buffer.cpp
  src/twist_stamped_data_buffer.cpp)
target_link_libraries(geometry_msgs_data_buffer ${catkin_LIBRARIES})

# install executables/libs
install(TARGETS geometry_msgs_data_buffer
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# install headers
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)