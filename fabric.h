#pragma once
#include "cat.h"
#include "dog.h"
#include "fish.h"
#include "parrot.h"

class Fabric {   
    virtual animal* Create(string name, int age, string sex, string breed, int owner_id, string special) = 0;

};



class CatFabric : public Fabric {
    public:
    animal* Create(string name, int age, string sex, string breed, int owner_id, string special) override {
        return new cat(name, age, sex, breed, owner_id, special);
    }
};

class DogFabric : public Fabric {
    public:
    animal* Create(string name, int age, string sex, string breed, int owner_id, string special) override {
        return new dog(name, age, sex, breed, owner_id, special);
    }
};

class ParrotFabric : public Fabric {
    public:
    animal* Create(string name, int age, string sex, string breed, int owner_id, string special) override {
        return new parrot(name, age, sex, breed, owner_id, special);
    }
};

class FishFabric : public Fabric {
    public:
    animal* Create(string name, int age, string sex, string breed, int owner_id, string special) override {
        return new fish(name, age, sex, breed, owner_id, special);
    }
};

