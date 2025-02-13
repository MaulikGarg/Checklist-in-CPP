#include "getInput.h"

#include <iostream>
#include <limits>
#include <string>

namespace getValidInput {
void ignoreLine() {
  // ignores any extra character which may be in the input
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns a bool for whether normal cin worked, gives error statement and
// clears buffer if not
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

// get an integer from a range(exclusive) and verify if valid input
int getInt(int min, int max) {
  int input;
  while (true) {
    std::cin >> input;
    //if cin has failed(ex: a character has been entered), return it to valid state and try again.
    if (!didInpWork()) continue;
    //if the input is outside the required range, print the min max and try again.
    if (!(min < input && input < max)) {
      std::cout << "Please enter a number between " << min << " and " << max
                << " .\n> ";
      continue;
    }
    //to make sure the extra input is cleared properly
    ignoreLine();
    return input;
  }
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

char getChar(const std::string& allowed) {
  char ch;
  while (true) {
    std::cin >> ch;
    // check if cin worked, if it did proceed with checking
    if (!didInpWork()) continue;
    // checks if the character matches the allowed string
    if (allowed.empty() || allowed.find(ch) != std::string::npos) {
      ignoreLine();
      return ch;
    }

    std::cout
        << "That was invalid, please enter one of these allowed inputs:  ";
    for (size_t i = 0; i < allowed.size(); ++i) {
      std::cout << allowed[i];
      if (i != allowed.size() - 1) std::cout << ", ";
    }
    std::cout << "\n>";
  }
}
}  // namespace getValidInput
