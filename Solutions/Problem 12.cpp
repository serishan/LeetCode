/*
Question 12: Integer to Roman

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution
{
public:
  void SubDigit(char c, char c2, string& output)
  {
    output += c;
    output += c2;
  }

  void MultipleDigit(char c, int n, string& output)
  {
    for (int j = 0; j < n; ++j)
      output += c;
  }

  string intToRoman(int num)
  {
    string output;

    //Loop until input number becomes 0
    while (num != 0)
    {
      if (num >= 1000)
      {
        MultipleDigit('M', num / 1000, output);
        num %= 1000;
      }

      else if (num >= 500)
      {
        if (num < 900)
        {
          MultipleDigit('D', num / 500, output);
          num %= 500;
        }

        else
        {
          SubDigit('C', 'M', output);
          num %= 100;
        }
      }

      else if (num >= 100)
      {
        if (num < 400)
        {
          MultipleDigit('C', num / 100, output);
          num %= 100;
        }

        else
        {
          SubDigit('C', 'D', output);
          num %= 100;
        }
      }

      else if (num >= 50)
      {
        if (num < 90)
        {
          MultipleDigit('L', num / 50, output);
          num %= 50;
        }

        else
        {
          SubDigit('X', 'C', output);
          num %= 10;
        }
      }

      else if (num >= 10)
      {
        if (num < 40)
        {
          MultipleDigit('X', num / 10, output);
          num %= 10;
        }

        else
        {
          SubDigit('X', 'L', output);
          num %= 10;
        }
      }

      else if (num >= 5)
      {
        if (num < 9)
        {
          MultipleDigit('V', num / 5, output);
          num %= 5;
        }

        else
        {
          SubDigit('I', 'X', output);
          num = 0;
        }
      }

      else if (num >= 1)
      {
        if (num < 4)
        {
          MultipleDigit('I', num, output);
          num = 0;
        }

        else
        {
          SubDigit('I', 'V', output);
          num = 0;
        }
      }
    }

    return output;
  }
};