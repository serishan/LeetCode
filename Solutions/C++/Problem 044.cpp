/*
Question 44: Wildcard matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:
1) s could be empty and contains only lowercase letters a-z.
2) p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/

/**********************************************************************/

class Solution {
public:
  /*
  s - original string
  p - string that needs to be compared
  */
  bool isMatch(string s, string p)
  {
    if (s.empty()) return p.empty() || p == "*";

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (auto ch : p) {
      // skip duplicate **
      bool prev = (dp[0] && ch == '*');

      for (int j = 1; j <= s.size(); j++) {
        // we will need dp[i-1][j-1] in next iteration, hence don't overwrite that value yet
        // for pattern '*', we have a special case, if previous match is valid, we can keep using '*'
        bool tmp = dp[j - 1] && (ch == '*' || ch == '?' || ch == s[j - 1]) ||
          // pattern '*' can match 0 or more chars, hence carry fwd prev || dp[i-1][j] result to dp[j]
          ((prev || dp[j]) && ch == '*');

        dp[j - 1] = prev;
        prev = tmp;
      }

      dp[s.size()] = prev;
    }

    return dp[s.size()];
  }
};