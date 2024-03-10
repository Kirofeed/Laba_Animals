//
// Created by drozh on 20.02.2024.
//
#pragma once
#ifndef LABA_ANIMALS_ANIMAL_H
#define LABA_ANIMALS_ANIMAL_H

#include <iostream>
#include <utility>
#include <vector>


using namespace std;

class animal {
    friend void ProcessString(string &line);

public:
    [[maybe_unused]] virtual string MakeSound() = 0;

    virtual string GetType() = 0;

    virtual string GetName() = 0;

    virtual int GetAge() = 0;

    virtual int GetOwnerId() = 0;

    static vector<animal *> GetListOfAllAnimals();

protected:
    animal(string name, int age, string sex, string breed, int owner_id) :
            name(std::move(name)), age(age), sex(std::move(sex)),
            breed(std::move(breed)), owner_id(owner_id), pet_id(count++) {}

    virtual ~animal() {
        for (auto animal: all_animals) {
            delete animal;
        }
    }

    string name;

    string sex;

    string breed;

    int age;

    int owner_id;

private:

    [[maybe_unused]] int pet_id;

    static int count;

    static vector<animal *> all_animals;
};













//done
class owner {
    friend void ReadDataFromFile();

    friend owner *OwnersAreSame(string &name, string &telephoneNumber,
                                string &adress, int &age);

    friend void ProcessString(string &line);

public:
    owner(string name, string telephoneNumber, string adress, int age) : name(std::move(name)), age(age),
                                                                         telephoneNumber(std::move(telephoneNumber)),
                                                                         adress(std::move(adress)), id(count++) {
    }

    ~owner() {
        for (auto owner: list_of_owners) {
            delete owner;
        }
    }

    void add_pet(animal *);

    static vector<owner *> Get_list_of_owners();

    vector<animal *> Get_list_of_animals();

    string GetName();

    string GetTelephoneNum();

    string GetAdress();

    [[nodiscard]] int GetID() const;

    [[nodiscard]] int GetAge() const;

private:
    static vector<owner *> list_of_owners;

    string name;

    int age;

    string telephoneNumber;

    string adress;

    vector<animal *> animal_collection;

    static int count;

    int id;
};
//done

#endif //LABA_ANIMALS_ANIMAL_H
