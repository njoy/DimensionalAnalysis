########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.14 )
project( dimwits LANGUAGES CXX )

########################################################################
# Dependencies
########################################################################

include( cmake/dimwits_dependencies.cmake )

########################################################################
# Project targets
########################################################################

add_library( dimwits INTERFACE )
target_include_directories( dimwits INTERFACE src/ )
target_link_libraries( dimwits
    INTERFACE catch-adapter
    INTERFACE hana-adapter
    )
