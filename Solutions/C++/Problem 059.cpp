/*
Problem 59: Spiral Matrix II

Given a positive integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/* Time: 4ms */
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) 
  {
	//Assign the space before actual action saves time
    vector<vector<int>> output(n, vector<int>(n, 0));
    if(n == 0) return {};
    if(n == 1) {
      vector<vector<int>> output{{1}};
      return output;
    }
    
    /*
    totalSize - Total Vector size
    e_Size - each element vector size
    */
    int totalSize = output.size(), e_Size = output[0].size();
    
    int number = 1; //This is for number input
    int leftMost = 0, upMost = 0, rightMost = n-1, downMost = totalSize-1;
    
    while(true)
    {
      //Right
      for(int col = leftMost; col <= rightMost; ++col) output[upMost][col] = number++;
      if(++upMost > downMost) break;
      
      //Down
      for(int row = upMost; row <= downMost; ++row) output[row][rightMost] = number++;
      if(--rightMost < leftMost) break;
      
      //Left
      for(int col = rightMost; col >= leftMost; --col) output[downMost][col] = number++;
      if(--downMost < upMost) break;
      
      //Up
      for(int row = downMost; row >= upMost; --row) output[row][leftMost] = number++;
      if(++leftMost > rightMost) break;
    }
    
    return output;
  }
};