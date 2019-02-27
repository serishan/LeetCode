/*
Question 4: Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

[Example 1]
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

[Example 2]
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution
{
public:
  /* 
  [Function]
  findMedianSortedArrays

  [Parameters]
  nums1 - vector of int holding the first list of numbers
  nums2 - vector of int holding the second list of numbers

  [Return]
  Median value of two vectors
  */
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    double median = 0.0;

    //First merge two vectors and sort
    vector<int> destination;
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(destination));

    //Check the size of the merged vector

    //If it has odd elements
    if (destination.size() % 2 == 1)
    {
      int index = (destination.size() / 2);
      median = destination[index];
    }

    //Otherwise has even elements
    else
    {
      int index1 = (destination.size() / 2) - 1;
      int index2 = (destination.size() / 2);
      double center = (destination[index1] + destination[index2]) / 2.0;
      median = center;
    }

    return median;
  }
};