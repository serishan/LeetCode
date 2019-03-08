/*
Question 7: Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
*/

class Solution
{
public:
  /*
  int x - number that needs to be reversed
  */
  int reverse(int x)
  {
    int rev = 0;

    while (x != 0)
    {
      int rem = x % 10;
      x /= 10;

      //Check the overflow
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7)) return 0;
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8)) return 0;
      rev = rev * 10 + rem;
    }

    return rev;
  }
};