/*
Question 42: Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/

/**********************************************************************/

class Solution {
public:
  int trap(vector<int>& height)
  {
    int left = 0, right = height.size() - 1;
    int maxLeft = 0, maxRight = 0;
    int output = 0;

    while (left <= right)
    {
      if (height[left] <= height[right])
      {
        if (height[left] >= maxLeft) maxLeft = height[left];
        else output += maxLeft - height[left];
        ++left;
      }

      else
      {
        if (height[right] >= maxRight) maxRight = height[right];
        else output += maxRight - height[right];
        --right;
      }
    }

    return output;
  }
};