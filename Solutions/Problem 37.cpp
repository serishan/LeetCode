/*
Question 37: Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

1) Each of the digits 1-9 must occur exactly once in each row.
2) Each of the digits 1-9 must occur exactly once in each column.
3) Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.

Note:
1) The given board contain only digits 1-9 and the character '.'.
2) You may assume that the given Sudoku puzzle will have a single unique solution.
3) The given board size is always 9x9.
*/

/**********************************************************************/

class Solution
{
private:
  bool row[9][9] = {};
  bool col[9][9] = {};
  bool grid[9][9] = {};
  bool found = false;

public:
  void Place(int num, vector<vector<char>>& board)
  {
    if (num == 81)//End of the board
    {
      found = true;
      return;
    }

    int i = num / 9, j = num % 9;
    int index = (i / 3) * 3 + (j / 3) % 3;
    if (board[i][j] == '.') {
      for (int c = 0; c < 9; ++c) {
        if (!row[i][c] && !col[j][c] && !grid[index][c]) {
          row[i][c] = true;
          col[j][c] = true;
          grid[index][c] = true;
          board[i][j] = c + '1';

          Place(num + 1, board);

          if (found)
            return;

          board[i][j] = '.';
          row[i][c] = false;
          col[j][c] = false;
          grid[index][c] = false;

        }
      }
    }
    else
      Place(num + 1, board);

    return;
  }

  void solveSudoku(vector<vector<char>>& board)
  {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          row[i][board[i][j] - '1'] = true;
          col[j][board[i][j] - '1'] = true;
          grid[(i / 3) * 3 + (j / 3) % 3][board[i][j] - '1'] = true;
        }
      }
    }
    Place(0, board);
    return;
  }
};