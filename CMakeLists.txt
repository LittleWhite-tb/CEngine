cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(CEngine)

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deps/NEngine/CMakeLists.txt")
    message(FATAL_ERROR "Did you run 'git submodule update --init --recursive' ?")
endif()
add_subdirectory("./deps/NEngine")

SET(CMAKE_CXX_WARNING_LEVEL 4)
if (MSVC)
        add_definitions("/W4")
else()
        add_definitions("-Wall -Wextra")
endif ()

set(sources
        src/AnimationLoader.cpp
        src/Animation.cpp
	src/AnimatedSprite.cpp
	src/Font.cpp
        src/SpriteSheet.cpp
        src/SpriteSheetLoader.cpp

        src/utils.cpp
)

add_library(
    CEngine
    ${sources}
)

include_directories(./deps/pugixml-1.7/include)

target_include_directories(CEngine PUBLIC ./include)

target_link_libraries (CEngine NEngine)

install(DIRECTORY ./include/CEngine/
        DESTINATION include/CEngine )

install(TARGETS CEngine
        ARCHIVE DESTINATION lib/
        LIBRARY DESTINATION lib/ )
