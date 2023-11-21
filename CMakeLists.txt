cmake_minimum_required(VERSION 3.5)

project(Painty)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)

add_executable(Painty
        glwidget.cpp
        main.cpp
        mainwindow.cpp
        pixel.cpp
#        toolCircle.cpp
#        toolLine.cpp
#        toolSpray.cpp
#        toolSquare.cpp
#        tools.cpp
        mainwindow.ui
)

target_link_libraries(Painty
        PRIVATE Qt5::Core
        PRIVATE Qt5::Gui
        PRIVATE Qt5::Widgets
        PRIVATE Qt5::OpenGL
        -lglut
        -lGL
)



target_include_directories(Painty
        PRIVATE ./
)

file(COPY ${CMAKE_SOURCE_DIR}/icons DESTINATION ${CMAKE_BINARY_DIR})
