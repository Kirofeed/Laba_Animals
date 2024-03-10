#include "cat.h"
string cat::MakeSound() {
    return "meow";
}

int cat::GetAge() {
    return age;
}

string cat::GetType() {
    return this->type;
}

int cat::GetOwnerId() {
    return this->owner_id;
}

string cat::GetName() {
    return name;
}