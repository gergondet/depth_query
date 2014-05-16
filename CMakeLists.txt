cmake_minimum_required(VERSION 2.8.3)
project(depth_query)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    image_transport
    message_generation
)

add_service_files(
    DIRECTORY srv
    FILES
    DepthQueryService.srv
)

generate_messages()

include_directories(include ${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(depth_query_node src/depth_query.cpp src/depth_query_node.cpp)
target_link_libraries(depth_query_node ${catkin_LIBRARIES})

install(TARGETS 
    depth_query_node
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h")

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)
