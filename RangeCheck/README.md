## RangeCheck ##

A C++ template class that checks whether a value is within minimum and maximum
values.

The methods use the <, >, and >= operators, so it must be used with types that
support those operators.

#### Methods ####

* excl() Check if value is in the range, exclusive of minimum and maximum
    * Example: (0, 100)
* inclMin() Check if value is in the range, inclusive of minimum only
    * Example: [0, 100)
* inclMax() Check if value is in the range, inclusive of maximum only
    * Example: (0, 100]
* incl() Check if value is in the range, inclusive of both min and max
    * Example: [0, 100]
