cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  https://github.com/njoy/catch-adapter
    GIT_TAG         fb84b82ebf7a4789aa43cea560680cf745c6ee4f
    )

FetchContent_Declare( hana
    GIT_REPOSITORY  https://github.com/boostorg/hana
    GIT_TAG         5c28aad03b6e157452d8623802d70dc95a7b57b6 # tag: boost-1.77.0
    )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    catch-adapter
    hana
    )
