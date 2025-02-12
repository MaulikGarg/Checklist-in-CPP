#include "getInput.h"

#include <iostream>
#include <limits>
#include <string>

namespace getValidInput {
void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getString() {
  std::string str{};
  while (true) {
    std::getline(std::cin >> std::ws, str);
    if (!std::cin) {
      std::cin.clear();
      ignoreLine();
      std::cout << "That was invalid input. Please try again.\n>";
    } else {
      return str;
    }
  }
}
}  // namespace getValidInput
