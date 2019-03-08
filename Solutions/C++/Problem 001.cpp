/*
Quesetion 1: Two Sum

Given an array of integers, return INDICES of the two numbers such that they
add up to a specific target.

You may assume that each input would have EXACTLY one solution, and you may 
not use the same element twice

[Example]
Given Nums = [2, 7, 11, 15], Target = 9,
return [0, 1] (nums[0] + nums[1] = 2 + 7 = 9)
*/

class Solution 
{
public:
  /*
  [Function]
  twoSum

  [Parameter:]
  nums - vector of int that holds the number that needs to be added
  target - The target number which we needs to find out by adding.

  [Return]
  vector of int that holds the indices of number
  */
  vector<int> twoSum(vector<int>& nums, int target)
  {
    vector<int> output;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = i + 1; j < nums.size(); ++j)
      {
        if (nums[i] + nums[j] == target)
        {
          output.push_back(i);
          output.push_back(j);
        }
      }
    }

    return output;
  }
};