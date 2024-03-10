#include "dog.h"

string dog::MakeSound() {
    return "woof";
}

int dog::GetAge() {
    return age;
}

string dog::GetType() {
    return type;
}

int dog::GetOwnerId() {
    return this->owner_id;
}

string dog::GetName() {
    return name;
}