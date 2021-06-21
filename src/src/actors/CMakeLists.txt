target_sources(Arrowpen
    PRIVATE topactors.cpp
)

target_include_directories(Arrowpen
    PRIVATE actortypes    
    PRIVATE actors
    PRIVATE hkactors
)

add_subdirectory(actortypes)
add_subdirectory(actors)
add_subdirectory(hkactors)