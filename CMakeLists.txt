cmake_minimum_required(VERSION 4.3)

set(PROJ_NAME TimeBranchr2)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS    CONFIGURE_DEPENDS "headers/*.h")
file(GLOB_RECURSE UI_FILES   CONFIGURE_DEPENDS "src/gui/ui/*.ui")
file(GLOB_RECURSE QRC_FILES  CONFIGURE_DEPENDS "src/gui/qrc/*.qrc")

# Let CMake run moc, uic and rcc automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(${PROJ_NAME} 
    ${SOURCES}
    ${HEADERS}      # needed so AUTOMOC sees Q_OBJECT headers
    ${UI_FILES}     # processed by AUTOUIC -> ui_<name>.h
    ${QRC_FILES}    # processed by AUTORCC
)


target_include_directories(${PROJ_NAME} PRIVATE 
    headers
    external_includes
)

target_link_libraries(${PROJ_NAME} PRIVATE Qt6::Widgets)

target_precompile_headers(${PROJ_NAME} PRIVATE
    headers/pch.h
)

# No console window for the GUI app
set_target_properties(${PROJ_NAME} PROPERTIES WIN32_EXECUTABLE ON)

# Copy Qt DLLs/plugins next to the exe after each build
add_custom_command(TARGET ${PROJ_NAME} POST_BUILD
    COMMAND Qt6::windeployqt ARGS "$<TARGET_FILE:${PROJ_NAME}>"
    COMMENT "Running windeployqt"
)
