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
  showList,
  max,
};
constexpr std::array str_options{"Exit Menu"sv, "Add a list"sv,
                                 "Remove a list"sv, "Show current lists"sv, "Show a list's elements"sv};

static_assert(max == std::size(str_options));
}  // namespace bosslistOptions

// main list of all the available lists
class BossList {
 private:
  // list of our Lists: Name + vector of elements
  std::map<std::string, List> m_mainlist;
  //returns true if the list is empty
  bool isListEmpty();
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
  // shows a specific list from the list collection
  void getList();
};

#endif
