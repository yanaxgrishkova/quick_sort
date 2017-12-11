cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    "https://github.com/yanaxgrishkova/hunter/archive/v1.1.tar.gz"
    SHA1 "c08dc366a403d1b28943d846e3c80cecd852d40d"
)

project(demo)

option(BUILD_EXAMPLES "Build Examples" OFF)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} INTERFACE "${PROJECT_SOURCE_DIR}/include/quick_sort.hpp")

target_include_directories(${PROJECT_NAME} INTERFACE "${PROJECT_SOURCE_DIR}/include")

if(BUILD_EXAMPLES)
    file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
    foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
        get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
        set(EXAMPLE_TARGET_NAME example_${EXAMPLE_NAME})
        add_executable(${EXAMPLE_TARGET_NAME} ${EXAMPLE_SOURCE})
        target_link_libraries(${EXAMPLE_TARGET_NAME} ${PROJECT_NAME})
        set_target_properties(${EXAMPLE_TARGET_NAME} PROPERTIES OUTPUT_NAME ${EXAMPLE_NAME})
        install(TARGETS ${EXAMPLE_TARGET_NAME}
                RUNTIME DESTINATION bin
                )
    endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()
