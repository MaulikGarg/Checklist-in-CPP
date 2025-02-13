#ifndef GET_INPUT_H
#define GET_INPUT_H
#include <string>
#include <vector>
#include <limits>

namespace getValidInput{
   //clears extra input that may be in the buffer
   void ignoreLine();
   //returns true if cin succeeded
   bool didInpWork();
   //gets a valid integer from a range(optional)
   int getInt(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max()); 
   //gets a valid string and returns it
   std::string getString();
   //gets a valid integer integer and allows it
   int getValidInt();
   //gets a valid character, can optionally except a pool to pick from
   char getChar(const std::string& allowed = {});
}
#endif
