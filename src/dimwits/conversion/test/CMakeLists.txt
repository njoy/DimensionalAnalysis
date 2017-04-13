
add_executable( dimwits.conversion.test
                conversion.test.cpp
                factorValue.test.cpp )
target_compile_options( dimwits.conversion.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${dimwits_appended_flags} )
target_link_libraries( dimwits.conversion.test PUBLIC dimwits ) 
add_test( NAME dimwits.conversion COMMAND dimwits.conversion.test )