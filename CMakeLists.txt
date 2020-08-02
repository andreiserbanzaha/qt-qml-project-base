cmake_minimum_required(VERSION 3.13.4)

project(qt-qml-base-project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# qt config
set(QT_TARGET_VERSION 5.12)

find_package(Qt5Core ${QT_TARGET_VERSION} REQUIRED)
find_package(Qt5Gui ${QT_TARGET_VERSION} REQUIRED)
find_package(Qt5Quick ${QT_TARGET_VERSION} REQUIRED)

add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Gui_DEFINITIONS})
add_definitions(${Qt5Quick_DEFINITIONS})

include_directories(SYSTEM ${Qt5Core_INCLUDE_DIRS})
include_directories(SYSTEM ${Qt5Gui_INCLUDE_DIRS})
include_directories(SYSTEM ${Qt5Quick_INCLUDE_DIRS})

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

add_definitions(-DQT_NO_VERSION_TAGGING)

set(QT5_LIBS
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Quick_LIBRARIES}
    )

# inc
file(GLOB P_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h)

# src
file(GLOB P_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# create executable project
add_executable(${PROJECT_NAME} ${P_INC} ${P_SRC})

target_link_libraries(${PROJECT_NAME} ${QT5_LIBS})

# install binary
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

add_subdirectory(qml)
