/*
Question 17: Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution
{
public:
  void AppendLetter(int size, string letterGroup, vector<string>& inout)
  {
    vector<string> tempOutput;

    for (int i = 0; i < inout.size(); ++i)
    {
      for (int j = 0; j < size; ++j)
      {
        string temp = (inout[i] + letterGroup[j]);
        tempOutput.push_back(temp);
      }
    }

    inout = tempOutput;
  }

  vector<string> letterCombinations(string digits)
  {
    std::vector<std::string> output;

    std::unordered_map<char, std::string> numToString{
      {'1', ""},
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "pqrs"},
      {'8', "tuv"},
      {'9', "wxyz"},
    };

    //First letter specification
    if (digits.length() == 1 && digits[0] == '1') return {};
    else
    {
      auto letter = numToString.find(digits[0]);
      if (letter == numToString.end()) return {};

      output.resize(letter->second.size());
      for (int i = 0; i < letter->second.length(); ++i)
        output[i] += letter->second[i];
    }

    //Real work
    for (int i = 1; i < digits.length(); ++i)
    {
      auto letter = numToString.find(digits[i]);
      if (letter == numToString.end()) return {};

      AppendLetter(letter->second.length(), letter->second, output);
    }

    return output;
  }
};