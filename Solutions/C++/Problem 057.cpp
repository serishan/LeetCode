/*
Problem 57: Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
  {
    /*
    Time: 32ms
    
    vector<Interval> output;
    
    if(intervals.empty()) {output.push_back(newInterval); return output;}
    
    //Add the new Interval to the intervals
    intervals.push_back(newInterval);
    
    //Sort the Intervals
    sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
    
    //Check the interval with starting value
    output.push_back(intervals[0]);//Initialize
    for(int i = 0; i < intervals.size(); ++i)
    {
      if(output.back().end < intervals[i].start) output.push_back(intervals[i]);
      else output.back().end = max(output.back().end, intervals[i].end);
    }
    
    return output;*/
	
    /******************************************************************************************************/
	
    /* Time: 12ms */
    vector<Interval> output;
    int index = 0; //Index Variable
    
    //Push all the intervals that have smaller end value then new Interval Start Value
    while(index < intervals.size() && intervals[index].end < newInterval.start)
      output.push_back(intervals[index++]);
    
    //New Interval Modification
    while(index < intervals.size() && intervals[index].start <= newInterval.end)
    {
      newInterval.start = min(newInterval.start, intervals[index].start);
      newInterval.end = max(newInterval.end, intervals[index].end);
      ++index;
    }
    
    output.push_back(newInterval);
    
    //Push back the left over intervals.
    while(index < intervals.size())
      output.push_back(intervals[index++]);
    
    return output;
  }
};