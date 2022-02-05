message("server---${PROJECT_SOURCE_DIR}")
#指定动态库输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
#生成动态库
add_library(server SHARED server.cpp)