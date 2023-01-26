###############################################################################
#                   :
#   File            :   CMakeLists.txt
#                   :
#   Author(s)       :   George Peppard (@inventor02)
#                   :
#   Description     :   Top level CMakeLists for project
#                   :
###############################################################################

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(candapter-listener VERSION 1.0.0)

# OS / architecture specific
if(APPLE)
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        # build natively for debug
        set(CMAKE_OSX_ARCHITECTURES "${CMAKE_HOST_SYSTEM_PROCESSOR}" CACHE INTERNAL "" FORCE)
    else()
        # universal binary for release
        set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE INTERNAL "" FORCE)
    endif()
endif()

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
  PRIVATE
    src/Candapter.cpp
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include)

IF(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Win32")
   execute_process(COMMAND ln -sf ${CMAKE_SOURCE_DIR}/build/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json)
ENDIF()