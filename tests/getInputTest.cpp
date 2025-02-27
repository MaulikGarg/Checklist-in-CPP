// tests all the commands in getInput module

#include <catch2/catch_all.hpp>
#include <functional>
#include <iostream>
#include <sstream>

#include "../src/getInput.h"
// use for string literals
using namespace std::string_literals;

namespace constants {
constexpr int numeric_min = std::numeric_limits<int>::min();
constexpr int numeric_max = std::numeric_limits<int>::max();
};  // namespace constants

using namespace getValidInput;
using namespace functionalities;
using void_lambda = std::function<void()>;

// const std::function<void()>& is the lambda function carrying the REQUIRE
// returns any cout that may be printed in the tested function
std::string getCout(const void_lambda& func) {
  // make an output stream
  std::stringstream output{};
  // save current buffer pointer so we can redirect cout back to it later
  auto coutBuffer = std::cout.rdbuf();
  // all coutput goes into the stream
  std::cout.rdbuf(output.rdbuf());
  // call the REQUIRE function which was passed
  func();
  // returns cout to where it left
  std::cout.rdbuf(coutBuffer);
  return output.str();
}

// gets the string to be tested, and a lambda function carrying the REQUIRE for
// the function which is to be tested
std::string redirectCin(const std::string& testedString,
                        const void_lambda& func) {
  // make a string stream to replace cin with
  std::stringstream ios{testedString};
  // // store cin's current buffer pointer so we can return later
  auto cinBuffer = std::cin.rdbuf();
  std::cin.rdbuf(ios.rdbuf());  // redirect cin
  // call the passed in function and save its output in a string
  std::string output = (getCout(func));
  std::cin.rdbuf(cinBuffer);
  return output;
}

// didInpWork function
TEST_CASE("Input state boolean") {
  // reset cin to fail for each section
  std::cin.setstate(std::ios_base::failbit);
  // checks cin for fail state and if cin manages to catch and
  // return to normal state after taking the hit
  SECTION("cin fails gracefully.") {
    // stores the cin failure warning in string output
    std::string output{getCout([]() { REQUIRE(didInpWork() == false); })};
    REQUIRE(output == "That was invalid input. Please try again.\n>");
    REQUIRE(std::cin);  // check if cin gets back to normal
  }

  SECTION("successfull cin returns true") {
    // checks if the function can detect valid cin correctly
    std::cin.clear();
    REQUIRE(didInpWork() == true);
  }
}

// getInt function
TEST_CASE("Integer input ") {
  // test for no min/max value
  SECTION("Invalid characters are input") {
    // get some random numbers
    auto num = GENERATE(
        take(3, random(constants::numeric_min, constants::numeric_max)));
    std::string output{
        // pass in the invalid values as string and the require condition
        redirectCin("9999999999\n\n@$#\nbbb\n" + std::to_string(num),
                    [=]() { REQUIRE(getInt() == num); })};
    std::string errorMsg{"That was invalid input. Please try again.\n>"};
    // since we give 3 invalid clauses, it should give error 3 times
    REQUIRE(output == errorMsg + errorMsg + errorMsg);
  }

  // test for values outside the given range
  SECTION("Input is outside allowed range.") {
    // generate a random minima + 1 from numeric min to -1
    int minima = GENERATE(take(3, random(constants::numeric_min + 1, -1)));
    // 0 is always valid as the middle point of the range.
    int valid{0};
    // generate a random maxima from 1 to maxima -1
    int maxima = GENERATE(take(1, random(1, constants::numeric_max - 1)));

    // since allowed range is (lower,upper), we check out of bounds by giving
    // minmum and maximum

    // the input should fail twice and then accept once
    std::string output{
        redirectCin((std::to_string(constants::numeric_min) + "\n" +
                     std::to_string(constants::numeric_max) + "\n" +
                     std::to_string(valid) + "\n"),
                    [=]() { REQUIRE(getInt(minima, maxima) == valid); })};

    // the basic error message
    std::string errorMsg{"Please enter a number between " +
                         std::to_string(minima) + " and " +
                         std::to_string(maxima) + " .\n> "};
    // since we provide 2 wrong inputs (min and max), error message should
    // appear twice
    REQUIRE(output == errorMsg + errorMsg);

    // now check by only giving the correct input
    output = redirectCin((std::to_string(valid) + "\n"),
                         [=]() { REQUIRE(getInt(minima, maxima) == valid); });
    REQUIRE(output == "");
  }

  // buffer overflow occurs
  SECTION("check for extra input for int getting") {
    // get some random numbers
    auto num = GENERATE(
        take(3, random(constants::numeric_min, constants::numeric_max)));
    // pass in the int and extra input
    redirectCin(std::to_string(num) + "abcde",
                [=]() { REQUIRE(getInt() == num); });
  }
}

// getString function
TEST_CASE("String extraction") {
  /*---------------------------------------------------------------------
  eof and similar input failure cases are handled and are not tested here
  -----------------------------------------------------------------------*/

  // first check with no specified length
  redirectCin("\n\n\ntest", []() { REQUIRE(getString() == "test"); });

  // now check if overlength works
  std::string output{redirectCin("\n\ntests\ntest",
                                 []() { REQUIRE(getString(4) == "test"); })};

  // check for the error message
  REQUIRE(output == "Maximum allowed length is 4 please try again.\n> ");
}

// getChar function
TEST_CASE("Single character extraction") {
  /*---------------------------------------------------------------------
  eof and similar input failure cases are handled and are not tested here
  -----------------------------------------------------------------------*/

  // the characters which can be input, vowels for testing(not y)
  std::string allowedCharacters{"aeiou"};
  //character the function is supposed to output
  char expecetedChar{'e'};

  SECTION("Not from valid input test") {
    // all the different invalid inputs to be tested
    std::string testedString{"\n"s + "9999\n"s + "qwrty\n"s + "e\n"s};
    //the error message capture
    std::string output{redirectCin(testedString, [&]() {
      REQUIRE(getChar(allowedCharacters) == expecetedChar);
    })};
    //the error message
    std::string errorMsg {"That was invalid, please enter one of these allowed inputs: a, e, i, o, u\n>"};
    //check if we get 2 invalid messages
    REQUIRE(output == errorMsg+errorMsg);
  }

  SECTION("Buffer overflow Test"){
    //overflow with valid elements
    std::string testedString {"eaiou\n"};
    std::string output{redirectCin(testedString, [&]() {
      REQUIRE(getChar(allowedCharacters) == expecetedChar);
    })};
    //check if there was no error message
    REQUIRE(output == "");
  }
}
