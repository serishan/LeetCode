/*
Question 5: Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

[Example 1]
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

[Example 2]
Input: "cbbd"
Output: "bb"
*/

class Solution
{
public:
  /*
  [Function]
  longestPalindrome

  [Parameter]
  s - string that needs for checking palindrome

  [Return]
  Longest Palindrome string
  */
  string longestPalindrome(string s)
  {
    int start = 0, end = 0;

    //Check if string is empty
    if (s.empty())
      return "";

    else
    {
      for (int center = 0; center < s.size(); ++center)
      {
        int len1 = PaliLength(center, center, s);
        int len2 = PaliLength(center, center + 1, s);

        if (len1 > end - start)
        {
          start = center - len1 / 2;
          end = center + len1 / 2;
        }

        if (len2 > end - start)
        {
          start = center + 1 - len2 / 2;
          end = center + len2 / 2;
        }
      }
    }

    return s.substr(start, end - start + 1);
  }

  int PaliLength(int L, int R, string S)
  {
    int len = 0;
    while (L >= 0 && R < S.size())
    {
      if (S[L] == S[R])
      {
        len = R - L + 1;
        L--;
        R++;
      }

      else
        break;
    }

    return len;
  }
};