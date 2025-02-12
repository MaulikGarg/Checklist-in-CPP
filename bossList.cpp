#include "bossList.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "getInput.h"

BossList::BossList() {
  std::cout << "Welcome to the list manager! \n";
  addList();
}

void BossList::addList() {
  std::cout << "Please type in the name of your list: ";
  std::string name{};
  // loop until we get a valid name for our new list
  while (true) {
    name = getValidInput::getString();
    bool alreadyExists{false};
    // check if the name already exists in the mainlist, if it does, say it out
    // and ask again.
    for (const auto& i : mainlist) {
      if (i.getName() == name){
        alreadyExists = true;
        break;
      }
    }
    if(!alreadyExists) break;
  }
  // initialize the list!
  mainlist.push_back({name});
  std::cout << "List " << name << " has been created.\n";
  std::cout << "Would you like to add elements to your list (y/n): ";
}

void BossList::removeList() {}

void BossList::showLists() {}

void BossList::getList() {}
