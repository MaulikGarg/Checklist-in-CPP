#include "list.h"
#include <vector>
#include <string>

bool List::addElement(){

}

bool List::removeElement(){
   
}

bool List::operator<(const List& rhs) const {
   if(name < rhs.name) return true;
   return false;
}
