project(server)
cmake_minimum_required(VERSION 3.12)

set(PROJECT_SOURCES
        main.cpp
        server.cpp
        )

set(PROJECT_HEADERS
        server.h
        server.cpp server.h)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(server ws2_32)