#ifndef LIST_H
#define LIST_H

#include <string>
#include <set>
class List{
   private:
      std::set<std::string> m_elements {};
   public: 
      //adds an element to the list, returns 1 if add successful and 0 if failure
      bool addElement();
      //removes an element to the list, returns 1 if add successful and 0 if failure
      bool removeElement();
      //operator < to determine if a List should come after or before
      //mainly needed to sort the boss list, and for the set container
      bool operator< (const List& rhs) const;

};

#endif
