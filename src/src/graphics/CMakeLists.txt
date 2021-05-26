target_sources(Arrowpen
    PRIVATE color.cpp
    PRIVATE actors.cpp
)

target_include_directories(Arrowpen
    PRIVATE actors
)
add_subdirectory(actors)