#include <iostream>

#include "bossList.h"
#include "getInput.h"

int main() {
  // basic greeting
  std::cout << "\n=== Welcome to the List Manager ===\n";
  //keeps a collection open until the user wants to quit
  while (true) {
    std::cout << "\nWould you like to open a collection?\n > ";
    char response = getValidInput::getChar(std::string{"ynYN"});
    //the user would like a mainlist, make and continue operations there.
    if (response == 'y' || response == 'Y') {
      BossList userlist;
    } else {
      //user wants to leave
      break;
    }
  }
  std::cout << "Exiting Program...\nMade by Maulik\nPress any key to close "
               "this window...";
  std::cin.get();

  return 0;
}
