/*
Quesetion 1: Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single
digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

[Example]
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/********************************************************************************/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
 
 /* Time: 108 ms */
public class Solution {
  public ListNode AddTwoNumbers(ListNode l1, ListNode l2) 
  {
    int carry = 0;
    ListNode Units = new ListNode(0);
    ListNode pre = Units;
    
    while(l1 != null || l2 != null || carry == 1)
    {
      int sum = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + carry;
      carry = sum / 10;
      
      pre.next = new ListNode(sum % 10);
      pre = pre.next;
      
      if(l1 != null) l1 = l1.next;
      if(l2 != null) l2 = l2.next;
    }
    
    return Units.next;
  }
}