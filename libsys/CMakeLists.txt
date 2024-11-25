cmake_minimum_required(VERSION 3.25)

project(sys)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
include_directories(include)

set(PUBLIC_HEADER include/sys/Batteries.h include/sys/Battery.h)
set(SOURCE_FILES src/Battery.cpp src/Batteries.cpp)

add_library(sys SHARED ${SOURCE_FILES} ${PUBLIC_HEADER} )

install(TARGETS sys DESTINATION lib)
install(FILES include/sys/Battery.h DESTINATION include/sys)
install(FILES include/sys/Batteries.h DESTINATION include/sys)
