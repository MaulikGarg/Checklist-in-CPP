#include "bossList.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "getInput.h"

// give a basic greeting and add a list
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
    // check if the name already exists in the mainlist, if it does, say it out
    // and ask again.
    if (find(mainlist)) {
      std::cout << "That name already exists. Please try again: ";
    } else {
      break;
    }
  }
  //initialize the list!
  mainlist.push_back({name});
  std::cout << "List " << name << " has been created.\n";
  std::cout << "Would you like to add elements to your list (y/n): ";
}

void BossList::removeList() {}

void BossList::showLists() {}

void BossList::getList() {}
