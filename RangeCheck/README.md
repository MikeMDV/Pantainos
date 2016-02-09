## RangeCheck ##

A C++ template class that checks whether a value is within minimum and maximum
values.

The methods use the <, >, and >= operators, so it must be used with types that
support those operators.

#### Methods ####

* inRngExcl() Check if value is in the range, exclusive of minimum and maximum
    * Example: (0, 100)
* inRngInclMin() Check if value is in the range, inclusive of minimum only
    * Example: [0, 100)
* inRngInclMax() Check if value is in the range, inclusive of maximum only
    * Example: (0, 100]
* inRngIncl() Check if value is in the range, inclusive of both min and max
    * Example: [0, 100]