cmake_minimum_required(VERSION 3.13.4)

project(qt-qml-base-project 
  LANGUAGES CXX
  VERSION 1.0.0
  DESCRIPTION "Qt5 startup project"
 )

# qt config
set(QT_TARGET_VERSION 5.12)

find_package(Qt5 ${QT_TARGET_VERSION} COMPONENTS Core Gui Quick REQUIRED)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME}_interface INTERFACE)
target_compile_definitions(${PROJECT_NAME}_interface INTERFACE QT_NO_VERSION_TAGGING)
set_target_properties(${PROJECT_NAME}_interface PROPERTIES INTERFACE_POSITION_INDEPENDENT_CODE ON)

# inc
file(GLOB P_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc/demoqml/*.h)
# src
file(GLOB P_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# create executable project
add_executable(${PROJECT_NAME} ${P_INC} ${P_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
  $<INSTALL_INTERFACE:inc>
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  ${PROJECT_NAME}_interface
  Qt5::Core
  Qt5::Quick
  Qt5::Gui
)

add_subdirectory(qml)

# install binary
include(GNUInstallDirs)
install(
  TARGETS
    ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-targets
  DESTINATION ${CMAKE_INSTALL_BINDIR}
)
