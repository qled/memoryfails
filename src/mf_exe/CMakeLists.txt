# ============================================================================
# CMake configuration
# ============================================================================

cmake_minimum_required (VERSION 3.19.0)

# ============================================================================
# External requirements
# ============================================================================

# ============================================================================
# Targets configuration
# ============================================================================

add_executable (exememoryfails)

set_target_properties (exememoryfails
    PROPERTIES
        OUTPUT_NAME memoryfails
    )

target_sources (exememoryfails
    PRIVATE
        src/main.cc
    )

target_include_directories (exememoryfails
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_link_libraries (exememoryfails
    PUBLIC
        libmemoryfails
    )

# ============================================================================
# Install configuration
# ============================================================================

install (TARGETS exememoryfails EXPORT ${PROJECT_NAME}-export)

# ----------------------------------------------------------------------------
# Export configuration
# ----------------------------------------------------------------------------

add_executable (${PROJECT_NAME}::exememoryfails ALIAS exememoryfails)