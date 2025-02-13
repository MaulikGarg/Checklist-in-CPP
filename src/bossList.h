#ifndef BOSS_LIST_H
#define BOSS_LIST_H
#include <map>
#include <array>
#include "list.h"

namespace bosslistOptions {
using namespace std::literals;
constexpr std::array options{"Exit Menu"sv, "Add a list"sv, "Remove a list"sv,
                             "Show current lists"sv};
}  // namespace bosslistOptions

// main list of all the available lists
class BossList {
 private:
  // list of our Lists: Name + vector of elements
  std::map<std::string, List> mainlist;

 public:
  // default constructor, when invoked, asks for a list.
  BossList();
  // adds a list to the main list
  void addList();
  // removes a list from the main list
  void removeList();
  // shows all available lists
  void showLists();
  // shows a basic menu with add/remove/view list
  void showMenu();
};

#endif
