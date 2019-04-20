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

/* Time: 248 ms */
public class Solution {
  public int[] TwoSum(int[] nums, int target) 
  {
    int[] output = new int[2];
    Dictionary<int, int> dic = new Dictionary<int, int>();
    
    for(int i = 0; i < nums.Length; ++i)
    {
      if(dic.ContainsKey(nums[i]))
      {
        output[0] = dic[nums[i]];
        output[1] = i;
        return output;
      }
      
      dic[target-nums[i]] = i;
    }
    return output;
  }
}