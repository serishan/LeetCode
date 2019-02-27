/*
Question 6: ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of 
rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
Output: "bb"
*/

class Solution
{
public:
  /*
  string s - string variable that needs to be zigzagged
  numRows - number of rows that will be writen
  */
  string convert(string s, int numRows)
  {
    if (numRows == 1) return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s)
    {
      rows[curRow] += c;
      if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
      curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows) ret += row;

    return ret;
  }
};