project(toys)

# to find OCV version
# pkg-config --modversion opencv
find_package(OpenCV REQUIRED)

# make executable from .cpp with main
add_executable(readWebcam readWebcam.cpp)
# Link to OpenCV
target_link_libraries(readWebcam ${OpenCV_LIBS})