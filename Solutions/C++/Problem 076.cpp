/*
Problem 76: Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

/* Time: 12 ms */
class Solution {
public:
  string minWindow(string s, string t) 
  {
    //One of the string is empty
    if(s.length() == 0 || t.length() == 0) return "";
    if(s.length() < t.length()) return "";
    
    int hash_s[256] = {0};
    int hash_str[256] = {0};
    
    //Finding Occurence
    for(int i = 0; i < t.length(); ++i)
      hash_str[t[i]]++;
    
    int start = 0, start_idx = -1, minLen = INT_MAX;
    
    //Traverse
    int count = 0;
    for(int j = 0; j < s.length(); ++j)
    {
      //Count Occurence of char
      hash_s[s[j]]++;
      
      if(hash_str[s[j]] != 0 && hash_s[s[j]] <= hash_str[s[j]]) ++count;
      
      //Try to Minimize
      if(count == t.length())
      {
        while(hash_s[s[start]] > hash_str[s[start]] || hash_str[s[start]] == 0)
        {
          if(hash_s[s[start]] > hash_str[s[start]])
            --hash_s[s[start]];
          
          ++start;
        }
        
        //Update Window size
        int len_win = j - start + 1;
        if(minLen > len_win)
        {
          minLen = len_win;
          start_idx = start;
        }
      }
    }
    
    //No Window
    if(start_idx == -1)
      return "";
    
    return s.substr(start_idx, minLen);
  }
};