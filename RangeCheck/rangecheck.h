/*
 *             Author: Michael Marven
 *       Date Created: 02/09/16
 * Last Date Modified: 02/13/16
 *          File Name: rangecheck.h
 *           Overview: This is the header file for the RangeCheck template class
 *                     
 *
 */

#ifndef RANGECHECK_H
#define RANGECHECK_H

#include <stdexcept>

namespace RCheckMarven
{
    /*
     * Template class for checking whether a value of type T is within a range
     */
    template<typename T>
    class RangeCheck
    {
    public:
        RangeCheck(); // Default constructor
        // Check if in range exclusive of min & max values
        bool excl(const T&, const T&, const T&) 
            throw (std::out_of_range);
        // Check if in range inclusive of min value only
        bool inclMin(const T&, const T&, const T&) 
            throw (std::out_of_range);
        // Check if in range inclusive of max value only
        bool inclMax(const T&, const T&, const T&) 
            throw (std::out_of_range);
        // Check if in range inclusive of min & max values
        bool incl(const T&, const T&, const T&) 
            throw (std::out_of_range);
    };
} // RCheckMarven
#endif // RANGECHECK_H