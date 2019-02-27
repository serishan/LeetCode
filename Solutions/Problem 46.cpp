/*
Question 46: Permutations

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

/**********************************************************************/

class Solution {
private:
  void Permutation(vector<int> nums, int pivot, vector<vector<int>>& output)
  {
    if (pivot >= nums.size())
    {
      output.push_back(nums);
      return;
    }

    for (int i = pivot; i < nums.size(); ++i)
    {
      swap(nums[pivot], nums[i]);
      Permutation(nums, pivot + 1, output);
      swap(nums[pivot], nums[i]);
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums)
  {
    vector<vector<int>> output;

    //Permutation is needed
    Permutation(nums, 0, output);

    return output;
  }
};