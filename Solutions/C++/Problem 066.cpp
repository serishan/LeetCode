/*
Problem 66: Plus One

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

/* Time: 4ms */
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) 
  {
    int start = digits.size()-1, end = 0;
    int carry = 0;
    
    for(int i = start; i >= end; --i)
    {
      int sum = 0;
      
      if(i == start) digits[i]++;
      
      sum += carry;
      sum += digits[i];
      
      carry = (sum/10);
      digits[i] = (sum%10);
    }
    
    //If front value is 0, this means the length needs to be resized
    if(digits[0] == 0)
    {
      digits.resize(digits.size()+1);
      digits[0] = 1;
    }
    
    return digits;
  }
};