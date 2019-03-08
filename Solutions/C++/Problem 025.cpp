/*
Question 25: Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number
of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
1) Only constant extra memory is allowed.
2) You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

/**********************************************************************/

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
  ListNode* ReverseRec(ListNode* head, int& length, int num)
  {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    --length;
    if (length == 1)
    {
      ListNode* newHead = head->next;
      ListNode* newNext = head->next->next;

      head->next->next = head;
      length = num;
      head->next = ReverseRec(newNext, length, num);
      return newHead;
    }

    ListNode* newHead = ReverseRec(head->next, length, num);
    ListNode* nextHead = head->next->next;

    //Group not reversed
    if (head->next == newHead) return head;

    head->next->next = head;
    head->next = nextHead;

    return newHead;
  }

  ListNode* reverseKGroup(ListNode* head, int k)
  {
    int len = k;
    return ReverseRec(head, len, k);
  }
};