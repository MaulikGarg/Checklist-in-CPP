#ifndef LIST_H
#define LIST_H

#include <array>
#include <set>
#include <string>

namespace listOptions {
using namespace std::literals;
enum options {
  exit,
  add,
  remove,
  showElements,
  max,
};
constexpr std::array str_options{
    "Exit Menu"sv,
    "Add an element"sv,
    "Remove an element"sv,
    "Show elements"sv,
};

static_assert(max == std::size(str_options));
}  // namespace listOptions

class List {
 private:
  std::set<std::string> m_elements{};

 public:
  // shows all the elements in the list
  void printList();
  // adds element(s) to the list
  void addElement();
  // adds a given element to the list, returns false if addition failed
  bool addElement(const std::string&);
  // removes an element to the list
  void removeElement();
  // shows a basic menu interface
  void showMenu();
};

#endif
