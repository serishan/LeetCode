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
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/* Time: 16ms */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l3 := &ListNode{}
	startNode := l3

	//Variable Declare and Initialize
	var flag int
	var sum int

	for {
		sum = l1.Val + l2.Val + flag
		l3.Val = sum % 10
		flag = sum / 10
		if l1.Next == nil && l2.Next == nil {
			if flag == 1 {
				l3.Next = &ListNode{1, nil}
			}

			return startNode
		}

		l3.Next = &ListNode{}
		l3 = l3.Next //Head Update

		if l1.Next == nil {
			l1.Val = 0
		} else {
			l1 = l1.Next
		}

		if l2.Next == nil {
			l2.Val = 0
		} else {
			l2 = l2.Next
		}
	}
}