target_sources(Arrowpen
    PRIVATE logging.cpp
    PRIVATE helpers.cpp
)

target_include_directories(Arrowpen
    PRIVATE sdlhelp
    PRIVATE sm
    PRIVATE window
    PRIVATE graphics
    PRIVATE events
    PRIVATE static-content
)

add_subdirectory(sdlhelp)
add_subdirectory(sm)
add_subdirectory(window)
add_subdirectory(graphics)
add_subdirectory(events)
add_subdirectory(static-content)