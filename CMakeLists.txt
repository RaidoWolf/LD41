cmake_minimum_required (VERSION 3.10)

# build type selection
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

# notify of the build type in use
message (STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# project definition
set (LD41_VERSION_MAJOR 0)
set (LD41_VERSION_MINOR 0)
set (LD41_VERSION_PATCH 0)
project (
    LD41
    VERSION ${LD41_VERSION_MAJOR}.${LD41_VERSION_MINOR}.${LD41_VERSION_PATCH}
    DESCRIPTION "Step-by-Step Deathmatch - Ludum Dare 41 game by Alexander Barber"
)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
set (CMAKE_CXX_FLAGS_DEBUG "-g -Og")
set (CMAKE_CXX_FLAGS_RELEASE "-O3")
configure_file (
    ${PROJECT_SOURCE_DIR}/include/LD41.hpp.in
    ${PROJECT_BINARY_DIR}/include/LD41.hpp
)
include_directories (
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
)

# debug mode testing/analysis
unset (CMAKE_CXX_CPPCHECK CACHE)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message (STATUS "Testing/Analysis Enabled")
    find_program (CMAKE_CXX_CPPCHECK NAMES cppcheck)
    if (CMAKE_CXX_CPPCHECK)
        list (APPEND CMAKE_CXX_CPPCHECK
            "--enable=warning"
            "--inconclusive"
            "--force"
            "--inline-suppr"
        )
    else ()
        message (WARNING "Could not find CPPCheck executive. CPPCheck testing disabled.")
    endif ()
else ()
    message (STATUS "Testing/Analysis Disabled")
    set (CMAKE_CXX_CPPCHECK)
endif ()

# sources list
list (APPEND SOURCES

    # game code
    ${PROJECT_SOURCE_DIR}/src/LoadingState.cpp
    ${PROJECT_SOURCE_DIR}/src/MenuState.cpp
    ${PROJECT_SOURCE_DIR}/src/PlayingState.cpp

    # entry point
    ${PROJECT_SOURCE_DIR}/src/main.cpp

)

# executable output
set (EXECUTABLE_NAME "LD41")
add_executable (${EXECUTABLE_NAME} ${SOURCES})

# cmake modules
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKES_MODULE_PATH})

# dependencies
find_package (ArcticWolf)
target_link_libraries (${EXECUTABLE_NAME} ArcticWolf)

# installation
install (TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# packaging
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE)
set (CPACK_PACKAGE_VERSION_MAJOR ${LD41_VERSION_MAJOR})
set (CPACK_PACKAGE_VERSION_MINOR ${LD41_VERSION_MINOR})
set (CPACK_PACKAGE_VERSION_PATCH ${LD41_VERSION_PATCH})
include (CPack)
