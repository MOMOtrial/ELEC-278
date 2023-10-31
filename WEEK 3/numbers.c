// Numbers
//The C language standard includes buit-in integer types char, short,
//int, long, and long long.

The C language standard includes buit-in integer types char, short,
int, long, and long long.
The exact size of each depends on the computer architecture (but
                                                             there are some common conventions).
Each of these can be marked as signed (the default) or unsigned

The C language standard includes buit-in integer types char, short,
int, long, and long long.
The exact size of each depends on the computer architecture (but
                                                             there are some common conventions).
Each of these can be marked as signed (the default) or unsigned.
size_t is an alias of one of the unsigned types (for example,
unsigned long long).


To avoid the ambiguity of the built-in types, the standard library
header stdint.h defines several exact-with integer types.
These allow you to specify the exact type, if needed.
For example, uint8_t is an unsigned 8-bit (1-byte) integer, while
int16_t is a signed 16-bit (2-byte) integer.



C includes two built-in floating point types, float and double.
A floating-point number stores arbitrary real numbers in a format
similar to scientific notation.
Floating-point types cannot store numbers at arbitrary precision.


The C standard library includes functions for parsing numbers from strings:
    strtol() parses a long from a string.
    strtof() parses a float from a string.
Let’s look at how to use these.




Here is a rough plan for parsing integers from a string:
    Loop over the string until you see a character that is not a digit.
    For each digit, use the fact that characters are stored as a number, and
    subtract '0' to get the actual numeric value it represents.
    Multiply by 10 each time to see another digit.
Remember: there is more than one right answer

// Parses an unsigned integer to 'out', stopping at the first non-digit character.
// Returns the number of digits read; if this is 0 then no number was read.
size_t parse_num(const char *str, unsigned int *out) {
    // Make sure first digit is an integer.
    if (str[0] < '0' || str[0] > '9')
        return 0;
    unsigned int result = 0;
    size_t i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result *= 10;
        result += str[i++] - '0';
    }
    *out = result;
    return i;
}
