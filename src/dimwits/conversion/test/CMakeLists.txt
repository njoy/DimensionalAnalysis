add_executable( conversion.test
                conversion.test.cpp
                factorValue.test.cpp )
set( test_flags ${dimwits_compiler_flags} )
separate_arguments( test_flags )
foreach( flag IN LISTS test_flags )
    target_compile_options( conversion.test PUBLIC ${flag} )
endforeach( flag )
set_target_properties( conversion.test PROPERTIES LINK_FLAGS "${dimwits_compiler_flags}" )
target_link_libraries( conversion.test PUBLIC dimwits )
add_test( NAME conversion COMMAND conversion.test ) 
