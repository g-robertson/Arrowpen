target_sources(Arrowpen
    PRIVATE topactors.cpp
)

target_include_directories(Arrowpen
    PRIVATE actortypes    
    PRIVATE actors
    PRIVATE floatactors
    PRIVATE intactors
    PRIVATE refactors
    PRIVATE hkactors
    PRIVATE hkfloatactors
    PRIVATE hkintactors
)

add_subdirectory(actortypes)
add_subdirectory(actors)
add_subdirectory(floatactors)
add_subdirectory(intactors)
add_subdirectory(refactors)
add_subdirectory(hkactors)
add_subdirectory(hkfloatactors)
add_subdirectory(hkintactors)