find_package(Qt6 REQUIRED COMPONENTS Core Quick Network)

qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

file(GLOB SOURCES
        "api/*.cpp"
        "api/*.h"
        "main/*.cpp"
        "model/*.cpp"
        "model/*.h"
)

qt_add_executable(${PROJECT_NAME}
        main/main.cpp
        ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick Qt6::Network)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

qt_add_qml_module(${PROJECT_NAME}
    URI TickQuickly
    VERSION 1.0
    QML_FILES
        qml/Main.qml
)
