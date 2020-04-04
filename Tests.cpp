#include "Types.h"
#include "MazeSolver.h"
#include "Breadcrumb.h"
#include "Trail.h"
#include "Util.h"
#include "Tests.h"

Tests::Tests() {}
Tests::~Tests() {}

void Tests::runTestSuite() {
    std::cout << "TESTING PROGRAM" << std::endl;
    testBreadcrumb();
    testTrail();
    testMazeSolver();
    testReadMaze();
    testPrintMaze();
    std::cout << "DONE TESTING" << std::endl << std::endl;
}

void Tests::testBreadcrumb() {
    std::cout << "TESTING BREADCRUMB" << std::endl;

    // Make a breadcrumb and print out the contents
    Breadcrumb* breadcrumb = new Breadcrumb(1, 1, false);
    std::cout << breadcrumb->getX() << ",";
    std::cout << breadcrumb->getY() << ",";
    std::cout << breadcrumb->isStale() << std::endl;

    // Change breadcrumb stale-ness and print again
    breadcrumb->setStale(true);
    std::cout << breadcrumb->getX() << ",";
    std::cout << breadcrumb->getY() << ",";
    std::cout << breadcrumb->isStale() << std::endl;

    delete breadcrumb;
}

void Tests::testTrail() {
    std::cout << "TESTING TRAIL" << std::endl;

    // Make a simple trail, should be empty size
    Trail* trail = new Trail();
    std::cout << "Trail size: " << trail->size() << std::endl;

    // Add a breadcrumb to the trail, print size, check contains
    Breadcrumb* b1 = new Breadcrumb(1, 1, false);
    trail->addCopy(b1);
    std::cout << "Trail size: " << trail->size() << std::endl;
    std::cout << "Contains (0,0): " << trail->contains(0,0) << std::endl;
    std::cout << "Contains (1,1): " << trail->contains(1,1) << std::endl;

    // Add second breadcrumb
    Breadcrumb* b2 = new Breadcrumb(0, 0, true);
    trail->addCopy(b2);
    std::cout << "Trail size: " << trail->size() << std::endl;
    std::cout << "Contains (0,0): " << trail->contains(0,0) << std::endl;
    std::cout << "Contains (1,1): " << trail->contains(1,1) << std::endl;

    // Test Get-ith - should be 0,0,true
    Breadcrumb* getB = trail->getPtr(1);
    std::cout << getB->getX() << ",";
    std::cout << getB->getY() << ",";
    std::cout << getB->isStale() << std::endl;

    // Print out the trail
    std::cout << "PRINTING OUT A TRAIL IS AN EXERCISE FOR YOU TO DO" << std::endl;

    delete trail;
}

void Tests::testMazeSolver() {
    std::cout << "TESTING MAZE SOLVER" << std::endl;
}

void Tests::testReadMaze() {
    std::cout << "TESTING READ MAZE" << std::endl;

}

void Tests::testPrintMaze() {
    std::cout << "TESTING PRINT MAZE" << std::endl;

}