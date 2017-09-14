cmake_minimum_required(VERSION 3.7)
project(SimpleEvolution)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp NNet.h NNet.cpp)
add_executable(SimpleEvolution ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

find_package (Threads)
target_link_libraries(SimpleEvolution ${CMAKE_THREAD_LIBS_INIT})
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SimpleEvolution ${SFML_LIBRARIES})
endif()