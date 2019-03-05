/*
Problem 48: Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

class Solution {
public:
  void rotate(vector<vector<int>>& matrix)
  {
    //Check if matrix is empty or its size is one
    if (matrix.empty() || matrix.size() == 1) return;

    //Rotate - Only touch 1/4 of matrix
    int lvl = matrix.size() / 2;
    int n = matrix.size();

    for (int l = 0; l < lvl; l++)
    {
      for (int i = l; i < n - l - 1; i++)
      {
        int temp = matrix[l][i];

        matrix[l][i] = matrix[n - i - 1][l];
        matrix[n - i - 1][l] = matrix[n - l - 1][n - i - 1];
        matrix[n - l - 1][n - i - 1] = matrix[i][n - l - 1];
        matrix[i][n - l - 1] = temp;
      }
    }
  }
};