#ifndef LIST_H
#define LIST_H

#include <string>
#include <set>

class List{
   private:
      std::string name {};
      std::set<std::string> elements {};
   public:
      //basic constructor, takes the name only
      List(std::string iName) : name{iName} {}
      //returns the name of the list
      const std::string& getName() const {return name;} 
      //adds an element to the list, returns 1 if add successful and 0 if failure
      bool addElement();
      //removes an element to the list, returns 1 if add successful and 0 if failure
      bool removeElement();
      //operator < to determine if a List should come after or before
      //mainly needed to sort the boss list, and for the set container
      bool operator< (const List& rhs) const;

};

#endif
