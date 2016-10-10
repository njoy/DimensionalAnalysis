add_executable( unit.test
                dimensionality.test.cpp
                isComposite.test.cpp
                referenceUnit.test.cpp
                symbol.test.cpp
                unit.test.cpp )
set( test_flags ${dimwits_compiler_flags} )
separate_arguments( test_flags )
foreach( flag IN LISTS test_flags )
    target_compile_options( unit.test PUBLIC ${flag} )
endforeach( flag )
set_target_properties( unit.test PROPERTIES LINK_FLAGS "${dimwits_compiler_flags}" )
target_link_libraries( unit.test PUBLIC dimwits )
add_test( NAME unit COMMAND unit.test ) 
