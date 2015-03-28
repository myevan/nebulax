set(CMAKE_DEBUG_POSTFIX "_d")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
    message("No CMAKE_BUILD_TYPE specified, defaulting to ${CMAKE_BUILD_TYPE}")
endif()

if (APPLE)
    set(XPLATFORM_NAME osx)
    find_library(CORE_FOUNDATION_LIBRARY CoreFoundation)
    mark_as_advanced(CORE_FOUNDATION_LIBRARY)
    set(SYSTEM_LIBS ${CORE_FOUNDATION_LIBRARY})
endif()
