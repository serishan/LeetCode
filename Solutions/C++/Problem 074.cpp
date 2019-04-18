/*
Problem 74: Seaerch a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

/* Time: 20 ms */
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) 
  {
    if(matrix.empty()) return false;
    if(matrix[0].empty()) return false;
    
    int right = matrix[0].size();
    int down = matrix.size();
    
    int row;
    int col;
    
    for(row = 0; row < down; ++row)
      if(target <= matrix[row][right-1]) break;
    
    if(row == down) return false;
    
    for(col = 0; col < right; ++col)
    {
      if(target == matrix[row][col])
        return true;
    }
    
    return false;
  }
};