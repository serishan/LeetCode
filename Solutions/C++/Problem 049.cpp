/*
Problem 49: Group Angrams
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) 
  {
    unordered_map<wstring, vector<string>> map;
    wstring histo(26, 0);
    for (const string& s : strs){
      for (char c : s) histo[c - 'a']++;//Increase the Counter of each letter
      map[histo].push_back(move(s));
      histo.assign(26, 0);
    }

    vector<vector<string>> result;
    for (auto& kv : map)
      result.push_back(move(kv.second));

    return result;
  }
};