#ifndef GET_INPUT_H
#define GET_INPUT_H
#include <limits>
#include <string>
#include <vector>

// only used by input functions implicitly
namespace functionalities {
// clears extra input that may be in the buffer
void ignoreLine();
// returns true if cin succeeded
bool didInpWork();
}  // namespace functionalities

namespace getValidInput {
// gets a valid integer from a range(optional)
int getInt(int min = std::numeric_limits<int>::min(),
           int max = std::numeric_limits<int>::max());
// gets a valid string of maximum size and returns it
std::string getString(int maxCharacters = std::numeric_limits<int>::max());
// gets a valid character, can optionally except a pool to pick from
char getChar(const std::string& allowed = {});
// returns true if the given string is only alphanumeric
bool alphanumeric(const std::string& input);
}  // namespace getValidInput
#endif
