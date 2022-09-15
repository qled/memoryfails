# ============================================================================
# CMake configuration
# ============================================================================

cmake_minimum_required (VERSION 3.19.0)

# ============================================================================
# Project configuration
# ============================================================================

project(memoryfails VERSION 0.0 LANGUAGES CXX)

# library behaviour
set (CMAKE_FIND_PACKAGE_SORT_ORDER NATURAL)
set (CMAKE_FIND_PACKAGE_SORT_DIRECTION DEC)

# ============================================================================
# Compiler configurations
# ============================================================================

# ----------------------------------------------------------------------------
# Compilation settings
# ----------------------------------------------------------------------------
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSION OFF)

# options a activer pour asan
#add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
#add_link_options(-fsanitize=address -fno-omit-frame-pointer)

# ----------------------------------------------------------------------------
# Install
# ----------------------------------------------------------------------------
set (ConfigPackageLocation "lib/cmake/${PROJECT_NAME}-${PROJECT_VERSION}")

install (FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}-config-version.cmake"
        DESTINATION "${ConfigPackageLocation}"
    )

install (EXPORT ${PROJECT_NAME}-export
        FILE ${PROJECT_NAME}-targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION "${ConfigPackageLocation}"
    )

# ============================================================================
# Targets configurations
# ============================================================================

add_subdirectory(src)