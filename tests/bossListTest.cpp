// tests everything for the bosslist class

#include <catch2/catch_all.hpp>
#include <functional>
#include <iostream>
#include <sstream>

#include "../src/bossList.h"
// use for string literals
using namespace std::string_literals;

using void_lambda = std::function<void()>;

TEST_CASE("Empty list name test") {
  // redirect cin and cout for testing.

  //  make an output stream
  std::stringstream output{};
  // save current buffer pointer so we can redirect cout back to it later
  auto coutBuffer = std::cout.rdbuf();
  // all coutput goes into the stream
  std::cout.rdbuf(output.rdbuf());

  // make an input stream
  std::stringstream input{"0"};
  // save the current input for later redirection
  auto cinBuffer = std::cin.rdbuf();
  // set cin's buffer to out string
  std::cin.rdbuf(input.rdbuf());

  BossList b1{true};  // set testing flag to true

  // initial constructor greeting
  std::string expected_output{
      "Please enter the name of your collection file(type 0 to create "
      "new): "};

  // try entering value 0    
  input << "0";
  
  // new list should be made when 0 is input
  expected_output+="New empty list made successfully!\n"s;

  REQUIRE(expected_output == output.str());

  // return cin and cout
  std::cout.rdbuf(coutBuffer);
  std::cin.rdbuf(cinBuffer);

}
