#include "logging.hpp"
#include "screens.hpp"

std::shared_ptr<Static::Screens::Screen> Static::Screens::SelectScreen(Static::Screens::ScreenNames name) {
    for (size_t i = 0; i < Screens::SCREEN_SELECTIONS.size(); ++i) {
        if (Static::Screens::SCREEN_SELECTIONS[i]->screenName == name) {
            return Static::Screens::SCREEN_SELECTIONS[i];
        }
    }
    Logging::Error("Screen name " + std::to_string(name) + " does not exist in screen selections");
    return nullptr;
}