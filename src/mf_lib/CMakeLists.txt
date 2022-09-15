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

# ----------------------------------------------------------------------------
# library
# ----------------------------------------------------------------------------

add_library (libmemoryfails)

set_target_properties (libmemoryfails
    PROPERTIES
        OUTPUT_NAME memoryfails)

target_sources (libmemoryfails
    PRIVATE
        src/memoryfails/Context.cc
        src/memoryfails/trucs/Choux.cc
        src/memoryfails/trucs/Legumes.cc
        src/memoryfails/trucs/Patates.cc
        src/memoryfails/algo/Ainejagne.cc
    )

target_include_directories (libmemoryfails
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
    )

target_link_libraries (libmemoryfails
    PUBLIC
    )

# ============================================================================
# Install configuration
# ============================================================================

install (TARGETS libmemoryfails EXPORT ${PROJECT_NAME}-export)

# FIXME à remplacer par la définition de PUBLIC_HEADERS
install (DIRECTORY src/libmemoryfails
    DESTINATION include
    FILES_MATCHING PATTERN "*.hh"
)

# ----------------------------------------------------------------------------
# Export configuration
# ----------------------------------------------------------------------------

add_library (${PROJECT_NAME}::libmemoryfails ALIAS libmemoryfails)

