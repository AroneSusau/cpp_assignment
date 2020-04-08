
#include "../headers/Trail.h"

Trail::Trail():
   breadcrumbs()
{}

Trail::Trail(Trail* &trail) {
   for (int i = 0; i < trail->size(); i++) {
      Breadcrumb* b = trail->getPtr(i);
      addCopy(b);
   }
}

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

Breadcrumb* Trail::find(int x, int y) {
   Breadcrumb* b = nullptr;
   
   for (int i = 0; i < length; i++) {
      if (breadcrumbs[i] != nullptr) {
         bool matchX = breadcrumbs[i]->getX() == x;
         bool matchY = breadcrumbs[i]->getY() == y;

         if (matchX && matchY) {
            b = breadcrumbs[i];
         }
      }
   }

   return b;
}

void Trail::addCopy(Breadcrumb* t) {
   Breadcrumb* cloneBreadcrumb = new Breadcrumb(
      t->getX(),
      t->getY(),
      t->isStale());

   breadcrumbs[length] = cloneBreadcrumb;
   length += 1;
}

bool Trail::contains(int x, int y) {
   bool exists = false;
   
   for (int i = 0; i < length; i++) {
      if (breadcrumbs[i] != nullptr) {
         bool matchX = breadcrumbs[i]->getX() == x;
         bool matchY = breadcrumbs[i]->getY() == y;

         if (matchX && matchY) {
            exists = true;
         }
      }
   }

   return exists;
}
