find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

find_package(Pangolin REQUIRED)

find_package(Sophus REQUIRED)
find_package(fmt REQUIRED)
set(FMT_LIBRARIES fmt::fmt)


add_executable(joinMap joinMap.cpp)
target_link_libraries(joinMap Sophus::Sophus ${OpenCV_LIBS} ${Pangolin_LIBRARIES} ${FMT_LIBRARIES}  fmt)


set(DEPENDENCIES realsense2)
add_executable(render_realsense_pangolin render_realsense_pangolin.cpp)
target_link_libraries(render_realsense_pangolin 
					Sophus::Sophus 
					${OpenCV_LIBS} 
					${Pangolin_LIBRARIES} 
					${FMT_LIBRARIES}  
					fmt 
					${DEPENDENCIES}
)

