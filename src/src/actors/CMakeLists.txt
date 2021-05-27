target_sources(Arrowpen
    PRIVATE actors.cpp
)

target_include_directories(Arrowpen
    PRIVATE actors
    PRIVATE hkactors
)
add_subdirectory(actors)
add_subdirectory(hkactors)