/*
Question 18: 4 Sum

Given an array nums of n integers and an integer target, are there elements a, b, c, and d
in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    vector<vector<int>> output;

    //Check if input vector is empty
    if (nums.empty()) return {};
    //check the length
    if (nums.size() < 4) return {};

    if (nums.size() == 4)
    {
      int temp = nums[0] + nums[1] + nums[2] + nums[3];
      if (temp == target)
      {
        vector<int> dataVector;
        dataVector.push_back(nums[0]);
        dataVector.push_back(nums[1]);
        dataVector.push_back(nums[2]);
        dataVector.push_back(nums[3]);
        output.push_back(dataVector);
      }

      return output;
    }

    //Sort the vector
    sort(nums.begin(), nums.end());

    //Real work
    for (int i = 0; i < nums.size() - 3; ++i)
    {
      for (int j = i + 1; j < nums.size() - 2; ++j)
      {
        //if(nums[j] == nums[j-1]) continue;

        int temp = target - (nums[i] + nums[j]);
        int left = j + 1, right = nums.size() - 1;
        vector<int> dataVector;

        while (left < right)
        {
          if (nums[left] + nums[right] < temp) ++left;
          else if (nums[left] + nums[right] > temp) --right;
          else
          {
            dataVector.push_back(nums[i]);
            dataVector.push_back(nums[j]);
            dataVector.push_back(nums[left]);
            dataVector.push_back(nums[right]);

            if (output.empty())
            {
              output.push_back(dataVector);
              dataVector.clear();

              ++left;
              --right;
            }
            else
            {
              bool found = false;
              for (auto it : output)
              {
                if (it == dataVector)
                {
                  dataVector.clear();
                  ++left;
                  found = true;
                  break;
                }
              }

              if (!found)
              {
                output.push_back(dataVector);
                dataVector.clear();

                ++left;
                --right;
              }
            }
          }
        }
      }
    }

    return output;
  }
};