// tests all the commands in getInput module

#include <catch2/catch_all.hpp>
#include <functional>
#include <iostream>
#include <sstream>

#include "../src/getInput.h"

using namespace getValidInput;
using namespace functionalities;

// const std::function<void()>& is the lambda function carrying the REQUIRE
std::string getCout(const std::function<void()>& func) {
  std::ostringstream ttstr;
  auto coutBuffer = std::cout.rdbuf();
  // now redirect all output to str
  std::cout.rdbuf(ttstr.rdbuf());
  // call the REQUIRE function which was passed
  func();
  // returns cout to normal state
  std::cout.rdbuf(coutBuffer);
  return ttstr.str();
}

TEST_CASE("didInpWork function") {
  // reset cin to fail for each section
  std::cin.setstate(std::ios_base::failbit);

  SECTION("cin fails gracefully") {
    REQUIRE(didInpWork() == false);
  }

  SECTION("cin fail is printed successfully.") {
    std::string output {getCout([]() { didInpWork(); })};
    REQUIRE(output == "That was invalid input. Please try again.\n>");
  }

  SECTION("successfull cin returns true") {
    // check state again, since failed didInpWork() should set cin to normal
    std::cin.clear();
    REQUIRE(didInpWork() == true);
  }
}
