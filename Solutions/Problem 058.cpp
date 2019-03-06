/*
Problem 58: Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/


/* Time: 4ms */
class Solution {
public:
  int lengthOfLastWord(string s) 
  {
    int length = 0;
    
    //String is emtpy
    if(s.size() == 0) return 0;
    
    //Input String is not empty
    int tail = s.size() - 1;
    
    //Decrease the tail index if it is whitespace
    while(tail >= 0 && s[tail] == ' ') --tail;
    
    //Count the length until we meet whitespace
    while(tail >= 0 && s[tail] != ' ')
    {
      ++length;
      --tail;
    }
    
    return length;
  }
};