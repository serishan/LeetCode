/*
Quesetion 1: Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

[Example 1]
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

[Example 2]
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

[Example 3]
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/********************************************************************************/

class Solution
{
public:
  /*
  [Function]
  lengthOfLongestSubstring

  [Parameter]
  s - string to find substring

  [Return]
  Length of the longest substring
  */
  int lengthOfLongestSubstring(string s)
  {
    vector m(128, -1);
    int res = 0, left = -1;
    for (int i = 0; i < s.length(); ++i)
    {
      left = max(left, m[s[i]]);
      m[s[i]] = i;
      res = max(res, i - left);
    }

    return res;
  }
};