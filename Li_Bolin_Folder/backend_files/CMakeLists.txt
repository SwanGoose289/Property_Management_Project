cmake_minimum_required(VERSION 3.10)

project(manager)

# 查找 pkg-config
find_package(PkgConfig REQUIRED)

# 使用 pkg-config 查找 libmicrohttpd
pkg_check_modules(MHD REQUIRED libmicrohttpd)

# 创建可执行文件
add_executable(manager src/Management.c)

# 链接库
target_link_libraries(manager ${MHD_LIBRARIES})

# 添加包含目录
target_include_directories(manager PRIVATE ${MHD_INCLUDE_DIRS})