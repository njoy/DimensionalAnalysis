add_executable( ratio.test
                add.test.cpp
                divide.test.cpp
                equality.test.cpp
                greatestCommonFactor.test.cpp
                less.test.cpp
                make.test.cpp
                multiply.test.cpp
                ratio.test.cpp
                reduce.test.cpp
                subtract.test.cpp )
set( test_flags ${dimwits_compiler_flags} )
separate_arguments( test_flags_list UNIX_COMMAND "${test_flags}" )
foreach( flag IN LISTS test_flags_list )
    target_compile_options( ratio.test PUBLIC ${flag} )
endforeach( flag )
set_target_properties( ratio.test PROPERTIES LINK_FLAGS "${test_flags}" )
target_link_libraries( ratio.test PUBLIC dimwits )
add_test( NAME ratio COMMAND ratio.test ) 
