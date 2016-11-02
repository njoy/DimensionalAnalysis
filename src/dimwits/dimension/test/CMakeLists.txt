add_executable( dimension.test
                dimension.test.cpp
                isBasis.test.cpp
                operation.test.cpp )
set( test_flags ${dimwits_compiler_flags} )
separate_arguments( test_flags_list UNIX_COMMAND "${test_flags}" )
foreach( flag IN LISTS test_flags_list )
    target_compile_options( dimension.test PUBLIC ${flag} )
endforeach( flag )
set_target_properties( dimension.test PROPERTIES LINK_FLAGS "${test_flags}" )
target_link_libraries( dimension.test PUBLIC dimwits )
add_test( NAME dimension COMMAND dimension.test ) 
