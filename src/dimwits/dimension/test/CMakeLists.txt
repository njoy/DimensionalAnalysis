
add_executable( dimwits.dimension.test
                isBasis.test.cpp
                dimension.test.cpp
                operation.test.cpp )
target_compile_options( dimwits.dimension.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${dimwits_appended_flags} )
target_link_libraries( dimwits.dimension.test PUBLIC dimwits ) 
add_test( NAME dimwits.dimension COMMAND dimwits.dimension.test )