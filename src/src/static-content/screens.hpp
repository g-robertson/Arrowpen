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
            std::unique_ptr<SDL_Color> backgroundColor;
            std::unique_ptr<TopActors> actors;
            std::unique_ptr<EventHandler> eventHandler;
        };

        // todo: figure out how to -- god willing -- make these into unique_ptrs for a perf gain of 0.000017% on application exit
        extern const std::map<Static::Screens::ScreenNames, std::shared_ptr<Static::Screens::Screen>> SCREEN_SELECTIONS;

        std::list<UPtrSDL_Texture> Init(UPtrSDL_Renderer& renderer);

        Static::Screens::Screen* SelectScreen(Screens::ScreenNames);
    };
};