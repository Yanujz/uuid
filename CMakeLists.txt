cmake_minimum_required(VERSION 3.10)
project(uuid VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

set(SOURCES
    uuid.c
)

add_library(uuid STATIC ${SOURCES})

target_include_directories(uuid
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR} 
)

install(TARGETS uuid
    ARCHIVE DESTINATION lib  # Install the static library to the lib directory
)

install(FILES uuid.h
    DESTINATION include  # Install the header to the include directory
)

set_target_properties(uuid PROPERTIES VERSION ${PROJECT_VERSION})