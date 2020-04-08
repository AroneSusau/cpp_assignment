#include "../headers/Types.h"
#include "../headers/MazeSolver.h"
#include "../headers/Breadcrumb.h"
#include "../headers/Trail.h"
#include "../headers/Tests.h"

Tests::Tests() {}
Tests::~Tests() {}

void Tests::runTestSuite() {
    std::cout << "\nTESTING PROGRAM" << std::endl;
    testBreadcrumb();
    testTrail();
    std::cout << "\nDONE TESTING" << std::endl << std::endl;
}

void Tests::testBreadcrumb() {
    std::cout << "\nTESTING BREADCRUMB" << std::endl;

    // Make a breadcrumb and print out the contents
    Breadcrumb* breadcrumb = new Breadcrumb(1, 1, false);
    std::cout << breadcrumb->getX() << ",";
    std::cout << breadcrumb->getY() << ",";
    std::cout << breadcrumb->isStale() << " - expecting 1,1,0." << std::endl;

    // Change breadcrumb stale-ness and print again
    breadcrumb->setStale(true);
    std::cout << breadcrumb->getX() << ",";
    std::cout << breadcrumb->getY() << ",";
    std::cout << breadcrumb->isStale() << " - expecting 1,1,1." << std::endl;

    delete breadcrumb;
}

void Tests::testTrail() {
    std::cout << "\nTESTING TRAIL" << std::endl;

    // Make a simple trail, should be empty size
    Trail* trail = new Trail();
    std::cout << "Trail size: " << trail->size() << " - expecting 0." << std::endl;

    // Add a breadcrumb to the trail, print size, check contains
    Breadcrumb* b1 = new Breadcrumb(1, 1, false);
    trail->addCopy(b1);
    std::cout << "\nTrail size: " << trail->size() << " - expecting 1." << std::endl;
    std::cout << "Contains (0,0): " << trail->contains(0,0) << " - expecting 0." << std::endl;
    std::cout << "Contains (1,1): " << trail->contains(1,1) << " - expecting 1." << std::endl;

    // Add second breadcrumb
    Breadcrumb* b2 = new Breadcrumb(0, 0, true);
    trail->addCopy(b2);
    std::cout << "\nTrail size: " << trail->size() << " - expecting 2." << std::endl;
    std::cout << "Contains (0,0): " << trail->contains(0,0) << " - expecting 1." << std::endl;
    std::cout << "Contains (1,1): " << trail->contains(1,1) << " - expecting 1." << std::endl;

    // Test Get-ith - should be 0,0,true
    Breadcrumb* getB = trail->getPtr(1);
    std::cout << getB->getX() << ",";
    std::cout << getB->getY() << ",";
    std::cout << getB->isStale() << " - expecting 1,1,1" << std::endl;

    // Print out the trail
    std::cout << "\nPRINTING OUT TRAIL" << std::endl;
    int length = trail->size();
    
    for (int i = 0; i < length; ++i) {
        Breadcrumb* b = trail->getPtr(i);
        std::cout << b->getX() << ",";
        std::cout << b->getY() << ",";
        std::cout << b->isStale() << std::endl;
    }

    std::cout << "Expecting \n1,1,0\n0,0,1" << std::endl;

    delete trail;
}