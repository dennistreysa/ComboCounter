# ComboCounter
A simple tool to determine the number of combinations that can be made with a given set of values and a total value (and optionally a maximum number of values).

## Usage
Set TOTAL_VALUE, VALUES (and array size), MAX_VALUES (no limit = 0) to preferred values and compile with your favorite C++ Compiler ;)

## Example 1
TOTAL_VALUE = 666\
VALUES = {1, 2, 5, 10, 20, 50, 100, 200}\
MAX_VALUES = 42\

**Output:**

> Total value: 666\
> Number of fractals: 8\
> Maximum number of values: 42\
> Number of possibilities: 155465\
> Time needed: xxx ms\


## Example 2
TOTAL_VALUE = 666\
VALUES = {1, 2, 5, 10, 20, 50, 100, 200}\
MAX_VALUES = 0\

**Output:**

> Total value: 666\
> Number of fractals: 8\
> Maximum number of values: 0\
> Number of possibilities: 30347250\
> Time needed: xxx ms\
