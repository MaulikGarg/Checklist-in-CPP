#ifndef BOSS_LIST_H
#define BOSS_LIST_H
#include <vector>

#include "list.h"
// main list of all the available lists
class BossList {
 private:
  //list of our Lists: Name + vector of elements
  std::vector<List> mainlist;
 public:
  // default constructor, when invoked, asks for a list.
  BossList();
  // adds a list to the main list
  void addList();
  // removes a list from the main list
  void removeList();
  // shows all available lists
  void showLists();
  // shows a specific list from the list of lists
  void getList();
};

#endif
