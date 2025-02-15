#include "bossList.h"

#include <iostream>

#include "fileIO.h"
#include "getInput.h"
#include "list.h"

BossList::BossList() {
  // ask user for their mainlist file name and make a json object of it
  std::cout << "Please enter the name of your collection file(type 0 to create "
               "new): ";
  filename = getValidInput::getString(25);
  // if the user wishes to load, open the file and load data
  if (!(filename == "0")) {
    // retrieve data from a file
    fileIO::json data;
    fileIO::readJSON(data, filename);
    // add data to the mainlist
    // picks a [listname, list] pair from the file's data
    for (const auto& [key, value] : data.items()) {
      List temporary;  // temporary list to add our iterated list elements to
      // picks an element from list and inserts it into temporary
      for (const auto& i : value) {
        if (!(temporary.addElement(i))) {
          std::cout << "Warning: Skipping bad element in list '" << key
                    << "'\n";
          continue;  // Skip bad elements, but continue loading others
        }
      }
      // insert the temporary list to the mainlist
      m_mainlist[key] = temporary;
    }
  } else {
    //if its a new file
    std::cout << "New empty list made successfully!\n";
  }
  showMenu();
}

// check if the list is empty, if so, say it and return true
bool BossList::isListEmpty() {
  if (m_mainlist.empty()) {
    std::cout << "Your collection is empty, try adding some lists!\n";
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
    name = getValidInput::getString(25);
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
  // update the sync variable to represent change
  m_saveSynced = false;
  std::cout << "Would you like to add elements to your new list (y/n): ";
  // stores the response of the user
  char response = getValidInput::getChar(std::string{"ynYN"});
  if (response == 'y' || response == 'Y') {
    m_mainlist[name].addElement();  // add elements to the newly made list
  }
  return;
}

// removes a specific list from the bosslist
void BossList::removeList() {
  if (isListEmpty()) return;
  std::cout << "\nPlease enter the name of the list you would like to "
               "remove(type 0 to cancel operation): ";
  std::string name{getValidInput::getString(25)};
  // check if the user wishes to cancel operation
  if (name == "0") {
    std::cout << "\nOperation cancelled.\n";
    return;
  }
  // if the list erasure fails, then it must not exist
  if (!m_mainlist.erase(name)) {
    std::cout << "\nThat list does not exist.\n";
    return;
  }
  // if we have reached here, the list has been removed.
  std::cout << "\nList " << name << " has been removed.\n";
  // update sync variable to represent change
  m_saveSynced = false;
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

// retrieves a specific list from a menu
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
  // after coming back, check if the selected list was modified
  // showMenu returns the list's save status (1 if synced)
  if (!iterator->second.showMenu()) m_saveSynced = false;
}

// show main menu for current boss list
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
      case options::save:
        saveList();
        break;
    }
  }
}

void BossList::saveList() {
  // if the mainlist is already saved, return
  if (m_saveSynced) {
    std::cout << "Your collection is already in sync.\n";
    return;
  }

  // lambda expression for the saving process
  auto save{[&]() {
    fileIO::writeJSON(this->m_mainlist, filename);
    // file save is successful and mainlist is now in sync!
    m_saveSynced = true;
    std::cout << "Save Success!\n";
  }};

  // if the user created a new list, ask for file name and save, else ask if
  // they would like to save to previously opened list, 0 indicates new
  if (filename != "0") {
    // ask the user if they would like to save to the file that was originally
    // opened
    std::cout << "Would you like to save to file " << filename << " ?(y/n)\n> ";
    char response = getValidInput::getChar(std::string{"ynYN"});
    // if the user wishes so, jump to saving
    if (response == 'Y' || response == 'y'){
      save();
      return;
    };
  }
  // ask for a valid new file name
  std::cout << "Name of the file to save to: ";
  // get the name of the file to write to and save to that file
  do {
    filename = getValidInput::getString(25);
    // since 0 is our indicator for new lists, it cannot be the file name
    if (filename == "0") std::cout << "Filename cannot be that. Try again: ";
  } while (filename == "0");

  save();
}

// saves the list before exiting just incase
BossList::~BossList() {
  // check if it is an empty collection
  if (m_mainlist.empty()) {
    std::cout << "Warning: Empty collection detected, no autosave.\n";
    return;
  }

  // if the current mainlist is not in sync with save, save it before exiting
  if (!m_saveSynced) saveList();
}
