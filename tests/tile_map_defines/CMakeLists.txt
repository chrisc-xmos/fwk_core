cmake_minimum_required(VERSION 3.23)

## Disable in-source build to reduce version control issues.
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In-source build is not allowed! Please specify a build folder.\n\tex:cmake -B build")
endif()

## Project name declaration
project(tile_map_defines_test)
set (APPLICATION_NAME map_test)

## Enable languages for the project
enable_language(C)

## Import some helpful build macros
#include(modules/fwk_rtos/tools/cmake_utils/xmos_macros.cmake)


## Gather customer source files
#file(GLOB_RECURSE APP_SOURCES
#  ${CMAKE_CURRENT_LIST_DIR}/../../src/tile_map.xc
#  ${CMAKE_CURRENT_LIST_DIR}/../../src/tile_map_defaults.c
#  ${CMAKE_CURRENT_LIST_DIR}/src/*.c
#)
#set (APP_SOURCES ${CMAKE_CURRENT_LIST_DIR}/../../src/tile_map_defaults.c)
set (APP_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/test.c)

## Set directory for customer header files
set(APP_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/src)

## Set tile usage list to use as a foreach loop variable
## This is application and device specific
set(MAX_TILES 2)
#set(MAX_TILES 4)
math(EXPR COMBINATION_RANGE "(1<<${MAX_TILES}) - 1" OUTPUT_FORMAT DECIMAL)
math(EXPR TILE_RANGE "${MAX_TILES} - 1" OUTPUT_FORMAT DECIMAL)

set (APP_LINK_LIBRARIES framework_core_multitile_support)

## Compiler flags. Note that .xscope and .xn files are added here.
set(APP_COMPILER_FLAGS
    -Os
    -g
    -report
    -mcmodel=large
    -Wno-xcore-fptrgroup
    -target=XCORE-AI-EXPLORER
    -v
)

## Link flags. Note that .xscope and .xn files are also added here.
set(APP_LINK_OPTIONS
    -lquadflash
    -report
    -target=XCORE-AI-EXPLORER
)


## Compilation settings.
set(APP_COMPILE_DEFINITIONS 
  DEBUG_PRINT_ENABLE=1 
  XUD_CORE_CLOCK=600
  MINIMISE_MAIN_TILE_ARGS 
)

foreach(USES RANGE ${COMBINATION_RANGE})
  foreach(SUPPORTS RANGE ${COMBINATION_RANGE})
  
    # Include any set where at least one tile is supported AND used.
    math(EXPR TEST_TILES "${SUPPORTS} & ${USES} & ${COMBINATION_RANGE}" OUTPUT_FORMAT DECIMAL)
    
    # Exclude any set where an unsupported tile is used.
    math(EXPR NOT_TEST_TILES "(~${SUPPORTS} & ${COMBINATION_RANGE}) & ${USES}" OUTPUT_FORMAT DECIMAL)
    
    # Set compiler definitions that are constant for all tests
    set(APP_COMPILE_DEFINITIONS ${BASE_APP_COMPILE_DEFINITIONS})
    
    # Set 
    if (NOT(${TEST_TILES} EQUAL 0) AND (${NOT_TEST_TILES} EQUAL 0))
    
      set(TARGET map_test_${USES}_${SUPPORTS})
      add_executable(${TARGET})
      message(${TARGET})
      
      target_sources(${TARGET} PUBLIC ${APP_SOURCES})
      message(APP_SOURCES: ${APP_SOURCES})
      
      target_include_directories(${TARGET} PUBLIC ${APP_INCLUDES})
      message(APP_INCLUDES: ${APP_INCLUDES})
      
      target_compile_definitions(${TARGET} PUBLIC ${APP_COMPILE_DEFINITIONS})
      message(APP_COMPILE_DEFINITIONS: ${APP_COMPILE_DEFINITIONS})
        
        
      foreach(TILE RANGE ${TILE_RANGE})
        math(EXPR USES_TILE " ${USES} & ( 1 << ${TILE} )" OUTPUT_FORMAT DECIMAL)
        
        if (USES_TILE EQUAL 0)
            target_compile_definitions(${TARGET} PUBLIC "PLATFORM_USES_TILE_${TILE}=0")
            message("PLATFORM_USES_TILE_${TILE}=0")
        else()
            target_compile_definitions(${TARGET} PUBLIC "PLATFORM_USES_TILE_${TILE}=1")
            message("PLATFORM_USES_TILE_${TILE}=1")
        endif()
        
        math(EXPR SUPPORTS_TILE "${SUPPORTS} & (1 << ${TILE} )" OUTPUT_FORMAT DECIMAL)
        
        if (SUPPORTS_TILE EQUAL 0)
            target_compile_definitions(${TARGET} PUBLIC "PLATFORM_SUPPORTS_TILE_${TILE}=0")
            message("PLATFORM_SUPPORTS_TILE_${TILE}=0")
        else()
            target_compile_definitions(${TARGET} PUBLIC "PLATFORM_SUPPORTS_TILE_${TILE}=1")
            message("PLATFORM_SUPPORTS_TILE_${TILE}=1")
        endif()
      endforeach()
      
      target_compile_options(${TARGET} PRIVATE ${APP_COMPILER_FLAGS})
      message(APP_COMPILER_FLAGS: ${APP_COMPILER_FLAGS})
      
      target_link_libraries(${TARGET} PUBLIC ${APP_LINK_LIBRARIES})
      message(APP_LINK_LIBRARIES: ${APP_LINK_LIBRARIES})
      
      target_link_options(${TARGET} PRIVATE ${APP_LINK_OPTIONS})    
      message(APP_LINK_OPTIONS: ${APP_LINK_OPTIONS})
      
     
    endif()
  endforeach()
endforeach()




## Create run and debug targets
#create_run_target(${APPLICATION_NAME})
#create_debug_target(${APPLICATION_NAME})
#create_flash_app_target(${APPLICATION_NAME})
#create_install_target(${APPLICATION_NAME})
