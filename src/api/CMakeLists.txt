project(API)
add_library(${PROJECT_NAME}
    api.cpp
    api.h
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME}
    QtOpenAPIClient
)