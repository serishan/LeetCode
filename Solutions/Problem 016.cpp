/*
Question 16: 3Sum Closest

Given an array nums of n integers and an integer target, find three integers in nums
such that the sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution
{
public:
  int threeSumClosest(vector<int>& nums, int target)
  {
    int TotalSum = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
      int l = i + 1;
      int r = nums.size() - 1;

      while (l < r)
      {
        int temp = nums[i] + nums[l] + nums[r];
        if (temp < target)
        {
          if (abs(TotalSum - target) > abs(temp - target))
            TotalSum = temp;

          ++l;
        }

        else if (temp > target)
        {
          if (abs(TotalSum - target) > abs(temp - target))
            TotalSum = temp;

          --r;
        }

        else return target;
      }
    }

    return TotalSum;
  }
};