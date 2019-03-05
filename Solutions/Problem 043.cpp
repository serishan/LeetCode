/*
Question 43: Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

1) The length of both num1 and num2 is < 110.
2) Both num1 and num2 contain only digits 0-9.
3) Both num1 and num2 do not contain any leading zero, except the number 0 itself.
4) You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

/**********************************************************************/

class Solution {
public:
  string multiply(string num1, string num2)
  {
    if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") return"0";

    int m = num1.length(), n = num2.length();

    string output(m + n, '0');//Initialize the length of the output with '0'

    for (int i = m - 1; i >= 0; --i)
    {
      for (int j = n - 1; j >= 0; --j)
      {
        int val = (num1[i] - '0') * (num2[j] - '0') + (output[i + j + 1] - '0');
        output[i + j + 1] = val % 10 + '0';
        output[i + j] = val / 10 + '0' + output[i + j] - '0';
      }
    }

    return (output[0] == '0') ? output.substr(1) : output;
  }
};