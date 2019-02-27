/*
Question 23: Merge k Sorted List

Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
  {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val > l2->val)
    {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }

    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    //Check if the vector is empty
    if (lists.empty()) return NULL;

    for (int n = lists.size(); n > 1; n = (n + 1) / 2)
      for (int i = 0, j = n - 1; i < j; ++i, --j)
        lists[i] = mergeTwoLists(lists[i], lists[j]);

    return lists[0];
  }
};