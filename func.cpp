#include "animal.h"
#include "cat.h"
#include "dog.h"
//#include "parrot.h"
//#include "fish.h"
#include "animal.cpp"
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

owner *OwnerById(int id) {
    auto vec = owner::Get_list_of_owners();
    for (auto owner: vec) {
        if (owner->GetID() == id) {
            return owner;
        }
    }
    return nullptr;
}


[[maybe_unused]] string NameById([[maybe_unused]] int id) {
    auto vec = owner::Get_list_of_owners();
    for (auto owner: vec) {
        if (owner->GetID() == id) {
            return owner->GetName();
        }
    }
    return "not_found";
}

[[maybe_unused]] void MakeOutFile() {
    ofstream out("output.txt");
    if (!out.is_open()) {
        cerr << "problem with creating output file" << endl;
    }
    auto vec = animal::GetListOfAllAnimals();
    for (auto pet : vec) {
        owner* owner = OwnerById(pet->GetOwnerId());
        out << owner->GetName()<< "; " << owner->GetTelephoneNum() << "; " << owner->GetAdress() << "; " <<
            owner->GetAge() << "; " << pet->GetType() << "; " << pet->GetName() << "; " << pet->GetAge() << "; ";
    }
}


void CountSpeciesByName(string &name) {
    auto vec = animal::GetListOfAllAnimals();
    set<string> pets;
    for (auto pet: vec) {
        if (pet->GetName() == name) {
            pets.emplace(pet->GetType());
        }
    }
    if (pets.size() > 1) {
        cout << pets.size() << " species have name \'" << name << "\'";
    } else if (pets.size() == 1) {
        cout << pets.size() << " species has name \'" << name << "\'";
    } else {
        cout << "Nobody has name \'" << name << "\'";
    }
    cout << endl;
}


void CountDifferentTypesOfSAnimalsForEveryOwner() {
    auto vec = owner::Get_list_of_owners();
    for (const auto owner: vec) {
        set<string> dif_types;
        auto collection = owner->Get_list_of_animals();
        for (auto pet: collection) {
            dif_types.emplace(pet->GetType());
        }
        if (dif_types.size() != 1) {
            cout << owner->GetName() << " has " << dif_types.size() << " different types of animals" << endl;
        } else {
            cout << owner->GetName() << " has " << dif_types.size() << " type of animals" << endl;
        }
    }
    cout << "\n";
}


void AllOwnersOfType(string &type) {
    bool SomebodyHas = false;
    auto vec = owner::Get_list_of_owners();
    for (const auto owner: vec) {
        vector<string> names_of_type;
        auto collection = owner->Get_list_of_animals();
        for (auto pet: collection) {
            if (pet->GetType() == type) {
                names_of_type.push_back(pet->GetName());
            }
        }
        if (!names_of_type.empty()) {
            SomebodyHas = true;
            cout << owner->GetName() << " has ";
            cout << names_of_type[0];
            for (int i = 1; i != names_of_type.size(); ++i) {
                cout << ", " << names_of_type[i];
            }
            cout << endl;
        }
    }
    if (!SomebodyHas) {
        cout << "Nobody has a " << type;
    }
    cout << "\n";
}


owner *OwnersAreSame(string &name, string &telephoneNumber,
                     string &adress, int &age) {
    for (auto it: owner::list_of_owners) {
        if (name == it->name && adress == it->adress &&
            telephoneNumber == it->telephoneNumber && age == it->age) {
            return it;
        }
    }
    return nullptr;
}


void Oldest_Youngest() {
    auto vec = animal::GetListOfAllAnimals();
    set<string> types;
    for (auto pet : vec) {
        types.emplace(pet->GetType());
    }

    for (const auto& type : types) {
        animal* oldest = nullptr;
        animal* youngest = nullptr;
        int maxAge = INT_MIN;
        int minAge = INT_MAX;

        for (auto pet : vec) {
            if (pet->GetType() == type) {
                if (pet->GetAge() > maxAge) {
                    maxAge = pet->GetAge();
                    oldest = pet;
                }
                if (pet->GetAge() < minAge) {
                    minAge = pet->GetAge();
                    youngest = pet;
                }
            }
        }

        if (oldest != nullptr && youngest != nullptr) {
            cout << "Type: " << type << endl;
            cout << "Oldest: " << oldest->GetName() << " (Age: " << oldest->GetAge() << ")" << endl;
            cout << "Youngest: " << youngest->GetName() << " (Age: " << youngest->GetAge() << ")" << endl;
        }
    }
    cout << endl;
}


void ProcessString(string &line) {
    string name;
    string telephoneNumber;
    string adress;
    int age;
    size_t delim;
    delim = line.find(';');
    if (delim > line.size()) {
        return;

    }
    name = line.substr(0, delim);
    line.erase(0, delim + 1);
    while (line[0] == ' ') {
        line.erase(0, 1);
    }

    delim = line.find(';');
    if (delim > line.size()) {
        return;

    }
    telephoneNumber = line.substr(0, delim);
    line.erase(0, delim + 1);
    while (line[0] == ' ') {
        line.erase(0, 1);
    }

    delim = line.find(';');
    if (delim > line.size()) {
        return;
    }
    adress = line.substr(0, delim);
    line.erase(0, delim + 1);
    while (line[0] == ' ') {
        line.erase(0, 1);
    }

    delim = line.find(';');
    if (delim > line.size()) {
        return;
    }
    age = stoi(line.substr(0, delim));
    line.erase(0, delim + 1);
    while (line[0] == ' ') {
        line.erase(0, 1);
    }

    owner *new_owner = OwnersAreSame(name, telephoneNumber, adress, age);
    if (new_owner == nullptr) {
        new_owner = new owner(name, telephoneNumber, adress, age);
        owner::list_of_owners.push_back(new_owner);
    }
    delim = line.find(';');
    if (delim > line.size()) {
        return;
    }
    string type = line.substr(0, delim);
    line.erase(0, delim + 1);
    while (line[0] == ' ') {
        line.erase(0, 1);
    }


    name = "NoName";
    age = -1;
    string sex = "Unkwon";
    string breed = "Unkwon";
    string special;


    delim = line.find(';');
    if (delim > line.size()) {
        return;
    }
    if (delim == 0) {
        line.erase(0, 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    } else {
        name = line.substr(0, delim);
        line.erase(0, delim + 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    }

    delim = line.find(';');
    if (delim > line.size()) {
        return;
    }
    if (delim == 0) {
        line.erase(0, 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    } else {
        age = stoi(line.substr(0, delim));
        line.erase(0, delim + 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    }

    delim = line.find(';');
    if (delim > line.size()) {
        return;
    }
    if (delim == 0) {
        line.erase(0, 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    } else {
        sex = line.substr(0, delim);
        line.erase(0, delim + 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    }

    delim = line.find(';');
    if (delim > line.size()) {
        return;
    }
    if (delim == 0) {
        line.erase(0, 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    } else {
        breed = line.substr(0, delim);
        line.erase(0, delim + 1);
        while (line[0] == ' ') {
            line.erase(0, 1);
        }
    }


    delim = line.find(';');
    if (delim > line.size() && !line.empty()) {
        special = line;
    } else {
        if (delim == 0) {
            line.erase(0, 1);
            while (line[0] == ' ') {
                line.erase(0, 1);
            }
        } else {
            special = line.substr(0, delim);
            line.erase(0, delim + 1);
            while (line[0] == ' ') {
                line.erase(0, 1);
            }
        }
    }


    if (type == "cat") {
        animal *new_pet = new cat(name, age, sex, breed, new_owner->id, special);
        new_owner->add_pet(new_pet);
        animal::all_animals.push_back(new_pet);
    } else if (type == "dog") {
        animal *new_pet = new dog(name, age, sex, breed, new_owner->id, special);
        new_owner->add_pet(new_pet);
        animal::all_animals.push_back(new_pet);
    } else if (type == "parrot") {
        animal *new_pet = new parrot(name, age, sex, breed, new_owner->id, special);
        new_owner->add_pet(new_pet);
        animal::all_animals.push_back(new_pet);
    } else if (type == "fish") {
        animal *new_pet = new fish(name, age, sex, breed, new_owner->id, special);
        new_owner->add_pet(new_pet);
        animal::all_animals.push_back(new_pet);
    }
}


void ReadDataFromFile() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cerr << "problems with opening file" << endl;
    }
    string line;
    while (getline(in, line)) {
        ProcessString(line);
    }
    in.close();
}


void Menu() {
    cout << "\tEnter number of option:\n"
            "1. Count different types of animals for every owner\n"
            "2. For the type of animal print all the owners of this type and names of the animals\n"
            "3. Print how many animals have a concrete name\n"
            "4. Print the information about the oldest and the youngest animal of every type\n"
            "5. To EXIT\n";
    int chosen_num;
    cin >> chosen_num;
    for (int i = 0; i < 88; ++i) {
        cout << '_';
    }
    cout << "\n\n\n";

    switch (chosen_num) {
        case 1: {
            CountDifferentTypesOfSAnimalsForEveryOwner();
            Menu();
            }
        case 2 : {
            string type;
            cout << "enter type of animal: " << endl;
            cin >> type;
            AllOwnersOfType(type);
            Menu();
        }
        case 3: {
            string name;
            cout << "enter name of pet: " << endl;
            cin >> name;
            CountSpeciesByName(name);
            Menu();
        }
        case 4: {
            Oldest_Youngest();
            Menu();
        }
        case 5: {
            return;
        }
        default: {
            cout << "incorrect input" << endl;
            Menu();
        }
    }

}


