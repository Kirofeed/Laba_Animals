#include "cat.h"
string cat::MakeSound() {
    return "meow";
}

int cat::GetAge() {
    return age;
}
cat* cat::operator=(cat* other) {
    animal::operator=(other);
    fur_type = other->fur_type;
    return this;
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