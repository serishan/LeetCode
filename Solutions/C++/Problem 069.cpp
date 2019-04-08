/*
Problem 69: Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

*/

/* Time: 4ms */
class Solution {
public:
  int mySqrt(int x) 
  {
    int output;
    
    if(x < 0)
      return 0;
    
    else if(x == 0 || x == 1) return x;
    
    else
    {
      long long start = 1;
      long long end = x;
      while(start <= end){
          long long mid = (start + end) / 2;
          long long temp =(mid+1) * (mid+1);
          if(mid * mid == x || (mid * mid < x && temp > x)){
              return mid;
          }
          else if(mid * mid < x && (mid+1) * (mid+1) <= x){
              start = mid + 1;
          }
          else{
              end = mid - 1;
          }
      }
      return -1;
    }
    
    return output;
  }
};