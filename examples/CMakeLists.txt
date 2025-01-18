cmake_minimum_required(VERSION 3.20)
project(uuidv4 VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ ${CMAKE_BINARY_DIR}/uuid_build)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PUBLIC uuid)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
