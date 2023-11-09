cmake_minimum_required(VERSION 3.15.0)
project(multi-agent-arch VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

set(TARGET_NAME march) # multi-agent-arch

set(TARGET_SOURCE_FILES

    "node.hpp"
    "node.cpp"
    
    "state.cpp"
    "state.hpp"

    "message.hpp"
    "message.cpp"

    "action.hpp"
    "action.cpp"

)

add_library(${TARGET_NAME} OBJECT ${TARGET_SOURCE_FILES})
target_include_directories(${TARGET_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_11)

set(TARGET_NAME ${PROJECT_NAME})
set(TARGET_SOURCE_FILES "main.cpp")
add_executable(${TARGET_NAME} ${TARGET_SOURCE_FILES})

target_link_libraries(${TARGET_NAME} PRIVATE march)
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
