cmake_minimum_required(VERSION 3.13.4)

project(qml)

# get qml files
file(GLOB P_QML ${CMAKE_CURRENT_SOURCE_DIR}/*.qml)

# add QML to project tree
add_custom_target(${PROJECT_NAME} SOURCES ${P_QML})

# install QML files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DESTINATION bin
    FILES_MATCHING PATTERN "*.qml"
)
