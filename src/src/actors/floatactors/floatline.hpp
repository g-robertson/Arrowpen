#pragma once
#include "actor.hpp"

class LineActor : public Actor {
    public:
        LineActor();
        void Draw(UPtrSDL_Renderer& renderer);
        NoHandle();
};