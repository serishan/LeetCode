/*
Problem 64: Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

/* Time: 12ms */
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) 
  {
    int downMost = grid.size(), rightMost = grid[0].size();
    
    //Initialize the new grid to value 0
    vector<vector<int>> DPGrid(downMost, vector<int>(rightMost, 0));
    
    DPGrid[downMost-1][rightMost-1] = grid[downMost-1][rightMost-1];
    
    //Initial values that need to be saved in the grid for dynamic programming
    //For going left
    for(int i = rightMost-2; i >= 0; --i)
      DPGrid[downMost-1][i] = DPGrid[downMost-1][i+1] + grid[downMost-1][i];
    
    //For going top
    for(int i = downMost-2; i >= 0; --i)
      DPGrid[i][rightMost-1] = DPGrid[i+1][rightMost-1] + grid[i][rightMost-1];
    
    for(int col = rightMost - 2; col >= 0; --col)
      for(int row = downMost - 2; row >= 0; --row)
        DPGrid[row][col] = min(DPGrid[row][col+1]+grid[row][col], DPGrid[row+1][col]+grid[row][col]);
    
    return DPGrid[0][0];
  }
};