cmake_minimum_required(VERSION 3.16) 

project(MonteCarloOptionPricer VERSION 1.0.0 LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(option_pricer
	src/option.cpp
) 

target_include_directories(option_pricer
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(option_pricer_cli
    src/main.cpp
)

target_link_libraries(option_pricer_cli
    PRIVATE option_pricer
)

enable_testing()

add_executable(option_tests
    tests/test_option.cpp
)

target_link_libraries(option_tests
    PRIVATE option_pricer
)

add_test(
    NAME option_tests
    COMMAND option_tests
)
