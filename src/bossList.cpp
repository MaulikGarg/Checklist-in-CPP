#include "bossList.h"

#include <../lib/json.hpp>
#include <iostream>

#include "getInput.h"
#include "list.h"

BossList::BossList() {
  std::cout << "Welcome to the list manager! \n";
  showMenu();
}

bool BossList::isListEmpty() {
  if (m_mainlist.empty()) {
    std::cout << "Your list is empty!\n";
    return true;
  }
  return false;
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
    if (m_mainlist.find(name) != m_mainlist.end()) {
      std::cout << "That list already exists, please try again: ";
      continue;
    }
    m_mainlist.insert({name, List{}});
    break;
  }
  std::cout << "\nList " << name << " has been created.\n";
  std::cout << "Would you like to add elements to your list (y/n): ";
  // stores the response of the user
  char response = getValidInput::getChar(std::string{"ynYN"});
  if (response == 'y' || response == 'Y') {
    m_mainlist[name].addElement();
  }
  return;
}

// removes a specific list from the bosslist
void BossList::removeList() {
  if (isListEmpty()) return;
  std::cout << "\nPlease enter the name of the list you would like to "
               "remove(type 0 to cancel operation): ";
  std::string name{getValidInput::getString()};
  // check if the user wishes to cancel operation
  if (name == "0") {
    std::cout << "\nOperation cancelled.\n";
    return;
  }
  if (!m_mainlist.erase(name)) {
    std::cout << "\nThat list does not exist.\n";
    return;
  }
  std::cout << "\nList " << name << " has been removed.\n";
}

// shows all the lists currently saved to the disk
void BossList::showLists() {
  // if list count is zero
  if (isListEmpty()) return;
  // count to keep track of the number of lists
  int count{};
  std::cout << "\n===Lists===\n";
  for (const auto& i : m_mainlist) {
    std::cout << ++count << ". " << i.first << '\n';
  }
}

void BossList::getList() {
  // check if bosslist is empty
  if (isListEmpty()) return;
  std::cout << "Enter the ID of the list which you would like to perform on: ";
  // get the id of the list which they would like to view
  int id = getValidInput::getInt(1, m_mainlist.size());
  // make an iterator (0 based) and move it ahead id-1 times to allign with the
  // intended element of the user
  auto iterator = std::next(m_mainlist.begin(), id - 1);
  // display the name of the list
  std::cout << "\n===List " << iterator->first << "===\n";
  iterator->second.showMenu();
}

void BossList::showMenu() {
  // put in a loop for current operations. Break when user is done
  while (true) {
    using namespace bosslistOptions;
    std::cout << "\n=== Available Operations ===\n";
    // prints all the available options from the namespace
    for (size_t i{0}; i < std::size(str_options); i++) {
      std::cout << i << ". " << str_options[i] << '\n';
    }
    std::cout
        << "\nPlease enter the ID of the operation you would like to perform: ";

    // get a response and act on it.
    switch (static_cast<options>(
        getValidInput::getInt(options::exit, options::max - 1))) {
      case options::exit:
        std::cout << "Exiting the program!\n";
        return;
      case options::add:
        addList();
        break;
      case options::remove:
        removeList();
        break;
      case options::show:
        showLists();
        break;
      case options::showListOperations:
        getList();
        break;
    }
  }
}
