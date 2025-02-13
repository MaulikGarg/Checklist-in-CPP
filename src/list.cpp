#include "list.h"

#include <iostream>

#include "getInput.h"

void List::printList() {
  size_t i = 0;
  for (const auto& element : m_elements) {
    std::cout << ++i << ". " << element << '\n';
  }
}

void List::addElement() {
  while (true) {
    std::cout << "Enter the element(Type 0 to eliminate operation): ";
    // get the element to the input
    std::string element{getValidInput::getString()};
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
  auto iterator = std::next(m_elements.begin(), elementID-1);
  m_elements.erase(iterator);
  // print success message and the new list
  std::cout << "Element successfully removed.\n";
  this->printList();
}
