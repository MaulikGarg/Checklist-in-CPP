//tests all the commands in getInput module

#include <catch2/catch_all.hpp>
#include <iostream>
#include "../src/getInput.h"

TEST_CASE("Test getInput function") {
  std::stringstream input("kk\n5\n");
  std::cin.rdbuf(input.rdbuf());
  REQUIRE(getValidInput::getInt() == 5);
}
