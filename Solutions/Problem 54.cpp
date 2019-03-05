/*
Problem 54: Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    //Check if the matrix is empty
    if(matrix.empty()) return {};
    
    int m = matrix.size(), n = matrix[0].size();
    vector<int> output(m * n);//Allocate Space - Faster
      
    //Set up most variables
    int upMost = 0, leftMost = 0, downMost = m-1, rightMost = n-1;
    
    //Setup index variable
    int k = 0;
    
    //Loop through the matrix
    while(true)
    {
      //Right
      for(int col = leftMost; col <= rightMost; ++col) output[k++] = matrix[upMost][col];
      if(++upMost > downMost) break;
      
      //Down
      for(int row = upMost; row <= downMost; ++row) output[k++] = matrix[row][rightMost];
      if(--rightMost < leftMost) break;
      
      //Left
      for(int col = rightMost; col >= leftMost; --col) output[k++] = matrix[downMost][col];
      if(--downMost < upMost) break;
      
      //Up
      for(int row = downMost; row >= upMost; --row) output[k++] = matrix[row][leftMost];
      if(++leftMost > rightMost) break;
    }
    
    return output;
  }
};