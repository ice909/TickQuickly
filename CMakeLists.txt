cmake_minimum_required(VERSION 3.16)

project(TickQuickly VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(GTest REQUIRED)

qt_standard_project_setup(REQUIRES 6.8)

set(SOURCES
    src/model/task_list_model.cpp
    src/storage/local_json_task_storage.cpp
)

set(HEADER_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model
    ${CMAKE_CURRENT_SOURCE_DIR}/src/storage
)

qt_add_executable(appTickQuickly
    main.cpp
    ${SOURCES}
)

target_include_directories(appTickQuickly
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${HEADER_DIRS}
)

qt_add_qml_module(appTickQuickly
    URI TickQuickly
    VERSION 1.0
    QML_FILES
    ./qml/Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTickQuickly PROPERTIES

    # MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTickQuickly
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTickQuickly
    PRIVATE Qt6::Quick
)

enable_testing()
add_executable(test_task_list_model
    tests/test_task_list_model.cpp
    ${SOURCES}
)

target_include_directories(test_task_list_model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src ${HEADER_DIRS})
target_link_libraries(test_task_list_model GTest::gtest_main Qt6::Core)

add_test(NAME test_task_list_model COMMAND test_task_list_model)

include(GNUInstallDirs)
install(TARGETS appTickQuickly
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
