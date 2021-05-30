#pragma once

#include "helpers.hpp"

#include "topactors.hpp"
#include "actor.hpp"

#include "button.hpp"
#include "floatscaledtext.hpp"
#include "floatrectangle.hpp"

#include <memory>
#include <vector>

namespace Static {
    namespace Screens {
        enum ScreenNames {
            NULL_SCREEN,
            TEST_SCREEN
        };

        struct Screen {
            Screens::ScreenNames screenName;
            std::unique_ptr<SDL_Color> backgroundColor;
            std::unique_ptr<TopActors> actors;
            std::unique_ptr<EventHandler> eventHandler;
        };


        const std::vector<std::shared_ptr<Screens::Screen>> SCREEN_SELECTIONS = {
            std::make_shared<Screens::Screen>(Screens::Screen({
                Screens::NULL_SCREEN,
                std::make_unique<SDL_Color>(Colors::ERROR),
                std::make_unique<TopActors>(TopActors()),
                std::make_unique<EventHandler>(EventHandler())
            })),
            std::make_shared<Screens::Screen>(Screens::Screen({
                Screens::TEST_SCREEN,
                std::make_unique<SDL_Color>(Colors::ERROR),
                std::make_unique<TopActors>(TopActors({
                    // primary and secondary colors and white and black
                    
                    new FloatRectangleActor(Colors::BLACK, 0, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::RED, 1.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::GREEN, 2.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::BLUE, 3.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::YELLOW, 4.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::PURPLE, 5.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::CYAN, 6.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::WHITE, 7.f/15, 0, 1.f/15, 1),

                    // rainbow
                    new FloatRectangleActor(Colors::RED, 8.0f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::ORANGE, 9.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::YELLOW, 10.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::GREEN, 11.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::BLUE, 12.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::INDIGO, 13.f/15, 0, 1.f/15, 1),
                    new FloatRectangleActor(Colors::PURPLE, 14.f/15, 0, 1.f/15, 1),

                    // grayscale
                    new FloatRectangleActor(Colors::WHITE, 0, 0, 1.f/16, 1.f/8),
                    new FloatRectangleActor(Colors::GRAYCF, (1.f/16) + (0.f/8), 0, 1.f/8, 1.f/8),
                    new FloatRectangleActor(Colors::GRAYAF, (1.f/16) + (1.f/8), 0, 1.f/8, 1.f/8),
                    new FloatRectangleActor(Colors::GRAY9F, (1.f/16) + (2.f/8), 0, 1.f/8, 1.f/8),
                    new FloatRectangleActor(Colors::GRAY7F, (1.f/16) + (3.f/8), 0, 1.f/8, 1.f/8),
                    new FloatRectangleActor(Colors::GRAY5F, (1.f/16) + (4.f/8), 0, 1.f/8, 1.f/8),
                    new FloatRectangleActor(Colors::GRAY3F, (1.f/16) + (5.f/8), 0, 1.f/8, 1.f/8),
                    new FloatRectangleActor(Colors::GRAY1F, (1.f/16) + (6.f/8), 0, 1.f/8, 1.f/8),
                    new FloatRectangleActor(Colors::BLACK, (1.f/16) + (7.f/8), 0, 1.f/16, 1.f/8),

                    // pink
                    new FloatRectangleActor(Colors::PINK, 0, 1.f/8, 1, 1.f/16),

                    new ScaledTextActor(1.f/8, 0, 1.f/6, 1.f/12, "graphics is my passion"),
                    new ButtonActor(0, 1.f/6, 1.f/3, 1.f/8, "graphics is my passion button"),
                    new ButtonActor(1.f/6, (1.f/6) + (1.f/16), 1.f/3, 1.f/8, "graphics is my overlayed button")
                })),
                std::make_unique<EventHandler>(EventHandler())
            }))
        };

        std::weak_ptr<Screens::Screen> SelectScreen(Screens::ScreenNames);
    };
};