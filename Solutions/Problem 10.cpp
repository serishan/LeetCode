/*
Question 10: Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

class Solution
{
public:
  bool DPTopDown(int i, int j, const string& s, const string& p, vector<vector<int>>& table)
  {
    if (table[i][j] != -1)
      return table[i][j];

    bool result = false;

    if (j == p.size())
      result = (i == s.size());

    else
    {
      bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

      if (j + 1 < p.size() && p[j + 1] == '*')
        result = DPTopDown(i, j + 2, s, p, table) || (match && DPTopDown(i + 1, j, s, p, table));

      else
        result = match && DPTopDown(i + 1, j + 1, s, p, table);
    }

    return (table[i][j] = result);
  }

  /*
  string s - Text
  string p - pattern
  */
  bool isMatch(string s, string p)
  {
    vector<vector<int>> table(s.size() + 1, vector<int>(p.size() + 1));
    for (auto i = 0; i < table.size(); ++i)
      for (auto j = 0; j < table[i].size(); ++j)
        table[i][j] = -1;

    return DPTopDown(0, 0, s, p, table);
  }
};