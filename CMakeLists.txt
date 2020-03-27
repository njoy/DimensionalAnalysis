project( dimwits )

if( NOT DEFINED dimwits_DEPENDENCIES )
    set( dimwits_DEPENDENCIES TRUE )
endif()

add_library( dimwits INTERFACE )
target_include_directories( dimwits INTERFACE src/ )
target_link_libraries( dimwits INTERFACE catch-adapter INTERFACE hana-adapter )
