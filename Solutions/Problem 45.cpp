/*
Question 45: Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:
  You can assume that you can always reach the last index.
*/

/**********************************************************************/

class Solution {
public:
  int jump(vector<int>& nums)
  {
    // Think about recursive
    int n = nums.size();
    vector<int> minimal_jumps(n, n + 1);
    minimal_jumps[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
      for (int j = i + 1; j <= i + nums[i] && j < n; j++)
        if (minimal_jumps[i] > minimal_jumps[j] + 1)
          minimal_jumps[i] = minimal_jumps[j] + 1;

    return minimal_jumps[0];
  }
};