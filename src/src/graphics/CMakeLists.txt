target_sources(Arrowpen
    PRIVATE color.cpp
    PRIVATE graphics.cpp
)

target_include_directories(Arrowpen
    PRIVATE actors
)
add_subdirectory(actors)