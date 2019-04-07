/*
Problem 67: Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/

/* Time: 8ms */
class Solution {
public:
  string addBinary(string a, string b) 
  {
    string output;
    
    int end1 = a.size() - 1, end2 = b.size() - 1;
    int carry = 0;
    
    while(end1 >= 0 || end2 >= 0 || carry == 1)
    {
      carry += end1 >= 0 ? a[end1--] - '0' : 0;
      carry += end2 >= 0 ? b[end2--] - '0' : 0;
      output.insert(0, 1, char(carry%2 + '0'));
      carry /= 2;
    }
    
    return output;
  }
};