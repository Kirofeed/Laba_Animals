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

