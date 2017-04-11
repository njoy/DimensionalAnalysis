cmake_minimum_required( VERSION 3.2 ) 

if( NOT ROOT_DIRECTORY )
    set( ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )
    if ( NOT fetched_subprojects )
        if ( NOT PYTHON_EXECUTABLE )
            find_package( PythonInterp )
            if ( NOT PYTHONINTERP_FOUND )
                message( FATAL_ERROR "Python interpeter installation was not found." )
            endif()
        endif()
        execute_process( COMMAND ${PYTHON_EXECUTABLE} "./metaconfigure/fetch_subprojects.py"
                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
                         RESULT_VARIABLE fetch_failure )
        if ( NOT fetch_failure )
            set( fetched_subprojects TRUE CACHE BOOL "fetch script ran" )
        else()
            message( FATAL_ERROR "Failed to fetch dependencies" )
        endif()
    endif()
endif()

project( dimwits LANGUAGES CXX )
get_directory_property( is_subproject PARENT_DIRECTORY )
include( CMakeDependentOption REQUIRED )

set( dimwits_Clang_minimum_version 3.8 )
set( dimwits_AppleClang_minimum_version 7.0 )
set( dimwits_GNU_minimum_version 6.2 )

if( dimwits_${CMAKE_CXX_COMPILER_ID}_minimum_version )
    if( CMAKE_CXX_COMPILER_VERSION AND
        CMAKE_CXX_COMPILER_VERSION VERSION_LESS
        ${dimwits_${CMAKE_CXX_COMPILER_ID}_minimum_version} )
        message( FATAL_ERROR "${CMAKE_CXX_COMPILER_ID} version must be greater than ${dimwits_${CMAKE_CXX_COMPILER_ID}_minimum_version}" )
    endif()
endif()

# general properties
option( strict "Compile time warnings are converted to errors" ON )

# binary instrumentation
option( coverage "Enable binary instrumentation to collect test coverage information in the DEBUG configuration" )
option( profile_generate "Enable binary instrumentation to generation execution profiles in the RELEASE configuration which may be used to guide later optimization" )

# additional optimizations
option( link_time_optimization "Enable link time optimization in the RELEASE configuration" )
option( profile_use "In the RELEASE configuration, leverage previously generated exeution profile to inform optimization decisions" )
option( nonportable_optimization "Enable optimizations which compromise portability of resulting binary in the RELEASE configuration" )

# libraries and linking
option( static "Statically link component and environment libraries" OFF )
if ( static AND ( "${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin" ) )
    message( FATAL_ERROR "Static binaries not supported on OSX" )
endif()

CMAKE_DEPENDENT_OPTION( static_libraries "Statically link component libraries" OFF "NOT static" ON )

option( unit_tests "Compile the dimwits unit tests and integrate with ctest" ON ) 

if ( profile_generate AND profile_use )
    message( FATAL_ERROR "Cannot both generate and use execution profile in the same configuration" )
endif()

if ( profile_generate )
    file( MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/profiling" )
endif()

set( dimwits_Clang_Linux_common_flags "-stdlib=libstdc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( dimwits_Clang_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( dimwits_Clang_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( dimwits_Clang_Linux_strict_flags "-Werror" )
set( dimwits_Clang_Linux_coverage_flags "--coverage" )
set( dimwits_Clang_Linux_subproject_flags  )
set( dimwits_Clang_Linux_base_project_flags  )
set( dimwits_Clang_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_Clang_Linux_link_time_optimization_flags "-flto" )
set( dimwits_Clang_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_Clang_Linux_nonportable_optimization_flags "-march=native" )
set( dimwits_Clang_Linux_static_flags "-static" )
set( dimwits_Clang_Windows_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( dimwits_Clang_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( dimwits_Clang_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( dimwits_Clang_Windows_strict_flags "-Werror" )
set( dimwits_Clang_Windows_coverage_flags "--coverage" )
set( dimwits_Clang_Windows_subproject_flags  )
set( dimwits_Clang_Windows_base_project_flags  )
set( dimwits_Clang_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_Clang_Windows_link_time_optimization_flags "-flto" )
set( dimwits_Clang_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_Clang_Windows_nonportable_optimization_flags "-march=native" )
set( dimwits_Clang_Windows_static_flags "-static" )
set( dimwits_Clang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( dimwits_Clang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( dimwits_Clang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( dimwits_Clang_Darwin_strict_flags "-Werror" )
set( dimwits_Clang_Darwin_coverage_flags "--coverage" )
set( dimwits_Clang_Darwin_subproject_flags  )
set( dimwits_Clang_Darwin_base_project_flags  )
set( dimwits_Clang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_Clang_Darwin_link_time_optimization_flags "-flto" )
set( dimwits_Clang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_Clang_Darwin_nonportable_optimization_flags "-march=native" )
set( dimwits_Clang_Darwin_static_flags "-static" )
set( dimwits_AppleClang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( dimwits_AppleClang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( dimwits_AppleClang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( dimwits_AppleClang_Darwin_strict_flags "-Werror" )
set( dimwits_AppleClang_Darwin_coverage_flags "--coverage" )
set( dimwits_AppleClang_Darwin_subproject_flags  )
set( dimwits_AppleClang_Darwin_base_project_flags  )
set( dimwits_AppleClang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_AppleClang_Darwin_link_time_optimization_flags "-flto" )
set( dimwits_AppleClang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_AppleClang_Darwin_nonportable_optimization_flags "-march=native" )
set( dimwits_AppleClang_Darwin_static_flags "-static" )
set( dimwits_GNU_Linux_common_flags "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( dimwits_GNU_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( dimwits_GNU_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( dimwits_GNU_Linux_strict_flags "-Werror" )
set( dimwits_GNU_Linux_coverage_flags "--coverage" )
set( dimwits_GNU_Linux_subproject_flags  )
set( dimwits_GNU_Linux_base_project_flags  )
set( dimwits_GNU_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_GNU_Linux_link_time_optimization_flags "-flto" )
set( dimwits_GNU_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_GNU_Linux_nonportable_optimization_flags "-march=native" )
set( dimwits_GNU_Linux_static_flags "-static" )
set( dimwits_GNU_Windows_common_flags "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( dimwits_GNU_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( dimwits_GNU_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( dimwits_GNU_Windows_strict_flags "-Werror" )
set( dimwits_GNU_Windows_coverage_flags "--coverage" )
set( dimwits_GNU_Windows_subproject_flags  )
set( dimwits_GNU_Windows_base_project_flags  )
set( dimwits_GNU_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_GNU_Windows_link_time_optimization_flags "-flto" )
set( dimwits_GNU_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_GNU_Windows_nonportable_optimization_flags "-march=native" )
set( dimwits_GNU_Windows_static_flags "-static" )
set( dimwits_GNU_Darwin_common_flags "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( dimwits_GNU_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( dimwits_GNU_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( dimwits_GNU_Darwin_strict_flags "-Werror" )
set( dimwits_GNU_Darwin_coverage_flags "--coverage" )
set( dimwits_GNU_Darwin_subproject_flags  )
set( dimwits_GNU_Darwin_base_project_flags  )
set( dimwits_GNU_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_GNU_Darwin_link_time_optimization_flags "-flto" )
set( dimwits_GNU_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( dimwits_GNU_Darwin_nonportable_optimization_flags "-march=native" )
set( dimwits_GNU_Darwin_static_flags "-static" )
get_directory_property( is_subproject PARENT_DIRECTORY )

if( NOT TARGET hana-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/hana-adapter )
endif()

if( NOT TARGET catch-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/catch-adapter )
endif()


if ( NOT GIT_EXECUTABLE )
    find_package( Git )
    if ( NOT GIT_FOUND )
        message( FATAL_ERROR "git installation was not found." )
    endif()
endif()

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
) 

message( STATUS "" )
message( STATUS "-----------------------------------------------------------" )
message( STATUS "" )
message( STATUS "dimwits" )
message( STATUS "Git current branch: ${GIT_BRANCH}" )
message( STATUS "Git commit hash: ${GIT_HASH}" )
message( STATUS "" )
message( STATUS "-----------------------------------------------------------" )

add_library( dimwits INTERFACE )
target_sources( dimwits INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/basis.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/constants.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/conversion.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/dimension.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/math.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/numeric_limits.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/scale.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/dimension/operation.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/dimension/operation/src/definition.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/dimension/operation/src/division.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/dimension/operation/src/exponentiation.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/dimension/operation/src/multiply.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/dimension/src/isBasis.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/Type.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/addition.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/assignment.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/division.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/equality.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/exponentiation.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/less.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/multiplication.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/output.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/subtraction.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/quantity/operation/src/unary.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/add.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/divide.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/equality.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/greatestCommonFactor.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/less.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/make.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/multiply.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/reduce.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/ratio/src/subtract.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/definitions.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/macros.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/operation.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/operation/src/division.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/operation/src/exponentiation.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/operation/src/multiply.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/src/dimensionality.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/src/isComposite.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/src/referenceUnit.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/dimwits/unit/src/symbol.hpp" )

target_include_directories( dimwits INTERFACE src )

set( PREFIX dimwits_${CMAKE_CXX_COMPILER_ID}_${CMAKE_SYSTEM_NAME} )

target_link_libraries( dimwits INTERFACE "$<$<AND:$<CONFIG:RELEASE>,$<BOOL:${link_time_optimization}>>:${${PREFIX}_RELEASE_flags};${${PREFIX}_link_time_optimization_flags}$<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags};>$<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags};>$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags};>>$<$<CONFIG:DEBUG>:$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags};>>$<$<BOOL:CXX_appended_flags>:${CXX_appended_flags};>$<$<BOOL:dimwits_appended_flags>:${dimwits_appended_flags};>" )

target_link_libraries( dimwits INTERFACE hana-adapter INTERFACE catch-adapter )

if( NOT is_subproject )
    enable_testing() 
    if ( unit_tests )
        add_subdirectory( src/dimwits/ratio/test )
        add_subdirectory( src/dimwits/unit/test )
        add_subdirectory( src/dimwits/numeric_limits/test )
        add_subdirectory( src/dimwits/quantity/test )
        add_subdirectory( src/dimwits/dimension/test )
        add_subdirectory( src/dimwits/basis/test )
        add_subdirectory( src/dimwits/math/test )
        add_subdirectory( src/dimwits/conversion/test )
        add_subdirectory( src/dimwits/scale/test )
    endif() 
endif()

install( DIRECTORY src DESTINATION include
         FILE_PERMISSIONS OWNER_READ OWNER_WRITE 
                          GROUP_READ 
                          WORLD_READ
         DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE 
                               GROUP_READ 
                               WORLD_READ
         FILES_MATCHING REGEX ".*\.h++|.*\.hxx|.*\.hpp|.*\.hh|.*\.h"  )
