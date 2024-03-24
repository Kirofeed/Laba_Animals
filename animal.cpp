//
// Created by drozh on 20.02.2024.
//

#include "animal.h"
#include <sstream>
#include <vector>

using namespace std;



int animal::count = 0;

vector<animal *> animal::all_animals;

vector<animal *> animal::GetListOfAllAnimals() {
    return all_animals;
}

animal* animal::operator=(const animal* other) {
    pet_id = other->pet_id;
    owner_id = other->owner_id;
    name = other->name;
    age = other->age;
    sex = other->sex;
    breed = other->breed;
    return this;
}
animal* animal::operator = (animal&& other) {
    pet_id = move(other.pet_id);
    owner_id = move(other.owner_id);
    name = move(other.name);
    age = move(other.age);
    sex = move(other.sex);
    breed = move(other.breed);
    return this;
}












void owner::add_pet(animal *pet) {
    animal_collection.push_back(pet);
}

vector<owner *> owner::list_of_owners;
int owner::count = 0;

vector<owner *> owner::Get_list_of_owners() {
    return list_of_owners;
}

string owner::GetName() {
    return this->name;
}

int owner::GetID() const {
    return this->id;
}

int owner::GetAge() const {
    return this->age;
}

string owner::GetTelephoneNum() {
    return this->telephoneNumber;
}

string owner::GetAdress() {
    return this->adress;
}

vector<animal *> owner::Get_list_of_animals() {
    return this->animal_collection;
}

