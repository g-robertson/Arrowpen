target_sources(Arrowpen
    PRIVATE floatactor.cpp
    PRIVATE topactors.cpp
)

target_include_directories(Arrowpen
    PRIVATE floatactors
    PRIVATE intactors
    PRIVATE hkfloatactors
)
add_subdirectory(floatactors)
add_subdirectory(intactors)
add_subdirectory(hkfloatactors)