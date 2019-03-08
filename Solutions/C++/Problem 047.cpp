/*
Problem 47: Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution
{
public:
  vector<vector<int>> permuteUnique(const vector<int> &nums)
  {
      vector<int> intermediate;
      unordered_map<int, int> available;
      vector<vector<int>> result;
      vector<int> uniqNums;

      for (auto item: nums) {
        if (!available[item]) {
            uniqNums.push_back(item);
        }
        available[item]++;
      }
      this->permute(result, nums.size(), uniqNums, intermediate, available);
      return result;
  }

private:
  void permute(vector<vector<int>> &result, int size, const vector<int> &nums, vector<int> &intermediate, unordered_map<int, int> &available)
  {
      if (intermediate.size() == size)
      {
        result.push_back(intermediate);
        return;
      }
      for (auto item : nums)
      {
        if (available[item])
        {
          intermediate.push_back(item);
          available[item]--;
          this->permute(result, size, nums, intermediate, available);
          intermediate.pop_back();
          available[item]++;
        }
      }
  }
};