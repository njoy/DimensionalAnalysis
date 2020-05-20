include( FetchContent )


########################################################################
# Forward declarations
########################################################################


########################################################################
# Declare project dependencies
########################################################################

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  http://github.com/njoy/catch-adapter
    GIT_TAG         origin/build/fetchcontent
    )

FetchContent_Declare( hana-adapter
    GIT_REPOSITORY  http://github.com/njoy/hana-adapter
    GIT_TAG         origin/build/fetchcontent
    )


########################################################################
# Load dependencies
########################################################################

FetchContent_MakeAvailable(
    catch-adapter
    hana-adapter
    )
