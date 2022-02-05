# 顶层CMakeLists.txt

# 最低版本要求
cmake_minimum_required(VERSION 3.0)

# 工程名称，这里用lctstudy这个名字
project(lctstudy)

#1. 指定头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)
#2. 指定源码目录
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST_CPP)
#3. 指定库搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
#4. 指定编译子目录
add_subdirectory(src)
#5. 指定可执行文件输出目录
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#6. 指定可执行文件名及源码
add_executable(lctstudy ${SRC_LIST_CPP})
#7. 链接外部库
target_link_libraries(lctstudy server client pthread)