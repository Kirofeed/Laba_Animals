//
// Created by drozh on 10.03.2024.
//
#pragma once

#include <string>
#include "animal.h"




class cat : public animal {
public:
    cat([[maybe_unused]] string name, int age, [[maybe_unused]] string sex, [[maybe_unused]] string breed, int owner_id, string fur_type) :
            animal(std::move(name), age, std::move(sex), std::move(breed), owner_id), fur_type(std::move(fur_type)),
            type("cat") {}

    ~cat() override = default;

    string MakeSound() override;

    cat* operator=(cat* other);

    string GetType() override;                                                                         

    string GetName() override;

    int GetAge() override;

    int GetOwnerId() override;

private:

    string fur_type;

    string type;
};