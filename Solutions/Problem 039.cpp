/*
Question 39: Combination Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*/

/**********************************************************************/

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target)
  {
    //First, sort the array
    sort(candidates.begin(), candidates.end());

    //Remove Duplicates
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    vector<int> r;
    vector<vector<int>> result;

    FindNumbers(candidates, target, result, r, 0);

    return result;
  }

private:
  void FindNumbers(vector<int>& input, int sum, vector<vector<int>>& output, vector<int>& r, int i)
  {
    if (sum < 0) return;
    if (sum == 0)
    {
      output.push_back(r);
      return;
    }

    while (i < input.size() && sum - input[i] >= 0)
    {
      r.push_back(input[i]);
      FindNumbers(input, sum - input[i], output, r, i);
      ++i;

      r.pop_back();
    }
  }
};