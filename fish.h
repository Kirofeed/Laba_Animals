#pragma once
#include <string>
#include "animal.h"

class fish : public animal {
public:
    fish([[maybe_unused]] string name, int age, [[maybe_unused]] string sex, [[maybe_unused]] string breed, int owner_id, string food_behavior) :
            animal(std::move(name), age, std::move(sex), std::move(breed), owner_id),
            food_behavior(std::move(food_behavior)), type("fish") {}

    ~fish() override = default;

    string MakeSound() override;

    string GetName() override;

    int GetAge() override;

    fish* operator=(fish* other);

    string GetType() override;

    int GetOwnerId() override;

private:
    string food_behavior;

    string type;
};