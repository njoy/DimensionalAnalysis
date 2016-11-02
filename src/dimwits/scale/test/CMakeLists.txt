add_executable( scale.test
                dimensionality.test.cpp
                factor.test.cpp
                referenceUnitRatio.test.cpp
                scale.test.cpp
                symbol.test.cpp )
set( test_flags ${dimwits_compiler_flags} )
separate_arguments( test_flags_list UNIX_COMMAND "${test_flags}" )
foreach( flag IN LISTS test_flags_list )
    target_compile_options( scale.test PUBLIC ${flag} )
endforeach( flag )
set_target_properties( scale.test PROPERTIES LINK_FLAGS "${test_flags}" )
target_link_libraries( scale.test PUBLIC dimwits )
add_test( NAME scale COMMAND scale.test ) 
