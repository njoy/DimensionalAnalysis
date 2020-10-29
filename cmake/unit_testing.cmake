#######################################################################
# Setup
#######################################################################

message( STATUS "Adding dimwits unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/dimwits/conversion/test )
add_subdirectory( src/dimwits/dimension/test )
add_subdirectory( src/dimwits/math/test )
add_subdirectory( src/dimwits/numeric_limits/test )
add_subdirectory( src/dimwits/quantity/test )
add_subdirectory( src/dimwits/ratio/test )
add_subdirectory( src/dimwits/scale/test )
add_subdirectory( src/dimwits/unit/test )
add_subdirectory( src/test )
