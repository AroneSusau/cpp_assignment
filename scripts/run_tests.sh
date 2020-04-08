#! /bin/bash

# Author: Arone Susau
#
# This script was written to automate the process of running
# all the tests found in the tests directory.

# Test meta data.
NUM_TESTS="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16"
TEST_LIMIT=16
SUCCESS_COUNT=0

# Check if MazeSolver exists.
if [ -f "./MazeSolver" ]
then

    # Loop through each test and run it.
    for i in $NUM_TESTS
    do
        # Gather test file details.
        DIR="tests/t${i}"
        OUTPUT=$DIR/program.out
        EXPECTED=$DIR/expected.out

        ./MazeSolver < $(ls $DIR/*.maze) > $OUTPUT

        # Check for a difference in output vs expected output.
        RESULT=$(diff $OUTPUT $EXPECTED)

        if [ ! -z "$RESULT" ]
        then
            echo "\nTest $i failed."
            echo $RESULT
        else
            SUCCESS_COUNT=$(($SUCCESS_COUNT+1))
        fi
    done

    echo "\nResult: $SUCCESS_COUNT tests passed out of $TEST_LIMIT."

else
    echo "ERROR: MazeSolver executable does not exist."
fi