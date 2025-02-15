#include "getInput.h"

#include <iostream>
#include <algorithm>

// used by the valid input functions
namespace functionalities {
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
}  // namespace functionalities

namespace getValidInput {
// get an integer from a range(inclusive) and verify if valid input
int getInt(int min, int max) {
  int input;
  while (true) {
    std::cin >> input;
    // if cin has failed(ex: a character has been entered), return it to valid
    // state and try again.
    if (!functionalities::didInpWork()) continue;
    // if the input is outside the required range, print the min max and try
    // again.
    if (!(min <= input && input <= max)) {
      std::cout << "Please enter a number between " << min << " and " << max
                << " .\n> ";
      continue;
    }
    // to make sure the extra input is cleared properly
    functionalities::ignoreLine();
    return input;
  }
}

// gets a string line of a maximum length
std::string getString(int maxLength) {
  std::string str{};
  while (true) {
    // gets a full whitespaced string
    std::getline(std::cin >> std::ws, str);

    // check if input failed, if so, try again.
    if (!functionalities::didInpWork()) {
      functionalities::ignoreLine();  // Clear buffer
      continue;
    }

    // check if the line exceeds maxlength
    if (str.length() > maxLength) {
      std::cout << "Maximum allowed length is " << maxLength
                << " please try again.\n> ";
      continue;
    }
    // if input worked, return it safely
    if (functionalities::didInpWork()) return str;
  }
}

char getChar(const std::string& allowed) {
  while (true) {
    std::string input{};
    std::cin >> input;
    // check if cin worked, if it did proceed with checking
    if (!functionalities::didInpWork()) {
      continue;
    }
    // cin success, get the first character as the only input
    char ch = input[0];
    // ignore any extra input that may be in the buffer
    functionalities::ignoreLine();
    // checks if the character matches the allowed string or if no requirements
    if (allowed.empty() || allowed.find(ch) != std::string::npos) {
      return ch;
    }

    // if function reaches here, it must be a disallowed character, print
    // message retry
    std::cout
        << "That was invalid, please enter one of these allowed inputs:  ";
    for (size_t i = 0; i < allowed.size(); ++i) {
      std::cout << allowed[i];
      if (i != allowed.size() - 1) std::cout << ", ";
    }
    std::cout << "\n>";
  }
}

//returns true if the input is only alpha numeric
bool alphanumeric(const std::string& input) {
  auto it = std::find_if_not(std::begin(input), std::end(input),
                             [](unsigned char c) { return std::isalnum(c); });

  return it == std::end(input);
}
}  // namespace getValidInput
