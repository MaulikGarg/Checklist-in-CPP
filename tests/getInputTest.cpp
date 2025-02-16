// tests all the commands in getInput module

#include <catch2/catch_all.hpp>
#include <functional>
#include <iostream>
#include <sstream>

#include "../src/getInput.h"

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
  std::ostringstream output{};
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
  std::istringstream ios{testedString};
  // // store cin's current buffer pointer so we can return later
  auto cinBuffer = std::cin.rdbuf();
  std::cin.rdbuf(ios.rdbuf());  // redirect cin
  // call the passed in function and save its output in a string
  std::string output = (getCout(func));
  std::cin.rdbuf(cinBuffer);
  return output;
}

// didInpWork function
TEST_CASE("Input state boolean"){
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
        take(1, random(constants::numeric_min, constants::numeric_max)));
    std::string output{
        // pass in the invalid values as string and the require condition
        redirectCin("9999999999\n\n@$#\nbbb\n" + std::to_string(num),
                    [=]() { REQUIRE(getInt() == num); })};
    REQUIRE(output ==
            // since we give 3 invalid clauses, it should give error 3 times
            "That was invalid input. Please try again.\n>"
            "That was invalid input. Please try again.\n>"
            "That was invalid input. Please try again.\n>");
  }

  // test for values outside the given range
  SECTION("Input is outside allowed range.") {
    // generate a random minima + 1 from numeric min to half of numeric max-1
    int minima = GENERATE(take(
        3, random(constants::numeric_min + 1, constants::numeric_max / 2 - 1)));
    // set numeric max /2 as an always valid input
    int valid = constants::numeric_max / 2;
    // generate a random maxima from numeric half of numeric maxima+1 to numeric
    // maxima - 1
    int maxima = GENERATE(take(
        3, random(constants::numeric_max / 2 + 1, constants::numeric_max - 1)));

    // since allowed range is [lower,upper], we check out of bounds by giving
    // minmum and maximum

    // the input should fail twice and then accept once
    std::string output{
        redirectCin((std::to_string(constants::numeric_min) + "\n" +
                     std::to_string(constants::numeric_max) + "\n" +
                     std::to_string(valid) + "\n"),
                    [=]() { REQUIRE(getInt(minima, maxima) == valid); })};

    std::string expected{
        // since we enter minimum and maximum, wrong input warning should appear
        // twice
        "Please enter a number between " + std::to_string(minima) + " and " +
        std::to_string(maxima) + " .\n> " + "Please enter a number between " +
        std::to_string(minima) + " and " + std::to_string(maxima) + " .\n> "};
    REQUIRE(output == expected);

    // now check by only giving the correct input
    output = redirectCin((std::to_string(valid) + "\n"),
                         [=]() { REQUIRE(getInt(minima, maxima) == valid); });
    REQUIRE(output == "");
  }
}
