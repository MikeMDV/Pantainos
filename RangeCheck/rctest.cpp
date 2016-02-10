/*
 *             Author: Michael Marven
 *       Date Created: 02/09/16
 * Last Date Modified: 02/09/16
 *          File Name: rangechecktest.cpp
 *           Overview: A program to test the RangeCheck template class
 *                     
 *
 */
 
#include <iostream>
#include <string>
#include <cstdlib>
#include "rangecheck.h"
#include "rangecheck.cpp"

const int RANGE_MIN   = 1;
const int RANGE_MAX   = 100;
const int IN_RANGE    = 50;
const int BELOW_RANGE = 0;
const int ABOVE_RANGE = 110;

/*
 * The testInts() function tests the class with ints
 */
void testInts();

int main (int argc, char *argv[])
{
    // Run tests
    testInts();
    
    return 0;
}

/*   *   *   *   *   *   *
 * 
 * Function: testInts()
 * 
 *    Entry: none 
 *
 *     Exit: Tests the RangeCheck class with ints
 *
 *  Purpose: Test with ints and check exception handling
 *
 *
 *   *   *   *   *   *   */
void testInts()
{
    // Create a RangeCheck object with ints
    RCheckMarven::RangeCheck<int> testRC;
    
    std::cout << "Testing RangeCheck with ints...\n";
    
    // Call inRngExcl and print result to console; Expected output: "1"
    std::cout << IN_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " exclusive: "
              << testRC.inRngExcl(IN_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngExcl and print result to console; Expected output: "0"
    std::cout << BELOW_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " exclusive: "
              << testRC.inRngExcl(BELOW_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngExcl and print result to console; Expected output: "0"
    std::cout << ABOVE_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " exclusive: "
              << testRC.inRngExcl(ABOVE_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Check range with min and max reversed; Expected output: error msg
    std::cout << "Testing min and max reversed: \n";
    try
    {
        testRC.inRngExcl(RANGE_MAX, RANGE_MAX, RANGE_MIN);
        std::cout << RANGE_MAX << "is in range.\n";
    }
    catch(std::out_of_range e)
    {
        std::cout << e.what() << "\n";
    }
    
}