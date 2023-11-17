cmake_minimum_required(VERSION 3.10)
project(ECSLibrary)

file(GLOB SOURCES
    Registry.cpp
    ComponentsArray/Systems/*.cpp)    

add_library(ECSLibrary STATIC ${SOURCES})

target_include_directories(ECSLibrary PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentsArray/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentsArray/Components
)
