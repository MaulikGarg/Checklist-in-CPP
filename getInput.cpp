#include "getInput.h"

#include <iostream>
#include <limits>
#include <string>

namespace getValidInput {
void ignoreLine() {
  // ignores any extra character which may be in the input
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool didInpWork() {
  // if cin failed, return it to safe state and return false
  if (!std::cin) {
    std::cin.clear();
    ignoreLine();
    std::cout << "That was invalid input. Please try again.\n>";
    return false;
  }
  return true;
}

std::string getString() {
  std::string str{};
  while (true) {
    // gets a full whitespaced string
    std::getline(std::cin >> std::ws, str);
    // if input worked, return it safely
    if (didInpWork()) return str;
  }
}

char getChar(const std::string& allowed = {}) {
  char ch;
  while (true) {
    std::cin >> ch;
    if (!didInpWork()) continue;
    // if the allowed vector was not provided, return the current character
    if (allowed.empty()) return ch;
    // compare the entered character against the allowed values
    for (auto& i : allowed) {
      // if a character matches, return the input
      if (i == ch) {
        return ch;
      }
    }
    std::cout << "That was invalid, please try again: ";
  }
}
}  // namespace getValidInput
