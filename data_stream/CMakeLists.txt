cmake_minimum_required (VERSION 2.6)
project (data_stream_project)

include_directories(include)
add_subdirectories(src)

add_executable(data_stream_project main.cpp)
target_link_libraries(data_stream_project data_stream)

install (TARGETS data_stream DESTINATION lib)
install (TARGETS data_stream_project DESTINATION bin)
install (FILES data_stream.h DESTINATION include)
