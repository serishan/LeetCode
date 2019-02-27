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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  /*
  [Function]
  addTwoNumbers

  [Parameter]
  l1 - single linked list of first number
  l2 - single linked list of second number

  [Return]
  addition of two numbers from two singly linked list
  */
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    struct ListNode* node1 = l1, *node2 = l2, *preSum;
    struct ListNode* Units = NULL;
    int carry = 0, curVal;

    while (node1 != NULL || node2 != NULL || carry != 0)
    {
      curVal = 0;
      if (node1 != NULL)
      {
        curVal += node1->val;
        node1 = node1->next;
      }

      if (node2 != NULL)
      {
        curVal += node2->val;
        node2 = node2->next;
      }

      curVal += carry;
      carry = curVal / 10;
      curVal %= 10;

      struct ListNode* curSum = new ListNode(sizeof(ListNode));
      curSum->val = curVal;
      curSum->next = NULL;

      if (Units == NULL)
        Units = curSum;

      else
        preSum->next = curSum;

      preSum = curSum;
    }

    return Units;
  }
};