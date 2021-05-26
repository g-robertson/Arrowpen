target_sources(Arrowpen
    PRIVATE actors.cpp
)

target_include_directories(Arrowpen
    PRIVATE actors
)
add_subdirectory(actors)