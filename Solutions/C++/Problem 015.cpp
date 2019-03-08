/*
Question 15: 3 Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    vector<vector<int>> output;

    //Empty Vector - Return Nothing
    if (nums.empty()) return {};

    //When Input Vector is not empty, the real work starts
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
      //Ensure everything is less than or same to 0
      int target = -nums[i];
      int front = i + 1;
      int back = nums.size() - 1;

      if (target < 0) break;

      while (front < back)
      {
        int sum = nums[front] + nums[back];

        if (sum < target) ++front;
        else if (sum > target) --back;
        else
        {
          vector<int> triplet(3, 0);
          triplet[0] = nums[i];
          triplet[1] = nums[front];
          triplet[2] = nums[back];
          output.push_back(triplet);

          //Processing duplicate of number 2
          while (front < back && nums[front] == triplet[1]) ++front;

          //Processing duplicate of number 3
          while (front < back && nums[back] == triplet[2]) --back;
        }
      }

      //Processing duplicate of number 1
      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
    }

    return output;
  }
};