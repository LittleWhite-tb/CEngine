cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

add_subdirectory("./deps/NEngine")

project(CEngine)

SET(CMAKE_CXX_WARNING_LEVEL 4)
if (DEFINED MSYS)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif ()

if (DEFINED CMAKE_COMPILER_IS_GNUCC OR DEFINED CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()

set(sources

	src/AnimatedSprite.cpp
	src/Font.cpp
)


add_library(
    CEngine
	SHARED
	${sources}
)

add_library(
    CEngine-static
	STATIC
	${sources}
)
# Since the static compilation will have same root name, with have to do some "hacky" things
# This is coming from CMake FAQ
SET_TARGET_PROPERTIES(CEngine-static PROPERTIES OUTPUT_NAME "CEngine")
# Now the library target "foo-static" will be named "foo.lib" with MS tools.
# This conflicts with the "foo.lib" import library corresponding to "foo.dll",
# so we add a "lib" prefix (which is default on other platforms anyway):
SET_TARGET_PROPERTIES(CEngine-static PROPERTIES PREFIX "lib")

include_directories(./src)
include_directories(./include)
include_directories(./include/CEngine)
include_directories(./deps/NEngine/include) # TODO : should it be done here ?

target_link_libraries (CEngine NEngine)
target_link_libraries (CEngine-static NEngine)

install(DIRECTORY ./include/CEngine/
        DESTINATION include/CEngine )

install(TARGETS CEngine CEngine-static
		ARCHIVE DESTINATION lib/
		LIBRARY DESTINATION lib/ )
