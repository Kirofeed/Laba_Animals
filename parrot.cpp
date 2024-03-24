#include "parrot.h"

string parrot::MakeSound() {
    return "tweet";
}

int parrot::GetAge() {
    return age;
}

string parrot::GetType() {
    return this->type;
}

parrot* parrot::operator=(parrot* other) {
    animal::operator=(other);
    ability_to_speak = other->ability_to_speak;
    return this;
}

int parrot::GetOwnerId() {
    return this->owner_id;
}

string parrot::GetName() {
    return name;
}