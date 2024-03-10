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

int fish::GetOwnerId() {
    return this->owner_id;
}

string fish::GetName() {
    return name;
}