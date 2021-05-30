# I expect at bare minimum 3 year to date software (2021->2018)
cmake_minimum_required(VERSION 3.13)
# Sorry I really want to use observer_ptr
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adds compile command definitions for vscode
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ARROWPEN_VERSION 0.0.1)

# Project name
project(Arrowpen
    VERSION ${ARROWPEN_VERSION}
    HOMEPAGE_URL https://github.com/g-robertson/arrowpen/
    LANGUAGES C CXX
)

# Add executable
add_executable(Arrowpen src/main.cpp)
# Add src
add_subdirectory(src)
# Add external dependencies
add_subdirectory(extern)

set_target_properties(Arrowpen
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."
)


# Set NDEBUGGING for not debugging, DEBUGGING (anything that isn't NDEBUGGING) for debugging
# It is this way because it makes vscode intellisense easier to work with
add_compile_definitions(DEBUGGING)