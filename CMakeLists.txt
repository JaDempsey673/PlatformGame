cmake_minimum_required(VERSION 3.14)
project(PlatformerSFML)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/Vector2.cpp src/Vector2.h src/Entities.cpp src/Entities.h src/Player.cpp src/Player.h src/Monster.cpp src/Monster.h src/Map.cpp src/Map.h src/Keys.cpp src/Keys.h src/Exit.cpp src/Exit.h)
add_executable(PlatformerSFML ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (PlatformerSFML sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)