#pragma once

#include "eventhandler.hpp"
#include "graphics.hpp"

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
            std::shared_ptr<Graphics> graphics;
            std::shared_ptr<EventHandler> eventHandler;
        };

        const std::vector<std::shared_ptr<Screens::ScreenSelection>> SCREEN_SELECTIONS = {
            std::shared_ptr<Screens::ScreenSelection>(new Screens::ScreenSelection({
                Screens::NULL_SCREEN,
                std::shared_ptr<Graphics>(new Graphics(std::vector<std::shared_ptr<Actor>>({
                    std::shared_ptr<Actor>(new RectangleActor(new Color(0, 0, 0), 0, 0, 200, 2000)),
                    std::shared_ptr<Actor>(new RectangleActor(new Color(255, 0, 0), 200, 0, 200, 2000)),
                    std::shared_ptr<Actor>(new RectangleActor(new Color(0, 255, 0), 400, 0, 200, 2000)),
                    std::shared_ptr<Actor>(new RectangleActor(new Color(0, 0, 255), 600, 0, 200, 2000)),
                    std::shared_ptr<Actor>(new RectangleActor(new Color(255, 255, 0), 800, 0, 200, 2000)),
                    std::shared_ptr<Actor>(new RectangleActor(new Color(255, 0, 255), 1000, 0, 200, 2000)),
                    std::shared_ptr<Actor>(new RectangleActor(new Color(0, 255, 255), 1200, 0, 200, 2000)),
                    std::shared_ptr<Actor>(new RectangleActor(new Color(255, 255, 255), 1400, 0, 2000, 2000)),
                }))),
                std::shared_ptr<EventHandler>(new EventHandler)
            }))
        };

        std::shared_ptr<Screens::ScreenSelection> SelectScreen(Screens::ScreenNames);
    };
};