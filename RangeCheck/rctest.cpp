/*
 *             Author: Michael Marven
 *       Date Created: 02/09/16
 * Last Date Modified: 02/10/16
 *          File Name: rangechecktest.cpp
 *           Overview: A program to test the RangeCheck template class
 *                     
 *
 */
 
#include <iostream>
#include <string>
#include <cstdlib>
#include "rangecheck.h"
#include "rangecheck.cpp" // Solves “Undefined reference to” compiler issue

const int RANGE_MIN    = 1;
const int RANGE_MAX    = 100;
const int IN_RANGE     = 50;
const int BELOW_RANGE  = 0;
const int ABOVE_RANGE  = 110;
const double RNG_MIN_D = 1.34;
const double RNG_MAX_D = 5.6745;
const double IN_RNG_D  = 2.458;
const double BEL_RNG_D = 1.3399999999;
const double ABV_RNG_D = 5.67450000001;




/*
 * The testInts() function tests the class with ints
 */
void testInts();

/*
 * The testInts() function tests the class with ints
 */
void testDoubles();

int main (int argc, char *argv[])
{
    // Run tests
    testInts();
    testDoubles();
    
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
    
    // Call inRngInclMin and print result to console; Expected output: "1"
    std::cout << IN_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min: "
              << testRC.inRngInclMin(IN_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngInclMin and print result to console; Expected output: "1"
    std::cout << RANGE_MIN << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min: "
              << testRC.inRngInclMin(RANGE_MIN, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngInclMin and print result to console; Expected output: "0"
    std::cout << BELOW_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min: "
              << testRC.inRngInclMin(BELOW_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngInclMin and print result to console; Expected output: "0"
    std::cout << ABOVE_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min: "
              << testRC.inRngInclMin(ABOVE_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              

              
    // Call inRngInclMax and print result to console; Expected output: "1"
    std::cout << IN_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of max: "
              << testRC.inRngInclMax(IN_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngInclMax and print result to console; Expected output: "1"
    std::cout << RANGE_MAX << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of max: "
              << testRC.inRngInclMax(RANGE_MAX, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngInclMax and print result to console; Expected output: "0"
    std::cout << BELOW_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of max: "
              << testRC.inRngInclMax(BELOW_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngInclMax and print result to console; Expected output: "0"
    std::cout << ABOVE_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of max: "
              << testRC.inRngInclMax(ABOVE_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
 
 
    // Call inRngIncl and print result to console; Expected output: "1"
    std::cout << IN_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min and max: "
              << testRC.inRngIncl(IN_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "1"
    std::cout << RANGE_MAX << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min and max: "
              << testRC.inRngIncl(RANGE_MAX, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "1"
    std::cout << RANGE_MIN << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min and max: "
              << testRC.inRngIncl(RANGE_MAX, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "0"
    std::cout << BELOW_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min and max: "
              << testRC.inRngIncl(BELOW_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "0"
    std::cout << ABOVE_RANGE << " is in the range of " << RANGE_MIN << " to "
              << RANGE_MAX << " inclusive of min and max: "
              << testRC.inRngIncl(ABOVE_RANGE, RANGE_MIN, RANGE_MAX) << "\n";
}

/*   *   *   *   *   *   *
 * 
 * Function: testDoubles()
 * 
 *    Entry: none 
 *
 *     Exit: Tests the RangeCheck class with doubles
 *
 *  Purpose: Test with doubles and check exception handling
 *
 *
 *   *   *   *   *   *   */
void testDoubles()
{
    // Create a RangeCheck object with doubles
    RCheckMarven::RangeCheck<double> testRC;
    
    std::cout << "Testing RangeCheck with doubles...\n";
    
    // Call inRngExcl and print result to console; Expected output: "1"
    std::cout << IN_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " exclusive: "
              << testRC.inRngExcl(IN_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngExcl and print result to console; Expected output: "0"
    std::cout << BEL_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " exclusive: "
              << testRC.inRngExcl(BEL_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngExcl and print result to console; Expected output: "0"
    std::cout << ABV_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " exclusive: "
              << testRC.inRngExcl(ABV_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Check range with min and max reversed; Expected output: error msg
    std::cout << "Testing min and max reversed: \n";
    try
    {
        testRC.inRngExcl(IN_RNG_D, RNG_MAX_D, RNG_MIN_D);
        std::cout << IN_RNG_D << "is in range.\n";
    }
    catch(std::out_of_range e)
    {
        std::cout << e.what() << "\n";
    }
    
    // Call inRngInclMin and print result to console; Expected output: "1"
    std::cout << IN_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min: "
              << testRC.inRngInclMin(IN_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngInclMin and print result to console; Expected output: "1"
    std::cout << RNG_MIN_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min: "
              << testRC.inRngInclMin(RNG_MIN_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngInclMin and print result to console; Expected output: "0"
    std::cout << BEL_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min: "
              << testRC.inRngInclMin(BEL_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngInclMin and print result to console; Expected output: "0"
    std::cout << ABV_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min: "
              << testRC.inRngInclMin(ABV_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              

              
    // Call inRngInclMax and print result to console; Expected output: "1"
    std::cout << IN_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of max: "
              << testRC.inRngInclMax(IN_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngInclMax and print result to console; Expected output: "1"
    std::cout << RNG_MAX_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of max: "
              << testRC.inRngInclMax(RNG_MAX_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngInclMax and print result to console; Expected output: "0"
    std::cout << BEL_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of max: "
              << testRC.inRngInclMax(BEL_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngInclMax and print result to console; Expected output: "0"
    std::cout << ABV_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of max: "
              << testRC.inRngInclMax(ABV_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
 
 
    // Call inRngIncl and print result to console; Expected output: "1"
    std::cout << IN_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min and max: "
              << testRC.inRngIncl(IN_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "1"
    std::cout << RNG_MAX_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min and max: "
              << testRC.inRngIncl(RNG_MAX_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "1"
    std::cout << RNG_MIN_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min and max: "
              << testRC.inRngIncl(RNG_MAX_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "0"
    std::cout << BEL_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min and max: "
              << testRC.inRngIncl(BEL_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
              
    // Call inRngIncl and print result to console; Expected output: "0"
    std::cout << ABV_RNG_D << " is in the range of " << RNG_MIN_D << " to "
              << RNG_MAX_D << " inclusive of min and max: "
              << testRC.inRngIncl(ABV_RNG_D, RNG_MIN_D, RNG_MAX_D) << "\n";
}