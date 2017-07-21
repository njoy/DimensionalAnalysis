
add_executable( dimwits.scale.test
                scale.test.cpp
                symbol.test.cpp
                dimensionality.test.cpp
                factor.test.cpp
                referenceUnitRatio.test.cpp )
target_compile_options( dimwits.scale.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${dimwits_appended_flags} )
target_link_libraries( dimwits.scale.test PUBLIC dimwits ) 
add_test( NAME dimwits.scale COMMAND dimwits.scale.test )