#include "bossList.h"

#include <iostream>
#include <map>
#include <string>
#include <set>

#include "getInput.h"
#include "list.h"

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
    //insert the element into the set, if successful return true
    //since this is a set, it will also check for duplication
    auto ins = mainlist.insert(List{name});
    //check if the insertion pair returned true
    if(ins.second) break;
    else std::cout << "That list already exists, please try again: ";
  }
  std::cout << "List " << name << " has been created.\n";
  std::cout << "Would you like to add elements to your list (y/n): ";
  // stores the response of the user
  char response = getValidInput::getChar(std::string{"ynYN"});
  if (response == 'y' || response == 'Y') {
  }
  return;
}

void BossList::removeList() {}

void BossList::showLists() {}

void BossList::getList() {}
