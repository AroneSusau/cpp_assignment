
#include "../headers/Trail.h"
#include "../headers/Breadcrumb.h"

Trail::Trail() : 
  breadcrumbs(nullptr)
{}

Trail::Trail(int maxLength) : 
  breadcrumbs(new Breadcrumb*[maxLength])
{}

Trail::Trail(Trail* &trail, int maxLength) {
  
  breadcrumbs = new Breadcrumb*[maxLength];
  length = 0;

  for (int i = 0; i < trail->size(); i++) {
    Breadcrumb* b = trail->getPtr(i);
    Breadcrumb* cloneBreadcrumb =
      new Breadcrumb(
        b->getX(), 
        b->getY(), 
        b->isStale());
  
  breadcrumbs[length] = cloneBreadcrumb;
  length += 1;
  }

}

Trail::~Trail() {
  for (size_t i = 0; i < length; i++) {
    if (breadcrumbs[i] != nullptr) {
      delete breadcrumbs[i];
      breadcrumbs[i] = nullptr;
    }
  }

  delete[] breadcrumbs;
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
  Breadcrumb* cloneBreadcrumb =
      new Breadcrumb(
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

int Trail::size() { return length; }

Breadcrumb* Trail::getPtr(int i) { return breadcrumbs[i]; }