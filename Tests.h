#ifndef TESTS_H
#define TESTS_H

class Tests {
    public: 

        Tests();
        ~Tests();

        // Runs all available tests.
        void runTestSuite();

        // Tests Breadcrumb class.
        void testBreadcrumb();
        
        // Tests Trail class.
        void testTrail();

        // Tests MazeSolver class.
        void testMazeSolver();        

        // Tests ReadMaze method.
        void testReadMaze();
        
        // Tests PrintMaze method.
        void testPrintMaze();

};

#endif
