#pragma once
#include <string>
#include "animal.h"


class parrot : public animal {
public:
    parrot([[maybe_unused]] string name, int age, [[maybe_unused]] string sex, [[maybe_unused]] string breed, int owner_id, string ability_to_speak) :
            animal(std::move(name), age, std::move(sex), std::move(breed), owner_id),
            ability_to_speak(std::move(ability_to_speak)), type("parrot") {}

    ~parrot() override = default;

    string MakeSound() override;

    string GetName() override;

    int GetAge() override;

    parrot* operator=(parrot* other);

    string GetType() override;

    int GetOwnerId() override;

private:
    string ability_to_speak;

    string type;
};
