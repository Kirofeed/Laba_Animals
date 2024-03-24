#include "fish.h"

string fish::MakeSound() {
    return "gurgle";
}

int fish::GetAge() {
    return age;
}

string fish::GetType() {
    return this->type;
}

fish* fish::operator=(fish* other) {
    animal::operator=(other);
    food_behavior = other->food_behavior;
    return this;
}

int fish::GetOwnerId() {
    return this->owner_id;
}

string fish::GetName() {
    return name;
}