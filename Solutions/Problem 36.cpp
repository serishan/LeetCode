/*
Question 36: Valid Sudoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

1) Each row must contain the digits 1-9 without repetition.
2) Each column must contain the digits 1-9 without repetition.
3) Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

1) A Sudoku board (partially filled) could be valid but is not necessarily solvable.
2) Only the filled cells need to be validated according to the mentioned rules.
3) The given board contain only digits 1-9 and the character '.'.
4) The given board size is always 9x9.

*/

/**********************************************************************/

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>>& board)
  {
    //Check Every Rows
    for (auto r : board)
    {
      map<char, int> count;
      for (int i = 0; i < r.size(); ++i)
      {
        if (r[i] == '.') continue;
        if (count[r[i]]) return false;
        count[r[i]]++;
      }
    }

    //Check Every Column
    for (int col = 0; col < 9; ++col)
    {
      map<char, int> count;
      for (int row = 0; row < 9; ++row)
      {
        if (board[row][col] == '.') continue;
        if (count[board[row][col]]) return false;
        count[board[row][col]]++;
      }
    }


    //Check Every Grid
    for (int i = 0; i < 9; i++)
    {
      int r = 3 * (i / 3);
      int c = 3 * (i % 3);
      map<char, int> nums;
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (board[r + j][c + k] == '.') continue;
          if (nums[board[r + j][c + k]]) {
            return false;
          }
          nums[board[r + j][c + k]]++;
        }
      }
    }

    return true;
  }
};