cmake_minimum_required(VERSION 3.10)
project("Code Kata")

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD 23)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /EHsc")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()
file(GLOB_RECURSE SOURCEFILES CONFIGURE_DEPENDS src/*)
add_library(Library ${SOURCEFILES})
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(ext)

file(GLOB_RECURSE UNITTESTFILES CONFIGURE_DEPENDS tests/*)
add_executable(unittests ${UNITTESTFILES})

target_link_libraries(unittests Library Catch2::Catch2WithMain)

	