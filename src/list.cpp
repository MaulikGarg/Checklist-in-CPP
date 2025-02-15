#include "list.h"

#include <iostream>

#include "getInput.h"

// print the list and check if empty
void List::printList() {
  if (m_elements.empty()) {
    std::cout << "This list has no elements!\n";
    return;
  }
  // print the elements in a list format
  size_t i = 0;
  for (const auto& element : m_elements) {
    std::cout << ++i << ". " << element << '\n';
  }
}

// function to add a given element to the list, returns false if the element
// failed to be added in, Only used when loading a list, does not effect status
bool List::addElement(const std::string& element) {
  auto result = m_elements.insert(element);  // attempt to add an element
  // check outcome
  if (!result.second) return false;
  return true;
}

void List::addElement() {
  while (true) {
    std::cout << "Enter the element(Type 0 to eliminate operation): ";
    // get the element to the input
    std::string element{getValidInput::getString(25)};
    // check if the user wishes to terminte
    if (element == "0") return;
    // attempt to insert it into the set of elements, store the resulting pair
    // in 'result'
    auto result = m_elements.insert(element);
    // if result has failed, then print message and continue the loop
    if (!result.second) {
      std::cout << element << " already exists in this list!\n";
      continue;
    }
    //update sync and print message
    m_saveSync = false;
    std::cout << element << " has been added to the list.\n";
  }
}

void List::removeElement() {
  // check if list is empty
  if (m_elements.empty()) {
    std::cout << "Your list is empty!\n";
    return;
  }
  std::cout << "Enter the ID of the element to remove(Type 0 to eliminate "
               "operation): ";
  // get the element id
  int elementID{getValidInput::getInt(0, m_elements.size())};
  // check if the user wishes to terminate
  if (elementID == 0) return;
  // attempt to remove the element from the set
  auto iterator = std::next(m_elements.begin(), elementID - 1);
  m_elements.erase(iterator);
  //update the list's save status code to reflect change
  m_saveSync = false;
  // print success message and the new list
  std::cout << "Element successfully removed.\n";
  printList();
}

//returns the save status of the list save, 1 if synced with save, 0 if not
bool List::showMenu() {
  // put in a loop for current operations. Break when user is done
  while (true) {
    using namespace listOptions;
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
      //return the sync status
        return m_saveSync;
      case options::add:
        addElement();
        break;
      case options::remove:
        removeElement();
        break;
      case options::showElements:
        printList();
        break;
    }
  }
}
