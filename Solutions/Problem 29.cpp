/*
Question 29: Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the
32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem,
assume that your function returns 2^31 − 1 when the division result overflows.
*/

/**********************************************************************/

class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    while (dvd >= dvs)
    {
      long temp = dvs, m = 1;
      while (dvd >= (temp << 1))
      {
        temp <<= 1;
        m <<= 1;
      }

      dvd -= temp;
      ans += m;
    }

    return sign * ans;
  }
};