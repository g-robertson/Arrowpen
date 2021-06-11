#include "logging.hpp"
#include "screens.hpp"

const std::map<Static::Screens::ScreenNames, std::shared_ptr<Static::Screens::Screen>> Static::Screens::SCREEN_SELECTIONS = {
    std::make_pair<Static::Screens::ScreenNames, std::shared_ptr<Static::Screens::Screen>>(
        Static::Screens::ScreenNames::NULL_SCREEN,
        std::make_unique<Static::Screens::Screen>(Static::Screens::Screen({
            std::make_unique<SDL_Color>(Colors::ERROR),
            std::make_unique<TopActors>(TopActors()),
            std::make_unique<EventHandler>(EventHandler())
        }))
    ),
    std::make_pair<Static::Screens::ScreenNames, std::shared_ptr<Static::Screens::Screen>>(
        Static::Screens::ScreenNames::TEST_SCREEN,
        std::make_unique<Static::Screens::Screen>(Static::Screens::Screen({
            std::make_unique<SDL_Color>(Colors::ERROR),
            std::make_unique<TopActors>(TopActors({
                // primary and secondary colors and white and black
                #define FL(actor) {true, new actor}
                #define INT(actor) {false, new actor}
                FL(FloatRectangleActor(Colors::BLACK, 0, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::RED, 1.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::GREEN, 2.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::BLUE, 3.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::YELLOW, 4.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::PURPLE, 5.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::CYAN, 6.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::WHITE, 7.f/15, 0, 1.f/15, 1)),

                // rainbow
                FL(FloatRectangleActor(Colors::RED, 8.0f/15, 0, 1.f/15, 1)),
                // text between red and orange
                INT(IntScaledTextActor(300, 200, 500, 100, "this should be eaten by orange")),
                FL(FloatRectangleActor(Colors::ORANGE, 9.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::YELLOW, 10.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::GREEN, 11.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::BLUE, 12.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::INDIGO, 13.f/15, 0, 1.f/15, 1)),
                FL(FloatRectangleActor(Colors::PURPLE, 14.f/15, 0, 1.f/15, 1)),

                // grayscale
                FL(FloatRectangleActor(Colors::WHITE, 0, 0, 1.f/16, 1.f/8)),
                FL(FloatRectangleActor(Colors::GRAYCF, (1.f/16) + (0.f/8), 0, 1.f/8, 1.f/8)),
                FL(FloatRectangleActor(Colors::GRAYAF, (1.f/16) + (1.f/8), 0, 1.f/8, 1.f/8)),
                FL(FloatRectangleActor(Colors::GRAY9F, (1.f/16) + (2.f/8), 0, 1.f/8, 1.f/8)),
                FL(FloatRectangleActor(Colors::GRAY7F, (1.f/16) + (3.f/8), 0, 1.f/8, 1.f/8)),
                FL(FloatRectangleActor(Colors::GRAY5F, (1.f/16) + (4.f/8), 0, 1.f/8, 1.f/8)),
                FL(FloatRectangleActor(Colors::GRAY3F, (1.f/16) + (5.f/8), 0, 1.f/8, 1.f/8)),
                FL(FloatRectangleActor(Colors::GRAY1F, (1.f/16) + (6.f/8), 0, 1.f/8, 1.f/8)),
                FL(FloatRectangleActor(Colors::BLACK, (1.f/16) + (7.f/8), 0, 1.f/16, 1.f/8)),

                // pink
                FL(FloatRectangleActor(Colors::PINK, 0, 1.f/8, 1, 1.f/16)),

                FL(FloatScaledTextActor(1.f/8, 0, 1.f/6, 1.f/12, "graphics is my passion")),
                FL(FloatButtonActor(0, 1.f/6, 1.f/3, 1.f/8, "graphics is my passion button")),
                FL(FloatButtonActor(1.f/6, (1.f/6) + (1.f/16), 1.f/3, 1.f/8, "graphics is my overlayed button")),
                INT(IntScaledTextActor(500, 300, 500, 200, "ahhhhhhhh"))
            })),
            std::make_unique<EventHandler>(EventHandler())
        }))
    )
};

std::list<UPtrSDL_Texture> Static::Screens::Init(UPtrSDL_Renderer& renderer) {
    std::list<UPtrSDL_Texture> inittedTextures;
    for (auto screenPair = Static::Screens::SCREEN_SELECTIONS.begin(); screenPair != Static::Screens::SCREEN_SELECTIONS.end(); ++screenPair) {
        auto topActorsInittedTextures = screenPair->second->actors->InitActors(renderer);
        inittedTextures.splice(inittedTextures.end(), topActorsInittedTextures);
    }
    return inittedTextures;
}

Static::Screens::Screen* Static::Screens::SelectScreen(Static::Screens::ScreenNames name) {
    auto found = Static::Screens::SCREEN_SELECTIONS.find(name);
    if (found != Static::Screens::SCREEN_SELECTIONS.end()) {
        return found->second.get();
    }
    Logging::Error("Screen name " + std::to_string(name) + " does not exist in screen selections");
    return Static::Screens::SCREEN_SELECTIONS.find(Static::Screens::ScreenNames::NULL_SCREEN)->second.get();
}