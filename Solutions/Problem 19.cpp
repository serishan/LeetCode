/*
Question 19: Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
*/

/*************************************************************************************/

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
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    int length = 0;//This will hold the total length of linked list
    ListNode* dummy = new ListNode(0);
    ListNode* first = head;
    dummy->next = head;

    //Getting the length;
    while (first != NULL)
    {
      ++length;
      first = first->next;
    }

    length -= n;

    first = dummy;

    while (length > 0)
    {
      --length;
      first = first->next;
    }

    first->next = first->next->next;
    //output = first;

    return dummy->next;
  }
};