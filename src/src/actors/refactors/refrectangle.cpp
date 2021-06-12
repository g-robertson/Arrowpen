#include "refrectangle.hpp"

RefRectangleActor::RefRectangleActor(std::unique_ptr<SDL_Color> c, const SDL_Rect* rect, bool filled) :
RefActor(rect), RectangleActor(std::move(c), filled) {}

RefRectangleActor::RefRectangleActor(std::unique_ptr<SDL_Color> c, std::unique_ptr<SDL_Rect>& rect, bool filled) :
RefActor(rect), RectangleActor(std::move(c), filled) {}

RefRectangleActor::RefRectangleActor(const SDL_Color& c, std::unique_ptr<SDL_Rect>& rect, bool filled) :
RefRectangleActor(std::make_unique<SDL_Color>(c), rect, filled) {}