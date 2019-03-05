/*
Question 32: Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

/**********************************************************************/

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int left = 0, right = 0, length = 0;

    for (int i = 0; i < s.length(); ++i)
    {
      if (s[i] == '(') ++left;
      else ++right;

      if (left == right) length = max(length, 2 * right);
      else if (right >= left) left = right = 0;
    }

    left = right = 0;
    for (int i = s.length() - 1; i >= 0; --i)
    {
      if (s[i] == '(') ++left;
      else ++right;

      if (left == right) length = max(length, 2 * left);
      else if (right <= left) left = right = 0;
    }

    return length;
  }
};