
#include "Trail.h"

Trail::Trail() {}

Trail::~Trail() {
   for (size_t i = 0; i < length; i++) {
      if (breadcrumbs[i] != nullptr) {
         delete breadcrumbs[i];
         breadcrumbs[i] = nullptr;
      }
   }
}

int Trail::size() {
   return length;
}

Breadcrumb* Trail::getPtr(int i) {
   return breadcrumbs[i];
}

void Trail::addCopy(Breadcrumb* t) {
   breadcrumbs[length] = t;
   length += 1;
}

bool Trail::contains(int x, int y) {
   bool exists = false;
   
   for (int i = 0; i < length; i++) {
      Breadcrumb* breadcrumb = breadcrumbs[i];
      bool matchX = breadcrumb->getX() == x;
      bool matchY = breadcrumb->getY() == y;

      if (matchX && matchY) {
         exists = true;
      }
   }

   return exists;
}
