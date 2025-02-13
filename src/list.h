#ifndef LIST_H
#define LIST_H

#include <set>
#include <string>
class List {
 private:
  std::set<std::string> m_elements{};

 public:
  // shows all the elements in the list
  void printList();
  // adds element(s) to the list
  void addElement();
  // removes an element to the list
  void removeElement();
};

#endif
