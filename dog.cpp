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

dog* dog::operator=(dog* other) {
    animal::operator=(other);
    knowledge_of_commands = other->knowledge_of_commands;
    return this;
}

int dog::GetOwnerId() {
    return this->owner_id;
}

string dog::GetName() {
    return name;
}