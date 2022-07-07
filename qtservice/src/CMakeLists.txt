include(GenerateExportHeader)

if(POLICY CMP0020)
    cmake_policy(SET CMP0020 NEW)
    cmake_policy(SET CMP0071 NEW)
endif()

project(QtService)
add_library(QtService STATIC)

target_compile_definitions(QtService PUBLIC QTSERVICE_DEBUG)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set_target_properties(QtService PROPERTIES AUTOMOC TRUE)
set_target_properties(QtService PROPERTIES AUTOUIC TRUE)
set_target_properties(QtService PROPERTIES AUTORCC TRUE)


find_package(Qt5 COMPONENTS Core Network REQUIRED)

target_include_directories(QtService PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(QtService PRIVATE
"qtservice.cpp"
"qtservice.h"
"qtservice_p.h"
)

if (WIN32)
target_sources(QtService PRIVATE "qtservice_win")
endif()

if (WIN32)
target_sources(QtService PRIVATE "qtservice_win")
endif()

if (UNIX)
    target_sources(QtService PRIVATE "qtunixsocket.h" "qtunixserversocket.h" "qtservice_unix.cpp" "qtunixsocket.cpp" "qtunixserversocket.cpp")
endif()

target_include_directories(QtService PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>  ${PROJECT_BINARY_DIR})
#set_property(TARGET QtService PROPERTY  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
target_compile_definitions(QtService PRIVATE  $<CONFIG:Debug>:"_DEBUG"> $<CONFIG:Release>"NDEBUG">  "WIN32;"        "_CONSOLE;"        "UNICODE;"        "_UNICODE"       )
target_link_libraries(QtService PUBLIC Qt5::Core Qt5::Network user32)

generate_export_header(QtService)
