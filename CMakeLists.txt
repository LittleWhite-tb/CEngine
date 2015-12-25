cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(CEngine)

if (NOT EXISTS "./deps/NEngine/CMakeLists.txt")
    message(FATAL_ERROR "Did you run 'git submodule update --init --recursive' ?")
endif()
add_subdirectory("./deps/NEngine")

SET(CMAKE_CXX_WARNING_LEVEL 4)
if (MSVC)
        add_definitions("/W4")
else()
        add_definitions("-Wall -Wextra")
endif ()

set(pugixml_sources
        deps/pugixml-1.7/src/pugixml.cpp)

set(sources
	src/AnimatedSprite.cpp
	src/Font.cpp
        src/SpriteSheet.cpp
        src/SpriteSheetLoader.cpp
)

add_library(
    CEngine
    ${pugixml_sources} ${sources}
)

include_directories(./src)
include_directories(./include)
include_directories(./include/CEngine)
include_directories(./deps/NEngine/include) # TODO : should it be done here ?
include_directories(./deps/pugixml-1.7/include)

target_link_libraries (CEngine NEngine)

install(DIRECTORY ./include/CEngine/
        DESTINATION include/CEngine )

install(TARGETS CEngine
        ARCHIVE DESTINATION lib/
        LIBRARY DESTINATION lib/ )
