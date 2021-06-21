#include "typedactor.hpp"

TypedActor<RefActor>::TypedActor() {
    this->actor = std::unique_ptr<RefActor, RefActor_Destroy>(new RefActor());
}

TypedActor<RefActor>::TypedActor(RefActor* actor) {
    this->actor = std::unique_ptr<RefActor, RefActor_Destroy>(actor);
}

TypedActor<IntActor>::TypedActor() {
    this->actor = std::unique_ptr<IntActor, IntActor_Destroy>(new IntActor());
}

TypedActor<IntActor>::TypedActor(IntActor* actor) {
    this->actor = std::unique_ptr<IntActor, IntActor_Destroy>(actor);
}

TypedActor<FloatActor>::TypedActor() {
    this->actor = std::unique_ptr<FloatActor, FloatActor_Destroy>(new FloatActor());
}

TypedActor<FloatActor>::TypedActor(FloatActor* actor) {
    this->actor = std::unique_ptr<FloatActor, FloatActor_Destroy>(actor);
}