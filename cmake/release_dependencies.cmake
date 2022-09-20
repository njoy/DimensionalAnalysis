cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( hana
    GIT_REPOSITORY  https://github.com/boostorg/hana
    GIT_TAG         07eadfb31eab29ca5548baae34e8d64e25a4c1a3 # tag: boost-1.75.0
    )

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  https://github.com/njoy/catch-adapter
    GIT_TAG         fb84b82ebf7a4789aa43cea560680cf745c6ee4f
    )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    hana
    catch-adapter
    )
