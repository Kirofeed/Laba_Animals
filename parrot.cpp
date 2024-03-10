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

int parrot::GetOwnerId() {
    return this->owner_id;
}

string parrot::GetName() {
    return name;
}