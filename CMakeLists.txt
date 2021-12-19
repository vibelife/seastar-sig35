cmake_minimum_required(VERSION 3.20)
project(sig35)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines")
set(Boost_NO_WARN_NEW_VERSIONS 1)
find_package (Seastar REQUIRED)

add_executable(sig35 main.cpp)
target_link_libraries(${PROJECT_NAME}  PRIVATE Seastar::seastar)
