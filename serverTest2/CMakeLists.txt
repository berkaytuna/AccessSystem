cmake_minimum_required(VERSION 3.5)

project(serverTest2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        tabwidget.cpp
        tabwindow.cpp
        uiwindow.cpp
        cardwindow.cpp
        relaiswindow.cpp
        serverwindow.cpp
        debugwindow.cpp
        parameters.cpp
        client.cpp
        mainwindow.h
        tabwidget.h
        tabwindow.h
        uiwindow.h
        cardwindow.h
        relaiswindow.h
        serverwindow.h
        debugwindow.h
        parameters.h
        client.h
        constants.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(serverTest2
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(serverTest2 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(serverTest2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(serverTest2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(serverTest2 PRIVATE Qt${QT_VERSION_MAJOR}::Network)
