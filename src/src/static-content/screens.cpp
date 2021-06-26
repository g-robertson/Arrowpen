#include "logging.hpp"
#include "screens.hpp"

#include "button.hpp"
#include "rectangle.hpp"
#include "scaledtext.hpp"

#define FL(actor) {true, new actor}
#define INT(actor) {false, new actor}

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
                FL(RectangleActor(new FloatActor(0, 0, 1.f/15, 1), Colors::BLACK)),
                FL(RectangleActor(new FloatActor(1.f/15, 0, 1.f/15, 1), Colors::RED)),
                FL(RectangleActor(new FloatActor(2.f/15, 0, 1.f/15, 1), Colors::GREEN)),
                FL(RectangleActor(new FloatActor(3.f/15, 0, 1.f/15, 1), Colors::BLUE)),
                FL(RectangleActor(new FloatActor(4.f/15, 0, 1.f/15, 1), Colors::YELLOW)),
                FL(RectangleActor(new FloatActor(5.f/15, 0, 1.f/15, 1), Colors::PURPLE)),
                FL(RectangleActor(new FloatActor(6.f/15, 0, 1.f/15, 1), Colors::CYAN)),
                FL(RectangleActor(new FloatActor(7.f/15, 0, 1.f/15, 1), Colors::WHITE)),

                // rainbow
                FL(RectangleActor(new FloatActor(8.0f/15, 0, 1.f/15, 1), Colors::RED)),
                // text between red and orange
                INT(ScaledTextActor(new IntActor(300, 200, 500, 100), "this should be eaten by orange")),
                FL(RectangleActor(new FloatActor(9.f/15, 0, 1.f/15, 1), Colors::ORANGE)),
                FL(RectangleActor(new FloatActor(10.f/15, 0, 1.f/15, 1), Colors::YELLOW)),
                FL(RectangleActor(new FloatActor(11.f/15, 0, 1.f/15, 1), Colors::GREEN)),
                FL(RectangleActor(new FloatActor(12.f/15, 0, 1.f/15, 1), Colors::BLUE)),
                FL(RectangleActor(new FloatActor(13.f/15, 0, 1.f/15, 1), Colors::INDIGO)),
                FL(RectangleActor(new FloatActor(14.f/15, 0, 1.f/15, 1), Colors::PURPLE)),

                // grayscale
                FL(RectangleActor(new FloatActor(0, 0, 1.f/16, 1.f/8), Colors::WHITE)),
                FL(RectangleActor(new FloatActor((1.f/16) + (0.f/8), 0, 1.f/8, 1.f/8), Colors::GRAYCF)),
                FL(RectangleActor(new FloatActor((1.f/16) + (1.f/8), 0, 1.f/8, 1.f/8), Colors::GRAYAF)),
                FL(RectangleActor(new FloatActor((1.f/16) + (2.f/8), 0, 1.f/8, 1.f/8), Colors::GRAY9F)),
                FL(RectangleActor(new FloatActor((1.f/16) + (3.f/8), 0, 1.f/8, 1.f/8), Colors::GRAY7F)),
                FL(RectangleActor(new FloatActor((1.f/16) + (4.f/8), 0, 1.f/8, 1.f/8), Colors::GRAY5F)),
                FL(RectangleActor(new FloatActor((1.f/16) + (5.f/8), 0, 1.f/8, 1.f/8), Colors::GRAY3F)),
                FL(RectangleActor(new FloatActor((1.f/16) + (6.f/8), 0, 1.f/8, 1.f/8), Colors::GRAY1F)),
                FL(RectangleActor(new FloatActor((1.f/16) + (7.f/8), 0, 1.f/16, 1.f/8), Colors::BLACK)),

                // pink
                FL(RectangleActor(new FloatActor(0, 1.f/8, 1, 1.f/16), Colors::PINK)),

                FL(ScaledTextActor(new FloatActor(1.f/8, 0, 1.f/6, 1.f/12), "graphics is my passion")),
                FL(ButtonActor<FloatActor>(new FloatActor(0, 1.f/6, 1.f/3, 1.f/8), "graphics is my passion button")),
                FL(ButtonActor<FloatActor>(new FloatActor(1.f/6, (1.f/6) + (1.f/16), 1.f/3, 1.f/8), "graphics is my overlayed button")),
                INT(ScaledTextActor(new IntActor(500, 300, 500, 200), "ahhhhhhhh"))
            })),
            std::make_unique<EventHandler>(EventHandler())
        }))
    )
};

#undef FL
#undef INT


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