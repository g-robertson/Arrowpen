#pragma once

#include "helpers.hpp"

#include "eventhandler.hpp"

#include "actors.hpp"
#include "actor.hpp"
#include "rectangle.hpp"

#include <memory>
#include <vector>

namespace Static {
    namespace Screens {
        enum ScreenNames {
            NULL_SCREEN
        };

        struct ScreenSelection {
            Screens::ScreenNames screenName;
            std::shared_ptr<ActorsActor> actors;
            std::shared_ptr<EventHandler> eventHandler;
        };


        const std::vector<std::shared_ptr<Screens::ScreenSelection>> SCREEN_SELECTIONS = {
            std::shared_ptr<Screens::ScreenSelection>(new Screens::ScreenSelection({
                Screens::NULL_SCREEN,
                std::shared_ptr<ActorsActor>(new ActorsActor(std::initializer_list<Actor*> {
                    new RectangleActor(Colors::BLACK, 0, 0, 100, 2000),
                    // primary and secondary colors and white and black
                    new RectangleActor(Colors::BLACK, 0, 0, 100, 2000),
                    new RectangleActor(Colors::RED, 1*100, 0, 100, 2000),
                    new RectangleActor(Colors::GREEN, 2*100, 0, 100, 2000),
                    new RectangleActor(Colors::BLUE, 3*100, 0, 100, 2000),
                    new RectangleActor(Colors::YELLOW, 4*100, 0, 100, 2000),
                    new RectangleActor(Colors::PURPLE, 5*100, 0, 100, 2000),
                    new RectangleActor(Colors::CYAN, 6*100, 0, 100, 2000),
                    new RectangleActor(Colors::WHITE, 7*100, 0, 100, 2000),

                    // rainbow
                    new RectangleActor(Colors::RED, 8*100, 0, 100, 2000),
                    new RectangleActor(Colors::ORANGE, 9*100, 0, 100, 2000),
                    new RectangleActor(Colors::YELLOW, 10*100, 0, 100, 2000),
                    new RectangleActor(Colors::GREEN, 11*100, 0, 100, 2000),
                    new RectangleActor(Colors::BLUE, 12*100, 0, 100, 2000),
                    new RectangleActor(Colors::INDIGO, 13*100, 0, 100, 2000),
                    new RectangleActor(Colors::PURPLE, 14*100, 0, 100, 2000),

                    // grayscale
                    new RectangleActor(Colors::WHITE, 0, 0, 50, 200),
                    new RectangleActor(Colors::GRAYCF, 50 + (0 * 200), 0, 200, 200),
                    new RectangleActor(Colors::GRAYAF, 50 + (1 * 200), 0, 200, 200),
                    new RectangleActor(Colors::GRAY9F, 50 + (2 * 200), 0, 200, 200),
                    new RectangleActor(Colors::GRAY7F, 50 + (3 * 200), 0, 200, 200),
                    new RectangleActor(Colors::GRAY5F, 50 + (4 * 200), 0, 200, 200),
                    new RectangleActor(Colors::GRAY3F, 50 + (5 * 200), 0, 200, 200),
                    new RectangleActor(Colors::GRAY1F, 50 + (6 * 200), 0, 200, 200),
                    new RectangleActor(Colors::BLACK, 50 + (7 * 200), 0, 50, 200),

                    // pink
                    new RectangleActor(Colors::PINK, 0, 200, 1500, 50)
                })),
                std::shared_ptr<EventHandler>(new EventHandler)
            }))
        };

        std::shared_ptr<Screens::ScreenSelection> SelectScreen(Screens::ScreenNames);
    };
};