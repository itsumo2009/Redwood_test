cmake_minimum_required(VERSION 3.5)

project(Inventory LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Multimedia Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Multimedia Sql REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        inventorytablemodel.cpp
        inventorytablemodel.h
        inventory.cpp
        inventory.h
        item.h
        itemdelegate.h
        itemdelegate.cpp
        database.h
        database.cpp
        resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Inventory
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Inventory SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Inventory
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Inventory PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia Qt${QT_VERSION_MAJOR}::Sql)
add_custom_command(TARGET Inventory POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/main.sqlite ${CMAKE_BINARY_DIR}/main.sqlite
)
