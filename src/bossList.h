#ifndef BOSS_LIST_H
#define BOSS_LIST_H
#include <array>
#include <map>

#include "list.h"

namespace bosslistOptions {
using namespace std::literals;
enum options {
  exit,
  add,
  remove,
  show,
  showListOperations,
  save,
  max,
};
constexpr std::array str_options{"Exit Menu"sv,         "Add a list"sv,
                                 "Remove a list"sv,     "Show current lists"sv,
                                 "Perform on a list"sv, "Save"sv};

static_assert(max == std::size(str_options));
}  // namespace bosslistOptions

// main list of all the available lists
class BossList {
 private:
 // bool to keep track if any data has been changed since last save, used for saving prompts
 bool m_saveSynced{true}; 
  // list of our Lists: Name + vector of elements
  std::map<std::string, List> m_mainlist;
  // returns true if the list is empty
  bool isListEmpty();

 public:
  // default constructor, when invoked, asks for a file name and opens main
  // menu.
  BossList();
  // default destructor, writes the current bosslist to a file for savinf
  ~BossList();
  // adds a list to the main list
  void addList();
  // removes a list from the main list
  void removeList();
  // shows all available lists
  void showLists();
  // shows a basic menu with add/remove/view list
  void showMenu();
  // shows a specific list from the list collection
  void getList();
  // saves the bosslist to a file
  void saveList();
};

#endif
