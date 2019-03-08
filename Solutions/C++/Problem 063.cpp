/*
Problem 63: Unique Paths II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

NAn obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/

/* Time: 4ms */
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
  {
    vector<vector<long>> v {obstacleGrid.size(), vector<long>(obstacleGrid[0].size(), 0)};
        v[0][0] = obstacleGrid[0][0] ^ 1;
        
        for(int i = 0; i < obstacleGrid.size(); ++i)
        {
          for(int k = 0; k < obstacleGrid[0].size(); ++k)
          {
            if(i != 0 && obstacleGrid[i-1][k] != 1 && obstacleGrid[i][k] != 1)
              v[i][k] += v[i-1][k];

            if(k != 0 && obstacleGrid[i][k-1] != 1 && obstacleGrid[i][k] != 1)
              v[i][k] += v[i][k-1];
          }
        }
        
        int m = v.size() - 1;
        int n = v[0].size() - 1;
        return v[m][n];
    }
};