#include <iostream>
#include <map>
#include <iterator> // For std::advance

int main() {
    std::map<int, std::string> myMap = {{1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};

    auto it = myMap.begin(); // Start at the first element
   //  std::advance(it, 2); // Move forward by 2 steps (0-based index)

    std::cout << "Key: " << it->first << ", Value: " << it->second << '\n';
    return 0;
}
