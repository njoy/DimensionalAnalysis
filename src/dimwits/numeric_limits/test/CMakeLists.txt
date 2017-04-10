
add_executable( dimwits.numeric_limits.test numeric_limits.test.cpp )
target_compile_options( dimwits.numeric_limits.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${dimwits_appended_flags} )
target_link_libraries( dimwits.numeric_limits.test PUBLIC dimwits ) 
add_test( NAME dimwits.numeric_limits COMMAND dimwits.numeric_limits.test )