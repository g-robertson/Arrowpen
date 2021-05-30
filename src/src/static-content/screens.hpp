#pragma once

#include "helpers.hpp"

#include "eventhandler.hpp"

#include "topactors.hpp"
#include "actor.hpp"

#include "button.hpp"
#include "scaledtext.hpp"
#include "rectangle.hpp"

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
            std::shared_ptr<SDL_Color> backgroundColor;
            std::shared_ptr<TopActors> actors;
            std::shared_ptr<EventHandler> eventHandler;
        };


        const std::vector<std::shared_ptr<Screens::Screen>> SCREEN_SELECTIONS = {
            std::shared_ptr<Screens::Screen>(new Screens::Screen({
                Screens::NULL_SCREEN,
                SharedNewPtr(SDL_Color, Colors::ERROR),
                SharedNewPtr(TopActors),
                SharedNewPtr(EventHandler)
            })),
            std::shared_ptr<Screens::Screen>(new Screens::Screen({
                Screens::TEST_SCREEN,
                SharedNewPtr(SDL_Color, Colors::ERROR),
                std::shared_ptr<TopActors>(new TopActors(std::initializer_list<FloatActor*> {
                    // primary and secondary colors and white and black
                    new RectangleActor(Colors::BLACK, 0, 0, 1.f/15, 1),
                    new RectangleActor(Colors::RED, 1.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::GREEN, 2.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::BLUE, 3.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::YELLOW, 4.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::PURPLE, 5.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::CYAN, 6.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::WHITE, 7.f/15, 0, 1.f/15, 1),

                    // rainbow
                    new RectangleActor(Colors::RED, 8.0f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::ORANGE, 9.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::YELLOW, 10.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::GREEN, 11.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::BLUE, 12.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::INDIGO, 13.f/15, 0, 1.f/15, 1),
                    new RectangleActor(Colors::PURPLE, 14.f/15, 0, 1.f/15, 1),

                    // grayscale
                    new RectangleActor(Colors::WHITE, 0, 0, 1.f/16, 1.f/8),
                    new RectangleActor(Colors::GRAYCF, (1.f/16) + (0.f/8), 0, 1.f/8, 1.f/8),
                    new RectangleActor(Colors::GRAYAF, (1.f/16) + (1.f/8), 0, 1.f/8, 1.f/8),
                    new RectangleActor(Colors::GRAY9F, (1.f/16) + (2.f/8), 0, 1.f/8, 1.f/8),
                    new RectangleActor(Colors::GRAY7F, (1.f/16) + (3.f/8), 0, 1.f/8, 1.f/8),
                    new RectangleActor(Colors::GRAY5F, (1.f/16) + (4.f/8), 0, 1.f/8, 1.f/8),
                    new RectangleActor(Colors::GRAY3F, (1.f/16) + (5.f/8), 0, 1.f/8, 1.f/8),
                    new RectangleActor(Colors::GRAY1F, (1.f/16) + (6.f/8), 0, 1.f/8, 1.f/8),
                    new RectangleActor(Colors::BLACK, (1.f/16) + (7.f/8), 0, 1.f/16, 1.f/8),

                    // pink
                    new RectangleActor(Colors::PINK, 0, 1.f/8, 1, 1.f/16),

                    new ScaledTextActor(1.f/8, 0, 1.f/6, 1.f/12, "graphics is my passion"),
                    new ButtonActor(0, 1.f/6, 1.f/3, 1.f/8, "graphics is my passion button"),
                    new ButtonActor(1.f/6, (1.f/6) + (1.f/16), 1.f/3, 1.f/8, "graphics is my overlayed button")
                })),
                std::shared_ptr<EventHandler>(new EventHandler)
            }))
        };

        std::shared_ptr<Screens::Screen> SelectScreen(Screens::ScreenNames);
    };
};