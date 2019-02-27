/*
Question 34: Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

/**********************************************************************/

class Solution
{
public:
  vector<int> searchRange(vector<int>& nums, int target)
  {
    if (nums.size() == 0) return { -1, -1 };

    int idx_lb = (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    if (idx_lb == nums.size() || nums[idx_lb] != target) return { -1, -1 };

    int idx_ub = (upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1;
    return { idx_lb, idx_ub };
  }
};