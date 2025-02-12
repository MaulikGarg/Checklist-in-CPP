#ifndef GET_INPUT_H
#define GET_INPUT_H
#include <string>
#include <vector>

namespace getValidInput{
   //gets a valid string and returns it
   std::string getString();
   //gets a valid integer integer and allows it
   int getValidInt();
   //gets a valid character, can optionally except a pool to pick from
   char getChar(const std::string& allowed = {});
}
#endif
