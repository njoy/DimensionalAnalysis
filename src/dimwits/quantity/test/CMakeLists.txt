add_executable( quantity.test
                operations.test.cpp
                quantity.test.cpp )
set( test_flags ${dimwits_compiler_flags} )
separate_arguments( test_flags )
foreach( flag IN LISTS test_flags )
    target_compile_options( quantity.test PUBLIC ${flag} )
endforeach( flag )
set_target_properties( quantity.test PROPERTIES LINK_FLAGS "${dimwits_compiler_flags}" )
target_link_libraries( quantity.test PUBLIC dimwits )
add_test( NAME quantity COMMAND quantity.test ) 
