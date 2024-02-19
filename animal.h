//
// Created by drozh on 20.02.2024.
//

#ifndef LABA_ANIMALS_ANIMAL_H
#define LABA_ANIMALS_ANIMAL_H
#include <iostream>
#include <utility>
#include <vector>

using namespace std;



class animal {
    friend void ProcessString(string& line);
public:
    virtual string MakeSound() =0;
    virtual string GetType() =0;
    virtual string GetName() =0;
    virtual int GetAge() =0;
    virtual int GetOwnerId() =0;
    static vector<animal*> GetListOfAllAnimals();
protected:
    animal(string name, int age, string sex, string breed,  int owner_id) :
    name(std::move(name)), age(age), sex(std::move(sex)), breed(std::move(breed)), owner_id(owner_id), pet_id(count++){}
    virtual ~animal() {
        for (auto animal : all_animals) {
            delete animal;
        }
    }
    string name;
    string sex;
    string breed;
    int age;
    int owner_id;
private:
    int pet_id;
    static int count;
    static vector<animal*> all_animals;
};

class cat : public animal{
public:
    cat(string name, int age, string sex, string breed,  int owner_id, string fur_type) :
    animal(std::move(name), age, std::move(sex), std::move(breed), owner_id), fur_type(std::move(fur_type)), type("cat") {}
    ~cat() override = default;
    string MakeSound() override;
    string GetType() override;
    string GetName() override;
    int GetAge() override;
    int GetOwnerId() override;

private:
    string fur_type;
    string type;
};


class dog : public animal{
public:
    dog(string name, int age, string sex, string breed,  int owner_id, string knowledge_of_commands) :
    animal(std::move(name), age, std::move(sex), std::move(breed), owner_id), knowledge_of_commands(std::move(knowledge_of_commands)), type("dog") {}
    ~dog() override = default;
    string MakeSound() override;
    string GetName() override;
    int GetAge() override;
    string GetType() override;
    int GetOwnerId() override;

private:
    string knowledge_of_commands;
    string type;
};


class parrot : public animal{
public:
    parrot(string name, int age, string sex, string breed,  int owner_id, string ability_to_speak) :
    animal(std::move(name), age, std::move(sex), std::move(breed), owner_id), ability_to_speak(std::move(ability_to_speak)), type("parrot") {}
    ~parrot() override = default;
    string MakeSound() override;
    string GetName() override;
    int GetAge() override;
    string GetType() override;
    int GetOwnerId() override;

private:
    string ability_to_speak;
    string type;
};


class fish : public animal{
public:
    fish(string name, int age, string sex, string breed,  int owner_id, string food_behavior) :
    animal(std::move(name), age, std::move(sex), std::move(breed), owner_id), food_behavior(std::move(food_behavior)), type("fish") {}
    ~fish() override = default;
    string MakeSound() override;
    string GetName() override;
    int GetAge() override;
    string GetType() override;
    int GetOwnerId() override;

private:
    string food_behavior;
    string type;
};



//done
class owner {
    friend void ReadDataFromFile();
    friend owner* OwnersAreSame( string& name, string& telephoneNumber,
                               string& adress, int& age);
    friend void ProcessString(string& line);
public:
    owner(string name, string telephoneNumber, string adress, int age) : name(std::move(name)), age(age),
    telephoneNumber(std::move(telephoneNumber)), adress(std::move(adress)), id(count++) {
    }
    ~owner() {
        for (auto owner : list_of_owners) {
            delete owner;
        }
    }
    void add_pet(animal*);
    static vector<owner*> Get_list_of_owners();
    vector<animal*> Get_list_of_animals();
    string GetName();
    int GetID();

private:
    static vector<owner*> list_of_owners;
    string name;
    int age;
    string telephoneNumber;
    string adress;
    vector<animal*> animal_collection;
    static int count;
    int id;
};
//done

#endif //LABA_ANIMALS_ANIMAL_H
