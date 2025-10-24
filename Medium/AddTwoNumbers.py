"""

PROBLEM

You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order, and each of their
nodes contains a single digit. Add the two numbers and return the sum
as a linked list.

You may assume the two numbers do not contain any leading zero, except
the number 0 itself.

Example

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have
leading zeros.


STEPS


1 - We define __init__ (constructor of a ListNode) to have a value of 0
    and a next pointer pointing to None
2 - The class constains a function that takes 2 list nodes and returns
    a list node

3 - dummy is the head of the list node with a value of 0
4 - current is where the dummy is situated, which is the head or dummy

5 - carry is 0 to hold the value that is going to be carried to the next
    node
6 - while checks whether l1 or l2 or l3 exist or are true

7 - If they are true or if they exist:
    - x (l1.val) is the current node of l1 if l1 exists and if it doesn't
    exist, x = 0

    l1: 2 → 4 → 3 → None
    l2: 5 → 6 → 4 → None
    dummy: 0 →

    - y (l2.val) is also the current node for l2
    - total is x + y + carry

    - carry is going to be total integer divided which is 1 when 10//10
    and 0 when a number less than 10 is divided with 10
    - digit is when total is divisible by 10 which is 1 only once and 0
    most of the time

    x = l1.val if l1 else 0 means If l1 exists, get its value; otherwise
    use 0
    y = l2.val if l2 else 0 If l2 exists, get its value; otherwise use 0

    return dummy.next Return the list starting after the dummy head



"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        current = dummy
        carry = 0

        while l1 or l2 or carry:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0

            total = x + y + carry
            carry = total // 10
            digit = total % 10

            current.next = ListNode(digit)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            
        return dummy.next


