/*
Question 22: Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution
{
private:
  vector<string> output;

public:
  void Helper(string s, int leftPare, int moreLeft)
  {
    //Everything is closed. Push back current string
    if (leftPare == 0 && moreLeft == 0)
    {
      output.push_back(s);
      return;
    }

    //Left Parentheses is needed
    if (leftPare > 0)
      Helper(s + "(", leftPare - 1, moreLeft + 1);

    //Need Closing Parenthes
    if (moreLeft > 0)
      Helper(s + ")", leftPare, moreLeft - 1);
  }

  vector<string> generateParenthesis(int n)
  {
    //First Check the input
    if (n == 0) return {};

    //if input number is 1, no variation needed
    else if (n == 1) output.push_back("()");

    //More than 2
    else
      Helper("", n, 0);

    return output;
  }
};