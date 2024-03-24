//
// Created by drozh on 10.03.2024.
//
#pragma once

#include <string>
#include "animal.h"


class dog : public animal {
public:
    dog([[maybe_unused]] string name, int age, [[maybe_unused]] string sex, [[maybe_unused]] string breed, int owner_id, string knowledge_of_commands) :
            animal(std::move(name), age, std::move(sex), std::move(breed), owner_id),
            knowledge_of_commands(std::move(knowledge_of_commands)), type("dog") {}

    ~dog() override = default;

    string MakeSound() override;

    string GetName() override;

    int GetAge() override;
    dog* operator=(dog* other);

    string GetType() override;

    int GetOwnerId() override;

private:
    string knowledge_of_commands;

    string type;
};