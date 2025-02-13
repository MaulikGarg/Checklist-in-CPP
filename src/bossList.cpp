#include "bossList.h"

#include <iostream>
#include <map>
#include <string>

#include "getInput.h"
#include "list.h"

BossList::BossList() {
  std::cout << "Welcome to the list manager! \n";
  addList();
}

// adds a list to the bosslist set whilst checking for duplicate names and
// sortion
void BossList::addList() {
  std::cout
      << "Please type in the name of your list(type 0 to cancel operation): ";
  std::string name{};
  // loop until we get a valid name for our new list
  while (true) {
    name = getValidInput::getString();
    // checks if the user wishes to cancel the operation
    if (name == "0") {
      std::cout << "operation cancelled.\n";
      return;
    }
    // checks if the mainlist already has the list
    if (mainlist.find(name) != mainlist.end()) {
      std::cout << "That list already exists, please try again: ";
      continue;
    } else {
      mainlist.insert({name, List{}});
      break;
    }
  }
  std::cout << "List " << name << " has been created.\n";
  std::cout << "Would you like to add elements to your list (y/n): ";
  // stores the response of the user
  char response = getValidInput::getChar(std::string{"ynYN"});
  if (response == 'y' || response == 'Y') {
    mainlist[name].addElement();
  }
  return;
}

// removes a specific list from the bosslist
void BossList::removeList() {
  std::cout << "Please enter the name of the string you would like to "
               "remove(type 0 to cancel operation): ";
  std::string name{getValidInput::getString()};
  // check if the user wishes to cancel operation
  if (name == "0") {
    std::cout << "Operation cancelled.\n";
    return;
  }
  // lookup the name in the list of lists
  auto removable_it{mainlist.find(name)};
  // if the list does not exist, print a message and return
  if (removable_it == mainlist.end()) {
    std::cout << "That list does not exist.\n";
    return;
  }
  // remove the element from the map
  mainlist.erase(removable_it);
  std::cout << "List " << name << " has been removed.\n";
}

// shows all the lists currently saved to the disk
void BossList::showLists() {
  // count to keep track of the number of lists
  int count{};
  for (const auto& i : mainlist) {
    std::cout << ++count << ". " << i.first << '\n';
  }
}

void BossList::getList() {}
