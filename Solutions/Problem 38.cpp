/*
Question 38: Count and Say

WThe count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"

*/

/**********************************************************************/

class Solution
{
public:
  string countAndSay(int n)
  {
    string output;
    //Just 1 number
    if (n == 1) return "1";
    if (n == 2) return "11";

    //This is for generating n-th term
    output = "11";
    for (int i = 3; i <= n; ++i)
    {
      int cnt = 1;
      output += "$";//Any value for extra iteration
      string tmp = "";
      for (int j = 1; j < output.length(); ++j)
      {
        if (output[j] != output[j - 1])
        {
          tmp += cnt + '0';
          tmp += output[j - 1];
          cnt = 1;
        }

        else cnt++;
      }

      output = tmp;
    }

    return output;
  }
};