/*
Question 21: Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/*************************************************************************/
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
  {
    ListNode* newList = new ListNode(0);
    ListNode* tail = newList;

    while (l1 && l2)
    {
      auto& listToMake = (l1->val < l2->val) ? l1 : l2;
      auto elt = listToMake;
      listToMake = listToMake->next;
      tail->next = elt;
      tail = tail->next;
    }

    if (l2) swap(l1, l2);
    tail->next = l1;

    return newList->next;
  }
};