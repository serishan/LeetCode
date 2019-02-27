/*
Question 31: Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/**********************************************************************/

class Solution
{
public:
  void nextPermutation(vector<int>& nums)
  {
    //next_permutation(nums.begin(), nums.end());
    if (nums.empty()) return;

    bool ascending = false;
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;

    if (i >= 0)
    {
      auto it = lower_bound(nums.begin() + i + 2, nums.end(), nums[i], [](int n1, int n2) {return n1 > n2; });
      --it;
      swap(nums[i], *it);
    }

    reverse(nums.begin() + i + 1, nums.end());
  }
};