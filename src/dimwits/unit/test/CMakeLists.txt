
add_executable( dimwits.unit.test
                symbol.test.cpp
                dimensionality.test.cpp
                referenceUnit.test.cpp
                isComposite.test.cpp
                unit.test.cpp )
target_compile_options( dimwits.unit.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${dimwits_appended_flags} )
target_link_libraries( dimwits.unit.test PUBLIC dimwits ) 
add_test( NAME dimwits.unit COMMAND dimwits.unit.test )