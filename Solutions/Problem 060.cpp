/*
Problem 60: Permutation Sequence

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

/* Time: 4ms */
class Solution {
public:
  string getPermutation(int n, int k) 
  {
    //Get the number into the vector
    vector<int> num;
    for(int i = 1; i <= n; ++i)
      num.push_back(i);
    
    int i = 0;
    string output;
    
    while(n > 0)
    {
      --n;
      int fact = GetFactorial(n);
      int d = (k + fact - 1) / fact;
      output += '0' + num[d-1];
      num.erase(num.begin() + d - 1);
      k = k - (d-1) * fact;
    }
    
    return output;
  }
  
private:
  int GetFactorial(int n)
  {
    if(n == 1 || n == 0) return 1;
    
    return n * GetFactorial(n-1);
  }
};