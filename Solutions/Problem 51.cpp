/*
Problem 51: N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

class Solution {
public:
  /*
  [Function] solveNQueens
  [Parameter]
  int n - Number of Queens
  
  [Return]
  vector<vector<string>> - board data
  */
  vector<vector<string>> solveNQueens(int n) 
  {
    vector<vector<string>> output;
    vector<string> nQueens(n, string(n, '.'));
    vector<int> flag(5*n - 2, 1);
    SolveNQueens(output, nQueens, flag, 0, n);
    
    return output;
  }
  
private:
  void SolveNQueens(vector<vector<string>>& out, vector<string>& nQueen, vector<int>& flag, int row, int& n)
  {
    if(row == n)
    {
      out.push_back(nQueen);
      return;
    }
    
    for(int col = 0; col != n; ++col)
    {
      if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
          flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
          nQueen[row][col] = 'Q';
          SolveNQueens(out, nQueen, flag, row + 1, n);
          nQueen[row][col] = '.';
          flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
      }
    }
  }
};