file(GLOB SOURCES
    *.cpp
    game/*.cpp
    graphic/*.cpp)

add_subdirectory(ecs)

add_executable(DawnOfEvolution ${SOURCES})

include_directories(../json/include)

target_link_libraries(DawnOfEvolution PUBLIC sfml-graphics sfml-window sfml-system)
target_link_libraries(DawnOfEvolution PUBLIC ECSLibrary)

target_include_directories(DawnOfEvolution PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/game
    ${CMAKE_CURRENT_SOURCE_DIR}/graphic)