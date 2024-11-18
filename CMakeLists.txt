cmake_minimum_required(VERSION 3.28)

project(sysapi)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES Battery.h Batteries.h)
set(SOURCE_FILES Battery.cpp Batteries.cpp)

add_library(sysapi STATIC ${SOURCE_FILES} ${HEADER_FILES} )

set_target_properties(sysapi PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})

