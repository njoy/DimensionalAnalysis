
add_executable( dimwits.ratio.test
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
target_compile_options( dimwits.ratio.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${dimwits_appended_flags} )
target_link_libraries( dimwits.ratio.test PUBLIC dimwits ) 
add_test( NAME dimwits.ratio COMMAND dimwits.ratio.test )