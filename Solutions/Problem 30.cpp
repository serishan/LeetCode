/*
Question 30: Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]

Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/

/**********************************************************************/

class Solution
{
public:
  vector<int> findSubstring(string s, vector<string>& words)
  {
    unordered_map<string, int> wfreq; // word frequency
    vector<int>                ans;
    int                        slen;
    int                        wcount, wlen; // word count and word len 

    if (words.empty())
      return ans;

    for (string word : words)
      wfreq[word]++;

    slen = s.length();
    wcount = words.size();
    wlen = words[0].size();

    int i = 0, j = 0;
    for (i = 0; i < slen - wcount * wlen + 1; i++) {
      unordered_map<string, int> seen;
      for (j = 0; j < wcount; j++) {
        string word = s.substr(i + j * wlen, wlen);
        if (wfreq.find(word) == wfreq.end())
          break;

        seen[word]++;

        if (seen[word] > wfreq[word])
          break;
      }
      if (j == wcount)
        ans.push_back(i);
    }
    return ans;
  }
};