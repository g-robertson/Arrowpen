#pragma once

#include "eventhandler.hpp"
#include "graphics.hpp"

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
                std::shared_ptr<Graphics>(new Graphics),
                std::shared_ptr<EventHandler>(new EventHandler)
            }))
        };

        std::shared_ptr<Screens::ScreenSelection> SelectScreen(Screens::ScreenNames);
    };
};