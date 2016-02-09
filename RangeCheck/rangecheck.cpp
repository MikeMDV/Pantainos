/*
 *             Author: Michael Marven
 *       Date Created: 02/09/16
 * Last Date Modified: 02/09/16
 *          File Name: rangecheck.cpp
 *           Overview: This is the implementation file for the RangeCheck 
 *                     template class
 *                     
 *
 */
 
#include <stdexcept>
#include "rangecheck.h"

namespace RCheckMarven
{
    template<typename T>
    RangeCheck<T>::RangeCheck()
    {/*Body intentionally empty*/}
    
    /*   *   *   *   *   *   *
     * 
     * Function: inRngExcl(const T&, const T&, const T&)
     * 
     *    Input: Data element, minimum & maximum values for comparison
     *
     *   Output: Boolean value
     *
     *  Purpose: Check whether element is within range of min and max value,
     *           exclusive of the min & max; Throws an out_of_range exception 
     *           if min value is greater than or equal to max value     
     *
     *
     *   *   *   *   *   *   */
    template <typename T>
    bool RangeCheck<T>::inRngExcl(const T& elem, const T& min, const T& max)
                            throw (std::out_of_range)
    {
        if (min >= max)
        {
            throw std::out_of_range("Error: RangeCheck<>::isInRngExcl():"
                "Min value greater than or equal to max value");
        }
        
        return ((elem > min) && (elem < max));
    }
    
    /*   *   *   *   *   *   *
     * 
     * Function: inRngInclMin(const T&, const T&, const T&)
     * 
     *    Input: Data element, minimum & maximum values for comparison
     *
     *   Output: Boolean value
     *
     *  Purpose: Check whether element is within range of min and max value,
     *           inclusive of the minimum; Throws an out_of_range exception 
     *           if min value is greater than or equal to max value     
     *
     *
     *   *   *   *   *   *   */
    template <typename T>
    bool RangeCheck<T>::inRngInclMin(const T& elem, const T& min, const T& max)
                            throw (std::out_of_range)
    {
        if (min >= max)
        {
            throw std::out_of_range("Error: RangeCheck<>::isInRngExcl():"
                "Min value greater than or equal to max value");
        }
        
        return (!(elem < min) && (elem < max));
    }
    
    /*   *   *   *   *   *   *
     * 
     * Function: inRngInclMax(const T&, const T&, const T&)
     * 
     *    Input: Data element, minimum & maximum values for comparison
     *
     *   Output: Boolean value
     *
     *  Purpose: Check whether element is within range of min and max value,
     *           inclusive of the maximum; Throws an out_of_range exception 
     *           if min value is greater than or equal to max value     
     *
     *
     *   *   *   *   *   *   */
    template <typename T>
    bool RangeCheck<T>::inRngInclMax(const T& elem, const T& min, const T& max)
                            throw (std::out_of_range)
    {
        if (min >= max)
        {
            throw std::out_of_range("Error: RangeCheck<>::isInRngExcl():"
                "Min value greater than or equal to max value");
        }
        
        return ((elem > min) && !(elem > max));
    }
    
    /*   *   *   *   *   *   *
     * 
     * Function: inRngInclMax(const T&, const T&, const T&)
     * 
     *    Input: Data element, minimum & maximum values for comparison
     *
     *   Output: Boolean value
     *
     *  Purpose: Check whether element is within range of min and max value,
     *           inclusive of the maximum; Throws an out_of_range exception 
     *           if min value is greater than or equal to max value     
     *
     *
     *   *   *   *   *   *   */
    template <typename T>
    bool RangeCheck<T>::inRngIncl(const T& elem, const T& min, const T& max)
                            throw (std::out_of_range)
    {
        if (min > max)
        {
            throw std::out_of_range("Error: RangeCheck<>::isInRngExcl():"
                "Min value greater than max value");
        }
        
        return (!(elem < min) && !(elem > max));
    }
    
} // RCheckMarven