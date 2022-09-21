cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  https://github.com/njoy/catch-adapter
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( hana
    GIT_REPOSITORY  https://github.com/boostorg/hana
    GIT_TAG         boost-1.77.0
    GIT_SHALLOW     TRUE
    )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    catch-adapter
    hana
    )
