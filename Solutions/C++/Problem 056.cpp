/*
Problem 56: Merge Interval

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) 
  {
    //Check if the input is empty
    if(intervals.empty()) return {};
    
    //Sort the Intervals by Starting Value
    sort(intervals.begin(), intervals.end(), [](Interval& start, Interval& end){return start.start < end.start;});
    
    //If Merge needed, Merge. If not, Push back to vector
    vector<Interval> output{intervals[0]};//Initialize
    for(int i = 0; i < intervals.size(); ++i)
    {
      if(output.back().end < intervals[i].start) output.push_back(intervals[i]);
      else output.back().end = max(output.back().end, intervals[i].end);
    }
    
    return output;
  }
};