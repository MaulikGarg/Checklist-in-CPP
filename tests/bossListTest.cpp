// tests everything for the bosslist class

#include <catch2/catch_all.hpp>
#include <functional>
#include <iostream>
#include <sstream>

#include "../src/bossList.h"
// use for string literals
using namespace std::string_literals;

using void_lambda = std::function<void()>;

class bufferCapture {
 private:
  // hold the initial buffer pointers
  std::streambuf* inputBackup;
  std::streambuf* outputBackup;
  // custom input for cin replacement
  std::stringstream inputStream;
  // stores cout's output
  std::stringstream outputStream;

 public:
  bufferCapture(const std::string& inp = "") {
    // make backups and set cin cout to custom buffer
    inputBackup = std::cin.rdbuf();
    outputBackup = std::cout.rdbuf();
    std::cin.rdbuf(inputStream.rdbuf());
    std::cout.rdbuf(outputStream.rdbuf());
    setInput(inp);
  }

  ~bufferCapture() {
    // use backup and return cin cout to normal
    std::cin.rdbuf(inputBackup);
    std::cout.rdbuf(outputBackup);
  }

  // set custom input
  void setInput(const std::string& inp) { inputStream.str(inp); }
  // get the output
  std::string getOutput() { return outputStream.str(); }
};

TEST_CASE("BossList constructor tests") {
  // initial constructor greeting
  std::string expected_output{
      "Please enter the name of your collection file(type 0 to create "
      "new): "};

  SECTION("Empty list name test") {
    bufferCapture b1{"0\n"};

    BossList testlist{true};  // set testing flag to true

    // new list should be made when 0 is input
    expected_output += "New empty list made successfully!\n"s;

    REQUIRE(expected_output == b1.getOutput());
  }

  SECTION("Non alphanumeric input file name") {
    // invalid file name
    bufferCapture b1{"++++++\n"};

    BossList testlist{true};  // set test list

    // should make new list and sets file name to 0
    expected_output +=
        "Invalid input file name, creating new collection.\nNew empty list "
        "made successfully!\n";

    REQUIRE(expected_output == b1.getOutput());
  }

  SECTION("Bad file input test"){
    // sample invalid file
    bufferCapture b1{"sample_badfile"};

    BossList testlist{true};

    // should complain about bad file
  }
}
