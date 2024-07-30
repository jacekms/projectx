cmake_minimum_required(VERSION 3.10)

# Project name
project(MiningSimulation)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(src)
include_directories(src/infra)
include_directories(src/stats)

# Source files
set(SOURCES
    src/main.cpp
    src/mining_truck.cpp
    src/mining_unload_station.cpp
    #src/event.cpp
    src/event_sequencer.cpp
    #src/random_duration_generator.cpp
    src/simulation.cpp
    src/infra/infra.cpp
    src/stats/mining_truck_stats.cpp
    src/stats/unload_station_stats.cpp
    src/stats/simulation_stats.cpp
)

# Infra source files
set(INFRA_SOURCES
    src/infra/sim_step_clock.hpp
    src/infra/logger.hpp
    src/infra/sh3m_assert.hpp
    src/infra/infra.hpp
)

# Option to enable debug build with gdb
#option(ENABLE_GDB "Enable GDB debugging" ON)
option(ENABLE_GDB "Enable GDB debugging" OFF)

if (ENABLE_GDB)
    message(STATUS "GDB debugging enabled")
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
else()
    message(STATUS "GDB debugging disabled")
endif()

# Compiler warning flags for GCC
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(
        -Wall -Wextra -Wpedantic -Werror -Wconversion -Wsign-conversion
        -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
        -Wunused -Woverloaded-virtual -Wnull-dereference
        -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches
        -Wlogical-op -Wuseless-cast -Wno-unused-parameter -Wfloat-equal
        -Wpointer-arith -Wcast-qual -Wswitch-enum -Wstrict-null-sentinel
        -Wstrict-overflow=5 -Wundef -Wno-endif-labels -Wstrict-aliasing
        -Wredundant-decls -Wctor-dtor-privacy -Wzero-as-null-pointer-constant
        -Wuseless-cast -Wvector-operation-performance -Wc++17-compat
    )
endif()

# Executables
add_executable(sim_h3_mining ${SOURCES})
add_executable(demo_sim_step_clock src/infra/demo/demo_sim_step_clock.cpp ${INFRA_SOURCES})
add_executable(demo_log src/infra/demo/demo_log.cpp ${INFRA_SOURCES})
