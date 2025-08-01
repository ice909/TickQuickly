# 搜索所有测试 cpp 文件
file(GLOB TEST_SOURCES "*.cpp")

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(GTest REQUIRED)

# 依赖的头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(test_task_list_model
    test_task_list_model.cpp
    ${SOURCES}
)

target_include_directories(test_task_list_model PRIVATE ${PROJECT_SOURCE_DIR}/src ${HEADER_DIRS})
target_link_libraries(test_task_list_model GTest::gtest_main Qt6::Core)

add_test(NAME test_task_list_model COMMAND test_task_list_model)