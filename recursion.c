#include <stdio.h>
#include <stdlib.h>

            EXAMPLE OF RECURSION USING A POWER FUNCTION

int _pow_recursion(int x, int y)
{
    if (y < 0)
    {
        return (-1);
    }
    if (y == 0)  <-------------- BASE CASE <---The function will keep calling
    {                                          itself until the base case
        return (1);                            condition is met.
    }
    return (_pow_recursion(x, y - 1) * x);
}

/* Example of function implementation of 2 to the 3rd power */

 _pow_recursion(2, 3)
-----> 2^3 = 8 <----- Example of power function
        |                                                        SUCCESS
	v                                                           v
	v                                                           v
call _pow_recursion((2, 3 - 1) * 2)               return (4) * 2 -> 8  <<<<<<<<

call _pow_recursion((2, 2 - 1) * 2)               return (2) * 2 -> 4

call _pow_recursion((2, 1 - 1) * 2)               return (1) * 2 -> 2
	|                                                 ^
	v                                                 ^
	base case reached (y == 0)                        ^
	|                                                 |
	------------------>  return (1) -------------------

/* We are storing variables on the STACK (randomly assigned unique address) */
/* STACK: This is a data structure in which items are removed in reverse order*/

       ------------------->>>    initial function call     <<<-----------------
	------------------->>>    _pow_recursion(2, 3)    <<<-----------------
        __________________________________________|
        |
	v      STACK    /* Variables being stored at random addresses */
-------------------------------------
|  VARIABLE |  VALUE   |   ADDRESS  |
-------------------------------------
|     x     |    2     | 0x01       |        FUNCTION CALLS UNTIL BASE CASE
|     y     |    3     | 0x02       |        -------------------------------
|           |	       |            | ------->  _pow_recursion((2, 3 - 1) * 2)
-------------------------------------                          |
|     x     |    2     | 0x03       | <-------------------------
|     y     |    2     | 0x04       |
|           |	       |            | ------->  _pow_recursion((2, 2 - 1) * 2)
-------------------------------------                          |
|     x     |    2     | 0x05       | <-------------------------
|     y     |    1     | 0x06       |
|           |	       |            | ------->  _pow_recursion((2, 1 - 1) * 2)
-------------------------------------                   |              ^
		                                        |       /* Base Case */
The_pow_recursion function will return 1                |           y == 0
once the base case is met.             |                |
                                       |                v
                                      |-->|-------------1--------------|
		                      |   _pow_recursion((2, 1 - 1) * 2) == 2
                                      |                 v
                RETURN VALUES ----------->|-------------2--------------|
	                              |   _pow_recursion((2, 2 - 1) * 2) == 4
                                      |                 v
                                      |-->|-------------4--------------|
		                          _pow_recursion((2, 3 - 1) * 2) == 8

       /* All items on the stack are removed after recursion is done */

     The function _pow_recursion(2, 3) will recursively return 8 on success.